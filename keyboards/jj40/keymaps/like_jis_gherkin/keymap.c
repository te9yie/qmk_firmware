#include QMK_KEYBOARD_H

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
#define KC_LMOD RGB_MOD
#define KC_KNRM  AG_NORM
#define KC_KSWP  AG_SWAP

#define KC_BTOG  BL_TOGG
#define KC_BINC  BL_INC
#define KC_BDEC  BL_DEC
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

#define KC_P_MN  TD(TD_P_MN)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_P_MN] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_MINS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = KC_LAYOUT_ortho_4x12( \
  //,-----------------------------------------------------------------------------------.
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+------|
      XXXXX,     Q,     W,     E,     R,     T,     Y,     U,     I,     O,  P_MN, XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+------|
      XXXXX,  A_SF,     S,     D,     F,     G,     H,     J,     K,     L,  ENSF, XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+------|
      XXXXX,  Z_CT,     X,     C,  V_RA,     B,     N,  M_RA,  COGU,  DTCT,   SPC, XXXXX \
  //|------+------+------+------+------+------|------+------+------+------+------+------|
  ),

  [_LOWER] = KC_LAYOUT_ortho_4x12( \
  //,-----------------------------------------------------------------------------------.
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+------|
      XXXXX,    F1,    F2,    F3,    F4,    F5,  MINS,   EQL,  JYEN,  LBRC,  RBRC, XXXXX,\
  //|------+------+------+------+------+------+------+------+------+------+------|------|
      XXXXX,    F6,    F7,    F8,    F9,   F10,  LGUI,  SCLN,  QUOT,  BSLS, _____, XXXXX,\
  //|------+------+------+------+------+------+------+------+------+------+------|------|
      XXXXX,   F11,   F12,  LGUI, _____,  BSPC,   SPC, _____,  SLSH,    RO, _____, XXXXX \
  //|------+------+------+------+------+------+------+------+------+------+-------------|
  ),

  [_RAISE] = KC_LAYOUT_ortho_4x12( \
  //,-----------------------------------------------------------------------------------.
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+------|
      XXXXX,     1,     2,     3,     4,     5,     6,     7,     8,     9,     0, XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+------|
      XXXXX,   ESC, XXXXX, XXXXX, KANJI, XXXXX,  LEFT,  DOWN,    UP,  RGHT, _____, XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+------|
      XXXXX,   TAB,  LALT, XXXXX, _____,   DEL, XXXXX, _____, XXXXX, XXXXX, _____, XXXXX \
  //|------+------+------+------+------+-------------+------+------+------+------+------|
  ),

  [_ADJUST] = KC_LAYOUT_ortho_4x12( \
  //,-----------------------------------------------------------------------------------.
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+------|
      XXXXX,   RST,  LRST,  KNRM,  KSWP,  BTOG,  BINC, XXXXX,  HOME,  PGUP, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+------|
      XXXXX,  LTOG,  LHUI,  LSAI,  LVAI,  LVAD,  BDEC, XXXXX,   END,  PGDN, _____, XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+------|
      XXXXX, LMOD,  LHUD,  LSAD, _____, XXXXX, XXXXX, _____, XXXXX, XXXXX, _____, XXXXX \
  //|------+------+------+------+------+-------------+------+------+------+------+------|
  )
};


#ifdef BACKLIGHT_ENABLE
  extern backlight_config_t backlight_config;

  static inline void enable_backright(bool on) {
      backlight_config.enable = on;
      if (backlight_config.raw == 1) // enabled but level = 0
          backlight_config.level = 1;
      eeconfig_update_backlight(backlight_config.raw);
      // dprintf("backlight toggle: %u\n", backlight_config.enable);
      backlight_set(backlight_config.enable ? backlight_config.level : 0);
  }

  uint8_t bl_breath_count;
  uint8_t bl_breath_speed = 10;
  int8_t bl_breath_updown = 1;
  bool bl_breath_on;
  backlight_config_t bl_breath_backup;

  void bl_breath_start(uint8_t speed) {

    bl_breath_on = true;
    bl_breath_speed = speed;
    bl_breath_backup = backlight_config;
  }

  void bl_breath_end(void) {

    bl_breath_on = false;
    backlight_config = bl_breath_backup;
    eeconfig_update_backlight(backlight_config.raw);
    backlight_set(backlight_config.enable ? backlight_config.level : 0);
  }

  void bl_breath_update(void) {

    if (bl_breath_on) {
      ++bl_breath_count;
      if (bl_breath_count > bl_breath_speed) {
        bl_breath_count = 0;

        backlight_config.level += bl_breath_updown;
        bl_breath_updown = (backlight_config.level > BACKLIGHT_LEVELS) ? -1 :
                          (backlight_config.level <= 0) ? 1 :
                          bl_breath_updown;
        enable_backright(true);
      }
    }
  }

  #define BL_BREATH_START bl_breath_start
  #define BL_BREATH_END bl_breath_end
  #define BL_BREATH_UPDATE bl_breath_update

#else

  #define BL_BREATH_START(a)
  #define BL_BREATH_END()
  #define BL_BREATH_UPDATE()
#endif

// Loop
void matrix_scan_user(void) {

  BL_BREATH_UPDATE();
}

// Setting ADJUST layer RGB back to default
static inline void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    BL_BREATH_END();
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case KC_V_RA:
      if (record->event.pressed) {
        BL_BREATH_START(75);
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        BL_BREATH_END();
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return true;
    case KC_M_RA:
      if (record->event.pressed) {
        BL_BREATH_START(100);
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        BL_BREATH_END();
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return true;
    default:
      return true;
  }

  return false;
}
