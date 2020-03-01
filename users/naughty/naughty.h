#pragma once
#include QMK_KEYBOARD_H
#include "muse.h"
#include "wrappers.h"
#include "quantum.h"
#include "action.h"
#include "version.h"

#ifdef TAP_DANCE_ENABLE
#    include "tapdance.h"
// include tap dance short name definitions here later
#endif  // TAP_DANCE_ENABLE

// clang-format off
enum userspace_layers {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _VIKEYS,
    _NAV,
    _GAMING,
    _GAMING2,
    _ROGUE,
    _NUMPAD
};
// clang-format on

// Mod Taps - custom names to shorten mod tap lengths and such
#define AL_A LALT_T(KC_A)
#define AL_SCN RALT_T(KC_SCLN)

#define CT_S LCTL_T(KC_S)
#define CT_L RCTL_T(KC_L)

#define SH_D LSFT_T(KC_D)
#define SH_K RSFT_T(KC_K)

#define GU_F LGUI_T(KC_F)
#define GU_J RGUI_T(KC_J)

#define VI_R LT(_VIKEYS, KC_R)
#define NV_W LT(_NAV, KC_W)
#define NM_E LT(_RAISE, KC_E)

#define LT_V LT(_LOWER, KC_V)
#define LT_M LT(_LOWER, KC_M)

#define SH_SPC RSFT_T(KC_SPC)

#define RsSPC LT(RAISE, KC_SPC)
#define LwENT LT(LOWER, KC_ENT)

#define _GAM _GAMING
#define _GAM2 _GAMING2
#define _ROG _ROGUE

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// define another set of tri layer state things for gaming layers, i think it would be really useful
