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

#include "naughty.h"

#define LAYOUT_planck_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A \
  ) \
  LAYOUT_wrapper( \
   KC_ESC,  K01,    K02,     K03,     K04,     K05,    K06,     K07,     K08,     K09,     K0A,     KC_LEAD, \
   KC_BSPC, K11,    K12,     K13,     K14,     K15,    K16,     K17,     K18,     K19,     K1A,     KC_ENT, \
   KC_DEL,  K21,    K22,     K23,     K24,     K25,    K26,     K27,     K28,     K29,     K2A,     KC_TAB, \
   KC_HOME, KC_END, KC_PGUP, KC_PGDN, LOWER,   KC_SPC, KC_SPC,  RAISE,  KC_INS, KC_CAPS, KC_VOLD, KC_VOLU \
                  )
/* Re-pass though to allow templates to be used */
#define LAYOUT_planck_base_wrapper(...)       LAYOUT_planck_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |NAV|W |NUM|E | VI|R |   T  |   Y  |   U  |   I  |   O  |   P  | Lead |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BKSP |alt A |Ctrl S|Shft D|Win F |   G  |   H  |WinJ  |Sft K |Ctrl L|Alt ; |  ENT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  |  Z   |   X  |   C  |LT V  |   B  |   N  |LT M  |   ,  |   .  |   /  |  TAB |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Home | End  | PGUp | PGDN |Lower |    Space    |Raise | INS  | CAPS | VOLD | VOLU |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_base_wrapper(
    _________________MQWERTY_L1_________________, _________________MQWERTY_R1_________________,
    _________________MQWERTY_L2_________________, _________________MQWERTY_R2_________________,
    _________________MQWERTY_L3_________________, _________________MQWERTY_R3_________________
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
    _______, _________________LOWER_L1__________________, _________________LOWER_L1__________________, KC_CAPS,
    _______, _________________LOWER_L2__________________, _________________LOWER_L2__________________, _______,
    _______, _________________LOWER_L3__________________, _________________LOWER_L3__________________ ,_______,
    _______, _______, _______, _______, LOWER, KC_SPC,       KC_SPC, RAISE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                              ),
 /* KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_GRV,     _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, */
 /* KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,      KC_DQT, KC_EQL, KC_MINS, KC_UNDS, KC_QUOT, */
 /* KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_AMPR,  _______, _______,  KC_AMPR, KC_PIPE,  KC_BSLS, */


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
    _______, KC_1,      KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    _______,
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
    RESET,   TO(_BASE), TO(_GAMING), TO(_ROGUE), _______, _______, _______, _______, _______, _______, _______, _______,
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
   KC_BSPC, KC_A,    KC_S,    KC_D,       KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
   KC_DEL, KC_Z, KC_X,    KC_C,   KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TAB,
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
