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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT_ortho_4x12_wrapper(
     KC_ESC,  _________________MQWERTY_L1_________________, _________________MQWERTY_R1_________________, KC_LEAD,
     KC_BSPC, _________________MQWERTY_L2_________________, _________________MQWERTY_R2_________________, KC_ENT,
     KC_DEL,  _________________MQWERTY_L3_________________, _________________MQWERTY_R3_________________, KC_TAB,
     KC_HOME, KC_END, KC_PGUP, KC_PGDN, LOWER, KC_SPC,      KC_SPC, RAISE, KC_INS, KC_CAPS, KC_VOLD, KC_VOLU
                                       ),

   [_LOWER] = LAYOUT_ortho_4x12_wrapper(
     _______, _________________LOWER_L1__________________, _________________LOWER_R1__________________, KC_CAPS,
     _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______,
     _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
     _______, _______, _______, _______, LOWER, KC_SPC,    KC_SPC, RAISE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                        ),

   [_RAISE] = LAYOUT_ortho_4x12_wrapper(
     _______, _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
     _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, XXXXXXX,
     _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, XXXXXXX,
     TG(_BASE), _______, _______, KC_PSCR, LOWER, KC_SPC,   KC_SPC, RAISE, KC_0, XXXXXXX, XXXXXXX, XXXXXXX
                                        ),

   [_ADJUST] = LAYOUT_ortho_4x12_wrapper(
     RESET,   _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, _______,
     _______, _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, _______,
     _______, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, _______,
     RGB_TOG, _______, _______, _______, LOWER, KC_SPC, KC_SPC, _________________ADJUST_R4_________________
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


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* case _LOWER: */
    /*     break; */
    /* case _RAISE: */
    /*     break; */
    /* case _ADJUST: */
    /*     break; */
    /* case _BASE: */
    /*     // ... */
    /*     break; */
    /* case _VIKEYS: */
    /*     // ... */
    /*     break; */
    /* case _NAV: */
    /*     // ... */
    /*     break; */
    /* case _GAMING: */
    /*     // ... */
    /*     break; */
    /* case _ROGUE: */
    /*     // ... */
    /*     break; */
    /* case _NUMPAD: */
    /*     break; */
  default:
    break;
  }

  return true;
}
