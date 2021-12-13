#include "unity_config.h"
#include "unity.h"
#include "button.h"

void setUp(void)
{
}

void tearDown(void)
{
}


// ***************************************************************************//
uint8_t dummy_port_read(const uint32_t *port, const uint32_t pin)
{

}

void test_button_init(void)
{
  btn_instance_t btn_inst = {
    .long_press_time_ms = 1000,
    .port = (uint32_t *)0xdeadbeaf,
    .pin = 13,
  };
  btn_init_t btn_init = {
    .process_time_ms = 10,
    .debounce_time_ms = 20,
    .port_read = NULL,
  };

  int8_t ret_code = 3;
  // test negative
  ret_code = Button_Init(NULL, NULL, 0);
  TEST_ASSERT_EQUAL_INT8(-1, ret_code);
  ret_code = Button_Init(&btn_init, NULL, 1);
  TEST_ASSERT_EQUAL_INT8(-1, ret_code);
  ret_code = Button_Init(NULL, &btn_inst, 1);
  TEST_ASSERT_EQUAL_INT8(-1, ret_code);
  ret_code = Button_Init(&btn_init, &btn_inst, 0);
  TEST_ASSERT_EQUAL_INT8(-1, ret_code);

  // btn_init_t struct field .port_read is missing
  ret_code = Button_Init(&btn_init, &btn_inst, 1);
  TEST_ASSERT_EQUAL_INT8(-1, ret_code);

  // test positive
  btn_init.port_read = dummy_port_read;
  ret_code = Button_Init(&btn_init, &btn_inst, 1);
  TEST_ASSERT_EQUAL_INT8(0, ret_code);

  // test internal object link
  TEST_ASSERT_EQUAL_PTR(&btn_inst, btn_init.instance);
  TEST_ASSERT_EQUAL_INT8(1, btn_init.count);
}

// ***************************************************************************//
//                          init_defaults_test                                //
// ***************************************************************************//
void test_init_defaults(void)
{
  // arrange
  // minimum required configuration
  btn_instance_t btn_inst[2] = {
    {
      .port = (uint32_t *)0xdeadbeaf,
      .pin = 13,
    },
    {
      .long_press_time_ms = 2050,
      .port = (uint32_t *)0x12345678,
      .pin = 5,
    },
  };

  btn_init_t btn_init = {
    .port_read = dummy_port_read,
  };

  // act
  int8_t ret_code = Button_Init(&btn_init, btn_inst, 2);

  // assert
  TEST_ASSERT_EQUAL_INT8(0, ret_code);
  TEST_ASSERT_EQUAL_UINT8(10, btn_init.process_time_ms);
  TEST_ASSERT_EQUAL_UINT8(20, btn_init.debounce_time_ms);
  TEST_ASSERT_EQUAL_UINT16(1000, btn_init.long_press_def_ms);
  TEST_ASSERT_EQUAL_UINT16(1000, btn_init.instance[0].long_press_time_ms);
  TEST_ASSERT_EQUAL_UINT16(2050, btn_init.instance[1].long_press_time_ms);
}

// ***************************************************************************//
//                            single_button_press                             //
// ***************************************************************************//
uint16_t test_single_button_timer_counter = 0;

