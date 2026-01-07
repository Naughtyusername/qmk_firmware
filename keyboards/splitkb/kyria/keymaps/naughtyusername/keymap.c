/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

// Kyria keymap ported from Mitosis layout
// Maintains Mitosis core layout with Kyria hardware features (RGB, OLED, encoders)

#include "keycodes.h"
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// clang-format off
// Layers - imported from Mitosis
enum kyria_layers {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST,
    _GAMING,
};

// Custom keycodes - imported from Mitosis
enum custom_keycodes {
  KC_COMPILE = SAFE_RANGE,
  KC_ASSIGN,
  KC_ARROP,
  KC_DCLN,
};

// Tap dance codes - DISABLED to save space
// enum tapdancers {
//   TD_Q_ESC,
// };

// Home row mods - GACS (GUI, Alt, Ctrl, Shift) - imported from Mitosis
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)

#define HM_J RSFT_T(KC_J)
#define HM_K RCTL_T(KC_K)
#define HM_L RALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

// Layer tap definitions - imported from Mitosis
#define LOW MO(_LOWER)
#define RAI MO(_RAISE)
// make space and enter work with mod time layer swapping
#define SP_RAI LT(_RAISE, KC_SPACE)
#define ENT_LOW LT(_LOWER, KC_ENTER)

// Kyria-specific aliases (keeping from original Kyria keymap for outer columns)
#define CTL_TAB MT(MOD_LCTL, KC_TAB)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)

// Tap Dance definitions - DISABLED to save space
// tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Q twice for Escape
//     [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
// };

/* Kyria Base layer (ported from Mitosis)
 *
 * MITOSIS LAYOUT PHILOSOPHY:
 * - Home row mods (GACS: GUI, Alt, Ctrl, Shift)
 * - Tap dance Q/ESC on Q key
 * - Space with layer tap to RAISE
 * - Enter with layer tap to LOWER
 * - Combo: J+K = Escape
 * - Key override: Shift+Backspace = Delete
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   | Q/ESC|   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Tab| A/GUI| S/ALT| D/CTL| F/SFT|   G  |                              |   H  | J/SFT| K/CTL| L/ALT|;/GUI |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  |  .   |  ,   |  /   | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |EncBtn|OS_CTL|  TAB |SPC/RA| BKSPC|  |  DEL |ENT/LO|OSL-FN| RALT |EncBtn|
 *                        |      |      |      | Raise|      |  | Lower|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * COMBOS: J+K = Escape (vim muscle memory!)
 * KEY OVERRIDES: Shift+Backspace = Delete
 * ENCODERS: Left = Volume control, Right = Page Up/Down
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT( /* Malt Layout with Home Row Mods (GACS) */
     KC_ESC  ,   KC_Q    , KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     CTL_TAB ,    HM_A    ,  HM_S   ,  HM_D  ,   HM_F ,   KC_G ,                                        KC_H,   HM_J ,  HM_K ,   HM_L ,HM_SCLN,CTL_QUOT,
     KC_LSFT ,    KC_Z    ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , _______, _______,     _______, _______, KC_N,   KC_M ,KC_DOT, KC_COMM,KC_SLSH, KC_RSFT,
                              KC_MUTE, OSM(MOD_LCTL), KC_TAB, SP_RAI, KC_BSPC,     KC_DEL, ENT_LOW, OSL(_FUNCTION), KC_RALT, KC_MUTE
  ),

