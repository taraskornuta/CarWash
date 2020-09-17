#include "util_stdout_private.h"

static UART_HandleTypeDef huart1;

#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
    
PUTCHAR_PROTOTYPE
{   
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1U, UART_TIMEOUT_MAX);
  return ch;
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
void utilStdout_Init(void)
{
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    //error accure
    while(1) {};
  }
}
