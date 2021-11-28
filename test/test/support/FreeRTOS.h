#ifndef TEST_SUPPORT_FREERTOS_H
#define TEST_SUPPORT_FREERTOS_H

#include <stdint.h>

#include "portable.h"

typedef unsigned long UBaseType_t;

struct xSTATIC_MINI_LIST_ITEM
{
	#if( configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES == 1 )
		TickType_t xDummy1;
	#endif
	TickType_t xDummy2;
	void *pvDummy3[ 2 ];
};
typedef struct xSTATIC_MINI_LIST_ITEM StaticMiniListItem_t;

typedef struct xSTATIC_LIST
{
	#if( configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES == 1 )
		TickType_t xDummy1;
	#endif
	UBaseType_t uxDummy2;
	void *pvDummy3;
	StaticMiniListItem_t xDummy4;
	#if( configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES == 1 )
		TickType_t xDummy5;
	#endif
} StaticList_t;

#endif