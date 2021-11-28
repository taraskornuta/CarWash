#include "build/temp/_test_state_machine.c"
#include "../Src/wash_tasks.h"
#include "../Src/wash_tasks_private.h"
#include "build/test/mocks/mock_man_buttons.h"
#include "test/support/UnityHelper.h"
#include "D:/projects/STM/CarWash/test/vendor/ceedling/vendor/unity/src/unity.h"






typedef uint32_t BaseType_t;



TaskHandle_t xTaskGetCurrentTaskHandle(void)

{



}



void vTaskDelay( const TickType_t xTicksToDelay )

{

  struct timespec ts;

  int res;

  ts.tv_sec = xTicksToDelay / 1000;

  ts.tv_nsec = (xTicksToDelay % 1000) * 1000000;

  nanosleep(&ts, &ts);

}



void vTaskDelete( TaskHandle_t xTaskToDelete )

{



}





osThreadId_t osThreadNew (osThreadFunc_t func, void *argument, const osThreadAttr_t *attr)

{



}



void vTaskSuspendAll( void )

{



}



BaseType_t xTaskResumeAll( void )

{



}



void assert_failed(uint8_t *file, uint32_t line)

{



}

void Error_Handler(void)

{}



void setUp(void)

{

}



void tearDown(void)

{

}











void test_state_machine(void)

{

  Tasks_Init();



  for(uint8_t i = WASH_STAGE_FOAM; i < WASH_STAGE_COUNT; i++)

  {

    WashTask_Washing(WASH_BOX_1);

  }







}
