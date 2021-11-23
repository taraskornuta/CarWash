#include "man_buttons_private.h"


btn_instance_t btn_inst[BTN_COUNT] = {
  {
      .port = (const uint32_t *)GPIOA,
      .pin = GPIO_PIN_0,
  },
  {
      .port = (const uint32_t *)GPIOA,
      .pin = GPIO_PIN_1,
  },
  {
      .port = (const uint32_t *)GPIOA,
      .pin = GPIO_PIN_2,
  },
  {
      .port = (const uint32_t *)GPIOA,
      .pin = GPIO_PIN_3,
  },
  {
      .port = (const uint32_t *)GPIOA,
      .pin = GPIO_PIN_4,
  }
};

btn_init_t btn_init = {
  .process_time_ms = 10,
  .debounce_time_ms = 20,
  .port_read = (port_read_cb_t)&HAL_GPIO_ReadPin,
  .short_release = Button_ShortRelease,
//  .long_release = Button_LongRelease,
//  .long_press = Button_LongPress,
};


static MessageBufferHandle_t buttonMsgHandler;

void manButtons_Init(void)
{
  manButtons_GpioInit();
  Button_Init(&btn_init, btn_inst, BTN_COUNT);
  buttonMsgHandler = xMessageBufferCreate(5);
}

void manButtons_Update(void)
{
  Button_Update();
  vTaskDelay(10);
}

MessageBufferHandle_t * manButtons_GetHandler(void)
{
  return &buttonMsgHandler;
}

uint8_t manButtons_GetBtnCode(void)
{
  uint8_t btnCode = 0;
  xMessageBufferReceive(buttonMsgHandler, &btnCode, sizeof(btnCode), portMAX_DELAY);
  return btnCode;
}

void Button_ShortRelease(uint8_t btnCode)
{
  xMessageBufferSend(buttonMsgHandler, (void *)&btnCode, sizeof(btnCode), 100);
}



static void manButtons_GpioInit(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 PA4 */              
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4;
                         
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

