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

#include QMK_KEYBOARD_H

enum layers {
    _DVORAK,
    _CAMILA,
    _NUMBER,
    _FN1,
    _ARROW,
    _LSHIFT,
    _RSHIFT,
    _GAMING,
};

enum unicode_names {
    SE_AA_HIGH,
    SE_AE_HIGH,
    SE_OE_HIGH,
    SE_AA_LOW,
    SE_AE_LOW,
    SE_OE_LOW,
};

const uint32_t PROGMEM unicode_map[] = {
  [SE_AA_HIGH] = 0x00C5,
  [SE_AE_HIGH] = 0x00C4,
  [SE_OE_HIGH] = 0x00D6,
  [SE_AA_LOW]  = 0x00E5,
  [SE_AE_LOW]  = 0x00E4,
  [SE_OE_LOW]  = 0x00F6,
};

// Encoder
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
      if (clockwise) {
        tap_code16 (KC_VOLU);
      } else {
		tap_code16 (KC_VOLD);
      }
  }
}

#define MO_LSFT MO(_LSHIFT)
#define MO_RSFT MO(_RSHIFT)
#define MO_FUNC MO(_FN1)
#define MO_NUMB MO(_NUMBER)
#define MO_ARRW MO(_ARROW)
#define TG_CAML TG(_CAMILA)
#define TO_GAME TO(_GAMING)
#define TO_DVOR TO(_DVORAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DVORAK] = LAYOUT(
        KC_TAB,  KC_SCLN, KC_SLSH, KC_EQL,  KC_P,    KC_Y,       KC_MINS, KC_ASTR, KC_SLSH,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS, LALT(KC_END), KC_ENT,
        KC_BSPC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,       KC_7,    KC_8,    KC_9,       KC_F,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,         KC_MINS,
        MO_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,       KC_4,    KC_5,    KC_6,       KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    MO_RSFT,
        KC_LGUI,          KC_LALT, MO_FUNC, MO_NUMB,             KC_1,    KC_2,    KC_3,       KC_SPC,  KC_RCTL, KC_MPLY,          KC_MUTE, MO_ARRW,
                                                                 KC_DOT,  KC_0,    KC_PLUS
    ),

	[_CAMILA] = LAYOUT(
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,       KC_PLUS, KC_DOT,  KC_MINS,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, LALT(KC_END), KC_ENT,
        KC_BSPC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,       KC_7,    KC_8,    KC_9,       KC_F,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,         KC_MINS,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,       KC_4,    KC_5,    KC_6,       KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
        KC_LGUI,          KC_LALT, MO_FUNC, MO_NUMB,             KC_1,    KC_2,    KC_3,       KC_SPC,  KC_RCTL, KC_MPLY,          KC_MUTE, MO_ARRW,
                                                                 KC_ASTR, KC_0,    KC_SLSH
    ),


    [_NUMBER] = LAYOUT(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_TRNS, KC_TRNS, KC_CIRC,    KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_ENT,
        KC_BSPC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_TRNS, KC_TRNS, KC_TRNS,    KC_CIRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_LABK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_PERC, KC_DLR,  KC_HASH, KC_AT,   KC_EXLM, KC_RABK,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,    KC_SPC,  KC_RCTL, KC_TRNS,          KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS, KC_TRNS
	),


    [_FN1] = LAYOUT(
        KC_TAB,  KC_ESC,     KC_TRNS,    KC_TRNS,    LALT(KC_F4), KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,    KC_PGUP, LCTL(KC_T), LCTL(KC_N), LCTL(LSFT(KC_N)), KC_TRNS, KC_TRNS, KC_ENT,
        KC_BSPC, LCTL(KC_A), LCTL(KC_X), LCTL(KC_C), KC_LGUI,     LCTL(KC_V),    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_HOME,    KC_LEFT,    KC_UP,            KC_DOWN, KC_RGHT, KC_END,
        KC_LSFT, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_PGDN,    LCTL(KC_W), LCTL(LSFT(KC_T)), KC_DEL,  KC_TRNS,
        KC_TRNS,             KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS,    KC_SPC,  KC_RCTL,    KC_TRNS,                      KC_TRNS, KC_TRNS,
                                                                                 KC_TRNS, KC_TRNS, KC_TRNS
	),


	[_ARROW] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_TRNS, KC_TRNS, KC_TRNS,        KC_F6,         KC_F7,   KC_F8,   KC_F9,   LCTL(LSFT(KC_ESC)), LGUI(LSFT(KC_S)), TG_CAML,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,       KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS,            KC_TRNS,
        RESET,            KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,        LGUI(KC_LEFT), KC_LEFT, KC_DOWN,          KC_RGHT,            KC_TRNS,
                                                                 KC_TRNS, KC_TRNS, TO_GAME

	),


	[_LSHIFT] = LAYOUT(
        KC_TILD,       KC_COLN,    KC_QUES,    KC_PLUS,    LSFT(KC_P), LSFT(KC_Y),    KC_TRNS, KC_TRNS, KC_TRNS,    LSFT(KC_G), LSFT(KC_C), LSFT(KC_R), LSFT(KC_L), KC_PIPE,    KC_TRNS,    LSFT(KC_ENT),
        LCTL(KC_BSPC), LSFT(KC_A), LSFT(KC_O), LSFT(KC_E), LSFT(KC_U), LSFT(KC_I),    KC_TRNS, KC_TRNS, KC_TRNS,    LSFT(KC_F), LSFT(KC_D), LSFT(KC_H), LSFT(KC_T), LSFT(KC_N), LSFT(KC_S), KC_UNDS,
        KC_TRNS,       KC_DQUO,    LSFT(KC_Q), LSFT(KC_J), LSFT(KC_K), LSFT(KC_X),    KC_TRNS, KC_TRNS, KC_TRNS,    LSFT(KC_B), LSFT(KC_M), LSFT(KC_W), LSFT(KC_V), LSFT(KC_Z), KC_DOT,
        KC_TRNS,                   KC_TRNS,    KC_LCBR,    KC_RCBR,                   KC_TRNS, KC_TRNS, KC_TRNS,    KC_SPC,     KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,
                                                                                      KC_TRNS, KC_TRNS, KC_TRNS
	),


	[_RSHIFT] = LAYOUT(
		KC_TILD,       KC_COLN,    KC_QUES,    KC_PLUS,    LSFT(KC_P), LSFT(KC_Y),    KC_TRNS, KC_TRNS, KC_TRNS,    LSFT(KC_G), LSFT(KC_C), LSFT(KC_R), LSFT(KC_L), KC_PIPE,    KC_TRNS,    LSFT(KC_ENT),
		LCTL(KC_BSPC), LSFT(KC_A), LSFT(KC_O), LSFT(KC_E), LSFT(KC_U), LSFT(KC_I),    KC_TRNS, KC_TRNS, KC_TRNS,    LSFT(KC_F), LSFT(KC_D), LSFT(KC_H), LSFT(KC_T), LSFT(KC_N), LSFT(KC_S), KC_UNDS,
		KC_COMM,       KC_DQUO,    LSFT(KC_Q), LSFT(KC_J), LSFT(KC_K), LSFT(KC_X),    KC_TRNS, KC_TRNS, KC_TRNS,    LSFT(KC_B), LSFT(KC_M), LSFT(KC_W), LSFT(KC_V), LSFT(KC_Z), KC_TRNS,
		KC_TRNS,                   KC_TRNS,    KC_LBRC,    KC_RBRC,                   KC_TRNS, KC_TRNS, KC_TRNS,    KC_SPC,     KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,
		                                                                              KC_TRNS, KC_TRNS, KC_TRNS

	),

    [_GAMING] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_MINS, KC_ASTR, KC_SLSH,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LCBR, LALT(KC_END), KC_ENT,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_7,    KC_8,    KC_9,       KC_Y,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,      KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_4,    KC_5,    KC_6,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES, KC_RSFT,
        KC_LCTL,          KC_LALT, KC_1,    KC_SPC,              KC_1,    KC_2,    KC_3,       TO_DVOR, KC_RCTL, KC_MPLY,          KC_MUTE, MO_ARRW,
                                                                 KC_TAB,  KC_0,    KC_PLUS
	)
};

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_LNX);
}
