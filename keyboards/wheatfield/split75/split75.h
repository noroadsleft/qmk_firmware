/* Copyright 2020-2021 Artjoms Rizihs (@artjomsR), Johannes Krude (@johannesk)
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

#define ___ KC_NO

// Number of keys in rows
// 0 + 7 / 9
// 2 + 7 / 8
// 2 + 6 / 9
// 2 + 6 / 8
// 2 + 6 / 8
// 2 + 5 / 7

#define LAYOUT( \
                K50, K51, K52, K53, K54, K55, K56,   K57, K58, K59, K5A, K5B, K5C, K5D, K68, K78, \
    K74, K64,   K40, K41, K42, K43, K44, K45, K46,   K47, K48, K49, K4A, K4B, K4C,      K69, K79, \
    K73, K63,   K30, K31, K32, K33, K34, K35,        K37, K38, K39, K3A, K3B, K3C, K3D, K6A, K7A, \
    K72, K62,   K20, K21, K22, K23, K24, K25,        K27, K28, K29, K2A, K2B, K2C,      K6B, K7B, \
    K71, K61,   K10,      K12, K13, K14, K15, K16,   K17, K18, K19, K1A, K1B,      K1D, K6C, K7C, \
    K70, K60,   K00, K01, K02,      K03,      K04,   K07,           K0A, K0B, K0C, K0D, K6D, K7D  \
){ \
    { K00, K01, K02, K03, K04, ___, ___, K07, ___, ___, K0A, K0B, K0C, K0D }, \
    { K10, ___, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, ___, K1D }, \
    { K20, K21, K22, K23, K24, K25, ___, K27, K28, K29, K2A, K2B, K2C, ___ }, \
    { K30, K31, K32, K33, K34, K35, ___, K37, K38, K39, K3A, K3B, K3C, K3D }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, ___ }, \
    { K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D }, \
    { K60, K61, K62, K63, K64, ___, ___, ___, K68, K69, K6A, K6B, K6C, K6D }, \
    { K70, K71, K72, K73, K74, ___, ___, ___, K78, K79, K7A, K7B, K7C, K7D }  \
}

#define LAYOUT_iso( \
                K50, K51, K52, K53, K54, K55, K56,   K57, K58, K59, K5A, K5B, K5C, K5D, K68, K78, \
    K74, K64,   K40, K41, K42, K43, K44, K45, K46,   K47, K48, K49, K4A, K4B, K4C,      K69, K79, \
    K73, K63,   K30, K31, K32, K33, K34, K35,        K37, K38, K39, K3A, K3B, K3C, K3D,      K7A, \
    K72, K62,   K20, K21, K22, K23, K24, K25,        K27, K28, K29, K2A, K2B, K2C, K2D, K6B, K7B, \
    K71, K61,   K10, K11, K12, K13, K14, K15, K16,   K17, K18, K19, K1A, K1B,      K1D, K6C, K7C, \
    K70, K60,   K00, K01, K02,      K03,      K04,   K07,           K0A, K0B, K0C, K0D, K6D, K7D  \
){ \
    { K00, K01, K02, K03, K04, ___, ___, K07, ___, ___, K0A, K0B, K0C, K0D }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, ___, K1D }, \
    { K20, K21, K22, K23, K24, K25, ___, K27, K28, K29, K2A, K2B, K2C, K2D }, \
    { K30, K31, K32, K33, K34, K35, ___, K37, K38, K39, K3A, K3B, K3C, K3D }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, ___ }, \
    { K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D }, \
    { K60, K61, K62, K63, K64, ___, ___, ___, K68, K69, ___, K6B, K6C, K6D }, \
    { K70, K71, K72, K73, K74, ___, ___, ___, K78, K79, K7A, K7B, K7C, K7D }  \
}
