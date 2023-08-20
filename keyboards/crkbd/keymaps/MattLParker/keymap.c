/*
Copyright 2019 @foostan
Copyright 2021 @HellSingCoder
Copyright 2023 @asdfire1

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
#include "keytabs.h"
//#include <stdio.h>

enum layer_names {
  _BASE,
  _GAME,
  _GAME2,
  _NAV,
  _SYMB
};



enum combo_events {
  L_SHIFT_COMBO,    // LM2 and LM3 => TD_SFT
  R_SHIFT_COMBO,  
  CAPS_WORD_COMBO,   
  CTRL_COMBO,      
  TILD_COMBO,    
  TGGAME_COMBO,
  TGGAME2_COMBO,
  COLON_COMBO,        
  BACKSPACE_COMBO, 
  BACKWORD_COMBO,  
  DELETE_COMBO,   
  ENTER_COMBO,     
  L_BRACKET_COMBO, 
  R_BRACKET_COMBO, 
  L_PAREN_COMBO,
  R_PAREN_COMBO,  
  L_BRACE_COMBO, 
  R_BRACE_COMBO, 
  SYM_LAYER_COMBO,  
  NAV_LAYER_COMBO,  
  GAME_H_COMBO,     
  GAME_B_COMBO,    
  COMBO_LENGTH,
  TAB_COMBO
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM l_shift_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM r_shift_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM caps_word_combo[] = {KC_F, KC_U, COMBO_END};
const uint16_t PROGMEM toggle_game_combo[] = {KC_Q, KC_QUOT, COMBO_END};
const uint16_t PROGMEM toggle2_game_combo[] = {KC_TAB, KC_P, COMBO_END};
const uint16_t PROGMEM backspace_combo[] = {KC_Y, KC_QUOT, COMBO_END};
const uint16_t l_bracket_combo[] PROGMEM = {KC_R, KC_W, COMBO_END};
const uint16_t r_bracket_combo[] PROGMEM = {KC_I, KC_Y, COMBO_END};
const uint16_t l_paren_combo[] PROGMEM = {KC_T, KC_P, COMBO_END};
const uint16_t r_paren_combo[] PROGMEM = {KC_N, KC_L, COMBO_END};
const uint16_t l_brace_combo[] PROGMEM = {KC_S, KC_F, COMBO_END};
const uint16_t r_brace_combo[] PROGMEM = {KC_E, KC_U, COMBO_END};
const uint16_t game_h_combo[] PROGMEM = {KC_F, KC_G, COMBO_END};
const uint16_t tild_combo[] PROGMEM = {KC_Q, KC_W, COMBO_END};
const uint16_t backword_combo[] PROGMEM = {KC_Y, KC_U, COMBO_END};
const uint16_t colon_combo[] PROGMEM = {KC_I, KC_O, COMBO_END};
const uint16_t tab_combo[] PROGMEM = {KC_A, KC_R, COMBO_END};
const uint16_t nav_layer_combo[] PROGMEM = {KC_ENT, KC_ESC, COMBO_END};
const uint16_t sym_layer_combo[] PROGMEM = {KC_LALT, KC_SPC, COMBO_END};
//const uint16_t r_brace_combo[] PROGMEM = {KC_G, KC_U, COMBO_END};


combo_t key_combos[] = {
    [L_SHIFT_COMBO] = COMBO(l_shift_combo, TD_SFT),
    [R_SHIFT_COMBO] = COMBO(r_shift_combo, RD_SFT),
    // [CTRL_COMBO] = COMBO(ctrl_combo, KC_LCTL),
    [CAPS_WORD_COMBO] = COMBO(caps_word_combo, CW_TOGG),
    [TILD_COMBO] = COMBO(tild_combo, QK_GESC),
    [TAB_COMBO] = COMBO(tab_combo, KC_TAB),
    [TGGAME_COMBO] = COMBO(toggle_game_combo, TG(_GAME)),
    [TGGAME2_COMBO] = COMBO(toggle2_game_combo, TG(_GAME)),
    // [Z_COMBO] = COMBO(kc_z_combo, KC_Z),
    [BACKSPACE_COMBO] = COMBO(backspace_combo, KC_BSPC),
    [BACKWORD_COMBO] = COMBO(backword_combo, C(KC_BSPC)),
    // [DELETE_COMBO] = COMBO(delete_combo, KC_DEL),
    [COLON_COMBO] = COMBO(colon_combo, KC_COLN),
    // [ENTER_COMBO] = COMBO(enter_combo, KC_ENT),
    [L_BRACKET_COMBO] = COMBO(l_bracket_combo, KC_LBRC),
    [R_BRACKET_COMBO] = COMBO(r_bracket_combo, KC_RBRC),
    [L_PAREN_COMBO] = COMBO(l_paren_combo, KC_LPRN),
    [R_PAREN_COMBO] = COMBO(r_paren_combo, KC_RPRN),
    [NAV_LAYER_COMBO] = COMBO(nav_layer_combo, TT(_NAV)),
    [SYM_LAYER_COMBO] = COMBO(sym_layer_combo, TT(_SYMB)),   
    [L_BRACE_COMBO] = COMBO(l_brace_combo, KC_LCBR),
    [R_BRACE_COMBO] = COMBO(r_brace_combo, KC_RCBR),
    [GAME_H_COMBO] = COMBO(game_h_combo, KC_H),
    // [GAME_B_COMBO] = COMBO(game_b_combo, KC_B),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  //disable and enable some left hand combos when on game layer 
    switch (combo_index) {
        case GAME_H_COMBO:
        case GAME_B_COMBO:
            if (layer_state_is(_GAME)) {
                return true;
            }
        case L_SHIFT_COMBO:
        case L_BRACKET_COMBO ... R_BRACE_COMBO:
        case TAB_COMBO:
            if (layer_state_is(_GAME)) {
                return false;
            }
    }
    return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, _GAME)) {
        autoshift_disable();
    } else { 
        autoshift_enable();
    }
    return state;
}

//where is tab and equal 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,    XXXXXXX,
      XXXXXXX,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,       XXXXXXX,
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H, KC_COMM,  KC_DOT,    KC_SLSH,    XXXXXXX,
                            OSM(MOD_LCTL),   LT(_SYMB,KC_ENT), TT(_NAV),                         KC_BSPC,     KC_SPC, KC_LGUI
  ),
  [_NAV] = LAYOUT_split_3x6_3(
   XXXXXXX,  KC_HOME,  SC_PTAB,     KC_UP,     SC_NTAB,     KC_PGUP,                   KC_KP_SLASH,   KC_7, KC_8,  KC_9, KC_KP_ASTERISK,  KC_PSCR,           
   XXXXXXX,  KC_END,   KC_LEFT,    KC_DOWN,   KC_RGHT,    KC_PGDN,                     KC_SCLN,       KC_4, KC_5,  KC_6, KC_KP_MINUS,     KC_LCTL,   
   XXXXXXX,  U_RDO,    SC_AF4,      KC_EQUAL,     KC_DEL,      SC_CAD,                       KC_GRV,        KC_1, KC_2,  KC_3, KC_KP_PLUS,      KC_LSFT,         
   OSM(MOD_LALT),TT(_SYMB),_______,                                                            _______,       KC_0, KC_DOT   
  ),                                                  
   [_SYMB] = LAYOUT_split_3x6_3(
   XXXXXXX, KC_F12,    KC_F7,     KC_F8,    KC_F9,     KC_PSCR,                           KC_BACKSLASH,  KC_AMPR,  KC_ASTR,   KC_LPRN,   KC_RCBR,  XXXXXXX,
   XXXXXXX, KC_F11,    KC_F4,     KC_F5,    KC_F6,     KC_SCRL,                           KC_UNDS,  KC_DLR,   KC_PERC,   KC_CIRC,   KC_COLN,  XXXXXXX,      
   XXXXXXX, KC_F10,    KC_F1,     KC_F2,    KC_F3,     KC_PAUS,                           KC_PIPE,  KC_EXLM,  KC_AT,     KC_HASH,   KC_TILD,  XXXXXXX,      
                     _______,_______,_______,                                                            KC_DEL,_______,_______       
  ),
  [_GAME] = LAYOUT_split_3x6_3(
     KC_T,     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                     KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_PGUP,
     KC_3,    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,                     KC_M,    KC_N,    KC_J,    KC_K,    KC_L,    KC_PGDN,  
     KC_5,    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_G,                     KC_B,    KC_H,     KC_COMM,  KC_DOT, KC_ESCAPE,  KC_M,
                                         KC_LALT,   LT(_GAME2,KC_M),  KC_SPC,     KC_ENT,   KC_4, KC_LGUI
 ),
   [_GAME2] = LAYOUT_split_3x6_3(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,     KC_0,  KC_PGUP,
     KC_LCTL,   KC_F1,   KC_F2, XXXXXXX, XXXXXXX,    KC_6,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN,
     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F4,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F13,
                                         KC_ENT, _______,  KC_SPC,         KC_4, KC_RALT,KC_LGUI
 )
};
// clang-format on

#ifdef OLED_ENABLE


/* 32 * 32 logo */
static void render_logo(void) {
    static const char PROGMEM rebal_logo[] = {
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x10, 0x00, 0x00, 0x00, 0x40, 0xe0, 0xe0, 0xc8, 0xfc, 0xfe, 
    0xfe, 0xfc, 0xc8, 0xe0, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x10, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0xf8, 0xfe, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0xff, 0xff, 
    0xff, 0xff, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xfe, 0xf8, 0x00, 
    0x00, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xf8, 0xfc, 0xfc, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xfc, 0xfc, 0xf8, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00
};
    oled_write_raw_P(rebal_logo, sizeof(rebal_logo));
}

