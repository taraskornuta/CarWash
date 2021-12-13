#include "man_buttons_private.h"


static btn_instance_t btn_inst[BTN_COUNT] = 
{
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

static btn_init_t btn_init = {
  .process_time_ms = 10,
  .debounce_time_ms = 20,
  .port_read = (port_read_cb_t)&HAL_GPIO_ReadPin,
  .short_release = Button_ShortRelease,
};

static MessageBufferHandle_t buttonMsgHandler;


int8_t manButtons_Init(void)
{
  int8_t ret_code = -1;

  do
  {
    manButtons_GpioInit();
    ret_code = Button_Init(&btn_init, btn_inst, BTN_COUNT);
    if (0 != ret_code)                // Init failde, break and finish execution
    {
      break;
    }

    buttonMsgHandler = xMessageBufferCreate(5);
    if (NULL == buttonMsgHandler)      // msgBuffer not created, break and finish execution
    {
      ret_code = -1;
      break;
    }
    
    ret_code = 0; 
  } while (0);
  
  return ret_code;
}

void manButtons_Update(void)
{
  Button_Update();
  vTaskDelay(10);
}

uint8_t manButtons_GetBtnCode(void)
{
  uint8_t btnCode = 0;
  xMessageBufferReceive(buttonMsgHandler, &btnCode, sizeof(btnCode), portMAX_DELAY);
  return btnCode;
}


static void Button_ShortRelease(uint8_t btnCode)
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

