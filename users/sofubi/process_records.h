#pragma once
#include "sofubi.h"

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    ADJUST,
	QWERTY,
	COLEMAK
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)
