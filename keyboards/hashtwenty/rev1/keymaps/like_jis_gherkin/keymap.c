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
  RGBRST = SAFE_RANGE
};

enum tapdances{
  TD_P_MN = 0,
};

// Layer Mode aliases
// #define KC_LOWER LOWER
// #define KC_RAISE RAISE
// #define KC_ADJST ADJUST
// #define KC_MLLO  MO(_LOWER)
// #define KC_MLRA  MO(_RAISE)
// #define KC_MLAD  MO(_ADJUST)

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

// #define KC_BTOG  BL_TOGG
// #define KC_BINC  BL_INC
// #define KC_BDEC  BL_DEC
// #define KC_BRTG  BL_BRTG

// #define KC_TBSF  LSFT_T(KC_TAB)
// #define KC_SPSF  LSFT_T(KC_SPC)
// #define KC_ALAP  LALT_T(KC_APP)
// #define KC_JEQL  LSFT(KC_MINS)
#define KC_A_SF  LSFT_T(KC_A)
#define KC_Z_CT  LCTL_T(KC_Z)
// #define KC_X_AL  LALT_T(KC_X)
#define KC_COGU  LGUI_T(KC_COMM)
#define KC_DTCT  LCTL_T(KC_DOT)

#define KC_ENSF  LSFT_T(KC_ENT)
#define KC_SPCT  LCTL_T(KC_SPC)
#define KC_V_RA  LT(_LOWER, KC_V)
#define KC_M_RA  LT(_RAISE, KC_M)

// #define KC_P_MN  TD(TD_P_MN)

// qk_tap_dance_action_t tap_dance_actions[] = {
//   [TD_P_MN] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_MINS),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
          Q,     W,     E,     R,     T,     Y,     U,     I,     O,     P,\
  //|------+------+------+------+------|------+------+------+------+------|
       A_SF,     S,     D,     F,     G,     H,     J,     K,     L,  ENSF,\
  //|------+------+------+------+------|------+------+------+------+------|
       Z_CT,     X,     C,  V_RA,     B,     N,  M_RA,  COGU,  DTCT,   SPC \
  //|------+------+------+------+------|------+------+------+------+------|
  ),

  [_LOWER] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
         F1,    F2,    F3,    F4,    F5,  MINS,   EQL,  JYEN,  LBRC,  RBRC,\
  //|------+------+------+------+------+------+------+------+------+------|
         F6,    F7,    F8,    F9,   F10,  LGUI,  SCLN,  QUOT,  BSLS,  LSFT,\
  //|------+------+------+------+------+------+------+------+------+------|
        F11,   F12,  LGUI, _____,  BSPC,   SPC, _____,  SLSH,    RO,  LCTL \
  //|------+------+------+------+------+------+------+------+------+------|
  ),

  [_RAISE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
          1,     2,     3,     4,     5,     6,     7,     8,     9,     0,\
  //|------+------+------+------+------|------+------+------+------+------|
        ESC, XXXXX, XXXXX, KANJI, XXXXX,  LEFT,  DOWN,    UP,  RGHT,  LSFT,\
  //|------+------+------+------+------|------+------+------+------+------|
        TAB,  LALT, XXXXX, _____,   DEL, XXXXX, _____, XXXXX, XXXXX,  LCTL \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
        RST,  LRST,  KNRM,  KSWP, XXXXX, XXXXX, XXXXX,  HOME,  PGUP, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI,  LVAD, XXXXX, XXXXX,   END,  PGDN, _____,\
  //|------+------+------+------+------|------+------+------+------+------|
      LSMOD,  LHUD,  LSAD, _____, XXXXX, XXXXX, _____, XXXXX, XXXXX, _____ \
  //|------+------+------+------+-------------+------+------+------+------|
  )
};

#ifdef SSD1306OLED
char keylog[24] = {};
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', '-', ' ', '@', ' ', ' ',
    ' ', ';', ':', ' ', ',', '.', '/', ' ', ' ', ' '};

static inline void set_keylog(uint16_t keycode, keyrecord_t *record)
{
  char name = ' ';
  uint8_t leds = host_keyboard_leds();

  if (keycode < 60)
  {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog, sizeof(keylog), "\n%dx%d %2x %c %c %c %c",
           record->event.key.row,
           record->event.key.col,
           keycode,
           name,
          (leds & (1<<USB_LED_NUM_LOCK)) ? 'N' : ' ',
          (leds & (1<<USB_LED_CAPS_LOCK)) ? 'C' : ' ',
          (leds & (1<<USB_LED_SCROLL_LOCK)) ? 'S' : ' '
           );
}
#endif

// define variables for reactive RGB
int RGB_current_mode;

// Setting ADJUST layer RGB back to default
static inline void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef SSD1306OLED
    if (record->event.pressed) {
      set_keylog(keycode, record);
    }
  #endif

  switch (keycode) {
    case KC_V_RA:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return true;
    case KC_M_RA:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return true;
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
#define L_BASE _BASE
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)

const char hash_twenty_logo[]={
  0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
  0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
  0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
  0};

static inline void render_logo(struct CharacterMatrix *matrix) {

  matrix_write(matrix, hash_twenty_logo);
}

const char mac_win_logo[][2][3]={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
static inline void render_status(struct CharacterMatrix *matrix) {

  char buf[24];
  // Render to mode icon
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write(matrix, mac_win_logo[0][0]);
  } else {
    matrix_write(matrix, mac_win_logo[1][0]);
  }

  #ifdef RGBLIGHT_ENABLE
    // snprintf(buf, sizeof(buf), " LED %s mode:%d",
    snprintf(buf, sizeof(buf), "LED %s mode:%d",
    rgblight_config.enable ? "on" : "off", rgblight_config.mode);
    matrix_write(matrix, buf);
  #endif

  matrix_write_P(matrix, PSTR("\n"));
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write(matrix, mac_win_logo[0][1]);
  } else {
    matrix_write(matrix, mac_win_logo[1][1]);
  }

  #ifdef RGBLIGHT_ENABLE
    snprintf(buf, sizeof(buf), " h:%d s:%d v:%d",
    rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
    matrix_write(matrix, buf);
  #endif

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  matrix_write_P(matrix, PSTR("\nLayer: "));
  switch (layer_state) {
    case L_BASE:
      matrix_write_P(matrix, PSTR("Base"));
      break;
    case L_RAISE:
      matrix_write_P(matrix, PSTR("Raise"));
      break;
    case L_LOWER:
      matrix_write_P(matrix, PSTR("Lower"));
      break;
    case L_ADJUST:
      matrix_write_P(matrix, PSTR("Adjust"));
      break;
    default:
      snprintf(buf, sizeof(buf), "%d", (short)layer_state);
      matrix_write(matrix, buf);
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
