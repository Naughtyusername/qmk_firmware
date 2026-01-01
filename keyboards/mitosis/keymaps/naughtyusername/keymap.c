// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "keycodes.h"
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
    _MODHMRW // Home row with modifiers - currently a copy paste of the base layer just for testing again
};

// Custom keycodes
enum custom_keycodes {
  KC_COMPILE, // Use SAFE_RANGE for custom codes
  KC_ASSIGN,
  KC_ARROP,
  KC_DCLN,
};

// Tap dance codes
enum tapdancers {
  TD_Q_ESC,
  TD_A_TAB,
};

enum homerowmods {
    SupA,
    SupScln,
    AltS,
    AltL,
    CtlD,
    CtlK,
};

// custom ones above is defaults other than renaming
#define LOW MO(_LOWER)
#define RAI MO(_RAISE)
// make space and enter work with mod time layer swapping
#define SP_RAI LT(RAI, KC_SPACE)
#define ENT_LOW LT(LOW, KC_ENTER)

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q twice for Escape
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
};

/* Mitosis Base layer
 * i think due to the limited keys we might use my old homerow mirroed
 * Alt, Shift, Ctrl, Super layouts, the forward thumb keys are to important for base things and the other ones are too far off
 * LEFT SIDE                                       RIGHT SIDE
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |Esc / Q|   W   |   E   |   R   |   T   |       |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |TAB / A|   S   |   D   |   F   |   G   |       |   H   |   J   |   K   |   L   |   ;   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   |       |   N   |   M   |   ,   |   .   |   /   |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * |       |       |       |CapsWrd|               |       |       |       |       |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * | ESC   |       |SPC/RAI| Bkspc |               | Del   |ENT/LOW| RCTRL | FUNCT |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT( /* Malt Layout, customised for reduced columns (ex: quote and shift locations) */
TD(TD_Q_ESC), KC_W, KC_E, KC_R, KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
TD(TD_A_TAB), KC_S, KC_D, KC_F, KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,     KC_X, KC_C, KC_V, KC_B,                 KC_N,    KC_M,    KC_DOT,  KC_COMM, KC_SLSH,

         _______, _______, _______, CW_TOGG,        _______,  _______, _______, _______,
         KC_ESC,  KC_LCTL, SP_RAI,  KC_BSPC,        KC_DEL,  ENT_LOW ,  KC_RCTL, _______
  ),

/* Mitosis Raise layer - combine with lower for tri-layer Adjust

 * LEFT SIDE                                       RIGHT SIDE
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |   %   |   $   |   -   |   |   |   [   |       |   ]   |   +   |   #   |   <   |   >   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   !   |   *   |   =   |   &   |   (   |       |   )   |   ^   |   _   |   "   |  ::   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |       |       |   ->  |   :=  |   {   |       |   }   |   @   |   ,   |   .   |   /   |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * |       |       |       |       |               |       |       |       |       |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * |       |       |HOLDING|       |               | Space |LOW/ADJ|       |       |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 */

  [_RAISE] = LAYOUT(

    KC_PERC, KC_DLR, KC_MINS, KC_PIPE, KC_LBRC,       KC_RBRC, KC_PLUS, KC_HASH, KC_LT, KC_GT,
    KC_EXLM, KC_ASTR, KC_EQL, KC_AMPR, KC_LPRN,       KC_RPRN, KC_CIRC, KC_UNDS, KC_DQT, KC_DCLN,
    _______, _______, KC_ARROP, KC_ASSIGN, KC_LCBR,       KC_RCBR, KC_AT, _______, _______, _______,

             _______, _______, _______, _______,       _______, _______, _______, _______,
             _______, _______, _______, _______,       KC_SPC, _______, _______, _______
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
 * |       |       |       |       |               | Delete|       |       |       |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * |       |       |SPC/RAI|       |               | Enter |HOLDING|       |       |
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
 * |   F9  |   F10 |  F11  |  F12  |       |       | PGUP  | HOME  | END   | INSERT|       |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   F5  |  F6   |   F7  |  F8   |       |       | LEFT  | DOWN  | UP    | RIGHT |       |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   F1  |  F2   |   F3  |  F4   |       |       | PGDW  |       |       |       |       |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * |       |       |       |       |               |       |       |       |       |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * |       |       |       |       |               |       |       |       |       |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
*/

  [_FUNCTION] = LAYOUT(
    KC_F9, KC_F10, KC_F11, KC_F12, _______,       KC_PGUP, KC_HOME, KC_END , KC_INS, _______,
       KC_F5, KC_F6, KC_F7, KC_F8, _______,       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
       KC_F1, KC_F2, KC_F3, KC_F4, _______,       KC_PGDN, _______, _______, _______, _______,

             _______, _______, _______, _______,       _______, _______, _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______
  ),

/* Adjust layer
 *
 * LEFT SIDE                                       RIGHT SIDE
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |  BASE |       |       |       |Compile|       |       |       |       |       |       |
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
 * |FLASH  |       |       |       |               |       |       |       |       |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 */

  [_ADJUST] = LAYOUT( /* Function Shifted Layer, secondary alternative layer with closing brackets,
                                                    and F-keys under their numpad equivalents*/
  TG(_BASE), _______, _______, _______, KC_COMPILE,       _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,

             _______, _______, _______, _______,       _______, _______, _______, _______,
             QK_BOOT, _______, _______, _______,       _______, _______, _______, _______
  ),

};

// flow tap customizing, will probably need refinment
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

// clang-format off
// process record user input function
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_COMPILE:
                // This sends "qmk compile" followed by the Enter key.
                // Ensure you are in the correct QMK firmware directory in your terminal.
                SEND_STRING("qmk compile -kb mitosis -km naughtyusername" SS_TAP(X_ENTER));
                return false; // Stop normal key processing
            case KC_ASSIGN:
              // these have to be tap_code16 for correct types, non shifted keys dont need the 16 typedef
                // Type ':'
                tap_code16(KC_COLON);
                // Type '='
                tap_code16(KC_EQUAL);
                return false; // Skip default handling
          case KC_ARROP:
          // arrow operator for odin/C
          tap_code(KC_MINS);
          tap_code16(KC_GT);
          return false;
          // double colon
          case KC_DCLN:
          tap_code16(KC_COLON);
          tap_code16(KC_COLON);
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

// This should change the LED color on the receiver piece when we swap layers since the mitosis doesnt have built in
// RGB's this is nice to have to have a visual indicator for inital debugging
void matrix_scan_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case _BASE:
            set_led_blue;
            break;
        case _RAISE:
            set_led_white;
            break;
        case _LOWER:
            set_led_red;
            break;
        case _ADJUST:
            set_led_green;
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
