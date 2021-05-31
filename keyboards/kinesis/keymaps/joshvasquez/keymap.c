#include QMK_KEYBOARD_H

#define QWERTY 0 // Base qwerty
#define GAMING 1
#define SYMBOL 2
#define MMEDIA 3
#define SHIFTD 4 // shift layer, rather than using the shift modifier allows for specific changes to ANSI shifted keys.  
#define NUMBER 5

const uint16_t PROGMEM bspc_combo[] = {KC_DOT, KC_COMM, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(bspc_combo, KC_BSPC)};


/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS | GAME |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* |MEH/Tab |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |HYPR/esc|   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   |  ~   | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Gui  | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Ctrl |------|         |------|Return| Space|
*                                 |      | F17  | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

#define MT_ESC HYPR_T(KC_ESC)
#define MT_QUOT HYPR_T(KC_QUOT)
#define MT_TAB MEH_T(KC_TAB)
#define LCTL17 LCTL_T(KC_F17)
#define CST_Z  C_S_T(KC_Z)
#define ALTESC LALT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT(
           KC_CAPS, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           MT_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           MT_ESC,C_S_T(KC_A),KC_S,KC_D,KC_F ,KC_G   ,
           KC_LSFT,SFT_T(KC_Z)  ,LGUI_T(KC_X)   ,LALT_T(KC_C)   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_TILD,KC_LEFT,KC_RGHT,
			   KC_LGUI,KC_LALT,
                                    KC_HOME,
                           LT(MMEDIA,KC_BSPC), LCTL17 ,LCA_T(KC_F17),
    KC_F9,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR   ,KC_VOLU  ,KC_VOLD, TG(GAMING), RESET,
	KC_6 ,KC_7   ,KC_8   ,KC_9   ,KC_0      ,KC_MINS,
	KC_Y ,KC_U   ,KC_I   ,KC_O   ,KC_P      ,KC_BSLS,
	KC_H ,KC_J,KC_K,KC_L,KC_SCLN,MT_QUOT,
	KC_N ,KC_M   ,LALT_T(KC_COMM),LGUI_T(KC_DOT) ,SFT_T(KC_SLSH)   ,KC_RSFT,
		KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,LT(SYMBOL,KC_ENTER ),KC_SPC
    ),
/****************************************************************************************************
*
* Keymap: Gaming Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* |  Tab   |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Alt/Esc|   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   |  ~   | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Gui  | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Ctrl |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/
[GAMING] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           ALTESC, KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_TILD ,KC_LEFT,KC_RGHT,
			   KC_LCTL,KC_LALT,
                                    KC_HOME,
                           KC_BSPC,KC_LCTL ,KC_END ,
    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, _______, RESET,
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
		KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    ), 
/****************************************************************************************************
*
* Keymap: Symbol Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Alt/Esc|   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   |  ~   | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Gui  | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | Space| Ctrl |------|         |------|Return| BkSp |
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/
[SYMBOL] = LAYOUT(
         _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,
         _______,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
         _______,  _______,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
         _______,  _______,   KC_DLR,  KC_PERC,  KC_CIRC,  _______,
         _______,  _______,  KC_EXLM,    KC_AT,  KC_HASH,  _______,
                   _______,  _______,  _______,  _______,
                             _______,  _______,
                                       _______,
                    _______, _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,
         _______,  _______,  _______,  _______,  _______,  _______,
            KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  _______,
         _______,     KC_4,     KC_5,     KC_6,  _______,  _______,
         _______,     KC_1,     KC_2,     KC_3,  _______,  _______,
                      KC_0,  _______,  _______,  _______,
         _______,  _______,
         _______,
         _______,  XXXXXXX, KC_RSHIFT 
    ),
[MMEDIA] = LAYOUT(
         _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,
         _______,  _______,  _______,  _______,  _______,  _______,
         _______,  KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC,
         _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,
         _______,  _______,  _______,  _______,  _______,  _______,
                   _______,  _______,  _______,  _______,
                             _______,  _______,
                                       _______,
                    _______, _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,
         _______,  _______,  _______,  _______,  _______,  _______,
         KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
         KC_LEFT,  KC_DOWN,  KC_UP  , KC_RIGHT,  KC_MUTE,  KC_VOLU,  
         _______,  _______,  _______,  _______,  _______,  KC_VOLD,
                   _______,  _______,  _______,  _______,
         _______,  _______,
         _______,
         _______,  _______,  _______
    ), 

};

/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           KC_CAPS,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT,KC_RGHT,
			   KC_LCTL,KC_LALT,
                                    KC_HOME,
                           KC_BSPC,KC_DEL ,KC_END ,
    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
		KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    )
};
 * */
void matrix_init_user(void) {

}

#define ledTurnOff palSetLine
#define ledTurnOn palClearLine

#define LED_KEYPAD LINE_PIN24
#define LED_SCROLL_LOCK LINE_PIN25
#define LED_NUM_LOCK LINE_PIN26
#define LED_CAPS_LOCK LINE_PIN12

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case QWERTY:
        break;
    case GAMING:
        break;
    case SYMBOL:
        break;
    case MMEDIA:
            break;
    default: //  for any other layers, or the default layer
        break;
    }
  return state;
}


void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
