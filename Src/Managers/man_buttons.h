#ifndef MAN_BUTTONS_H
#define MAN_BUTTONS_H

#include <stdint.h>


typedef enum 
{
  BTN_BOX_1 = 0,
  BTN_BOX_2,
  BTN_BOX_3,
  BTN_BOX_4,
  BTN_START,
  BTN_COUNT
}button_t;

/**
  * @brief manButtons_Init Initialization buttons driver
  * @param None
  * @retval None
  */
void manButtons_Init(void);

/**
  * @brief manButtons_Update polls the buttons state
  * Should be used in separate thread or timer interrupt handler
  * which generates ISR each 1 ms
  * @param None
  * @retval None
  */
void manButtons_Update(void);

/**
  * @brief manButtons_GetBtnCode Get pushed button code
  * @param None
  * @retval button code
  */
uint8_t manButtons_GetBtnCode(void);

#endif
