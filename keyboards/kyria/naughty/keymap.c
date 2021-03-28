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

#include "naughty.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
       [_BASE] = LAYOUT_wrapper(
       KC_ESC,  _________________MQWERTY_L1_________________,                                        _________________MQWERTY_R1_________________, KC_CAPS,
       KC_BSPC, _________________MQWERTY_L2_________________,                                        _________________MQWERTY_R2_________________, KC_ENT,
       KC_DEL,  _________________MQWERTY_L3_________________, KC_LT, KC_AMPR,        TO(_NUMPAD), /*KC_LEAD*/ KC_GT, _________________MQWERTY_R3_________________, KC_TAB,
                                    KC_MUTE, KC_TAB, KC_ASTR, KC_QUOT, RsSPC,        LwENT, KC_EQL, KC_PIPE, KC_COLN, KC_HOME
                                ),

       [_LOWER] = LAYOUT_wrapper(
       _______, _________________LOWER_L1__________________,                                         _________________LOWER_R1__________________, _______,
       _______, _________________LOWER_L2__________________,                                         _________________LOWER_R2__________________, _______,
       _______, _________________LOWER_L3__________________,   KC_LT, KC_PIPE,     KC_COLN, KC_GT,   _________________LOWER_R3__________________, _______,
                                    _______, _______, _______, KC_DQT,  RsSPC,     KC_ENT, KC_QUES,  _______, _______, _______
                                 ),

     [_RAISE] = LAYOUT_wrapper(
       _______, _________________RAISE_L1__________________,                                         _________________RAISE_R1__________________, _______,
       _______, _________________RAISE_L2__________________,                                         _________________RAISE_R2__________________, _______,
       _______, _________________RAISE_L3__________________, KC_F11, KC_F12,     _______, _______, _________________RAISE_R3__________________, _______,
                               KC_PSCR, _______, _______,  _______, _______,     _______, _______, _______, _______, _______
                               ),

     [_ADJUST] = LAYOUT_wrapper(
       _______, _________________ADJUST_L1_________________,                                         _________________ADJUST_R1_________________, KC_NLCK,
       _______, _________________ADJUST_L2_________________,                                         _________________ADJUST_R2_________________, _______,
       _______, _________________ADJUST_L3_________________, _______, _______,     _______, _______, _________________ADJUST_R3_________________, _______,
                                  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

       [_NORMIES] = LAYOUT_wrapper(
         _______, _________________NORMIES_L1_________________,                                         _________________NORMIES_R1_________________, _______,
         _______, _________________NORMIES_L2_________________,                                         _________________NORMIES_R2_________________, _______,
         _______, _________________NORMIES_L3_________________, _______, _______,     _______, _______, _________________NORMIES_R3_________________, _______,
         TO(_BASE), KC_LALT, _______, _______, _______,     _______, _______, _______, _______, _______
         ),

     [_NAV] = LAYOUT_wrapper(
       _______, _________________NAV_L1_________________,                                         _________________NAV_R1_________________, _______,
       _______, _________________NAV_L2_________________,                                         _________________NAV_R2_________________, _______,
       _______, _________________NAV_L3_________________, _______, _______,     _______, _______, _________________NAV_R2_________________, _______,
                               _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
                             ),

     [_VIKEYS] = LAYOUT_wrapper(
       _______, _________________VIKEYS_L1_________________,                                        _________________VIKEYS_R1_________________, _______,
       _______, _________________VIKEYS_L2_________________,                                        _________________VIKEYS_R2_________________, _______,
       _______, _________________VIKEYS_L3_________________, _______, _______,     _______, _______, _________________VIKEYS_R3_________________, _______,
                                   _______, _______, _______, KC_CIRC, KC_SPC,     _______, KC_DLR, _______, _______, _______
    ),

     [_GAMING] = LAYOUT_wrapper(
       _______, _________________GAMING_L1__________________,                                        _________________GAMING_R1__________________, _______,
       _______, _________________GAMING_L2__________________,                                        _________________GAMING_R2__________________, _______,
       _______, _________________GAMING_L3__________________,   KC_F9,   KC_F5,     TO(_GAM3), _______, _________________GAMING_R3__________________, _______,
                                      TO(_BASE), KC_U, KC_Y, MO(_GAM2), KC_SPC,     TO(_GAM2), _______, _______, _______, _______
   ),

     [_GAMING2] = LAYOUT_wrapper(
       _______, _________________GAMING2_L1__________________,                                        _________________GAMING2_R1__________________, _______,
       _______, _________________GAMING2_L2__________________,                                        _________________GAMING2_R2__________________, _______,
       _______, _________________GAMING2_L3__________________,     KC_F11, KC_F12,     _______, _______, _________________GAMING2_R3__________________, _______,
                                       TO(_GAM), KC_LEAD, KC_Y, _______, KC_SPC,     _______, _______, _______, _______, _______
                                 ),
     [_GAMING3] = LAYOUT_wrapper(
       _______, _________________GAMING3_L1__________________,                                        _________________GAMING3_R1__________________, _______,
       _______, _________________GAMING3_L2__________________,                                        _________________GAMING3_R2__________________, _______,
       _______, _________________GAMING3_L3__________________,     _______, _______,     _______, _______, _________________GAMING3_R3__________________, _______,
       TO(_BASE), _______, _______, _______, LT(_ROGUE, KC_SPC),    _______, _______, _______, _______, _______

       ),

     [_ROGUE] = LAYOUT_wrapper(
       _______, _________________ROGUE_L1__________________,                                        _________________ROGUE_R1__________________, _______,
       _______, _________________ROGUE_L2__________________,                                        _________________ROGUE_R2__________________, _______,
       _______, _________________ROGUE_L3__________________, TO(_GAM), TO(_GAM2),     _______, _______, _________________ROGUE_R3__________________, _______,
                                    TO(_BASE), _______, _______, _______, KC_SPC,     _______, TO(_NUMPAD), _______, _______, _______
                               ),

     [_NUMPAD] = LAYOUT_wrapper(
        _______, _________________NUMPAD_L1__________________,                                        _________________NUMPAD_R1__________________, KC_NLCK,
        _______, _________________NUMPAD_L2__________________,                                        _________________NUMPAD_R2__________________, _______,
        _______, _________________NUMPAD_L3__________________, _______, _______,     TO(_BASE), _______, _________________NUMPAD_R3__________________, _______,
                                    TO(_GAM), _______, _______, _______, KC_SPC,     _______, _______, _______, _______, _______
                                ),
};
// clang-format on

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

// clang-format off
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

void matrix_scan_keymap(void) {
}

// clang-format on
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
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST\n"), false);
            break;
        case _NORMIES:
            oled_write_P(PSTR("NORMIES\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        case _VIKEYS:
            oled_write_P(PSTR("VIKEYS\n"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("GAMING\n"), false);
            break;
        case _GAMING2:
            oled_write_P(PSTR("GAMING2\n"), false);
            break;
        case _GAMING3:
            oled_write_P(PSTR("GAMING3\n"), false);
            break;
        case _ROGUE:
            oled_write_P(PSTR("ROGUE\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("NUMPAD\n"), false);
            break;
        default:
            oled_write_P(PSTR("YOU FORGOT\nTO NAME IT\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

// temp
#ifdef ENCODER_ENABLE
// still backwards
uint8_t selected_layer = 0;
void    encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            // Volume control
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            // Page up/Page down
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
    case 1:
      if (!clockwise && selected_layer < 10) {
        selected_layer ++;
      } else if (clockwise && selected_layer > 0) {
        selected_layer --;
      }
      layer_clear();
      layer_on(selected_layer);
    }
}
#endif
