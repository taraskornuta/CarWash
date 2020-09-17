#ifndef MAN_BUTTONS_H
#define MAN_BUTTONS_H

#include "message_buffer.h"

typedef enum 
{
  BTN_BOX_1 = 0,
  BTN_BOX_2,
  BTN_BOX_3,
  BTN_BOX_4,
  BTN_START,
  BTN_COUNT
}button_t;

void manButtons_Init(void);
void manButtons_Update(void);
MessageBufferHandle_t * manButtons_GetHandler(void);

#endif
