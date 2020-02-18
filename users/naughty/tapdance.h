#pragma once
#include "naughty.h"

  // tap dancing key initilizations
  enum {
      TDMuPl = 0,  // mute/play
      TDStrStp,    // media start/stop
      TDHoEn,      // home end

      TDtgBase,   // toggle base
      TDtgVi,     // toggle vi
      TDtgNum,    // toggle number
      TD_FNA_VI,  // toggle function advanced vi
  };

  //Define a type for as many tap dance states as you need
  enum {
        SINGLE_TAP = 1,
        SINGLE_HOLD = 2,
        DOUBLE_TAP = 3,
        DOUBLE_SINGLE_TAP = 4,
        DOUBLE_HOLD = 5,
        TRIPLE_TAP = 6,
        TRIPLE_HOLD = 7,
  };

/* typedef struct { */
/*   bool is_press_action; */
/*   int state; */
/* } tap; */

  /* /\* //Function associated with all tap dances *\/ */
  /* int cur_dance (qk_tap_dance_state_t *state); */

  /* //Functions associated with individual tap dances */
  /* void ql_finished (qk_tap_dance_state_t *state, void *user_data); */
  /* void ql_reset (qk_tap_dance_state_t *state, void *user_data); */

  /* //Determine the current tap dance state */
  /* int cur_dance (qk_tap_dance_state_t *state) { */
  /*   if (state->count == 1) { */
  /*     if (!state->pressed) { */
  /*       return SINGLE_TAP; */
  /*     } else { */
  /*       return SINGLE_HOLD; */
  /*     } */
  /*   } else if (state->count == 2) { */
  /*     return DOUBLE_TAP; */
  /*   } */
  /*   else return 8; */
  /* } */

  /* //Initialize tap structure associated with example tap dance key */
  /* static tap ql_tap_state = { */
  /*                            .is_press_action = true, */
  /*                            .state = 0 */
  /* }; */

  /* //Functions that control what our tap dance key does */
  /* void ql_finished (qk_tap_dance_state_t *state, void *user_data) { */
  /*   ql_tap_state.state = cur_dance(state); */
  /*   switch (ql_tap_state.state) { */

  /*   case SINGLE_TAP: */
  /*     tap_code(KC_R); */
  /*     break; */
  /*   case SINGLE_HOLD: */
  /*     layer_on(_VIKEYS); */
  /*     break; */
  /*   case DOUBLE_TAP: */
  /*   } */
  /* } */

  /* void ql_reset (qk_tap_dance_state_t *state, void *user_data) { */
  /*   //if the key was held down and now is released then switch off the layer */
  /*   if (ql_tap_state.state==SINGLE_HOLD) { */
  /*     layer_off(_VIKEYS); */
  /*   } */
  /*   ql_tap_state.state = 0; */
  /* } */

  /* // end of tap dancing */
