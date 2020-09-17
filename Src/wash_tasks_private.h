#ifndef TASKS_PRIVATE_H
#define TASKS_PRIVATE_H

#include "wash_tasks.h"
#include "main.h"
#include "man_buttons.h"
#include "util_stdout.h"
#include "cmsis_os.h"
#include "message_buffer.h"

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
  * @brief Timings intervals for each washing stage
  */
const uint16_t washStageTimingsSec[WASH_STAGE_COUNT] = 
{
  30UL * WASH_TASKS_ONE_SEC,
  30UL * WASH_TASKS_ONE_SEC,
  60UL * WASH_TASKS_ONE_SEC,
  30UL * WASH_TASKS_ONE_SEC
};

/**
  * @brief RTOS tasks settings
  */
const osThreadAttr_t ButtonTasksAttrib =
{
  .name = "TaskButton",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = WASH_TASKS_STACK_SIZE
};

const osThreadAttr_t WashTasksAttrib[WASH_BOX_COUNT] =
{
  {
    .name = "TaskBox_1",
    .priority = (osPriority_t) osPriorityNormal1,
    .stack_size = WASH_TASKS_STACK_SIZE
  },
  {
    .name = "TaskBox_2",
    .priority = (osPriority_t) osPriorityNormal2,
    .stack_size = WASH_TASKS_STACK_SIZE
  },
  {
    .name = "TaskBox_3",
    .priority = (osPriority_t) osPriorityNormal3,
    .stack_size = WASH_TASKS_STACK_SIZE
  },
  {
    .name = "TaskBox_4",
    .priority = (osPriority_t) osPriorityNormal4,
    .stack_size = WASH_TASKS_STACK_SIZE
  }
};

/**
  * @brief Module private functions
  */

/**
  * @brief RTOS Task functions callbacks
  */
static void WashTask(void *argument);
static void ButtonTask(void *argument);

/**
  * @brief Module decomposed functions
  */
static void WashTask_TaskStart(washBox_t boxNumber);
static void WashTask_Washing(washBox_t boxNumber);
static void WashTask_StateFoam(washBox_t boxNumber);
static void WashTask_StateBrushes(washBox_t boxNumber);
static void WashTask_StateRinsing(washBox_t boxNumber);
static void WashTask_StateDrying(washBox_t boxNumber);


#endif
