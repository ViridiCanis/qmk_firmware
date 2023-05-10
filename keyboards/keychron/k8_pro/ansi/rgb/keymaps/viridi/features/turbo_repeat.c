#include "features/turbo_repeat.h"
#include "deferred_exec.h"

#if !defined(DEFERRED_EXEC_ENABLE)
#    error "mouse_turbo_click: Please set `DEFERRED_EXEC_ENABLE = yes` in rules.mk."
#else

// Repeat period in ms-> 500ms -> 2/s, 100ms -> 10/s
#    ifndef TURBO_REPEAT_PERIOD
#        define TURBO_REPEAT_PERIOD 80
#    endif

struct TurboRepeatState create_state(uint16_t keycode_to_repeat) {
    struct TurboRepeatState state;

    state.keycode_to_repeat = keycode_to_repeat;
    state.locked            = false;
    state.tapped            = false;
    state.tap_timer         = 0;
    state.active            = false;
    state.repeat_token      = INVALID_DEFERRED_TOKEN;
    state.code_registered   = false;

    return state;
}

static uint32_t turbo_repeat_callback(uint32_t trigger_time, void* cb_arg) {
    struct TurboRepeatState* state = (struct TurboRepeatState*)cb_arg;

    if (state->code_registered) {
        unregister_code16(state->keycode_to_repeat);
        state->code_registered = false;
    } else {
        register_code16(state->keycode_to_repeat);
        state->code_registered = true;
    }

    // un-/register in half the period
    return TURBO_REPEAT_PERIOD / 2;
}

static void turbo_repeat_start(struct TurboRepeatState* state) {
    state->active = true;

    if (state->repeat_token == INVALID_DEFERRED_TOKEN) {
        uint32_t next_delay_ms = turbo_repeat_callback(0, state);
        state->repeat_token    = defer_exec(next_delay_ms, turbo_repeat_callback, state);
    }
}

static void turbo_repeat_stop(struct TurboRepeatState* state) {
    state->active = false;

    if (state->repeat_token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(state->repeat_token);
        state->repeat_token = INVALID_DEFERRED_TOKEN;

        if (state->code_registered) {
            unregister_code16(state->keycode_to_repeat);
            state->code_registered = false;
        }
    }
}

bool process_turbo_repeat(uint16_t keycode, keyrecord_t* record, struct TurboRepeatState* state, uint16_t turbo_repeat_keycode) {
    if (keycode != turbo_repeat_keycode) {
        state->tapped = false;
        return true;
    }

    if (record->event.pressed) {
        if (state->tapped && !timer_expired(record->event.time, state->tap_timer)) {
            state->locked = true;
        } else if (state->locked) {
            state->locked = false;
            state->tapped = false;
            turbo_repeat_stop(state);
            return false;
        }

        state->tapped    = true;
        state->tap_timer = record->event.time + TAPPING_TERM;

        turbo_repeat_start(state);
    } else if (!state->locked) {
        turbo_repeat_stop(state);
    }

    return false;
}

#endif
