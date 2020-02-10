/*
  Copyright 2017 Christopher Courtney <drashna@live.com> @drashna

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include QMK_KEYBOARD_H
#include "muse.h"
#include "wrappers.h"
#include "quantum.h"
#include "action.h"
#include "version.h"

// #ifdef TAP_DANCE_ENABLE
// #    include "tapdance.h"
// #endif  // TAP_DANCE_ENABLE

/* enum custom_keycodes { */

/* } */

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


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// define another set of tri layer state things for gaming layers, i think it would be really useful

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
