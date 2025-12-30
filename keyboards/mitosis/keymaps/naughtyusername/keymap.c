// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// clang-format off
enum mitosis_layers {
	_BASE = 0,
	_LOWER,
	_RAISE,
	_ADJUST,
    _MODHMRW // Home row with modifiers - currently a copy paste of the base layer just for testing again
};

enum tapdancers {
  TD_Q_ESC,
};


#define LONGPRESS_DELAY 150
#define LAYER_TOGGLE_DELAY 300

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
};

/* Mitosis Base layer
 * i think due to the limited keys we might use my old homerow mirroed
 * Alt, Shift, Ctrl, Super layouts, the forward thumb keys are to important for base things and the other ones are too far off
 * LEFT SIDE                                       RIGHT SIDE
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |Esc / Q|   W   |   E   |   R   |   T   |       |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   A   |   S   |   D   |   F   |   G   |       |   H   |   J   |   K   |   L   |   ;   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   |       |   N   |   M   |   ,   |   .   |   /   |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * | LALT  | LSHFT | LGUI  | Bkspc |               |  Del  | RGUI  | RSHFT | RALT  |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * | ESC   | LCTRL | SPRAI | Space |               | Enter |ENTLOW | RCTRL | TAB   |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT( /* Malt Layout, customised for reduced columns (ex: quote and shift locations) */
TD(TD_Q_ESC),KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_DOT,  KC_COMM, KC_SLSH,
             KC_LALT, KC_LSFT, KC_LGUI, KC_BSPC,        KC_DEL,  KC_RGUI, KC_RSFT, KC_RALT,
             KC_ESC, KC_LCTL,  SP_RAI,     KC_SPC,         KC_ENT,  ENT_LOW ,  KC_RCTL, KC_TAB
  ),

/* Mitosis Lower layer - combined with raise for tri-layer Adjust
 *
 * LEFT SIDE                                       RIGHT SIDE
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |   1   |   2   |   3   |   4   |   5   |       |   6   |   7   |   8   |   9   |   0   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   !   |   @   |   #   |   $   |   %   |       |   ^   |   &   |   *   |   `   |   \   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |       |   <   |   {   |   [   |   (   |       |   )   |   ]   |   }   |   >   |       |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * |       |       |       |   -   |               | Delete|       |       |       |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * |       |       | RAISE | SPC   |RAI = ADJ Here | Enter |LowerH |       |       |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 */

  [_LOWER] = LAYOUT(

     KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,        KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,
    KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV, KC_BSLS,
    _______, KC_LT  , KC_LCBR, KC_LBRC, KC_LPRN,       KC_RPRN, KC_RBRC, KC_RCBR, KC_GT, _______,
             _______, _______, _______, KC_MINS,       _______, _______, _______, _______,
             _______, _______,   RAI  , KC_SPC ,       _______, _______, _______, _______
  ),

/* Mitosis Raise layer - combine with lower for tri-layer Adjust

 * LEFT SIDE                                       RIGHT SIDE
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
 */

  [_RAISE] = LAYOUT(

    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______
    ),

/* Mitosis This is for the Adjust layer
 *
 * LEFT SIDE                                       RIGHT SIDE
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
 */

  [_ADJUST] = LAYOUT( /* Function Shifted Layer, secondary alternative layer with closing brackets,
                                                    and F-keys under their numpad equivalents*/
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______,
             QK_BOOT, _______, _______, _______,       _______, _______, _______, _______
  )

};

/* Mitosis Mod keys on homerow layer, wanna test this again, i know i loved it.
   we need to test chording with this, this time, it seems perfecte even tho in the past
   it was close enough to perfect for me

 * LEFT SIDE                                       RIGHT SIDE
 * ,-------.-------.-------.-------.-------.       ,-------.-------.-------.-------.-------.
 * |Esc / Q|   W   |   E   |   R   |   T   |       |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |SHIFT A|ALT S  |CTRL D |GUI F  |   G   |       |GUI H  |CTRL J |ALT K  |SHIFT L|   ;   |
 * |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   |       |   N   |   M   |   ,   |   .   |   /   |
 * `-------'-------'-------'-------'-------'       `-------'-------'-------'-------'-------'
 *
 * Left Thumb Cluster                              Right Thumb Cluster
 * ,-------.-------.-------.-------.               ,-------.-------.-------.-------.
 * | LALT  | LSHFT | LGUI  | Bkspc |               |  Del  | RGUI  | RSHFT | RALT  |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * | ESC   | LCTRL | SPRAI | Space |               | Enter |ENTLOW | RCTRL | TAB   |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 */

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // do things
    return 0;
};

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
 */

/*
  Blank keymap template

    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______

********************************************************************************************
*/
