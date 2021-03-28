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

#include "naughty.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT_ortho_4x12_wrapper(
     KC_ESC,  _________________PlanckMQWERTY_L1___________, _________________MQWERTY_R1_________________, KC_CAPS,
     KC_BSPC, _________________MQWERTY_L2_________________, _________________MQWERTY_R2_________________, KC_ENT,
     KC_DEL,  _________________MQWERTY_L3_________________, _________________MQWERTY_R3_________________, KC_TAB,
     KC_HOME, KC_END, KC_PGUP, KC_PGDN, RAISE, KC_SPC,      KC_SPC, LOWER, KC_AMPR, _______, _______, KC_LEAD
                                       ),

   [_LOWER] = LAYOUT_ortho_4x12_wrapper(
     _______, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
     _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______,
     _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
     _______, KC_COLN, KC_COMMA, KC_DOT, RAISE, KC_SPC,    KC_SPC, LOWER, KC_SCLN, _______, _______, _______
                                        ),

   [_RAISE] = LAYOUT_ortho_4x12_wrapper(
     _______, _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
     _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, XXXXXXX,
     _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, XXXXXXX,
     TG(_BASE), _______, _______, KC_PSCR, RAISE, KC_SPC,   KC_SPC, LOWER, KC_0, KC_COMMA, KC_DOT, KC_LEAD
                                        ),

   [_ADJUST] = LAYOUT_ortho_4x12_wrapper(
     RESET,   _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, _______,
     _______, _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, _______,
     _______, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, _______,
     RGB_TOG, _______, _______, _______, RAISE, KC_SPC, KC_SPC, _________________ADJUST_R4_________________
                                         ),

   [_NORMIES] = LAYOUT_ortho_4x12_wrapper(
     KC_ESC,  _________________NORMIES_L1_________________, _________________NORMIES_R1_________________, KC_LEAD,
     KC_BSPC, _________________NORMIES_L2_________________, _________________NORMIES_R2_________________, KC_ENT,
     KC_DEL,  _________________NORMIES_L3_________________, _________________NORMIES_R3_________________, KC_TAB,
     TO(_BASE), KC_LALT, KC_LCTRL, KC_LSFT, KC_LGUI, KC_SPC,      KC_SPC, KC_RSFT, KC_INS, KC_CAPS, KC_VOLD, KC_VOLU
     ),

   [_VIKEYS] = LAYOUT_ortho_4x12_wrapper(
     _______, _________________VIKEYS_L1_________________, _________________VIKEYS_R1_________________, _______,
     _______, _________________VIKEYS_L2_________________, _________________VIKEYS_R2_________________, _______,
     _______, _________________VIKEYS_L3_________________, _________________VIKEYS_R3_________________, _______,
     TO(_BASE), KC_CIRC, KC_DLR, _______, _______, _______, ___________________BLANK___________________, _______
                                         ),

   [_NAV] = LAYOUT_ortho_4x12_wrapper(
     _______, _________________NAV_L1_________________, _________________NAV_R1_________________, _______,
     _______, _________________NAV_L2_________________, _________________NAV_R2_________________, _______,
     _______, _________________NAV_L3_________________, _________________NAV_R3_________________, _______,
     _______, ___________________BLANK___________________, ___________________BLANK___________________, _______
                                      ),

   [_GAMING] = LAYOUT_ortho_4x12_wrapper(
     KC_ESC,  _________________GAMING_L1__________________, _________________GAMING_R1__________________,   KC_LEAD,
     KC_BSPC, _________________GAMING_L2__________________, _________________GAMING_R2__________________,   KC_ENT,
     KC_DEL,  _________________GAMING_L3__________________, _________________GAMING_R3__________________,   KC_TAB ,
     TO(_BASE), KC_LALT, KC_LCTL, KC_LSFT, MO(_GAM2), KC_SPC,KC_SPC, MO(_NUMPAD), _______, _______, _______, _______
                                         ),

   [_GAMING2] = LAYOUT_ortho_4x12_wrapper(
     KC_ESC,  _________________GAMING2_L1__________________, _________________GAMING2_R1__________________,   KC_LEAD,
     KC_BSPC, _________________GAMING2_L2__________________, _________________GAMING2_R2__________________,   KC_ENT,
     KC_DEL,  _________________GAMING2_L3__________________, _________________GAMING2_R3__________________,   KC_TAB ,
     TO(_BASE), KC_LALT, KC_LCTL, KC_LSFT, _______, KC_SPC,KC_SPC, _______, _______, _______, _______, _______
     ),

   [_GAMING3] = LAYOUT_ortho_4x12_wrapper(
     KC_ESC,  _________________GAMING3_L1__________________, _________________GAMING3_R1__________________,   KC_LEAD,
     KC_BSPC, _________________GAMING3_L2__________________, _________________GAMING3_R2__________________,   KC_ENT,
     KC_DEL,  _________________GAMING3_L3__________________, _________________GAMING3_R3__________________,   KC_TAB ,
     TO(_BASE), KC_LALT, KC_LCTL, KC_LSFT, _______, KC_SPC,KC_SPC, _______, _______, _______, _______, _______
     ),

   [_ROGUE] = LAYOUT_ortho_4x12_wrapper(
     KC_ESC,  _________________ROGUE_L1__________________, _________________ROGUE_R1__________________, KC_LEAD,
     KC_BSPC, _________________ROGUE_L2__________________, _________________ROGUE_R2__________________, KC_ENT,
     KC_DEL,  _________________ROGUE_L3__________________, _________________ROGUE_R3__________________, KC_TAB,
     TO(_BASE), KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,   KC_SPC,  KC_SPC,  TO(_NUMPAD),   _______, _______, _______, _______
                                        ),

   [_NUMPAD] = LAYOUT_ortho_4x12_wrapper(
     _______, _________________NUMPAD_L1__________________, _________________NUMPAD_R1__________________, KC_NLCK,
     _______, _________________NUMPAD_L2__________________, _________________NUMPAD_R2__________________, _______,
     _______, _________________NUMPAD_L3__________________, _________________NUMPAD_R3__________________, _______,
     TO(_BASE), _______, _______, _______, _______, _______, _______, TO(_ROGUE),   KC_KP_0, _______, _______, _______
                                         ),

