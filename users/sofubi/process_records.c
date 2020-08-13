#include "sofubi.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
	process_record_user_oled(keycode, record);
#endif
	return true;
}
