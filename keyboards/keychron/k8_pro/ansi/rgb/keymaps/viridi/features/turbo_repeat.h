#pragma once

#include "deferred_exec.h"
#include "quantum.h"

#ifdef __cplusplus
extern "C" {
#endif

struct TurboRepeatState {
    uint16_t keycode_to_repeat;

    bool active;

    bool           locked;
    bool           tapped;
    uint16_t       tap_timer;
    deferred_token repeat_token;
    bool           code_registered;
};

struct TurboRepeatState create_state(uint16_t keycode_to_repeat);

bool process_turbo_repeat(uint16_t keycode, keyrecord_t* record, struct TurboRepeatState* state, uint16_t turbo_repeat_keycode);

#ifdef __cplusplus
}
#endif
