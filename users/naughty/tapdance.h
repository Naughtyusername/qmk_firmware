  typedef struct {
  bool is_press_action;
  int state;
  } tap;

  //Define a type for as many tap dance states as you need
  enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3
  };

  //Declare the functions to be used with your tap dance key(s)

  //Function associated with all tap dances
  int cur_dance (qk_tap_dance_state_t *state);

  //Functions associated with individual tap dances
  void ql_finished (qk_tap_dance_state_t *state, void *user_data);
  void ql_reset (qk_tap_dance_state_t *state, void *user_data);

  // tap dancing key initilizations
  enum {
        TDMuPl = 0,     // mute/play
        TDStrStp,       // media start/stop
        TDHoEn,         // home end

        TDtgBase,       // toggle base
        TDtgVi,         // toggle vi
        TDtgNum,        // toggle number
        TD_FNA_VI,      // toggle function advanced vi
  };



//Determine the current tap dance state
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    return DOUBLE_TAP;
  }
  else return 8;
}

//Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
                           .is_press_action = true,
                           .state = 0
};

//Functions that control what our tap dance key does
void ql_finished (qk_tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {

  case SINGLE_TAP:
    tap_code(KC_R);
    break;
  case SINGLE_HOLD:
    layer_on(_VIKEYS);
    break;
  case DOUBLE_TAP:
    //check to see if the layer is already set
    if (layer_state_is(_VIKEYS)) {
      //if already set, then switch it off
      layer_off(_VIKEYS);
    } else {
      //if not already set, then switch the layer on
      layer_on(_BASE);
    }
  }
}

void ql_reset (qk_tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (ql_tap_state.state==SINGLE_HOLD) {
    layer_off(_VIKEYS);
  }
  ql_tap_state.state = 0;
}


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
// misc
[TD_MUTE_PLAY]   =      ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_MPLY), */
[TD_HOME_END]    =      ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END), */

// layers */
[TD_TG_BASE]     =      ACTION_TAP_DANCE_LAYER_TOGGLE(KC_Z, _BASE), */
[TD_TG_NUM]      =      ACTION_TAP_DANCE_LAYER_TOGGLE(KC_E, _RAISE), */
[TD_TG_VI]       =      ACTION_TAP_DANCE_LAYER_TOGGLE(KC_R, _VIKEYS), */

//[TD_TDFNA_VI]    =      ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 200), */
gaming layers ? theory
};

// end of tap dancing
