#include "../Middlewares/Third_Party/FreeRTOS/Source/include/portable.h"
#include "../Middlewares/Third_Party/FreeRTOS/Source/include/projdefs.h"
#include "../Src/FreeRTOSConfig.h"




















struct xSTATIC_LIST_ITEM

{

 TickType_t xDummy1;

 void *pvDummy2[ 4 ];

};

typedef struct xSTATIC_LIST_ITEM StaticListItem_t;





struct xSTATIC_MINI_LIST_ITEM

{

 TickType_t xDummy1;

 void *pvDummy2[ 2 ];

};

typedef struct xSTATIC_MINI_LIST_ITEM StaticMiniListItem_t;





typedef struct xSTATIC_LIST

{

 UBaseType_t uxDummy1;

 void *pvDummy2;

 StaticMiniListItem_t xDummy3;

} StaticList_t;

typedef struct xSTATIC_TCB

{

 void *pxDummy1;







 StaticListItem_t xDummy3[ 2 ];

 UBaseType_t uxDummy5;

 void *pxDummy6;

 uint8_t ucDummy7[ ( 16 ) ];















  UBaseType_t uxDummy10[ 2 ];





  UBaseType_t uxDummy12[ 2 ];

  uint32_t ulDummy18;

  uint8_t ucDummy19;





  uint8_t uxDummy20;













} StaticTask_t;

typedef struct xSTATIC_QUEUE

{

 void *pvDummy1[ 3 ];



 union

 {

  void *pvDummy2;

  UBaseType_t uxDummy2;

 } u;



 StaticList_t xDummy3[ 2 ];

 UBaseType_t uxDummy4[ 3 ];

 uint8_t ucDummy5[ 2 ];





  uint8_t ucDummy6;















  UBaseType_t uxDummy8;

  uint8_t ucDummy9;





} StaticQueue_t;

typedef StaticQueue_t StaticSemaphore_t;

typedef struct xSTATIC_EVENT_GROUP

{

 TickType_t xDummy1;

 StaticList_t xDummy2;





  UBaseType_t uxDummy3;







   uint8_t ucDummy4;





} StaticEventGroup_t;

typedef struct xSTATIC_TIMER

{

 void *pvDummy1;

 StaticListItem_t xDummy2;

 TickType_t xDummy3;

 UBaseType_t uxDummy4;

 void *pvDummy5[ 2 ];



  UBaseType_t uxDummy6;







  uint8_t ucDummy7;





} StaticTimer_t;

typedef struct xSTATIC_STREAM_BUFFER

{

 size_t uxDummy1[ 4 ];

 void * pvDummy2[ 3 ];

 uint8_t ucDummy3;



  UBaseType_t uxDummy4;



} StaticStreamBuffer_t;





typedef StaticStreamBuffer_t StaticMessageBuffer_t;
