/* Copyright 2019 noroadsleft
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

/* Sendstring definitions for the European Portuguese (pt-PT) layout */

#pragma once

#include "keymap_portuguese.h"

const bool ascii_to_shift_lut[0x80] PROGMEM = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,

    0, 1, 1, 1, 1, 1, 1, 0,
    1, 1, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 0, 1, 1, 1,
    0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0
};

const bool ascii_to_altgr_lut[0x80] PROGMEM = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,

    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 1, 0, 0
};

const uint8_t ascii_to_keycode_lut[0x80] PROGMEM = {
    0,       0,       0,       0,       0,       0,       0,       0,
    KC_BSPC, KC_TAB,  KC_ENT,  0,       0,       0,       0,       0,
    0,       0,       0,       0,       0,       0,       0,       0,
    0,       0,       0,       KC_ESC,  0,       0,       0,       0,

    KC_SPC,  PT_1,    PT_2,    PT_3,    PT_4,    PT_5,    PT_6,    PT_QUOT,
    PT_8,    PT_9,    PT_PLUS, PT_PLUS, PT_COMM, PT_MINS, PT_DOT,  PT_7,
    PT_0,    PT_1,    PT_2,    PT_3,    PT_4,    PT_5,    PT_6,    PT_7,
    PT_8,    PT_9,    PT_DOT,  PT_COMM, PT_LABK, PT_0,    PT_LABK, PT_QUOT,
    PT_2,    PT_A,    PT_B,    PT_C,    PT_D,    PT_E,    PT_F,    PT_G,
    PT_H,    PT_I,    PT_J,    PT_K,    PT_L,    PT_M,    PT_N,    PT_O,
    PT_P,    PT_Q,    PT_R,    PT_S,    PT_T,    PT_U,    PT_V,    PT_W,
    PT_X,    PT_Y,    PT_Z,    PT_8,    PT_BSLS, PT_9,    PT_TILD, PT_MINS,
    PT_ACUT, PT_A,    PT_B,    PT_C,    PT_D,    PT_E,    PT_F,    PT_G,
    PT_H,    PT_I,    PT_J,    PT_K,    PT_L,    PT_M,    PT_N,    PT_O,
    PT_P,    PT_Q,    PT_R,    PT_S,    PT_T,    PT_U,    PT_V,    PT_W,
    PT_X,    PT_Y,    PT_Z,    PT_7,    PT_BSLS, PT_0,    PT_TILD, KC_DEL
};
