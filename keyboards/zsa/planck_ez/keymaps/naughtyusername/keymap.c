#include QMK_KEYBOARD_H

/* * PLANCK EZ - FULL MITOSIS PORT
 * 12 Columns total | Alphas in Columns 1-10
 * Bottom Row: 2u Centered Space (4 Left, 1 Center, 6 Right = 11 Keys)
 */

// clang-format off
enum mitosis_layers {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST,
    _GAMING
};

// Custom Keycodes
enum custom_keycodes {
    KC_ASSIGN = SAFE_RANGE, // :=
    KC_ARROP,               // ->
    KC_DCLN,                // ::
};

// Tap Dance
enum tapdancers { TD_Q_ESC };
tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

// Audio shenanigans
#ifdef AUDIO_ENABLE
// Modern QMK expects this specific [][2] structure for songs
float combo_song[][2]     = SONG(QWERTY_SOUND);
float gaming_on_song[][2]  = SONG(STARTUP_SOUND);
float gaming_off_song[][2] = SONG(GOODBYE_SOUND);

float my_startup_song[][2] = SONG(
    E__NOTE(_E5), E__NOTE(_G5), E__NOTE(_E6), E__NOTE(_C6), E__NOTE(_D6), E__NOTE(_G6)
);
#endif

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        PLAY_SONG(my_startup_song);
    #endif
}

// Home Row Mods (GACS)
#define HM_A    LGUI_T(KC_A)
#define HM_S    LALT_T(KC_S)
#define HM_D    LCTL_T(KC_D)
#define HM_F    LSFT_T(KC_F)
#define HM_J    RSFT_T(KC_J)
#define HM_K    RCTL_T(KC_K)
#define HM_L    RALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

// Layer Shortcuts
#define LOW     MO(_LOWER)
#define RAI     MO(_RAISE)
#define FN      MO(_FUNCTION)
#define SP_RAI  LT(_RAISE, KC_SPACE)
#define ENT_LOW LT(_LOWER, KC_ENTER)

// Combos
const uint16_t PROGMEM jk_combo[] = {HM_J, HM_K, COMBO_END};
combo_t key_combos[] = { COMBO(jk_combo, KC_ESC) };

