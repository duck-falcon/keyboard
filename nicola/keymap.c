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
#include "keymap.h"

/* -----------------
タップダンス 共通定義
--------------------*/

enum {
    TD_LCMD,
    TD_RCMD,
    TD_LCTL,
    TD_NICOLA_SHIFT,
    TD_NUMBER_SHIFT
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // シングルタップ command, ダブルタップ command + shift
    [TD_LCMD] = ACTION_TAP_DANCE_DOUBLE(KC_LCMD, LGUI(KC_LSFT)),
    // シングルタップ command, ダブルタップ option
    [TD_RCMD] = ACTION_TAP_DANCE_DOUBLE(KC_RCMD, KC_LOPT),
    // シングルタップ control, ダブルタップ shift + control(chrome のタブ切り替え用)
    [TD_LCTL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LSFT(KC_LCTL)),
    // tap で nicola layer change, 長押しで shift
    [TD_NICOLA_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nicola_shift_finished, td_layer_shift_reset),
    // tap で number layer change, 長押しで shift
    [TD_NUMBER_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_number_shift_finished, td_layer_shift_reset)
};


/* --------------------------------------------------
    親指シフト用, tap で layer change, 長押しで shift
    数字用,      tap で layer change, 長押して shift
-----------------------------------------------------*/ 
#define NICOLA_LAYER 4
#define NUMBER_LAYER 2

void td_nicola_shift_finished(tap_dance_state_t *state, void *user_data) {
  if (state->pressed) {
    register_mods(MOD_BIT(KC_LSFT)); // 長押しでシフトキーを登録
  } else {
    layer_invert(NICOLA_LAYER); // タップでレイヤーをトグル
    tap_code(KC_LANGUAGE_1); // かな入力にする
  }
}

void td_number_shift_finished(tap_dance_state_t *state, void *user_data) {
  if (state->pressed) {
    register_mods(MOD_BIT(KC_LSFT)); // 長押しでシフトキーを登録
  } else {
    layer_invert(NUMBER_LAYER); // タップでレイヤーをトグル
  }
}

void td_layer_shift_reset(tap_dance_state_t *state, void *user_data) {
  unregister_mods(MOD_BIT(KC_LSFT)); // シフトキーの登録を解除
}

/* ------------------------------------------------
Combo declaretions(同時押しでキー変更する), 親指シフト用
---------------------------------------------------*/
// 使わないであろうキーを親指シフトのシフトとする
#define NI_SHIFT_R KC_F19
#define NI_SHIFT_L KC_F18

enum custom_keycodes {
// 左
  NI_MARU = SAFE_RANGE,
  NI_KA,
  NI_TA,
  NI_KO,
  NI_SA,

  NI_U,
  NI_SHI,
  NI_TE,
  NI_KE,
  NI_SE,

  NI_HI,
  NI_SU,
  NI_HU,
  NI_HE,
  NI_CDOT,

// 左 + R-shift
  NI_GA,
  NI_DA,
  NI_GO,
  NI_ZA,

  NI_VU,
  NI_ZI,
  NI_DE,
  NI_GE,
  NI_ZE,

  NI_BI,
  NI_ZU,
  NI_BU,
  NI_BE,

// 左 + L-shift
  NI_LA,
  NI_E,
  NI_RI,
  NI_LYA,
  NI_RE,
  NI_WO,
  NI_A,
  NI_NA,
  NI_LYU,
  NI_MO,
  NI_LU,
  NI_HYPN,
  NI_RO,
  NI_YA,
  NI_LI,

// 右
NI_RA,
NI_TI,
NI_KU,
NI_TU,
NI_HA,
NI_TO,
NI_KI,
NI_I,
NI_NN,
NI_ME,
NI_SO,
NI_NE,
NI_HO,
NI_CMMA,
NI_TEN,

// 右 + L-shift
  NI_PA,
  NI_DI,
  NI_GU,
  NI_DU,
  NI_PI,
  NI_BA,
  NI_DO,
  NI_GI,
  NI_PO,
  NI_PU,
  NI_ZO,
  NI_PE,
  NI_BO,
  NI_LWA,

// 右 + R-shift
  NI_YO,
  NI_NI,
  NI_RU,
  NI_MA,
  NI_LE,
  NI_MI,
  NI_O,
  NI_NO,
  NI_LYO,
  NI_LTU,
  NI_NU,
  NI_YU,
  NI_MU,
  NI_WA,
  NI_LO,
};

