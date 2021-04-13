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

#include "quantum.h"

#define ___ KC_NO

#define LAYOUT( \
    K50, K52, K53, K54, K55, K60, K6A, K7A, K70, K5B, K5C, K5D, K5E, K1D, K1E, K2E, \
    K40, K41, K42, K43, K44, K45, K61, K6B, K7B, K71, K4A, K4B, K4C, K4E,      K0D, \
    K30, K31, K32, K33, K34, K35, K62, K6C, K7C, K72, K3A, K3B, K3C, K3D,      K76, \
    K20, K21, K22, K23, K24, K25, K63, K6D, K7D, K73, K2A, K2B,      K2D,      K78, \
    K10,      K11, K12, K13, K14, K15, K64, K6E, K7E, K74, K1A,      K1B, K68, K77, \
    K00, K01, K02,                K65,                K75, K0B, K0C, K69, K67, K66  \
) { \
    { K00, K01, K02, ___, ___, ___, ___, ___, ___, ___, ___, K0B, K0C, K0D, ___ }, \
    { K10, K11, K12, K13, K14, K15, ___, ___, ___, ___, K1A, K1B, ___, K1D, K1E }, \
    { K20, K21, K22, K23, K24, K25, ___, ___, ___, ___, K2A, K2B, ___, K2D, K2E }, \
    { K30, K31, K32, K33, K34, K35, ___, ___, ___, ___, K3A, K3B, K3C, K3D, ___ }, \
    { K40, K41, K42, K43, K44, K45, ___, ___, ___, ___, K4A, K4B, K4C, ___, K4E }, \
    { K50, ___, K52, K53, K54, K55, ___, ___, ___, ___, ___, K5B, K5C, K5D, K5E }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, K68, K69, K6A, K6B, K6C, K6D, K6E }, \
    { K70, K71, K72, K73, K74, K75, K76, K77, K78, ___, K7A, K7B, K7C, K7D, K7E }  \
}

#define LAYOUT_75_iso( \
    K50, K52, K53, K54, K55, K60, K6A, K7A, K70, K5B, K5C, K5D, K5E, K1D, K1E, K2E, \
    K40, K41, K42, K43, K44, K45, K61, K6B, K7B, K71, K4A, K4B, K4C, K4E,      K0D, \
    K30, K31, K32, K33, K34, K35, K62, K6C, K7C, K72, K3A, K3B, K3C,           K76, \
    K20, K21, K22, K23, K24, K25, K63, K6D, K7D, K73, K2A, K2B, K2C, K2D,      K78, \
    K10, K03, K11, K12, K13, K14, K15, K64, K6E, K7E, K74, K1A, K1B,      K68, K77, \
    K00, K01, K02,                K65,                K75, K0B, K0C, K69, K67, K66  \
) { \
    { K00, K01, K02, K03, ___, ___, ___, ___, ___, ___, ___, K0B, K0C, K0D, ___ }, \
    { K10, K11, K12, K13, K14, K15, ___, ___, ___, ___, K1A, K1B, ___, K1D, K1E }, \
    { K20, K21, K22, K23, K24, K25, ___, ___, ___, ___, K2A, K2B, K2C, K2D, K2E }, \
    { K30, K31, K32, K33, K34, K35, ___, ___, ___, ___, K3A, K3B, K3C, ___, ___ }, \
    { K40, K41, K42, K43, K44, K45, ___, ___, ___, ___, K4A, K4B, K4C, ___, K4E }, \
    { K50, ___, K52, K53, K54, K55, ___, ___, ___, ___, ___, K5B, K5C, K5D, K5E }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, K68, K69, K6A, K6B, K6C, K6D, K6E }, \
    { K70, K71, K72, K73, K74, K75, K76, K77, K78, ___, K7A, K7B, K7C, K7D, K7E }  \
}

#define LAYOUT_75_iso_rwkl( \
    K50, K52, K53, K54, K55, K60, K6A, K7A, K70, K5B, K5C, K5D, K5E, K1D, K1E, K2E, \
    K40, K41, K42, K43, K44, K45, K61, K6B, K7B, K71, K4A, K4B, K4C, K4E,      K0D, \
    K30, K31, K32, K33, K34, K35, K62, K6C, K7C, K72, K3A, K3B, K3C,           K76, \
    K20, K21, K22, K23, K24, K25, K63, K6D, K7D, K73, K2A, K2B, K2C, K2D,      K78, \
    K10, K03, K11, K12, K13, K14, K15, K64, K6E, K7E, K74, K1A, K1B,      K68, K77, \
    K00, K01, K02,                K65,                K75,   K0C,    K69, K67, K66  \
) { \
    { K00, K01, K02, K03, ___, ___, ___, ___, ___, ___, ___, ___, K0C, K0D, ___ }, \
    { K10, K11, K12, K13, K14, K15, ___, ___, ___, ___, K1A, K1B, ___, K1D, K1E }, \
    { K20, K21, K22, K23, K24, K25, ___, ___, ___, ___, K2A, K2B, K2C, K2D, K2E }, \
    { K30, K31, K32, K33, K34, K35, ___, ___, ___, ___, K3A, K3B, K3C, ___, ___ }, \
    { K40, K41, K42, K43, K44, K45, ___, ___, ___, ___, K4A, K4B, K4C, ___, K4E }, \
    { K50, ___, K52, K53, K54, K55, ___, ___, ___, ___, ___, K5B, K5C, K5D, K5E }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, K68, K69, K6A, K6B, K6C, K6D, K6E }, \
    { K70, K71, K72, K73, K74, K75, K76, K77, K78, ___, K7A, K7B, K7C, K7D, K7E }  \
}
