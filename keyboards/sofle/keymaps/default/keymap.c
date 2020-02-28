#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
    #include "lufa.h"
    #include "split_util.h"
#endif

// extern uint8_t is_master;

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _M_QWERTY,
    _W_QWERTY,
    _M_COLEMAK,
    _W_COLEMAK,
    _M_LOWER,
    _W_LOWER,
    _M_RAISE,
    _W_RAISE,
    _ADJUST,
};

enum custom_keycodes {
    M_QWERTY = SAFE_RANGE,
    W_QWERTY,
    M_COLEMAK,
    W_COLEMAK,
    M_LOWER,
    W_LOWER,
    M_RAISE,
    W_RAISE,
    ADJUST,
};

/* Linux/win variants */
#define W_UNDO    LCTL(KC_Z)
#define W_CUT     LCTL(KC_X)
#define W_COPY    LCTL(KC_C)
#define W_PASTE   LCTL(KC_V)
#define W_PRVWD   LCTL(KC_LEFT)
#define W_NXTWD   LCTL(KC_RIGHT)
#define W_LSTRT   KC_HOME
#define W_LEND    KC_END
#define W_DLINE   LCTL(KC_BSPC)

/* Mac variants */
#define M_UNDO  LGUI(KC_Z)
#define M_CUT   LGUI(KC_X)
#define M_COPY  LGUI(KC_C)
#define M_PASTE LGUI(KC_V)
#define M_PRVWD LALT(KC_LEFT)
#define M_NXTWD LALT(KC_RIGHT)
#define M_LSTRT LGUI(KC_LEFT)
#define M_LEND  LGUI(KC_RIGHT)
#define M_DLINE LGUI(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_M_QWERTY] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,     XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT, KC_LGUI, M_LOWER, KC_ENT,      KC_SPC,  M_RAISE, KC_RGUI, KC_RALT, KC_RCTL
    ),
    [_W_QWERTY] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,     XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LGUI, KC_LALT, KC_LCTL, W_LOWER, KC_ENT,      KC_SPC,  W_RAISE, KC_RCTL, KC_RALT, KC_RGUI
    ),

    /*
     * COLEMAK
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_M_COLEMAK] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                          KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                          KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,     XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT, KC_LGUI, M_LOWER, KC_ENT,      KC_SPC,  M_RAISE, KC_RGUI, KC_RALT, KC_RCTL
    ),
    [_W_COLEMAK] = LAYOUT(
        KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                          KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                          KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,     XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LGUI, KC_LALT, KC_LCTL, W_LOWER, KC_ENT,      KC_SPC,  W_RAISE, KC_RCTL, KC_RALT, KC_RGUI
    ),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_M_LOWER] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,     _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                          _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),
    [_W_LOWER] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,     _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                          _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

    /* RAISE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_M_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
        _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                       KC_PGUP, M_PRVWD, KC_UP,   M_NXTWD, M_DLINE, _______,
        _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  XXXXXXX,
        _______, M_UNDO,  M_CUT,   M_COPY,  M_PASTE, XXXXXXX, _______,     _______, XXXXXXX, M_LSTRT, XXXXXXX, M_LEND,  XXXXXXX, _______,
                          _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),
    [_W_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
        _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                       KC_PGUP, W_PRVWD, KC_UP,   W_NXTWD, W_DLINE, _______,
        _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  XXXXXXX,
        _______, W_UNDO,  W_CUT,   W_COPY,  W_PASTE, XXXXXXX, _______,     _______, XXXXXXX, W_LSTRT, XXXXXXX, W_LEND,  XXXXXXX, _______,
                          _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RESET,   XXXXXXX, M_QWERTY, M_COLEMAK, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, W_QWERTY, W_COLEMAK, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                          _______,  _______,   _______, _______, _______,     _______, _______, _______, _______, _______
    )
};

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
    if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
        layer_on(layer3);
    } else {
        layer_off(layer3);
    }
}


#ifdef OLED_DRIVER_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

    oled_write_P(qmk_logo, false);
}

// static void print_status_wide(void) {
//     // Print current mode

//     switch (biton32(default_layer_state)) {
//     case _W_COLEMAK:
//         oled_write_P(PSTR("Mode: Colemak Linux\n"), false);
//         break;
//     case _M_COLEMAK:
//         oled_write_P(PSTR("Mode: Colemak Mac\n"), false);
//         break;
//     default:
//         oled_write_P(PSTR("Mode: Undefined\n"), false);
//     }
//     // Print current layer
//     oled_write_P(PSTR("Layer: "), false);
//     switch (biton32(layer_state)) {
//     case _M_COLEMAK:
//     case _W_COLEMAK:
//         oled_write_P(PSTR("Base\n"), false);
//         break;
//     case _M_RAISE:
//     case _W_RAISE:
//         oled_write_P(PSTR("Raise\n"), false);
//         break;
//     case _M_LOWER:
//     case _W_LOWER:
//         oled_write_P(PSTR("Lower\n"), false);
//         break;
//     case _ADJUST:
//         oled_write_P(PSTR("Adjust\n"), false);
//         break;
//     default:
//         oled_write_ln_P(PSTR("Undefined"), false);
//     }

//     uint8_t led_usb_state = host_keyboard_leds();
//     oled_write_ln_P(led_usb_state & (1 << USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
// }

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    switch (biton32(default_layer_state)) {
    case _W_QWERTY:
        oled_write_P(PSTR("Qwrt\nLinux"), false);
        break;
    case _M_QWERTY:
        oled_write_P(PSTR("Qwrt\nMac\n"), false);
        break;
    case _W_COLEMAK:
        oled_write_P(PSTR("Clmk\nLinux"), false);
        break;
    case _M_COLEMAK:
        oled_write_P(PSTR("Clmk\nMac\n"), false);
        break;
    default:
        oled_write_P(PSTR("Undefined\n"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (biton32(layer_state)) {
    case _M_COLEMAK:
    case _W_COLEMAK:
    case _M_QWERTY:
    case _W_QWERTY:
        oled_write_P(PSTR("Base\n"), false);
        break;
    case _M_RAISE:
    case _W_RAISE:
        oled_write_P(PSTR("Raise"), false);
        break;
    case _M_LOWER:
    case _W_LOWER:
        oled_write_P(PSTR("Lower"), false);
        break;
    case _ADJUST:
        oled_write_P(PSTR("Adj\n"), false);
        break;
    default:
        oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_ln_P(led_usb_state & (1 << USB_LED_CAPS_LOCK) ? PSTR("CPSLK") : PSTR("     "), false);
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270; // flips the display 180 degrees if offhand
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    switch (keycode) {
    case W_QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_W_QWERTY);
        }
        return false;
        break;
    case M_QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_M_QWERTY);
        }
        return false;
        break;
    case W_COLEMAK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_W_COLEMAK);
        }
        return false;
        break;
    case M_COLEMAK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_M_COLEMAK);
        }
        return false;
        break;
    case M_LOWER:
        if (record->event.pressed) {
            layer_on(_M_LOWER);
            update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
        } else {
            layer_off(_M_LOWER);
            update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
        }
        return false;
        break;
    case M_RAISE:
        if (record->event.pressed) {
            layer_on(_M_RAISE);
            update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
        } else {
            layer_off(_M_RAISE);
            update_tri_layer_RGB(_M_LOWER, _M_RAISE, _ADJUST);
        }
        return false;
        break;
    case W_LOWER:
        if (record->event.pressed) {
            layer_on(_W_LOWER);
            update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
        } else {
            layer_off(_W_LOWER);
            update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
        }
        return false;
        break;
    case W_RAISE:
        if (record->event.pressed) {
            layer_on(_W_RAISE);
            update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
        } else {
            layer_off(_W_RAISE);
            update_tri_layer_RGB(_W_LOWER, _W_RAISE, _ADJUST);
        }
        return false;
        break;

    case ADJUST:
        if (record->event.pressed) {
            layer_on(_ADJUST);
        } else {
            layer_off(_ADJUST);
        }
        return false;
        break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}