// 左 + R-shift
const uint16_t PROGMEM cm_MARU[] = {NI_SHIFT_R, NI_MARU, COMBO_END};
const uint16_t PROGMEM cm_GA[] = {NI_SHIFT_R, NI_KA, COMBO_END};
const uint16_t PROGMEM cm_DA[] = {NI_SHIFT_R, NI_TA, COMBO_END};
const uint16_t PROGMEM cm_GO[] = {NI_SHIFT_R, NI_KO, COMBO_END};
const uint16_t PROGMEM cm_ZA[] = {NI_SHIFT_R, NI_SA, COMBO_END};

const uint16_t PROGMEM cm_VU[] = {NI_SHIFT_R, NI_U, COMBO_END};
const uint16_t PROGMEM cm_ZI[] = {NI_SHIFT_R, NI_SHI, COMBO_END};
const uint16_t PROGMEM cm_DE[] = {NI_SHIFT_R, NI_TE, COMBO_END};
const uint16_t PROGMEM cm_GE[] = {NI_SHIFT_R, NI_KE, COMBO_END};
const uint16_t PROGMEM cm_ZE[] = {NI_SHIFT_R, NI_SE, COMBO_END};

const uint16_t PROGMEM cm_BI[] = {NI_SHIFT_R, NI_HI, COMBO_END};
const uint16_t PROGMEM cm_ZU[] = {NI_SHIFT_R, NI_SU, COMBO_END};
const uint16_t PROGMEM cm_BU[] = {NI_SHIFT_R, NI_HU, COMBO_END};
const uint16_t PROGMEM cm_BE[] = {NI_SHIFT_R, NI_HE, COMBO_END};

// 左 + L-shift
const uint16_t PROGMEM cm_LA[] = {NI_SHIFT_L, NI_MARU, COMBO_END};
const uint16_t PROGMEM cm_E[] = {NI_SHIFT_L, NI_KA, COMBO_END};
const uint16_t PROGMEM cm_RI[] = {NI_SHIFT_L, NI_TA, COMBO_END};
const uint16_t PROGMEM cm_LYA[] = {NI_SHIFT_L, NI_KO, COMBO_END};
const uint16_t PROGMEM cm_RE[] = {NI_SHIFT_L, NI_SA, COMBO_END};
const uint16_t PROGMEM cm_WO[] = {NI_SHIFT_L, NI_U, COMBO_END};
const uint16_t PROGMEM cm_A[] = {NI_SHIFT_L, NI_SHI, COMBO_END};
const uint16_t PROGMEM cm_NA[] = {NI_SHIFT_L, NI_TE, COMBO_END};
const uint16_t PROGMEM cm_LYU[] = {NI_SHIFT_L, NI_KE, COMBO_END};
const uint16_t PROGMEM cm_MO[] = {NI_SHIFT_L, NI_SE, COMBO_END};
const uint16_t PROGMEM cm_LU[] = {NI_SHIFT_L, NI_CDOT, COMBO_END};
const uint16_t PROGMEM cm_HYPN[] = {NI_SHIFT_L, NI_HI, COMBO_END};
const uint16_t PROGMEM cm_RO[] = {NI_SHIFT_L, NI_SU, COMBO_END};
const uint16_t PROGMEM cm_YA[] = {NI_SHIFT_L, NI_HU, COMBO_END};
const uint16_t PROGMEM cm_LI[] = {NI_SHIFT_L, NI_HE, COMBO_END};

