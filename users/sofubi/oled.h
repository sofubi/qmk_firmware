#pragma once

#include "quantum.h"
#include "oled_driver.h"

bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);

#    define IDLE_FRAMES 4
#    define IDLE_SPEED 40
#    define TAP_FRAMES 2
#    define TAP_SPEED 60
#    define ANIM_FRAME_DURATION 200
#    define ANIM_SIZE 636
#    define OLED_RENDER_KEYLOGGER "Keys:"
#    define OLED_RENDER_LAYOUT_NAME "Lyout"
#    define OLED_RENDER_LAYOUT_QWERTY  " QRTY"
#    define OLED_RENDER_LAYOUT_COLEMAK " COLE"
#    define OLED_RENDER_LAYER_NAME   "Layer"
#    define OLED_RENDER_LAYER_LOWER  " Lwer"
#    define OLED_RENDER_LAYER_RAISE  " Rais"
#    define OLED_RENDER_LAYER_ADJUST " Adjs"
#    define OLED_RENDER_LAYER_DEFAULT " Dflt"
