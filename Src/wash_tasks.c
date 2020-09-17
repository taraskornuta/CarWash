#include "wash_tasks_private.h"

static osThreadId_t ButtonTaskHandle;
static washTaskProgress_t washBox[WASH_BOX_COUNT];
static MessageBufferHandle_t *pButtonMsgHandler;

void Tasks_Init(void)
{
  pButtonMsgHandler = manButtons_GetHandler();
  ButtonTaskHandle = osThreadNew(ButtonTask, NULL, &ButtonTasksAttrib);
  
  for(uint8_t i = 0; i < WASH_BOX_COUNT; i++) //
  {
    washBox[i].taskHandle = osThreadNew(WashTask, NULL, &WashTasksAttrib[i]);
    washBox[i].delayClbk  = vTaskDelay;
  }
}


static void WashTask(void *argument)
{
  uint8_t btnCode = 0;
  uint8_t lastBtnCode = 0;
  
  while(1)
  {
    osThreadId_t handler = xTaskGetCurrentTaskHandle();
    
    if (!xMessageBufferIsEmpty(*pButtonMsgHandler))
    {
      xMessageBufferReceive(*pButtonMsgHandler, &btnCode, sizeof(btnCode), 100);
      if ((1 << BTN_BOX_1 & btnCode) == btnCode) washBox[BTN_BOX_1].isOccupied = true;
      if ((1 << BTN_BOX_2 & btnCode) == btnCode) washBox[BTN_BOX_2].isOccupied = true;
      if ((1 << BTN_BOX_3 & btnCode) == btnCode) washBox[BTN_BOX_3].isOccupied = true;
      if ((1 << BTN_BOX_4 & btnCode) == btnCode) washBox[BTN_BOX_4].isOccupied = true;
      //if (BTN_START == btnCode) washBox[i].start = true;
    }
    
    for(uint8_t i = 0; i < WASH_BOX_COUNT; i++)
    {
      if (washBox[i].taskHandle == handler)
      {
        if ((true == washBox[i].isOccupied) && (true == washBox[i].start))
        {
          switch((uint8_t)washBox[i].stage)
          {
            case WASH_STAGE_FOAM:
                WashTask_StateFoam(i);
                break;
            case WASH_STAGE_BRUSHES:
                WashTask_StateBrushes(i);
                break;
            case WASH_STAGE_RINSING:
                WashTask_StateRinsing(i);
                break;
            case WASH_STAGE_DRYING:
                WashTask_StateDrying(i);
                break;
            default:
                break;
          }   
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
    manButtons_Update();
  }
}


static void WashTask_StateFoam(uint8_t boxNumber)
{
  TRACE("Box %d, stage FOAM", boxNumber);
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_FOAM] * 1000);
  washBox[boxNumber].stage = WASH_STAGE_BRUSHES; // switch to next state
}

static void WashTask_StateBrushes(uint8_t boxNumber)
{
  TRACE("Box %d, stage BRUSHES", boxNumber);
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_BRUSHES] * 1000);
  washBox[boxNumber].stage = WASH_STAGE_RINSING; // switch to next state
}

static void WashTask_StateRinsing(uint8_t boxNumber)
{
  TRACE("Box %d, stage RINSING", boxNumber);  
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_RINSING] * 1000);
  washBox[boxNumber].stage = WASH_STAGE_DRYING;  // switch to next state
}

static void WashTask_StateDrying(uint8_t boxNumber)
{
  TRACE("Box %d, stage DRYING", boxNumber);
  washBox[boxNumber].delayClbk(washStageTimingsSec[WASH_STAGE_DRYING] * 1000);
  washBox[boxNumber].stage      = WASH_STAGE_FOAM; // switch to next state
  washBox[boxNumber].isOccupied = false;           // reset all triggers as it was last stage
  washBox[boxNumber].start      = false;
  TRACE("Box %d Finish!", boxNumber); 
}
