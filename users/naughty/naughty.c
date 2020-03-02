#include "naughty.h"

// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps
__attribute__((weak)) void matrix_init_keymap(void) {}
// Call user matrix init, then call the keymap's init function
void matrix_init_user(void) {
    matrix_init_keymap();
    rgblight_enable();
}

__attribute__((weak)) void matrix_scan_keymap(void) {}
// No global matrix scan code, so just run keymap's matix
// scan function
void matrix_scan_user(void) { matrix_scan_keymap(); }

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions tor my global custom keycodes. Defined in drashna.h file
// Then runs the _keymap's recod handier if not processed here,
// And use "NEWPLACEHOLDER" for new safe range
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {}
    return process_record_keymap(keycode, record);
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }
layer_state_t                       layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);

    switch (get_highest_layer(state)) {
        case _RAISE:
            rgblight_sethsv(HSV_CORAL);
            break;
        case _LOWER:
            rgblight_sethsv(HSV_SPRINGGREEN);
            break;
        case _ADJUST:
            rgblight_sethsv(HSV_RED);
            break;
        case _BASE:
            rgblight_sethsv(HSV_PURPLE);
            break;
        case _VIKEYS:
            rgblight_sethsv(HSV_BLUE);
            break;
        case _NAV:
            rgblight_sethsv(HSV_TEAL);
            break;
        case _GAMING:
            rgblight_sethsv(HSV_ORANGE);
            break;
        case _ROGUE:
            rgblight_sethsv(HSV_CHARTREUSE);
            break;
        case _NUMPAD:
            rgblight_sethsv(HSV_CYAN);
            break;
        default:
            rgblight_sethsv(HSV_CHARTREUSE);
            break;
    }

    return layer_state_set_keymap(state);
    /* return state; */
}
__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}

void led_set_user(uint8_t usb_led) { led_set_keymap(usb_led); }

__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) { suspend_power_down_keymap(); }

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

void suspend_wakeup_init_user(void) {}

__attribute__((weak)) void startup_keymap(void) {}

void startup_user(void) {}

__attribute__((weak)) void shutdown_keymap(void) {}

void shutdown_user(void) { shutdown_keymap(); }
