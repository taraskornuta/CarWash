#include "build/temp/_test_button.c"
#include "../Middlewares/Third_Party/Button/button.h"
#include "D:/projects/STM/CarWash/test/vendor/ceedling/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}







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

    .port_read = 

                ((void *)0)

                    ,

  };



  int8_t ret_code = 3;



  ret_code = Button_Init(

                        ((void *)0)

                            , 

                              ((void *)0)

                                  , 0);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-1)), (UNITY_INT)(UNITY_INT8 )((ret_code)), (

 ((void *)0)

 ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT8);

  ret_code = Button_Init(&btn_init, 

                                   ((void *)0)

                                       , 1);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-1)), (UNITY_INT)(UNITY_INT8 )((ret_code)), (

 ((void *)0)

 ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT8);

  ret_code = Button_Init(

                        ((void *)0)

                            , &btn_inst, 1);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-1)), (UNITY_INT)(UNITY_INT8 )((ret_code)), (

 ((void *)0)

 ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT8);

  ret_code = Button_Init(&btn_init, &btn_inst, 0);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-1)), (UNITY_INT)(UNITY_INT8 )((ret_code)), (

 ((void *)0)

 ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT8);



  ret_code = Button_Init(&btn_init, &btn_inst, 1);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-1)), (UNITY_INT)(UNITY_INT8 )((ret_code)), (

 ((void *)0)

 ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT8);



  btn_init.port_read = dummy_port_read;

  ret_code = Button_Init(&btn_init, &btn_inst, 1);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((ret_code)), (

 ((void *)0)

 ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT8);



  UnityAssertEqualNumber((UNITY_INT32)((&btn_inst)), (UNITY_INT32)((btn_init.instance)), (

 ((void *)0)

 ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((1)), (UNITY_INT)(UNITY_INT8 )((btn_init.count)), (

 ((void *)0)

 ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT8);

}





void test_init_defaults(void)

{



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



  int8_t ret_code = Button_Init(&btn_init, btn_inst, 2);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((ret_code)), (

 ((void *)0)

 ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_INT8);



  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((10)), (UNITY_INT)(UNITY_UINT8 )((btn_init.process_time_ms)), (

 ((void *)0)

 ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((20)), (UNITY_INT)(UNITY_UINT8 )((btn_init.debounce_time_ms)), (

 ((void *)0)

 ), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1000)), (UNITY_INT)(UNITY_UINT16)((btn_init.long_press_def_ms)), (

 ((void *)0)

 ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_UINT16);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1000)), (UNITY_INT)(UNITY_UINT16)((btn_init.instance[0].long_press_time_ms)), (

 ((void *)0)

 ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_UINT16);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((2050)), (UNITY_INT)(UNITY_UINT16)((btn_init.instance[1].long_press_time_ms)), (

 ((void *)0)

 ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_UINT16);

}





uint16_t test_single_button_timer_counter = 0;



uint8_t single_button_port_read(const uint32_t *port, const uint32_t pin)

{

  if ((test_single_button_timer_counter >= 10) && (test_single_button_timer_counter <= 40))

  {

    return 1;

  }

  else if ((test_single_button_timer_counter >= 1000) && (test_single_button_timer_counter <= 2400))

  {

    return 1;

  }

  else

  {

    return 0;

  }

}





uint8_t btn_ev_short_release_flag = 0;

void btn_ev_short_release(uint8_t btn_code)

{

  if (0 == test_single_button_timer_counter)

  {

    UnityFail( (("Not supposed to happen")), (UNITY_UINT)(109));

  }



  btn_ev_short_release_flag = 1;

}



uint8_t btn_ev_long_press_flag = 0;

void btn_ev_long_press(uint8_t btn_code)

{

  if (0 == test_single_button_timer_counter)

  {

    UnityFail( (("Not supposed to happen")), (UNITY_UINT)(120));

  }



  btn_ev_long_press_flag = 1;

}



uint8_t btn_ev_long_release_flag = 0;

void btn_ev_long_release(uint8_t btn_code)

