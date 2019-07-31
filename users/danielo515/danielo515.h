#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#define KC_E_COLN LSFT(KC_DOT)
#define KC_E_EQL ES_EQL
#define KC_GUI OSM(MOD_RGUI)
#define KC_R_NUB S(KC_NUBS)
#define KC_E_LT KC_NUBS
#define KC_E_GT S(KC_NUBS)
#define KC_E_TILD ES_TILD
#define KC_E_MINS ES_MINS
#define KC_S_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift
#define KC_E_OVRR ES_OVRR 
#define KC_E_APOS ES_APOS	
#define KC_E_IEXL ES_IEXL	
// TAP DANCE KEYS
#define TD_COPY TD(_TD_COPY)
#define TD_CUT TD(_TD_CUT)
#define KC_TD_COPY TD(_TD_COPY) // Declarations for macros that add KC_
#define KC_TD_CUT TD(_TD_CUT)
#define KC_TD_PASTE TD(_TD_PASTE)
#define KC_E_GRV ES_GRV	

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _F,
  _D,
  _A,
  _S,
  _J,
  _K,
  _MACROS,
  _ADJUST = 16,
  _SAFE_LAYER
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MAC_TGL,
  MACRO_START,  // START OF VSC DECLARATIONS
  T_TERM,
  FIX_ALL,
  BLK_CMNT,
  LN_CMNT,
  CMD_S_P,
  TRI_TICKS,
  MACRO_END,  // END OF VSC DECLARATIONS
  INC_MACROS_START,
  ARROW,
  INC_MACROS_END,
};

// Function letters
#define FN_F LT(_F,KC_F)
#define FN_D LT(_D,KC_D)
#define FN_S LT(_S,KC_S)
#define FN_A LT(_A,KC_A)
#define FN_K LT(_K,KC_K)
#define FN_J LT(_J,KC_J)
#define KC_FN_D FN_D
#define KC_FN_S FN_S
#define KC_FN_F FN_F

#define KC_MACROS OSL(_MACROS)


#define TAP(keycode) register_code16(keycode); unregister_code16(keycode)

#define ACTION_TAP_DANCE_DOUBLE_SAFE(kc1, kc2) { \
    .fn = { NULL, qk_tap_dance_pair_finished_safe, qk_tap_dance_pair_reset_safe }, \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 }),  \
  }


//Enums used to clearly convey the state of the tap dance
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5 //send SINGLE_TAP twice - NOT DOUBLE_TAP
  // Add more enums here if you want for triple, quadruple, etc.
};

int cur_dance (qk_tap_dance_state_t *state);

void qk_tap_dance_pair_finished_safe(qk_tap_dance_state_t *state, void *user_data);
void qk_tap_dance_pair_reset_safe(qk_tap_dance_state_t *state, void *user_data);
void dance_cut (qk_tap_dance_state_t *state, void *user_data);
void dance_copy (qk_tap_dance_state_t *state, void *user_data);
void dance_paste (qk_tap_dance_state_t *state, void *user_data);
bool handle_macro(uint16_t kc);
bool is_macro (uint16_t kc);
bool process_incremental_macro (uint16_t);
void refresh_incremental_macros (uint16_t);

#endif
