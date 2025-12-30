// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// clang-format off
enum mitosis_layers
{
	_BASE,
	_LOWER,
	_RAISE,
	_ADJUST
};

enum mitosis_keycodes
{
  FNKEY = SAFE_RANGE,
  SHIFT,
  M_VOLU,
  M_VOLD,
  M_ESCM
};

#define LONGPRESS_DELAY 150
#define LAYER_TOGGLE_DELAY 300

// custom ones above is defaults other than renaming
#define LOW MO(_LOWER)
#define RAI MO(_RAISE)

/* Mitosis Base layer
   i think due to the limited keys we might use my old homerow mirroed
   Alt, Shift, Ctrl, Super layouts, the forward thumb keys are to important for base things and the other ones are too far off

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
 * | LALT  | LSHFT | LGUI  | Bkspc |               |  Del  | RGUI  | RSHFT | RALT  |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * | ESC   | LCTRL | Raise | Space |               | Enter | Lower | RCTRL | TAB   |
 * `-------'-------'-------'-------'               `-------'-------'-------'-------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT( /* Malt Layout, customised for reduced columns (ex: quote and shift locations) */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_DOT,  KC_COMM, KC_SLSH,
             KC_LALT, KC_LSFT, KC_LGUI, KC_BSPC,        KC_DEL,  KC_RGUI, KC_RSFT, KC_RALT,
             KC_ESC, KC_LCTL,  RAI,     KC_SPC,         KC_ENT,     LOW ,  KC_RCTL, KC_TAB
  ),

/* Mitosis Lower layer - combined with raise for tri-layer Adjust

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
 * |       |       |       |   -   |               |       |       |       |       |
 * |-------+-------+-------+-------|     [RX]      |-------+-------+-------+-------|
 * |       |       | RAISE | SPC   |RAI = ADJ Here |       |LowerH |       |       |
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
             _______, _______, _______, _______,       _______, _______, _______, _______
  )

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

// clang-format on
static uint16_t key_timer;

static bool singular_key = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t layer;
    layer = get_highest_layer(layer_state); // get the current layer

    // custom layer handling for tri_layer,
    switch (keycode) {
        case FNKEY:
            if (record->event.pressed) {
                key_timer    = timer_read();
                singular_key = true;
                layer_on(_RAISE);
            } else {
                if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY || !singular_key) {
                    layer_off(_RAISE);
                }
            }
            update_tri_layer(_RAISE, _LOWER, _ADJUST);
            return false;
            break;
        // SHIFT is handled as LSHIFT in the general case
        case SHIFT:
            if (record->event.pressed) {
                key_timer    = timer_read();
                singular_key = true;
                layer_on(_LOWER);
                register_code(KC_LSFT);
            } else {
                if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY || !singular_key) {
                    layer_off(_LOWER);
                    unregister_code(KC_LSFT);
                }
            }
            update_tri_layer(_RAISE, _LOWER, _ADJUST);
            return false;
            break;
        // switch multiplexing for media, short tap for volume up, long press for play/pause
        case M_VOLU:
            if (record->event.pressed) {
                key_timer = timer_read();                         // if the key is being pressed, we start the timer.
            } else {                                              // this means the key was just released, so we can figure out how long it was pressed for (tap or "held down").
                if (timer_elapsed(key_timer) > LONGPRESS_DELAY) { // LONGPRESS_DELAY being 150ms, the threshhold we pick for counting something as a tap.
                    tap_code(KC_MPLY);
                } else {
                    tap_code(KC_VOLU);
                }
            }
            return false;

        // switch multiplexing for media, short tap for volume down, long press for next track
        case M_VOLD:
            if (record->event.pressed) {
                key_timer = timer_read();
            } else {
                if (timer_elapsed(key_timer) > LONGPRESS_DELAY) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            return false;

        // switch multiplexing for escape, short tap for escape, long press for context menu
        case M_ESCM:
            if (record->event.pressed) {
                key_timer = timer_read();
            } else {
                if (timer_elapsed(key_timer) > LONGPRESS_DELAY) {
                    tap_code(KC_APP);
                } else {
                    tap_code(KC_ESC);
                }
            }
            return false;

        // If any other key was pressed during the layer mod hold period,
        // then the layer mod was used momentarily, and should block latching
        default:
            singular_key = false;
            break;
    }

    // ADJUST has been shifted by the SHIFT handling, some keys need to be excluded
    if (layer == _ADJUST) {
        // F1-F12 should be sent as unshifted keycodes,
        // and ] needs to be unshifted or it is sent as }
        if ((keycode >= KC_F1 && keycode <= KC_F12) || keycode == KC_RBRC) {
            if (record->event.pressed) {
                unregister_mods(MOD_LSFT);
            } else {
                register_mods(MOD_LSFT);
            }
        }
    }

    return true;
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
