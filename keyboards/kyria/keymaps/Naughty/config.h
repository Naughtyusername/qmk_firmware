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

// https://docs.qmk.fm/#/config_options?id=behaviors-that-can-be-configured

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
#define SPLIT_USB_DETECT
#define NO_USB_STARTUP_CHECK

// Tap terms
#define TAPPING_TERM 135 // set to my prefered 135ms

// Nkey rollover
#define FORCE_NKRO

// Combo Count, adjust this number later!
#define COMBO_COUNT 1


// Init encoder pads
#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }

#define ENCODERS_PAD_A { encoder1a, encoder2a }
#define ENCODERS_PAD_B { encoder1b, encoder2b }
// If encoders clockwise directions are incorrect you can swap the a and b pad definitions

// the resolution can be specified in the same file (the default suggested is 4) might not need
 #define ENCODER_RESOLUTION 4

// split keyboards - different pinouts for the encoders on each half of a split keyboard,
// you can define the pinout for the right half like this
#define ENCODERS_PAD_A_RIGHT { encoder1a, encoder2a }
#define ENCODERS_PAD_B_RIGHT { encoder1b, encoder2b }

// permissive hold
#define PERMISSIVE_HOLD

#define
