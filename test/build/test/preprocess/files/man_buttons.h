#include "../Middlewares/Third_Party/FreeRTOS/Source/include/message_buffer.h"
#include "../Src/main.h"








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













uint8_t manButtons_GetBtnCode(void);
