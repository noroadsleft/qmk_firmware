/* Copyright 2018 u/mythosmann
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

// clang-format off
enum layers {
    _BL,
    _FL,
    _OL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * ,-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.
     * |  Esc  |   q   |   w   |   e   |   r   |   t   |   y   |   u   |   i   |   o   |   p   |   '   | Bspc  |
     * |-------'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-------|
     * |  Tab    |   a   |   s   |   d   |   f   |   g   |   h   |   j   |   k   |   l   |   ;   |    Enter    |
     * |---------'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----------|
     * |  Shift     |   z   |   x   |   c   |   v   |   b   |   n   |   m   |   ,   |   .   |   /   |   Shift  |
     * |-------,----'--,----'--,----'-------'-------'-------'-------'-------'--,----'--,----'--,----'--,-------|
     * |  Ctl  |  Alt  |  Fn   |                                               | TgFn  | Left  |  Up   | Right |
     * `-------'-------'-------'-----------------------------------------------'-------'-------'-------'-------'
     */
    [_BL] = LAYOUT_tg3( /* Base */
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SCLN, KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LALT, MO(_FL),                            KC_SPC,                    MO(_OL), KC_LEFT, KC_UP,   KC_RGHT
    ),

    /*
     * ,-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.
     * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |  Del  |
     * |-------'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-------|
     * |  Caps   | Home  | PgUp  |       | RGB   |       |       |   [   |   ]   |   =   |   \   |    Enter    |
     * |---------'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----------|
     * |  Shift     |  End  | PgDn  |       |       |       |       |       |       |       |  Up   |   Shift  |
     * |-------,----'--,----'--,----'-------'-------'-------'-------'-------'--,----'--,----'--,----'--,-------|
     * |  Ctl  |  Win  |  Fn   |                                               |  Fn   | Left  | Down  | Right |
     * `-------'-------'-------'-----------------------------------------------'-------'-------'-------'-------'
     */
    [_FL] = LAYOUT_tg3( /* Function */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_DEL,
        KC_CAPS, KC_HOME, KC_PGUP, _______, RGB_TOG, _______, _______, KC_LBRC, KC_RBRC, KC_EQL,  KC_BSLS,          KC_ENT,
        _______,          KC_END,  KC_PGDN, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_RSFT,
        _______, KC_LGUI, _______,                            _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /*
     * ,-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.
     * |   `   |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |
     * |-------'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-------|
     * | RGB Tog |       |       |       |       |       |       |       |       |       |       |    Enter    |
     * |---------'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----------|
     * |            |       |       |       |       |       |       |       |       |       |  Up   |   Reset  |
     * |-------,----'--,----'--,----'-------'-------'-------'-------'-------'--,----'--,----'--,----'--,-------|
     * |       |       |       |                                               |       |       |       |       |
     * `-------'-------'-------'-----------------------------------------------'-------'-------'-------'-------'
     */
    [_OL] = LAYOUT_tg3( /* Other Function */
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_ENT,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   QK_BOOT,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______
    ),

};
// clang-format on

void update_led(void) {
    if (host_keyboard_led_state().caps_lock == true) { // if caps lock is on
        rgblight_sethsv_at(0, 255, 255, 0);            // turns the first led red
        switch (get_highest_layer(layer_state)) {
            case _BL: // when the base layer is active, turns the LEDs red
                rgblight_sethsv_range(0, 255, 255, 1, 7);
                break;
            case _FL: // when the function layer is active, turns the LEDs cyan
                rgblight_sethsv_range(180, 255, 255, 1, 7);
                break;
            default: // if anything else is active, turns the LEDs off. isn't in use, mostly a fallback
                rgblight_sethsv(0, 0, 0);
                break;
        }
    } else { // if caps lock isn't on
        rgblight_sethsv_at(0, 0, 0, 0);
        switch (get_highest_layer(layer_state)) { // same code as above
            case _BL:
                rgblight_sethsv_range(50, 190, 125, 1, 7);
                break;
            case _FL:
                rgblight_sethsv_range(205, 150, 240, 1, 7);
                break;
            default:
                rgblight_sethsv(0, 0, 0);
                break;
        }
    }
}

void led_set_user(uint8_t usb_led) {
    update_led();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    update_led();
    return state;
}
