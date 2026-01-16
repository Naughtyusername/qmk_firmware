// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "keycodes.h"
#include "mitosis.h"
#include "quantum.h"
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// clang-format off
// Layers
enum mitosis_layers {
	_BASE = 0,
	_LOWER,
	_RAISE,
    _FUNCTION,
	_ADJUST,
    _GAMING,
};

// Custom keycodes
enum custom_keycodes {
  KC_COMPILE = SAFE_RANGE,
  KC_ASSIGN,
  KC_ARROP,
  KC_DCLN,
  KC_RANGE,
  KC_HMDR,
};

// Tap dance codes
enum tapdancers {
  TD_Q_ESC,
};

// Home row mods - GACS (GUI, Alt, Ctrl, Shift)
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)

#define HM_J RSFT_T(KC_J)
#define HM_K RCTL_T(KC_K)
#define HM_L RALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

// custom ones above is defaults other than renaming
#define LOW MO(_LOWER)
#define RAI MO(_RAISE)
// make space and enter work with mod time layer swapping
#define SP_RAI LT(RAI, KC_SPACE)
#define SP_LOW LT(LOW, KC_SPACE) // this is so we can hit space with the other thumb when on Raise - Symbol layer
#define ENT_LOW LT(LOW, KC_ENTER)

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q twice for Escape
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

/* Mitosis Base layer
 * LEFT SIDE                                       RIGHT SIDE
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |Esc / Q|   W   |   E   |   R   |   T   |       |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * | A/GUI | S/ALT | D/CTL | F/SFT |   G   |       |   H   | J/SFT | K/CTL | L/ALT | ;/GUI |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   |       |   N   |   M   |   ,   |   .   |   /   |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'

 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * |OS_SHFT|OS_CTRL|OS_ALT |  TAB  |               |CAPSWRD|OSL(FN)|OSL(AJ)|       |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * |  ESC  | CTRL  | Bkspc |SPC/RAI|               |ENT/LOW|   '   |   "   |       |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 *
 * COMBOS: J+K = Escape
 * KEY OVERRIDES: Shift+Backspace = Delete
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT( /* Malt Layout with Home Row Mods (GACS) */
TD(TD_Q_ESC), KC_W,     KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,
    HM_A,     HM_S,     HM_D,    HM_F,    KC_G,                 KC_H,    HM_J,    HM_K,    HM_L,       HM_SCLN,
    KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,                 KC_N,    KC_M,    KC_COMM,  KC_DOT,    KC_SLSH,

         OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), KC_TAB,        CW_TOGG,  OSL(_FUNCTION), OSL(_ADJUST), _______,
                      KC_ESC, KC_LCTL, KC_BSPC, SP_RAI,                           ENT_LOW,  KC_QUOT, KC_DQT,  _______
  ),

/* Mitosis Raise layer - combine with lower for tri-layer Adjust
   // TODO update the layer to match the chart

 * LEFT SIDE                                       RIGHT SIDE
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |   \   |   $   |   |   |   -   |   [   |       |   ]   |   +   |   #   |   ;   |   ::  |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   ~   |   &   |   *   |   =   |   (   |       |   )   |   ^   |   _   |   %   |   :   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |  ..=  |   !   |   '   |   "   |   {   |       |   }   |   @   |   <   |   >   |   ?   |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * |       |       |  ~/.  |   `   |               |  ->   |  :=   |   /   |  ../  |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * |       |       |BCKSPC |HOLDING|               |LOW/ADJ|  <<   |  >>   |       |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 */

  [_RAISE] = LAYOUT(

    KC_BSLS, KC_DLR, KC_PIPE, KC_MINS, KC_LBRC,       KC_RBRC, KC_PLUS, KC_HASH, KC_SCLN, KC_DCLN,
    KC_TILD, KC_AMPR, KC_ASTR, KC_EQL, KC_LPRN,       KC_RPRN, KC_CIRC, KC_UNDS, KC_PERC, KC_COLN,
    KC_RANGE, KC_EXLM, KC_QUOT, KC_DQT, KC_LCBR,   KC_RCBR, KC_AT, KC_LT, KC_GT, KC_QUES,

                    _______, _______, KC_HMDR, KC_GRV,       KC_ARROP, KC_ASSIGN, KC_SLSH, _______,
         _______, _______, _______, _______,      SP_LOW, _______, _______, _______
    ),

