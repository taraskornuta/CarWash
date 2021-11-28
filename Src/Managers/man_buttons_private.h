#ifndef MAN_BUTTONS_PRIVATE_H
#define MAN_BUTTONS_PRIVATE_H

#include "main.h"
#include "man_buttons.h"
#include "button.h"
#include "FreeRTOS.h"
#include "message_buffer.h"

static void manButtons_GpioInit(void);
static void Button_ShortRelease(uint8_t btnCode);


#endif

