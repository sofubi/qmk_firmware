SRC += sofubi.c \
	   process_records.c

STENO_ENABLE = no
AUDIO_ENABLE = no
KEY_LOCK_ENABLE = no
GRAVE_ESC_ENABLE = no
BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE  = no  
TAP_DANCE_ENABLE = no
VELOCIKEY_ENABLE = no
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no
CONSOLE_ENABLE = no
NKRO_ENABLE = no
LINK_TIME_OPTIMIZATION_ENABLE = yes

ifeq ($(strip $(KEYBOARD)), crkbd/rev1)
RGB_MATRIX_ENABLE = WS2812
EXTRAFLAGS += -flto
BOOTLOADER = qmk-dfu
OLED_DRIVER_ENABLE = yes
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
WPM_ENABLE = yes
    SRC += oled.c
endif

ifdef CONSOLE_ENABLE
    ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
        OPT_DEFS += -DKEYLOGGER_ENABLE
    endif
endif
