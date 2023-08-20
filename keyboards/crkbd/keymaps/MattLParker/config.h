/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_RIGHT
// #define MASTER_RIGHT
// #define EE_HANDS

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define SPLIT_LAYER_STATE_ENABLE
// #define SPLIT_WPM_ENABLE //Enable WPM across split keyboards (+268).
//#define NO_ACTION_ONESHOT
//#define SPLIT_OLED_ENABLE
#define OLED_TIMEOUT 30000
#define DYNAMIC_KEYMAP_LAYER_COUNT 
#define OLED_UPDATE_INTERVAL 50

#define TAPPING_TOGGLE 3



//combo
#define COMBO_TERM 35
#define COMBO_TERM_PER_COMBO
#define COMBO_STRICT_TIMER
//#define COMBO_ONLY_FROM_LAYER 1
#define COMBO_SHOULD_TRIGGER
#define ONESHOT_TAP_TOGGLE 3