//  [_TEMPLATE] = LAYOUT_ortho_4x12_wrapper(
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//                                ),


};

LEADER_EXTERNS();
void matrix_scan_user(void) {
    // use mnemonics, Leader f ... for file management, etc.
    // todo: leader keys to do my display fusion window managment
    // todo: ...
    LEADER_DICTIONARY() {
        leading = false;
        /*
          Display fusion keybinds
          leader key W binds

          shift super , - move window bottom left 25%
          shift super . - move window bottom right 25%
          shift super k - Move window top left 25%
          shift super l - Move window top right 25%

          shift super j - move window bottom 50%
          shift super k - move window top 50%

          shift super n - move window left monitor, scale appropreiately
          shift super b - move window right monitor, scale appropreiately

          shift super h  - move window left, split 50%
          shift super l - move window right, split 50%
          shift super g     - maximixe window
         */

        SEQ_TWO_KEYS(KC_W, KC_DOT) {  // move window bottom right 25%
            SEND_STRING(SS_LCTL(SS_LGUI(".")));
        }

        SEQ_TWO_KEYS(KC_W, KC_COMM) {  // move window bottom left 25%
            SEND_STRING(SS_LCTL(SS_LGUI(",")));
        }

        SEQ_TWO_KEYS(KC_W, KC_K) {  // move window top left 25%
            SEND_STRING(SS_LCTL(SS_LGUI("k")));
        }

        SEQ_TWO_KEYS(KC_W, KC_L) {  // move window top right 25%
            SEND_STRING(SS_LCTL(SS_LGUI("l")));
        }

        SEQ_TWO_KEYS(KC_W, KC_G) {  // move window bottom 50%
            SEND_STRING(SS_LCTL(SS_LGUI("j")));
        }

        SEQ_TWO_KEYS(KC_W, KC_T) {  // move window top 50%
            SEND_STRING(SS_LCTL(SS_LGUI("k")));
        }

        SEQ_TWO_KEYS(KC_W, KC_I) {  // move window left, scale appropreiately
            SEND_STRING(SS_LSFT(SS_LALT("h")));
        }

        SEQ_TWO_KEYS(KC_W, KC_O) {  // move window right, scale appropreiately
            SEND_STRING(SS_LSFT(SS_LALT("l")));
        }
        // Bspwm - linux window manager commands (consider actually just making these the same as display fusion, or the opposit.)

        // synergy commands
        // .. Lead, a(pplications), s(ynergy), s(wap) - swap cursor/focus to other computer.
        // swap left alt ctrl shift t
        // swap left alt ctrl shift g
        SEQ_THREE_KEYS(KC_A, KC_S, KC_Q) {  // Swap To Laptop
            SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("t"))));
        }

        SEQ_THREE_KEYS(KC_A, KC_S, KC_W) {  // Swap To Desktop
            SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("g"))));
        }

        // File system
        SEQ_THREE_KEYS(KC_F, KC_A, KC_R) {  // summon 'Everything'
            SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("r"))));
        }
        // general commands
        // lead o w to send email string
        SEQ_TWO_KEYS(KC_O, KC_W) {  // summon 'Everything'
            SEND_STRING("whatsahardscope@gmail.com");
            // Tmux commands

            //end of commands

            matrix_scan_keymap();
            leader_end();
        }
    }
}

/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*                                              [TD_NAV] = action_tap_dance_ */
/* }; */

// clang-format on
void keyboard_post_init_user(void) {
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }

  return true;
}
