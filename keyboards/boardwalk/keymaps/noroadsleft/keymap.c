/*
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
#include "version.h"
#include <sendstring_dvorak.h>

// Layer shorthand
enum layers {
    // BASE LAYERS
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK,
    _MAC,

    // FUNCTION LAYERS
    _FUNC_L,
    _FUNC_R,

    // OTHER LAYERS
    _NUMPAD,
    _MACROS,
    _SYSTEM
};


enum macros {
    // BASE LAYERS
    C_NUBS = SAFE_RANGE,
    KC_P00,
    SEL_ALL,
    UNDO,
    CUT,
    COPY,
    PASTE,
    VRSN
};

#define FN_CAPS LT(_FUNC_L, KC_CAPS)
#define L_BSPC  LT(_FUNC_L, KC_BSPC)
#define R_SPC   LT(_FUNC_R, KC_SPC)
#define FN      MO(_FUNC_L)


/* LAYOUT_2x2u_c
     ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
     │00   │01 │02 │03 │04 │05 │06 │07 │08 │09 │0A │0B │0C │0D   │
     ├─────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────┤
     │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1A │1B │1C │1D   │
     ├─────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────┤
     │20   │21 │22 │23 │24 │25 │26 │27 │28 │29 │2A │2B │2C │2D   │
     ├─────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────┤
     │30   │31 │32 │33 │34 │35 │36 │37 │38 │39 │3A │3B │3C │3D   │
     ├─────┼───┼───┼───┼───┼───┴───┼───┴───┼───┼───┼───┼───┼─────┤
     │40   │41 │42 │43 │44 │  45   │  47   │49 │4A │4B │4C │4D   │
     └─────┴───┴───┴───┴───┴───────┴───────┴───┴───┴───┴───┴─────┘
 */
#define LAYOUT_2x2u_c( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, \
    k40, k41, k42, k43, k44,   k45,      k47,    k49, k4A, k4B, k4C, k4D  \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06,   k07, k08,   k09, k0A, k0B, k0C, k0D }, \
    { k10, k11, k12, k13, k14, k15, k16,   k17, k18,   k19, k1A, k1B, k1C, k1D }, \
    { k20, k21, k22, k23, k24, k25, k26,   k27, k28,   k29, k2A, k2B, k2C, k2D }, \
    { k30, k31, k32, k33, k34, k35, k36,   k37, k38,   k39, k3A, k3B, k3C, k3D }, \
    { k40, k41, k42, k43, k44, k45, KC_NO, k47, KC_NO, k49, k4A, k4B, k4C, k4D } \
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_2x2u_c(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,      KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,      KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, \
        FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,      KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,       KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
        KC_LCTL, C_NUBS,  KC_LGUI, FN,      KC_LALT,          L_BSPC,       R_SPC,            KC_RALT, FN,      KC_RGUI, KC_BSLS, KC_RCTL  \
    ),

    [_FUNC_L] = LAYOUT_2x2u_c(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,       KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
        _______, _______, _______, _______, _______, _______, KC_PSCR,      KC_SLCK, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, \
        _______, _______, _______, _______, _______, _______, _______,      _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, \
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, \
        _______, _______, _______, KC_TRNS, _______,          KC_TRNS,      KC_DEL,           _______, _______, _______, _______, _______  \
    ),

    [_FUNC_R] = LAYOUT_2x2u_c(
        RESET,   DEBUG,   VRSN,    _______, _______, _______, KC_MINS,      _______, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_0,    _______, \
        _______, _______, _______, _______, _______, KC_VOLU, KC_LBRC,      _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_P,    _______, \
        _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_VOLD, KC_HOME,      _______, KC_PMNS, KC_P1,   KC_P2,   KC_P3,   KC_SCLN, KC_PENT, \
        _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_MUTE, KC_END,       _______, KC_PPLS, KC_P0,   KC_P00,  KC_PDOT, KC_SLSH, _______, \
        _______, _______, _______, _______, _______,          _______,      KC_TRNS,          _______, _______, _______, _______, _______  \
    )

};


bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    switch (keycode) {
        case C_NUBS:
            if ( record -> event.pressed ) {
                SEND_STRING(SS_TAP(X_NONUS_BSLASH));
            }
            return false;
        case KC_P00:
            if ( record -> event.pressed ) {
                SEND_STRING(SS_TAP(X_KP_0) SS_TAP(X_KP_0));
            }
            return false;
        case SEL_ALL:
            if ( record -> event.pressed ) {
                if (biton32(layer_state) == _MAC) {
                    SEND_STRING(SS_LGUI("a"));
                } else {
                    SEND_STRING(SS_LCTRL("a"));
                }
            }
            return false;
        case UNDO:
            if ( record -> event.pressed ) {
                if (biton32(layer_state) == _MAC) {
                    SEND_STRING(SS_LGUI("z"));
                } else {
                    SEND_STRING(SS_LCTRL("z"));
                }
            }
            return false;
        case CUT:
            if ( record -> event.pressed ) {
                if (biton32(layer_state) == _MAC) {
                    SEND_STRING(SS_LGUI("x"));
                } else {
                    SEND_STRING(SS_LCTRL("x"));
                }
            }
            return false;
        case COPY:
            if ( record -> event.pressed ) {
                if (biton32(layer_state) == _MAC) {
                    SEND_STRING(SS_LGUI("c"));
                } else {
                    SEND_STRING(SS_LCTRL("c"));
                }
            }
            return false;
        case PASTE:
            if ( record -> event.pressed ) {
                if (biton32(layer_state) == _MAC) {
                    SEND_STRING(SS_LGUI("v"));
                } else {
                    SEND_STRING(SS_LCTRL("v"));
                }
            }
            return false;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING( QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION );
            }
            return false;
    }
    return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
