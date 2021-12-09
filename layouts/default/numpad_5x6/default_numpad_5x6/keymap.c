/* Copyright 2019-2021 QMK
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
     * ┌───┬───┬───┬───┬───┬───┐
     * │Esc│ ( │ ) │ / │ * │ - │
     * ├───┼───┼───┼───┼───┼───┤
     * │ A │ B │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┼───┼───┤ + │
     * │ C │ D │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┼───┼───┤
     * │ E │ F │ 1 │ 2 │ 3 │   │
     * ├───┼───┼───┴───┼───┤Ent│
     * │Ctl│TG1│ 0     │ . │   │
     * └───┴───┴───────┴───┴───┘
     */
    [0] = LAYOUT_numpad_5x6(
        KC_ESC,  KC_LPRN, KC_RPRN, KC_PSLS, KC_PAST, KC_PMNS,
        KC_A,    KC_B,    KC_P7,   KC_P8,   KC_P9,
        KC_C,    KC_D,    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_E,    KC_F,    KC_P1,   KC_P2,   KC_P3,
        KC_LCTL, TG(1),   KC_P0,            KC_PDOT, KC_PENT
    ),

    /*
     * ┌───┐───┬───┬───┬───┬───┐
     * │Rst│ ( │ ) │ / │ * │ - │
     * └───┘───┌───┬───┬───┬───┐
     * │ A │ B │Hom│ ↑ │PgU│   │
     * ├───┼───├───┼───┼───┤ + │
     * │ C │ D │ ← │   │ → │   │
     * ├───┼───├───┼───┼───┼───┤
     * │ E │ F │End│ ↓ │PgD│   │
     * ├───┼───├───┴───┼───┤Ent│
     * │Ctl│TG1│Insert │Del│   │
     * └───┴───└───────┴───┴───┘
     */
    [1] = LAYOUT_numpad_5x6(
        RESET,   _______, _______, _______, _______, _______,
        _______, _______, KC_HOME, KC_UP,   KC_PGUP,
        _______, _______, KC_LEFT, XXXXXXX, KC_RGHT, _______,
        _______, _______, KC_END,  KC_DOWN, KC_PGDN,
        _______, _______, KC_INS,           KC_DEL,  _______
    )
};
