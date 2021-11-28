#ifndef TEST_SUPPORT_PORT_MACRO
#define TEST_SUPPORT_PORT_MACRO

#include "mpu_wrappers.h"

typedef uint32_t TickType_t;
#define portMAX_DELAY ( TickType_t ) 0xffffffffUL

#endif