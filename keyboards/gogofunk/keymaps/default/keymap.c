/* Copyright 2018 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_number {
  _BASE = 0,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_KANJI KC_GRV

#define KC_RST   RESET

#define KC_RSBR  LSFT(KC_8)
#define KC_REBR  LSFT(KC_9)

#define KP_00 0	// keypad "double 0"
#define KC_KP00  M(KP_00)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc(
  //,----------------------------------- // ESC
       NLCK,  PSLS,  PAST,  BSPC,    F1,\
  //|------+------+------+------+------| // TAB
         P7,    P8,    P9,  PERC,    F2,\
  //|------+------+------+------+------| // SPC
         P4,    P5,    P6,  PMNS,    F3,\
  //|------+------+------+------+------| // PCMM
         P1,    P2,    P3,  PPLS,    F4,\
  //|------+------+------+------+------|
         P0,  KP00,  PDOT,  PEQL,  PENT \
  //|------+------+------+------+-------
  ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  switch (id) {
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
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  return true;
}

void matrix_init_user(void) {

}


LEADER_EXTERNS();

static bool flag1 = false;
static bool flag2 = false;

void matrix_scan_user(void) {

  // How to software reset: The numlock does off after then tap to /* -+ .= keys.
  if (leds & (1<<USB_LED_NUM_LOCK)) {
    falg1 = false;
    falg2 = false;
    return;
  }

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_PSLS, KC_PAST) {
      falg1 = true;
    }
    SEQ_TWO_KEYS(KC_PMNS, KC_PPLS) {
      falg2 = true;
    }
    SEQ_TWO_KEYS(KC_PDOT, KC_PEQL) {
      if (falg1 && falg2) {
        SEND_STRING(SS_TAP(RESET));
      }

      falg1 = false;
      falg2 = false;
    }
  }
}

void led_set_user(uint8_t usb_led) {

}
