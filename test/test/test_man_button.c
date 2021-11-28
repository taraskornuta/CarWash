#include "unity.h"
#include "man_buttons.h"

#include "mock_button.h"
#include "mock_stm32f1xx_hal_gpio.h"
#include "mock_message_buffer.h"
#include "mock_task.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_man_buttons(void)
{
  manButtons_Init();
  //Button_Init_ExpectAndReturn()
}