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

#define ___ KC_NO

#define LAYOUT( \
    K00, K01, K02, K03, K04, K05,    K07, K08, K09,    K0B, K0C, K0D, K0E, K0F, K0H, \
    K10, K11, K12, K13, K14, K15,    K17, K18, K19,    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, \
    K21, K22, K23, K24, K25, K26,    K27, K28, K29,    K2B, K2C, K2D, K2E, K2F, K2G, \
    K31,      K32, K33, K35,         K37, K38, K39,    K3B, K3C, K3E,      K3F, K3G, \
                                     K47, K48, K49                                   \
) \
{ \
    { K00, K01, K02, K03, K04, K05, ___, K07, K08, K09, ___, K0B, K0C, K0D, K0E, K0F, ___, K0H }, \
    { K10, K11, K12, K13, K14, K15, ___, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H }, \
    { ___, K21, K22, K23, K24, K25, K26, K27, K28, K29, ___, K2B, K2C, K2D, K2E, K2F, K2G, ___ }, \
    { ___, K31, K32, K33, ___, K35, ___, K37, K38, K39, ___, K3B, K3C, ___, K3E, K3F, K3G, ___ }, \
    { ___, ___, ___, ___, ___, ___, ___, K47, K48, K49, ___, ___, ___, ___, ___, ___, ___, ___ }  \
}
