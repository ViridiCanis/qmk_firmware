/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include "features/turbo_repeat.h"

// clang-format off
enum layers {
    BASE,
    EXTRA_SIMPLE,
    EXTRA_MACROS,
    MOUSE_MODE,
    FN
};

#define EXT_SMP EXTRA_SIMPLE
#define EXT_MCR EXTRA_MACROS

enum my_keycodes {
    MY_DELAY = SAFE_RANGE,
    EXTRA_SWITCH,
    TURBO_CLICK,
    TURBO_REPEAT,
    TURBO_REPEAT_SET
};

#define EXT_SWT EXTRA_SWITCH
#define TRB_CLK TURBO_CLICK
#define TRB_REP TURBO_REPEAT
#define TRB_SET TURBO_REPEAT_SET
#define MS_MD MOUSE_MODE

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define MT_CAPS MT(MOD_RSFT, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ansi_87(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_PSCR,   KC_CTANA, RGB_MOD,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,    KC_HOME,  KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,    KC_END,   KC_PGDN,
     EXT_SWT,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                      MT_CAPS,             KC_UP,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI,  OSL(FN),  KC_RCTL,  KC_LEFT,   KC_DOWN,  KC_RGHT),

[EXTRA_SIMPLE] = LAYOUT_ansi_87(
     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PSLS,  KC_PAST,  KC_PMNS,  KC_PPLS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  KC_P7,    KC_P8,    KC_P9,    KC_PDOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     _______,  _______,  _______,  _______,  KC_P4,    KC_P5,    KC_P6,    KC_P0,    XXXXXXX,  XXXXXXX,  TG(MS_MD),XXXXXXX,            XXXXXXX,
     _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P1,    KC_P2,    KC_P3,    KC_PENT,  KC_NUM,   XXXXXXX,  XXXXXXX,                      _______,            XXXXXXX,
     _______,  _______,  _______,                                XXXXXXX,                                _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX),

[EXTRA_MACROS] = LAYOUT_ansi_87(
     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  QK_LOCK,  _______,  XXXXXXX,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,            XXXXXXX,
     _______,  TRB_SET,  TRB_REP,  TRB_CLK,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,                      _______,            XXXXXXX,
     _______,  _______,  _______,                                XXXXXXX,                                _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX),

[MOUSE_MODE] = LAYOUT_ansi_87(
     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_WH_U,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     _______,  KC_BTN1,  KC_BTN2,  KC_BTN3,  KC_WH_D,  XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R, _______,  XXXXXXX,            XXXXXXX,
     _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______,            XXXXXXX,
     _______,  _______,  _______,                                XXXXXXX,                                _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX),

[FN] = LAYOUT_ansi_87(
     XXXXXXX,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            XXXXXXX,  XXXXXXX,  RGB_TOG,
     XXXXXXX,  BT_HST1,  BT_HST2,  BT_HST3,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
     _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BAT_LVL,  NK_TOGG,  XXXXXXX,  DM_REC1,  DM_PLY1,  MY_DELAY,                     _______,            XXXXXXX,
     _______,  _______,  _______,                                XXXXXXX,                                _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX),

// [x] = LAYOUT_ansi_87(
//      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
//      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,            _______,
//      _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______),
};

struct TurboRepeatState turbo_click_state;
struct TurboRepeatState turbo_repeat_state;

void keyboard_post_init_user(void) {
    turbo_click_state = create_state(KC_MS_BTN1);
    turbo_repeat_state = create_state(KC_A);
}

static bool extra_layer_macros;

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        extra_layer_macros = active;
    }

    return false; // override default functionality
}

static bool awaiting_turbo_repeat_set = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == EXTRA_SWITCH) {
        if (record->event.pressed) {
            layer_on(EXTRA_SIMPLE);
            if (extra_layer_macros) {
                layer_on(EXTRA_MACROS);
            }
        } else {
            layer_off(EXTRA_SIMPLE);
            layer_off(EXTRA_MACROS);
        }

        return false;
    }

    if (record->event.pressed && awaiting_turbo_repeat_set) {
        awaiting_turbo_repeat_set = false;
        unregister_code16(keycode);
        turbo_repeat_state.keycode_to_repeat = keycode;

        return false;
    }

    if (!process_turbo_repeat(keycode, record, &turbo_click_state, TURBO_CLICK)) {
        return false;
    }

    if (!process_turbo_repeat(keycode, record, &turbo_repeat_state, TURBO_REPEAT)) {
        return false;
    }

    switch (keycode) {
        case TURBO_REPEAT_SET:
            awaiting_turbo_repeat_set = true;

            return false;
        case MY_DELAY:
            if (record->event.pressed) {
                wait_ms(200);
            }

            return false;
    }

    return true;
}

bool dyn_macro_is_recording = false;

void dynamic_macro_record_start_user(void) {
    dyn_macro_is_recording = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
    dyn_macro_is_recording = false;
}

bool rgb_matrix_indicators_user(void) {
    if (layer_state_is(MOUSE_MODE)) {
        rgb_matrix_set_color(0x3c, 255, 0, 0);
    }
    if (dyn_macro_is_recording) {
        rgb_matrix_set_color(0x47, 255, 0, 0);
    }
    if (awaiting_turbo_repeat_set) {
        rgb_matrix_set_color(0x40, 255, 0, 0);
    }
    if (turbo_repeat_state.active) {
        rgb_matrix_set_color(0x41, 255, 0, 0);
    }
    if (turbo_click_state.active) {
        rgb_matrix_set_color(0x42, 255, 0, 0);
    }
    if (host_keyboard_led_state().num_lock) {
        rgb_matrix_set_color(0x47, 255, 0, 0);
    }

    return true;
}