uint8_t single_button_port_read(const uint32_t *port, const uint32_t pin)
{
  if ((test_single_button_timer_counter >= 10) && 
      (test_single_button_timer_counter <= 40))   // emulate short press
  {
    return 1;
  }
  else if ((test_single_button_timer_counter >= 1000) &&
           (test_single_button_timer_counter <= 2400))  // emulate 1.4 sec long press and hold
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


void btn_ev_short_release(uint8_t btn_code)
{
  if (0 == test_single_button_timer_counter)
  {
    TEST_FAIL_MESSAGE("Not supposed to happen");
  }

  TEST_ASSERT_EQUAL_UINT8(0, btn_code);
  TEST_ASSERT_EQUAL_UINT32(70, test_single_button_timer_counter);
}

void btn_ev_long_press(uint8_t btn_code)
{
  if (0 == test_single_button_timer_counter)
  {
    TEST_FAIL_MESSAGE("Not supposed to happen");
  }

  TEST_ASSERT_EQUAL_UINT8(0, btn_code);
  TEST_ASSERT_INT16_WITHIN(400, 2000, test_single_button_timer_counter);
}

void btn_ev_long_release(uint8_t btn_code)
{
  if (0 == test_single_button_timer_counter)
  {
    TEST_FAIL_MESSAGE("Not supposed to happen");
  }

  TEST_ASSERT_EQUAL_UINT8(0, btn_code);
  TEST_ASSERT_EQUAL_UINT32((2400 + 30), test_single_button_timer_counter);
}


void test_single_button_press(void)
{
  btn_instance_t btn_inst = {
    .long_press_time_ms = 1000,
    .port = (uint32_t *)0xdeadbeaf,
    .pin = 13,
  };

  btn_init_t btn_init = {
    .process_time_ms = 10,
    .debounce_time_ms = 20,
    .port_read     = single_button_port_read,
    .short_release = btn_ev_short_release,
    .long_release  = btn_ev_long_release,
    .long_press    = btn_ev_long_press,
  };

  int8_t ret_code = Button_Init(&btn_init, &btn_inst, 1);
  TEST_ASSERT_EQUAL_INT8(0, ret_code);

  while (test_single_button_timer_counter < 3500) 
  {
    Button_Update();
    test_single_button_timer_counter += 10;    // assume that we trigger ISR each 10ms durring 3.5sec period
  }
}

// ***************************************************************************//
//                            multi_button_press                              //
// ***************************************************************************//
uint16_t test_multi_button_timer_counter = 0;

uint8_t multi_button_port_read(const uint32_t *port, const uint32_t pin)
{
  if (13 == pin)
  {
    if ((test_multi_button_timer_counter >= 10) && 
        (test_multi_button_timer_counter <= 40))   // emulate short press
    {
      return 1;
    }
  }
  
  if (5 == pin)
  {
    if ((test_multi_button_timer_counter >= 30) && 
        (test_multi_button_timer_counter <= 50))  // trigger event with 10ms diff
    {
      return 1;
    }
  }
  return 0;
}

uint8_t btn_1_ev_short_release_flag = 0;
uint8_t btn_2_ev_short_release_flag = 0;

void btn_ev_short_release_2(uint8_t btn_code)
{
  if (0 == test_single_button_timer_counter)
  {
    TEST_FAIL_MESSAGE("Not supposed to happen");
  }

  if (0 == btn_code)
  {
    TEST_ASSERT_EQUAL_UINT8(BTN_STATE_SHORT, Button_EventGet(0));
    TEST_ASSERT_EQUAL_UINT32(70, test_multi_button_timer_counter);
  }

  if (1 == btn_code)
  {
    TEST_ASSERT_EQUAL_UINT8(BTN_STATE_SHORT, Button_EventGet(1));
    TEST_ASSERT_EQUAL_UINT32(80, test_multi_button_timer_counter);
  }
}

void test_multi_button_press(void)
{
  btn_instance_t btn_inst[2] = {
    {
      .port = (uint32_t *)0xdeadbeaf,
      .pin = 13,
    },
    {
      .port = (uint32_t *)0x12345678,
      .pin = 5,
    },
  };

  btn_init_t btn_init = {
    .port_read = multi_button_port_read,
    .short_release = btn_ev_short_release_2
  };

  int8_t ret_code = Button_Init(&btn_init, btn_inst, 2);
  TEST_ASSERT_EQUAL_INT8(0, ret_code);

  while (test_multi_button_timer_counter < 3500) // assume that we trigger ISR each 10ms
  {
    Button_Update();
    test_multi_button_timer_counter += 10;
  }
}


// ***************************************************************************//
//                            button_event_get                                //
// ***************************************************************************//
uint16_t test_button_event_get_timer_counter = 0;

uint8_t button_event_get_port_read(const uint32_t *port, const uint32_t pin)
{
  if (13 == pin)
  {
    if ((test_button_event_get_timer_counter >= 10) && 
        (test_button_event_get_timer_counter <= 40))   // emulate short press
    {
      return 1;
    }
  }
  
  if (5 == pin)
  {
    if ((test_button_event_get_timer_counter >= 1000) &&
        (test_button_event_get_timer_counter <= 2000))  // emulate long press
    {
       return 1;
    }
  }
  return 0;
}

void test_button_event_get(void)
{
  btn_instance_t btn_inst[2] = {
    {
      .port = (uint32_t *)0xdeadbeaf,
      .pin = 13,
    },
    {
      .port = (uint32_t *)0x12345678,
      .pin = 5,
    },
  };

  btn_init_t btn_init = {
    .port_read = button_event_get_port_read,
  };

  int8_t ret_code = Button_Init(&btn_init, btn_inst, 2);
  TEST_ASSERT_EQUAL_INT8(0, ret_code);
  while (test_button_event_get_timer_counter < 3500) // assume that we trigger ISR each 10ms
  {
    Button_Update();
      
    if (test_button_event_get_timer_counter == 70) // check short press test case
    {
      TEST_ASSERT_EQUAL_UINT8(BTN_STATE_SHORT, Button_EventGet(0));
      // check unexisting button
      TEST_ASSERT_EQUAL_UINT8(BTN_STATE_NONE, Button_EventGet(3));
    }
    else if (test_button_event_get_timer_counter == 2000) // long button press
    {
      TEST_ASSERT_EQUAL_UINT8(BTN_STATE_LONG, Button_EventGet(1));
      // check unexisting button
      TEST_ASSERT_EQUAL_UINT8(BTN_STATE_NONE, Button_EventGet(2));
    }

    test_button_event_get_timer_counter += 10;
  }
}