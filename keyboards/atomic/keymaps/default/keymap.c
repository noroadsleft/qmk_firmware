#include QMK_KEYBOARD_H

// Fillers to make layering more clear
#define ___T___ KC_TRNS

// Layer shorthand
enum layer_names {
    _QW,
    _CM,
    _DV,
    _LW,
    _RS,
    _FN
};

/* ROW 1 OPTIONS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 *                                                                                                                      .- 2u ------------.
 *                                                                                                                      | KEY    . XXXXXX |
 *                                                                                                                      '-----------------'
 */

/* ROW 2 OPTIONS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 * .- 2u ------------.                                                                                                  .- 2u ------------.
 * | KEY    . XXXXXX |                                                                                                  | KEY    . XXXXXX |
 * '-----------------'                                                                                                  '-----------------'
 */

/* ROW 3 OPTIONS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 * .- 2u ------------.                                                                                         .- 2u ------------.
 * | KEY    . XXXXXX |                                                                                         |   X             |
 * '-----------------'                                                                                         '-----------------'
 *                                                                                                                      .- 2u ------------.
 *                                                                                                                      |   X             |
 *                                                                                                                      '-----------------'
 */

/* ROW 4 OPTIONS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 *                                                                                                    .- 2u ------------.
 *                                                                                                    | KEY    . XXXXXX |
 *                                                                                                    '-----------------'
 * .- 2u ------------.                                                                                         .- 2u ------------.
 * | KEY    . XXXXXX |                                                                                         | KEY    . XXXXXX |
 * '-----------------'                                                                                         '-----------------'
 *                                                                                                                      .- 2u ------------.
 *                                                                                                                      | KEY    . XXXXXX |
 *                                                                                                                      '-----------------'
 */

