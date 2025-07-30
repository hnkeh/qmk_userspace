/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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

#define UC_AE UC(0x00E4)  // ä
#define UC_OE UC(0x00F6)  // ö
#define UC_AA UC(0x00E5)  // å

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYMBOLS,
    LAYER_MISC,
};

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
/** \brief QWERTY layout (3 rows, 10 columns). */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Layers used on the Dilemma.
 *
 * These layers started off heavily inspired by the Miryoku layout, but trimmed
 * down and tailored for a stock experience that is meant to be fundation for
 * further personalization.
 *
 * See https://github.com/manna-harbour/miryoku for the original layout.
 */
  [LAYER_BASE] = LAYOUT_split_3x5_3(
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_QUOT, KC_L,    KC_K,    KC_J,    KC_H,
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,
                      MT(MOD_LCTL,KC_TAB), LT(1,KC_SPC), KC_LGUI, LT(2,KC_ENT), MT(MOD_LALT,KC_BSPC), KC_LSFT
  ),

  [LAYER_SYMBOLS] = LAYOUT_split_3x5_3(
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_0,    KC_9,     KC_8,     KC_7,     KC_6,
       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_RPRN, KC_LPRN,  KC_ASTR,  KC_AMPR,  KC_CIRC,
       KC_UNDS, KC_PLUS, KC_MINS, KC_GRV,  KC_PIPE,  KC_RBRC, KC_LBRC,  S(KC_RBRC), S(KC_LBRC), KC_BSLS,
                      KC_NO, KC_NO, KC_TILD, KC_EQL, S(KC_SCLN), KC_SCLN
  ),

  [LAYER_MISC] = LAYOUT_split_3x5_3(
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    U_AA, U_OE, KC_UP,   KC_MUTE,  KC_F20,
       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   U_AE, KC_RGHT, KC_DOWN, KC_LEFT,  KC_HOME,
       KC_F11,  KC_F12,  KC_INS,  KC_DEL,  KC_END,   KC_ESC,  KC_VOLD, KC_VOLU, KC_MNXT,  KC_MPLY,
                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE
