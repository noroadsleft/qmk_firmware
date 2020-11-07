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

#include "quantum.h"

#define LAYOUT( \
    K00, K01, K02, K03, K04, K05,    K07, K08, K09,    K0B, K0C, K0D, K0E, K0F, K0H,  K1H, \
    K10, K11, K12, K13, K14, K15,    K17, K18, K19,    K1A, K1B, K1C, K1D, K1E, K1F, K1G, \
    K21, K22, K23, K24, K25, K26,    K27, K28, K29,    K2B, K2C, K2D, K2E, K2F, K2G, \
    K31,      K32, K33, K35,         K37, K38, K39,    K3B, K3C, K3E,      K3F, K3G, \
                                     K47, K48, K49                                   \
) \
{ \
    { K00,   K01,   K02,   K03,   K04,   K05,   KC_NO, K07, K08, K09, KC_NO, K0B,   K0C,   K0D,   K0E,   K0F,   KC_NO, K0H   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   KC_NO, K17, K18, K19, K1A,   K1B,   K1C,   K1D,   K1E,   K1F,   K1G,   K1H   }, \
    { KC_NO, K21,   K22,   K23,   K24,   K25,   K26,   K27, K28, K29, KC_NO, K2B,   K2C,   K2D,   K2E,   K2F,   K2G,   KC_NO }, \
    { KC_NO, K31,   K32,   K33,   KC_NO, K35,   KC_NO, K37, K38, K39, KC_NO, K3B,   K3C,   KC_NO, K3E,   K3F,   K3G,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K47, K48, K49, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
}
