/* Copyright 2019 noroadsleft
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

/* keymap_extras definitions for European Portuguese (pt-PT) */

#pragma once

#include "keymap.h"


/* Portuguese (Portugal) layout
 *   Normal Characters
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │\  │1  │2  │3  │4  │5  │6  │7  │8  │9  │0  │'  │«  │ Bksp  │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │ Tab │q  │w  │e  │r  │t  │y  │u  │i  │o  │p  │+  │´  │Enter│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │CapsLk│a  │s  │d  │f  │g  │h  │j  │k  │l  │ç  │º  │~  │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │Sft │<  │z  │x  │c  │v  │b  │n  │m  │,  │.  │-  │  Shift   │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │Ctrl│GUI │Alt │                        │Alt │GUI │Menu│Ctrl│
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
#define PT_BSLS KC_GRV
#define PT_1    KC_1
#define PT_2    KC_2
#define PT_3    KC_3
#define PT_4    KC_4
#define PT_5    KC_5
#define PT_6    KC_6
#define PT_7    KC_7
#define PT_8    KC_8
#define PT_9    KC_9
#define PT_0    KC_0
#define PT_QUOT KC_MINS // '
#define PT_LDQT KC_EQL  // «

#define PT_Q    KC_Q
#define PT_W    KC_W
#define PT_E    KC_E
#define PT_R    KC_R
#define PT_T    KC_T
#define PT_Y    KC_Y
#define PT_U    KC_U
#define PT_I    KC_I
#define PT_O    KC_O
#define PT_P    KC_P
#define PT_PLUS KC_LBRC // +
#define PT_ACUT KC_RBRC // ´

#define PT_A    KC_A
#define PT_S    KC_S
#define PT_D    KC_D
#define PT_F    KC_F
#define PT_G    KC_G
#define PT_H    KC_H
#define PT_J    KC_J
#define PT_K    KC_K
#define PT_L    KC_L
#define PT_CCED KC_SCLN // Ç
#define PT_ORDM KC_QUOT // º
#define PT_TILD KC_BSLS // ~

#define PT_LABK KC_NUBS // <
#define PT_Z    KC_Z
#define PT_X    KC_X
#define PT_C    KC_C
#define PT_V    KC_V
#define PT_B    KC_B
#define PT_N    KC_N
#define PT_M    KC_M
#define PT_COMM KC_COMM
#define PT_DOT  KC_DOT
#define PT_MINS KC_SLSH // -


/* Portuguese (Portugal) layout
 *   Shifted Characters
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │|  │!  │"  │#  │$  │%  │&  │/  │(  │)  │=  │?  │»  │ Bksp  │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │ Tab │Q  │W  │E  │R  │T  │Y  │U  │I  │O  │P  │*  │`  │Enter│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │CapsLk│A  │S  │D  │F  │G  │H  │J  │K  │L  │Ç  │ª  │^  │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │Sft │>  │Z  │X  │C  │V  │B  │N  │M  │;  │:  │_  │  Shift   │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │Ctrl│GUI │Alt │                        │Alt │GUI │Menu│Ctrl│
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
#define PT_PIPE LSFT(PT_BSLS) // |
#define PT_EXLM LSFT(PT_1)    // !
#define PT_DQUO LSFT(PT_2)    // "
#define PT_HASH LSFT(PT_3)    // #
#define PT_DLR  LSFT(PT_4)    // $
#define PT_PERC LSFT(PT_5)    // %
#define PT_AMPR LSFT(PT_6)    // &
#define PT_SLSH LSFT(PT_7)    // /
#define PT_LPRN LSFT(PT_8)    // (
#define PT_RPRN LSFT(PT_9)    // )
#define PT_EQL  LSFT(PT_0)    // =
#define PT_QUES LSFT(PT_QUOT) // ?
#define PT_RDQT LSFT(PT_LDQT) // »

#define PT_ASTR LSFT(PT_PLUS) // *
#define PT_GRV  LSFT(PT_ACUT) // `

#define PT_ORDF LSFT(PT_ORDM) // ª
#define PT_CIRC LSFT(PT_TILD) // ^

#define PT_RABK LSFT(PT_LABK) // >
#define PT_SCLN LSFT(PT_COMM) // ;
#define PT_COLN LSFT(PT_DOT)  // :
#define PT_UNDS LSFT(PT_MINS) // _


/* Portuguese (Portugal) layout
 *   AltGr-ed Characters
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │   │@  │£  │§  │   │   │{  │[  │]  │}  │   │   │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │€  │   │   │   │   │   │   │   │¨  │   │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │   │   │   │   │   │   │   │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
#define PT_AT   ALGR(PT_2)    // @
#define PT_PND  ALGR(PT_3)    // £
#define PT_SECT ALGR(PT_4)    // §
#define PT_LCBR ALGR(PT_7)    // {
#define PT_LBRC ALGR(PT_8)    // [
#define PT_RBRC ALGR(PT_9)    // ]
#define PT_RCBR ALGR(PT_0)    // }

#define PT_EURO ALGR(PT_E)    // €
#define PT_DIA  ALGR(PT_LBRC) // ¨
