#ifndef TASKS_PRIVATE_H
#define TASKS_PRIVATE_H

#include "wash_tasks.h"
#include "main.h"
#include "man_buttons.h"
#include "util_stdout.h"
#include "cmsis_os.h"
#include "message_buffer.h"

#define WASH_TASKS_STACK_SIZE (64 * 4)

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

typedef void (*delayTimer)(const TickType_t xTicksToDelay);

typedef struct
{
  //washBox_t    boxId;        // id of the box occupied by the car
  bool         isOccupied;   // box status
  bool         start;
  washStage_t  stage;        // at which stage washing is
  delayTimer   delayClbk;    // stage delay
  osThreadId_t taskHandle;   // pointer to task handler
}washTaskProgress_t;

const uint8_t washStageTimingsSec[WASH_STAGE_COUNT] = {30UL, 30UL, 60UL, 30UL};

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



static void WashTask(void *argument);
static void ButtonTask(void *argument);

static void WashTask_StateFoam(uint8_t boxNumber);
static void WashTask_StateBrushes(uint8_t boxNumber);
static void WashTask_StateRinsing(uint8_t boxNumber);
static void WashTask_StateDrying(uint8_t boxNumber);




#endif
