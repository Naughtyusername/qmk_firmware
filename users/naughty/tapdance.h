#pragma once
#include "naughty.h"

enum {
      TDMuPl = 0,  // mute/play
      TDStrStp,    // media start/stop
      TDHoEn,      // home end

      TDtgBase,   // toggle base
      TDtgVi,     // toggle vi
      TDtgNum,    // toggle number
      TD_FNA_VI,  // toggle function advanced vi
};

// define a type containing as many tapdance states as you need
typedef enum { SINGLE_TAP, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD } td_state_t;

// function to determine the current tapdance state
int cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void TD_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_reset(qk_tap_dance_state_t *state, void *user_data);

/* void dance_cln_finished(qk_tap_dance_state_t *state, void *user_date) { */
/*     if (state->count == 1) { */
/*         register_code(KC_RSFT); */
/*         register_code(KC_SCLN); */
/*     } else { */
/*         register_code(KC_SCLN); */
/*     } */
/* } */

/* void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*     if (state->count == 1) { */
/*         unregistered_code(KC_RSFT); */
/*         unregistered_code(KC_SCLN); */
/*     } else { */
/*         unregister_code(KC_SCLN); */
/*     } */
/* } */
