#pragma once

// Nkey rollover
#define FORCE_NKRO // not sure i need when its in the .mk?

// Tap terms
#define TAPPING_TERM 140

// #define TAPPING_TOGGLE 3 // defined in another file outside of my config?

// permissive hold
#define PERMISSIVE_HOLD

// debounce delay
#define DEBOUNCE 5 // 5 is what i use on planck. adjust as needed

// ignore mod tap interrupt // https://docs.qmk.fm/#/feature_advanced_keycodes?id=mod-tap
// #define IGNORE_MOD_TAP_INTERRUPT // requires holding both keys for the tapping term
// to trigger the function/mod

#define TAPPING_FORCE_HOLD // prevents keys with modifiers from repeating without sending their modifier code.

// leader key
#define LEADER_TIMEOUT 280
#define LEADER_PER_KEY_TIMING // Resets the timer per each chorded key that is hit within the window, need short timeout to make this not feel laggy

// could be useful for laptop?
/* #define USB_MAX_POWER_CONSUMPTION 100 */
