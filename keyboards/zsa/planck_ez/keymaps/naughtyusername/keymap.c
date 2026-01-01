#include "quantum_keycodes.h"
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

#include QMK_KEYBOARD_H

// clang-format off
// Define layer names for easier reading
enum {
    _BASE = SAFE_RANGE,
    _LOWER,
    _UPPER,
    _ADJUST
};

/* * This function handles the "Tri-Layer" logic.
 * When both LOWER and UPPER are pressed, ADJUST is activated.
 */
layer_state_t
layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _UPPER, _ADJUST);
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* 0: BASE LAYER (QWERTY)
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │  TAB   │   Q    │   W    │   E    │   R    │   T    │   Y    │   U    │   I    │   O    │   P    │  BSPC  │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  ESC   │   A    │   S    │   D    │   F    │   G    │   H    │   J    │   K    │   L    │   ;    │   '    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  LSFT  │   Z    │   X    │   C    │   V    │   B    │   N    │   M    │   ,    │   .    │   /    │  ENT   │
     * ├────────┼────────┼────────┼────────┼────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤
     * │ CapsW  │  LCTL  │  LALT  │  LGUI  │         SPACE            │  UPPR  │  LEFT  │  DOWN  │   UP   │  RGHT  │
     * └────────┴────────┴────────┴────────┴──────────────────────────┴────────┴────────┴────────┴────────┴────────┘
     */
[_BASE] = LAYOUT_planck_1x2uC(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    CW_TOGG, KC_LCTL, KC_LALT, KC_LGUI, TL_LOWR,      KC_SPC,      TL_UPPR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

    /* 1: LOWER (Symbols & F-Keys)
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   ~    │   !    │   @    │   #    │   $    │   %    │   ^    │   &    │   *    │   (    │   )    │  BSPC  │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  DEL   │   F1   │   F2   │   F3   │   F4   │   F5   │   F6   │   _    │   +    │   {    │   }    │   |    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  TRNS  │   F7   │   F8   │   F9   │  F10   │  F11   │  F12   │ S(#)   │ S(\)   │  HOME  │  END   │  TRNS  │
     * ├────────┼────────┼────────┼────────┼────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤
     * │  TRNS  │  TRNS  │  TRNS  │  TRNS  │         TRNS             │  TRNS  │  NEXT  │  VOL-  │  VOL+  │  PLAY  │
     * └────────┴────────┴────────┴────────┴──────────────────────────┴────────┴────────┴────────┴────────┴────────┘
     */

[_LOWER] = LAYOUT_planck_1x2uC(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

    /* 2: UPPER (Numbers & Navigation)
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │   `    │   1    │   2    │   3    │   4    │   5    │   6    │   7    │   8    │   9    │   0    │  BSPC  │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  DEL   │   F1   │   F2   │   F3   │   F4   │   F5   │   F6   │   -    │   =    │   [    │   ]    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  TRNS  │   F7   │   F8   │   F9   │  F10   │  F11   │  F12   │  NUHS  │  NUBS  │  PGUP  │  PGDN  │  TRNS  │
     * ├────────┼────────┼────────┼────────┼────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤
     * │  TRNS  │  TRNS  │  TRNS  │  TRNS  │         TRNS             │  TRNS  │  NEXT  │  VOL-  │  VOL+  │  PLAY  │
     * └────────┴────────┴────────┴────────┴──────────────────────────┴────────┴────────┴────────┴────────┴────────┘
     */
[_UPPER] = LAYOUT_planck_1x2uC(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

    /* 3: ADJUST (System, RGB & Audio)
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │  TRNS  │ BOOTL  │ DEBUG  │ RGB_TG │ RGB_NX │ HUE_UP │ HUE_DN │ SAT_UP │ SAT_DN │ VAL_UP │ VAL_DN │  DEL   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  TRNS  │  TRNS  │ MU_NX  │ AU_ON  │ AU_OFF │ AG_NRM │ AG_SWP │  TRNS  │  TRNS  │  TRNS  │  TRNS  │  TRNS  │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  TRNS  │ AU_PR  │ AU_NX  │ MU_ON  │ MU_OFF │ MI_ON  │ MI_OFF │  TRNS  │  TRNS  │  TRNS  │  TRNS  │  TRNS  │
     * ├────────┼────────┼────────┼────────┼────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤
     * │  TRNS  │  TRNS  │  TRNS  │  TRNS  │         TRNS             │  TRNS  │  TRNS  │  TRNS  │  TRNS  │  TRNS  │
     * └────────┴────────┴────────┴────────┴──────────────────────────┴────────┴────────┴────────┴────────┴────────┘
     */
[_ADJUST] = LAYOUT_planck_1x2uC(
    KC_TRNS, QK_BOOT, DB_TOGG, RM_TOGG, RM_NEXT, RM_HUEU, RM_HUED, RM_SATU, RM_SATD, RM_VALU, RM_VALD, KC_DEL,
    KC_TRNS, KC_TRNS, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)

};