// --- Key Overrides ---
const key_override_t shift_bspc_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// Use this EXACT array syntax so ARRAY_SIZE() works
const key_override_t *key_overrides[] = {
    &shift_bspc_override,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE (Qwerty)
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │ Tab │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ Bksp│
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │ Esc │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │Shift│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │Enter│
 * ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
 * │ Ctrl│ GUI │ Alt │CapsW│Raise│   Space   │Lower│ Left│ Down│  Up │Right│
 * └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
 */
[_BASE] = LAYOUT_planck_1x2uC(
    KC_TAB,  TD(TD_Q_ESC),    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  HM_A,    HM_S,    HM_D,    HM_F,    KC_G,    KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT, CW_TOGG, MO(_RAISE),    KC_SPC,     MO(_LOWER), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* RAISE (Symbols)
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  %  │  $  │  -  │  |  │  [  │  ]  │  +  │  #  │  <  │  >  │ Del │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  !  │  *  │  =  │  &  │  (  │  )  │  ^  │  _  │  "  │  :: │     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │  -> │  := │  {  │     │     │  }  │  @  │     │     │     │
 * ├─────┼─────┼─────┼─────┼───────────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │     │     │   TRANS   │     │     │     │     │     │     │
 * └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_RAISE] = LAYOUT_planck_1x2uC(
    KC_GRV,  KC_PERC, KC_DLR,  KC_MINS, KC_PIPE, KC_LBRC, KC_RBRC, KC_PLUS, KC_HASH, KC_LT,   KC_GT,   KC_DEL,
    _______, KC_EXLM, KC_ASTR, KC_EQL,  KC_AMPR, KC_LPRN, KC_RPRN, KC_CIRC, KC_UNDS, KC_DQT,  KC_DCLN,    _______,
    _______, _______, KC_ARROP,   KC_ASSIGN,  KC_LCBR, _______, _______, KC_RCBR, KC_AT,   _______, _______, _______,
    _______, _______, _______, _______, _______,      _______,      MO(_LOWER), _______, _______, _______, _______
),

/* LOWER (Symbols & Numbers)
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │ Del │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │     │     │     │     │     │     │     │     │     │     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │     │     │     │           │XXXXX│     │     │     │     │
 * └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
 */
[_LOWER] = LAYOUT_planck_1x2uC(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______,      _______, _______, _______, _______, _______
),

/* FUNCTION (F-Keys / Navigation)
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │ F9  │ F10 │ F11 │ F12 │PrtSc│     │ PgUp│ Home│ End │ Ins │     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │ F5  │ F6  │ F7  │ F8  │     │     │ Left│ Down│ Up  │Right│     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │ F1  │ F2  │ F3  │ F4  │     │     │ PgDn│     │     │     │     │
 * ├─────┼─────┼─────┼─────┼───────────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │     │     │   TRANS   │     │ HOLD│     │     │     │     │
 * └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_FUNCTION] = LAYOUT_planck_1x2uC(
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, _______, KC_PGUP, KC_HOME, KC_END,  KC_INS,  _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_PGDN, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______,      _______,   _______, _______, _______, _______
),

/* ADJUST (System)
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │Base │ Boot│ Debg│RGB_T│     │     │     │     │     │     │     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │     │     │     │     │     │Ms Up│Btn 1│Btn 2│Btn 3│     │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │     │     │     │     │     │Ms L │Ms Dn│Ms Up│Ms R │     │
 * ├─────┼─────┼─────┼─────┼───────────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │     │     │  Gaming   │     │EEClr│     │     │     │     │
 * └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_ADJUST] = LAYOUT_planck_1x2uC(
    _______, TO(_BASE), QK_BOOT, DB_TOGG, QK_RGB_MATRIX_TOGGLE, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,   _______, _______, _______,              _______,                   _______, MS_UP,   MS_BTN1, MS_BTN2, MS_BTN3, _______,
    _______, _______,   _______, _______, _______,              _______,                   _______, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______,
    _______, _______,   _______, _______,       TG(_GAMING),                               _______, EE_CLR,  _______, _______, _______, _______
),

/* GAMING (No Home Row Mods)
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │ Tab │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ Bksp│
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │ Esc │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │ Ent │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │Shift│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │     │
 * ├─────┼─────┼─────┼─────┼───────────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │ Ctrl│ Alt │ GUI │ Low │   Space   │ Rai │ FN  │ Left│ Down│ Up  │Right│
 * └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_GAMING] = LAYOUT_planck_1x2uC(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    KC_LCTL, KC_LALT, KC_LGUI, TG(_GAMING), MO(_RAISE),    KC_SPC,     MO(_LOWER), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
)

};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_ASSIGN:
                tap_code16(KC_COLON);
                tap_code16(KC_EQUAL);
                return false;
            case KC_ARROP:
                tap_code(KC_MINS);
                tap_code16(KC_GT);
                return false;
            case KC_DCLN:
                tap_code16(KC_COLON);
                tap_code16(KC_COLON);
                return false;
        }
    }
    return true;
}

// Add this function to play sound when the combo fires
void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed && combo_index == 0) { // 0 is your JK combo
#ifdef AUDIO_ENABLE
        PLAY_SONG(combo_song);
#endif
    }
}

// clang-format off
// Tri-Layer Logic
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

    #ifdef AUDIO_ENABLE
        static bool gaming_was_on = false;
        bool gaming_is_on = layer_state_cmp(state, _GAMING);
        if (gaming_is_on && !gaming_was_on) {
            PLAY_SONG(gaming_on_song);
        } else if (!gaming_is_on && gaming_was_on) {
            PLAY_SONG(gaming_off_song);
        }
        gaming_was_on = gaming_is_on;
    #endif

    return state;
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {

        case _GAMING:
            // Set the whole board to Red
            rgb_matrix_set_color_all(255, 0, 0);
            break;

        case _LOWER:
            // Set the whole board to Blue
            rgb_matrix_set_color_all(0, 0, 255);
            break;

        case _RAISE:
            // Set the whole board to Green
            rgb_matrix_set_color_all(0, 255, 0);
            break;

        case _FUNCTION:
            // Set the whole board to Yellow
            rgb_matrix_set_color_all(255, 255, 0);
            break;

        case _ADJUST:
            // Set the whole board to Purple
            rgb_matrix_set_color_all(191, 0, 255);
            break;

        default:
            // Base layer (no specific color/use your default effect)
          return true;
            break;
    }
  return false;
}
#endif
