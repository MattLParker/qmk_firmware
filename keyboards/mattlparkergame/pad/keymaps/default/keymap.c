#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _RGB
};

// +-------+-------+-------+-------+-------+-------+-------+
// |       |       |       |       |       |       |       |
// +-------+-------+-------+-------+-------+-------+-------+
// |       |       |       |       |       |       |       |
// +-------+-------+-------+-------+-------+-------+-------+
// |       |       |       |       |       |       |       |
// +-------+-------+-------+-------+-------+-------+-------+           +-------+
// |       |       |       |       |       |       |                   |       |
// +-------+-------+-------+-------+-------+-------+-------+   +-------+-------+-------+
// |       |       |       |       |       |       |       |   |       |       |       |    <--- 5 way nav
// +-------+-------+-------+       +-------+-------+-------+   +-------+-------+-------+
//                                                                     |       |
//                                                                     +-------+
//                                 +-------+-------+-------+
//                                 |       |       |       |   <--- 3 way thumb
//                                 +-------+-------+-------+

//    ----.
//         '..
//            '
//        +-------+
//        |       |
//        |       |    <---- foot pedal via TRRS
//        |       |
//        +-------+


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_kucheza(
    KC_ESC,    KC_M,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,
    KC_PGUP,   KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,
    KC_PGDOWN, KC_LCTL,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,
    KC_LGUI,   KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,                          KC_B,
    LALT(KC_F10), MO(_NAV), MO(_RGB),               KC_LALT, KC_J,  KC_SPC,          KC_MPRV, KC_MPLY, KC_MNXT,
                                                                                          KC_VOLD,
                                                KC_VOLD,   KC_MUTE,   KC_VOLU,
    KC_LSFT
),

[_NAV] = LAYOUT_kucheza(
    KC_ESC,    KC_N,      KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,
    KC_PGUP,   KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,
    KC_PGDOWN, KC_LCTL,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,
    KC_LGUI,   KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,                          KC_B,
    LALT(KC_F10), MO(_NAV), MO(_RGB),               KC_LALT, KC_J,  KC_SPC,          KC_MPRV, KC_MPLY, KC_MNXT,
                                                                                          KC_VOLD,
                                                KC_VOLD,   KC_MUTE,   KC_VOLU,
    KC_LSFT
),

[_RGB] =  LAYOUT_kucheza(
    QK_BOOT,   KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        _______,
    _______,   RGB_TOG,      RGB_RMOD,     RGB_MOD,      _______,      TG(_QWERTY),  _______,
    _______,   RGB_SPI,      RGB_HUI,      RGB_SAI,      RGB_VAI,      KC_END,       _______,
    _______,   RGB_SPD,      RGB_HUD,      RGB_SAD,      RGB_VAD,      TG(_COLEMAK),                       _______,
    _______,   _______,      _______,                    _______,      _______,      _______,     _______, _______, _______,
                                                                                                           _______,
                                                         _______,      _______,      _______,
    _______
)
}