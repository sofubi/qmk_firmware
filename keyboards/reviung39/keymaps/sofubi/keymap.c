/* Copyright 2019 gtips
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
#include "sofubi.h"

// clang-format off
#define LAYOUT_reviung_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
  ) \
  LAYOUT_reviung39_wrapper( \
    LGUI_T(KC_TAB), K01, K02, K03, K04,     K05,                   K06,   K07,    K08, K09, K0A, KC_BSPC, \
    LCTL_T(KC_ESC), K11, K12, K13, K14,     K15,                   K16,   K17,    K18, K19, K1A, LALT_T(KC_QUOT), \
    KC_LSFT,        K21, K22, K23, K24,     K25,                   K26,   K27,    K28, K29, K2A, RSFT_T(KC_ENT), \
                                            LOWER,     KC_SPC,     RAISE                                     \
  )
#define LAYOUT_reviung_base_wrapper(...)       LAYOUT_reviung_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_reviung_base_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
  ),
  [_LOWER] = LAYOUT_reviung39_wrapper( 
    _______, _________________LOWER_L1__________________,                    _________________LOWER_R1__________________, KC_DEL,
    _______, _________________LOWER_L2__________________,                    _________________LOWER_R2__________________, KC_TILD,
    _______, _________________LOWER_L3__________________,                    _________________LOWER_R3__________________, _______,
                                                       _______, _______, _______
  ),
  [_RAISE] = LAYOUT_reviung39_wrapper(
    _______, _________________RAISE_L1__________________,                    _________________RAISE_R1__________________, KC_DEL,
    _______, _________________RAISE_L2__________________,                    _________________RAISE_R2__________________, _______,
    _______, _________________RAISE_L3__________________,                    _________________RAISE_R3__________________, _______,
                                                       _______, KC_TILD, _______
  ),
  [_ADJUST] = LAYOUT_reviung39_wrapper(
    KC_F1,   _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________, KC_F12,
    _______, _________________ADJUST_L2_________________,                    _________________ADJUST_R2_________________, _______,
    _______, _________________ADJUST_L3_________________,                    _________________ADJUST_R3_________________, _______,
                                                      _______, _______, _______
  )
};
// clang-format on
