/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

// undefined to save space just in case we wanna use some more for other features that im considering adding in saved us about 2kib
#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#    undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    undef RGBLIGHT_EFFECT_SNAKE
#    undef RGBLIGHT_EFFECT_KNIGHT
#    undef RGBLIGHT_EFFECT_CHRISTMAS
#    undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#    undef RGBLIGHT_EFFECT_RGB_TEST
#    undef RGBLIGHT_EFFECT_ALTERNATING
#    undef RGBLIGHT_EFFECT_TWINKLE
#endif

// custom
#define MASTER_LEFT

// Layer specific lighting
#define RGB_LIGHT_LAYERS

// Keeps them the way im used to.
#define ENCODER_DIRECTION_FLIP

// Accordion/CHORDAL holds, primarily for mods on homerow
// permissive hold / hold on other key press
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD

// Caps Word configuration
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000 // 3 seconds

// Flow tap for fast typing without mis-input on home row mods
#define FLOW_TAP_TERM 150

// Tap terms for TD and Chords
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define LONGPRESS_DELAY 150
#define LAYER_TOGGLE_DELAY 300

// Tri-layer configuration
#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 4

// Combo configuration
#define COMBO_TERM 50 // Time window to hit both keys (ms)

// One-shot configuration
#define ONESHOT_TAP_TOGGLE 2 // Tapping twice locks the one-shot
// Note: ONESHOT_TIMEOUT is already defined in the base keyboard config.h as 500ms

// Mouse key configuration
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

// Enable NKRO by default (updated from deprecated FORCE_NKRO)
#define NKRO_DEFAULT_ON true
