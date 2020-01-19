SRC += muse.c

FORCE_NKRO = yes           # costs space, but i like it. consider making it toggleable
COMBO_ENABLE = no 		   # not sure i need or want this, read more


RGBLIGHT_STARTUP_ANIMATION = yes # RGB startup animation
EXTRAKEY_ENABLE = yes     		 # Audio control and System control
UNICODE_ENABLE = yes      		 # Unicode

LEADER_ENABLE = yes              # enables leader key functionality

# diabled for space

MOUSEKEY_ENABLE = no      		 # Mouse keys
CONSOLE_ENABLE = no              # Console for debug
COMMAND_ENABLE = no              # Commands for debug and configuration

EXTRAFLAGS += -flto
