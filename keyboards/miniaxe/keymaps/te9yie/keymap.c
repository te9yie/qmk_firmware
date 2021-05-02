/* Copyright 2018 ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |Ctl/A |Alt/S |   D  |   F  |   G  |           |   H  |   J  |   K  |Alt/L |Ctl/; |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |LT3/GUI|LT2/F13|Sft/Ent|        |LT1/Spc| F14 | GUI  |
 *               `--------------------'           `--------------------'
 */
[0] = LAYOUT( \
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,
    LCTL_T(KC_A),LALT_T(KC_S),KC_D,KC_F,KC_G,KC_H,  KC_J,   KC_K,   RALT_T(KC_L),RCTL_T(KC_SCLN),
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,
                    LT(3,KC_LGUI),LT(2,KC_F13),SFT_T(KC_ENT),LT(1,KC_SPC),KC_F14,KC_RGUI
),

/*
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |Ctl/` |      | Del  |      |      |           | BkSp |Enter | Tab  |Alt/Esc|Ctl/'|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |   -  |   =  |   [  |   ]  |   \  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[1] = LAYOUT( \
    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,
    LCTL_T(KC_GRV),KC_TRNS,KC_DEL, KC_TRNS,KC_TRNS,KC_BSPC,KC_ENT,KC_TAB,RALT_T(KC_ESC),RCTL_T(KC_QUOT),
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MINS,KC_EQL, KC_LBRC,KC_RBRC,KC_BSLS,
                    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
),

/*
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[2] = LAYOUT( \
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
),

/*
 * ,----------------------------------.           ,----------------------------------.
 * | Reset|      |      |      |      |           |   F1 |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |  F11 | F12  |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      | TO(4)|
 *               `--------------------'           `--------------------'
 */
[3] =  LAYOUT( \
    RESET,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_F11, KC_F12, KC_TRNS,KC_TRNS,KC_TRNS,
                    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,TO(4)
),

/*
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  | Enter|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |  ESC |  Tab | Space|           | Space| BkSp | TO(0)|
 *               `--------------------'           `--------------------'
 */
[4] = LAYOUT( \
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,
    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_ENT,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,
                    KC_ESC, KC_TAB, KC_SPC, KC_SPC, KC_BSPC,TO(0)
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
