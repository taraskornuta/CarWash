#include "wash_tasks_private.h"

/**
  * @brief Timings intervals for each washing stage
  */
static const uint16_t washStageTimingsSec[WASH_STAGE_COUNT] = 
{
  30UL * WASH_TASKS_ONE_SEC,
  30UL * WASH_TASKS_ONE_SEC,
  60UL * WASH_TASKS_ONE_SEC,
  30UL * WASH_TASKS_ONE_SEC
};

/**
  * @brief RTOS tasks settings
  */
static const osThreadAttr_t ButtonTasksAttrib =
{
  .name = "TaskButton",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = WASH_TASKS_STACK_SIZE
};

static const osThreadAttr_t ButtonProcessAttrib =
{
  .name = "TaskButtonProc",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = WASH_TASKS_STACK_SIZE
};

static const osThreadAttr_t WashTasksAttrib[WASH_BOX_COUNT] =
{
  {
    .name = "TaskBox_1",
    .priority = (osPriority_t) osPriorityBelowNormal,
    .stack_size = WASH_TASKS_STACK_SIZE
  },
  {
    .name = "TaskBox_2",
    .priority = (osPriority_t) osPriorityBelowNormal,
    .stack_size = WASH_TASKS_STACK_SIZE
  },
  {
    .name = "TaskBox_3",
    .priority = (osPriority_t) osPriorityBelowNormal,
    .stack_size = WASH_TASKS_STACK_SIZE
  },
  {
    .name = "TaskBox_4",
    .priority = (osPriority_t) osPriorityBelowNormal,
    .stack_size = WASH_TASKS_STACK_SIZE
  }
};

static washTaskProgress_t washBox[WASH_BOX_COUNT];
static washBox_t reservedBox = WASH_BOX_COUNT;

void Tasks_Init(void)
{
  osThreadNew(ButtonTask, NULL, &ButtonTasksAttrib);
  osThreadNew(ButtonProcess, NULL, &ButtonProcessAttrib);
  
  for(uint8_t i = 0; i < WASH_BOX_COUNT; i++)
  {
    washBox[i].delayClbk  = vTaskDelay;
  }
}


void WashTask(void *argument)
{
  while(1)
  { 
    // get task hendle to identify which task call WashTask func
    TaskHandle_t handler = xTaskGetCurrentTaskHandle();
    
    //iterate over all washing boxes
    for(uint8_t box = 0; box < WASH_BOX_COUNT; box++)
    {
      if ((handler == washBox[box].taskHandle) && washBox[box].occupied)
      {
        // start washing process 
        WashTask_Washing(box);
      } 
    }
  }
}

void ButtonTask(void *argument)
{
  while(1)
  {
    manButtons_Update();
    vTaskDelay(10);
  }
}

void ButtonProcess(void *argument)
{
  while(1)
  {
    //use MessageBuffer to store buttons state
    uint8_t btnCode = manButtons_GetBtnCode();
    
    TRACE("BUTTON_PIN_%d", btnCode);
    // try to reserve box for washing
    if (BTN_BOX_1 == btnCode) reservedBox = WASH_BOX_1;
    if (BTN_BOX_2 == btnCode) reservedBox = WASH_BOX_2;
    if (BTN_BOX_3 == btnCode) reservedBox = WASH_BOX_3;
    if (BTN_BOX_4 == btnCode) reservedBox = WASH_BOX_4;
    // if box was reserved than washing will start, else ignore
    if ((BTN_START) == btnCode) WashTask_TaskStart(&reservedBox); 
  }
}

void WashTask_TaskStart(washBox_t *boxNumber)
{
  assert_param(IS_WASH_BOX(*boxNumber));
  
  washBox_t box = *boxNumber;
  if (IS_WASH_BOX(box) && (false == washBox[box].occupied))
  {
    washBox[box].occupied = true;
    washBox[box].taskHandle = osThreadNew(WashTask, NULL, &WashTasksAttrib[box]);
    *boxNumber = WASH_BOX_COUNT; // set dummy value
  }
}

void WashTask_Washing(washBox_t boxNumber)
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

void WashTask_StateFoam(washBox_t boxNumber)
{
  assert_param(IS_WASH_BOX(boxNumber));
  
  TRACE("Box %d, stage FOAM", boxNumber);
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_FOAM]);
  washBox[boxNumber].stage = WASH_STAGE_BRUSHES; // switch to next state
}

void WashTask_StateBrushes(washBox_t boxNumber)
{
  assert_param(IS_WASH_BOX(boxNumber));
  
  TRACE("Box %d, stage BRUSHES", boxNumber);
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_BRUSHES]);
  washBox[boxNumber].stage = WASH_STAGE_RINSING; // switch to next state
}

void WashTask_StateRinsing(washBox_t boxNumber)
{
  assert_param(IS_WASH_BOX(boxNumber));
  
  TRACE("Box %d, stage RINSING", boxNumber);  
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_RINSING]);
  washBox[boxNumber].stage = WASH_STAGE_DRYING;  // switch to next state
}

void WashTask_StateDrying(washBox_t boxNumber)
{
  assert_param(IS_WASH_BOX(boxNumber));
  
  TRACE("Box %d, stage DRYING", boxNumber);
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_DRYING]);
  washBox[boxNumber].stage    = WASH_STAGE_FOAM; // switch to next state
  washBox[boxNumber].occupied = false;           // reset all triggers as it was last stage
  TRACE("Box %d Finish!", boxNumber);
  vTaskDelete(washBox[boxNumber].taskHandle);
}
