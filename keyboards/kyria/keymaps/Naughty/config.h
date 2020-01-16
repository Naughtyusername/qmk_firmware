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

// rgb shit
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

 // split rgb
 #define RGBLIGHT_SPLIT

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
#define SPLIT_USB_DETECT
#define NO_USB_STARTUP_CHECK

// Nkey rollover
#define FORCE_NKRO

// Tap terms
#define TAPPING_TERM 140 // set to my prefered 135ms

// tapping term per keycodes
/* #define TAPPING_TERM_PER_KEY */

#define TAPPING_TOGGLE 3

// permissive hold
#define PERMISSIVE_HOLD

// debounce delay
#define DEBOUNCE 5 // 5 is what i use on planck. adjust as needed

// ignore mod tap interrupt // https://docs.qmk.fm/#/feature_advanced_keycodes?id=mod-tap
// #define IGNORE_MOD_TAP_INTERRUPT // requires holding both keys for the tapping term
// to trigger the function/mod

// #define TAPPING_FORCE_HOLD // when the user holds a key after tap this repeats
// the tapped key rather to hold a modifier key this allows us to use auto repeat
// for the tped key.

// #define RETRO_TAPPING // holding and releasing a dual function key without
// pessing another key will result in nothing happening. with retro enabled
// releasing the key without pressing another will send the original keycode even
// if outside the tapping term.

// the resolution can be specified in the same file (the default suggested is 4) might not need
#define ENCODER_RESOLUTION 2

// a.llows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10

// leader key
#define LEADER_TIMEOUT 200 // shorter timing because we ae using per key timing
#define LEADER_PER_KEY_TIMING // sets the timer for leader key chords to run on each key press rather than overall




// allows to use either side a the master. Loook at the documentation for information
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS

// could be useful for laptop?
/* #define USB_MAX_POWER_CONSUMPTION 500 */

// Allows sending more than one key per scan. By default, only one key event gets sent via process_record() per scan. This has little impact on most typing, but if you're doing a lot of chords, or your scan rate is slow to begin with, you can have some delay in processing key events. Each press and release is a separate event. For a keyboard with 1ms or so scan times, even a very fast typist isn't going to produce the 500 keystrokes a second needed to actually get more than a few ms of delay from this. But if you're doing chording on something with 3-4ms scan times? You probably want this.
#define QMK_KEYS_PER_SCAN 4









// disable for more firmware space
// #define no_action_macro
// #define no_action_function

#ifndef no_debug
#define no_debug
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
//
//
//
//

/*
  If you define these options you will disable the associated feature, which can save on code size.

  #define NO_DEBUG
  disable debugging
  #define NO_PRINT
  disable printing/debugging using hid_listen
  #define NO_ACTION_LAYER
  disable layers
  #define NO_ACTION_TAPPING
  disable tap dance and other tapping features
  #define NO_ACTION_ONESHOT
  disable one-shot modifiers
  #define NO_ACTION_MACRO
  disable old style macro handling: MACRO() & action_get_macro
  #define NO_ACTION_FUNCTION
  disable calling of action_function() from the fn_actions array (deprecated)
 */
