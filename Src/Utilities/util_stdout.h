#include "stdio.h"
#include "string.h"
#include "FreeRTOS.h"
#include "task.h"

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
void STDOUT_UART_Init(void);


/*!
 * @brief Debug trace macro
 *
 * This macro prints to serial port debug information 
 * TRACE behaves like standard printf function except for addition
 * it prints file where the macro was run. Serial port should be inited
 * before run macro. Global define DEBUG_TRACE should be used in project.
 *
 * @param All available in standard printf function
 * @return None
 */
 
#define TRACE(...) \
     taskENTER_CRITICAL(); \
     printf("\r\n"); \
     printf (__VA_ARGS__); \
     taskEXIT_CRITICAL()

