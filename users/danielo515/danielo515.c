#include "danielo515.h"

bool on_mac = false;
// Send control or GUI depending if we are on windows or mac
bool CMD(uint16_t kc) {
  if(on_mac){ TAP(LGUI(kc)); } else { TAP(LCTL(kc)); }
  return false;
}
//**************** Definitions needed for quad function to work *********************//

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted || state->pressed==0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap. In example below, that means to send `xx` instead of `Escape`.
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return 6; //magic number. At some point this method will expand to work for more presses
}

//**************** END Definitions needed for quad function to work *********************//

//===== The awesome tap dance for CUT, COPY and PASTE
void dance_copy (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    TAP(KC_C);
  } else if (state->interrupted)
        { TAP(KC_C);TAP(KC_C);}
         else CMD(KC_C);

  reset_tap_dance (state);
}

void dance_cut (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    TAP(KC_X);
  }
  else {
    CMD(KC_X);
  }
  reset_tap_dance (state);
}  

void dance_paste (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    TAP(KC_V);
  }
  else {
    CMD(KC_V);
  }
  reset_tap_dance (state);
}

// Slightly better tap dance double: interruption sends double single and any number over double sends the single that number of times
void qk_tap_dance_pair_finished_safe(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  int count = state->count;
  if (state->count == 2) {
    if (state->interrupted){
      TAP(pair->kc1);register_code16 (pair->kc1);
      state->count = 1; // Reset the counter as we are using the first key
    } else register_code16 (pair->kc2);
    return;
  }
  register_code16 (pair->kc1);
  while(--count){
    unregister_code16(pair->kc1);
    register_code16 (pair->kc1);
  }
}

void qk_tap_dance_pair_reset_safe(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  if (state->count == 2) {
    unregister_code16 (pair->kc2);
    return;
  }
  unregister_code16(pair->kc1);
}

// ======== INCREMENTAL MACROS STUFF =============

#define MAX_INCREMENTAL_MACRO 20
#define TAP_ROTATION_TIMEOUT 400

uint16_t latest_kc = 0;
uint16_t latest_rotation = 0;
int key_count = 0;

const char incremental_macros[][MAX_INCREMENTAL_MACRO] = { "String1"SS_TAP(X_HOME)"X-", "String2"SS_TAP(X_HOME) };

bool process_incremental_macro (uint16_t kc) {

  if( kc < INC_MACROS_START || kc > INC_MACROS_END ){
    return false;
  }
  int macro_idx = (int) (kc - INC_MACROS_START) - 1;
  char tempstring[3] = {0};
  tempstring[0] = incremental_macros[macro_idx][key_count];
  // Special cases of SS_TAP SS_UP and SS_DOWN, they require two characters so get both once and skip on next iteration
  if( tempstring[0] == '\1' || tempstring[0] == '\2' || tempstring[0] == '\3'){
    tempstring[1] = incremental_macros[macro_idx][++key_count];
  }
  if( tempstring[0] == '\0'){
    key_count = 0;
  }
  send_string(tempstring);

  return true;
};

void refresh_incremental_macros (uint16_t kc) {
  if (kc == latest_kc)
    {
      if ( (timer_elapsed(latest_rotation) > TAP_ROTATION_TIMEOUT) || (key_count >= MAX_INCREMENTAL_MACRO) ) key_count = 0;
      else key_count++;
    } else {
      key_count = 0;
      latest_kc = kc;
    }

  latest_rotation = timer_read();
}


// ======== VISUAL STUDIO CODE SHORTCUTS STUFF

bool is_macro (uint16_t kc){
  return kc > MACRO_START && kc < MACRO_END;
};

bool command_shift_p (bool isMac) {
   isMac
   ? SEND_STRING(SS_DOWN(X_LSHIFT)SS_LGUI("p")SS_UP(X_LSHIFT))
   : SEND_STRING(SS_DOWN(X_LSHIFT)SS_LCTRL("p")SS_UP(X_LSHIFT));
   return false;
};

bool VSCommand(bool isMac, char *cmd)
{
  command_shift_p (isMac);
  send_string(cmd);
  SEND_STRING(SS_TAP(X_ENTER));
  return false;
};

bool handle_macro(uint16_t kc)
{
  switch (kc)
  {
    case T_TERM: return VSCommand(on_mac, "toit");
    case FIX_ALL: return VSCommand(on_mac, "faap");
    case BLK_CMNT: return VSCommand(on_mac, "tbc");
    case LN_CMNT: return VSCommand(on_mac, "tlic");
    case CMD_S_P: return command_shift_p(on_mac);
    case TRI_TICKS: SEND_STRING("[[[ "); break;
  }
  return false;
};