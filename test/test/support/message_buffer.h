#ifndef TEST_SUPPORT_MESSAGE_BUFFER_H
#define TEST_SUPPORT_MESSAGE_BUFFER_H

typedef void * MessageBufferHandle_t;
typedef void * StreamBufferHandle_t;
typedef long BaseType_t;
typedef uint32_t TickType_t;
#define pdFALSE			( ( BaseType_t ) 0 )
#define pdTRUE			( ( BaseType_t ) 1 )

StreamBufferHandle_t xStreamBufferGenericCreate( size_t xBufferSizeBytes, size_t xTriggerLevelBytes, BaseType_t xIsMessageBuffer );
#define xMessageBufferCreate( xBufferSizeBytes ) ( MessageBufferHandle_t ) xStreamBufferGenericCreate( xBufferSizeBytes, ( size_t ) 0, pdTRUE );

size_t xStreamBufferReceive( StreamBufferHandle_t xStreamBuffer, void *pvRxData, size_t xBufferLengthBytes, TickType_t xTicksToWait );
#define xMessageBufferReceive( xMessageBuffer, pvRxData, xBufferLengthBytes, xTicksToWait ) xStreamBufferReceive( ( StreamBufferHandle_t ) xMessageBuffer, pvRxData, xBufferLengthBytes, xTicksToWait );

size_t xStreamBufferSend( StreamBufferHandle_t xStreamBuffer, const void *pvTxData, size_t xDataLengthBytes, TickType_t xTicksToWait );
#define xMessageBufferSend( xMessageBuffer, pvTxData, xDataLengthBytes, xTicksToWait ) xStreamBufferSend( ( StreamBufferHandle_t ) xMessageBuffer, pvTxData, xDataLengthBytes, xTicksToWait );

#endif