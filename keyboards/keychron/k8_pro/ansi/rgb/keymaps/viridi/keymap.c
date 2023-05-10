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

#include "features/mouse_turbo_click.h"

// clang-format off
enum layers {
    BASE,
    FN,
    EXTRA
};

enum my_keycodes {
    MY_DELAY = SAFE_RANGE,
    TURBO,
    R_CHAT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ansi_87(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_PSCR,   KC_CTANA, RGB_MOD,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,    KC_HOME,  KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,    KC_END,   KC_PGDN,
     MO(EXTRA),KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,      MT(MOD_RSFT, KC_CAPS),     KC_UP,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI,  MO(FN),   KC_RCTL,  KC_LEFT,   KC_DOWN,  KC_RGHT),

[FN] = LAYOUT_ansi_87(
     _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            _______,  _______,  RGB_TOG,
     _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  DM_REC1,  DM_PLY1,  MY_DELAY,           _______,            _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______),

[EXTRA] = LAYOUT_ansi_87(
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  QK_LOCK,  _______,  _______,  R_CHAT,   TURBO,    _______,  _______,  KC_KP_7,  KC_KP_8,  KC_KP_9,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_NUM,             _______,
     _______,            _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_0,  KC_KP_1,  KC_KP_2,  KC_KP_3,            _______,            _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______),

// [x] = LAYOUT_ansi_87(
//      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
//      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
//      _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______),
};

bool f13_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_mouse_turbo_click(keycode, record, TURBO)) {
        return false;
    }

    switch (keycode) {
        case MY_DELAY:
            if (record->event.pressed) {
                wait_ms(200);
            }

            return false;
        case R_CHAT:
            // i don't know where the pressed GUI mod comes from, but it's there
            unregister_code(KC_LGUI);

            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(20));

                if (get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("r?");
                    register_code(KC_LEFT_SHIFT);
                } else {
                    SEND_STRING("r");
                }

                SEND_STRING(SS_DELAY(20) SS_TAP(X_ENTER));
            }

            return false;
    }

    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        default_layer_set(BASE);
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
    if (dyn_macro_is_recording) {
        rgb_matrix_set_color(0x47, 255, 0, 0);
    }
    if (turbo_click_active) {
        rgb_matrix_set_color(0x26, 255, 0, 0);
    }
    if (host_keyboard_led_state().num_lock) {
        rgb_matrix_set_color(0x3d, 255, 0, 0);
    }

    return true;
}
