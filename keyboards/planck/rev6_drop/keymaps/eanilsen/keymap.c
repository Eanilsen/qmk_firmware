/* Eanilsen - QMK Planck setup */
/* Copyright (C) 2023 Even A. Nilsen */

/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/* (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#include QMK_KEYBOARD_H
#include "features/customkeys.h"
#include "features/swapper.h"
#include "features/select_word.h"
#include "features/custom_shift_keys.h"

#define SYMBOL OSL(_SYMBOL)
#define FUNCTION OSL(_FUNCTION)
#define NAV TO(_NAV)
#define HOME TO(_ISRT)
#define NUM TO(_NUM)
#define QWRT TO(_QWERTY)
/* #define MOD_SPC GUI_T(KC_SPC) // For DWM */
#define MOD_SPC MEH_T(KC_SPC)
#define MOD_ESC LGUI_T(KC_ESC)
#define BSP_DWRD LT(0,KC_BSPC)
#define LT_UP LT(0,KC_UP)
#define LT_LEFT LT(0,KC_LEFT)
#define SWAPPWIN_TAB LT(0,KC_TAB)
/* Home row mods */
#define HOME_S LGUI_T(KC_S)
#define HOME_R LALT_T(KC_R)
#define HOME_T LCTL_T(KC_T)
#define HOME_N RCTL_T(KC_N)
#define HOME_E RALT_T(KC_E)
#define HOME_A RGUI_T(KC_A)
#define HOME_P LT(_NUM,KC_P)
#define HOME_G LT(_NAV,KC_G)
#define N_TAB LCTL(KC_TAB)
#define P_TAB LSFT(LCTL(KC_TAB))
#define O_LSFT OSM(MOD_LSFT)
#define O_LCTL OSM(MOD_LCTL)
#define O_LGUI OSM(MOD_LGUI)
#define O_LALT OSM(MOD_LALT)
#define O_RSFT OSM(MOD_RSFT)
#define O_RCTL OSM(MOD_RCTL)
#define O_RGUI OSM(MOD_RGUI)
#define O_RALT OSM(MOD_RALT)

enum planck_layers {
  _ISRT,
  _SYMBOL,
  _FUNCTION,
  _NAV,
  _NUM,
  _QWERTY
};

