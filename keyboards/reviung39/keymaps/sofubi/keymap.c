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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum {
    TD_SQUO_DQUO = 0,
    TD_SPC_ENT = 1,
    TD_SCLN_COL = 2,
    TD_SLSH_QUES = 3,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SQUO_DQUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TD_SCLN_COL] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_SLSH_QUES] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_QUES),
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung39(
    KC_TAB,          KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,            KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,             KC_BSPC,
    LCTL_T(KC_ESC),  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,            KC_H,  KC_J,  KC_K,     KC_L,    TD(TD_SCLN_COL),  TD(TD_SQUO_DQUO),
    LSFT_T(KC_DOT),  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,            KC_N,  KC_M,  KC_COMM,  KC_DOT,  TD(TD_SLSH_QUES), RSFT_T(KC_ENT),
                                                 LOWER,  KC_SPC,  RAISE
  ),

  [_LOWER] = LAYOUT_reviung39(
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_GRV,   KC_TILD,
    _______,  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_NO,     KC_GRV,             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PSCR,  RSFT_T(KC_DOT),
                                                       _______,  KC_TILD,   _______
  ),

  [_RAISE] = LAYOUT_reviung39(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_NO,    KC_4,     KC_5,     KC_6,     KC_NO,    KC_NO,
    _______,  KC_LCTL,  KC_RGUI,  KC_RALT,  KC_LPRN,   KC_RPRN,            KC_NO,    KC_1,     KC_2,     KC_3,     KC_NO,    KC_F12,
                                                       _______,  KC_TILD,  _______

  ),

  [_ADJUST] = LAYOUT_reviung39(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  _______,  _______,  _______,  _______,  RESET,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,
                                                       _______,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};