// 右 + L-shift
const uint16_t PROGMEM cm_PA[] = {NI_SHIFT_L, NI_RA, COMBO_END};
const uint16_t PROGMEM cm_DI[] = {NI_SHIFT_L, NI_TI, COMBO_END};
const uint16_t PROGMEM cm_GU[] = {NI_SHIFT_L, NI_KU, COMBO_END};
const uint16_t PROGMEM cm_DU[] = {NI_SHIFT_L, NI_TU, COMBO_END};
const uint16_t PROGMEM cm_PI[] = {NI_SHIFT_L, NI_CMMA, COMBO_END};
const uint16_t PROGMEM cm_BA[] = {NI_SHIFT_L, NI_HA, COMBO_END};
const uint16_t PROGMEM cm_DO[] = {NI_SHIFT_L, NI_TO, COMBO_END};
const uint16_t PROGMEM cm_GI[] = {NI_SHIFT_L, NI_KI, COMBO_END};
const uint16_t PROGMEM cm_PO[] = {NI_SHIFT_L, NI_I, COMBO_END};
const uint16_t PROGMEM cm_PU[] = {NI_SHIFT_L, NI_ME, COMBO_END};
const uint16_t PROGMEM cm_ZO[] = {NI_SHIFT_L, NI_SO, COMBO_END};
const uint16_t PROGMEM cm_PE[] = {NI_SHIFT_L, NI_NE, COMBO_END};
const uint16_t PROGMEM cm_BO[] = {NI_SHIFT_L, NI_HO, COMBO_END};
const uint16_t PROGMEM cm_LWA[] = {NI_SHIFT_L, NI_LI, COMBO_END};

// 右 + R-shift
const uint16_t PROGMEM cm_YO[] = {NI_SHIFT_R, NI_RA, COMBO_END};
const uint16_t PROGMEM cm_NI[] = {NI_SHIFT_R, NI_TI, COMBO_END};
const uint16_t PROGMEM cm_RU[] = {NI_SHIFT_R, NI_KU, COMBO_END};
const uint16_t PROGMEM cm_MA[] = {NI_SHIFT_R, NI_TU, COMBO_END};
const uint16_t PROGMEM cm_LE[] = {NI_SHIFT_R, NI_CMMA, COMBO_END};
const uint16_t PROGMEM cm_MI[] = {NI_SHIFT_R, NI_HA, COMBO_END};
const uint16_t PROGMEM cm_O[] = {NI_SHIFT_R, NI_TO, COMBO_END};
const uint16_t PROGMEM cm_NO[] = {NI_SHIFT_R, NI_KI, COMBO_END};
const uint16_t PROGMEM cm_LYO[] = {NI_SHIFT_R, NI_I, COMBO_END};
const uint16_t PROGMEM cm_LTU[] = {NI_SHIFT_R, NI_NN, COMBO_END};
const uint16_t PROGMEM cm_NU[] = {NI_SHIFT_R, NI_ME, COMBO_END};
const uint16_t PROGMEM cm_YU[] = {NI_SHIFT_R, NI_SO, COMBO_END};
const uint16_t PROGMEM cm_MU[] = {NI_SHIFT_R, NI_NE, COMBO_END};
const uint16_t PROGMEM cm_WA[] = {NI_SHIFT_R, NI_HO, COMBO_END};
const uint16_t PROGMEM cm_LO[] = {NI_SHIFT_R, NI_LI, COMBO_END};

