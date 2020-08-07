#pragma once

#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "process_records.h"
#include "wrappers.h"
#if defined(OLED_DRIVER_ENABLE)
#    include "oled.h"
#endif

enum layers {
    _QWERTY = 0,
	_COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

void          matrix_init_keymap(void);
void          shutdown_keymap(void);
void          suspend_power_down_keymap(void);
void          suspend_wakeup_init_keymap(void);
void          matrix_scan_keymap(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t default_layer_state_set_keymap(layer_state_t state);
void          led_set_keymap(uint8_t usb_led);
void          eeconfig_init_keymap(void);
