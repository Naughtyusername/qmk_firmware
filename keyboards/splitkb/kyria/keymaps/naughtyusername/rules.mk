OLED_ENABLE = yes
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGB_MATRIX_ENABLE = no    # Disable keyboard RGB matrix, as it is enabled by default on rev3
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow

# Custom changes - above is the defaults - 2026, first time back into qmk in 6 years!
SPLIT_KEYBOARD = yes
SPLIT_OLED_ENABLE = yes
SPLIT_WPM_ENABLE = no      # Disabled to save space (~500 bytes)

EXTRAKEY_ENABLE = yes					 # Audio control and System control
TRI_LAYER_ENABLE = yes
CAPS_WORD_ENABLE = yes

TAP_DANCE_ENABLE = no      # Disabled to save space (~500 bytes)
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = no   # Disabled to save space (~300 bytes)
# too much space on kyria :( - saves about 1200 bytes turning this off
MOUSEKEY_ENABLE = no

# Enable NKRO (N-key rollover)
NKRO_ENABLE = yes

# Bootmagic for easy bootloader access (lite version saves ~200 bytes)
BOOTMAGIC_ENABLE = lite

# Space saving options - these can be changed if we need them
CONSOLE_ENABLE = no  # enable when we need debugging only
COMMAND_ENABLE = no  # magic debugging - we have this off for caps word
# SPACE_CADET_ENABLE = no
# GRAVE_ESC_ENABLE = no
# MAGIC_ENABLE = no
UNICODE_ENABLE = no
SWAP_HANDS_ENABLE = no
# Enable link time optimization (saves space)
LTO_ENABLE = yes
