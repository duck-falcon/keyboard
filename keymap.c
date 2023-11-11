/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
    TD_LCMD,
    TD_RCMD,
    TD_LCTL
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for command, twice for command + shift
    [TD_LCMD] = ACTION_TAP_DANCE_DOUBLE(KC_LCMD, LGUI(KC_LSFT)),
    // Tap once for command, twice for option
    [TD_RCMD] = ACTION_TAP_DANCE_DOUBLE(KC_RCMD, KC_LOPT),
    // Tap once for command, twice for shift + control(chrome のタブ切り替え用)
    [TD_LCTL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LSFT(KC_LCTL))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  TG(3),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, LSFT(KC_SCLN),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TG(2),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  TD(TD_LCTL),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          TD(TD_LCMD),   MT(MOD_LSFT,KC_LANGUAGE_2),  LT(1,KC_SPC),     LT(1,KC_ENT),  MT(MOD_RSFT,KC_LANGUAGE_1), TD(TD_RCMD)
                                      //`--------------------------'  `--------------------------'

  ),
// code 系
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_DLR,   KC_BSLS,    KC_PERC,    KC_NUHS,    KC_EXLM,    KC_AMPR,        KC_QUOT,    LSFT(KC_QUOT),    KC_UP,    RGUI(KC_UP),    XXXXXXX, KC_AT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_MINS, KC_EQL, KC_LPRN, KC_LBRC, KC_LCBR, KC_PLUS,                      KC_BSPC, KC_LEFT,   KC_DOWN,KC_RIGHT, XXXXXXX, KC_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_UNDS, XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, KC_PIPE,                      KC_SPC, RSFT(KC_SPC), RGUI(KC_DOWN), XXXXXXX , XXXXXXX, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
// number とか F12 とか
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX,   KC_F9, KC_F8,  KC_F7, KC_F10,                      XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_F6, KC_F5, KC_F4, KC_F11,                      XXXXXXX,  KC_4, KC_5, KC_6, XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TG(2), XXXXXXX, KC_F3, KC_F2, KC_F1, KC_F12,                      XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          TD(TD_LCMD),   KC_LSFT,  KC_SPC,     KC_ENT, KC_0, KC_0
                                      //`--------------------------'  `--------------------------'
  ),
// mouse 操作
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, TG(3),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_WH_R, KC_WH_U, KC_WH_L, LCTL(KC_LEFT),                      RCTL(KC_RIGHT), KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_WH_U, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_BTN2,     KC_BTN1, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};
