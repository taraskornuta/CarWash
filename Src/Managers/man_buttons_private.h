#ifndef MAN_BUTTONS_PRIVATE_H
#define MAN_BUTTONS_PRIVATE_H

#include "main.h"
#include "man_buttons.h"
#include "util_stdout.h"
#include "button_debounce.h"

#define BUTTONS_DEBOUNCE_TIME (25UL)

static const uint16_t pin[BTN_COUNT] = 
{
  GPIO_PIN_0,
  GPIO_PIN_1,
  GPIO_PIN_2,
  GPIO_PIN_3,
  GPIO_PIN_4
};

static void manButtons_GpioInit(void);

#endif

