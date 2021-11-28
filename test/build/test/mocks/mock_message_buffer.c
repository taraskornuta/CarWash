/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_message_buffer.h"

static const char* CMockString_pvRxData = "pvRxData";
static const char* CMockString_pvTxData = "pvTxData";
static const char* CMockString_xBufferLengthBytes = "xBufferLengthBytes";
static const char* CMockString_xBufferSizeBytes = "xBufferSizeBytes";
static const char* CMockString_xDataLengthBytes = "xDataLengthBytes";
static const char* CMockString_xIsMessageBuffer = "xIsMessageBuffer";
static const char* CMockString_xStreamBuffer = "xStreamBuffer";
static const char* CMockString_xStreamBufferGenericCreate = "xStreamBufferGenericCreate";
static const char* CMockString_xStreamBufferReceive = "xStreamBufferReceive";
static const char* CMockString_xStreamBufferSend = "xStreamBufferSend";
static const char* CMockString_xTicksToWait = "xTicksToWait";
static const char* CMockString_xTriggerLevelBytes = "xTriggerLevelBytes";

typedef struct _CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  StreamBufferHandle_t ReturnVal;
  int CallOrder;
  size_t Expected_xBufferSizeBytes;
  size_t Expected_xTriggerLevelBytes;
  BaseType_t Expected_xIsMessageBuffer;

} CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE;

typedef struct _CMOCK_xStreamBufferReceive_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  size_t ReturnVal;
  int CallOrder;
  StreamBufferHandle_t Expected_xStreamBuffer;
  void* Expected_pvRxData;
  size_t Expected_xBufferLengthBytes;
  TickType_t Expected_xTicksToWait;

} CMOCK_xStreamBufferReceive_CALL_INSTANCE;

typedef struct _CMOCK_xStreamBufferSend_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  size_t ReturnVal;
  int CallOrder;
  StreamBufferHandle_t Expected_xStreamBuffer;
  const void* Expected_pvTxData;
  size_t Expected_xDataLengthBytes;
  TickType_t Expected_xTicksToWait;

} CMOCK_xStreamBufferSend_CALL_INSTANCE;

static struct mock_message_bufferInstance
{
  int xStreamBufferGenericCreate_IgnoreBool;
  StreamBufferHandle_t xStreamBufferGenericCreate_FinalReturn;
  int xStreamBufferGenericCreate_CallbackBool;
  CMOCK_xStreamBufferGenericCreate_CALLBACK xStreamBufferGenericCreate_CallbackFunctionPointer;
  int xStreamBufferGenericCreate_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE xStreamBufferGenericCreate_CallInstance;
  int xStreamBufferReceive_IgnoreBool;
  size_t xStreamBufferReceive_FinalReturn;
  int xStreamBufferReceive_CallbackBool;
  CMOCK_xStreamBufferReceive_CALLBACK xStreamBufferReceive_CallbackFunctionPointer;
  int xStreamBufferReceive_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE xStreamBufferReceive_CallInstance;
  int xStreamBufferSend_IgnoreBool;
  size_t xStreamBufferSend_FinalReturn;
  int xStreamBufferSend_CallbackBool;
  CMOCK_xStreamBufferSend_CALLBACK xStreamBufferSend_CallbackFunctionPointer;
  int xStreamBufferSend_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE xStreamBufferSend_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_message_buffer_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.xStreamBufferGenericCreate_CallInstance;
  if (Mock.xStreamBufferGenericCreate_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_xStreamBufferGenericCreate);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == call_instance, cmock_line, CMockStringCalledLess);
  UNITY_CLR_DETAILS();
  if (Mock.xStreamBufferGenericCreate_CallbackFunctionPointer != NULL)
    call_instance = CMOCK_GUTS_NONE;
  call_instance = Mock.xStreamBufferReceive_CallInstance;
  if (Mock.xStreamBufferReceive_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_xStreamBufferReceive);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == call_instance, cmock_line, CMockStringCalledLess);
  UNITY_CLR_DETAILS();
  if (Mock.xStreamBufferReceive_CallbackFunctionPointer != NULL)
    call_instance = CMOCK_GUTS_NONE;
  call_instance = Mock.xStreamBufferSend_CallInstance;
  if (Mock.xStreamBufferSend_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_xStreamBufferSend);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == call_instance, cmock_line, CMockStringCalledLess);
  UNITY_CLR_DETAILS();
  if (Mock.xStreamBufferSend_CallbackFunctionPointer != NULL)
    call_instance = CMOCK_GUTS_NONE;
}

