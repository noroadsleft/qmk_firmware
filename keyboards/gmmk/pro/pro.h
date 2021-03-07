/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

#include "gmmk.h"

#define LAYOUT_all( \
    k13, k26, k36, k31, k33, k07, k2b, k39, k3e, k2m, k2n, k2j, k2l, k1n,     k01, \
    k16, k17, k27, k37, k0f, k0e, k1e, k1f, k2f, k3f, k0n, k0m, k2e, k2h,     k2d, \
    k11, k10, k20, k30, k08, k09, k19, k18, k28, k38, k0g, k0h, k29, k2i,     k15, \
    k21, k12, k22, k32, k0a, k0b, k1b, k1a, k2a, k3a, k0i, k0j,      k2k,     k25, \
    k00, k14, k24, k34, k0c, k0d, k1d, k1c, k2c, k3c, k0l, k23, k1h,     k35, k3d, \
    k06, k1g, k1j,               k1k,               k1l, k1i, k04,  k03, k3b, k05  \
) \
{ \
    { k00,   k01,   KC_NO, k03,   k04,   k05,   k06,   k07 }, \
    { k10,   k11,   k12,   k13,   k14,   k15,   k16,   k17 }, \
    { k20,   k21,   k22,   k23,   k24,   k25,   k26,   k27 }, \
    { k30,   k31,   k32,   k33,   k34,   k35,   k36,   k37 }, \
    { k08,   k09,   k0a,   k0b,   k0c,   k0d,   k0e,   k0f }, \
    { k18,   k19,   k1a,   k1b,   k1c,   k1d,   k1e,   k1f }, \
    { k28,   k29,   k2a,   k2b,   k2c,   k2d,   k2e,   k2f }, \
    { k38,   k39,   k3a,   k3b,   k3c,   k3d,   k3e,   k3f }, \
    { k0g,   k0h,   k0i,   k0j,   KC_NO, k0l,   k0m,   k0n }, \
    { k1g,   k1h,   k1i,   k1j,   k1k,   k1l,   KC_NO, k1n }, \
    { KC_NO, k2h,   k2i,   k2j,   k2k,   k2l,   k2m,   k2n }  \
}
