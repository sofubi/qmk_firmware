#include QMK_KEYBOARD_H
#include "sofubi.h"

extern uint8_t is_master;

#define LAYOUT_crkbd_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_TAB,         K01, K02, K03, K04,     K05,                   K06,   K07,    K08, K09, K0A, KC_BSPC, \
    LCTL_T(KC_ESC), K11, K12, K13, K14,     K15,                   K16,   K17,    K18, K19, K1A, KC_QUOT, \
    KC_LSFT,        K21, K22, K23, K24,     K25,                   K26,   K27,    K28, K29, K2A, KC_RSFT, \
                                   KC_LGUI, LOWER, KC_ENT, KC_SPC, RAISE, KC_LALT                                     \
  )
#define LAYOUT_crkbd_base_wrapper(...)       LAYOUT_crkbd_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_crkbd_base_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
  ),
  [_LOWER] = LAYOUT_wrapper(
    _______, _________________LOWER_L1__________________,                    _________________LOWER_R1__________________, KC_DEL,
    _______, _________________LOWER_L2__________________,                    _________________LOWER_R2__________________, KC_TILD,
    _______, _________________LOWER_L3__________________,                    _________________LOWER_R3__________________, _______,
                                     _______, _______, _______,        _______, _______, _______
  ),
  [_RAISE] = LAYOUT_wrapper( \
    _______, _________________RAISE_L1__________________,                    _________________RAISE_R1__________________, KC_DEL,
    _______, _________________RAISE_L2__________________,                    _________________RAISE_R2__________________, _______,
    _______, _________________RAISE_L3__________________,                    _________________RAISE_R3__________________, _______,
                                     _______, _______, _______,        _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_wrapper( \
    KC_F1,   _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________, KC_F12,
    _______, _________________ADJUST_L2_________________,                    _________________ADJUST_R2_________________, _______,
    _______, _________________ADJUST_L3_________________,                    _________________ADJUST_R3_________________, _______,
                                     _______, _______, _______,        _______, _______, _______
  )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifndef SPLIT_KEYBOARD
        if (keycode == RESET && !is_master) {
            return false;
        }
#endif
    }
    return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#    ifndef SPLIT_KEYBOARD
    if (is_master) {
#    endif
        return OLED_ROTATION_180;
#    ifndef SPLIT_KEYBOARD
    }  else {
        return OLED_ROTATION_180;
    }
#    endif
}
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_T(KC_A):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}
