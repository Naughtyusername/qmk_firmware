/* Copyright 2019 Thomas Baart <thomas@splitkb.com>

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

  My current set up for the Kyria board, Thanks to Thomas for making this awesome keyboard for us! and thanks to the QMK team for
  providing us with this amazing firmware!
                                            -Naughtyusername
*/

// git fetch upstream - git pull upstream master - git push origin master -- or just use magit and ignore gits annoyance
#include QMK_KEYBOARD_H

// Todo: define some more things to make it more readable. (colors i like, cleaner keybinds, etc.)


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

enum layers {
             _BASE,
             _LOWER,
             _RAISE,
             _ADJUST,
             _VIKEYS,
             _NAV,
             _GAMING,
             _GAMING2,
             _ROGUE,
             _NUMPAD
};

// tap dancing key initilizations
enum tapdancers {
                 TD_MUTE_PLAY = 0,
                 TD_HOME_END,
                 TD_TG_BASE,
                 TD_TG_VI,
                 TD_TG_NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: BASE
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |     ESC|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | CAPS   |
   |        |      | Nav  |  Num |TDTGVI|      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |     BS |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | Enter  |
 * |        | Alt  | Ctrl | Shift| Win  |      |                              |      |  Win |  Shft|  Ctrl| Alt  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Delete |   Z  |   X  |   C  |   V  |   B  |      |      |  |Leader|      |   N  |   M  | ,  < | . >  | /  ? | Tab    |
 * |        |      |      |      |Lower |      |      |      |  |      |      |      | Lower|      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |TDMUTE|      |      |  "   | Space|  |Enter |      |      |      | Home |
 *                        | Play |      |      | Lower| Raise|  |Lower | Lower|      |      | End  |
 *                        `----------------------------------'  `----------------------------------'
 *  Rotary: clock - VOLU | counter - VOLD | Push - Mute/play|     Rotary: clock - PGDN | counter - PGUP | push - Tap dance a home/end
 */
    [_BASE] = LAYOUT(
      KC_ESC,  KC_Q,   NV_W,   KC_E, TD(TD_TG_VI), KC_T,                                                  KC_Y, KC_U, KC_I, KC_O, KC_P, KC_CAPS,
      KC_BSPC, AL_A, CT_S, SH_D, GU_F, KC_G,                                                      KC_H, GU_J, SH_K, CT_L, AL_SCN, KC_ENT,
      KC_DEL,  KC_Z,   KC_X,   KC_C,   LT_V, KC_B, _______, _______,                  KC_LEAD, _______,   KC_N, LT_M, KC_COMM, KC_DOT,  KC_SLSH, KC_TAB,
      TD(TD_MUTE_PLAY), _______, _______, KC_DQT, LT(_RAISE, KC_SPC),      LT(_LOWER, KC_ENT), MO(_LOWER), _______, _______, TD(TD_HOME_END)
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  `   |                              |      |  +   |  -   |  *   |  /   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  ~   |                              |  "   |  =   |  -   |  _   |  '   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |      |      |      |  |      |      |  &   |  |   |  <   |  >   |  \   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | Prnt |      |      |Space |  |      |      |  "   |      |      |
 *                        |      |      |      |      |Shift |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *       Rotary: Counter Clock - ^ Clockwise - $ | Push -                                    Rotary: not sure
 */
    [_LOWER] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_GRV,                                                       _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, _______,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,                                                      _______, KC_EQL, KC_MINS, KC_UNDS, KC_QUOT,  _______,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, _______, _______, _______,                  _______, _______, KC_AMPR, KC_PIPE,  KC_LT, KC_GT,  KC_BSLS,   _______,
                          _______, KC_PSCR, _______, _______, LSFT_T(KC_SPC),                  KC_DQT,  _______, KC_DQT, _______, _______
    ),
/*
 * Raise Layer: Number keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |   7  |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F1  |  F2  | F3   | F4   | F5   |                              |      |   4  |  5   |  6   |  0   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | BASE   |  F6  |  F7  | F8   | F9   | F10  | F11  | F12  |  |      |      |      |   1  |  2   |  3   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Prnt |      |  |      |      |      |      |  0   |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *                  Rotary: not sure                                                                Rotary: 0 when pressed, for now
 */
    [_RAISE] = LAYOUT(
      _______, KC_1,      KC_2,    KC_3,    KC_4,    KC_5,                                               KC_6,    KC_7, KC_8, KC_9, KC_0,    _______,
      _______, KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,                                             _______,  KC_4, KC_5, KC_6, KC_0, _______,
      TO(_BASE), KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12,          _______, _______, _______,  KC_1, KC_2, KC_3, _______, _______,
                                _______, _______, _______, KC_PSCR, _______,          _______, _______, _______, _______,   KC_0
    ),
/*
 * Adjust Layer: Layer switching, media controls,firmware reset, not sure what else.
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | RESET  | BASE |GAMING|ROGUE |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | RGBTOG |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |VOL   |      |      |      |      |  |      |      |      |      |MPlay|
 *                        |      |      |      |      |      |  |      |      |      |      |     |
 *                        `----------------------------------'  `---------------------------------'
 *        Rotary: clock - vol up | counter - vol down | push - mute               Rotary: clock - next media | counter - Prev media | push - pause
 */
    [_ADJUST] = LAYOUT(
      RESET, TO(_BASE), TO(_GAMING), TO(_ROGUE), _______, _______,                                  _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
      RGB_TOG, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                 KC_MUTE, _______, _______, _______, _______,     _______, _______, _______, _______, KC_MPLY
                       ),

 /*
  * VI Keys Layer:
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * | Esc    | Q    |   W  |  E   |  R   |  T   |                              |   Y  |  U   |  I   |  O   |  P   |        |
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * | BkSpc  |  A   |  S   |   D  |   F  |  G   |                              |   H  |  J   |  K   |  L   |  ;   |enter   |
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * | DEl    |  Z   |  X   |   C  |  V   |  B   |      |      |  |      |      |   N  |  M   |  ,   |  .   |  /   |tab     |
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |Space |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  *                 Rotary: counter - ^ clock - $ push - idk                                  Rotary: counter - clock - push
  */

 [_VIKEYS] = LAYOUT(
                    KC_ESC,    KC_Q,   KC_W,   LT(_NUMPAD, KC_E),   TD(TD_TG_BASE), KC_T,                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
       KC_BSPC,   KC_A, KC_S,  KC_D,   KC_F, KC_G,                                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
       KC_DEL,    KC_Z,   KC_X,   KC_C,   KC_V, KC_B, _______, _______,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TAB,
                            _______, _______, _______, _______, KC_SPC,   _______, _______,  _______, _______,  _______
                    ),
// * Gaming Layer
// *
// * ,-------------------------------------------.                              ,-------------------------------------------.
// * | Esc    | Q    |   W  |  E   |  R   |  T   |                              |   Y  |  U   |  I   |  O   |  P   |        |
// * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
// * | BkSpc  |  A   |  S   |   D  |   F  |  G   |                              |   H  |  J   |  K   |  L   |  ;   |enter   |
// * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
// * | DEl    |  Z   |  X   |   C  |  V   |  B   |      |ToGam2|  |      |      |   N  |  M   |  ,   |  .   |  /   |tab     |
// * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
// * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
// *                        |      |TOBase|      |      |Space |  |TOROG |      |      |      |      |
// *                        |      |      |      |      |      |  |      |      |      |      |      |
// *                        `----------------------------------'  `----------------------------------'
// *                  Rotary: not sure                                                                Rotary: not sure
// *
// *


     [_GAMING] = LAYOUT(
       KC_ESC,    KC_Q,   KC_W,   KC_E,   LT(_VIKEYS, KC_R), KC_T,                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
       KC_BSPC,   KC_A, KC_S,  KC_D,   KC_F, KC_G,                                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
       KC_DEL,    LT(_RAISE, KC_Z),   KC_X,   KC_C,   KC_V, KC_B, _______, TO(_GAMING2),    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TAB,
                                      _______, TO(_BASE), _______, _______, KC_SPC,    TO(_ROGUE), _______,  _______, _______,  _______
                        ),

// * ROGUE
// *
// * ,-------------------------------------------.                              ,-------------------------------------------.
// * |        |      |      |      |      |      |                              |      | N7   |  N8  | N9   |      |        |
// * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
// * |        |      |      |      |      |      |                              |      | N4   |  N5  | N6   |      |        |
// * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
// * |        |      |      |      |      |      |      |TOGam2|  |      |      |      | N1   |  N2  | N3   |      |        |
// * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
// * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
// *                        |      |      |      |      |TOgame|  |      |      |      | N0   |      |
// *                        |      |      |      |      |      |  |      |      |      |      |      |
// *                        `----------------------------------'  `----------------------------------'
// *                  Rotary: not sure                                                                Rotary: not sure
// *
// *


     [_ROGUE] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                        _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______,
       _______, _______, _______, _______, _______, _______,                                        _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_0, _______,
       _______, _______, _______, _______, _______, _______, _______, TO(_GAMING2),    _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______,
                                _______, _______, _______, _______, TO(_GAMING),    _______, _______, _______, _______, _______
                           ),

/*
 * Raise Layer: Gaming2
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |   7  |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F1  |  F2  | F3   | F4   | F5   |                              |      |   4  |  5   |  6   |  0   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F6  |  F7  | F8   | F9   | F10  | F11  | F12  |  |      |      |      |   1  |  2   |  3   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Prnt |      |  |      |      |      |      |  0   |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *                  Rotary: not sure                                                                Rotary: 0 when pressed, for now
 */
    [_GAMING2] = LAYOUT(
      _______, KC_1,      KC_2,    KC_3,    KC_4,    KC_5,                                               KC_6,    KC_7, KC_8, KC_9, KC_0,    _______,
      _______, KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,                                             _______,  KC_4, KC_5, KC_6, KC_0, _______,
      _______, KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12,          _______, _______, _______,  KC_1, KC_2, KC_3, _______, _______,
                                _______, _______, _______, KC_PSCR, _______,          _______, _______, _______, _______,   KC_0
    ),


/*
// * Layer template
// *
// * ,-------------------------------------------.                              ,-------------------------------------------.
// * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
// * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
// * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
// * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
// * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
// *                        |      |      |      |      |      |  |      |      |      |      |      |
// *                        |      |      |      |      |      |  |      |      |      |      |      |
// *                        `----------------------------------'  `----------------------------------'
// *                  Rotary: not sure                                                                Rotary: not sure
// *
// *
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
*/

};


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
                                             // misc
                                             [TD_MUTE_PLAY] =        ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_MPLY),
                                             [TD_HOME_END] =         ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),

                                             // layers
                                             [TD_TG_BASE] =          ACTION_TAP_DANCE_LAYER_TOGGLE(KC_R, _BASE),
                                             [TD_TG_NUM] =           ACTION_TAP_DANCE_LAYER_TOGGLE(KC_E, _RAISE),
               /* might not work LT*/        [TD_TG_VI] =            ACTION_TAP_DANCE_LAYER_TOGGLE(LT(_VIKEYS, KC_R), _VIKEYS),
                                             // gaming layers ? theory
};

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


        // File system
        SEQ_THREE_KEYS(KC_F, KC_A, KC_R) { // summon 'Everything'
            SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("r"))));
        }

        SEQ_THREE_KEYS(KC_F, KC_A, KC_F) { // summon 'Everything'
            // SEND_STRING(); // open fman. its not summonable like everything so do ...
        }

    }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
    case _BASE:
        oled_write_P(PSTR("BASE\n"), false);
        break;
    case _LOWER:
        oled_write_P(PSTR("Lower\n"), false);
        break;
    case _RAISE:
        oled_write_P(PSTR("Raise\n"), false);
        break;
    case _ADJUST:
        oled_write_P(PSTR("Adjust\n"), false);
        break;
    case _VIKEYS:
        oled_write_P(PSTR("ViKeys\n"), false);
        break;
    case _GAMING:
        oled_write_P(PSTR("Gaming\n"), false);
        break;
    case _ROGUE:
        oled_write_P(PSTR("Rogue\n"), false);
        break;
    default:
        oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    // Left encoder
    if (index == 0) {
        switch(biton32(layer_state)) {
            case _BASE:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        case _LOWER:
        case _RAISE:
        case _ADJUST:
        case _VIKEYS:
        case _GAMING:
        case _ROGUE:
        default: break;
        }
    }
    // Right encoder
    if (index == 1) {
        switch(biton32(layer_state)) {
        case _BASE:
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
            break;
        case _LOWER:
        case _RAISE:
        case _ADJUST:
        case _VIKEYS:
        case _GAMING:
        case _ROGUE:
        default: break;
        }

    }
}
#endif