/* Kyria Raise layer (ported from Mitosis) - combine with lower for tri-layer Adjust
 *
 * Symbols and programming operators optimized for Odin
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   %  |  $   |  -   |  |   |  [   |                              |   ]  |  +   |  #   |  <   |  >   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   !  |  *   |  =   |  &   |  (   |                              |   )  |  ^   |  _   |  "   |  ::  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |  ->  |  :=  |  {   |      |      |  |      |      |   }  |  @   |  .   |  ,   |  /   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |HOLDNG|      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

  [_RAISE] = LAYOUT(
    _______, KC_PERC, KC_DLR, KC_MINS, KC_PIPE, KC_LBRC,                                       KC_RBRC, KC_PLUS, KC_HASH, KC_LT,   KC_GT,   _______,
    _______, KC_EXLM, KC_ASTR, KC_EQL, KC_AMPR, KC_LPRN,                                       KC_RPRN, KC_CIRC, KC_UNDS, KC_DQT,  KC_DCLN, _______,
    _______, _______, _______, KC_ARROP, KC_ASSIGN, KC_LCBR, _______, _______,  _______, _______, KC_RCBR, KC_AT,  KC_DOT, KC_COMM, KC_SLSH, _______,
                                _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

/* Kyria Lower layer (ported from Mitosis) - combined with raise for tri-layer Adjust
 *
 * Numbers and media controls
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      | VOLUP|VOLDOWN MUTE |                              |  .   |  4   |  5   |  6   |  0   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      | Prev |Ply/Pau Next |      |      |  |      |      |      |  1   |  2   |  3   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |SPC/RA|      |      |      |  |HOLDNG|      |      |      |      |
 *                        |      | Raise|      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

  [_LOWER] = LAYOUT(
      _______,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______,
      _______, _______, _______, KC_VOLU, KC_VOLD, KC_MUTE,                                       KC_DOT,   KC_4,    KC_5,    KC_6,    KC_0, _______,
      _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,  _______, _______, _______,  KC_1,    KC_2,    KC_3, _______, _______,
                                 _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
  ),

/* Function layer (ported from Mitosis)
 *
 * Function keys and navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |PRTSC |                              | PGUP | HOME | END  |INSERT|      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              | LEFT | DOWN |  UP  | RIGHT|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      | PGDW |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      | HOLD |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

  [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, KC_PSCR,                                     KC_PGUP, KC_HOME, KC_END,  KC_INS,  _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, KC_PGDN, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

/* Adjust layer (ported from Mitosis) - System controls and settings
 *
 * Accessed by holding LOWER + RAISE
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | BASE |      |      |      |Compil|                              |MS_UP |MS_BT1|MS_BT2|MS_BT3| NKRO |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |MS_LFT|MS_DN |MS_UP |MS_RGT|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      | GAME |      |      |  |      |      |MS_DN |WH_DN |WH_UP |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |EE_CLR| BOOT |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

  [_ADJUST] = LAYOUT( /* System controls - accessed by holding LOWER + RAISE */
  _______, TG(_BASE), _______, _______, _______, KC_COMPILE,                                    MS_UP,   MS_BTN1, MS_BTN2, MS_BTN3, NK_TOGG, _______,
    _______, _______, _______, _______, _______, _______,                                       MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______, _______,
    _______, _______, _______, _______, _______, TG(_GAMING), _______, _______,  _______, _______, MS_DOWN, MS_WHLD, MS_WHLU, _______, _______, _______,
                                 _______, EE_CLR,  QK_BOOT, _______, _______,  _______, _______, _______, _______, _______
  ),