const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOT, KC_EQL},
  {KC_COMM, KC_EXLM},
  {KC_QUOT, KC_QUES},
  {KC_SLSH, KC_BSLS},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
  sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ISRT] = LAYOUT_ortho_4x12(
    KC_TAB,   KC_Y,    KC_C,    KC_L,    KC_M,    KC_K,     KC_Z,     KC_F,     KC_U,    KC_COMM, KC_QUOT, KC_DEL,
    MOD_ESC,  KC_I,    HOME_S,  HOME_R,  HOME_T,  HOME_G,   HOME_P,   HOME_N,   HOME_E,  HOME_A,  KC_O,    KC_ENT,
    O_LSFT,  KC_Q,    KC_V,    KC_W,    KC_D,    KC_J,     KC_B,     KC_H,     KC_SLSH, KC_DOT,  KC_X,    O_RSFT,
    CW_TOGG,  O_LCTL,  O_LALT,  O_LGUI,  MOD_SPC, SYMBOL,   FUNCTION, BSP_DWRD, NAV,     O_LGUI,  KC_LEFT, KC_RGHT
    ),

  [_SYMBOL] = LAYOUT_ortho_4x12(
    KC_NO,   KC_EXLM, KC_LT,   KC_GT,   KC_PLUS, KC_NO, KC_NO, KC_UNDS, KC_PIPE, KC_TILD, KC_PERC, KC_DEL,
    KC_ESC,  KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT, ARROW, KC_AMPR, KC_ASTR, KC_DQUO, KC_DLR,  KC_ENT,
    O_LSFT, KC_COLN, KC_SCLN, KC_LBRC, KC_RBRC, KC_NO, KC_NO, KC_MINS, KC_HASH, GRAVE,   KC_CIRC, O_RSFT,
    QWRT,    O_LCTL, O_LALT, O_LGUI, MOD_SPC, KC_NO, HOME,  NUM,     KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

  [_NUM] = LAYOUT_ortho_4x12(
    KC_NO,  KC_SLSH, KC_1,    KC_2,    KC_3,    KC_PLUS, KC_NO, KC_NO,   KC_NO, KC_COMM,  KC_NO, KC_DEL,
    KC_ESC, KC_0,    KC_4,    KC_5,    KC_6,    KC_MINS, KC_NO, KC_NO,   KC_NO, KC_NO,    KC_NO, KC_ENT,
    KC_NO,  KC_ASTR, KC_7,    KC_8,    KC_9,    KC_EQL,  KC_NO, KC_NO,   KC_NO, KC_DOT,   KC_NO, O_RSFT,
    QWRT,   O_LCTL, O_LALT, O_LGUI, MOD_SPC, HOME,    KC_NO, KC_BSPC, KC_NO, KC_NO,    KC_NO, KC_NO
    ),

  [_FUNCTION] = LAYOUT_ortho_4x12(
    CG_TOGG,   KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, QK_BOOT,
    KC_NO,     KC_NO,   KC_F5,   KC_F6,   KC_F7,  KC_F8,  KC_NO,   CT_AE,   CT_OE,    CT_AA, KC_NO, KC_NO,
    O_LSFT,   KC_NO,   KC_F9,   KC_F10,  KC_F11, KC_F12, KC_NO,   SEL_WRD, SEL_SRCH, KC_NO, KC_NO, O_RSFT,
    KC_NO,     O_LCTL, O_LALT, O_LGUI, MOD_SPC, HOME,  KC_TRNS, O_RCTL, KC_NO,    KC_NO, KC_NO, KC_NO
    ),

  [_NAV] = LAYOUT_ortho_4x12(
    CLS_WIN, KC_WH_U, P_TAB,   KC_MS_U, N_TAB,   KC_H,  KC_MUTE, KC_VOLD, LT_UP,   KC_VOLU, CLS_WIN, KC_D,
    KC_ESC,  KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_G,  KC_BTN4, LT_LEFT, KC_DOWN, KC_RGHT, KC_BTN5, KC_ENT,
    KC_ENT,  SW_APP,  KC_S,    KC_D,    KC_F,    KC_F5, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PSCR, SW_APP,
    KC_D,    KC_COMM, KC_DOT,  KC_BTN3, KC_BTN1, HOME,  KC_NO,   KC_BTN2, KC_NO,   KC_NO,   KC_NO,   KC_F5
    ),

  [_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    O_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, O_RSFT,
    KC_D, O_LCTL, O_LALT, O_LGUI, KC_SPC,  HOME,    NUM,     KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    )
};