{

  if (0 == test_single_button_timer_counter)

  {

    UnityFail( (("Not supposed to happen")), (UNITY_UINT)(131));

  }



  btn_ev_long_release_flag = 1;

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

    .port_read = single_button_port_read,

    .short_release = btn_ev_short_release,

    .long_release = btn_ev_long_release,

    .long_press = btn_ev_long_press,

  };



  int8_t ret_code = Button_Init(&btn_init, &btn_inst, 1);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((ret_code)), (

 ((void *)0)

 ), (UNITY_UINT)(156), UNITY_DISPLAY_STYLE_INT8);



  while (test_single_button_timer_counter < 3500)

  {

    Button_Update();



    if (test_single_button_timer_counter == 80)

    {

      UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((1)), (UNITY_INT)(UNITY_INT8 )((btn_ev_short_release_flag)), (

     ((void *)0)

     ), (UNITY_UINT)(164), UNITY_DISPLAY_STYLE_INT8);

    }

    else if (test_single_button_timer_counter == (2010))

    {

      UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((1)), (UNITY_INT)(UNITY_INT8 )((btn_ev_long_press_flag)), (

     ((void *)0)

     ), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_INT8);

    }

    else if (test_single_button_timer_counter == (2400 + 40))

    {

      UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((1)), (UNITY_INT)(UNITY_INT8 )((btn_ev_long_release_flag)), (

     ((void *)0)

     ), (UNITY_UINT)(172), UNITY_DISPLAY_STYLE_INT8);

    }

    test_single_button_timer_counter += 10;

  }

}





uint16_t test_multi_button_timer_counter = 0;



uint8_t multi_button_port_read(const uint32_t *port, const uint32_t pin)

{

  if (13 == pin)

  {

    if ((test_multi_button_timer_counter >= 10) && (test_multi_button_timer_counter <= 40))

    {

      return 1;

    }

  }



  if (5 == pin)

  {

    if ((test_multi_button_timer_counter >= 30) && (test_multi_button_timer_counter <= 50))

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

    UnityFail( (("Not supposed to happen")), (UNITY_UINT)(208));

  }



  if (0 == btn_code) btn_1_ev_short_release_flag = 1;

  if (1 == btn_code) btn_2_ev_short_release_flag = 1;

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

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((ret_code)), (

 ((void *)0)

 ), (UNITY_UINT)(234), UNITY_DISPLAY_STYLE_INT8);



  while (test_multi_button_timer_counter < 3500)

  {

    Button_Update();



    if (test_multi_button_timer_counter == 80)

    {

      UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((1)), (UNITY_INT)(UNITY_INT8 )((btn_1_ev_short_release_flag)), (

     ((void *)0)

     ), (UNITY_UINT)(242), UNITY_DISPLAY_STYLE_INT8);

    }

    else if (test_multi_button_timer_counter == 90)

    {

      UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((1)), (UNITY_INT)(UNITY_INT8 )((btn_2_ev_short_release_flag)), (

     ((void *)0)

     ), (UNITY_UINT)(246), UNITY_DISPLAY_STYLE_INT8);

    }

    test_multi_button_timer_counter += 10;

  }

}





uint16_t test_button_event_get_timer_counter = 0;



uint8_t button_event_get_port_read(const uint32_t *port, const uint32_t pin)

{

  if (13 == pin)

  {

    if ((test_button_event_get_timer_counter >= 10) && (test_button_event_get_timer_counter <= 40))

    {

      return 1;

    }

  }



  if (5 == pin)

  {

    if ((test_button_event_get_timer_counter >= 1000) && (test_button_event_get_timer_counter <= 2000))

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

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((ret_code)), (

 ((void *)0)

 ), (UNITY_UINT)(293), UNITY_DISPLAY_STYLE_INT8);

  while (test_button_event_get_timer_counter < 3500)

  {

    Button_Update();



    if (test_button_event_get_timer_counter == 80)

    {

      UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((BTN_STATE_SHORT)), (UNITY_INT)(UNITY_INT8 )((Button_EventGet(0))), (

     ((void *)0)

     ), (UNITY_UINT)(300), UNITY_DISPLAY_STYLE_INT8);



      UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((BTN_STATE_NONE)), (UNITY_INT)(UNITY_INT8 )((Button_EventGet(3))), (

     ((void *)0)

     ), (UNITY_UINT)(302), UNITY_DISPLAY_STYLE_INT8);

    }

    else if (test_button_event_get_timer_counter == 2000)

    {

      UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((BTN_STATE_LONG)), (UNITY_INT)(UNITY_INT8 )((Button_EventGet(1))), (

     ((void *)0)

     ), (UNITY_UINT)(306), UNITY_DISPLAY_STYLE_INT8);



      UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((BTN_STATE_NONE)), (UNITY_INT)(UNITY_INT8 )((Button_EventGet(2))), (

     ((void *)0)

     ), (UNITY_UINT)(308), UNITY_DISPLAY_STYLE_INT8);

    }



    test_button_event_get_timer_counter += 10;

  }

}