combo_t key_combos[] = {
// 左 + R-shift
  COMBO(cm_MARU, NI_MARU),
  COMBO(cm_GA, NI_GA),
  COMBO(cm_DA, NI_DA),
  COMBO(cm_GO, NI_GO),
  COMBO(cm_ZA, NI_ZA),

  COMBO(cm_VU, NI_VU),
  COMBO(cm_ZI, NI_ZI),
  COMBO(cm_DE, NI_DE),
  COMBO(cm_GE, NI_GE),
  COMBO(cm_ZE, NI_ZE),

  /*COMBO(cm_Z, NI_NAI),*/
  COMBO(cm_BI, NI_BI),
  COMBO(cm_ZU, NI_ZU),
  COMBO(cm_BU, NI_BU),
  COMBO(cm_BE, NI_BE),

// 左 + L-shift
COMBO(cm_LA, NI_LA),
COMBO(cm_E, NI_E),
COMBO(cm_RI, NI_RI),
COMBO(cm_LYA, NI_LYA),
COMBO(cm_RE, NI_RE),
COMBO(cm_WO, NI_WO),
COMBO(cm_A, NI_A),
COMBO(cm_NA, NI_NA),
COMBO(cm_LYU, NI_LYU),
COMBO(cm_MO, NI_MO),
COMBO(cm_LU, NI_LU),
COMBO(cm_HYPN, NI_HYPN),
COMBO(cm_RO, NI_RO),
COMBO(cm_YA, NI_YA),
COMBO(cm_LI, NI_LI),

// 右 + L-shift
COMBO(cm_PA, NI_PA),
COMBO(cm_DI, NI_DI),
COMBO(cm_GU, NI_GU),
COMBO(cm_DU, NI_DU),
COMBO(cm_PI, NI_PI),
COMBO(cm_BA, NI_BA),
COMBO(cm_DO, NI_DO),
COMBO(cm_GI, NI_GI),
COMBO(cm_PO, NI_PO),
COMBO(cm_PU, NI_PU),
COMBO(cm_ZO, NI_ZO),
COMBO(cm_PE, NI_PE),
COMBO(cm_BO, NI_BO),
COMBO(cm_LWA, NI_LWA),

// 右 + R-shift
COMBO(cm_YO, NI_YO),
COMBO(cm_NI, NI_NI),
COMBO(cm_RU, NI_RU),
COMBO(cm_MA, NI_MA),
COMBO(cm_LE, NI_LE),
COMBO(cm_MI, NI_MI),
COMBO(cm_O, NI_O),
COMBO(cm_NO, NI_NO),
COMBO(cm_LYO, NI_LYO),
COMBO(cm_LTU, NI_LTU),
COMBO(cm_NU, NI_NU),
COMBO(cm_YU, NI_YU),
COMBO(cm_MU, NI_MU),
COMBO(cm_WA, NI_WA),
COMBO(cm_LO, NI_LO),
};

