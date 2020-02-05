/* Copyright 2015-2017 Jack Humbert
 *

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
  88b 88    db    88   88  dP""b8 88  88 888888 Yb  dP 88   88 .dP"Y8 888888 88""Yb 88b 88    db    8b    d8 888888
  88Yb88   dPYb   88   88 dP   `" 88  88   88    YbdP  88   88 `Ybo." 88__   88__dP 88Yb88   dPYb   88b  d88 88__
  88 Y88  dP__Yb  Y8   8P Yb  "88 888888   88     8P   Y8   8P o.`Y8b 88""   88"Yb  88 Y88  dP__Yb  88YbdP88 88""
  88  Y8 dP""""Yb `YbodP'  YboodP 88  88   88    dP    `YbodP' 8bodP' 888888 88  Yb 88  Y8 dP""""Yb 88 YY 88 888888

  Current PlanckEz configuration.
  Thank you to all of the QMK team and contributors for this incredible firmware!
  -Naughtyusername
*/

// Todo: define some more things to make it more readable. (colors i like, cleaner keybinds, etc.)

#include QMK_KEYBOARD_H
#include "muse.h"

// Mod Taps - custom names to shorten mod tap lengths and such
#define AL_A LALT_T(KC_A)
#define AL_SCN RALT_T(KC_SCLN)

#define CT_S LCTL_T(KC_S)
#define CT_L RCTL_T(KC_L)

#define SH_D LSFT_T(KC_D)
#define SH_K RSFT_T(KC_K)

#define GU_F LGUI_T(KC_F)
#define GU_J RGUI_T(KC_J)

#define VI_R LT(_VIKEYS, KC_R)
#define NV_W LT(_NAV, KC_W)
#define NM_E LT(_RAISE, KC_E)

#define LT_V LT(_LOWER, KC_V)
#define LT_M LT(_LOWER, KC_M)


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

