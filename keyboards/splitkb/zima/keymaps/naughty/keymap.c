/* Copyright 2019 Thomas Baart
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

  Current Zima configuration.
  Thank you to all of the QMK team and contributors for this incredible firmware!
  -Naughtyusername

*/

#include "naughty.h"
#include QMK_KEYBOARD_H


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x3( /* Base */
        RESET,   TG(1),   TG(2),
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3
    ),
    [1] = LAYOUT_ortho_4x3( /* Layer 1 */
        RESET,   _______, XXXXXXX,
        AU_ON,   AU_OFF,  XXXXXXX,
        CK_TOGG, XXXXXXX, CK_UP,
        CK_RST,  XXXXXXX, CK_DOWN
    ),
    [2] = LAYOUT_ortho_4x3( /* Layer 2*/
        RGB_TOG, RGB_MOD, _______,
        RGB_HUI, RGB_SAI, RGB_VAI,
        RGB_HUD, RGB_SAD, RGB_VAD,
        HPT_TOG, HPT_FBK, HPT_CONT
    )
};
// clang-format on
