SRC += lib/logo.c

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow

# Additional thing to reduce compiled size
LTO_ENABLE = yes
NO_USB_STARTUP_CHECK = yes

# RGB Matrix enabled
RGB_MATRIX_ENABLE = yes

# OLED enabled
OLED_ENABLE = yes
