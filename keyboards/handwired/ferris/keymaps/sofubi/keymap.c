/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "sofubi.h"
//clang-format off
#define LAYOUT_ferris_base( \
    K0_0, K0_1, K0_2, K0_3, K0_4, K0_5, K0_6, K0_7, K0_8, K0_9, \
    K1_0, K1_1, K1_2, K1_3, K1_4, K1_5, K1_6, K1_7, K1_8, K1_9, \
    K2_0, K2_1, K2_2, K2_3, K2_4, K2_5, K2_6, K2_7, K2_8, K2_9  \
  ) \
  LAYOUT_wrapper( \
    K0_0, K0_1, K0_2, K0_3, K0_4, K0_5, K0_6, K0_7, K0_8, K0_9, \
    K1_0, K1_1, K1_2, K1_3, K1_4, K1_5, K1_6, K1_7, K1_8, K1_9, \
    K2_0, K2_1, K2_2, K2_3, K2_4, K2_5, K2_6, K2_7, K2_8, K2_9, \
				KC_0, KC_BSPC, LT(7, KC_SPC), KC_1 \
  )

#define LAYOUT_ferris_base_wrapper(...) LAYOUT_ferris_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_ferris_base_wrapper(
	_________________34_L1_____________________, _________________34_R1_____________________,
	_________________34_L2_____________________, _________________34_R2_____________________,
	_________________34_L3_____________________, _________________34_R3_____________________
	),
	[_MOUSE] = LAYOUT_wrapper(
	_________________34_MOUSE_L1_______________, _________________34_MOUSE_R1_______________,
	_________________34_MOUSE_L2_______________, _________________34_MOUSE_R2_______________,
	_________________34_MOUSE_L3_______________, _________________34_MOUSE_R3_______________,
								_______, _______, _______, _______
	),
	[_NAV] = LAYOUT_wrapper(
	_________________34_NAV_L1_________________, _________________34_NAV_R1_________________,
	_________________34_NAV_L2_________________, _________________34_NAV_R2_________________,
	_________________34_NAV_L3_________________, _________________34_NAV_R3_________________,
								_______, _______, _______, _______
	), 
	[_RSYM] = LAYOUT_wrapper(
	_________________34_RSYM_L1________________, _________________34_RSYM_R1________________,
	_________________34_RSYM_L2________________, _________________34_RSYM_R2________________,
	_________________34_RSYM_L3________________, _________________34_RSYM_R3________________,
								_______, _______, _______, _______
	),
	[_LSYM] = LAYOUT_wrapper(
	_________________34_LSYM_L1________________, _________________34_LSYM_R1________________,
	_________________34_LSYM_L2________________, _________________34_LSYM_R2________________,
	_________________34_LSYM_L3________________, _________________34_RSYM_R3________________,
								KC_VOLD, _______, _______, KC_VOLU
	),
	[_FUNC] = LAYOUT_wrapper(
	_________________34_FUNC_L1________________, _________________34_FUNC_R1________________,
	_________________34_FUNC_L2________________, _________________34_FUNC_R2________________,
	_________________34_FUNC_L3________________, _________________34_FUNC_R3________________,
								_______, _______, _______, _______
	),
	[_NUM] = LAYOUT_wrapper(
	_________________34_NUM_L1_________________, _________________34_NUM_R1_________________,
	_________________34_NUM_L2_________________, _________________34_NUM_R2_________________,
	_________________34_NUM_L3_________________, _________________34_NUM_R3_________________,
								_______, _______, _______, _______
	),
	[_ALWAYS] = LAYOUT_wrapper(
	_________________34_ALWAYS_L1______________, _________________34_ALWAYS_R1______________,
	_________________34_ALWAYS_L2______________, _________________34_ALWAYS_R2______________,
	_________________34_ALWAYS_L3______________, _________________34_ALWAYS_R3______________,
								_______, KC_TAB, KC_NO, _______
	)
};
// clang-format on