/* Mitosis Lower layer - combined with raise for tri-layer Adjust
 *
 * LEFT SIDE                                       RIGHT SIDE
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |   1   |   2   |   3   |   4   |   5   |       |   6   |   7   |   8   |   9   |   0   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |       |       | VOLUP |VOLDOWN| MUTE  |       |   .   |   4   |   5   |   6   |   0   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |       |       | Prev  |Ply/Pau| Next  |       |       |   1   |   2   |   3   |       |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * |       |       |       |       |               |       |       |       |       |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * |       |       |       |       |               |       |       |       |       |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 */

  [_LOWER] = LAYOUT(

      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,   KC_7,    KC_8,    KC_9, KC_0,
    _______, _______, KC_VOLU, KC_VOLD, KC_MUTE,       KC_DOT, KC_4,    KC_5,    KC_6, KC_0,
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT,       _______, KC_1,    KC_2,    KC_3, _______,

             _______, _______, _______, _______,       _______, _______, _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______
  ),

/* Funtion layer

 * LEFT SIDE                                       RIGHT SIDE
 * Main Grid                                       Main Grid
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |   F9  |   F10 |  F11  |  F12  | PRTSC |       | PGUP  | HOME  | END   | INSERT|       |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   F5  |  F6   |   F7  |  F8   |       |       | LEFT  | DOWN  | UP    | RIGHT |       |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   F1  |  F2   |   F3  |  F4   |       |       | PGDW  |       |       |       |       |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * |       |       |       |       |               |       | BASE |       |       |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * |       |       |       |       |               |       |       |       |       |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
*/

  [_FUNCTION] = LAYOUT(
    KC_F9,   KC_F10, KC_F11, KC_F12, KC_PSCR,       KC_PGUP, KC_HOME, KC_END , KC_INS, _______,
    KC_F5,   KC_F6,  KC_F7,  KC_F8,  _______,       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
    KC_F1,   KC_F2,  KC_F3,  KC_F4,  _______,       KC_PGDN, _______, _______, _______, _______,

             _______, _______, _______, _______,       _______, TO(_BASE), _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______
  ),

/* Adjust layer - System controls and settings
 *
 * LEFT SIDE                                       RIGHT SIDE
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |  BASE | GAME  |       |       |       |       |MS_UP  |MS_BTN1|MS_BTN2|MS_BTN3| NKRO  |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |MS_LEFT|MS_DOWN|MS_UP  |MS_RGHT|       |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |MS_DOWN|WH_DOWN|WH_UP  |       |       |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * |       |       |       |       |               |       |       |       |       |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * |EE_CLR | BOOT  |       |       |               |       |       |       |       |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 */

  [_ADJUST] = LAYOUT( /* System controls - accessed by holding LOWER + RAISE */
  TG(_BASE), TG(_GAMING), _______, _______, _______,       MS_UP,   MS_BTN1, MS_BTN2, MS_BTN3, NK_TOGG,
    _______, _______, _______, _______, _______,          MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______,
    _______, _______, _______, _______, _______,      MS_DOWN, MS_WHLD, MS_WHLU, _______, _______,

             _______, _______, _______, _______,       _______, _______, _______, _______,
             EE_CLR,  QK_BOOT, _______, _______,       _______, _______, _______, _______
  ),

/* Gaming layer - No home row mods, standard layout
 *
 * LEFT SIDE                                       RIGHT SIDE
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |   Q   |   W   |   E   |   R   |   T   |       |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   A   |   S   |   D   |   F   |   G   |       |   H   |   J   |   K   |   L   |   ;   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   |       |   N   |   M   |   ,   |   .   |   /   |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * | SHIFT |  ESC  |  TAB  |   1   |               |   2   |   3   |   4   |   5   |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * | CTRL  |  ALT  | BKSPC | SPACE |               |  RET  |  DEL  |  FN   | BASE  |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 */

  [_GAMING] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,

             KC_LSFT, KC_ESC,  KC_TAB,  KC_1,                 KC_2, KC_3, KC_4, KC_5,
             KC_LCTL, KC_LALT, KC_BSPC,  KC_SPC,              KC_ENT,  KC_DEL,  MO(_FUNCTION), TG(_BASE)
  ),

};

// Configure tapping term for home row mods
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

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                      uint16_t other_keycode, keyrecord_t *other_record) {

    switch (tap_hold_keycode) {
        // This "unlocks" your Space/Raise key so it works even on the same hand
        case SP_RAI:
        case ENT_LOW:
            return true;
    }
    // Change this line to only pass the records:
    return get_chordal_hold_default(tap_hold_record, other_record);
}

