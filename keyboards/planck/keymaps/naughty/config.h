#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Nkey rollover
#define FORCE_NKRO

// Tap terms
#define TAPPING_TERM 140 // set to my prefered 135ms

// tapping term per keycodes
/* #define TAPPING_TERM_PER_KEY */

// #define TAPPING_TOGGLE 3 // defined in another file outside of my config?

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


// leader key
#define LEADER_TIMEOUT 200 // shorter timing because we ae using per key timing
#define LEADER_PER_KEY_TIMING // sets the timer for leader key chords to run on each key press rather than overall

// could be useful for laptop?
/* #define USB_MAX_POWER_CONSUMPTION 500 */
