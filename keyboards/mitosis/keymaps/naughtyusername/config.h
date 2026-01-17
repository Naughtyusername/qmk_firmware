/* Mitosis config.h - User configuration */

#pragma once

// Caps Word configuration
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000 // 3 seconds

// Accordion/CHORDAL holds, primarily for mods on homerow
// permissive hold / hold on other key press
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
#define SPECULATIVE_HOLD

// Flow tap for fast typing without mis-input on home row mods
// Increased to reduce conflicts with tapping terms and make less aggressive
#define FLOW_TAP_TERM 100 // was at 200, but in theory this should be faster than the tapping term and we should stop that buggy feeling

// Tap terms for TD and Chords
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define LONGPRESS_DELAY 150
// #define LAYER_TOGGLE_DELAY 300

// Tri-layer configuration
#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 4

// Combo configuration
#define COMBO_TERM 50 // Time window to hit both keys (ms)

// One-shot configuration
#define ONESHOT_TAP_TOGGLE 2 // Tapping twice locks the one-shot
// Note: ONESHOT_TIMEOUT is already defined in keyboard config.h as 500ms

// Mouse key configuration - honestly never see myself using this - delete when done testing
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

// TODO we need to change this, bootmagic lite. so we can use keyboards at boot time.
// Enable NKRO by default (updated from deprecated FORCE_NKRO)
#define NKRO_DEFAULT_ON true