// Combos - J+K = Escape (vim classic!)
const uint16_t PROGMEM jk_combo[] = {HM_J, HM_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(jk_combo, KC_ESC),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

// Key overrides - Shift+Backspace = Delete
const key_override_t shift_bspc_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// Add all overrides to array
const key_override_t *key_overrides[] = {
    &shift_bspc_override,
};

// flow tap customizing, will probably need refinment
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // case KC_SPC:  // Exclude space from flow tap - we want chordal hold but not flow tap timing
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

// example code - this function takes precidence over flow_tap_key also
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        return FLOW_TAP_TERM;
    }
    return 0;
}

/*****************************************************************************/
/* uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,         */
/*                            uint16_t prev_keycode) {                       */
/*     if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {      */
/*         switch (keycode) {                                                */
/*             case LCTL_T(KC_F):                                            */
/*             case RCTL_T(KC_H):                                            */
/*               return FLOW_TAP_TERM - 25;  // Short timeout on these keys. */
/*                                                                           */
/*             default:                                                      */
/*               return FLOW_TAP_TERM;  // Longer timeout otherwise.         */
/*         }                                                                 */
/*     }                                                                     */
/*     return 0;  // Disable Flow Tap.                                       */
/* }                                                                         */
/*****************************************************************************/

// process record user input function
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {

            case KC_COMPILE:
                // This sends "qmk compile" followed by the Enter key.
                // Ensure you are in the correct QMK firmware directory in your terminal.
                SEND_STRING("qmk compile -kb mitosis -km naughtyusername" SS_TAP(X_ENTER));
                return false; // Stop normal key processing
          // TODO this can be removed, add in the email one maybe tho. build script kinda solves this

            case KC_ASSIGN:
              // these have to be tap_code16 for correct types, non shifted keys dont need the 16
                tap_code16(KC_COLON);
                tap_code16(KC_EQUAL);
                return false; // Skip default handling

          // arrow operator for odin/C
          case KC_ARROP:
          tap_code(KC_MINS);
          tap_code16(KC_GT);
          return false;

          // double colon
          case KC_DCLN:
          tap_code16(KC_COLON);
          tap_code16(KC_COLON);
          return false;

          // Odin range operator
          case KC_RANGE:
                SEND_STRING("..=");
          return false;

          // Home Dir
          case KC_HMDR:
                SEND_STRING("~/");
          return false;
        }
    }
    return true; // Continue with normal key processing
}

// update tri-layer state
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(
                                   state,
                                   _LOWER,
                                   _RAISE,
                                   _ADJUST
                                   );

    return state;
}
// clang-format on
// This should change the LED color on the receiver piece when we swap layers since the mitosis doesnt have built in
// RGB's this is nice to have to have a visual indicator for inital debugging
void matrix_scan_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case _BASE:
            set_led_blue;
            break;
        case _RAISE:
            set_led_yellow;
            break;
        case _LOWER:
            set_led_cyan;
            break;
        case _ADJUST:
            set_led_green;
            break;
        case _FUNCTION:
            set_led_magenta;
            break;
        case _GAMING:
            set_led_white;
            break;
        default:
            break;
    }
};

// clang-format off
/********************************************************************************************
 * Mitosis BLANK TEMPLATES FOR WHEN WE ADD MORE
 *
 * LEFT SIDE                                       RIGHT SIDE
 * Main Grid                                       Main Grid
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * |       |       |       |       |               |       |       |       |       |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * |       |       |       |       |               |       |       |       |       |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'


  [_BLANK] = LAYOUT(
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______
  )

*/


/*****************************************************************/
/* #define set_led_off     red_led_off; grn_led_off; blu_led_off */
/* #define set_led_red     red_led_on;  grn_led_off; blu_led_off */
/* #define set_led_blue    red_led_off; grn_led_off; blu_led_on  */
/* #define set_led_green   red_led_off; grn_led_on;  blu_led_off */
/* #define set_led_yellow  red_led_on;  grn_led_on;  blu_led_off */
/* #define set_led_magenta red_led_on;  grn_led_off; blu_led_on  */
/* #define set_led_cyan    red_led_off; grn_led_on;  blu_led_on  */
/* #define set_led_white   red_led_on;  grn_led_on;  blu_led_on  */
/*****************************************************************/
