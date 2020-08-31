/*
 * wenlong xiong
 * wenlongx@gmail.com
 */

#include QMK_KEYBOARD_H

#define _LA 0
#define _LB 1
#define _LC 2
#define _LD 3

enum custom_keycodes {
    SUDOBB = SAFE_RANGE,
    TMUX_A,
    TMUX_B,
    TMUX_C,
    TMUX_D,
    TMUX_S,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SUDOBB:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("sudo !!"SS_TAP(X_ENTER));
        } else {
            // when keycode is released
        }
        break;

    case TMUX_A:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("tmux new-session -A -s session_a"SS_TAP(X_ENTER));
        } else {
            // when keycode is released
        }
        break;

    case TMUX_B:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("tmux new-session -A -s session_b"SS_TAP(X_ENTER));
        } else {
            // when keycode is released
        }
        break;

    case TMUX_C:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("tmux new-session -A -s session_c"SS_TAP(X_ENTER));
        } else {
            // when keycode is released
        }
        break;

    case TMUX_D:
        if (record->event.pressed) {
            // when keycode is pressed
            // Ctrl+B D
            SEND_STRING(SS_LCTL("b")SS_DELAY(50)"d");
        } else {
            // when keycode is released
        }
        break;

    case TMUX_S:
        if (record->event.pressed) {
            // when keycode is pressed
            // Ctrl+B []
            SEND_STRING(SS_LCTL("b")SS_DELAY(50)SS_TAP(X_LBRACKET));
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _LA: Default Layer (layer A)
     * ,----------------------------------------------------------------.
     * |Esc`| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | V+ |
     * |----------------------------------------------------------------|
     * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return | V- |
     * |----------------------------------------------------------------|
     * |Shift (|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift )| Up| Mut|
     * |----------------------------------------------------------------|
     * |Ctrl|Alt |Cmd |        Space          |MO1|MO2|MO3|Lef|Dow|Rig |
     * `----------------------------------------------------------------'
     */
  [_LA] = LAYOUT_65_ansi(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,  KC__VOLUP,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,   KC__VOLDOWN,
      KC_LSPO,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSPC, KC_UP,    KC__MUTE,
      KC_LCTL, KC_LALT, KC_LCMD,                          KC_SPC,                 MO(_LB), MO(_LC), KC_MPLY,  KC_LEFT, KC_DOWN,  KC_RIGHT
  ),

// 15 / 15 / 14 / 14 / 10


  /* Keymap _LB: Layer B
   * ,----------------------------------------------------------------.
   * |~ `| F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |    |
   * |----------------------------------------------------------------|
   * |     |   |M^ |   |   |   |   |   |   |   |*3 |*5 |   |     |Prev|
   * |----------------------------------------------------------------|
   * |      |M< |Mv |M> |   |   |   |   |   |*3 |*4 |*5 |        |Next|
   * |----------------------------------------------------------------|
   * |   {  |   |   |   |   |   |   |   |    |    |    |  }  |*1 |Paus|
   * |----------------------------------------------------------------|
   * |RCtrl|RAlt|RCmd|                       |   |   |   |   |*2 |    |
   * `----------------------------------------------------------------'
   * *1 - screen brightness up
   * *2 - screen brightness down
   * *3 - mouse button 1
   * *4 - mouse button 2
   * *5 - mouse button 3
   */
  [_LB] = LAYOUT_65_ansi(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______,
      KC_HOME, _______, KC_MS_U, _______, _______, _______, _______, _______,   _______, _______, KC_BTN1, KC_BTN3, _______,  KC_END, KC_MPRV,
      _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______,   _______, KC_BTN1, KC_BTN2, KC_BTN3,          _______, KC_MNXT,
      KC_LCBR,          _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_RCBR, KC_BRMU, KC_MPLY,
      KC_RCTL, KC_RALT, KC_RCMD,                             KC_UNDS,                    _______, _______, _______, _______, KC_BRMD, _______
  ),

  /* Keymap _LC: Default Layer (layer c)
   * ,----------------------------------------------------------------.
   * |    |   |   |   |   |   |   |   |   |   |   |   |   |      |    |
   * |----------------------------------------------------------------|
   * |     |   |*1 |   |   |   |   |   |   |   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |       |*2 |*3 |*4 |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |   <   |   |   |   |   |   |   |   |*5 |*6 |*7 |   >   |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   * *1: scroll up
   * *2: scroll left
   * *3: scroll down
   * *4: scroll right
   * *5: mouse accel 0
   * *6: mouse accel 1
   * *7: mouse accel 3
   */

  [_LC] = LAYOUT_65_ansi(
       TMUX_D,  TMUX_A,  TMUX_B,  TMUX_C, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,  SUDOBB,
      KC_HOME, _______, KC_WH_U, _______,   RESET, _______, _______, _______,   _______, _______, _______,  TMUX_S, _______,  KC_END, _______,
      _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, _______, _______,   _______, _______, _______, _______,          _______, _______,
      KC_LABK,          _______, _______, _______, _______, _______, _______,   _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_RABK, _______, _______,
      _______, _______, _______,                             _______,                    _______, _______, _______, _______, _______, _______
  ),

  [_LD] = LAYOUT_65_ansi(
     /* esc      1        2        3        4       5       6       7       8       9         0        -         =     bkspc       `~  */
      _______, _______, _______, _______, _______,_______,_______,_______,_______,_______, _______, _______,  _______, _______,  _______,
     /*  tab      Q       W        E        R        T      Y        U      I        O        P        [         ]        \      delete*/
      _______, _______, _______, _______, _______,_______,_______,_______,_______,_______, _______, _______,  _______, _______,  _______,
     /*  caps     A       S        D        F        G      H        J      K        L        ;        '       enter              pg up*/
      _______, _______, _______, _______, _______,_______,_______,_______,_______,_______, _______, _______,  _______,           _______,
     /* shift             Z         X        C       V       B       N      M        ,        .        /        shift     up      pg dn*/
      _______,          _______, _______, _______,_______,_______,_______,_______,_______, _______, _______,  _______, _______,  _______,
     /* ctrl     win      alt                              space                    alt      fn       ctrl      left     down     right*/
      _______, _______, _______,                          _______,                _______, _______, _______,  _______, _______,  _______
  )

};
