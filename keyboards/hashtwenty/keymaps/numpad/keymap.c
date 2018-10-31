#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
  _LOWER,
  _ADJUST,
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  ADJUST,
  RGBRST
};

// enum tapdances{
//   TD_CONDOT = 0,
//   TD_MINUB,
// };

// Layer Mode aliases
#define KC_DLBAS BASE //DF(_BASE)
#define KC_MLLO  LOWER//MO(_LOWER)
#define KC_DLADJ ADJUST//DF(_ADJUST)

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_KANJI KC_GRV

#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LSMOD RGB_SMOD
#define KC_KNRM  AG_NORM
#define KC_KSWP  AG_SWAP

#define KC_RSBR  LSFT(KC_8)
#define KC_REBR  LSFT(KC_9)

#define KP_00 0	// keypad "double 0"
#define KC_KP00  M(KP_00)

// #define KC_CODO  TD(TD_CONDOT)
// #define KC_MNUB  TD(TD_MINUB)

// qk_tap_dance_action_t tap_dance_actions[] = {
//   [TD_CONDOT] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),
//   [TD_MINUB] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, LSFT(KC_RO)),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
         P7,    P8,    P9,  QUOT,  BSPC, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
         P4,    P5,    P6,  PMNS,  PSLS, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
         P1,    P2,    P3,  PPLS,  PAST, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       MLLO,    P0,  PDOT,   SPC,  PENT, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_LOWER] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
          A,     B,     C,  HASH,   DEL, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
          D,     E,     F,  PEQL,  PERC, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       RSBR,  REBR,  RBRC,  BSLS,  UNDS, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____,  KP00,  PCMM,   TAB, DLADJ, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
        RST,  LRST,  KNRM,  KSWP, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      LSMOD,  LHUD,  LSAD,  LVAD,  NLCK, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, _____, _____, DLBAS, _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    // keypad "double 0"
    case KP_00:
      if (record->event.pressed) {
        return MACRO( T(KP_0), D(KP_0), END );
      } else {
        return MACRO( U(KP_0), END );
      }
      break;
  }
  return MACRO_NONE;
};

#ifdef SSD1306OLED
static char keylog_buf[24] = "Key state ready.";
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', '-', ' ', '@', ' ', ' ',
    ' ', ';', ':', ' ', ',', '.', '/', ' ', ' ', ' '};

static inline void set_keylog(uint16_t keycode, keyrecord_t *record)
{
  char name = (keycode < 60) ? code_to_name[keycode] : ' ';
  snprintf(keylog_buf, sizeof(keylog_buf) - 1, "Key:%dx%d %2x %c",
          record->event.key.row, record->event.key.col,
          (uint16_t)keycode, name);
}

static char lock_buf[24] = "Lock state ready.\n";
static inline void set_lock_buf(void)
{
  uint8_t leds = host_keyboard_leds();
  char *num_lock = (leds & (1<<USB_LED_NUM_LOCK)) ? "Num" : "";
  char *caps_lock = (leds & (1<<USB_LED_CAPS_LOCK)) ? "Caps" : "";
  char *scrl_lock = (leds & (1<<USB_LED_SCROLL_LOCK)) ? "Scrn" : "";
  snprintf(lock_buf, sizeof(lock_buf) - 1, "Lock:%s %s %s\n",
          num_lock, caps_lock, scrl_lock);
}

//assign the right code to your layers for OLED display
typedef struct {
  uint8_t state;
  char name[8];
}LAYER_DISPLAY_NAME;

#define L_BASE _BASE
#define L_LOWER (1<<_LOWER)
#define L_ADJUST (1<<_ADJUST)

const LAYER_DISPLAY_NAME layer_display_name[4] = {
  {L_BASE, "Base"},
  {L_BASE + 1, "Base"},
  {L_LOWER, "Lower"},
  {L_ADJUST, "Adjust"}
};

static inline const char* get_layer_name(void) {

  for (uint8_t i = 0; i < 4; ++i) {
    if (layer_state == 0 && layer_display_name[i].state == default_layer_state) {

      return layer_display_name[i].name;
    } else if (layer_state != 0 && layer_display_name[i].state == layer_state) {

      return layer_display_name[i].name;
    }
  }

  return "?";
}

static char layer_buf[24] = "Layer state ready.\n";
static inline void set_layer_buf(void) {
  snprintf(layer_buf, sizeof(layer_buf) - 1, "OS:%s Layer:%s\n",
    keymap_config.swap_lalt_lgui? "win" : "mac", get_layer_name());
}

#ifdef RGBLIGHT_ENABLE
static char led_buf[24] = "LED state ready.\n";
static rgblight_config_t rgblight_config_bak;
static inline void set_led_buf(void) {

  if (rgblight_config_bak.enable != rgblight_config.enable ||
      rgblight_config_bak.mode != rgblight_config.mode ||
      rgblight_config_bak.hue != rgblight_config.hue ||
      rgblight_config_bak.sat != rgblight_config.sat ||
      rgblight_config_bak.val != rgblight_config.val
  ) {
    snprintf(led_buf, sizeof(led_buf) - 1, "LED%c:%2d hsv:%2d %2d %2d\n",
      rgblight_config.enable ? '*' : '.', (uint8_t)rgblight_config.mode,
      (uint8_t)(rgblight_config.hue / RGBLIGHT_HUE_STEP),
      (uint8_t)(rgblight_config.sat / RGBLIGHT_SAT_STEP),
      (uint8_t)(rgblight_config.val / RGBLIGHT_VAL_STEP));
      rgblight_config_bak = rgblight_config;
  }
}
#endif
#endif

// define variables for reactive RGB
int RGB_current_mode;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef SSD1306OLED
    if (record->event.pressed) {
      set_keylog(keycode, record);
    }
  #endif

  bool result = false;
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        default_layer_set(L_BASE);
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      break;
    case ADJUST:
      if (record->event.pressed) {
        default_layer_set(L_ADJUST);
      }
      break;
    #ifdef RGBLIGHT_ENABLE
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  #ifdef SSD1306OLED
    set_layer_buf();
  #endif
  return result;
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
  #ifdef SSD1306OLED
    iota_gfx_init(!has_usb()); // turns on the display
  #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
  iota_gfx_task();  // this is what updates the display continuously
}

static inline void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

const char hash_twenty_logo[]={
  0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
  0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
  0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
  0};

static inline void render_logo(struct CharacterMatrix *matrix) {

  matrix_write(matrix, hash_twenty_logo);
}

static inline void render_status(struct CharacterMatrix *matrix) {

  #ifdef RGBLIGHT_ENABLE
    set_led_buf();
    matrix_write(matrix, led_buf);
  #endif

  matrix_write(matrix, layer_buf);

  set_lock_buf();
  matrix_write(matrix, lock_buf);

  matrix_write(matrix, keylog_buf);
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

  #if DEBUG_TO_SCREEN
    if (debug_enable) {
      return;
    }
  #endif

  matrix_clear(&matrix);
  if (is_master) {
    render_status(&matrix);
  } else {
    render_logo(&matrix);
  }

  matrix_update(&display, &matrix);
}

#endif
