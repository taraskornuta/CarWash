#include "wash_tasks_private.h"

static osThreadId_t ButtonTaskHandle;
static washTaskProgress_t washBox[WASH_BOX_COUNT];
static uint8_t reservedBox = WASH_BOX_COUNT;

void Tasks_Init(void)
{
  ButtonTaskHandle = osThreadNew(ButtonTask, NULL, &ButtonTasksAttrib);
  for(uint8_t i = 0; i < WASH_BOX_COUNT; i++)
  {
    washBox[i].taskHandle = osThreadNew(WashTask, NULL, &WashTasksAttrib[i]);
    washBox[i].delayClbk  = vTaskDelay;
  }
}


static void WashTask(void *argument)
{
  while(1)
  { 
    // get task hendle to identify which task call WashTask func
    osThreadId_t handler = xTaskGetCurrentTaskHandle();
    
    //iterate over all washing boxes
    for(uint8_t box = 0; box < WASH_BOX_COUNT; box++)
    {
      if (washBox[box].taskHandle == handler)
      {
        // check is box occupied by car
        if (true == washBox[box].occupied)
        {
          // start washing process 
          WashTask_Washing(box);
        }
      } 
    }
    
    vTaskDelay(10);
  }
}

static void ButtonTask(void *argument)
{
  while(1)
  {
    uint8_t btnCode = 0;
    // polls the buttons pressings 
    manButtons_Update();
    //use MessageBuffer to store buttons state
    btnCode = manButtons_GetBtnCode();
    if (btnCode)
    {
      // try to reserve box for washing
      if ((1 << BTN_BOX_1 & btnCode) == btnCode) reservedBox = BTN_BOX_1;
      if ((1 << BTN_BOX_2 & btnCode) == btnCode) reservedBox = BTN_BOX_2;
      if ((1 << BTN_BOX_3 & btnCode) == btnCode) reservedBox = BTN_BOX_3;
      if ((1 << BTN_BOX_4 & btnCode) == btnCode) reservedBox = BTN_BOX_4;
      // if box was reserved than washing will start, else ignore
      if ((1 << BTN_START & btnCode) == btnCode) WashTask_TaskStart(reservedBox);
    }
  }
}


static void WashTask_TaskStart(washBox_t boxNumber)
{
  assert_param(IS_WASH_BOX(boxNumber));
  if (boxNumber < WASH_BOX_COUNT)
  {
    washBox[boxNumber].occupied = true;
    boxNumber = WASH_BOX_COUNT; // set dummy value
  }
}

static void WashTask_Washing(washBox_t boxNumber)
{
  assert_param(IS_WASH_BOX(boxNumber));
  switch((uint8_t)washBox[boxNumber].stage)
  {
    case WASH_STAGE_FOAM:
        WashTask_StateFoam(boxNumber);
        break;
    case WASH_STAGE_BRUSHES:
        WashTask_StateBrushes(boxNumber);
        break;
    case WASH_STAGE_RINSING:
        WashTask_StateRinsing(boxNumber);
        break;
    case WASH_STAGE_DRYING:
        WashTask_StateDrying(boxNumber);
        break;
    default:
        break;
  }
}

static void WashTask_StateFoam(washBox_t boxNumber)
{
  assert_param(IS_WASH_BOX(boxNumber));
  TRACE("Box %d, stage FOAM", boxNumber);
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_FOAM]);
  washBox[boxNumber].stage = WASH_STAGE_BRUSHES; // switch to next state
}

static void WashTask_StateBrushes(washBox_t boxNumber)
{
  assert_param(IS_WASH_BOX(boxNumber));
  TRACE("Box %d, stage BRUSHES", boxNumber);
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_BRUSHES]);
  washBox[boxNumber].stage = WASH_STAGE_RINSING; // switch to next state
}

static void WashTask_StateRinsing(washBox_t boxNumber)
{
  assert_param(IS_WASH_BOX(boxNumber));
  TRACE("Box %d, stage RINSING", boxNumber);  
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_RINSING]);
  washBox[boxNumber].stage = WASH_STAGE_DRYING;  // switch to next state
}

static void WashTask_StateDrying(washBox_t boxNumber)
{
  assert_param(IS_WASH_BOX(boxNumber));
  TRACE("Box %d, stage DRYING", boxNumber);
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_DRYING]);
  washBox[boxNumber].stage    = WASH_STAGE_FOAM; // switch to next state
  washBox[boxNumber].occupied = false;           // reset all triggers as it was last stage
  TRACE("Box %d Finish!", boxNumber); 
}
