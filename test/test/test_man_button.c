#include "unity.h"
#include "man_buttons.h"

#include "mock_button.h"
#include "mock_stm32f1xx_hal_gpio.h"
#include "mock_stm32f1xx_hal_rcc.h"
#include "mock_message_buffer.h"
#include "mock_task.h"
#include "mock_portmacro.h"

void setUp(void)
{
}

void tearDown(void)
{
}

//******************************************************************************

int8_t button_init_stub(btn_init_t* init, btn_instance_t* instance, uint8_t count, int cmock_num_calls)
{
  TEST_ASSERT_NOT_NULL(init);
  TEST_ASSERT_NOT_NULL(instance);
  TEST_ASSERT_EQUAL(BTN_COUNT, count);
  TEST_ASSERT_EQUAL(0, cmock_num_calls);
  return 0;
}


void test_man_buttons_init(void)
{
  int8_t ret_code = -1;
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init_Expect(GPIOA, &GPIO_InitStruct);

  MessageBufferHandle_t buttonMsgHandler;
  Button_Init_StubWithCallback(button_init_stub);
  xStreamBufferGenericCreate_IgnoreAndReturn(buttonMsgHandler);
  
  ret_code = manButtons_Init();
  TEST_ASSERT_EQUAL(0, ret_code);
}

//******************************************************************************
void button_update_stub(int cmock_num_calls)
{
  TEST_ASSERT_EQUAL(0, cmock_num_calls);
}

void test_man_button_update(void)
{
  Button_Update_StubWithCallback(button_update_stub);
  vTaskDelay_Ignore();

  manButtons_Update();
}

//******************************************************************************

size_t xstreambufferreceive_callback(StreamBufferHandle_t xStreamBuffer, void* pvRxData, size_t xBufferLengthBytes, TickType_t xTicksToWait, int cmock_num_calls)
{
  TEST_ASSERT_NOT_NULL(pvRxData);
  TEST_ASSERT_GREATER_OR_EQUAL_INT32(0, xBufferLengthBytes);
  TEST_ASSERT_EQUAL_UINT32(portMAX_DELAY, xTicksToWait);
  uint8_t *btn_code = (uint8_t *)pvRxData;   // avoid dereferencing void pointer
  *btn_code = 0x77;                          // return button code 0x77
}

void test_man_button_get_btn_code(void)
{
  uint8_t code = 0;
  xStreamBufferReceive_Stub(xstreambufferreceive_callback);
  code = manButtons_GetBtnCode();
  TEST_ASSERT_EQUAL_UINT8(0x77, code);
}