enum planck_layers {
                    _BASE,
                    _LOWER,
                    _RAISE,
                    _ADJUST,
                    _VIKEYS,
                    _NAV,
                    _GAMING,
                    _ROGUE,
                    _NUMPAD
};

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
                 TD_MUTE_PLAY = 0,
                 TD_HOME_END,
                 TD_TG_BASE,
                 TD_TG_VI,
                 TD_TG_NUM,
                 TD_TDFNA_VI,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |NAV|W |NUM|E | VI|R |   T  |   Y  |   U  |   I  |   O  |   P  | Lead |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BKSP |alt A |Ctrl S|Shft D|Win F |   G  |   H  |WinJ  |Sft K |Ctrl L|Alt ; |  ENT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  |  Z   |   X  |   C  |   V  | LT B |LT N  |   M  |   ,  |   .  |   /  |  TAB |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Home | End  | PGUp | PGDN |Lower |    Space    |Raise | INS  | CAPS | VOLD | VOLU |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    NV_W,    NM_E,    VI_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LEAD,
    KC_BSPC, AL_A,    CT_S,    SH_D,    GU_F,    KC_G,    KC_H,    GU_J,    SH_K,    CT_L,    AL_SCN,  KC_ENT,
    KC_DEL,  KC_Z,    KC_X,    KC_C,    LT_V,    KC_B,    KC_N,    LT_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TAB ,
    KC_HOME, KC_END, KC_PGUP, KC_PGDN, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_INS, KC_CAPS, KC_VOLD, KC_VOLU
                             ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  !   |  @   |  {   |  }   |  `   |      |  +   |  -   |  *   |  /   | CAPS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  #   |  $   |  (   |  )   |  ~   |  "   |  =   |  -   |  _   |  '   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  %   |  ^   |  [   | ] LT |  &   |      | LT   |  &   |  |   |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |    SPACE    |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_GRV,  _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_CAPS,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD, KC_DQT, KC_EQL, KC_MINS, KC_UNDS, KC_QUOT, _______,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_AMPR, _______, _______,  KC_AMPR, KC_PIPE,  KC_BSLS, _______,
    _______, _______, _______, _______, LOWER, KC_SPC, KC_SPC, RAISE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                              ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  | F4   |  F5  | F11  |  4   |  5   |  6   |  0   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  | F9   | F10  | F12  |  1   |  2   |  3   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TOBase|      |      | Prnt |Lower |   Space     |Raise |  0   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,         KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F11,       KC_4,    KC_5,    KC_6,    KC_0,  XXXXXXX,
    _______, KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F12,      KC_1,    KC_2,    KC_3, XXXXXXX,  XXXXXXX,
    TG(_BASE), _______, _______, KC_PSCR, LOWER,  KC_SPC, KC_SPC,   RAISE,         KC_0,  XXXXXXX,  XXXXXXX, XXXXXXX
                              ),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |RESET |BASE  |GAMING|ROGUE |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RGB/IO|      |      |      |Lower |             |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET, TO(_BASE), TO(_GAMING), TO(_ROGUE), _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MSTP, KC_MPLY, _______,
    RGB_TOG, _______, _______, _______, LOWER, KC_SPC, KC_SPC, RAISE, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
                               ),

/* ViKeys
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | H    | J    |  K   |  L   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 [_VIKEYS] = LAYOUT_planck_grid(
    _______, _______, KC_W, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,     KC_H,    KC_J,    KC_K,    KC_L, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
                             ),
/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 [_NAV] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
                             ),
/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | LEAD |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BKS  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  ENT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   | TAB  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BASE | ALT  | CTRL | SHFT |      |    SPC      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

 [_GAMING] = LAYOUT_planck_grid(
   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LEAD,
   KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
   KC_DEL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TAB ,
   TO(_BASE), KC_LALT, KC_LCTL, KC_LSFT, _______, KC_SPC,KC_SPC, _______, _______, _______, _______, _______
                                ),

/* ROGUE
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |  Q   |  W   |NUM|E |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | LEAD?|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BKS  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  ENT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   | TAB  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BASE | ALT  | CTRL | SHFT | Win  |    SPC      | NUM  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_ROGUE] = LAYOUT_planck_grid(
   KC_ESC,  KC_Q,    KC_W,    LT(_NUMPAD, KC_E),    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LEAD,
   KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
   KC_DEL, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TAB,
   TO(_BASE), KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,   KC_SPC,  KC_SPC,  TO(_NUMPAD),   _______, _______, _______, _______
                              ),
/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  7   |  8   |  9   |      |NumLck|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  4   |  5   |  6   |  0   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BASE  |      |      |      |      |             |ROGUE |  0   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______,        KC_KP_7, KC_KP_8, KC_KP_9, _______, KC_NLCK,
    _______, _______, _______, _______, _______, _______, _______,        KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_0, _______,
    _______, _______, _______, _______, _______, _______, _______,        KC_KP_1, KC_KP_2, KC_KP_3, _______, _______,
    TO(_BASE), _______, _______, _______, _______, _______, _______, TO(_ROGUE),   KC_KP_0, _______, _______, _______
                               ),
/* TEMPLATE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* [_TEMPLATE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
                                ),
*/

};

/*
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
*/

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
                                             // misc
                                             [TD_MUTE_PLAY]   =      ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_MPLY),
                                             [TD_HOME_END]    =      ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),

                                             // layers
                                             [TD_TG_BASE]     =      ACTION_TAP_DANCE_LAYER_TOGGLE(KC_Z, _BASE),
                                             [TD_TG_NUM]      =      ACTION_TAP_DANCE_LAYER_TOGGLE(KC_E, _RAISE),
                                             [TD_TG_VI]       =      ACTION_TAP_DANCE_LAYER_TOGGLE(KC_R, _VIKEYS),

                                             //                                             [TD_TDFNA_VI]    =      ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 200),
                                             // gaming layers ? theory
};

// end of tap dancing

void keyboard_post_init_user(void) {
  /* rgblight_enable_noeeprom(); // enables Rgb, without saving settings */
  /* rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // sets mode to static */
  /* rgblight_disable_noeeprom(); */
};

void matrix_init_user() {
    rgblight_enable();

}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);

    switch (get_highest_layer(state)) {
    case _RAISE:
        rgblight_sethsv(HSV_CORAL);
        break;
    case _LOWER:
        rgblight_sethsv(HSV_SPRINGGREEN);
        break;
    case _ADJUST:
        rgblight_sethsv(HSV_RED);
        break;
    case _BASE:
        rgblight_sethsv(HSV_PURPLE);
        break;
    case _VIKEYS:
        rgblight_sethsv(HSV_BLUE);
        break;
    case _NAV:
        rgblight_sethsv(HSV_TEAL);
        break;
    case _GAMING:
        rgblight_sethsv(HSV_ORANGE);
        break;
    case _ROGUE:
        rgblight_sethsv(HSV_CHARTREUSE);
        break;
    case _NUMPAD:
        rgblight_sethsv(HSV_CYAN);
        break;
    default:
        rgblight_sethsv(HSV_CHARTREUSE);
        break;
    }

    return state;
}

// Leader key stuff
LEADER_EXTERNS();
void matrix_scan_user(void) {
    // use mnemonics, Leader f ... for file management, etc.
    // todo: leader keys to do my display fusion window managment
    // todo: ...
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        /*
          Display fusion keybinds
          leader key W binds

          ctrl win , - move window bottom left 25%
          ctrl win . - move window bottom right 25%
          ctrl win k - Move window top left 25%
          ctrl win l - Move window top right 25%
          ctrl win g - move window bottom 50%
          ctrl win t - move window top 50%

          shift alt T - move window left monitor, scale appropreiately
          shift alt R - move window right monitor, scale appropreiately

          shift alt ctrl left  - move window left, split 50%
          shift alt ctrl right - move window right, split 50%
          shift ctrl win g     - maximixe window
         */

        SEQ_TWO_KEYS(KC_W, KC_DOT) { // move window bottom right 25%
             SEND_STRING(SS_LCTL(SS_LGUI(".")));
        }

        SEQ_TWO_KEYS(KC_W, KC_COMM) { // move window bottom left 25%
            SEND_STRING(SS_LCTL(SS_LGUI(",")));
        }

        SEQ_TWO_KEYS(KC_W, KC_K) { // move window top left 25%
            SEND_STRING(SS_LCTL(SS_LGUI("k")));
        }

        SEQ_TWO_KEYS(KC_W, KC_L) { // move window top right 25%
            SEND_STRING(SS_LCTL(SS_LGUI("l")));
        }

        SEQ_TWO_KEYS(KC_W, KC_G) { // move window bottom 50%
            SEND_STRING(SS_LCTL(SS_LGUI("g")));
        }

        SEQ_TWO_KEYS(KC_W, KC_T) { //move window top 50%
            SEND_STRING(SS_LCTL(SS_LGUI("t")));
        }

        SEQ_TWO_KEYS(KC_W, KC_I) { // move window left, scale appropreiately
            SEND_STRING(SS_LSFT(SS_LALT("i")));
        }

        SEQ_TWO_KEYS(KC_W, KC_O) { // move window right, scale appropreiately
            SEND_STRING(SS_LSFT(SS_LALT("o")));
        }
        // i3 - linux window manager commands (consider actually just making these the same as display fusion, or the opposit.)

        // synergy commands
        // .. Lead, a(pplications), s(ynergy), s(wap) - swap cursor/focus to other computer.
        SEQ_THREE_KEYS(KC_A, KC_S, KC_Q) { // Swap To Laptop
            SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("t"))));
        }

        SEQ_THREE_KEYS(KC_A, KC_S, KC_W) { // Swap To Desktop
            SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("g"))));
        }

        // File system
        SEQ_THREE_KEYS(KC_F, KC_A, KC_R) { // summon 'Everything'
            SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("r"))));
        }



    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case _LOWER:
        break;
    case _RAISE:
        break;
    case _ADJUST:
        break;
    case _BASE:
        // ...
        break;
    case _VIKEYS:
        // ...
        break;
    case _NAV:
        // ...
        break;
    case _GAMING:
        // ...
        break;
    case _ROGUE:
        // ...
        break;
    case _NUMPAD:
        break;
    default:
        break;
    }

    return true;
}
