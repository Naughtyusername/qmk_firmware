#include "tapdance.h"

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

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // misc
    [TDMuPl] = ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_MPLY),
    [TDHoEn] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),

    // layers
    [TDTG_BASE] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_Z, _BASE),
    [TDTG_NUM]  = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_E, _RAISE),
    [TDTG_VI]   = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_R, _VIKEYS),

    // [TD_FNA_VI]    =      ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 200),
    // gaming layers ? theory
};
