#include "encoders.h"

void encoder_update_user(uint8_t index, bool clockwise) {
  // Left encoder
  if (index == 0) {
    switch(biton32(layer_state)) {
    case _BASE:
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
      break;
    case _LOWER:
    case _RAISE:
    case _ADJUST:
    case _VIKEYS:
    case _GAMING:
    case _ROGUE:
    default: break;
    }
  }
  // Right encoder
  if (index == 1) {
    switch(biton32(layer_state)) {
    case _BASE:
      if (clockwise) {
        tap_code(KC_PGDN);
      } else {
        tap_code(KC_PGUP);
      }
      break;
    case _LOWER:
    case _RAISE:
    case _ADJUST:
    case _VIKEYS:
    case _GAMING:
    case _ROGUE:
    default: break;
    }

  }
}
