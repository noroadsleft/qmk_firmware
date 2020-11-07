/* Copyright 2020 Santiago Garcia
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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x1707
#define DEVICE_VER      0x0001
#define MANUFACTURER    Santy
#define PRODUCT         4bar60

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 18

#define MATRIX_ROW_PINS { B8, A0, A1, A2, B13 }
#define MATRIX_COL_PINS { A4, A5, A6, A7, B15, B14, B12, B11, B10, B9, B7, B6, B5, B4, B3, B2, B1, B0 }

#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* 1 Encoder */
#define ENCODERS_PAD_A { A8 }
#define ENCODERS_PAD_B { A15 }
#define TAP_CODE_DELAY 10
#define ENCODER_RESOLUTION 2

#define FORCE_NKRO
