#include "tapdance.h"
// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (!state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) return DOUBLE_TAP;
	else return 8;
}

// initialize tap structure asssociated with example tap key
static tap ql_tap_state = {
	.is_press_action = true,
	.state = 0
}; 

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
	ql_tap_state.state = cur_dance(state);
	switch (ql_tap_state.state) {
		case SINGLE_TAP:
			tap_code(KC_ENT);
			break;
		case SINGLE_HOLD:
			layer_on(_RAISE);
			break;
	}
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
	// If the key was held and is released then switch off the layer
	if (ql_tap_state.state == SINGLE_HOLD) {
		layer_off(_RAISE);
	}
	ql_tap_state.state = 0;
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	// single for slash double for enter
	[TD_EN_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_ENT),
	// single for semicolon double for single quote
	[TD_QUOT_SEM] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
	// tap for enter hold for raise
	[TD_RAIS_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
	// single for t double for esc
	[TD_ESC_T] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_ESC),
	// single for q double for tab
	[TD_TAB_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB),
};