void mock_message_buffer_Init(void)
{
  mock_message_buffer_Destroy();
}

void mock_message_buffer_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

StreamBufferHandle_t xStreamBufferGenericCreate(size_t xBufferSizeBytes, size_t xTriggerLevelBytes, BaseType_t xIsMessageBuffer)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_xStreamBufferGenericCreate);
  cmock_call_instance = (CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.xStreamBufferGenericCreate_CallInstance);
  Mock.xStreamBufferGenericCreate_CallInstance = CMock_Guts_MemNext(Mock.xStreamBufferGenericCreate_CallInstance);
  if (Mock.xStreamBufferGenericCreate_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.xStreamBufferGenericCreate_FinalReturn;
    memcpy((void*)(&Mock.xStreamBufferGenericCreate_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(StreamBufferHandle_t[sizeof(cmock_call_instance->ReturnVal) == sizeof(StreamBufferHandle_t) ? 1 : -1])); /* add StreamBufferHandle_t to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.xStreamBufferGenericCreate_CallbackBool &&
      Mock.xStreamBufferGenericCreate_CallbackFunctionPointer != NULL)
  {
    StreamBufferHandle_t cmock_cb_ret = Mock.xStreamBufferGenericCreate_CallbackFunctionPointer(xBufferSizeBytes, xTriggerLevelBytes, xIsMessageBuffer, Mock.xStreamBufferGenericCreate_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_xStreamBufferGenericCreate,CMockString_xBufferSizeBytes);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_xBufferSizeBytes), (void*)(&xBufferSizeBytes), sizeof(size_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_xStreamBufferGenericCreate,CMockString_xTriggerLevelBytes);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_xTriggerLevelBytes), (void*)(&xTriggerLevelBytes), sizeof(size_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_xStreamBufferGenericCreate,CMockString_xIsMessageBuffer);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_xIsMessageBuffer), (void*)(&xIsMessageBuffer), sizeof(BaseType_t), cmock_line, CMockStringMismatch);
  }
  if (Mock.xStreamBufferGenericCreate_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.xStreamBufferGenericCreate_CallbackFunctionPointer(xBufferSizeBytes, xTriggerLevelBytes, xIsMessageBuffer, Mock.xStreamBufferGenericCreate_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_xStreamBufferGenericCreate(CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE* cmock_call_instance, size_t xBufferSizeBytes, size_t xTriggerLevelBytes, BaseType_t xIsMessageBuffer);
void CMockExpectParameters_xStreamBufferGenericCreate(CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE* cmock_call_instance, size_t xBufferSizeBytes, size_t xTriggerLevelBytes, BaseType_t xIsMessageBuffer)
{
  memcpy((void*)(&cmock_call_instance->Expected_xBufferSizeBytes), (void*)(&xBufferSizeBytes),
         sizeof(size_t[sizeof(xBufferSizeBytes) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
  memcpy((void*)(&cmock_call_instance->Expected_xTriggerLevelBytes), (void*)(&xTriggerLevelBytes),
         sizeof(size_t[sizeof(xTriggerLevelBytes) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
  memcpy((void*)(&cmock_call_instance->Expected_xIsMessageBuffer), (void*)(&xIsMessageBuffer),
         sizeof(BaseType_t[sizeof(xIsMessageBuffer) == sizeof(BaseType_t) ? 1 : -1])); /* add BaseType_t to :treat_as_array if this causes an error */
}

void xStreamBufferGenericCreate_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, StreamBufferHandle_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE));
  CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE* cmock_call_instance = (CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.xStreamBufferGenericCreate_CallInstance = CMock_Guts_MemChain(Mock.xStreamBufferGenericCreate_CallInstance, cmock_guts_index);
  Mock.xStreamBufferGenericCreate_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.xStreamBufferGenericCreate_IgnoreBool = (int)1;
}

