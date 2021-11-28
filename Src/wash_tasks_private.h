#ifndef TASKS_PRIVATE_H
#define TASKS_PRIVATE_H

#include "wash_tasks.h"
#include "main.h"
#include "man_buttons.h"
#include "util_stdout.h"
#include "cmsis_os.h"
#include "message_buffer.h"

#ifdef TEST
#define static
#endif

#define WASH_TASKS_STACK_SIZE (64 * 4)  // stack size, used 
#define WASH_TASKS_ONE_SEC    (100UL)


typedef enum
{
  WASH_BOX_1 = 0,
  WASH_BOX_2,
  WASH_BOX_3,
  WASH_BOX_4,
  WASH_BOX_COUNT
}washBox_t;

typedef enum
{
  WASH_STAGE_FOAM = 0,
  WASH_STAGE_BRUSHES,
  WASH_STAGE_RINSING,
  WASH_STAGE_DRYING,
  WASH_STAGE_COUNT
}washStage_t;

#define IS_WASH_BOX(TYPE)    (((TYPE) == WASH_BOX_1) ||\
                              ((TYPE) == WASH_BOX_2) ||\
                              ((TYPE) == WASH_BOX_3) ||\
                              ((TYPE) == WASH_BOX_4))

#define IS_WASH_STAGE(TYPE)  (((TYPE) == WASH_STAGE_FOAM) ||\
                              ((TYPE) == WASH_STAGE_BRUSHES) ||\
                              ((TYPE) == WASH_STAGE_RINSING) ||\
                              ((TYPE) == WASH_STAGE_DRYING))

typedef void (*delayTimer)(const TickType_t xTicksToDelay);

typedef struct
{
  delayTimer   delayClbk;    // stage delay callback
  osThreadId_t taskHandle;   // pointer to task handler
  bool         occupied;     // box status
  washStage_t  stage;        // at which stage washing is
}washTaskProgress_t;



/**
  * @brief Module private functions
  */

/**
  * @brief RTOS Task functions callbacks
  */
void WashTask(void *argument);
void ButtonTask(void *argument);
void ButtonProcess(void *argument);

/**
  * @brief Module decomposed functions
  */
void WashTask_TaskStart(washBox_t *boxNumber);
void WashTask_Washing(washBox_t boxNumber);
void WashTask_StateFoam(washBox_t boxNumber);
void WashTask_StateBrushes(washBox_t boxNumber);
void WashTask_StateRinsing(washBox_t boxNumber);
void WashTask_StateDrying(washBox_t boxNumber);


#endif
