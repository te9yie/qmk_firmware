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
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  RGBRST
};

enum tapdances{
  TD_CODO = 0,
  // TD_MNUB,
};

// Layer Mode aliases
#define KC_LOWER LOWER
#define KC_RAISE RAISE

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

#define KC_ZSFT  LSFT_T(KC_Z)
#define KC_MNSF  LSFT_T(KC_MINS)
#define KC_ESCT  LCTL_T(KC_ESC)
#define KC_TBAL  LALT_T(KC_TAB)
#define KC_11SF  LSFT_T(KC_F11)
#define KC_ALAP  LALT_T(KC_APP)
#define KC_JEQL  LSFT(KC_MINS)
#define KC_WLCK  LALT(KC_L)

#define KC_CODO  TD(TD_CODO)
// #define KC_MNUB  TD(TD_MNUB)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CODO] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),
  // [TD_MNUB] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, LSFT(KC_RO)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
          Q,     W,     E,     R,     T,     Y,     U,     I,     O,     P,\
  //|------+------+------+------+------|------+------+------+------+------|
          A,     S,     D,     F,     G,     H,     J,     K,     L,   ENT,\
  //|------+------+------+------+------|------+------+------+------+------|
       ZSFT,     X,     C,     V,     B,     N,     M,  CODO,    UP,  MNSF,\
  //|------+------+------+------+------|------+------+------+------+------|
       ESCT,  TBAL,  LGUI, LOWER,  BSPC,   SPC, RAISE,  LEFT,  DOWN,  RGHT \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_LOWER] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
         F1,    F2,    F3,    F4,    F5,  MINS,   EQL,  JYEN,  LBRC,  RBRC,\
  //|------+------+------+------+------|------+------+------+------+------|
         F6,    F7,    F8,    F9,   F10, XXXXX, XXXXX,  SCLN,  QUOT,  BSLS,\
  //|------+------+------+------+------|------+------+------+------+------|
       11SF,   F12,    UP, KANJI,   ENT, XXXXX,  COMM,   DOT,  SLSH,    RO,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, _____, _____, _____,   DEL, _____, _____, _____, _____, _____ \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_RAISE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
          1,     2,     3,     4,     5,     6,     7,     8,     9,     0,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,  QUOT,     4,     5,     6,  MINS,\
  //|------+------+------+------+------|------+------+------+------+------|
       LSFT, XXXXX, XXXXX, XXXXX, XXXXX,  SLSH,     1,     2,     3,  PPLS,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, _____, _____, _____,  BSPC,  WLCK, _____,     0,   DOT,  JEQL \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
        RST,  LRST,  KNRM,  KSWP,  CAPS, XXXXX,  WH_L,  WH_U,  HOME,  PGUP,\
  //|------+------+------+------+------|------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI,  SLCK, XXXXX,  WH_R,  WH_D,   END,  PGDN,\
  //|------+------+------+------+------|------+------+------+------+------|
      LSMOD,  LHUD,  LSAD,  LVAD,  NLCK, XXXXX,  BTN1,  BTN2,  MS_U, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
       LSFT, _____, _____, _____, XXXXX, XXXXX, _____,  MS_L,  MS_D,  MS_R \
  //|------+------+------+------+-------------+------+------+------+------|
  )
};

#ifdef SSD1306OLED
char keylog[32] = {};
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', '-', ' ', '@', ' ', ' ',
    ' ', ';', ':', ' ', ',', '.', '/', ' ', ' ', ' '};

static inline void set_keylog(uint16_t keycode, keyrecord_t *record)
{
  uint8_t leds = host_keyboard_leds();
  char name = (keycode < 60) ? code_to_name[keycode] : ' ';
  char num_lock = (leds & (1<<USB_LED_NUM_LOCK)) ? 'N' : ' ';
  char caps_lock = (leds & (1<<USB_LED_CAPS_LOCK)) ? 'C' : ' ';
  char scrl_lock = (leds & (1<<USB_LED_SCROLL_LOCK)) ? 'S' : ' ';
  snprintf(keylog, sizeof(keylog), "\nkm:%dx%d %2x %c lck:%c%c%c",
          record->event.key.row, record->event.key.col,
          keycode, name,
          num_lock, caps_lock, scrl_lock);
}
#endif

// define variables for reactive RGB
int RGB_current_mode;

// Setting ADJUST layer RGB back to default
inline void update_change_layer(bool pressed, uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  pressed ? layer_on(layer1) : layer_off(layer1);
  IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2) ? layer_on(layer3) : layer_off(layer3);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef SSD1306OLED
    if (record->event.pressed) {
      set_keylog(keycode, record);
    }
  #endif

  switch (keycode) {
    case LOWER:
      update_change_layer(record->event.pressed, _LOWER, _RAISE, _ADJUST);
      break;
    case RAISE:
      update_change_layer(record->event.pressed, _RAISE, _LOWER, _ADJUST);
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
      return true;
  }

  return false;
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

//assign the right code to your layers for OLED display
typedef struct {
  uint8_t state;
  char name[8];
}LAYER_DISPLAY_NAME;

#define L_BASE _BASE
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

const LAYER_DISPLAY_NAME layer_display_name[4] = {
  {L_BASE, "Base"},
  {L_LOWER, "Lower"},
  {L_RAISE, "Raise"},
  {L_ADJUST_TRI, "Adjust"}
};

// const char hash_twenty_logo[]={
//   0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//   0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//   0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
//   0};

// static inline void render_logo(struct CharacterMatrix *matrix) {

//   matrix_write(matrix, hash_twenty_logo);
// }

static char render_buf[32];
static inline void render_status(struct CharacterMatrix *matrix) {


  #ifdef RGBLIGHT_ENABLE
    snprintf(render_buf, sizeof(render_buf), "LED%c %2d: hsv:%2d %2d %d",
      rgblight_config.enable ? '*' : '.',
      rgblight_config.mode,
      rgblight_config.hue / RGBLIGHT_HUE_STEP,
      rgblight_config.sat / RGBLIGHT_SAT_STEP,
      rgblight_config.val / RGBLIGHT_VAL_STEP);
    matrix_write(matrix, render_buf);
  #endif

  for (uint8_t i = 0; i < 4; ++i) {
    if (layer_display_name[i].state == layer_state) {
      snprintf(render_buf, sizeof(render_buf), "\nOS:%s Layer:%s",
        keymap_config.swap_lalt_lgui? "win" : "mac",
        layer_display_name[i].name);
      matrix_write(matrix, render_buf);
      break;
    }
  }

  matrix_write(matrix, keylog);
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

  #if DEBUG_TO_SCREEN
    if (debug_enable) {
      return;
    }
  #endif

  matrix_clear(&matrix);
  // if (is_master) {
    render_status(&matrix);
  // } else {
  //   render_logo(&matrix);
  // }

  matrix_update(&display, &matrix);
}

#endif
