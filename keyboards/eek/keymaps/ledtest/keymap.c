/* Copyright 2020 klackygears
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
    _QUERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

/* #define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
 */
enum custom_keycodes {
  RGBRST = SAFE_RANGE
};


#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QUERTY] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         RGBRST,     RGB_HUI,    RGB_SAI,    RGB_VAI,    RGB_SPI,    \
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         RGB_MOD,    RGB_HUD,    RGB_SAD,    RGB_VAD,    RGB_SPD, \
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         RGB_TOG,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                      KC_LCTL, LOWER, KC_SPC,         KC_BSPC, RAISE, OSM(MOD_LSFT)                 \
  ),

  [_LOWER] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
    KC_ESC,  _______, _______, _______, _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, \
    KC_CAPS, KC_TILD, _______, _______, _______,      _______, _______, _______, KC_PIPE,  KC_DQT, \
                      _______, _______, _______,      KC_ENT,  _______, KC_DEL                    \
),

  [_RAISE] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
    KC_TAB,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
    KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, _______,      _______, _______, _______, KC_BSLS, KC_QUOT, \
                      _______, _______, _______,      _______, _______, _______                    \
  ),

  [_ADJUST] = LAYOUT(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  RGB_TOG,      _______,  KC_F9,  KC_F10, KC_F11, KC_F12,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, _______,      _______,  KC_F5,  KC_F6,  KC_F7,  KC_F8,
    _______,   _______, _______,  _______,  _______,      RESET,    KC_F1,  KC_F2,  KC_F3,  KC_F4,
                        _______,  _______,  _______,      _______,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
  }

  switch (keycode) {
   /*  case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false; */
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}
