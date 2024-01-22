#include QMK_KEYBOARD_H

enum layer_names {
    _MAIN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Keymap __MAIN: Default Layer  
	*  ,---------------.
	*  | |-----|-----| |  
	*  | |  Ζ  |  Χ  | |  
	*  | |-----|-----| |
	*  '---------------'
	*/
  [_MAIN] = LAYOUT(
    KC_Z,  KC_X
  ),
};
