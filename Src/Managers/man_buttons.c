#include "man_buttons_private.h"

static Debouncer port;
static MessageBufferHandle_t buttonMsgHandler;

void manButtons_Init(void)
{
  manButtons_GpioInit();
  buttonMsgHandler = xMessageBufferCreate(5);
}

void manButtons_Update(void)
{
  uint8_t btnCode = 0;
  // Poll the data from port
  for (uint8_t i = 0; i < BTN_COUNT; i++)
  {
    btnCode |= ((bool)HAL_GPIO_ReadPin(GPIOA, pin[i]) << i);
  }
  
  // Use debounce to filter button press
  ButtonProcess(&port, btnCode);
  btnCode = 0;
  // Check is button pressed
  for (uint8_t i = 0; i < BTN_COUNT; i++)
  {
    if(ButtonPressed(&port, 1 << i)) // was pressed, send state to msgBuffer
    {
      btnCode |= 1 << i;
      TRACE("BUTTON_PIN_%d mask 0x%x", i, btnCode); 
      xMessageBufferSend(buttonMsgHandler, (void *)&btnCode, sizeof(btnCode), 100);
    }
  }
  vTaskDelay(BUTTONS_DEBOUNCE_TIME);
}

MessageBufferHandle_t * manButtons_GetHandler(void)
{
  return &buttonMsgHandler;
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

