#pragma once
#include "naughty.h"
// thanks to Drashna for the idea of the wrappers!
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_kyria_wrapper(...)            LAYOUT(__VA_ARGS__)

#define _________________MQWERTY_L1_________________        KC_Q,    NV_W,    KC_E,    VI_R,    KC_T
#define _________________MQWERTY_L2_________________        AL_A,    CT_S,    SH_D,    GU_F,    KC_G
#define _________________MQWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    LT_V,    KC_B

#define _________________MQWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________MQWERTY_R2_________________        KC_H,    GU_J,    SH_K,    CT_L,    AL_SCN
#define _________________MQWERTY_R3_________________        KC_N,    LT_M,    KC_COMM, KC_DOT,  KC_SLASH


#define ________________NUMBER_LEFT________________         KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________         KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10


#define _________________LOWER_L1__________________        KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_GRV
#define _________________LOWER_L2__________________        KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD
#define _________________LOWER_L3__________________        KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_LT

#define _________________LOWER_R1__________________        _______, KC_PLUS, KC_SCLN, KC_ASTR, KC_SLSH // copy paste on Y? or copy on Y pase on Slsh (P)
#define _________________LOWER_R2__________________        KC_DQT,  KC_EQL,  KC_MINS, KC_UNDS, KC_QUOT
#define _________________LOWER_R3__________________        KC_GT, KC_COLN, KC_AMPR, KC_PIPE, KC_BSLS



#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        _________________FUNC_LEFT_________________
#define _________________RAISE_L3__________________        _________________FUNC_RIGHT________________

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        KC_F11,       KC_4,    KC_5,    KC_6, KC_0
#define _________________RAISE_R3__________________        KC_F12,       KC_1,    KC_2,    KC_3, XXXXXXX



#define _________________ADJUST_L1_________________        TO(_BASE), TO(_GAMING), TO(_ROGUE), _______, _______
#define _________________ADJUST_L2_________________        _______, _______, _______, _______, _______
#define _________________ADJUST_L3_________________        _______, _______, _______, _______, _______

#define _________________ADJUST_R1_________________        _______, _______, _______, _______, _______
#define _________________ADJUST_R2_________________        _______, _______, KC_MSTP, KC_MPLY, KC_MUTE
#define _________________ADJUST_R3_________________        _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
// realistically wont ever use this i dont think?
#define _________________ADJUST_R4_________________        RAISE, _______, KC_MSTP, KC_MPLY, KC_MUTE


#define _________________VIKEYS_L1_________________        _______, _______, _______, _______, _______
#define _________________VIKEYS_L2_________________        _______, _______, _______, _______, _______
#define _________________VIKEYS_L3_________________        _______, _______, _______, _______, _______

#define _________________VIKEYS_R1_________________        _______, _______, _______, _______, _______
#define _________________VIKEYS_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    _______
#define _________________VIKEYS_R3_________________        _______, _______, _______, _______, _______


#define _________________NAV_L1_________________           _______, _______, _______, _______, _______
#define _________________NAV_L2_________________           _______, _______, _______, _______, _______
#define _________________NAV_L3_________________           _______, _______, _______, _______, _______

#define _________________NAV_R1_________________           _______, _______, _______, _______, _______
#define _________________NAV_R2_________________           KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______
#define _________________NAV_R3_________________           _______, _______, _______, _______, _______


#define _________________NUMPAD_L1__________________       _______, _______, _______, _______, _______
#define _________________NUMPAD_L2__________________       _______, _______, _______, _______, _______
#define _________________NUMPAD_L3__________________       _______, _______, _______, _______, _______

#define _________________NUMPAD_R1__________________       _______, KC_KP_7, KC_KP_8, KC_KP_9, _______
#define _________________NUMPAD_R2__________________       _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_0
#define _________________NUMPAD_R3__________________       _______, KC_KP_1, KC_KP_2, KC_KP_3, _______


#define _________________GAMING_L1__________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________GAMING_L2__________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________GAMING_L3__________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________GAMING_R1__________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________GAMING_R2__________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________GAMING_R3__________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________GAMING2_L1__________________       ________________NUMBER_LEFT________________
#define _________________GAMING2_L2__________________       _________________FUNC_LEFT_________________
#define _________________GAMING2_L3__________________       _________________FUNC_RIGHT________________

#define _________________GAMING2_R1__________________       _______, _______, _______, _______, _______
#define _________________GAMING2_R2__________________       _______, _______, _______, _______, _______
#define _________________GAMING2_R3__________________       _______, _______, _______, _______, _______

#define _________________GAMING3_L1__________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________GAMING3_L2__________________       AL_A,    CT_S,    SH_D,    KC_F,    KC_G
#define _________________GAMING3_L3__________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________GAMING3_R1__________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________GAMING3_R2__________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________GAMING3_R3__________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________ROGUE_L1__________________         KC_Q,    KC_W,    LT(_NUMPAD, KC_E),    KC_R,    KC_T
#define _________________ROGUE_L2__________________         KC_A,    KC_S,    KC_D,       KC_F,     KC_G
#define _________________ROGUE_L3__________________         KC_Z,    KC_X,    KC_C,       KC_V,     KC_B

#define _________________ROGUE_R1__________________         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________ROGUE_R2__________________         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________ROGUE_R3__________________         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

/* #define _________________something_L1__________________       _______, _______, _______, _______, _______ */
/* #define _________________something_L2__________________       _______, _______, _______, _______, _______ */
/* #define _________________something_L3__________________       _______, _______, _______, _______, _______ */

/* #define _________________something_R1__________________       _______, _______, _______, _______, _______ */
/* #define _________________something_R2__________________       _______, _______, _______, _______, _______ */
/* #define _________________something_R3__________________       _______, _______, _______, _______, _______ */

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ___________________BLANK___________________        _______, _______, _______, _______, _______