void xStreamBufferGenericCreate_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, size_t xBufferSizeBytes, size_t xTriggerLevelBytes, BaseType_t xIsMessageBuffer, StreamBufferHandle_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE));
  CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE* cmock_call_instance = (CMOCK_xStreamBufferGenericCreate_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.xStreamBufferGenericCreate_CallInstance = CMock_Guts_MemChain(Mock.xStreamBufferGenericCreate_CallInstance, cmock_guts_index);
  Mock.xStreamBufferGenericCreate_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_xStreamBufferGenericCreate(cmock_call_instance, xBufferSizeBytes, xTriggerLevelBytes, xIsMessageBuffer);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(StreamBufferHandle_t[sizeof(cmock_to_return) == sizeof(StreamBufferHandle_t) ? 1 : -1])); /* add StreamBufferHandle_t to :treat_as_array if this causes an error */
}

void xStreamBufferGenericCreate_AddCallback(CMOCK_xStreamBufferGenericCreate_CALLBACK Callback)
{
  Mock.xStreamBufferGenericCreate_IgnoreBool = (int)0;
  Mock.xStreamBufferGenericCreate_CallbackBool = (int)1;
  Mock.xStreamBufferGenericCreate_CallbackFunctionPointer = Callback;
}

void xStreamBufferGenericCreate_Stub(CMOCK_xStreamBufferGenericCreate_CALLBACK Callback)
{
  Mock.xStreamBufferGenericCreate_IgnoreBool = (int)0;
  Mock.xStreamBufferGenericCreate_CallbackBool = (int)0;
  Mock.xStreamBufferGenericCreate_CallbackFunctionPointer = Callback;
}