static void print_logo_narrow(void) {
    render_logo();
    oled_set_cursor(1, 5);
    oled_write("E\n l\n u S\n s h\n i o\n v t\n e", false);
    oled_set_cursor(1, 14);
        switch (get_highest_layer(layer_state)) {
    case _BASE:
        oled_write_P(PSTR("Base "), false);
        break;
    case _NAV:
        oled_write_P(PSTR("Nav  "), false);
        break;  
    case _SYMB:
        oled_write_P(PSTR("Symb "), false);
        break;  
    case _GAME:
        oled_write_P(PSTR("Game "), false);
        break;
    case _GAME2:
        oled_write_P(PSTR("Game2"), false);
        break;         
    default:
        // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_write_ln_P(PSTR("Undefined"), false);
    }
}


static void print_status_narrow(void) {
    render_logo();
    oled_set_cursor(1, 5);
    oled_write("E\n l\n u S\n s h\n i o\n v t\n e", false);
    oled_set_cursor(1, 15);
        switch (get_highest_layer(layer_state)) {
    case _BASE:
        oled_write_P(PSTR("Base "), false);
        break;
    case _NAV:
        oled_write_P(PSTR("Nav  "), false);
        break;  
    case _SYMB:
        oled_write_P(PSTR("Symb "), false);
        break;  
    case _GAME:
        oled_write_P(PSTR("Game "), false);
        break;
    case _GAME2:
        oled_write_P(PSTR("Game2"), false);
        break;              
    default:
        // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_write_ln_P(PSTR("Undefined"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}
#endif