/* --------------------------------------
key が 押された時に毎回走る処理
親指シフト用 toggle layer 変更のオーバーライド
親指シフト用 shift + KC の処理
-----------------------------------------*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TG(2): // 数字からデフォルトに戻る
      if (record->event.pressed) {
        // デフォルトレイヤーに戻る時は "英数" にする
        tap_code(KC_LANGUAGE_2);
        // レイヤーをトグルする
        layer_invert(2);
      }
      return false;  // これ以上の処理は不要なので false を返す
    case TG(4): // 数字からnicolaに飛ぶ
      if (record->event.pressed) {
        // デフォルトレイヤーに戻る時は "かな" にする
        tap_code(KC_LANGUAGE_1);
        // レイヤーをトグルする
        layer_invert(2);
        layer_invert(4);
      }
      return false;  // これ以上の処理は不要なので false を返す
    case NI_SHIFT_R: // nicola からデフォルトに戻る
      if (record->event.pressed) {
        // デフォルトレイヤーに戻る時は "英数" にする
        tap_code(KC_LANGUAGE_2);
        // レイヤーをトグルする
        layer_invert(4);
      }
      return false;
    case NI_SHIFT_L: // nicola から数字に飛ぶ
      if (record->event.pressed) {
        // 数字レイヤーに戻る時は "英数" にする
        tap_code(KC_LANGUAGE_2);
        // レイヤーをトグルする
        layer_invert(4);
        layer_invert(2);
      }
      return false;
    // 左
    case NI_KA:
  if (record->event.pressed) {
    tap_code(KC_K);
    tap_code(KC_A);
  }
  return false;
case NI_TA:
  if (record->event.pressed) {
    tap_code(KC_T);
    tap_code(KC_A);
  }
  return false;
case NI_KO:
  if (record->event.pressed) {
    tap_code(KC_K);
    tap_code(KC_O);
  }
  return false;
case NI_SA:
  if (record->event.pressed) {
    tap_code(KC_S);
    tap_code(KC_A);
  }
  return false;
case NI_U:
  if (record->event.pressed) {
    tap_code(KC_U);
  }
  return false;
case NI_SHI:
  if (record->event.pressed) {
    tap_code(KC_S);
    tap_code(KC_H);
    tap_code(KC_I);
  }
  return false;
case NI_TE:
  if (record->event.pressed) {
    tap_code(KC_T);
    tap_code(KC_E);
  }
  return false;
case NI_KE:
  if (record->event.pressed) {
    tap_code(KC_K);
    tap_code(KC_E);
  }
  return false;
case NI_SE:
  if (record->event.pressed) {
    tap_code(KC_S);
    tap_code(KC_E);
  }
  return false;
case NI_HI:
  if (record->event.pressed) {
    tap_code(KC_H);
    tap_code(KC_I);
  }
  return false;
case NI_SU:
  if (record->event.pressed) {
    tap_code(KC_S);
    tap_code(KC_U);
  }
  return false;
case NI_HU:
  if (record->event.pressed) {
    tap_code(KC_H);
    tap_code(KC_U);
  }
  return false;
case NI_HE:
  if (record->event.pressed) {
    tap_code(KC_H);
    tap_code(KC_E);
  }
  return false;
case NI_CDOT:
  if (record->event.pressed) {
    tap_code(KC_SLSH);
  }
  return false;
    // 左 + R-shift
    case NI_MARU:
      if (record->event.pressed) {
        tap_code(KC_DOT); 
      }
      return false;
    case NI_GA:
      if (record->event.pressed) {
        tap_code(KC_G);
        tap_code(KC_A);
      }
      return false;
    case NI_DA:
      if (record->event.pressed) {
        tap_code(KC_D);
        tap_code(KC_A);
      }
      return false;
    case NI_GO:
      if (record->event.pressed) {
        tap_code(KC_G);
        tap_code(KC_O);
      }
      return false;
    case NI_ZA:
      if (record->event.pressed) {
        tap_code(KC_Z);
        tap_code(KC_A);
      }
      return false;

    case NI_VU:
      if (record->event.pressed) {
        tap_code(KC_V);
        tap_code(KC_U);
      }
      return false;  
    case NI_ZI:
      if (record->event.pressed) {
        tap_code(KC_Z);
        tap_code(KC_I);
      }
      return false;
    case NI_DE:
      if (record->event.pressed) {
        tap_code(KC_D);
        tap_code(KC_E);
      }
      return false;
    case NI_GE:
      if (record->event.pressed) {
        tap_code(KC_G);
        tap_code(KC_E);
      }
      return false;
    case NI_ZE:
      if (record->event.pressed) {
        tap_code(KC_Z);
        tap_code(KC_E);
      }
      return false;

    case NI_BI:
      if (record->event.pressed) {
        tap_code(KC_B);
        tap_code(KC_I);
      }
      return false;
    case NI_ZU:
      if (record->event.pressed) {
        tap_code(KC_Z);
        tap_code(KC_U);
      }
      return false;
    case NI_BU:
      if (record->event.pressed) {
        tap_code(KC_B);
        tap_code(KC_U);
      }
      return false;
    case NI_BE:
      if (record->event.pressed) {
        tap_code(KC_B);
        tap_code(KC_E);
      }
      return false;
// 左 + L-shift
    case NI_LA:
  if (record->event.pressed) {
    tap_code(KC_L);
    tap_code(KC_A);
  }
  return false;
case NI_E:
  if (record->event.pressed) {
    tap_code(KC_E);
  }
  return false;
case NI_RI:
  if (record->event.pressed) {
    tap_code(KC_R);
    tap_code(KC_I);
  }
  return false;
case NI_LYA:
  if (record->event.pressed) {
    tap_code(KC_L);
    tap_code(KC_Y);
    tap_code(KC_A);
  }
  return false;
case NI_RE:
  if (record->event.pressed) {
    tap_code(KC_R);
    tap_code(KC_E);
  }
  return false;
case NI_WO:
  if (record->event.pressed) {
    tap_code(KC_W);
    tap_code(KC_O);
  }
  return false;
case NI_A:
  if (record->event.pressed) {
    tap_code(KC_A);
  }
  return false;
case NI_NA:
  if (record->event.pressed) {
    tap_code(KC_N);
    tap_code(KC_A);
  }
  return false;
case NI_LYU:
  if (record->event.pressed) {
    tap_code(KC_L);
    tap_code(KC_Y);
    tap_code(KC_U);
  }
  return false;
case NI_MO:
  if (record->event.pressed) {
    tap_code(KC_M);
    tap_code(KC_O);
  }
  return false;
case NI_LU:
  if (record->event.pressed) {
    tap_code(KC_L);
    tap_code(KC_U);
  }
  return false;
case NI_HYPN:
  if (record->event.pressed) {
    tap_code(KC_SLSH);
  }
  return false;
case NI_RO:
  if (record->event.pressed) {
    tap_code(KC_R);
    tap_code(KC_O);
  }
  return false;
case NI_YA:
  if (record->event.pressed) {
    tap_code(KC_Y);
    tap_code(KC_A);
  }
  return false;
case NI_LI:
  if (record->event.pressed) {
    tap_code(KC_L);
    tap_code(KC_I);
  }
  return false;
case NI_TEN:
  if (record->event.pressed) {
    tap_code16(KC_AT);
  }
  return false;
    
// 右 + L-shift
  case NI_PA:
  if (record->event.pressed) {
    tap_code(KC_P);
    tap_code(KC_A);
  }
  return false;
case NI_DI:
  if (record->event.pressed) {
    tap_code(KC_D);
    tap_code(KC_I);
  }
  return false;
case NI_GU:
  if (record->event.pressed) {
    tap_code(KC_G);
    tap_code(KC_U);
  }
  return false;
case NI_DU:
  if (record->event.pressed) {
    tap_code(KC_D);
    tap_code(KC_U);
  }
  return false;
case NI_PI:
  if (record->event.pressed) {
    tap_code(KC_P);
    tap_code(KC_I);
  }
  return false;
case NI_BA:
  if (record->event.pressed) {
    tap_code(KC_B);
    tap_code(KC_A);
  }
  return false;
case NI_DO:
  if (record->event.pressed) {
    tap_code(KC_D);
    tap_code(KC_O);
  }
  return false;
case NI_GI:
  if (record->event.pressed) {
    tap_code(KC_G);
    tap_code(KC_I);
  }
  return false;
case NI_PO:
  if (record->event.pressed) {
    tap_code(KC_P);
    tap_code(KC_O);
  }
  return false;
case NI_PU:
  if (record->event.pressed) {
    tap_code(KC_P);
    tap_code(KC_U);
  }
  return false;
case NI_ZO:
  if (record->event.pressed) {
    tap_code(KC_Z);
    tap_code(KC_O);
  }
  return false;
case NI_PE:
  if (record->event.pressed) {
    tap_code(KC_P);
    tap_code(KC_E);
  }
  return false;
case NI_BO:
  if (record->event.pressed) {
    tap_code(KC_B);
    tap_code(KC_O);
  }
  return false;
case NI_LWA:
  if (record->event.pressed) {
    tap_code(KC_L);
    tap_code(KC_W);
    tap_code(KC_A);
  }
  return false;

// 右 + R-shift
case NI_YO:
  if (record->event.pressed) {
    tap_code(KC_Y);
    tap_code(KC_O);
  }
  return false;
case NI_NI:
  if (record->event.pressed) {
    tap_code(KC_N);
    tap_code(KC_I);
  }
  return false;
case NI_RU:
  if (record->event.pressed) {
    tap_code(KC_R);
    tap_code(KC_U);
  }
  return false;
case NI_MA:
  if (record->event.pressed) {
    tap_code(KC_M);
    tap_code(KC_A);
  }
  return false;
case NI_LE:
  if (record->event.pressed) {
    tap_code(KC_L);
    tap_code(KC_E);
  }
  return false;
case NI_MI:
  if (record->event.pressed) {
    tap_code(KC_M);
    tap_code(KC_I);
  }
  return false;
case NI_O:
  if (record->event.pressed) {
    tap_code(KC_O);
  }
  return false;
case NI_NO:
  if (record->event.pressed) {
    tap_code(KC_N);
    tap_code(KC_O);
  }
  return false;
case NI_LYO:
  if (record->event.pressed) {
    tap_code(KC_L);
    tap_code(KC_Y);
    tap_code(KC_O);
  }
  return false;
case NI_LTU:
  if (record->event.pressed) {
    tap_code(KC_L);
    tap_code(KC_T);
    tap_code(KC_U);
  }
  return false;
case NI_NU:
  if (record->event.pressed) {
    tap_code(KC_N);
    tap_code(KC_U);
  }
  return false;
case NI_YU:
  if (record->event.pressed) {
    tap_code(KC_Y);
    tap_code(KC_U);
  }
  return false;
case NI_MU:
  if (record->event.pressed) {
    tap_code(KC_M);
    tap_code(KC_U);
  }
  return false;
case NI_WA:
  if (record->event.pressed) {
    tap_code(KC_W);
    tap_code(KC_A);
  }
  return false;
case NI_LO:
  if (record->event.pressed) {
    tap_code(KC_L);
    tap_code(KC_O);
  }
  return false;

// 右
case NI_RA:
  if (record->event.pressed) {
    tap_code(KC_R);
    tap_code(KC_A);
  }
  return false;
case NI_TI:
  if (record->event.pressed) {
    tap_code(KC_T);
    tap_code(KC_I);
  }
  return false;
case NI_KU:
  if (record->event.pressed) {
    tap_code(KC_K);
    tap_code(KC_U);
  }
  return false;
case NI_TU:
  if (record->event.pressed) {
    tap_code(KC_T);
    tap_code(KC_U);
  }
  return false;
case NI_HA:
  if (record->event.pressed) {
    tap_code(KC_H);
    tap_code(KC_A);
  }
  return false;
case NI_TO:
  if (record->event.pressed) {
    tap_code(KC_T);
    tap_code(KC_O);
  }
  return false;
case NI_KI:
  if (record->event.pressed) {
    tap_code(KC_K);
    tap_code(KC_I);
  }
  return false;
case NI_I:
  if (record->event.pressed) {
    tap_code(KC_I);
  }
  return false;
case NI_NN:
  if (record->event.pressed) {
    tap_code(KC_N);
    tap_code(KC_N);
  }
  return false;
case NI_ME:
  if (record->event.pressed) {
    tap_code(KC_M);
    tap_code(KC_E);
  }
  return false;
case NI_SO:
  if (record->event.pressed) {
    tap_code(KC_S);
    tap_code(KC_O);
  }
  return false;
case NI_NE:
  if (record->event.pressed) {
    tap_code(KC_N);
    tap_code(KC_E);
  }
  return false;
case NI_HO:
  if (record->event.pressed) {
    tap_code(KC_H);
    tap_code(KC_O);
  }
  return false;

    // case TG(4):
    //   if (record->event.pressed) {
    //     // レイヤーをトグルする
    //     layer_invert(4);
    //     // デフォルトレイヤーに戻る時は "英数" にする
    //     tap_code(KC_LANGUAGE_2);
    //   }
    //   return false;  // これ以上の処理は不要なので false を返す
    default:
      return true;  // 他のキーコードには通常通り処理させる
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_AT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, LSFT(KC_SCLN),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TG(3),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  TD(TD_LCTL),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          TD(TD_LCMD),   TD(TD_NUMBER_SHIFT),  LT(1,KC_SPC),     LT(1,KC_ENT),  TD(TD_NICOLA_SHIFT), TD(TD_RCMD)
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
                                          XXXXXXX, XXXXXXX,  LGUI(KC_SPC),     RGUI(KC_SPC),   XXXXXXX, XXXXXXX
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
                                          TD(TD_LCMD),  TG(2) ,  KC_SPC,     KC_ENT, TG(4), KC_0
                                      //`--------------------------'  `--------------------------'
  ),
// mouse 操作
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, TG(3),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_WH_R, KC_WH_U, KC_WH_L, LCTL(KC_LEFT),                      RCTL(KC_RIGHT), KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TG(3), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_WH_U, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_BTN2,     KC_BTN1, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  // 親指シフト nicola 配列
      [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, NI_MARU, NI_KA, NI_TA, NI_KO, NI_SA,                            NI_RA,   NI_TI,    NI_KU,    NI_TU,   NI_CMMA, NI_TEN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, NI_U,    NI_SHI,  NI_TE,   NI_KE,   NI_SE,                        NI_HA,   NI_TO,    NI_KI,    NI_I,  NI_NN,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, NI_CDOT,  NI_HI,    NI_SU,   NI_HU,  NI_HE,                        NI_ME,   NI_SO, NI_NE,  NI_HO, NI_LI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, NI_SHIFT_L,  KC_SPC,     KC_ENT, NI_SHIFT_R, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};

