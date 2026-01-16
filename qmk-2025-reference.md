# QMK Firmware 2025: New Features & Modules Reference

A reference guide for QMK developments in 2025, focusing on community modules, tap-hold improvements, and home row mod configurations.

---

## Table of Contents

1. [Community Modules](#community-modules)
2. [Core Tap-Hold Features](#core-tap-hold-features)
3. [Home Row Mods: The 2025 Stack](#home-row-mods-the-2025-stack)
4. [Getreuer's Community Modules](#getreuers-community-modules)
5. [Drashna's Community Modules](#drashnas-community-modules)
6. [External Userspace](#external-userspace)
7. [Other Notable Changes](#other-notable-changes)
8. [Quick Reference](#quick-reference)

---

## Community Modules

**Released:** QMK 0.28.0 (February 2025)

Community Modules are the headline feature of 2025. They allow third-party code to be packaged and shared cleanly, replacing the old method of copying C files and manually editing `rules.mk`.

### How Modules Work

Modules can provide:
- Custom keycodes
- Key processing hooks
- Initialization/shutdown handlers
- RGB matrix effects
- Pointing device callbacks
- Layer state callbacks

### Installation

**Step 1:** Add module repo as a git submodule:

```bash
cd /path/to/your/userspace
git submodule add https://github.com/getreuer/qmk-modules.git modules/getreuer
git submodule update --init --recursive
```

**Step 2:** Reference modules in your `keymap.json`:

```json
{
  "modules": ["getreuer/sentence_case", "getreuer/custom_shift_keys"]
}
```

**Step 3:** Compile and flash as usual.

### Key Module Repositories

| Repository | Maintainer | Focus |
|------------|------------|-------|
| [getreuer/qmk-modules](https://github.com/getreuer/qmk-modules) | Pascal Getreuer | Tap-hold, typing enhancements |
| [drashna/qmk_modules](https://github.com/drashna/qmk_modules) | Drashna | Hardware, pointing devices, displays |
| [tzarc/modules](https://github.com/tzarc) | Tzarc | SOCD Cleaner, misc |

### Module File Structure

```
modules/
└── getreuer/
    └── sentence_case/
        ├── qmk_module.json    # Module metadata
        ├── sentence_case.c    # Implementation
        ├── sentence_case.h    # Header
        └── rules.mk           # Build rules (optional)
```

---

## Core Tap-Hold Features

Several popular userspace features have graduated to QMK core in 2025.

### Chordal Hold

**Released:** February 2025 (QMK 0.28.0)

Implements an "opposite hands" rule for tap-hold keys. Supersedes the Achordion userspace library.

**How it works:**
- Press a tap-hold key, then another key on the **same hand** → tap
- Press a tap-hold key, then another key on the **opposite hand** → hold (with Permissive Hold)

**Why it matters:** Eliminates accidental modifier triggers from typing rolls like "df" or "jk" when using home row mods.

**Setup:**

```c
// config.h
#define CHORDAL_HOLD
```

**Recommended combo:**

```c
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
#define TAPPING_TERM 200  // or up to 250
```

**Custom handedness** (if auto-detection doesn't work):

```c
// keymap.c
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R',
                   '*', '*', '*',    '*', '*', '*'  // Thumbs exempt
);
```

Use `'*'` to exempt keys (like thumbs) from Chordal Hold.

---

### Flow Tap

**Released:** May 2025

Disables hold behavior during fast typing. If a tap-hold key is pressed within a short timeout of the previous key, it always registers as a tap.

**How it works:**
- You're typing fast (keys within ~150ms of each other)
- Tap-hold keys become regular taps
- No accidental modifier triggers during typing streaks

**Setup:**

```c
// config.h
#define FLOW_TAP_TERM 150  // milliseconds, adjust to taste
```

**Customizing which keys use Flow Tap:**

```c
// keymap.c
bool is_flow_tap_key(uint16_t keycode) {
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
```

**Note:** Flow Tap is temporarily disabled while a tap-hold key is unsettled. This allows chording multiple mod-tap keys (like Ctrl+Shift) without waiting.

---

### Speculative Hold

**Released:** November 2025

Applies mod-tap modifiers **instantly** on keydown, before the tap-hold decision is made. Makes Shift+Click and Ctrl+Scroll feel responsive when using mod-taps with an external mouse.

**How it works:**
1. Press a mod-tap key → modifier applies immediately
2. If settled as **held** → modifier stays active
3. If settled as **tapped** → modifier is canceled, tap keycode sent

**Setup:**

```c
// config.h
#define SPECULATIVE_HOLD
```

**Default behavior:** Applies to Ctrl and Shift mod-taps only.

**Custom configuration:**

```c
// keymap.c
bool get_speculative_hold(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
        case LSFT_T(KC_Z):
        case RSFT_T(KC_SLSH):
            return true;
    }
    return false;
}
```

**Caveat:** Some OS features trigger on lone modifier taps (like Windows key opening Start menu). Use `DUMMY_MOD_NEUTRALIZER_KEYCODE` if this causes issues.

---

### Caps Word

**Released:** Core since May 2022

Auto-disabling caps lock for typing `ALL_CAPS_IDENTIFIERS`. Automatically turns off when you type a word-breaking character.

**Activation options:**

```c
// config.h

// Option 1: Both shifts simultaneously
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Option 2: Double-tap left shift
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Option 3: Dedicated keycode
// Use CW_TOGG in your keymap
```

**Behavior:**
- Letters → capitalized
- `-` → becomes `_`
- Numbers, backspace, delete → continue Caps Word
- Space, punctuation → end Caps Word
- Idle timeout → 5 seconds (configurable)

**Customizing:**

```c
// keymap.c
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;
        default:
            return false;  // Deactivate Caps Word
    }
}
```

---

## Home Row Mods: The 2025 Stack

The recommended configuration for home row mods in 2025:

```c
// config.h

// Core timing
#define TAPPING_TERM 200          // Base tap-hold timeout (200-250ms)
#define PERMISSIVE_HOLD           // Opposite-hand chords settle quickly

// The 2025 additions
#define CHORDAL_HOLD              // Same-hand = tap, opposite-hand = hold
#define FLOW_TAP_TERM 150         // Disable holds during fast typing

// Optional but recommended
#define SPECULATIVE_HOLD          // Instant mods for mouse usage
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD  // Easy all-caps typing
```

### What Each Setting Solves

| Problem | Solution |
|---------|----------|
| "fresh" becomes "Resh" (same-hand roll) | Chordal Hold |
| Accidental Ctrl+A when typing "day" fast | Flow Tap |
| Shift+Click feels laggy | Speculative Hold |
| Typing `CONSTANT_NAMES` is awkward | Caps Word |
| Opposite-hand shortcuts feel slow | Permissive Hold |

### Example Home Row Mod Layout (GACS)

```c
// Left hand home row
// A        S        D        F
LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),

// Right hand home row
// J        K        L        ;
RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
```

---

## Getreuer's Community Modules

Pascal Getreuer maintains the most popular collection of QMK modules.

### Typing Enhancement Modules

| Module | Description | Use Case |
|--------|-------------|----------|
| `custom_shift_keys` | Customize what Shift+key produces | Make Shift+, produce ? |
| `sentence_case` | Auto-capitalize first letter of sentences | Reduce shift usage |
| `select_word` | Tap to select word, again for line | Faster text selection |
| `caps_word` | Userspace Caps Word (if you want more control) | ALL_CAPS typing |

### Tap-Hold Modules

| Module | Description | Use Case |
|--------|-------------|----------|
| `achordion` | Original opposite-hands implementation | Legacy, use Chordal Hold instead |
| `tap_flow` | Userspace Flow Tap with more options | Fine-grained control |
| `speculative_hold` | Userspace Speculative Hold | More customization |

### Gaming & Input Modules

| Module | Description | Use Case |
|--------|-------------|----------|
| `socd_cleaner` | SOCD filtering (left+right → neutral) | Fighting games, FPS |
| `repeat_key` | Repeat last pressed key | Gaming, macros |

### Mouse & Pointing Modules

| Module | Description | Use Case |
|--------|-------------|----------|
| `orbital_mouse` | Polar coordinate mouse control | Alternative to mouse keys |
| `mouse_turbo_click` | Rapid clicking | Gaming |

### Utility Modules

| Module | Description | Use Case |
|--------|-------------|----------|
| `layer_lock` | Lock current layer until pressed again | Avoid holding layer keys |
| `keycode_string` | Format keycodes as readable strings | Debugging |

### Installation Example

```bash
# Add to your userspace
cd ~/qmk_userspace
git submodule add https://github.com/getreuer/qmk-modules.git modules/getreuer
```

```json
// keymap.json
{
  "modules": [
    "getreuer/custom_shift_keys",
    "getreuer/sentence_case",
    "getreuer/select_word"
  ]
}
```

---

## Drashna's Community Modules

Drashna's modules focus on hardware extensions and pointing devices.

### Pointing Device Modules

| Module | Description | Use Case |
|--------|-------------|----------|
| `drag_scroll` | Hold key to turn trackball into scroll | Trackball keyboards |
| `maccel` | Mouse acceleration curves | Fine-tune pointing feel |
| `cardinal_behavior` | Trigger actions by mouse direction | Directional gestures |
| `wiggle_behavior` | Trigger actions when wiggling mouse | Gesture input |

### Hardware Modules

| Module | Description | Use Case |
|--------|-------------|----------|
| `hardware_rtc` | Real-time clock support | Timestamps on displays |
| `watchdog` | Hardware watchdog support | Crash recovery |

### Display Modules

| Module | Description | Use Case |
|--------|-------------|----------|
| `osd_display` | On-screen display code | Custom OLED/LCD content |
| `qp_util` | Quantum Painter utilities | Line graphs, etc. |

### Debug Modules

| Module | Description | Use Case |
|--------|-------------|----------|
| `debug_console` | FAQ debugging console code | Troubleshooting |
| `i2c_scanner` | Scan I2C bus for devices | Hardware debugging |

### Installation Example

```bash
cd ~/qmk_userspace
git submodule add https://github.com/drashna/qmk_modules.git modules/drashna
```

```json
// keymap.json
{
  "modules": [
    "drashna/drag_scroll",
    "drashna/maccel"
  ]
}
```

---

## External Userspace

External Userspace lets you keep your keymap in a **separate git repo** from `qmk_firmware`.

### The Problem with Traditional Setup

```
qmk_firmware/
└── keyboards/
    └── your_keyboard/
        └── keymaps/
            └── your_keymap/    ← Tangled with QMK
```

- Merge conflicts when updating QMK
- Hard to version control just your stuff
- Can't easily share your setup

### External Userspace Structure

```
qmk_firmware/               ← Upstream QMK (never edit)

your_userspace/             ← Your own repo
├── keyboards/
│   └── your_keyboard/
│       └── keymaps/
│           └── your_keymap/
│               ├── keymap.c
│               ├── keymap.json
│               ├── config.h
│               └── rules.mk
├── modules/
│   ├── getreuer/           ← Community modules (submodules)
│   └── drashna/
└── users/
    └── your_name/          ← Shared code across keymaps
        ├── your_name.c
        └── your_name.h
```

### Setup Steps

**Step 1:** Create your userspace repo:

```bash
mkdir ~/qmk_userspace
cd ~/qmk_userspace
git init
```

**Step 2:** Tell QMK where it is:

```bash
qmk config user.overlay_dir="$(realpath ~/qmk_userspace)"
```

**Step 3:** Create your keymap structure:

```bash
mkdir -p keyboards/your_keyboard/keymaps/your_keymap
# Copy your keymap files here
```

**Step 4:** Add community modules:

```bash
git submodule add https://github.com/getreuer/qmk-modules.git modules/getreuer
```

**Step 5:** Build as usual:

```bash
qmk compile -kb your_keyboard -km your_keymap
```

### Benefits

- Update QMK without touching your keymap
- Your keymap has its own git history
- Easy to add/update community modules
- Share your setup by sharing the repo
- Back up just your configuration

---

## Other Notable Changes

### VIA Keymaps Moved Out (August 2024)

VIA-enabled keymaps are no longer accepted into `qmk_firmware`. The VIA team maintains their own repository. If you use VIA, your keymap configuration is stored separately.

### RGB Matrix Effects from Modules

Community modules can now define custom RGB matrix effects. Effect names are prefixed with `RGB_MATRIX_COMMUNITY_MODULE_`.

### Encoder Mapping Changes

The old `encoder_update_user()` callback is deprecated. Use encoder mapping instead:

```c
// Old way (deprecated)
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}

// New way (encoder mapping)
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif
```

### NKRO and Bluetooth

Force-disabling NKRO when Bluetooth is enabled has been removed. You can now use NKRO with Bluetooth if your setup supports it.

---

## Quick Reference

### Essential config.h for Home Row Mods

```c
// Timing
#define TAPPING_TERM 200

// Tap-hold behavior
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define FLOW_TAP_TERM 150
#define SPECULATIVE_HOLD

// Quality of life
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
```

### Community Module Setup

```json
// keymap.json
{
  "modules": [
    "getreuer/custom_shift_keys",
    "getreuer/sentence_case"
  ]
}
```

### External Userspace Commands

```bash
# Set overlay directory
qmk config user.overlay_dir="$(realpath ~/qmk_userspace)"

# Add module submodule
git submodule add https://github.com/getreuer/qmk-modules.git modules/getreuer

# Update modules
git submodule update --remote

# Compile
qmk compile -kb keyboard -km keymap
```

### Key Resources

| Resource | URL |
|----------|-----|
| QMK Docs | https://docs.qmk.fm |
| Chordal Hold Docs | https://docs.qmk.fm/tap_hold#chordal-hold |
| Flow Tap Docs | https://docs.qmk.fm/tap_hold#flow-tap |
| Community Modules Docs | https://docs.qmk.fm/features/community_modules |
| Getreuer's Modules | https://github.com/getreuer/qmk-modules |
| Getreuer's Keyboard Posts | https://getreuer.info/posts/keyboards/ |
| Drashna's Modules | https://github.com/drashna/qmk_modules |

---

*Last updated: January 2026*
