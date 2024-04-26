/* Copyright 2019 /u/KeepItUnder
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

// LAYERS
enum Layer {
    _QWERTY=0,        // Standard QWERTY layer
    _REGULAR,          // Regular key layer
    _FUNCTION,          // Function key layer
    _COLOUR             // RGB key layer
};
#define _QW _QWERTY
#define _RG _REGULAR
#define _FN _FUNCTION
#define _CLR _COLOUR

// Home row mod keys
// Left-hand home row mods
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)

// Right-hand home row mods
#define HM_J RSFT_T(KC_J)
#define HM_K RCTL_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

// // Left-hand home row mods
// #define HM_A KC_A
// #define HM_S KC_S
// #define HM_D KC_D
// #define HM_F KC_F
//
// // Right-hand home row mods
// #define HM_J KC_J
// #define HM_K KC_K
// #define HM_L KC_L
// #define HM_SCLN KC_SCLN


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_all(
    //       2        3        4        5        6        7        8        9        10       11       12       13       14
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    MO(_FN), HM_A,    HM_S,    HM_D,    HM_F,    KC_G,    KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             MO(_FN), KC_RALT, DF(_RG), KC_RCTL
  ),

  [_REGULAR] = LAYOUT_all(
    //       2        3        4        5        6        7        8        9        10       11       12       13       14
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    MO(_FN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             MO(_FN), KC_RALT, DF(_QW), KC_RCTL
  ),

  [_FUNCTION] = LAYOUT_all(
    //       2        3        4        5        6        7        8        9        10       11       12       13       14
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, KC_1,    KC_2,    KC_3,    KC_WH_U, _______, KC_INS,  _______, KC_UP,   KC_PAUS, KC_PGUP, KC_HOME, KC_PSCR, _______,
    _______, KC_4,    KC_5,    KC_6,    KC_WH_D, _______, KC_SCRL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_END,  _______, KC_ENT,
    _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, KC_CALC, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,
    _______, _______, MO(_CLR),                           KC_0,                               _______, KC_APP,  _______, _______
  ),

  [_COLOUR] = LAYOUT_all(
    //       2        3        4        5        6        7        8        9        10       11       12       13       14
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______,                            RGB_TOG,                            _______, _______, _______, _______
  ),
};