size_t xStreamBufferReceive(StreamBufferHandle_t xStreamBuffer, void* pvRxData, size_t xBufferLengthBytes, TickType_t xTicksToWait)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_xStreamBufferReceive_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_xStreamBufferReceive);
  cmock_call_instance = (CMOCK_xStreamBufferReceive_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.xStreamBufferReceive_CallInstance);
  Mock.xStreamBufferReceive_CallInstance = CMock_Guts_MemNext(Mock.xStreamBufferReceive_CallInstance);
  if (Mock.xStreamBufferReceive_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.xStreamBufferReceive_FinalReturn;
    memcpy((void*)(&Mock.xStreamBufferReceive_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(size_t[sizeof(cmock_call_instance->ReturnVal) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.xStreamBufferReceive_CallbackBool &&
      Mock.xStreamBufferReceive_CallbackFunctionPointer != NULL)
  {
    size_t cmock_cb_ret = Mock.xStreamBufferReceive_CallbackFunctionPointer(xStreamBuffer, pvRxData, xBufferLengthBytes, xTicksToWait, Mock.xStreamBufferReceive_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_xStreamBufferReceive,CMockString_xStreamBuffer);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_xStreamBuffer), (void*)(&xStreamBuffer), sizeof(StreamBufferHandle_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_xStreamBufferReceive,CMockString_pvRxData);
    if (cmock_call_instance->Expected_pvRxData == NULL)
      { UNITY_TEST_ASSERT_NULL(pvRxData, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_pvRxData, pvRxData, 1, cmock_line, CMockStringMismatch); }
  }
  {
    UNITY_SET_DETAILS(CMockString_xStreamBufferReceive,CMockString_xBufferLengthBytes);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_xBufferLengthBytes), (void*)(&xBufferLengthBytes), sizeof(size_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_xStreamBufferReceive,CMockString_xTicksToWait);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_xTicksToWait), (void*)(&xTicksToWait), sizeof(TickType_t), cmock_line, CMockStringMismatch);
  }
  if (Mock.xStreamBufferReceive_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.xStreamBufferReceive_CallbackFunctionPointer(xStreamBuffer, pvRxData, xBufferLengthBytes, xTicksToWait, Mock.xStreamBufferReceive_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_xStreamBufferReceive(CMOCK_xStreamBufferReceive_CALL_INSTANCE* cmock_call_instance, StreamBufferHandle_t xStreamBuffer, void* pvRxData, size_t xBufferLengthBytes, TickType_t xTicksToWait);
void CMockExpectParameters_xStreamBufferReceive(CMOCK_xStreamBufferReceive_CALL_INSTANCE* cmock_call_instance, StreamBufferHandle_t xStreamBuffer, void* pvRxData, size_t xBufferLengthBytes, TickType_t xTicksToWait)
{
  memcpy((void*)(&cmock_call_instance->Expected_xStreamBuffer), (void*)(&xStreamBuffer),
         sizeof(StreamBufferHandle_t[sizeof(xStreamBuffer) == sizeof(StreamBufferHandle_t) ? 1 : -1])); /* add StreamBufferHandle_t to :treat_as_array if this causes an error */
  cmock_call_instance->Expected_pvRxData = pvRxData;
  memcpy((void*)(&cmock_call_instance->Expected_xBufferLengthBytes), (void*)(&xBufferLengthBytes),
         sizeof(size_t[sizeof(xBufferLengthBytes) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
  memcpy((void*)(&cmock_call_instance->Expected_xTicksToWait), (void*)(&xTicksToWait),
         sizeof(TickType_t[sizeof(xTicksToWait) == sizeof(TickType_t) ? 1 : -1])); /* add TickType_t to :treat_as_array if this causes an error */
}

void xStreamBufferReceive_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, size_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_xStreamBufferReceive_CALL_INSTANCE));
  CMOCK_xStreamBufferReceive_CALL_INSTANCE* cmock_call_instance = (CMOCK_xStreamBufferReceive_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.xStreamBufferReceive_CallInstance = CMock_Guts_MemChain(Mock.xStreamBufferReceive_CallInstance, cmock_guts_index);
  Mock.xStreamBufferReceive_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.xStreamBufferReceive_IgnoreBool = (int)1;
}

void xStreamBufferReceive_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, StreamBufferHandle_t xStreamBuffer, void* pvRxData, size_t xBufferLengthBytes, TickType_t xTicksToWait, size_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_xStreamBufferReceive_CALL_INSTANCE));
  CMOCK_xStreamBufferReceive_CALL_INSTANCE* cmock_call_instance = (CMOCK_xStreamBufferReceive_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.xStreamBufferReceive_CallInstance = CMock_Guts_MemChain(Mock.xStreamBufferReceive_CallInstance, cmock_guts_index);
  Mock.xStreamBufferReceive_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_xStreamBufferReceive(cmock_call_instance, xStreamBuffer, pvRxData, xBufferLengthBytes, xTicksToWait);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(size_t[sizeof(cmock_to_return) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
}

void xStreamBufferReceive_AddCallback(CMOCK_xStreamBufferReceive_CALLBACK Callback)
{
  Mock.xStreamBufferReceive_IgnoreBool = (int)0;
  Mock.xStreamBufferReceive_CallbackBool = (int)1;
  Mock.xStreamBufferReceive_CallbackFunctionPointer = Callback;
}

void xStreamBufferReceive_Stub(CMOCK_xStreamBufferReceive_CALLBACK Callback)
{
  Mock.xStreamBufferReceive_IgnoreBool = (int)0;
  Mock.xStreamBufferReceive_CallbackBool = (int)0;
  Mock.xStreamBufferReceive_CallbackFunctionPointer = Callback;
}

size_t xStreamBufferSend(StreamBufferHandle_t xStreamBuffer, const void* pvTxData, size_t xDataLengthBytes, TickType_t xTicksToWait)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_xStreamBufferSend_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_xStreamBufferSend);
  cmock_call_instance = (CMOCK_xStreamBufferSend_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.xStreamBufferSend_CallInstance);
  Mock.xStreamBufferSend_CallInstance = CMock_Guts_MemNext(Mock.xStreamBufferSend_CallInstance);
  if (Mock.xStreamBufferSend_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.xStreamBufferSend_FinalReturn;
    memcpy((void*)(&Mock.xStreamBufferSend_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(size_t[sizeof(cmock_call_instance->ReturnVal) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.xStreamBufferSend_CallbackBool &&
      Mock.xStreamBufferSend_CallbackFunctionPointer != NULL)
  {
    size_t cmock_cb_ret = Mock.xStreamBufferSend_CallbackFunctionPointer(xStreamBuffer, pvTxData, xDataLengthBytes, xTicksToWait, Mock.xStreamBufferSend_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_xStreamBufferSend,CMockString_xStreamBuffer);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_xStreamBuffer), (void*)(&xStreamBuffer), sizeof(StreamBufferHandle_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_xStreamBufferSend,CMockString_pvTxData);
    if (cmock_call_instance->Expected_pvTxData == NULL)
      { UNITY_TEST_ASSERT_NULL(pvTxData, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_pvTxData, pvTxData, 1, cmock_line, CMockStringMismatch); }
  }
  {
    UNITY_SET_DETAILS(CMockString_xStreamBufferSend,CMockString_xDataLengthBytes);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_xDataLengthBytes), (void*)(&xDataLengthBytes), sizeof(size_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_xStreamBufferSend,CMockString_xTicksToWait);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_xTicksToWait), (void*)(&xTicksToWait), sizeof(TickType_t), cmock_line, CMockStringMismatch);
  }
  if (Mock.xStreamBufferSend_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.xStreamBufferSend_CallbackFunctionPointer(xStreamBuffer, pvTxData, xDataLengthBytes, xTicksToWait, Mock.xStreamBufferSend_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_xStreamBufferSend(CMOCK_xStreamBufferSend_CALL_INSTANCE* cmock_call_instance, StreamBufferHandle_t xStreamBuffer, const void* pvTxData, size_t xDataLengthBytes, TickType_t xTicksToWait);
void CMockExpectParameters_xStreamBufferSend(CMOCK_xStreamBufferSend_CALL_INSTANCE* cmock_call_instance, StreamBufferHandle_t xStreamBuffer, const void* pvTxData, size_t xDataLengthBytes, TickType_t xTicksToWait)
{
  memcpy((void*)(&cmock_call_instance->Expected_xStreamBuffer), (void*)(&xStreamBuffer),
         sizeof(StreamBufferHandle_t[sizeof(xStreamBuffer) == sizeof(StreamBufferHandle_t) ? 1 : -1])); /* add StreamBufferHandle_t to :treat_as_array if this causes an error */
  cmock_call_instance->Expected_pvTxData = pvTxData;
  memcpy((void*)(&cmock_call_instance->Expected_xDataLengthBytes), (void*)(&xDataLengthBytes),
         sizeof(size_t[sizeof(xDataLengthBytes) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
  memcpy((void*)(&cmock_call_instance->Expected_xTicksToWait), (void*)(&xTicksToWait),
         sizeof(TickType_t[sizeof(xTicksToWait) == sizeof(TickType_t) ? 1 : -1])); /* add TickType_t to :treat_as_array if this causes an error */
}

void xStreamBufferSend_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, size_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_xStreamBufferSend_CALL_INSTANCE));
  CMOCK_xStreamBufferSend_CALL_INSTANCE* cmock_call_instance = (CMOCK_xStreamBufferSend_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.xStreamBufferSend_CallInstance = CMock_Guts_MemChain(Mock.xStreamBufferSend_CallInstance, cmock_guts_index);
  Mock.xStreamBufferSend_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.xStreamBufferSend_IgnoreBool = (int)1;
}

void xStreamBufferSend_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, StreamBufferHandle_t xStreamBuffer, const void* pvTxData, size_t xDataLengthBytes, TickType_t xTicksToWait, size_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_xStreamBufferSend_CALL_INSTANCE));
  CMOCK_xStreamBufferSend_CALL_INSTANCE* cmock_call_instance = (CMOCK_xStreamBufferSend_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.xStreamBufferSend_CallInstance = CMock_Guts_MemChain(Mock.xStreamBufferSend_CallInstance, cmock_guts_index);
  Mock.xStreamBufferSend_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_xStreamBufferSend(cmock_call_instance, xStreamBuffer, pvTxData, xDataLengthBytes, xTicksToWait);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(size_t[sizeof(cmock_to_return) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
}

void xStreamBufferSend_AddCallback(CMOCK_xStreamBufferSend_CALLBACK Callback)
{
  Mock.xStreamBufferSend_IgnoreBool = (int)0;
  Mock.xStreamBufferSend_CallbackBool = (int)1;
  Mock.xStreamBufferSend_CallbackFunctionPointer = Callback;
}

void xStreamBufferSend_Stub(CMOCK_xStreamBufferSend_CALLBACK Callback)
{
  Mock.xStreamBufferSend_IgnoreBool = (int)0;
  Mock.xStreamBufferSend_CallbackBool = (int)0;
  Mock.xStreamBufferSend_CallbackFunctionPointer = Callback;
}
