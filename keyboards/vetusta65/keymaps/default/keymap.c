#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_ESC,  KC_2,    KC_4,    KC_6,    KC_8,    KC_0,    KC_EQL,  KC_DEL, 
		KC_1,    KC_3,    KC_5,    KC_7,    KC_9,    KC_MINS, KC_BSPC, 
		KC_TAB,  KC_W,    KC_R,    KC_Y,    KC_I,    KC_P,    KC_RBRC, KC_PGUP, 
		KC_Q,    KC_E,    KC_T,    KC_U,    KC_O,    KC_LBRC, KC_BSLS, 
		KC_A,    KC_D,    KC_G,    KC_J,    KC_L,    KC_QUOT, TG(1),   KC_PGDN, 
		KC_CAPS, KC_S,    KC_F,    KC_H,    KC_K,    KC_SCLN, KC_ENT, 
		KC_LGUI, KC_Z,    KC_C,    KC_B,    KC_M,    KC_DOT,  KC_LSFT, KC_PAUS, 
		KC_LSFT, KC_X,    KC_V,    KC_N,    KC_COMM, KC_SLSH, KC_UP,   KC_DOWN, 
		KC_LCTL, KC_LALT, KC_SPC,  KC_MPLY, MO(1),   KC_LEFT, KC_RGHT
    ),

	LAYOUT(
		KC_GRV,  KC_F2,   KC_F4,   KC_F6,   KC_F8,   KC_F10,  KC_F12,  _______, 
		KC_F1,   KC_F3,   KC_F5,   KC_F7,   KC_F9,   KC_F11,  _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, TG(0),   _______, 
		_______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, KC_VOLU, KC_VOLD, 
		_______, _______, _______, KC_MSTP, _______, KC_MPRV, KC_MNXT
    ),


};
