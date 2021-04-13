/*
Base Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2017 Andrew Novak <ndrw.nvk@gmail.com>
Modified 2018 Wayne Jones (WarmCatUK) <waynekjones@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define DEVICE_VER      0x0300

/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 9

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { B7, B3, B2, B1, B0, E6, F0, F1, F4, F5, F6, F7 }
#define MATRIX_COL_PINS { D0, D1, D2, D3, D5, D4, D6, D7, B4 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION ROW2COL

#define LED_NUM_LOCK_PIN C6
#define LED_CAPS_LOCK_PIN C7
#define LED_SCROLL_LOCK_PIN B5

#define BACKLIGHT_PIN B6 // change the backlight pin that has since changed in Rev 3

#define RGBLIGHT_EFFECT_KNIGHT_OFFSET 4