// Returns the value set by CG_TOGG
bool is_mac_the_default(void) { return keymap_config.swap_lctl_lgui; }
bool is_shift_held(void) { return (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT; }
bool is_ctrl_held(void) { return (get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL; }

void send_mac_or_win(uint16_t mac_code, uint16_t win_code, bool is_pressed)
{
  uint16_t code = is_mac_the_default() ? mac_code : win_code;
  if (is_pressed) {
    register_code16(code);
  } else {
    unregister_code16(code);
  }
}

void send_norwegian_letter(uint16_t keycode, uint16_t shifted_keycode, bool is_pressed)
{
  if (is_pressed) {
    const uint8_t mods = get_mods();

    if (is_mac_the_default()) SEND_STRING(SS_LCTL(SS_TAP(X_SPACE)) SS_DELAY(100));
    else SEND_STRING(SS_LCTL(SS_TAP(X_LSFT)) SS_DELAY(100));

    if (is_shift_held()) {
      del_mods(MOD_MASK_SHIFT);
      del_oneshot_mods(MOD_MASK_SHIFT);
      tap_code16(shifted_keycode);
    } else tap_code16(keycode);

    if (is_mac_the_default()) SEND_STRING(SS_LCTL(SS_TAP(X_SPACE)) SS_DELAY(100));
    else SEND_STRING(SS_LCTL(SS_TAP(X_LSFT)) SS_DELAY(100));

    set_mods(mods);
  }
}

bool sw_app_active = false;
bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  bool isPressed = record->event.pressed;
  bool isHeld = !record->tap.count && isPressed;
  const uint8_t mods = get_mods();

  {
    uint16_t mod = is_mac_the_default() ? KC_LGUI : KC_LALT;
    update_swapper(&sw_app_active, mod, KC_TAB, SW_APP, keycode, record);
  }
  update_swapper(&sw_win_active, KC_LGUI, KC_GRV, SW_WIN, keycode, record);

  if (!process_custom_shift_keys(keycode, record)) { return false; }
  if (!process_select_word(keycode, record, SEL_WRD, is_mac_the_default())) { return false; }

  switch (keycode) {
  case LT_LEFT:
    // Guard close returning true if the key is tapped,
    // meaning the rest of the code will only run when the
    // key is held.
    if (record->tap.count) return true;
    if (isHeld) register_code16(KC_BTN1);
    else unregister_code16(KC_BTN1);
    return false;
  case CT_AA:
    send_norwegian_letter(KC_LBRC, KC_LCBR, isPressed);
    return false;
  case CT_OE:
    send_norwegian_letter(KC_SCLN, KC_COLN, isPressed);
    return false;
  case CT_AE:
    send_norwegian_letter(KC_QUOT, KC_DQUO, isPressed);
    return false;
  case GRAVE:
    if (isPressed) {
      if (is_shift_held()) {
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        for (uint8_t i = 0; i < 3; i++) tap_code16(KC_GRV);
        set_mods(mods);
      } else {
        tap_code16(KC_GRV);
      }
    }
    return false;
  case SEL_SRCH:
    if (isPressed) {
      if (is_mac_the_default()) {
        SEND_STRING(SS_LGUI("ct") SS_DELAY(100) SS_LGUI("v") SS_TAP(X_ENTER));
      } else {
        SEND_STRING(SS_LCTL("ct") SS_DELAY(100) SS_LCTL("v") SS_TAP(X_ENTER));
      }
    }
    return false;
  case ARROW:
    if (isPressed) {
      if (is_shift_held()) {
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        SEND_STRING("=>");
        set_mods(mods);
      } else {
        SEND_STRING("->");
      }
    }
    return false;
  case KC_PSCR:
    send_mac_or_win(G(S(KC_4)), KC_PSCR, isPressed);
    return false;
  case LT_UP:
    if (isHeld) {
      tap_code16(C(KC_UP));
      return false;
    }
    return true;
  case LT(0,KC_BSLS):
    if (isHeld) {
      tap_code16(KC_HOME);
      return false;
    }
    return true;
  case BSP_DWRD:
    if (isHeld) {
      uint16_t code = is_mac_the_default() ? A(KC_BSPC) : C(KC_BSPC);
      tap_code16(code);
      return false;
    }
    return true;
  case LT(0,CT_PIPE):
    if (record->tap.count && isPressed) {
      tap_code16(S(KC_BSLS));
    } else if (isHeld) {
      tap_code16(KC_END);
    }
    return false;
  case MW_PSTE:
    send_mac_or_win(G(KC_V), C(KC_V), isPressed);
    return false;
  case MW_UNDO:
    send_mac_or_win(G(KC_Z), C(KC_Z), isPressed);
    return false;
  case MW_CUT:
    send_mac_or_win(G(KC_X), C(KC_X), isPressed);
    return false;
  case MW_COPY:
    send_mac_or_win(G(KC_C), C(KC_C), isPressed);
    return false;
  case CLS_WIN:
    send_mac_or_win(G(KC_W), C(KC_W), isPressed);
    return false;
  case MW_REDO:
    send_mac_or_win(G(S(KC_Z)), C(KC_Y), isPressed);
    return false;
  }
  return true;
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
  case HOME_R:
    return TAPPING_TERM + 200;
  case HOME_T:
    return TAPPING_TERM + 200;
  case HOME_N:
    return TAPPING_TERM + 200;
  case HOME_P:
    return TAPPING_TERM + 200;
  case HOME_G:
    return TAPPING_TERM + 200;
  case HOME_E:
    return TAPPING_TERM + 200;
  case HOME_S:
    return TAPPING_TERM + 200;
  case HOME_A:
    return TAPPING_TERM + 200;
  case LT_UP:
    return TAPPING_TERM + 200;
  case MOD_SPC:
    return TAPPING_TERM + 60;
  case MOD_ESC:
    return TAPPING_TERM + 60;
  case BSP_DWRD:
    return TAPPING_TERM + 60;
  default:
    return TAPPING_TERM;
  }
}
#endif
