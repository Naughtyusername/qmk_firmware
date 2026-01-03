# Mitosis rules.mk - Feature enables

# Custom features
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
EXTRAKEY_ENABLE = yes  # Audio control and System control
TRI_LAYER_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
MOUSEKEY_ENABLE = yes

# Enable NKRO (N-key rollover)
NKRO_ENABLE = yes

# Bootmagic for easy bootloader access
BOOTMAGIC_ENABLE = yes

# Space saving options - these can be changed if we need them
CONSOLE_ENABLE = no  # enable when we need debugging only
COMMAND_ENABLE = no  # magic debugging - we have this off for caps word
# SPACE_CADET_ENABLE = no
# GRAVE_ESC_ENABLE = no
# MAGIC_ENABLE = no

# Enable link time optimization (saves space)
LTO_ENABLE = yes
