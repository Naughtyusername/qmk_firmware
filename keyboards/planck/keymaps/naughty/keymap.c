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

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV,
  _GAMING,
  _ROGUE,

};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// custom names to shorten mod tap lengths and such
// Mod Taps
#define LALT_MT LALT_T(KC_A)
#define RALT_MT RALT_T(KC_SCLN)

#define LCTL_MT LCTL_T(KC_S)
#define RCTL_MT RCTL_T(KC_L)

#define LSFT_MT LSFT_T(KC_D)
#define RSFT_MT RSFT_T(KC_K)

#define LGUI_MT LGUI_T(KC_F)
#define RGUI_MT RGUI_T(KC_J)

//


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

          ctrl win ,  - move window bottom left 25%
          ctrl win .  - move window bottom right 25%
          ctrl win k - Move window top right 25%
          ctrl win l - Move window top left 25%
          ctrl win g - move window bottom 50%
          ctrl win t - move window top 50%

          shift alt T - move window left monitor, scale appropreiately
          shift alt R - move window right monitor, scale appropreiately

          shift alt ctrl left - move window left, split 50%
          shift alt ctrl right - move window right, split 50%
          shift ctrl win g - maximixe window
         */

        SEQ_TWO_KEYS(KC_W, KC_DOT) { // move window bottom right 25%
             SEND_STRING(SS_LCTL(SS_LGUI(".")));
        }

        SEQ_TWO_KEYS(KC_W, KC_COMM) { // move window bottom left 25%
            SEND_STRING(SS_LCTL(SS_LGUI(",")));
        }

        SEQ_TWO_KEYS(KC_W, KC_K) { // move window top left 25%
        }

        SEQ_TWO_KEYS(KC_W, KC_L) { // move window top right 25%
        }

        SEQ_TWO_KEYS(KC_W, KC_G) { // move window bottom 50%
        }

        SEQ_TWO_KEYS(KC_W, KC_T) { //move window top 50%
        }

        SEQ_TWO_KEYS(KC_W, KC_I) { // move window left, scale appropreiately
        }

        SEQ_TWO_KEYS(KC_W, KC_O) { // move window right, scale appropreiately
        }
        // ...






        }
};

    void leader_start(void) {
        // sequence started.
    };

    void leader_end(void) {
        // sequence ended
    };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  | VI|R |   T  |   Y  |   U  |   I  |   O  |   P  | Lead |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BKSP |alt A |Ctrl S|Shft D|Win F |   G  |   H  |WinJ  |Sft K |Ctrl L|Alt ; |  ENT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  |Z|Rais|   X  |   C  |   V  | LT B |LT N  |   M  |   ,  |   .  |   /  |  TAB |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |    Space    |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LEAD,
    KC_BSPC, LALT_MT, LCTL_MT, LSFT_MT, LGUI_MT, KC_G,    KC_H, RGUI_MT, RSFT_MT, RCTL_MT, RALT_MT, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    LT(_LOWER, KC_B),  LT(_LOWER, KC_N),    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    _______, _______, _______, _______, LOWER,   KC_SPC,  KC_SPC,  RAISE,   _______, _______, _______, _______
),

/* Lower | Todo: See if we can remove LT in here, couldn't in gui editor. if so add <> in instead of .
 * ,-----------------------------------------------------------------------------------.
 * |      |  !   |  @   |  {   |  }   |  `   |      |  +   |  -   |  *   |  /   |      |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * |      |  #   |  $   |  (   |  )   |  ~   |      |  =   |  -   |  _   |  '   |      |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * |      |  %   |  ^   |  [   |  ]   | LT   | LT   |  &   |  |   |  .   |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |             |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_GRV,  _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, _______,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD, _______, KC_EQL, KC_MINS, KC_UNDS, KC_QUOT, _______,
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
 * |RESET |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |             |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET, TO(_BASE), TO(_GAMING), TO(_ROGUE), _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

 [_GAMING] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
                                ),



/* ROGUE
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

[_ROGUE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _BASE:
      return false;
      break;
  }
  return true;
}
