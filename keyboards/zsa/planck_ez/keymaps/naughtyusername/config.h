#pragma once

/* --- Tapping & Holding Behavior --- */
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 0
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define LONGPRESS_DELAY 150
#define LAYER_TOGGLE_DELAY 300

/* --- Feature Configuration --- */
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000
#define COMBO_COUNT 1
#define COMBO_TERM 50
#define ONESHOT_TAP_TOGGLE 2

/* --- Layer & System Settings --- */
#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 4
#define NKRO_DEFAULT_ON true

/* --- RGB Matrix & Lighting --- */
// DO NOT use "= yes" here. Just defining the name turns it on.
#ifndef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_ENABLE
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10
#endif
