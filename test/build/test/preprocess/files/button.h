





typedef enum {

  BTN_STATE_NONE = 0,

  BTN_STATE_SHORT,

  BTN_STATE_LONG

} btn_state_t;









typedef uint8_t (*port_read_cb_t)(const uint32_t *port, const uint32_t pin);









typedef void (*btn_ev_cb_t)(uint8_t btn_code);

typedef struct {

  struct {

    btn_state_t act : 2;

    btn_state_t prew : 2;

    uint8_t locked : 1;

  } state;



  uint8_t lock_count;

  uint16_t long_count;



  uint16_t long_press_time_ms;

  const uint32_t *port;

  const uint32_t pin;

} btn_instance_t;











typedef struct {

  btn_instance_t *instance;

  uint8_t count;

  uint8_t process_time_ms;

  uint8_t debounce_time_ms;

  uint16_t long_press_def_ms;



  port_read_cb_t port_read;

  btn_ev_cb_t short_release;

  btn_ev_cb_t long_release;

  btn_ev_cb_t long_press;

} btn_init_t;

int8_t Button_Init(btn_init_t *init, btn_instance_t *instance, uint8_t count);

void Button_Update(void);















btn_state_t Button_EventGet(uint8_t key);
