/*
 * Default 60 ANSI Arrow Split Backspace & 7U Space Keymap.
 *
 * Copyright (C) 2020 Sendy YK <https://mr.sendyyk.com>
 *               2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN
};

#define FN_APP LT(1, KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│1  │2  │3  │4  │5  │6  │7  │8  │9  │0  │-  │+  │\  │`  │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
     * │Tab  │Q  │W  │E  │R  │T  │Y  │U  │I  │O  │P  │[  │]  │Bspc │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │Caps  │A  │S  │D  │F  │G  │H  │J  │K  │L  │;  │'  │Enter   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┬───┤
     * │Shift   │Z  │X  │C  │V  │B  │N  │M  │,  │.  │Shift │↑  │/  │
     * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴──┬───┼───┼───┤
     * │Ctrl │GUI│Alt  │Space                      │Fn │←  │↓  │→  │
     * └─────┴───┴─────┴───────────────────────────┴───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_60_ansi_arrow_split_bs_7u_spc(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT, KC_UP,   KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             FN_APP,  KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │Del│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
     * │     │   │↑  │   │   │   │Ins│   │   │   │   │Prt│SLk│Pause│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │      │←  │↓  │→  │   │   │Del│   │   │   │   │   │        │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┬───┤
     * │        │   │   │   │   │   │   │   │   │   │      │PgU│   │
     * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴──┬───┼───┼───┤
     * │     │   │     │                           │   │Hom│PgD│End│
     * └─────┴───┴─────┴───────────────────────────┴───┴───┴───┴───┘
     */
    [_FN] = LAYOUT_60_ansi_arrow_split_bs_7u_spc(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______, _______, KC_UP,   _______, _______, _______, KC_INS,  _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_DEL,  _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
        _______, _______, _______,                            _______,                            _______, KC_HOME, KC_PGDN, KC_END
    ),

};
