/* Copyright 2020 Mechlovin'
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
#include <print.h>


// clang-format off
enum custom_keycodes {
    LSTATUS = SAFE_RANGE
};

#define FN_CAPS LT(1,KC_CAPS)
#define FN_APP  LT(1,KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, RESET,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, LSTATUS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, MO(1),
        KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,           KC_SPC,           KC_SPC,           KC_RALT, KC_RGUI, FN_APP,  KC_RCTL
    ),
    [1] = LAYOUT_all(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  RESET,
        _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______,
        _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______
    ),
    [2] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______
    ),
    [3] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______
    ),

};
// clang-format on

void keyboard_post_init_user(void) {
    // Call the post init code.
    // Customise these values to desired behaviour
    debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse=true;
    rgb_matrix_enable_noeeprom();                    // enables RGB Matrix, without saving settings
    rgb_matrix_set_color_all(212, 255, 127);         // sets the color to teal/cyan without saving
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);  // sets mode to Fast breathing without saving
}

/*
    print("string"): Print a simple string.
    uprintf("%s string", var): Print a formatted string
    dprint("string") Print a simple string, but only when debug mode is enabled
    dprintf("%s string", var): Print a formatted string, but only when debug mode is enabled
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // these are our macros!
        case RGB_TOG ... RGB_SPD:
        case LSTATUS:
            if (record->event.pressed) {
                dprintf("rgb matrix [EEPROM]: %u\n  Mode: %u\n  HSV: %u, %u, %u\n  Speed: %u\n  Suspend State: %u\n", rgb_matrix_is_enabled(), rgb_matrix_get_mode(), rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val(), rgb_matrix_get_speed(), rgb_matrix_get_suspend_state());
            }
            return false;
    }  // switch()
    return true;
};
