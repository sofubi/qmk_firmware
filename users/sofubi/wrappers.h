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
#define LAYOUT_ferris_wrapper(...)      LAYOUT(__VA_ARGS__)
#define LAYOUT_reviung34_wrapper(...)   LAYOUT_reviung34(__VA_ARGS__)
#define LAYOUT_reviung39_wrapper(...)   LAYOUT_reviung39(__VA_ARGS__)

#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

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

#define _________________34_L1_____________________       KC_Q, KC_W, KC_E, KC_R, KC_T
#define _________________34_L2_____________________       LSFT_T(KC_A), LT(5, KC_S), LT(2, KC_D), LT(3, KC_F), KC_G
#define _________________34_L3_____________________       KC_Z, LCTL_T(KC_X), LGUI_T(KC_C), KC_V, KC_B

#define _________________34_R1_____________________       KC_Y, KC_U, KC_I, KC_O, KC_P
#define _________________34_R2_____________________       KC_H, LT(4, KC_J), LT(1, KC_K), LT(6, KC_L), LSFT_T(KC_SCLN)
#define _________________34_R3_____________________       KC_N, KC_M, LGUI_T(KC_COMM), LCTL_T(KC_DOT), KC_SLSH
 
#define _________________34_MOUSE_L1_______________       _______, KC_BTN1, KC_WH_U, KC_BTN2, _______
#define _________________34_MOUSE_L2_______________       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______
#define _________________34_MOUSE_L3_______________       _______, KC_WH_L, KC_WH_D, KC_WH_R, _______

#define _________________34_MOUSE_R1_______________       ___________________BLANK___________________
#define _________________34_MOUSE_R2_______________       _______, KC_BTN1, KC_NO, KC_BTN2, _______
#define _________________34_MOUSE_R3_______________       ___________________BLANK___________________
 
#define _________________34_NAV_L1_________________       ___________________BLANK___________________
#define _________________34_NAV_L2_________________       _______, KC_LALT, KC_NO, LCTL_T(KC_LGUI), _______
#define _________________34_NAV_L3_________________       ___________________BLANK___________________

#define _________________34_NAV_R1_________________       _______, _______, KC_PGUP, _______, _______
#define _________________34_NAV_R2_________________       KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______
#define _________________34_NAV_R3_________________       _______, KC_HOME, KC_PGDN, KC_END, _______

#define _________________34_RSYM_L1________________       ___________________BLANK___________________
#define _________________34_RSYM_L2________________       KC_CIRC, KC_ASTR, KC_AMPR, KC_NO, _______
#define _________________34_RSYM_L3________________       ___________________BLANK___________________
 
#define _________________34_RSYM_R1________________       _______, KC_UNDS, KC_PIPE, KC_QUOT, _______
#define _________________34_RSYM_R2________________       KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR
#define _________________34_RSYM_R3________________       _______, KC_MINS, KC_BSLS, KC_GRV, _______

#define _________________34_LSYM_L1________________       _______, KC_COLN, KC_LT, KC_GT, KC_SCLN
#define _________________34_LSYM_L2________________       KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT
#define _________________34_LSYM_L3________________       _______, KC_EXLM, KC_LBRC, KC_RBRC, _______
 
#define _________________34_LSYM_R1________________       ___________________BLANK___________________
#define _________________34_LSYM_R2________________       _______, KC_NO, KC_EQL, KC_PLUS, KC_PERC
#define _________________34_LSYM_R3________________       ___________________BLANK___________________

#define _________________34_FUNC_L1________________       ___________________BLANK___________________
#define _________________34_FUNC_L2________________       _______, KC_NO, LCTL(KC_LALT), _______, _______
#define _________________34_FUNC_L3________________       ___________________BLANK___________________
 
#define _________________34_FUNC_R1________________       _______, KC_F7, KC_F8, KC_F9, KC_F10
#define _________________34_FUNC_R2________________       _______, KC_F4, KC_F5, KC_F6, KC_F11
#define _________________34_FUNC_R3________________       _______, KC_F1, KC_F2, KC_F3, KC_F12 

#define _________________34_NUM_L1_________________       KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS
#define _________________34_NUM_L2_________________       KC_0, KC_4, KC_5, KC_6, KC_PMNS
#define _________________34_NUM_L3_________________       KC_PAST, KC_1, KC_2, KC_3, KC_PEQL

#define _________________34_NUM_R1_________________       ___________________BLANK___________________
#define _________________34_NUM_R2_________________       _______, _______, _______, KC_NO, _______
#define _________________34_NUM_R3_________________       ___________________BLANK___________________

#define _________________34_ALWAYS_L1______________       _______, _______, KC_COLN, KC_ESC, _______
#define _________________34_ALWAYS_L2______________       _______, KC_PERC, KC_SLSH, KC_ENT, _______
#define _________________34_ALWAYS_L3______________       _______, _______, _______, KC_EXLM, _______

#define _________________34_ALWAYS_R1______________       _______, _______, _______, _______, KC_DEL
#define _________________34_ALWAYS_R2______________       _______, KC_LGUI, _______, _______, _______
#define _________________34_ALWAYS_R3______________       _______, _______, RALT_T(KC_LT), RCTL_T(KC_GT), RESET
// clang-format on