/* Gaming layer (ported from Mitosis) - No home row mods, standard layout
 *
 * For gaming where you need direct key access without mod-tap delays
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Tab|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |  ;   |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  | ESC  |  | FN   |  ] } |   N  |   M  |  ,   |  .   |  /   | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute | SPACE| BKSPC|  TAB |   1  |  | ENTER|  DEL |  FN  |TG_GAM|      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

  [_GAMING] = LAYOUT(
     KC_ESC  , KC_Q   ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,    KC_U ,  KC_I ,   KC_O ,   KC_P , KC_BSPC,
     CTL_TAB , KC_A   ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,    KC_J ,  KC_K ,   KC_L , KC_SCLN,CTL_QUOT,
     KC_LSFT , KC_Z   ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , _______, _______,     _______, _______, KC_N,    KC_M ,KC_COMM, KC_DOT,KC_SLSH, KC_RSFT,
                              KC_MUTE, KC_LCTL, KC_TAB, KC_SPC, KC_BSPC,     KC_DEL, KC_ENT, MO(_FUNCTION), TG(_GAMING), KC_MUTE
  ),

};

// Configure tapping term for home row mods - imported from Mitosis
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Pinkies get longer tapping term (weaker fingers)
        case HM_A:
        case HM_SCLN:
            return 185;
        // Other home row mods
        case HM_S:
        case HM_D:
        case HM_F:
        case HM_J:
        case HM_K:
        case HM_L:
            return 165;
        default:
            return TAPPING_TERM;
    }
}

// Combos - J+K = Escape (vim classic!) - imported from Mitosis
const uint16_t PROGMEM jk_combo[] = {HM_J, HM_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(jk_combo, KC_ESC),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

// Key overrides - DISABLED to save space
// const key_override_t shift_bspc_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
//
// // Add all overrides to array
// const key_override_t *key_overrides[] = {
//     &shift_bspc_override,
// };

// Flow tap customizing - imported from Mitosis
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

// Flow tap term configuration - imported from Mitosis
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        return FLOW_TAP_TERM;
    }
    return 0;
}

// Process record user input function - imported from Mitosis
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_COMPILE:
                // Updated for Kyria compilation
                SEND_STRING("qmk compile -kb splitkb/kyria/rev1 -km naughtyusername" SS_TAP(X_ENTER));
                return false; // Stop normal key processing
            case KC_ASSIGN:
                // Assignment operator for Odin (:=)
                tap_code16(KC_COLON);
                tap_code16(KC_EQUAL);
                return false;
            case KC_ARROP:
                // Arrow operator for Odin/C (->)
                tap_code(KC_MINS);
                tap_code16(KC_GT);
                return false;
            case KC_DCLN:
                // Double colon for Odin (::)
                tap_code16(KC_COLON);
                tap_code16(KC_COLON);
                return false;
        }
    }
    return true; // Continue with normal key processing
}

// Layer state checking - merged Mitosis tri-layer with Kyria RGB
layer_state_t layer_state_set_user(layer_state_t state) {
    // RGB layer indication - using Mitosis color scheme
    switch (get_highest_layer(state)) {
        case _BASE:
            rgblight_sethsv_noeeprom(HSV_BLUE); // Blue for base (matches Mitosis)
            break;
        case _LOWER:
            rgblight_sethsv_noeeprom(HSV_RED); // Red for lower (matches Mitosis)
            break;
        case _RAISE:
            rgblight_sethsv_noeeprom(HSV_WHITE); // White for raise (matches Mitosis)
            break;
        case _FUNCTION:
            rgblight_sethsv_noeeprom(HSV_YELLOW); // Yellow for function
            break;
        case _ADJUST:
            rgblight_sethsv_noeeprom(HSV_GREEN); // Green for adjust (matches Mitosis)
            break;
        case _GAMING:
            rgblight_sethsv_noeeprom(HSV_PURPLE); // Purple for gaming
            break;
        default:
            rgblight_sethsv_noeeprom(HSV_WHITE); // White for default
            break;
    }

    // Update tri-layer state (LOWER + RAISE = ADJUST) - from Mitosis
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

    return state;
}

// OLED code - Kyria specific, updated with Mitosis layer names
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status - updated with Mitosis layer names
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case _BASE:
                oled_write_P(PSTR("Base\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("Lower\n"), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("Raise\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            case _GAMING:
                oled_write_P(PSTR("Gaming\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}

// Rotary encoder code - Kyria specific
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control on left encoder
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down on right encoder
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}

// clang-format off
/********************************************************************************************
 * KYRIA BLANK TEMPLATE FOR FUTURE LAYERS
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'

  [_BLANK] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

*/
