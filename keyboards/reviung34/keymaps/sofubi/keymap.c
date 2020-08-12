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
#include QMK_KEYBOARD_H
#include "sofubi.h"

enum layer_names {
    _BASE
};

#define T_ESC TD(TD_ESC_T)
#define CT_A  LCTL_T(KC_A)
#define SF_Z  LSFT_T(KC_Z)
#define AL_X  LALT_T(KC_X)
#define RA_EN TD(TD_RAIS_ENT)
#define SEM_Q TD(TD_QUOT_SEM)
#define SL_RS RSFT_T(KC_SLSH)
#define Q_TB TD(TD_TAB_Q)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung34(
    Q_TB,     KC_W,     KC_E,     KC_R,     T_ESC,				KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    CT_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     SEM_Q,
    SF_Z,     AL_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   SL_RS,
                        KC_LGUI,  LOWER,    RA_EN,              KC_SPC
  ),
  
  [_LOWER] = LAYOUT_reviung34(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_GRV,
    KC_LSFT,  KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,
                        _______,  _______,  _______,            KC_BSPC
  ),
	
	[_RAISE] = LAYOUT_reviung34(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,            XXXXXXX,  KC_4,     KC_5,     KC_6,     KC_TILD,
    KC_LSFT,  KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_1,     KC_2,     KC_3,     XXXXXXX,
                        _______,  _______,  _______,            KC_BSPC
  ),
  
  [_ADJUST] = LAYOUT_reviung34(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_F7,    KC_F7,    KC_F8,    KC_F9,    KC_F10,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,  KC_PSCR,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                        _______,  _______,  _______,            XXXXXXX
  ),
};
