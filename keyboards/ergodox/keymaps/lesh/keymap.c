#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define CTLL 3 // experimental

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_DELT,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
        KC_RCTRL,       KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_DELT,
        LT(SYMB,KC_GRV),KC_ESC,      LALT(KC_LSFT),  KC_UP,  KC_DOWN,
        
                                              KC_LGUI,  KC_LGUI, KC_PGUP,
                                      KC_SPC, MO(SYMB), LT(SYMB,KC_PGDN),
        // right hand
             KC_BSPC,     KC_6,   KC_7,   KC_8,    KC_9,          KC_0,              KC_MINS,
             TG(SYMB),    KC_Y,   KC_U,   KC_I,    KC_O,          KC_P,              KC_BSLS,
                          KC_H,   KC_J,   KC_K,    KC_L,          LT(MDIA, KC_SCLN), KC_ESC,
             KC_BSPC     ,KC_N,   KC_M,   KC_COMM, KC_DOT,        LT(MDIA, KC_SLSH), KC_QUOT,
        
                                  KC_LEFT, KC_RGHT,LALT(KC_LSFT), KC_RBRC,   LT(SYMB,KC_GRV),
        
             KC_LALT,  CTL_T(KC_ESC),
             KC_ESC,
             KC_ESC,

             KC_LGUI, KC_ENT
    ),
/* Keymap 1: Symbol Layer
` *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// SYMBOLS
[SYMB] = KEYMAP(
       // left hand 
       KC_TILD,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  RESET,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LPRN,M(1),KC_RPRN,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LBRC,M(2),KC_RBRC,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LCBR,M(3),KC_RCBR,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_PGUP,KC_PGDN,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_1,   KC_2,    KC_3,    KC_ASTR, KC_F12,
                KC_F9,   KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_7,   KC_8,    KC_9,    KC_BSLS, M(4),
                         KC_HOME,KC_END,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),



// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_BTN2, KC_MS_U, KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, 
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),


// EXPERIMENTAL
[CTLL] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};


/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

const uint16_t PROGMEM fn_actions[] = {
	[1] = ACTION_FUNCTION(1)
    //    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)

};


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
    case 1:
      if (record->event.pressed) {
          layer_on(CTLL);
          add_key(KC_LCTL);
          send_keyboard_report();
      } else {
          layer_off(CTLL);
          del_key(KC_LCTL);
          send_keyboard_report();
      }
      break;
    }
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        
        case 1:
        if (record->event.pressed) {
          return MACRODOWN(D(LSHIFT), T(LPRN), T(RPRN), U(LSHIFT), T(LEFT) ,END);
        }
        break;
        
        case 2:
        if (record->event.pressed) {
          return MACRO(T(LCBR), T(SPC), T(SPC), T(RCBR), T(LEFT), T(LEFT) ,END);
        }
        break;
        
        case 3:
        if (record->event.pressed) {
          return MACRODOWN(D(LSHIFT), T(LBRC), T(SPC), T(SPC), T(RBRC), U(LSHIFT), T(LEFT), T(LEFT) ,END);
        }
        break;
        
        case 4:
        if (record->event.pressed) {
          return MACRO(T(QUOT), T(QUOT), U(RSHIFT), U(LSHIFT), T(LEFT), END);
        }
        break;
        
        case 99:
        if (record->event.pressed) {
          SEND_STRING ("YOLO BURRITO HA HA HA HA");
        }
        break;
        
        case 98:
        if (record->event.pressed) {
          return MACRO(D(LCTL), END);
        } else {
          return MACRO(U(LCTL), END);
        }
        break;
        
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};
uint16_t cnt = 0;
uint16_t cntCompare = 10;

uint8_t led = 2;

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  cnt++;
  
  uint8_t layer = biton32(layer_state);
  
  bool ledState[ 3 ] = { false, false, false};
  
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
    
  if (cnt > cntCompare) {
    if (cntCompare < 500) {
      cntCompare += cntCompare / 10;
      if (cntCompare > 500) { cntCompare = 500; } 
    }
    cnt = 0;
    led++;
    if (led == 3) { led = 0; }
  }
  
  if (cnt == 0) { ledState[ led ] = true; }
  
  ledState[layer - 1] = !ledState[layer - 1];
  
  if (ledState[ 0 ]) { ergodox_right_led_1_on(); }
  if (ledState[ 1 ]) { ergodox_right_led_2_on(); }
  if (ledState[ 2 ]) { ergodox_right_led_3_on(); }
  
    
  
};