/* ROW 5 OPTIONS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 * .- 1.25u --+ 1.25u ------- 1.25u +--- 1.25u --- 2u -------------- 1.25u ---- 1.25u ------ 1.25u +---- 1.25u .
 * |   X      | X        |        X |      X    |   X             |   X      | X        |        X |      X    |
 * '-----------------------------------------------------------------------------------------------------------'
 *                                                                .- 2u ------------.
 *                                                                |   X             |
 *                                                                '-----------------'
 *                                  .--------------------- 6.25u ----------------------------.
 *                                  |                        X                               |
 *                                  '--------------------------------------------------------'
 *                       .----------------------- 6.25u ---------------------------- 1.25u ---- 1.25u ---- 1.25u ------ 1.25u +-- 1.25u --.
 *                       |                          X                             |     X    |   X      | X        |        X |      X    |
 *                       '----------------------------------------------------------------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY - MIT ENHANCED / GRID COMPATIBLE
   * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
   * | `      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | XXXXXX . BACKSP |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
   * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \      | DEL    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
   * | ESC    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | XXXXXX . ENTER  | PG UP  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
   * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | XXXXXX . RSHIFT | UP     | PG DN  |
   * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+-----------------+--------+--------|
   * | BRITE  | LCTRL  | LALT   | LGUI   | RAISE  | XXXXXX . SPACE  | LOWER  | RGUI   | RALT   | RCTRL  | FN     | LEFT   | DOWN   | RIGHT  |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

  [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL ,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,  KC_PGUP,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN,
    BL_STEP, KC_LCTL, KC_LALT, KC_LGUI, MO(_RS), KC_SPC,  KC_SPC,  MO(_LW), KC_RGUI, KC_RALT, KC_RCTL, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* COLEMAK - MIT ENHANCED / GRID COMPATIBLE
   * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
   * | `      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | XXXXXX . BACKSP |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
   * | TAB    | Q      | W      | F      | P      | G      | J      | L      | U      | Y      | ;      | [      | ]      | \      | DEL    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
   * | ESC    | A      | R      | S      | T      | D      | H      | N      | E      | I      | O      | '      | XXXXXX . ENTER  | PG UP  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
   * | LSHIFT | Z      | X      | C      | V      | B      | K      | M      | ,      | .      | /      | XXXXXX . RSHIFT | UP     | PG DN  |
   * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+-----------------+--------+--------|
   * | BRITE  | LCTRL  | LALT   | LGUI   | RAISE  | XXXXXX . SPACE  | LOWER  | RGUI   | RALT   | RCTRL  | FN     | LEFT   | DOWN   | RIGHT  |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

  [_CM] = LAYOUT_ortho_5x15( /* COLEMAK */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL ,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,  KC_ENT,  KC_PGUP,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN,
    BL_STEP, KC_LCTL, KC_LALT, KC_LGUI, MO(_RS), KC_SPC,  KC_SPC,  MO(_LW), KC_RGUI, KC_RALT, KC_RCTL, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* DVORAK - MIT ENHANCED / GRID COMPATIBLE
   * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
   * | `      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | XXXXXX . BACKSP |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
   * | TAB    | '      | ,      | .      | P      | Y      | F      | G      | C      | R      | L      | [      | ]      | \      | DEL    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
   * | ESC    | A      | O      | E      | U      | I      | D      | H      | T      | N      | S      | /      | XXXXXX . ENTER  | PG UP  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
   * | LSHIFT | ;      | Q      | J      | K      | X      | B      | M      | W      | V      | Z      | XXXXXX . RSHIFT | UP     | PG DN  |
   * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+-----------------+--------+--------|
   * | BRITE  | LCTRL  | LALT   | LGUI   | RAISE  | XXXXXX . SPACE  | LOWER  | RGUI   | RALT   | RCTRL  | FN     | LEFT   | DOWN   | RIGHT  |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

  [_DV] = LAYOUT_ortho_5x15( /* DVORAK */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL ,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, KC_ENT,  KC_ENT,  KC_PGUP,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN,
    BL_STEP, KC_LCTL, KC_LALT, KC_LGUI, MO(_RS), KC_SPC,  KC_SPC,  MO(_LW), KC_RGUI, KC_RALT, KC_RCTL, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* LOWERED
   * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
   * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX .        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
   * |        | !      | @      | #      | $      | %      | ^      | &      | *      | (      | )      |        |        |        | INS    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
   * |        | F1     | F2     | F3     | F4     | F5     | F6     | _      | +      | {      | }      | |      | XXXXXX .        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
   * |        | F7     | F8     | F9     | F10    | F11    | F12    |        |        |        |        | XXXXXX .        |        |        |
   * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+-----------------+--------+--------|
   * |        |        |        |        |        | XXXXXX .        |        |        |        |        |        |        |        |        |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

  [_LW] = LAYOUT_ortho_5x15( /* LOWERED */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___T___, ___T___,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, KC_INS ,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, ___T___, ___T___, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, ___T___, ___T___, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* RAISED
   * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
   * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX .        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
   * |        | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      |        |        |        | INS    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
   * |        | F1     | F2     | F3     | F4     | F5     | F6     | -      | =      | [      | ]      | \      | XXXXXX .        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
   * |        | F7     | F8     | F9     | F10    | F11    | F12    |        |        |        |        | XXXXXX .        |        |        |
   * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+-----------------+--------+--------|
   * |        |        |        |        |        | XXXXXX .        |        |        |        |        |        |        |        |        |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

  [_RS] = LAYOUT_ortho_5x15( /* RAISED */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___T___, ___T___,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, KC_INS ,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, ___T___, ___T___, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, ___T___, ___T___, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* FUNCTION
   * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
   * | NUM LK | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX .        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
   * | SCR LK | F13    | F14    | F15    | F16    | F17    | F18    | F19    | F20    | F21    | F22    | F23    | F24    | PAUSE  | PR SCR |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
   * | CAP LK | MS BT5 | MS BT4 | MS BT3 | MS BT2 | SLOW M | FAST M | NEXT   | VOL+   | VOL-   | PLAY   |        | XXXXXX .        | WHEEL+ |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
   * |        |        | QWERTY | COLEMK | DVORAK |        |        |        |        |        |        | XXXXXX .        | MOUS U | WHEEL- |
   * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+-----------------+--------+--------|
   * |        |        |        |        |        | XXXXXX . MS BT1 |        |        |        |        |        | MOUS L | MOUS D | MOUS R |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

  [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
     KC_NUM,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___T___, ___T___,
     KC_SCRL, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_PAUS, KC_PSCR,
     KC_CAPS, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, KC_ACL0, KC_ACL2, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______, ___T___, ___T___, KC_WH_U,
     _______, _______, DF(_QW), DF(_CM), DF(_DV), _______, _______, _______, _______, _______, _______, ___T___, ___T___, KC_MS_U, KC_WH_D,
     _______, _______, _______, _______, _______, KC_BTN1, KC_BTN1, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
  ),
};
