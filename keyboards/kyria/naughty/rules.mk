USER_NAME := naughty

OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
FORCE_NKRO = yes           # costs space, but i like it. consider making it toggleable
COMBO_ENABLE = no					 # not sure i need or want this, read more
#TAP_DANCE_ENABLE = yes    # enable tap dance
LEADER_ENABLE = yes        # enable leader keys
SPLIT_KEYBOARD = yes

RGBLIGHT_STARTUP_ANIMATION = yes # RGB startup animation
EXTRAKEY_ENABLE = yes					 # Audio control and System control
# BACKLIGHT_ENABLE = yes				 # Enable keyboard backlight functionality on B7 by default

# diabled for space
UNICODE_ENABLE = no					 # Unicode
MOUSEKEY_ENABLE = no					 # Mouse keys
CONSOLE_ENABLE = no              # Console for debug
COMMAND_ENABLE = no              # Commands for debug and configuration

EXTRAFLAGS += -flto
