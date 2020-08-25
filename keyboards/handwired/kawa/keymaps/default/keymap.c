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

#define KC_ALW LT(_ALWAYS, KC_SPC)
#define KC_FUN LT(_FUNC, KC_S)
#define KC_NAV LT(_NAV, KC_D)
#define KC_RSM LT(_RSYM, KC_F)
#define KC_LSM LT(_LSYM, KC_J)
#define KC_MOU LT(_MOUSE, KC_K)
#define KC_NUMP LT(_NUM, KC_L)
#define KC_ASH LSFT_T(KC_A)
#define KC_XCT LCTL_T(KC_X)
#define KC_CGU LGUI_T(KC_C)
#define KC_CMGU LGUI_T(KC_COMM)
#define KC_DTCT LCTL_T(KC_DOT)
#define KC_CLSH LSFT_T(KC_SCLN)
#define KC_TTY LCTL(KC_LALT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,   KC_U,     KC_I,      KC_O,      KC_P,
        KC_ASH,   KC_FUN,   KC_NAV,   KC_RSM,   KC_G,     KC_H,   KC_LSM,   KC_MOU,    KC_NUMP,   KC_CLSH,
        KC_Z,     KC_XCT,   KC_CGU,   KC_V,     KC_B,     KC_N,   KC_M,     KC_CMGU,   KC_DTCT,   KC_SLSH,
										 KC_BSPC,            KC_ALW
    ),
    [_ALWAYS] = LAYOUT(
        XXXXXXX,   XXXXXXX,   KC_COLN,   KC_ESC,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_DEL,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_ENT,   XXXXXXX,   XXXXXXX,   KC_LGUI,   XXXXXXX,   XXXXXXX,   XXXXXXX,
		XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   RESET,
										      KC_TAB,               KC_NO
    ),
    [_FUNC] = LAYOUT(
		XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
		XXXXXXX,   KC_NO,     XXXXXXX,   KC_TTY,   XXXXXXX,   XXXXXXX,   KC_F4,   KC_F5,   KC_F6,   KC_F11,
		XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
										       XXXXXXX,             XXXXXXX
    ),
    [_NAV] = LAYOUT(
		XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
		XXXXXXX,   XXXXXXX,   KC_NO,     XXXXXXX,  XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  XXXXXXX,
		XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
											  XXXXXXX,				XXXXXXX
    ), 
	[_LSYM] = LAYOUT(
		XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,    KC_UNDS,   KC_PIPE,   KC_QUOT,   XXXXXXX,
		KC_CIRC,   KC_ASTR,   KC_AMPR,   KC_NO,    XXXXXXX,   KC_HASH,    KC_TILD,   KC_SLSH,   KC_DQUO,   KC_DLR,
		XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,    KC_MINS,   KC_BSLS,   KC_GRV,    XXXXXXX,
											  XXXXXXX,              XXXXXXX
	),
	[_RSYM] = LAYOUT(
		XXXXXXX,   KC_COLN,   KC_LT,     KC_GT,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
		KC_LCBR,   KC_RCBR,   KC_LPRN,   KC_RPRN,  KC_AT,     XXXXXXX,   KC_NO,     KC_EQL,    KC_PLUS,   KC_PERC,
		XXXXXXX,   KC_EXLM,   KC_LBRC,   KC_RBRC,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
											  XXXXXXX,              XXXXXXX
	),
	[_MOUSE] = LAYOUT(
		XXXXXXX,   KC_BTN1,   KC_MS_U,   KC_BTN2,  XXXXXXX,   XXXXXXX,   KC_WH_U,   XXXXXXX,   XXXXXXX,   XXXXXXX,
		XXXXXXX,   KC_MS_L,   KC_MS_D,   KC_MS_R,  XXXXXXX,   XXXXXXX,   KC_WH_L,   KC_NO,     KC_WH_R,   XXXXXXX,
		XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,   KC_WH_D,   XXXXXXX,   XXXXXXX,   XXXXXXX,
											  XXXXXXX,              XXXXXXX
	),
	[_NUM] = LAYOUT(
		XXXXXXX,   KC_7,   KC_8,   KC_9,  KC_0,      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
		XXXXXXX,   KC_4,   KC_5,   KC_6,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_NO,     XXXXXXX,
		XXXXXXX,   KC_1,   KC_2,   KC_3,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
											   XXXXXXX,              XXXXXXX
	),
};
