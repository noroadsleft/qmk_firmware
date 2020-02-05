#include QMK_KEYBOARD_H
#include "keymap_french.h"

enum layer_names {
    _LAYER0,
    _LAYER1,
    _LAYER2,
    _LAYER3,
    _LAYER4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT_60_iso_no_nubs(
        KC_GESC, FR_AMP,  FR_EACU, FR_QUOT, FR_APOS, FR_LPRN, FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN, FR_EQL,  KC_BSPC,
        KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    FR_CIRC, FR_DLR,
        KC_CAPS, FR_Q,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    FR_M,    FR_UGRV, FR_ASTR, KC_ENT,
        KC_LSFT,          FR_LESS, FR_W,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    FR_COMM, FR_SCLN, FR_COLN,          KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, FR_EXLM, KC_RCTL
    )
};

void rgb_matrix_layer_helper(uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    uint8_t this_led = host_keyboard_leds();
    if (!g_suspend_state) {
        switch (biton32(layer_state)) {
        case _LAYER1:
            rgb_matrix_layer_helper(0xFF, 0x00, 0x00, false);
            break;
        case _LAYER2:
            rgb_matrix_layer_helper(0x00, 0xFF, 0x00, false);
            break;
        case _LAYER3:
            rgb_matrix_layer_helper(0x00, 0x00, 0xFF, false);
            break;
        case _LAYER4:
            rgb_matrix_layer_helper(0xFF, 0xFF, 0x00, false);
            break;
        }
    }
    if (this_led & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
    }
}
