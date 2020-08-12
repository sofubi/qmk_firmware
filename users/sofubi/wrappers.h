#pragma once
#include "sofubi.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)
#define LAYOUT_reviung39_wrapper(...)   LAYOUT_reviung39(__VA_ARGS__)

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define ___________________BLANK___________________       _______, _______, _______, _______, _______

#define _____________________NO____________________       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO

#define _________________LOWER_L1__________________       KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________       KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS  
#define _________________LOWER_L3__________________       _____________________NO____________________

#define _________________LOWER_R1__________________       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN
#define _________________LOWER_R2__________________       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_GRV
#define _________________LOWER_R3__________________       KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_TILD

#define _________________RAISE_L1__________________       ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________       KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE
#define _________________RAISE_L3__________________       _____________________NO____________________

#define _________________RAISE_R1__________________       ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________       KC_NO, KC_4, KC_5, KC_6, KC_NO
#define _________________RAISE_R3__________________       KC_NO, KC_1, KC_2, KC_3, KC_NO

#define _________________ADJUST_L1_________________       KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6
#define _________________ADJUST_L2_________________       RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define _________________ADJUST_L3_________________       RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, KC_NO

#define _________________ADJUST_R1_________________       KC_F7,  KC_F8,   KC_F9, KC_F10, KC_F11
#define _________________ADJUST_R2_________________       QWERTY, COLEMAK, KC_NO, KC_NO,  KC_NO
#define _________________ADJUST_R3_________________       _____________________NO____________________

// clang-format on
