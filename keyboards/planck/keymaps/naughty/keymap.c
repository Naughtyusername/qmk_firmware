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



/*     switch(layer) { */
/*     case _LOWER: */
/*         break; */
/*     case _RAISE: */
/*         break; */
/*     case _ADJUST: */
/*         break; */
/*     case _BASE: */
/*         rgblight_sethsv(255, 255, 255); */
/*         break; */
/*     case _VIKEYS: */
/*         // ... */
/*         break; */
/*     case _NAV: */
/*         // ... */
/*         break; */
/*     case _GAMING: */
/*         // ... */
/*         break; */
/*     case _ROGUE: */
/*         // ...*/
/*         break; */
/*     case _NUMPAD: */
/*         break; */
/*     default: */
/*         break; */
/*     } */










#include QMK_KEYBOARD_H
#include "muse.h"


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

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// custom names to shorten mod tap lengths and such
// Mod Taps
#define AL_A LALT_T(KC_A)
#define AL_SCN RALT_T(KC_SCLN)

#define CT_S LCTL_T(KC_S)
#define CT_L RCTL_T(KC_L)

#define SH_D LSFT_T(KC_D)
#define SH_K RSFT_T(KC_K)

#define GU_F LGUI_T(KC_F)
#define GU_J RGUI_T(KC_J)

//

// clang format

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |NAV|W |NUM|E | VI|R |   T  |   Y  |   U  |   I  |   O  |   P  | Lead |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BKSP |alt A |Ctrl S|Shft D|Win F |   G  |   H  |WinJ  |Sft K |Ctrl L|Alt ; |  ENT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  |  Z   |   X  |   C  |   V  | LT B |LT N  |   M  |   ,  |   .  |   /  |  TAB |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |    Space    |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    LT(_NAV, KC_W),   LT(_RAISE, KC_E),    LT(_VIKEYS, KC_R),    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LEAD,
    KC_BSPC, AL_A,    CT_S,    SH_D,    GU_F,    KC_G,    KC_H,    GU_J,    SH_K,    CT_L,    AL_SCN,  KC_ENT,
    KC_DEL,  KC_Z,    KC_X,    KC_C,    KC_V,    LT(_LOWER, KC_B),  LT(_LOWER, KC_N),    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TAB ,
    _______, _______, _______, _______, LOWER,   KC_SPC,  KC_SPC,  RAISE,   _______, _______, _______, _______
),

/* Lower | Todo: See if we can remove LT in here, couldn't in gui editor. if so add <> in instead of .
 * ,-----------------------------------------------------------------------------------.
 * |      |  !   |  @   |  {   |  }   |  `   |      |  +   |  -   |  *   |  /   |      |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * |      |  #   |  $   |  (   |  )   |  ~   |      |  =   |  -   |  _   |  '   | Caps |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * |      |  %   |  ^   |  [   |  ]   | LT   | LT   |  &   |  |   |  .   |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |    SPACE    |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_GRV,  _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, _______,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD, _______, KC_EQL, KC_MINS, KC_UNDS, KC_QUOT, KC_CAPS,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, _______, KC_AMPR, KC_PIPE,  KC_LT, KC_GT,  KC_BSLS, _______,
    _______, _______, _______, _______, LOWER, KC_SPC, KC_SPC, RAISE, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |  7   |  8   |  9   |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Prnt  |  F1  |  F2  |  F3  | F4   |  F5  | F11  |  4   |  5   |  6   |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  | F9   | F10  | F12  |  1   |  2   |  3   |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |Lower |   Space     |Raise |  0   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,         KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_PSCR, KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F11,       KC_4,    KC_5,    KC_6, XXXXXXX,  XXXXXXX,
    _______, KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F12,      KC_1,    KC_2,    KC_3, XXXXXXX,  XXXXXXX,
    _______, _______, _______, _______, LOWER,  KC_SPC, KC_SPC,   RAISE,         KC_0,  XXXXXXX,  XXXXXXX, XXXXXXX
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
 * | BASE | ALT  | CTRL | SHFT |LOWER |    SPC      | RAISE|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

 [_GAMING] = LAYOUT_planck_grid(
   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LEAD,
   KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
   KC_DEL, LT(_RAISE, KC_Z),    KC_X,    KC_C,    KC_V,    LT(_LOWER, KC_B),  LT(_LOWER, KC_N),    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TAB ,
   TO(_BASE), KC_LALT, KC_LCTL, KC_LSFT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   _______, _______, _______, _______
   ),



/* ROGUE
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | LEAD?|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BKS  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  ENT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  |NUM Z |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   | TAB  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BASE | ALT  | CTRL | SHFT |LOWER |    SPC      | RAISE|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_ROGUE] = LAYOUT_planck_grid(
   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LEAD,
   KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
   KC_DEL, LT(_NUMPAD, KC_Z),    KC_X,    KC_C,    KC_V,    LT(_LOWER, KC_B),  LT(_LOWER, KC_N),    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TAB ,
   TO(_BASE), KC_LALT, KC_LCTL, KC_LSFT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   _______, _______, _______, _______
                              ),

/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  7   |  8   |  9   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  4   |  5   |  6   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BASE  |      |      |      |      |             |Raise |  0   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______,   KC_KP_7, KC_KP_8, KC_KP_9, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   KC_KP_4, KC_KP_5, KC_KP_6, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   KC_KP_1, KC_KP_2, KC_KP_3, _______, _______,
    TO(_BASE), _______, _______, _______, _______, _______, _______, _______, KC_KP_0, _______, _______, _______
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

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(biton32(state)) {
        case _LOWER:
            rgblight_sethsv(HSV_GREEN);
            break;
        case _RAISE:
            rgblight_sethsv(HSV_CORAL);
            break;
        case _ADJUST:
            rgblight_sethsv(HSV_RED);
            break;
        case _BASE:
            rgblight_sethsv(HSV_CHARTREUSE);
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

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

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

// test - lets us enable the rgb? hopefully
void matrix_init_user() {
    rgblight_enable();

}

void keyboard_post_init_user(void) {
	rgblight_enable_noeeprom();
	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
	rgblight_disable_noeeprom();
};


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
