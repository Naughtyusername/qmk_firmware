#!/bin/bash

# --- 1. Configuration ---
QMK_PATH="$HOME/qmk/qmk_firmware"

# --- 2. The Build Function ---
# This takes two arguments: keyboard name and keymap name
build_keyboard() {
    local KEYBOARD=$1
    local KEYMAP=$2
    echo "---------------------------------------"
    echo "🛠️  BUILDING $KEYBOARD"
    echo "---------------------------------------"

    # Build the keyboard
    qmk compile -kb "$KEYBOARD" -km "$KEYMAP"
}

# --- 3. Execution ---
cd "$QMK_PATH" || exit

# Build your keyboards
build_keyboard "mitosis" "naughtyusername"
build_keyboard "splitkb/kyria" "naughtyusername"
build_keyboard "splitkb/zima" "naughtyusername"
build_keyboard "zsa/planck_ez/glow" "naughtyusername"

# --- 4. Notifications ---
echo "---------------------------------------"

# Desktop Notification (Linux)
if command -v notify-send &>/dev/null; then
    notify-send "QMK Build Complete" "All keyboards built successfully." -i keyboard
fi

# Sound Alert (System Beep)
echo -e "\a"

echo "✅ ALL BUILDS COMPLETE"
echo "📂 Location: $QMK_PATH/.build/"
