/* Copyright 2017 Wunder
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

// Layers
enum layers {
  _QW = 0, // QWERTY layer
  _LT,     // Lighting controls
  _FN      // Function layer
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = LAYOUT_ortho_5x15( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME, KC_END,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_PGUP, KC_UP,   KC_PGDN, \
    KC_LCTL, KC_LGUI, KC_LALT, MO(1),   KC_SPC,  KC_SPC,  KC_BSPC, KC_BSPC, KC_RALT, TG(2),   KC_APP,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),
  [1] = LAYOUT_ortho_5x15( \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   RESET,   \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_NO,   KC_NO,   \
    KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_NO,   KC_NO,   RGB_TOG, RGB_RMOD,RGB_MOD, KC_NO,   KC_NO,   KC_NO,   KC_INS,  KC_HOME, KC_PGUP, \
    KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RGB_SPD, RGB_SPI, KC_DEL,  KC_END,  KC_PGDN, \
    KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_VAD, RGB_VAI  \
  ),
  [2] = LAYOUT_ortho_5x15( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PERC, KC_PSLS, KC_PAST, KC_PEQL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC, \
    KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_AGIN, KC_7,    KC_8,    KC_9,    KC_PMNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
    KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,   KC_4,    KC_5,    KC_6,    KC_PPLS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
    KC_NO,   KC_UNDO, KC_NO,   KC_COPY, KC_PSTE, KC_NO,   KC_1,    KC_2,    KC_3,    KC_PENT, KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,  KC_SPC,  KC_0,    KC_0,    KC_DOT,  KC_TRNS, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT  \
  )

};

