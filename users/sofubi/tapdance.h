#pragma once
#include "sofubi.h"

#ifdef TAP_DANCE_ENABLE
typedef struct {
	bool is_press_action;
	uint8_t state;
} tap;

// Function to be associated with all dances
uint8_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individiual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

// define a type for as many tap dance states as needed
enum {
	SINGLE_TAP = 1,
	SINGLE_HOLD,
	DOUBLE_TAP
};
// defin tap dances
enum {
	TD_ESC_T,
	TD_EN_SLSH,
	TD_QUOT_SEM,
	TD_RAIS_ENT,
	TD_TAB_Q,
};
#endif
