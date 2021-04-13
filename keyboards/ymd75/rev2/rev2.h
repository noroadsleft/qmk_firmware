#pragma once

#include "quantum.h"

#define ___ KC_NO

#define LAYOUT_75_ansi( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K5E, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1E,      K5D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D,      K2E, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D,      K3E, \
    K40,      K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B,      K4C, K4D, K4E, \
    K50, K51, K52,                K55,                K56, K57, K58, K59, K5A, K5B  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, ___, K1E }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, ___, K3D, K3E }, \
    { K40, ___, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E }, \
    { K50, K51, K52, ___, ___, K55, K56, K57, K58, K59, K5A, K5B, ___, K5D, K5E }  \
}

#define LAYOUT_75_iso( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K5E, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1E,      K5D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,           K2E, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,      K3E, \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B,      K4C, K4D, K4E, \
    K50, K51, K52,                K55,                K56, K57, K58, K59, K5A, K5B  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, ___, K1E }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, ___, K2E }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E }, \
    { K50, K51, K52, ___, ___, K55, K56, K57, K58, K59, K5A, K5B, ___, K5D, K5E }  \
}

#define LAYOUT_75_iso_rwkl( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K5E, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1E,      K5D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,           K2E, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,      K3E, \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B,      K4C, K4D, K4E, \
    K50, K51, K52,                K55,                K56,   K58,    K59, K5A, K5B  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, ___, K1E }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, ___, K2E }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E }, \
    { K50, K51, K52, ___, ___, K55, K56, ___, K58, K59, K5A, K5B, ___, K5D, K5E }  \
}

#define LAYOUT LAYOUT_75_ansi
