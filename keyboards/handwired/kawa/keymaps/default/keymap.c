/* Copyright 2020 sofubi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE = 0,
	_ALWAYS,
	_FUNC,
	_NAV,
	_LSYM,
	_RSYM,
	_MOUSE,
	_NUM
};

enum best_keycodes {
	KC_ALW = SAFE_RANGE,
	KC_FUN,
	KC_NAV,
	KC_RSM,
	KC_LSM,
	KC_MOU,
	KC_NUMP,
	KC_ASH,
	KC_XCT,
	KC_CGU,
	KC_CMGU,
	KC_DTCT,
	KC_CLSH,
	KC_TTY
};

#define KC_ALW LT(1, KC_SPC)
#define KC_FUN LT(2, KC_S)
#define KC_NAV LT(3, KC_D)
#define KC_RSM LT(4, KC_F)
#define KC_LSM LT(5, KC_J)
#define KC_MOU LT(6, KC_K)
#define KC_NUMP LT(7, KC_L)
#define KC_ASH LSFT_T(KC_A)
#define KC_XCT LCTL_T(KC_X)
#define KC_CGU LGUI_T(KC_C)
#define KC_CMGU LGUI_T(KC_COMM)
#define KC_DTCT LCTL_T(KC_DOT)
#define KC_CLSH LSFT_T(KC_SCLN)
#define KC_TTY LCTL(KC_LALT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,   KC_U,     KC_I,      KC_O,      KC_P,
        KC_ASH,   KC_FUN,   KC_NAV,   KC_RSM,   KC_G,     KC_H,   KC_LSM,   KC_MOU,    KC_NUMP,   KC_CLSH,
        KC_Z,     KC_XCT,   KC_CGU,   KC_V,     KC_B,     KC_N,   KC_M,     KC_CMGU,   KC_DTCT,   KC_SLSH,
										 KC_BSPC,            KC_ALW
    ),
    [_ALWAYS] = LAYOUT(
        _______,   _______,   KC_COLN,   KC_ESC,   _______,   _______,   _______,   _______,   _______,   KC_DEL,
        _______,   _______,   _______,   KC_ENT,   _______,   _______,   KC_LGUI,   _______,   _______,   _______,
		_______,   _______,   _______,   _______,  _______,   _______,   _______,   _______,   _______,   RESET,
										      KC_TAB,               KC_NO
    ),
    [_FUNC] = LAYOUT(
		_______,   _______,   _______,   _______,  _______,   _______,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
		_______,   KC_NO,     KC_TTY,   _______,   _______,   _______,   KC_F4,   KC_F5,   KC_F6,   KC_F11,
		_______,   _______,   _______,   _______,  _______,   _______,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
										       _______,             _______
    ),
    [_NAV] = LAYOUT(
		_______,   _______,   _______,   _______,  _______,   _______,   _______,   _______,   _______,   _______,
		_______,   _______,   KC_NO,     _______,  _______,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  _______,
		_______,   _______,   _______,   _______,  _______,   _______,   _______,   _______,   _______,   _______,
											  _______,				_______
    ), 
	[_LSYM] = LAYOUT(
		_______,   _______,   _______,   _______,  _______,   _______,    KC_UNDS,   KC_PIPE,   KC_QUOT,   _______,
		KC_CIRC,   KC_ASTR,   KC_AMPR,   KC_NO,    _______,   KC_HASH,    KC_TILD,   KC_SLSH,   KC_DQUO,   KC_DLR,
		_______,   _______,   _______,   _______,  _______,   _______,    KC_MINS,   KC_BSLS,   KC_GRV,    _______,
											  _______,              _______
	),
	[_RSYM] = LAYOUT(
		_______,   KC_COLN,   KC_LT,     KC_GT,    _______,   _______,   _______,   _______,   _______,   _______,
		KC_LCBR,   KC_RCBR,   KC_LPRN,   KC_RPRN,  KC_AT,     _______,   KC_NO,     KC_EQL,    KC_PLUS,   KC_PERC,
		_______,   KC_EXLM,   KC_LBRC,   KC_RBRC,  _______,   _______,   _______,   _______,   _______,   _______,
											  _______,              _______
	),
	[_MOUSE] = LAYOUT(
		_______,   KC_BTN1,   KC_MS_U,   KC_BTN2,  _______,   _______,   KC_WH_U,   _______,   _______,   _______,
		_______,   KC_MS_L,   KC_MS_D,   KC_MS_R,  _______,   _______,   KC_WH_L,   KC_NO,     KC_WH_R,   _______,
		_______,   _______,   _______,   _______,  _______,   _______,   KC_WH_D,   _______,   _______,   _______,
											  _______,              _______
	),
	[_NUM] = LAYOUT(
		_______,   KC_7,   KC_8,   KC_9,  _______,      _______,   _______,   _______,   _______,   _______,
		KC_0,      KC_4,   KC_5,   KC_6,  _______,   _______,   _______,   _______,   KC_NO,     _______,
		_______,   KC_1,   KC_2,   KC_3,  _______,   _______,   _______,   _______,   _______,   _______,
											   _______,              _______
	),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;	
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

/* static void render_qmk_logo(void) { */
/*   static const char PROGMEM qmk_logo[] = { */
/*     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94, */
/*     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4, */
/*     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0}; */

/*   oled_write_P(qmk_logo, false); */
/* } */

/* static void render_status(void) { */
/*     // QMK Logo and version information */
/*     render_qmk_logo(); */
/*     oled_write_P(PSTR("       Kyria rev1.0\n\n"), false); */

/*     // Host Keyboard Layer Status */
/*     oled_write_P(PSTR("Layer: "), false); */
/*     switch (get_highest_layer(layer_state)) { */
/*         case _BASE: */
/*             oled_write_P(PSTR("Default\n"), false); */
/*             break; */
/*         case _ALWAYS: */
/*             oled_write_P(PSTR("Always\n"), false); */
/*             break; */
/*         case _FUNC: */
/*             oled_write_P(PSTR("Function\n"), false); */
/*             break; */
/*         case _NAV: */
/*             oled_write_P(PSTR("Navigation\n"), false); */
/*             break; */
/*         case _LSYM: */
/*             oled_write_P(PSTR("Left Symbol\n"), false); */
/*             break; */
/*         case _RSYM: */
/*             oled_write_P(PSTR("Right Symbol\n"), false); */
/*             break; */
/*         case _MOUSE: */
/*             oled_write_P(PSTR("Mouse\n"), false); */
/*             break; */
/*         case _NUM: */
/*             oled_write_P(PSTR("Number\n"), false); */
/*             break; */
/*         default: */
/*             oled_write_P(PSTR("Undefined\n"), false); */
/*     } */

/*     // Host Keyboard LED Status */
/*     uint8_t led_usb_state = host_keyboard_leds(); */
/*     oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false); */
/*     oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false); */
/*     oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false); */
/* } */

void oled_task_user(void) {
    render_kyria_logo();
}
#endif
