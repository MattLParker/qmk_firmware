/* Copyright 2022 Julian Turner
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



//Quick adjusts
  #define U_RDO C(KC_Y)
  #define U_PST C(KC_V)
  #define U_CPY C(KC_C)
  #define U_CUT C(KC_X)
  #define U_UND C(KC_Z)

  //
#define RD_SFT OSM(MOD_RSFT)
#define TD_SFT OSM(MOD_LSFT)

#define SC_CUT LCTL(KC_X)
#define SC_COPY LCTL(KC_C)
#define SC_PASTE LCTL(KC_V)
#define SC_PASTE_NO_FORMAT LCTL(S(KC_V))
#define SC_PTAB LCTL(S(KC_TAB))
#define SC_LAUNCHER LGUI(KC_TAB)
#define SC_CLOSE LCTL(KC_W)
#define SC_NTAB LCTL(KC_T)
#define SC_NEW_WINDOW LCTL(KC_N)
#define SC_CAD LCTL(LALT(KC_DEL))
#define SC_AF4 LALT(KC_F4)

// Shorthands.
#define SC_PSTE SC_PASTE
#define SC_CLSE SC_CLOSE
#define SC_NWIN SC_NEW_WINDOW
#define SC_SELA SC_SELECT_ALL
#define LAUNCHR SC_LAUNCHER

// UC_DISA

//         case UC_SHRG:
//             if (record->event.pressed) {
//                 send_unicode_string("¯\\_(ツ)_/¯");
//             }
//             break;