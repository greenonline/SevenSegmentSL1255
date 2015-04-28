/*
SevenSegmentSL1255.cpp - Library for the:
						SL-1255-30 Red Seven Segment display (Common Anode)
						SL-1256-30 Red Seven Segment display (Common Cathode)
						SL-2255-30 Green Seven Segment display (Common Anode)
						SL-2256-30 Green Seven Segment display (Common Cathode)
Created by Mark G. Jenkins March 13 2015
Released into the public domain.
-------------------------------------------------------------------------------
Copyright (c) 2015, Greenonline, coded by Mark Graham Jenkins.

SevenSegmentSL1255 Library is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

SevenSegmentSL1255 Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This file needs the following Libraries:

None
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Special Thanks:
Bangkok Food stalls and Thai Beer
Ban Mo district for the inspiration.

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Version:
0.1 Rudimentary Direct Draw
0.2 Effects added
0.3 drawBitmap and use of Seven Segment (bit)maps added
0.4 Arduino standardisation (Write and Begin)
0.5 Public Beta
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BugList of the current version:

Please report any!

*/

#include "Arduino.h"
#include "SevenSegmentSL1255.h"

const uint8_t SevenSegmentSL1255::_asciiTable[128] = {   ascii_NUL
                                               ,   ascii_SOH
                                               ,   ascii_STX
                                               ,   ascii_ETX
                                               ,   ascii_EOT
                                               ,   ascii_ENQ
                                               ,   ascii_ACK
                                               ,   ascii_BEL
                                               ,   ascii_BS
                                               ,   ascii_TAB
                                               ,   ascii_LF
                                               ,   ascii_VT
                                               ,   ascii_FF
                                               ,   ascii_CR
                                               ,   ascii_SO
                                               ,   ascii_SI
                                               ,   ascii_DLE
                                               ,   ascii_DC1
                                               ,   ascii_DC2
                                               ,   ascii_DC3
                                               ,   ascii_DC4
                                               ,   ascii_NAK
                                               ,   ascii_SYN
                                               ,   ascii_ETB
                                               ,   ascii_CAN
                                               ,   ascii_EM
                                               ,   ascii_SUB
                                               ,   ascii_ESC
                                               ,   ascii_FS
                                               ,   ascii_GS
                                               ,   ascii_RS
                                               ,   ascii_US
                                               ,   ascii_space
                                               ,   ascii_exclamation
                                               ,   ascii_doublequote
                                               ,   ascii_hash
                                               ,   ascii_dollar
                                               ,   ascii_percent
                                               ,   ascii_ampersand
                                               ,   ascii_singlequote
                                               ,   ascii_leftparentese
                                               ,   ascii_rightparentese
                                               ,   ascii_asterisk
                                               ,   ascii_plus
                                               ,   ascii_comma
                                               ,   ascii_minus
                                               ,   ascii_period
                                               ,   ascii_forwardslash
                                               ,   ascii_0
                                               ,   ascii_1
                                               ,   ascii_2
                                               ,   ascii_3
                                               ,   ascii_4
                                               ,   ascii_5
                                               ,   ascii_6
                                               ,   ascii_7
                                               ,   ascii_8
                                               ,   ascii_9
                                               ,   ascii_colon
                                               ,   ascii_semicolon
                                               ,   ascii_lessthan
                                               ,   ascii_equals
                                               ,   ascii_greaterthan
                                               ,   ascii_interrogation
                                               ,   ascii_at
                                               ,   ascii_A
                                               ,   ascii_B
                                               ,   ascii_C
                                               ,   ascii_D
                                               ,   ascii_E
                                               ,   ascii_F
                                               ,   ascii_G
                                               ,   ascii_H
                                               ,   ascii_I
                                               ,   ascii_J
                                               ,   ascii_K
                                               ,   ascii_L
                                               ,   ascii_M
                                               ,   ascii_N
                                               ,   ascii_O
                                               ,   ascii_P
                                               ,   ascii_Q
                                               ,   ascii_R
                                               ,   ascii_S
                                               ,   ascii_T
                                               ,   ascii_U
                                               ,   ascii_V
                                               ,   ascii_W
                                               ,   ascii_X
                                               ,   ascii_Y
                                               ,   ascii_Z
                                               ,   ascii_leftbracket
                                               ,   ascii_backslash
                                               ,   ascii_rightbracket
                                               ,   ascii_circumflex
                                               ,   ascii_underscore
                                               ,   ascii_accent
                                               ,   ascii_a
                                               ,   ascii_b
                                               ,   ascii_c
                                               ,   ascii_d
                                               ,   ascii_e
                                               ,   ascii_f
                                               ,   ascii_g
                                               ,   ascii_h
                                               ,   ascii_i
                                               ,   ascii_j
                                               ,   ascii_k
                                               ,   ascii_l
                                               ,   ascii_m
                                               ,   ascii_n
                                               ,   ascii_o
                                               ,   ascii_p
                                               ,   ascii_q
                                               ,   ascii_r
                                               ,   ascii_s
                                               ,   ascii_t
                                               ,   ascii_u
                                               ,   ascii_v
                                               ,   ascii_w
                                               ,   ascii_x
                                               ,   ascii_y
                                               ,   ascii_z
                                               ,   ascii_leftbrace
                                               ,   ascii_pipe
                                               ,   ascii_rightbrace
                                               ,   ascii_cedilla
                                               ,   ascii_DEL};



const uint8_t SevenSegmentSL1255::_hexTable[16] = {alphanum_0, alphanum_1, alphanum_2, alphanum_3, alphanum_4, alphanum_5, alphanum_6, alphanum_7, alphanum_8, alphanum_9, alphanum_A, alphanum_b, alphanum_C, alphanum_d, alphanum_E, alphanum_F}; //for hexWrite()
const uint8_t SevenSegmentSL1255::_decTable[10] = {alphanum_0, alphanum_1, alphanum_2, alphanum_3, alphanum_4, alphanum_5, alphanum_6, alphanum_7, alphanum_8, alphanum_9}; //for decWrite()
const uint8_t SevenSegmentSL1255::_octTable[8] = {alphanum_0, alphanum_1, alphanum_2, alphanum_3, alphanum_4, alphanum_5, alphanum_6, alphanum_7}; //for octWrite()

//Default Constructor
SevenSegmentSL1255::SevenSegmentSL1255(){
  init();
}

//Constructor for digit 1
SevenSegmentSL1255::SevenSegmentSL1255(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1){
  init(a1, b1, c1, d1, e1, f1, g1);
}

//Constructor for digits 1 and 2
SevenSegmentSL1255::SevenSegmentSL1255(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2){
  init(a1, b1, c1, d1, e1, f1, g1, a2, b2, c2, d2, e2, f2, g2);
}

//Constructor for digits 1 and 2 and Seven Segment Type
SevenSegmentSL1255::SevenSegmentSL1255(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2, uint8_t ssType){
  init(a1, b1, c1, d1, e1, f1, g1, a2, b2, c2, d2, e2, f2, g2, ssType);
}

//Constructor for digits 1 and 2 and logical On Value and Off Value
SevenSegmentSL1255::SevenSegmentSL1255(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2, uint8_t onValue, uint8_t offValue){
  init(a1, b1, c1, d1, e1, f1, g1, a2, b2, c2, d2, e2, f2, g2, onValue, offValue);
}


//Initialiser called by default constructor
void SevenSegmentSL1255::init(void) {
  init(default_a1, default_b1, default_c1, default_d1, default_e1, default_f1, default_g1);
}

//Initialiser called by constructor for digit 1
void SevenSegmentSL1255::init(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1) {
  init(a1, b1, c1, d1, e1, f1, g1, default_a2, default_b2, default_c2, default_d2, default_e2, default_f2, default_g2);
}

//Initialiser called by constructor for digits 1 and 2
void SevenSegmentSL1255::init(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2) {
  init(a1, b1, c1, d1, e1, f1, g1, a2, b2, c2, d2, e2, f2, g2, default_onValue, default_offValue);
}

//Initialiser called by constructor for digits 1 and 2 and Seven Segment Type
void SevenSegmentSL1255::init(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2, uint8_t ssType) {

  _ssType=ssType;
  //could call init (a1...g2, on, off) in this if construct

  if (_ssType == SL_1255){
    init(a1, b1, c1, d1, e1, f1, g1, a2, b2, c2, d2, e2, f2, g2, default_onValue, default_offValue);
  } else if (_ssType == SL_1256){
    init(a1, b1, c1, d1, e1, f1, g1, a2, b2, c2, d2, e2, f2, g2, !default_onValue, !default_offValue);
  } else {
	// If error;
	// Use defaults
    init(a1, b1, c1, d1, e1, f1, g1, a2, b2, c2, d2, e2, f2, g2, default_onValue, default_offValue);
  }

  //could call init (a1...g2, on, off) in this if construct
}

//Initialiser called by constructor for digits 1 and 2 and and logical On Value and Off Value
void SevenSegmentSL1255::init(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2, uint8_t onValue, uint8_t offValue) {
  _a1=a1;
  _b1=b1;
  _c1=c1;
  _d1=d1;
  _e1=e1;
  _f1=f1;
  _g1=g1;

  _a2=a2;
  _b2=b2;
  _c2=c2;
  _d2=d2;
  _e2=e2;
  _f2=f2;
  _g2=g2;

  _onValue=onValue;
  _offValue=offValue;

  //don't forget to set _ssType!!!
  // use _onValue to set _ssType
  _ssType=_onValue;
}

// Default begin() method, to set the pins defined by the constructor to be outputs
void SevenSegmentSL1255::begin(void) {
  pinMode(_a1, OUTPUT);
  pinMode(_b1, OUTPUT);
  pinMode(_c1, OUTPUT);
  pinMode(_d1, OUTPUT);
  pinMode(_e1, OUTPUT);
  pinMode(_f1, OUTPUT);
  pinMode(_g1, OUTPUT);

  pinMode(_a2, OUTPUT);
  pinMode(_b2, OUTPUT);
  pinMode(_c2, OUTPUT);
  pinMode(_d2, OUTPUT);
  pinMode(_e2, OUTPUT);
  pinMode(_f2, OUTPUT);
  pinMode(_g2, OUTPUT);
}

//Direct draw Methods
// *** Most Significant Digit ***
// Hex chars (2nd digit)

//The 'x' notation methods call the direct draw draw_<character>_<digit> methods
//Draw character '0' to left hand (MSD) digit
void SevenSegmentSL1255::draw_0x(void) {
  draw_0_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/
}

//Draw character '1' to left hand (MSD) digit
void SevenSegmentSL1255::draw_1x(void) {
  draw_1_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
*/
}

//Draw character '2' to left hand (MSD) digit
void SevenSegmentSL1255::draw_2x(void) {
  draw_2_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character '3' to left hand (MSD) digit
void SevenSegmentSL1255::draw_3x(void) {
  draw_3_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character '4' to left hand (MSD) digit
void SevenSegmentSL1255::draw_4x(void) {
  draw_4_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character '5' to left hand (MSD) digit
void SevenSegmentSL1255::draw_5x(void) {
  draw_5_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character '6' to left hand (MSD) digit
void SevenSegmentSL1255::draw_6x(void) {
  draw_6_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character '7' to left hand (MSD) digit
void SevenSegmentSL1255::draw_7x(void) {
  draw_7_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character '8' to left hand (MSD) digit
void SevenSegmentSL1255::draw_8x(void) {
  draw_8_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character '9' to left hand (MSD) digit
void SevenSegmentSL1255::draw_9x(void) {
  draw_9_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'A' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Ax(void) {
  draw_A_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'a' to left hand (MSD) digit
void SevenSegmentSL1255::draw_ax(void) {
  draw_a_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'B' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Bx(void) {
  draw_B_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'b' to left hand (MSD) digit
void SevenSegmentSL1255::draw_bx(void) {
  draw_b_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'C' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Cx(void) {
  draw_C_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'c' to left hand (MSD) digit
void SevenSegmentSL1255::draw_cx(void) {
  draw_c_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'D' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Dx(void) {
  draw_D_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'd' to left hand (MSD) digit
void SevenSegmentSL1255::draw_dx(void) {
  draw_d_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'E' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Ex(void) {
  draw_E_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'e' to left hand (MSD) digit
void SevenSegmentSL1255::draw_ex(void) {
  draw_e_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'F' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Fx(void) {
  draw_F_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'f' to left hand (MSD) digit
void SevenSegmentSL1255::draw_fx(void) {
  draw_f_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

// Extra Letters

//The 'x' notation methods call the direct draw draw_<character>_<digit> methods

//Draw character 'G' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Gx(void) {
  draw_G_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'g' to left hand (MSD) digit
void SevenSegmentSL1255::draw_gx(void) {
  draw_g_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'H' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Hx(void) {
  draw_H_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'h' to left hand (MSD) digit
void SevenSegmentSL1255::draw_hx(void) {
  draw_h_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'I' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Ix(void) {
  draw_I_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'i' to left hand (MSD) digit
void SevenSegmentSL1255::draw_ix(void) {
  draw_i_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'J' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Jx(void) {
  draw_J_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'j' to left hand (MSD) digit
void SevenSegmentSL1255::draw_jx(void) {
  draw_j_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'K' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Kx(void) {
  draw_K_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'k' to left hand (MSD) digit
void SevenSegmentSL1255::draw_kx(void) {
  draw_k_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'L' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Lx(void) {
  draw_L_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'l' to left hand (MSD) digit
void SevenSegmentSL1255::draw_lx(void) {
  draw_l_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'M' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Mx(void) {
  draw_M_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'm' to left hand (MSD) digit
void SevenSegmentSL1255::draw_mx(void) {
  draw_m_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'N' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Nx(void) {
  draw_N_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'n' to left hand (MSD) digit
void SevenSegmentSL1255::draw_nx(void) {
  draw_n_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'O' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Ox(void) {
  draw_O_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'o' to left hand (MSD) digit
void SevenSegmentSL1255::draw_ox(void) {
  draw_o_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'P' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Px(void) {
  draw_P_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'p' to left hand (MSD) digit
void SevenSegmentSL1255::draw_px(void) {
  draw_p_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'Q' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Qx(void) {
  draw_Q_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'q' to left hand (MSD) digit
void SevenSegmentSL1255::draw_qx(void) {
  draw_q_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'R' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Rx(void) {
  draw_R_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'r' to left hand (MSD) digit
void SevenSegmentSL1255::draw_rx(void) {
  draw_r_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'S' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Sx(void) {
  draw_S_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 's' to left hand (MSD) digit
void SevenSegmentSL1255::draw_sx(void) {
  draw_s_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'T' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Tx(void) {
  draw_T_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 't' to left hand (MSD) digit
void SevenSegmentSL1255::draw_tx(void) {
  draw_t_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'U' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Ux(void) {
  draw_U_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'u' to left hand (MSD) digit
void SevenSegmentSL1255::draw_ux(void) {
  draw_u_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'V' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Vx(void) {
  draw_V_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'v' to left hand (MSD) digit
void SevenSegmentSL1255::draw_vx(void) {
  draw_v_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'W' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Wx(void) {
  draw_W_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'w' to left hand (MSD) digit
void SevenSegmentSL1255::draw_wx(void) {
  draw_w_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
*/}

//Draw character 'X' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Xx(void) {
  draw_X_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'x' to left hand (MSD) digit
void SevenSegmentSL1255::draw_xx(void) {
  draw_x_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'Y' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Yx(void) {
  draw_Y_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'Y' to left hand (MSD) digit
void SevenSegmentSL1255::draw_yx(void) {
  draw_y_1();

/*
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'Z' to left hand (MSD) digit
void SevenSegmentSL1255::draw_Zx(void) {
  draw_Z_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
*/}

//Draw character 'z' to left hand (MSD) digit
void SevenSegmentSL1255::draw_zx(void) {
  draw_z_1();

/*
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
*/}

// Symbols
//Draw degree character to left hand (MSD) digit
void SevenSegmentSL1255::draw_degreex(void) {
  draw_degree_1();
}

// Bitmap
/*
void SevenSegmentSL1255::draw_bitmapx(uint8_t character) {
	if ((character >> 0) & 1)
	  digitalWrite(_a1,_onValue);
	else
	  digitalWrite(_a1,_offValue);
	if ((character >> 1) & 1)
	  digitalWrite(_b1,_onValue);
	else
	  digitalWrite(_b1,_offValue);
	if ((character >> 2) & 1)
	  digitalWrite(_c1,_onValue);
	else
	  digitalWrite(_c1,_offValue);
	if ((character >> 3) & 1)
	  digitalWrite(_d1,_onValue);
	else
	  digitalWrite(_d1,_offValue);
	if ((character >> 4) & 1)
	  digitalWrite(_e1,_onValue);
	else
	  digitalWrite(_e1,_offValue);
	if ((character >> 5) & 1)
	  digitalWrite(_f1,_onValue);
	else
	  digitalWrite(_f1,_offValue);
	if ((character >> 6) & 1)
	  digitalWrite(_g1,_onValue);
	else
	  digitalWrite(_g1,_offValue);
}
*/

void SevenSegmentSL1255::draw_bitmap2(uint8_t segmentMapCode) {
	digitalWrite(_a2, (((segmentMapCode >> 0) & 1)? _onValue : _offValue));
	digitalWrite(_b2, (((segmentMapCode >> 1) & 1)? _onValue : _offValue));
	digitalWrite(_c2, (((segmentMapCode >> 2) & 1)? _onValue : _offValue));
	digitalWrite(_d2, (((segmentMapCode >> 3) & 1)? _onValue : _offValue));
	digitalWrite(_e2, (((segmentMapCode >> 4) & 1)? _onValue : _offValue));
	digitalWrite(_f2, (((segmentMapCode >> 5) & 1)? _onValue : _offValue));
	digitalWrite(_g2, (((segmentMapCode >> 6) & 1)? _onValue : _offValue));
}

void SevenSegmentSL1255::draw_bitmapInvert2(uint8_t segmentMapCode) {
	digitalWrite(_a2, (!((segmentMapCode >> 0) & 1)? _onValue : _offValue));
	digitalWrite(_b2, (!((segmentMapCode >> 1) & 1)? _onValue : _offValue));
	digitalWrite(_c2, (!((segmentMapCode >> 2) & 1)? _onValue : _offValue));
	digitalWrite(_d2, (!((segmentMapCode >> 3) & 1)? _onValue : _offValue));
	digitalWrite(_e2, (!((segmentMapCode >> 4) & 1)? _onValue : _offValue));
	digitalWrite(_f2, (!((segmentMapCode >> 5) & 1)? _onValue : _offValue));
	digitalWrite(_g2, (!((segmentMapCode >> 6) & 1)? _onValue : _offValue));
}

void SevenSegmentSL1255::draw2(uint8_t segmentMapCode) { //calls draw_bitmap(void) {
	draw_bitmap2(segmentMapCode);
}

void SevenSegmentSL1255::drawInvert2(uint8_t segmentMapCode) { //calls draw_bitmap()
	draw_bitmapInvert2(segmentMapCode);
}

void SevenSegmentSL1255::draw_bitmap0(uint8_t segmentMapCode) {
	digitalWrite(_a2, (((segmentMapCode >> 0) & 1)? _onValue : _offValue));
	digitalWrite(_b2, (((segmentMapCode >> 1) & 1)? _onValue : _offValue));
	digitalWrite(_c2, (((segmentMapCode >> 2) & 1)? _onValue : _offValue));
	digitalWrite(_d2, (((segmentMapCode >> 3) & 1)? _onValue : _offValue));
	digitalWrite(_e2, (((segmentMapCode >> 4) & 1)? _onValue : _offValue));
	digitalWrite(_f2, (((segmentMapCode >> 5) & 1)? _onValue : _offValue));
	digitalWrite(_g2, (((segmentMapCode >> 6) & 1)? _onValue : _offValue));
}

void SevenSegmentSL1255::draw_bitmapInvert0(uint8_t segmentMapCode) {
	digitalWrite(_a2, (!((segmentMapCode >> 0) & 1)? _onValue : _offValue));
	digitalWrite(_b2, (!((segmentMapCode >> 1) & 1)? _onValue : _offValue));
	digitalWrite(_c2, (!((segmentMapCode >> 2) & 1)? _onValue : _offValue));
	digitalWrite(_d2, (!((segmentMapCode >> 3) & 1)? _onValue : _offValue));
	digitalWrite(_e2, (!((segmentMapCode >> 4) & 1)? _onValue : _offValue));
	digitalWrite(_f2, (!((segmentMapCode >> 5) & 1)? _onValue : _offValue));
	digitalWrite(_g2, (!((segmentMapCode >> 6) & 1)? _onValue : _offValue));
}

void SevenSegmentSL1255::draw0(uint8_t segmentMapCode) { //calls draw_bitmap(void) {
	draw_bitmap0(segmentMapCode);
}

void SevenSegmentSL1255::drawInvert0(uint8_t segmentMapCode) { //calls draw_bitmap()
	draw_bitmapInvert0(segmentMapCode);
}

void SevenSegmentSL1255::draw_bitmap1(uint8_t segmentMapCode) {
	digitalWrite(_a1, (((segmentMapCode >> 0) & 1)? _onValue : _offValue));
	digitalWrite(_b1, (((segmentMapCode >> 1) & 1)? _onValue : _offValue));
	digitalWrite(_c1, (((segmentMapCode >> 2) & 1)? _onValue : _offValue));
	digitalWrite(_d1, (((segmentMapCode >> 3) & 1)? _onValue : _offValue));
	digitalWrite(_e1, (((segmentMapCode >> 4) & 1)? _onValue : _offValue));
	digitalWrite(_f1, (((segmentMapCode >> 5) & 1)? _onValue : _offValue));
	digitalWrite(_g1, (((segmentMapCode >> 6) & 1)? _onValue : _offValue));
}

void SevenSegmentSL1255::draw_bitmapInvert1(uint8_t segmentMapCode) {
	digitalWrite(_a1, (!((segmentMapCode >> 0) & 1)? _onValue : _offValue));
	digitalWrite(_b1, (!((segmentMapCode >> 1) & 1)? _onValue : _offValue));
	digitalWrite(_c1, (!((segmentMapCode >> 2) & 1)? _onValue : _offValue));
	digitalWrite(_d1, (!((segmentMapCode >> 3) & 1)? _onValue : _offValue));
	digitalWrite(_e1, (!((segmentMapCode >> 4) & 1)? _onValue : _offValue));
	digitalWrite(_f1, (!((segmentMapCode >> 5) & 1)? _onValue : _offValue));
	digitalWrite(_g1, (!((segmentMapCode >> 6) & 1)? _onValue : _offValue));
}

void SevenSegmentSL1255::draw1(uint8_t segmentMapCode) { //calls draw_bitmap(void) {
	draw_bitmap1(segmentMapCode);
}

void SevenSegmentSL1255::drawInvert1(uint8_t segmentMapCode) { //calls draw_bitmap()
	draw_bitmapInvert1(segmentMapCode);
}

// Put
//void SevenSegmentSL1255::putc(char character) {}
//void SevenSegmentSL1255::putchar(char character){}

// Write Routines

//Write to Digit 2 (Least Significant Digit) - Using SL-1255 notion
// Write ASCII character to Digit 2 (LSD)
void SevenSegmentSL1255::digit2CharWrite(char character) {
	uint8_t value = character;
	if ((value >= 0) && (value <= 127)) {
		draw_bitmap2(_asciiTable[value]);
	}
}

// Write Octal character to Digit 2 (LSD)
void SevenSegmentSL1255::digit2OctWrite(uint8_t value) {
	if ((value >= 0) && (value <= 7)) {
		draw_bitmap2(_octTable[value]);
	}
}

// Write Decimal character to Digit 2 (LSD)
void SevenSegmentSL1255::digit2DecWrite(uint8_t value) {
	if ((value >= 0) && (value <= 9)) {
		draw_bitmap2(_decTable[value]);
	}
}

// Write Hexadecimal character to Digit 2 (LSD)
void SevenSegmentSL1255::digit2HexWrite(uint8_t value) {
	if ((value >= 0) && (value <= 15)) {
		draw_bitmap2(_hexTable[value]);
	}
}

void SevenSegmentSL1255::digit2Write(uint8_t value) {
	if ((value >= 0) && (value < 10)) {
		draw_bitmap2(_decTable[value]);
	}
}

void SevenSegmentSL1255::write2(uint8_t value) {
	digit2Write(value);
}

void SevenSegmentSL1255::digit2Write(char character) {
	digit2CharWrite(character);
}

void SevenSegmentSL1255::write2(char character) {
	digit2Write(character);
}

//Write to Digit 0 (Least Significant Digit) - Using standard notion
// Write ASCII character to Digit 0 (LSD)
void SevenSegmentSL1255::digit0CharWrite(char character) {
	uint8_t value = character;
	if ((value >= 0) && (value <= 127)) {
		draw_bitmap0(_asciiTable[value]);
	}
}

// Write Octal character to Digit 0 (LSD)
void SevenSegmentSL1255::digit0OctWrite(uint8_t value) {
	if ((value >= 0) && (value <= 7)) {
		draw_bitmap0(_octTable[value]);
	}
}

// Write Decimal character to Digit 0 (LSD)
void SevenSegmentSL1255::digit0DecWrite(uint8_t value) {
	if ((value >= 0) && (value <= 9)) {
		draw_bitmap0(_decTable[value]);
	}
}

// Write Hexadecimal character to Digit 0 (LSD)
void SevenSegmentSL1255::digit0HexWrite(uint8_t value) {
	if ((value >= 0) && (value <= 15)) {
		draw_bitmap0(_hexTable[value]);
	}
}

void SevenSegmentSL1255::digit0Write(uint8_t value) {
	if ((value >= 0) && (value < 10)) {
		draw_bitmap0(_decTable[value]);
	}
}

void SevenSegmentSL1255::write0(uint8_t value) {
	digit0Write(value);
}

void SevenSegmentSL1255::digit0Write(char character) {
	digit0CharWrite(character);
}

void SevenSegmentSL1255::write0(char character) {
	digit0Write(character);
}

//Write to Digit 1 (Most Significant Digit) - Using standard notion
// Write ASCII character to Digit 1 (MSD)
void SevenSegmentSL1255::digit1CharWrite(char character) {
	uint8_t value = character;
	if ((value >= 0) && (value <= 127)) {
		draw_bitmap1(_asciiTable[value]);
	}
}

// Write Octal character to Digit 1 (MSD)
void SevenSegmentSL1255::digit1OctWrite(uint8_t value) {
	if ((value >= 0) && (value <= 7)) {
		draw_bitmap1(_octTable[value]);
	}
}

// Write Decimal character to Digit 1 (MSD)
void SevenSegmentSL1255::digit1DecWrite(uint8_t value) {
	if ((value >= 0) && (value <= 9)) {
		draw_bitmap1(_decTable[value]);
	}
}

// Write Hexadecimal character to Digit 1 (MSD)
void SevenSegmentSL1255::digit1HexWrite(uint8_t value) {
	if ((value >= 0) && (value <= 15)) {
		draw_bitmap1(_hexTable[value]);
	}
}

void SevenSegmentSL1255::digit1Write(uint8_t value) {
	if ((value >= 0) && (value < 10)) {
		draw_bitmap1(_decTable[value]);
	}
}

void SevenSegmentSL1255::write1(uint8_t value) {
	digit1Write(value);
}

void SevenSegmentSL1255::digit1Write(char character) {
	digit1CharWrite(character);
}

void SevenSegmentSL1255::write1(char character) {
	digit1Write(character);
}

void SevenSegmentSL1255::write(uint8_t value) {
	//if value<=99
	if (value <= 99){
		uint8_t MSD = value/10;			// get the Most Significant Digit
		uint8_t LSD = value-(MSD*10);	// get the Least Significant Digit
		digit1Write(MSD);			//write the MSD to digit 1
		digit2Write(LSD);			//write the LSD to digit 0, or digit 2 using SL-1255 notion
    }
}

void SevenSegmentSL1255::write(char characters[]) {
	char c1; // first character
	char c2; // second character
	//discard any other characters in the string

	if (characters[0] != 0 && characters[1] != 0){
		c1=characters[0]; // get the first character
		c2=characters[1]; // get the second character
		digit1Write(c1);
		digit2Write(c2);
	}

	if (characters[1] == 0){	// print only one character in digit 2 (digit 0)
		c2=characters[0]; // get the second character
		blank_1();
		digit2Write(c2);
	}

}

//scroll() is a default left scroll method
void SevenSegmentSL1255::scroll(char characters[]) {
	scroll(characters, default_delay);	// Call scroll() with the default delay
}

//scroll() is a default left scroll method
void SevenSegmentSL1255::scroll(char characters[], int delayBetweenScroll) {
	scrollLeft(characters, delayBetweenScroll); // Call scrollLeft() with the specified delay
}

//scroll and specify delay and direction in parameter
// Scroll left  == 1
// Scroll right != 1
void SevenSegmentSL1255::scroll(char characters[], int delayBetweenScroll, int directionLeft) {
	if (directionLeft == 1){
		scrollLeft(characters, delayBetweenScroll);
	} else {
		scrollRight(characters, delayBetweenScroll);
	}
}

void SevenSegmentSL1255::scrollLeft(char characters[]) {
	scrollLeft(characters, default_delay);	// Call scrollLeft() with the default delay
}

//Scrolls in from the right to the left
//First LSD is first character of message and
//MSD is blank
//then LSD->MSD, next character->LSD ...
//Finally MSD is last character of message, and
//LSD is blank
//
//When calling scrollLeft(), should encouch in blankx() and
//  xblank() calls (before and after) to clear the display
//  i.e.
//    xblank();  // Not strictly needed for scrollRight() calls
//    blankx();  // Not strictly needed for scrollLeft() calls
//    scrollLeft();
//    xblank();  // Not strictly needed for scrollLeft() calls
//    blankx();  // Not strictly needed for scrollRight() calls

void SevenSegmentSL1255::scrollLeft(char characters[], int delayBetweenScroll) {
	char c1; // first character
	char c2; // second character
	int index=0;

	blankx();						// Clear the display
	xblank();						// Clear the display
	delay(delayBetweenScroll);		// Delay before starting scroll

	if (characters[index] != 0){
		c2=characters[index++]; 	// get the second character
		digit2Write(c2);	 		// and write to the LSD first
		blankx();					// Also we blank MSD
		delay(delayBetweenScroll);	// Delay before moving on to writing both digits (below)
	}

	while (characters[index] != 0){
		c1=c2; 						// get the first character from the previous second character
		c2=characters[index++]; 	// get the new second character
		digit1Write(c1);			// write the first character
		digit2Write(c2);			// write the second character
		delay(delayBetweenScroll);	// Delay before shifting both digits left
	}

	c1=c2; 							// get the first character from the previous second character
	digit1Write(c1);				// write the first character
	xblank();						// Also we blank LSD
	delay(delayBetweenScroll);		// Delay before finishing scroll

	blankx();						// Clear the display
	xblank();						// Clear the display
	delay(delayBetweenScroll);		// Delay before ending scroll

}

void SevenSegmentSL1255::scrollRight(char characters[]) {
	scrollRight(characters, default_delay);	// Call scrollRight() with the default delay
}

//Scrolls in from the left to the right
//First MSD is first character of message and
//LSD is blank
//then MSD->LSD, next character->MSD ...
//Finally LSD is last character of message, and
//MSD is blank
//
//When calling scrollRight(), should encouch in blankx() and
//  xblank() calls (before and after) to clear the display
//  i.e.
//    xblank();  // Not strictly needed for scrollRight() calls
//    blankx();  // Not strictly needed for scrollLeft() calls
//    scrollRight();
//    xblank();  // Not strictly needed for scrollLeft() calls
//    blankx();  // Not strictly needed for scrollRight() calls

void SevenSegmentSL1255::scrollRight(char characters[], int delayBetweenScroll) {
	char c1; // first character
	char c2; // second character
	int index=0;

	//Find length of string
	int length = 0;
	while (characters[length] != 0){
		length++;
	}

	index= length-1;

	blankx();						// Clear the display
	xblank();						// Clear the display
	delay(delayBetweenScroll);		// Delay before starting scroll

	if (index>=0){
		c1=characters[index--]; 	// get the first character
		digit1Write(c1);	 		// and write to the MSD first
		xblank();					// Also we blank LSD
		delay(delayBetweenScroll);	// Delay before moving on to writing both digits (below)
	}

	while (index>=0){
		c2=c1; 						// get the second character from the previous first character
		c1=characters[index--];		// get the new first character
		digit1Write(c1);			// write the first character
		digit2Write(c2);			// write the second character
		delay(delayBetweenScroll);	// Delay before shifting both digits right
	}

	c2=c1;							// get the second character from the previous first character
	digit2Write(c2);				// write the second character
	blankx();						// Also we blank MSD
	delay(delayBetweenScroll);		// Delay before finishing scroll

	blankx();						// Clear the display
	xblank();						// Clear the display
	delay(delayBetweenScroll);		// Delay before ending scroll
}

void SevenSegmentSL1255::write(uint8_t value, uint8_t digit) {
	//if value<=9
	if (value <= 9) {
		switch (digit) {
			case 0 :
				digit0Write(value);
				break;
			case 1 :
				digit1Write(value);
				break;
			case 2 :
				digit2Write(value);
				break;
			default :
				break;
		}
    }
}

void SevenSegmentSL1255::write(char character, uint8_t digit) {
	switch (digit) {
		case 0 :
			digit0Write(character);
			break;
		case 1 :
			digit1Write(character);
			break;
		case 2 :
			digit2Write(character);
			break;
		default :
			break;
	}
}

// Effects

void SevenSegmentSL1255::effect_1(uint8_t index) {
	int defaultDelay = default_delay;
	effect_1(index, defaultDelay);
}

void SevenSegmentSL1255::effect_1(uint8_t index, int totaldelay) {
	switch (index) {
		case 0 :
			blank_1();
			break;
		case 1 :
			flash_1(totaldelay);
			break;
		case 2 :
			rotateOnSegment_1(totaldelay);
			break;
		case 3 :
			rotateOffSegment_1(totaldelay);
			break;
		case 4 :
			sequentiallyTurnOnAllSegments_1(totaldelay);
			break;
		case 5 :
			sequentiallyTurnOffAllSegments_1(totaldelay);
			break;
		case 6 :
			figure8Clock_1(totaldelay);
			break;
		case 7 :
			figure8Anticlock_1(totaldelay);
			break;
		case 8 :
			figure8ClockInvert_1(totaldelay);
			break;
		case 9 :
			figure8AnticlockInvert_1(totaldelay);
			break;
		case 10 :
			rotateTopClock_1(totaldelay);
			break;
		case 11 :
			rotateTopAnticlock_1(totaldelay);
			break;
		case 12 :
			rotateTopClockInvert_1(totaldelay);
			break;
		case 13 :
			rotateTopAnticlockInvert_1(totaldelay);
			break;
		case 14 :
			rotateBottomClock_1(totaldelay);
			break;
		case 15 :
			rotateBottomAnticlock_1(totaldelay);
			break;
		case 16 :
			rotateBottomClockInvert_1(totaldelay);
			break;
		case 17 :
			rotateBottomAnticlockInvert_1(totaldelay);
			break;
		case 18 :
			rotateBothClock_1(totaldelay);
			break;
		case 19 :
			rotateBothAnticlock_1(totaldelay);
			break;
		case 20 :
			rotateBothClockInvert_1(totaldelay);
			break;
		case 21 :
			rotateBothAnticlockInvert_1(totaldelay);
			break;
		case 22 :
			rotateCircleClock_1(totaldelay);
			break;
		case 23 :
			rotateCircleAnticlock_1(totaldelay);
			break;
		case 24 :
			rotateCircleClockInvert_1(totaldelay);
			break;
		case 25 :
			rotateCircleAnticlockInvert_1(totaldelay);
			break;
		default :
			break;
	}
}

void SevenSegmentSL1255::blank_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::blankx(void) {
  blank_1();
}

void SevenSegmentSL1255::fill_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::fillx(void) {
  fill_1();
}

void SevenSegmentSL1255::flash_1(int totaldelay) {
  blank_1();
  delay (totaldelay/2);
  fill_1();
  delay (totaldelay/2);
}

void SevenSegmentSL1255::flashx(int totaldelay) {
  flash_1(totaldelay);
}


// This only works if the pins are sequential
void SevenSegmentSL1255::rotateOffSegment_1(int totaldelay){
  fill_1();
  for(uint8_t pin=_a1; pin<=_g1; pin++) {
    digitalWrite(pin,_offValue);
    delay(totaldelay/2);
    digitalWrite(pin,_onValue);
    delay(totaldelay/2);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::rotateOnSegment_1(int totaldelay){
  blank_1();
  for(uint8_t pin=_a1; pin<=_g1; pin++) {
    digitalWrite(pin,_onValue);
    delay(totaldelay/2);
    digitalWrite(pin,_offValue);
    delay(totaldelay/2);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::sequentiallyTurnOnAllSegments_1(int totaldelay){
  blank_1();
  for(uint8_t pin=_a1; pin<=_g1; pin++) {
    digitalWrite(pin,_onValue);
    delay(totaldelay);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::sequentiallyTurnOffAllSegments_1(int totaldelay){
  fill_1();
  for(uint8_t pin=_a1; pin<=_g1; pin++) {
    digitalWrite(pin,_offValue);
    delay(totaldelay);
  }
}

void SevenSegmentSL1255::figure8Clock_1(int totaldelay){
  // a, b, g, e, d, c, g, f, a, ...
  blank_1();
  digitalWrite(_a1,_onValue);
  delay(totaldelay);
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_g1,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_e1,_onValue);
  delay(totaldelay);
  digitalWrite(_e1,_offValue);
  digitalWrite(_d1,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_c1,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_g1,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_f1,_onValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8Anticlock_1(int totaldelay){
  // a, f, g, c, d, e, g, b, a, ...
  blank_1();
  digitalWrite(_f1,_onValue);
  delay(totaldelay);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_c1,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  delay(totaldelay);
  digitalWrite(_e1,_offValue);
  digitalWrite(_g1,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_b1,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_a1,_onValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8ClockInvert_1(int totaldelay){
  // a, b, g, e, d, c, g, f, a, ...
  fill_1();
  digitalWrite(_a1,_offValue);
  delay(totaldelay);
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_g1,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_e1,_offValue);
  delay(totaldelay);
  digitalWrite(_e1,_onValue);
  digitalWrite(_d1,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_c1,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_g1,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_f1,_offValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8AnticlockInvert_1(int totaldelay){
  // a, f, g, c, d, e, g, b, a, ...
  fill_1();
  digitalWrite(_f1,_offValue);
  delay(totaldelay);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_c1,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  delay(totaldelay);
  digitalWrite(_e1,_onValue);
  digitalWrite(_g1,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_b1,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_a1,_offValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

//Start Rotate First Digit

void SevenSegmentSL1255::rotateTopClock_1(int totaldelay){
  // a, b, g, f, a, ...
  blank_1();
  digitalWrite(_a1,_onValue);
  delay(totaldelay);
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_g1,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_f1,_onValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopAnticlock_1(int totaldelay){
  // a, f, g, b, a, ...
  blank_1();
  digitalWrite(_f1,_onValue);
  delay(totaldelay);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_b1,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_a1,_onValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopClockInvert_1(int totaldelay){
  // a, b, g, f, a, ...
  fill_1();// draw top circle, not 8?
  digitalWrite(_a1,_offValue);
  delay(totaldelay);
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_g1,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_f1,_offValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopAnticlockInvert_1(int totaldelay){
  // a, f, g, b, a, ...
  fill_1();// draw top circle, not 8?
  digitalWrite(_f1,_offValue);
  delay(totaldelay);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_b1,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_a1,_offValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomClock_1(int totaldelay){
  // g, c, d, e, g, ...
  blank_1();
  digitalWrite(_g1,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_c1,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  delay(totaldelay);
//  digitalWrite(_e1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomAnticlock_1(int totaldelay){
  // g, e, d, c, g, ...
  blank_1();
  digitalWrite(_e1,_onValue);
  delay(totaldelay);
  digitalWrite(_e1,_offValue);
  digitalWrite(_d1,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_c1,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_g1,_onValue);
  delay(totaldelay);
//  digitalWrite(_g1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomClockInvert_1(int totaldelay){
  // g, c, d, e, g, ...
  fill_1();// draw bottom circle, not 8?
  digitalWrite(_g1,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_c1,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  delay(totaldelay);
//  digitalWrite(_e1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomAnticlockInvert_1(int totaldelay){
  // g, e, d, c, g, ...
  fill_1();// draw bottom circle, not 8?
  digitalWrite(_e1,_offValue);
  delay(totaldelay);
  digitalWrite(_e1,_onValue);
  digitalWrite(_d1,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_c1,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_g1,_offValue);
  delay(totaldelay);
//  digitalWrite(_g1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothClock_1(int totaldelay){
  // a, b, g, f, a, ...
  // g, c, d, e, g, ...
  blank_1();
  digitalWrite(_a1,_onValue);
  digitalWrite(_g1,_onValue);
  delay(totaldelay);
  digitalWrite(_a1,_offValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_d1,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_e1,_onValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothAnticlock_1(int totaldelay){
  // a, f, g, b, a, ...
  // g, e, d, c, g, ...
  blank_1();
  digitalWrite(_f1,_onValue);
  digitalWrite(_e1,_onValue);
  delay(totaldelay);
  digitalWrite(_f1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_d1,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_a1,_onValue);
  digitalWrite(_g1,_onValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothClockInvert_1(int totaldelay){
  // a, b, g, f, a, ...
  // g, c, d, e, g, ...
  fill_1();// draw top circle, not 8?
  digitalWrite(_a1,_offValue);
  digitalWrite(_g1,_offValue);
  delay(totaldelay);
  digitalWrite(_a1,_onValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_d1,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_e1,_offValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothAnticlockInvert_1(int totaldelay){
  // a, f, g, b, a, ...
  // g, e, d, c, g, ...
  fill_1();// draw top circle, not 8?
  digitalWrite(_f1,_offValue);
  digitalWrite(_e1,_offValue);
  delay(totaldelay);
  digitalWrite(_f1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_d1,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_a1,_offValue);
  digitalWrite(_g1,_offValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleClock_1(int totaldelay){
  // a, b, c, d, e, f, a, ...
  blank_1();
  digitalWrite(_a1,_onValue);
  delay(totaldelay);
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  delay(totaldelay);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleAnticlock_1(int totaldelay){
  // a, f, e, d, c, b, a, ...
  blank_1();
  digitalWrite(_f1,_onValue);
  delay(totaldelay);
  digitalWrite(_f1,_offValue);
  digitalWrite(_e1,_onValue);
  delay(totaldelay);
  digitalWrite(_e1,_offValue);
  digitalWrite(_d1,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_c1,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_b1,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_a1,_onValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleClockInvert_1(int totaldelay){
  // a, b, c, d, e, f, a, ...
  fill_1();// draw circle (draw_0x), not 8?
  digitalWrite(_a1,_offValue);
  delay(totaldelay);
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  delay(totaldelay);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleAnticlockInvert_1(int totaldelay){
  // a, f, e, d, c, b, a, ...
  fill_1();// draw circle (draw_0x), not 8?
  digitalWrite(_f1,_offValue);
  delay(totaldelay);
  digitalWrite(_f1,_onValue);
  digitalWrite(_e1,_offValue);
  delay(totaldelay);
  digitalWrite(_e1,_onValue);
  digitalWrite(_d1,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_c1,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_b1,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_a1,_offValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}


//End Rotate First Digit

// *** Least Significant Digit ***
// Hex chars (1st digit)

void SevenSegmentSL1255::draw_x0(void) {
  draw_0_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/
}

void SevenSegmentSL1255::draw_x1(void) {
  draw_1_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_x2(void) {
  draw_2_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_x3(void) {
  draw_3_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_x4(void) {
  draw_4_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_x5(void) {
  draw_5_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_x6(void) {
  draw_6_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_x7(void) {
  draw_7_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_x8(void) {
  draw_8_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_x9(void) {
  draw_9_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xA(void) {
  draw_A_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xa(void) {
  draw_a_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xB(void) {
  draw_B_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xb(void) {
  draw_b_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xC(void) {
  draw_C_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xc(void) {
  draw_c_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xD(void) {
  draw_D_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xd(void) {
  draw_d_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xE(void) {
  draw_E_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xe(void) {
  draw_e_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xF(void) {
  draw_F_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xf(void) {
  draw_f_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

// Extra Letters

void SevenSegmentSL1255::draw_xG(void) {
  draw_G_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xg(void) {
  draw_g_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xH(void) {
  draw_H_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xh(void) {
  draw_h_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xI(void) {
  draw_I_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xi(void) {
  draw_i_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xJ(void) {
  draw_J_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xj(void) {
  draw_j_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xK(void) {
  draw_K_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xk(void) {
  draw_k_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xL(void) {
  draw_L_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xl(void) {
  draw_l_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xM(void) {
  draw_M_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xm(void) {
  draw_m_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xN(void) {
  draw_N_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xn(void) {
  draw_n_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xO(void) {
  draw_O_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xo(void) {
  draw_o_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xP(void) {
  draw_P_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xp(void) {
  draw_p_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xQ(void) {
  draw_Q_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xq(void) {
  draw_q_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xR(void) {
  draw_R_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xr(void) {
  draw_r_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xS(void) {
  draw_S_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xs(void) {
  draw_s_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xT(void) {
  draw_T_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xt(void) {
  draw_t_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xU(void) {
  draw_U_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xu(void) {
  draw_u_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xV(void) {
  draw_V_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xv(void) {
  draw_v_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xW(void) {
  draw_W_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xw(void) {
  draw_w_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
*/}

void SevenSegmentSL1255::draw_xX(void) {
  draw_X_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

//void SevenSegmentSL1255::draw_xx(void) {
//  digitalWrite(_a2,_offValue);
//  digitalWrite(_b2,_onValue);
//  digitalWrite(_c2,_onValue);
//  digitalWrite(_d2,_offValue);
//  digitalWrite(_e2,_onValue);
//  digitalWrite(_f2,_onValue);
//  digitalWrite(_g2,_onValue);
//*/}

void SevenSegmentSL1255::draw_xY(void) {
  draw_Y_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xy(void) {
  draw_y_2();

/*
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xZ(void) {
  draw_Z_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
*/}

void SevenSegmentSL1255::draw_xz(void) {
  draw_z_2();

/*
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
*/}

// Symbols
void SevenSegmentSL1255::draw_xdegree(void) {
  draw_degree_0();
}


// Effects (1st digit)

void SevenSegmentSL1255::effect_0(uint8_t index) {
	int defaultDelay = default_delay;
	effect_0(index, defaultDelay);
}

void SevenSegmentSL1255::effect_0(uint8_t index, int totaldelay) {
	switch (index) {
		case 0 :
			blank_0();
			break;
		case 1 :
			flash_0(totaldelay);
			break;
		case 2 :
			rotateOnSegment_0(totaldelay);
			break;
		case 3 :
			rotateOffSegment_0(totaldelay);
			break;
		case 4 :
			sequentiallyTurnOnAllSegments_0(totaldelay);
			break;
		case 5 :
			sequentiallyTurnOffAllSegments_0(totaldelay);
			break;
		case 6 :
			figure8Clock_0(totaldelay);
			break;
		case 7 :
			figure8Anticlock_0(totaldelay);
			break;
		case 8 :
			figure8ClockInvert_0(totaldelay);
			break;
		case 9 :
			figure8AnticlockInvert_0(totaldelay);
			break;
		case 10 :
			rotateTopClock_0(totaldelay);
			break;
		case 11 :
			rotateTopAnticlock_0(totaldelay);
			break;
		case 12 :
			rotateTopClockInvert_0(totaldelay);
			break;
		case 13 :
			rotateTopAnticlockInvert_0(totaldelay);
			break;
		case 14 :
			rotateBottomClock_0(totaldelay);
			break;
		case 15 :
			rotateBottomAnticlock_0(totaldelay);
			break;
		case 16 :
			rotateBottomClockInvert_0(totaldelay);
			break;
		case 17 :
			rotateBottomAnticlockInvert_0(totaldelay);
			break;
		case 18 :
			rotateBothClock_0(totaldelay);
			break;
		case 19 :
			rotateBothAnticlock_0(totaldelay);
			break;
		case 20 :
			rotateBothClockInvert_0(totaldelay);
			break;
		case 21 :
			rotateBothAnticlockInvert_0(totaldelay);
			break;
		case 22 :
			rotateCircleClock_0(totaldelay);
			break;
		case 23 :
			rotateCircleAnticlock_0(totaldelay);
			break;
		case 24 :
			rotateCircleClockInvert_0(totaldelay);
			break;
		case 25 :
			rotateCircleAnticlockInvert_0(totaldelay);
			break;
		default :
			break;
	}
}

void SevenSegmentSL1255::blank_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::fill_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::flash_0(int totaldelay) {
  blank_0();
  delay (totaldelay/2);
  fill_0();
  delay (totaldelay/2);
}

// This only works if the pins are sequential
void SevenSegmentSL1255::rotateOffSegment_0(int totaldelay){
  fill_0();
  for(uint8_t pin=_a2; pin<=_g2; pin++) {
    digitalWrite(pin,_offValue);
    delay(totaldelay/2);
    digitalWrite(pin,_onValue);
    delay(totaldelay/2);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::rotateOnSegment_0(int totaldelay){
  blank_0();
  for(uint8_t pin=_a2; pin<=_g2; pin++) {
    digitalWrite(pin,_onValue);
    delay(totaldelay/2);
    digitalWrite(pin,_offValue);
    delay(totaldelay/2);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::sequentiallyTurnOnAllSegments_0(int totaldelay){
  blank_0();
  for(uint8_t pin=_a2; pin<=_g2; pin++) {
    digitalWrite(pin,_onValue);
    delay(totaldelay);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::sequentiallyTurnOffAllSegments_0(int totaldelay){
  fill_0();
  for(uint8_t pin=_a2; pin<=_g2; pin++) {
    digitalWrite(pin,_offValue);
    delay(totaldelay);
  }
}

void SevenSegmentSL1255::figure8Clock_0(int totaldelay){
  // a, b, g, e, d, c, g, f, a, ...
  blank_0();
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8Anticlock_0(int totaldelay){
  // a, f, g, c, d, e, g, b, a, ...
  blank_0();
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8ClockInvert_0(int totaldelay){
  // a, b, g, e, d, c, g, f, a, ...
  fill_0();
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8AnticlockInvert_0(int totaldelay){
  // a, f, g, c, d, e, g, b, a, ...
  fill_0();
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

//Start Rotate First Digit

void SevenSegmentSL1255::rotateTopClock_0(int totaldelay){
  // a, b, g, f, a, ...
  blank_0();
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopAnticlock_0(int totaldelay){
  // a, f, g, b, a, ...
  blank_0();
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopClockInvert_0(int totaldelay){
  // a, b, g, f, a, ...
  fill_0();// draw top circle, not 8?
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopAnticlockInvert_0(int totaldelay){
  // a, f, g, b, a, ...
  fill_0();// draw top circle, not 8?
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomClock_0(int totaldelay){
  // g, c, d, e, g, ...
  blank_0();
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomAnticlock_0(int totaldelay){
  // g, e, d, c, g, ...
  blank_0();
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomClockInvert_0(int totaldelay){
  // g, c, d, e, g, ...
  fill_0();// draw bottom circle, not 8?
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomAnticlockInvert_0(int totaldelay){
  // g, e, d, c, g, ...
  fill_0();// draw bottom circle, not 8?
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothClock_0(int totaldelay){
  // a, b, g, f, a, ...
  // g, c, d, e, g, ...
  blank_0();
  digitalWrite(_a2,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_a2,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothAnticlock_0(int totaldelay){
  // a, f, g, b, a, ...
  // g, e, d, c, g, ...
  blank_0();
  digitalWrite(_f2,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_f2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_a2,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothClockInvert_0(int totaldelay){
  // a, b, g, f, a, ...
  // g, c, d, e, g, ...
  fill_0();// draw top circle, not 8?
  digitalWrite(_a2,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_a2,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothAnticlockInvert_0(int totaldelay){
  // a, f, g, b, a, ...
  // g, e, d, c, g, ...
  fill_0();// draw top circle, not 8?
  digitalWrite(_f2,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_f2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_a2,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleClock_0(int totaldelay){
  // a, b, c, d, e, f, a, ...
  blank_0();
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleAnticlock_0(int totaldelay){
  // a, f, e, d, c, b, a, ...
  blank_0();
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
  digitalWrite(_f2,_offValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleClockInvert_0(int totaldelay){
  // a, b, c, d, e, f, a, ...
  fill_0();// draw circle (draw_0x), not 8?
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleAnticlockInvert_0(int totaldelay){
  // a, f, e, d, c, b, a, ...
  fill_0();// draw circle (draw_0x), not 8?
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
  digitalWrite(_f2,_onValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

// Using SL-1255 Notion of LSD Digit 0 is Digit 2
// Effects (1st digit) (Least Significant)

void SevenSegmentSL1255::effect_2(uint8_t index) {
	int defaultDelay = default_delay;
	effect_2(index, defaultDelay);
}

void SevenSegmentSL1255::effect_2(uint8_t index, int totaldelay) {
	switch (index) {
		case 0 :
			blank_2();
			break;
		case 1 :
			flash_2(totaldelay);
			break;
		case 2 :
			rotateOnSegment_2(totaldelay);
			break;
		case 3 :
			rotateOffSegment_2(totaldelay);
			break;
		case 4 :
			sequentiallyTurnOnAllSegments_2(totaldelay);
			break;
		case 5 :
			sequentiallyTurnOffAllSegments_2(totaldelay);
			break;
		case 6 :
			figure8Clock_2(totaldelay);
			break;
		case 7 :
			figure8Anticlock_2(totaldelay);
			break;
		case 8 :
			figure8ClockInvert_2(totaldelay);
			break;
		case 9 :
			figure8AnticlockInvert_2(totaldelay);
			break;
		case 10 :
			rotateTopClock_2(totaldelay);
			break;
		case 11 :
			rotateTopAnticlock_2(totaldelay);
			break;
		case 12 :
			rotateTopClockInvert_2(totaldelay);
			break;
		case 13 :
			rotateTopAnticlockInvert_2(totaldelay);
			break;
		case 14 :
			rotateBottomClock_2(totaldelay);
			break;
		case 15 :
			rotateBottomAnticlock_2(totaldelay);
			break;
		case 16 :
			rotateBottomClockInvert_2(totaldelay);
			break;
		case 17 :
			rotateBottomAnticlockInvert_2(totaldelay);
			break;
		case 18 :
			rotateBothClock_2(totaldelay);
			break;
		case 19 :
			rotateBothAnticlock_2(totaldelay);
			break;
		case 20 :
			rotateBothClockInvert_2(totaldelay);
			break;
		case 21 :
			rotateBothAnticlockInvert_2(totaldelay);
			break;
		case 22 :
			rotateCircleClock_2(totaldelay);
			break;
		case 23 :
			rotateCircleAnticlock_2(totaldelay);
			break;
		case 24 :
			rotateCircleClockInvert_2(totaldelay);
			break;
		case 25 :
			rotateCircleAnticlockInvert_2(totaldelay);
			break;
		default :
			break;
	}
}

void SevenSegmentSL1255::blank_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::xblank(void) {
  blank_2();
}

void SevenSegmentSL1255::fill_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::xfill(void) {
  fill_2();
}

void SevenSegmentSL1255::flash_2(int totaldelay) {
  blank_2();
  delay (totaldelay/2);
  fill_2();
  delay (totaldelay/2);
}

void SevenSegmentSL1255::xflash(int totaldelay) {
  flash_2(totaldelay);
}

// This only works if the pins are sequential
void SevenSegmentSL1255::rotateOffSegment_2(int totaldelay){
  fill_2();
  for(uint8_t pin=_a2; pin<=_g2; pin++) {
    digitalWrite(pin,_offValue);
    delay(totaldelay/2);
    digitalWrite(pin,_onValue);
    delay(totaldelay/2);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::rotateOnSegment_2(int totaldelay){
  blank_2();
  for(uint8_t pin=_a2; pin<=_g2; pin++) {
    digitalWrite(pin,_onValue);
    delay(totaldelay/2);
    digitalWrite(pin,_offValue);
    delay(totaldelay/2);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::sequentiallyTurnOnAllSegments_2(int totaldelay){
  blank_2();
  for(uint8_t pin=_a2; pin<=_g2; pin++) {
    digitalWrite(pin,_onValue);
    delay(totaldelay);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::sequentiallyTurnOffAllSegments_2(int totaldelay){
  fill_2();
  for(uint8_t pin=_a2; pin<=_g2; pin++) {
    digitalWrite(pin,_offValue);
    delay(totaldelay);
  }
}

void SevenSegmentSL1255::figure8Clock_2(int totaldelay){
  // a, b, g, e, d, c, g, f, a, ...
  blank_2();
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8Anticlock_2(int totaldelay){
  // a, f, g, c, d, e, g, b, a, ...
  blank_2();
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8ClockInvert_2(int totaldelay){
  // a, b, g, e, d, c, g, f, a, ...
  fill_2();
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8AnticlockInvert_2(int totaldelay){
  // a, f, g, c, d, e, g, b, a, ...
  fill_2();
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

//Start Rotate First Digit

void SevenSegmentSL1255::rotateTopClock_2(int totaldelay){
  // a, b, g, f, a, ...
  blank_2();
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopAnticlock_2(int totaldelay){
  // a, f, g, b, a, ...
  blank_2();
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopClockInvert_2(int totaldelay){
  // a, b, g, f, a, ...
  fill_2();// draw top circle, not 8?
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopAnticlockInvert_2(int totaldelay){
  // a, f, g, b, a, ...
  fill_2();// draw top circle, not 8?
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomClock_2(int totaldelay){
  // g, c, d, e, g, ...
  blank_2();
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomAnticlock_2(int totaldelay){
  // g, e, d, c, g, ...
  blank_2();
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomClockInvert_2(int totaldelay){
  // g, c, d, e, g, ...
  fill_2();// draw bottom circle, not 8?
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomAnticlockInvert_2(int totaldelay){
  // g, e, d, c, g, ...
  fill_2();// draw bottom circle, not 8?
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothClock_2(int totaldelay){
  // a, b, g, f, a, ...
  // g, c, d, e, g, ...
  blank_2();
  digitalWrite(_a2,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_a2,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothAnticlock_2(int totaldelay){
  // a, f, g, b, a, ...
  // g, e, d, c, g, ...
  blank_2();
  digitalWrite(_f2,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_f2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_a2,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothClockInvert_2(int totaldelay){
  // a, b, g, f, a, ...
  // g, c, d, e, g, ...
  fill_2();// draw top circle, not 8?
  digitalWrite(_a2,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_a2,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothAnticlockInvert_2(int totaldelay){
  // a, f, g, b, a, ...
  // g, e, d, c, g, ...
  fill_2();// draw top circle, not 8?
  digitalWrite(_f2,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_f2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_a2,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleClock_2(int totaldelay){
  // a, b, c, d, e, f, a, ...
  blank_2();
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleAnticlock_2(int totaldelay){
  // a, f, e, d, c, b, a, ...
  blank_2();
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
  digitalWrite(_f2,_offValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e2,_offValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d2,_offValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c2,_offValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b2,_offValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleClockInvert_2(int totaldelay){
  // a, b, c, d, e, f, a, ...
  fill_2();// draw circle (draw_0x), not 8?
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleAnticlockInvert_2(int totaldelay){
  // a, f, e, d, c, b, a, ...
  fill_2();// draw circle (draw_0x), not 8?
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
  digitalWrite(_f2,_onValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e2,_onValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d2,_onValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c2,_onValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b2,_onValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}



// Number placement
// *** Most Significant Digit ***
// Hex chars (2nd digit)


void SevenSegmentSL1255::draw_0_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_1_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_2_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_3_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_4_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_5_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_6_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_7_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_8_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_9_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_A_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_a_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_B_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_b_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_C_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_c_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_D_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_d_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_E_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_e_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_F_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_f_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

// Extra Letters

void SevenSegmentSL1255::draw_G_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_g_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_H_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_h_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_I_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_i_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_J_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_j_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_K_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_k_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_L_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_l_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_M_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_m_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_N_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_n_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_O_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_o_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_P_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_p_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_Q_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_q_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_R_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_r_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_S_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_s_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_T_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_t_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_U_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_u_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_V_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_v_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_W_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_w_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_offValue);
}

void SevenSegmentSL1255::draw_X_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_x_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_Y_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_y_1(void) {
  digitalWrite(_a1,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_Z_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
}

void SevenSegmentSL1255::draw_z_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_g1,_onValue);
}

// Symbols
void SevenSegmentSL1255::draw_degree_1(void) {
  digitalWrite(_a1,_onValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_g1,_onValue);
}

// *** Least Significant Digit ***
// Hex chars (1st digit)


void SevenSegmentSL1255::draw_0_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_1_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_2_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_3_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_4_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_5_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_6_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_7_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_8_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_9_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_A_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_a_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_B_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_b_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_C_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_c_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_D_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_d_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_E_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_e_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_F_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_f_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

// Extra Letters

void SevenSegmentSL1255::draw_G_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_g_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_H_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_h_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_I_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_i_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_J_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_j_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_K_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_k_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_L_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_l_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_M_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_m_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_N_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_n_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_O_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_o_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_P_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_p_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_Q_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_q_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_R_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_r_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_S_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_s_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_T_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_t_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_U_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_u_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_V_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_v_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_W_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_w_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_X_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_x_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_Y_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_y_0(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_Z_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_z_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

// Symbols
void SevenSegmentSL1255::draw_degree_0(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}


// *** Least Significant Digit (using SL-1255 notion of LSD is digit 2) ***
// Hex chars (1st digit)


void SevenSegmentSL1255::draw_0_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_1_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_2_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_3_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_4_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_5_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_6_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_7_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_8_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_9_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_A_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_a_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_B_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_b_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_C_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_c_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_D_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_d_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_E_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_e_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_F_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_f_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

// Extra Letters

void SevenSegmentSL1255::draw_G_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_g_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_H_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_h_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_I_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_i_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_J_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_j_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_K_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_k_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_L_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_l_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_M_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_m_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_N_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_n_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_O_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_o_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_P_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_p_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_Q_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_q_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_R_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_r_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_S_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_s_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_T_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_t_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_U_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_u_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_V_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_v_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_W_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_w_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_offValue);
}

void SevenSegmentSL1255::draw_X_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_x_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_Y_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_y_2(void) {
  digitalWrite(_a2,_offValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_Z_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

void SevenSegmentSL1255::draw_z_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g2,_onValue);
}

// Symbols
void SevenSegmentSL1255::draw_degree_2(void) {
  digitalWrite(_a2,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g2,_onValue);
}

// Simultaneous Effects on digits 1 and 2

void SevenSegmentSL1255::effect_3(uint8_t index) {
	int defaultDelay = default_delay;
	effect_3(index, defaultDelay);
}

void SevenSegmentSL1255::effect_3(uint8_t index, int totaldelay) {
	switch (index) {
		case 0 :
			blank_3();
			break;
		case 1 :
			flash_3(totaldelay);
			break;
		case 2 :
			rotateOnSegment_3(totaldelay);
			break;
		case 3 :
			rotateOffSegment_3(totaldelay);
			break;
		case 4 :
			sequentiallyTurnOnAllSegments_3(totaldelay);
			break;
		case 5 :
			sequentiallyTurnOffAllSegments_3(totaldelay);
			break;
		case 6 :
			figure8Clock_3(totaldelay);
			break;
		case 7 :
			figure8Anticlock_3(totaldelay);
			break;
		case 8 :
			figure8ClockInvert_3(totaldelay);
			break;
		case 9 :
			figure8AnticlockInvert_3(totaldelay);
			break;
		case 10 :
			rotateTopClock_3(totaldelay);
			break;
		case 11 :
			rotateTopAnticlock_3(totaldelay);
			break;
		case 12 :
			rotateTopClockInvert_3(totaldelay);
			break;
		case 13 :
			rotateTopAnticlockInvert_3(totaldelay);
			break;
		case 14 :
			rotateBottomClock_3(totaldelay);
			break;
		case 15 :
			rotateBottomAnticlock_3(totaldelay);
			break;
		case 16 :
			rotateBottomClockInvert_3(totaldelay);
			break;
		case 17 :
			rotateBottomAnticlockInvert_3(totaldelay);
			break;
		case 18 :
			rotateBothClock_3(totaldelay);
			break;
		case 19 :
			rotateBothAnticlock_3(totaldelay);
			break;
		case 20 :
			rotateBothClockInvert_3(totaldelay);
			break;
		case 21 :
			rotateBothAnticlockInvert_3(totaldelay);
			break;
		case 22 :
			rotateCircleClock_3(totaldelay);
			break;
		case 23 :
			rotateCircleAnticlock_3(totaldelay);
			break;
		case 24 :
			rotateCircleClockInvert_3(totaldelay);
			break;
		case 25 :
			rotateCircleAnticlockInvert_3(totaldelay);
			break;
		default :
			break;
	}
}

void SevenSegmentSL1255::blank_3(void) {
  blank_1();
  blank_2();
}

void SevenSegmentSL1255::xblankx(void) {
  blank_3();
}

void SevenSegmentSL1255::fill_3(void) {
  fill_1();
  fill_2();
}

void SevenSegmentSL1255::xfillx(void) {
  fill_3();
}

void SevenSegmentSL1255::flash_3(int totaldelay) {
  blank_3();
  delay (totaldelay/2);
  fill_3();
  delay (totaldelay/2);
}

void SevenSegmentSL1255::xflashx(int totaldelay) {
  flash_3(totaldelay);
}

// This only works if the pins are sequential
void SevenSegmentSL1255::rotateOffSegment_3(int totaldelay){
  fill_3();
  for(uint8_t pin=_a1; pin<=_g1; pin++) {
    digitalWrite(pin,_offValue);
    digitalWrite(pin+7,_offValue);
    delay(totaldelay/2);
    digitalWrite(pin,_onValue);
    digitalWrite(pin+7,_onValue);
    delay(totaldelay/2);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::rotateOnSegment_3(int totaldelay){
  blank_3();
  for(uint8_t pin=_a1; pin<=_g1; pin++) {
    digitalWrite(pin,_onValue);
    digitalWrite(pin+7,_onValue);
    delay(totaldelay/2);
    digitalWrite(pin,_offValue);
    digitalWrite(pin+7,_offValue);
    delay(totaldelay/2);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::sequentiallyTurnOnAllSegments_3(int totaldelay){
  blank_3();
  for(uint8_t pin=_a1; pin<=_g1; pin++) {
    digitalWrite(pin,_onValue);
    digitalWrite(pin+7,_onValue);
    delay(totaldelay);
  }
}

// This only works if the pins are sequential
void SevenSegmentSL1255::sequentiallyTurnOffAllSegments_3(int totaldelay){
  fill_3();
  for(uint8_t pin=_a1; pin<=_g1; pin++) {
    digitalWrite(pin,_offValue);
    digitalWrite(pin+7,_offValue);
    delay(totaldelay);
  }
}

void SevenSegmentSL1255::figure8Clock_3(int totaldelay){
  // a, b, g, e, d, c, g, f, a, ...
  blank_3();
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8Anticlock_3(int totaldelay){
  // a, f, g, c, d, e, g, b, a, ...
  blank_3();
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8ClockInvert_3(int totaldelay){
  // a, b, g, e, d, c, g, f, a, ...
  fill_3();
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::figure8AnticlockInvert_3(int totaldelay){
  // a, f, g, c, d, e, g, b, a, ...
  fill_3();
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

//Start Rotate First Digit

void SevenSegmentSL1255::rotateTopClock_3(int totaldelay){
  // a, b, g, f, a, ...
  blank_3();
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopAnticlock_3(int totaldelay){
  // a, f, g, b, a, ...
  blank_3();
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopClockInvert_3(int totaldelay){
  // a, b, g, f, a, ...
  fill_3();// draw top circle, not 8?
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateTopAnticlockInvert_3(int totaldelay){
  // a, f, g, b, a, ...
  fill_3();// draw top circle, not 8?
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomClock_3(int totaldelay){
  // g, c, d, e, g, ...
  blank_3();
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
//  digitalWrite(_e1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomAnticlock_3(int totaldelay){
  // g, e, d, c, g, ...
  blank_3();
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
//  digitalWrite(_g1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomClockInvert_3(int totaldelay){
  // g, c, d, e, g, ...
  fill_3();// draw bottom circle, not 8?
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
//  digitalWrite(_e1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBottomAnticlockInvert_3(int totaldelay){
  // g, e, d, c, g, ...
  fill_3();// draw bottom circle, not 8?
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
//  digitalWrite(_g1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothClock_3(int totaldelay){
  // a, b, g, f, a, ...
  // g, c, d, e, g, ...
  blank_3();
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothAnticlock_3(int totaldelay){
  // a, f, g, b, a, ...
  // g, e, d, c, g, ...
  blank_3();
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothClockInvert_3(int totaldelay){
  // a, b, g, f, a, ...
  // g, c, d, e, g, ...
  fill_3();// draw top circle, not 8?
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_e2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateBothAnticlockInvert_3(int totaldelay){
  // a, f, g, b, a, ...
  // g, e, d, c, g, ...
  fill_3();// draw top circle, not 8?
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_g1,_onValue);
  digitalWrite(_g2,_onValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  digitalWrite(_g1,_offValue);
  digitalWrite(_g2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_g2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleClock_3(int totaldelay){
  // a, b, c, d, e, f, a, ...
  blank_3();
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleAnticlock_3(int totaldelay){
  // a, f, e, d, c, b, a, ...
  blank_3();
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  delay(totaldelay);
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  delay(totaldelay);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  delay(totaldelay);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  delay(totaldelay);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  delay(totaldelay);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleClockInvert_3(int totaldelay){
  // a, b, c, d, e, f, a, ...
  fill_3();// draw circle (draw_0x), not 8?
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
  digitalWrite(_a1,_onValue);
  digitalWrite(_a2,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
//  digitalWrite(_f1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_f2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}

void SevenSegmentSL1255::rotateCircleAnticlockInvert_3(int totaldelay){
  // a, f, e, d, c, b, a, ...
  fill_3();// draw circle (draw_0x), not 8?
  digitalWrite(_f1,_offValue);
  digitalWrite(_f2,_offValue);
  delay(totaldelay);
  digitalWrite(_f1,_onValue);
  digitalWrite(_f2,_onValue);
  digitalWrite(_e1,_offValue);
  digitalWrite(_e2,_offValue);
  delay(totaldelay);
  digitalWrite(_e1,_onValue);
  digitalWrite(_e2,_onValue);
  digitalWrite(_d1,_offValue);
  digitalWrite(_d2,_offValue);
  delay(totaldelay);
  digitalWrite(_d1,_onValue);
  digitalWrite(_d2,_onValue);
  digitalWrite(_c1,_offValue);
  digitalWrite(_c2,_offValue);
  delay(totaldelay);
  digitalWrite(_c1,_onValue);
  digitalWrite(_c2,_onValue);
  digitalWrite(_b1,_offValue);
  digitalWrite(_b2,_offValue);
  delay(totaldelay);
  digitalWrite(_b1,_onValue);
  digitalWrite(_b2,_onValue);
  digitalWrite(_a1,_offValue);
  digitalWrite(_a2,_offValue);
  delay(totaldelay);
//  digitalWrite(_a1,_offValue); //each new effect should kill the "trailing" lit LED
//  digitalWrite(_a2,_offValue); //each new effect should kill the "trailing" lit LED
//  delay(totaldelay);			 //of the previous effect
}


//Get State
// pass pin number 2, 3, 4, ..., 16
uint8_t SevenSegmentSL1255::getPinState(uint8_t pin){
	return (digitalRead(pin));
}

// pass segment name a1...g1, a2...g2
/*
uint8_t SevenSegmentSL1255::getSegmentState(char segment[]){
	uint8_t pin;
	switch (segment) {
		case 'a0' :
			pin=_a2;
			break;
		case 'b0' :
			pin=_b2;
			break;
		case 'c0' :
			pin=_c2;
			break;
		case 'd0' :
			pin=_d2;
			break;
		case 'e0' :
			pin=_e2;
			break;
		case 'f0' :
			pin=_f2;
			break;
		case 'g0' :
			pin=_g2;
			break;
		case 'a1' :
			pin=_a1;
			break;
		case 'b1' :
			pin=_b1;
			break;
		case 'c1' :
			pin=_c1;
			break;
		case 'd1' :
			pin=_d1;
			break;
		case 'e1' :
			pin=_e1;
			break;
		case 'f1' :
			pin=_f1;
			break;
		case 'g1' :
			pin=_g1;
			break;
		case 'a2' :
			pin=_a2;
			break;
		case 'b2' :
			pin=_b2;
			break;
		case 'c2' :
			pin=_c2;
			break;
		case 'd2' :
			pin=_d2;
			break;
		case 'e2' :
			pin=_e2;
			break;
		case 'f2' :
			pin=_f2;
			break;
		case 'g2' :
			pin=_g2;
			break;
		default :
			pin = _a2;
			break;
	}
	return (digitalRead(pin));
}
*/

// pass segment name a1...g1, a2...g2
uint8_t SevenSegmentSL1255::getSegmentState(char segment[]){
	uint8_t pin;
	pin = getPinFromSegment(segment);
/*
	if (!strcmp(segment, "a0"))
			pin=_a2;
	if (!strcmp(segment, "b0"))
			pin=_b2;
	if (!strcmp(segment, "c0"))
			pin=_c2;
	if (!strcmp(segment, "d0"))
			pin=_d2;
	if (!strcmp(segment, "e0"))
			pin=_e2;
	if (!strcmp(segment, "f0"))
			pin=_f2;
	if (!strcmp(segment, "g0"))
			pin=_g2;
	if (!strcmp(segment, "a1"))
			pin=_a1;
	if (!strcmp(segment, "b1"))
			pin=_b1;
	if (!strcmp(segment, "c1"))
			pin=_c1;
	if (!strcmp(segment, "d1"))
			pin=_d1;
	if (!strcmp(segment, "e1"))
			pin=_e1;
	if (!strcmp(segment, "f1"))
			pin=_f1;
	if (!strcmp(segment, "g1"))
			pin=_g1;
	if (!strcmp(segment, "a2"))
			pin=_a2;
	if (!strcmp(segment, "b2"))
			pin=_b2;
	if (!strcmp(segment, "c2"))
			pin=_c2;
	if (!strcmp(segment, "d2"))
			pin=_d2;
	if (!strcmp(segment, "e2"))
			pin=_e2;
	if (!strcmp(segment, "f2"))
			pin=_f2;
	if (!strcmp(segment, "g2"))
			pin=_g2;
*/
	return (digitalRead(pin));
}

// static 2 (for C99) force two characters array (should be 3?)
uint8_t SevenSegmentSL1255::getPinFromSegment(char segment[/*static 2*/]){
	uint8_t pin;
	if (!strcmp(segment, "a0"))
			pin=_a2;
	if (!strcmp(segment, "b0"))
			pin=_b2;
	if (!strcmp(segment, "c0"))
			pin=_c2;
	if (!strcmp(segment, "d0"))
			pin=_d2;
	if (!strcmp(segment, "e0"))
			pin=_e2;
	if (!strcmp(segment, "f0"))
			pin=_f2;
	if (!strcmp(segment, "g0"))
			pin=_g2;
	if (!strcmp(segment, "a1"))
			pin=_a1;
	if (!strcmp(segment, "b1"))
			pin=_b1;
	if (!strcmp(segment, "c1"))
			pin=_c1;
	if (!strcmp(segment, "d1"))
			pin=_d1;
	if (!strcmp(segment, "e1"))
			pin=_e1;
	if (!strcmp(segment, "f1"))
			pin=_f1;
	if (!strcmp(segment, "g1"))
			pin=_g1;
	if (!strcmp(segment, "a2"))
			pin=_a2;
	if (!strcmp(segment, "b2"))
			pin=_b2;
	if (!strcmp(segment, "c2"))
			pin=_c2;
	if (!strcmp(segment, "d2"))
			pin=_d2;
	if (!strcmp(segment, "e2"))
			pin=_e2;
	if (!strcmp(segment, "f2"))
			pin=_f2;
	if (!strcmp(segment, "g2"))
			pin=_g2;
	return (pin);
}

// get the state for each segment
// of digit 1
uint8_t SevenSegmentSL1255::getState_a1(void) {
	return (digitalRead(_a1));
}

uint8_t SevenSegmentSL1255::getState_b1(void) {
	return(digitalRead(_b1));
}

uint8_t SevenSegmentSL1255::getState_c1(void) {
	return(digitalRead(_c1));
}

uint8_t SevenSegmentSL1255::getState_d1(void) {
	return(digitalRead(_d1));
}

uint8_t SevenSegmentSL1255::getState_e1(void) {
	return(digitalRead(_e1));
}

uint8_t SevenSegmentSL1255::getState_f1(void) {
	return(digitalRead(_f1));
}

uint8_t SevenSegmentSL1255::getState_g1(void) {
	return(digitalRead(_g1));
}

// get the state for each segment
// of digit 2 (aka digit 0)
uint8_t SevenSegmentSL1255::getState_a0(void) {
	return(digitalRead(_a2));
}

uint8_t SevenSegmentSL1255::getState_b0(void) {
	return(digitalRead(_b2));
}

uint8_t SevenSegmentSL1255::getState_c0(void) {
	return(digitalRead(_c2));
}

uint8_t SevenSegmentSL1255::getState_d0(void) {
	return(digitalRead(_d2));
}

uint8_t SevenSegmentSL1255::getState_e0(void) {
	return(digitalRead(_e2));
}

uint8_t SevenSegmentSL1255::getState_f0(void) {
	return(digitalRead(_f2));
}

uint8_t SevenSegmentSL1255::getState_g0(void) {
	return(digitalRead(_g2));
}

// get the state for each segment
// of digit 2 (aka digit 0)
uint8_t SevenSegmentSL1255::getState_a2(void) {
	return(digitalRead(_a2));
}

uint8_t SevenSegmentSL1255::getState_b2(void) {
	return(digitalRead(_b2));
}

uint8_t SevenSegmentSL1255::getState_c2(void) {
	return(digitalRead(_c2));
}

uint8_t SevenSegmentSL1255::getState_d2(void) {
	return(digitalRead(_d2));
}

uint8_t SevenSegmentSL1255::getState_e2(void) {
	return(digitalRead(_e2));
}

uint8_t SevenSegmentSL1255::getState_f2(void) {
	return(digitalRead(_f2));
}

uint8_t SevenSegmentSL1255::getState_g2(void) {
	return(digitalRead(_g2));
}

//Set State
// pass pin number 2, 3, 4, ..., 16
void SevenSegmentSL1255::setPinState(uint8_t pin, uint8_t value){
	digitalWrite(pin,value);
}

// pass segment name a1...g1, a2...g2
void SevenSegmentSL1255::setSegmentState(char segment[], uint8_t value){
	uint8_t pin;
	pin = getPinFromSegment(segment);
/*
	switch (segment) {
		case 'a0' :
			pin=_a2;
			break;
		case 'b0' :
			pin=_b2;
			break;
		case 'c0' :
			pin=_c2;
			break;
		case 'd0' :
			pin=_d2;
			break;
		case 'e0' :
			pin=_e2;
			break;
		case 'f0' :
			pin=_f2;
			break;
		case 'g0' :
			pin=_g2;
			break;
		case 'a1' :
			pin=_a1;
			break;
		case 'b1' :
			pin=_b1;
			break;
		case 'c1' :
			pin=_c1;
			break;
		case 'd1' :
			pin=_d1;
			break;
		case 'e1' :
			pin=_e1;
			break;
		case 'f1' :
			pin=_f1;
			break;
		case 'g1' :
			pin=_g1;
			break;
		case 'a2' :
			pin=_a2;
			break;
		case 'b2' :
			pin=_b2;
			break;
		case 'c2' :
			pin=_c2;
			break;
		case 'd2' :
			pin=_d2;
			break;
		case 'e2' :
			pin=_e2;
			break;
		case 'f2' :
			pin=_f2;
			break;
		case 'g2' :
			pin=_g2;
			break;
		default :
			pin=_a2;
			break;
	}
*/
	digitalWrite(pin,value);
}

// set the state for each segment
// of digit 1
void SevenSegmentSL1255::setState_a1(uint8_t value) {
	digitalWrite(_a1,value);
}

void SevenSegmentSL1255::setState_b1(uint8_t value) {
	digitalWrite(_b1,value);
}

void SevenSegmentSL1255::setState_c1(uint8_t value) {
	digitalWrite(_c1,value);
}

void SevenSegmentSL1255::setState_d1(uint8_t value) {
	digitalWrite(_d1,value);
}

void SevenSegmentSL1255::setState_e1(uint8_t value) {
	digitalWrite(_e1,value);
}

void SevenSegmentSL1255::setState_f1(uint8_t value) {
	digitalWrite(_f1,value);
}

void SevenSegmentSL1255::setState_g1(uint8_t value) {
	digitalWrite(_g1,value);
}

// set the state for each segment
// of digit 2 (aka digit 0)
void SevenSegmentSL1255::setState_a0(uint8_t value) {
	digitalWrite(_a2,value);
}

void SevenSegmentSL1255::setState_b0(uint8_t value) {
	digitalWrite(_b2,value);
}

void SevenSegmentSL1255::setState_c0(uint8_t value) {
	digitalWrite(_c2,value);
}

void SevenSegmentSL1255::setState_d0(uint8_t value) {
	digitalWrite(_d2,value);
}

void SevenSegmentSL1255::setState_e0(uint8_t value) {
	digitalWrite(_e2,value);
}

void SevenSegmentSL1255::setState_f0(uint8_t value) {
	digitalWrite(_f2,value);
}

void SevenSegmentSL1255::setState_g0(uint8_t value) {
	digitalWrite(_g2,value);
}

// set the state for each segment
// of digit 2 (aka digit 0)
void SevenSegmentSL1255::setState_a2(uint8_t value) {
	digitalWrite(_a2,value);
}

void SevenSegmentSL1255::setState_b2(uint8_t value) {
	digitalWrite(_b2,value);
}

void SevenSegmentSL1255::setState_c2(uint8_t value) {
	digitalWrite(_c2,value);
}

void SevenSegmentSL1255::setState_d2(uint8_t value) {
	digitalWrite(_d2,value);
}

void SevenSegmentSL1255::setState_e2(uint8_t value) {
	digitalWrite(_e2,value);
}

void SevenSegmentSL1255::setState_f2(uint8_t value) {
	digitalWrite(_f2,value);
}

void SevenSegmentSL1255::setState_g2(uint8_t value) {
	digitalWrite(_g2,value);
}

//Getters
uint8_t SevenSegmentSL1255::get_a1(void) {
	return (_a1);
}

uint8_t SevenSegmentSL1255::get_b1(void) {
	return(_b1);
}

uint8_t SevenSegmentSL1255::get_c1(void) {
	return(_c1);
}

uint8_t SevenSegmentSL1255::get_d1(void) {
	return(_d1);
}

uint8_t SevenSegmentSL1255::get_e1(void) {
	return(_e1);
}

uint8_t SevenSegmentSL1255::get_f1(void) {
	return(_f1);
}

uint8_t SevenSegmentSL1255::get_g1(void) {
	return(_g1);
}

uint8_t SevenSegmentSL1255::get_a0(void) {
	return(_a2);
}

uint8_t SevenSegmentSL1255::get_b0(void) {
	return(_b2);
}

uint8_t SevenSegmentSL1255::get_c0(void) {
	return(_c2);
}

uint8_t SevenSegmentSL1255::get_d0(void) {
	return(_d2);
}

uint8_t SevenSegmentSL1255::get_e0(void) {
	return(_e2);
}

uint8_t SevenSegmentSL1255::get_f0(void) {
	return(_f2);
}

uint8_t SevenSegmentSL1255::get_g0(void) {
	return(_g2);
}

uint8_t SevenSegmentSL1255::get_a2(void) {
	return(_a2);
}

uint8_t SevenSegmentSL1255::get_b2(void) {
	return(_b2);
}

uint8_t SevenSegmentSL1255::get_c2(void) {
	return(_c2);
}

uint8_t SevenSegmentSL1255::get_d2(void) {
	return(_d2);
}

uint8_t SevenSegmentSL1255::get_e2(void) {
	return(_e2);
}

uint8_t SevenSegmentSL1255::get_f2(void) {
	return(_f2);
}

uint8_t SevenSegmentSL1255::get_g2(void) {
	return(_g2);
}

uint8_t SevenSegmentSL1255::get_onValue(void) {
	return(_onValue);
}

uint8_t SevenSegmentSL1255::get_offValue(void) {
	return(_offValue);
}

uint8_t SevenSegmentSL1255::get_ssType(void) {
	return(_ssType);
}

//Setters
void SevenSegmentSL1255::set_a1(uint8_t value) {
	_a1=value;
}

void SevenSegmentSL1255::set_b1(uint8_t value) {
	_b1=value;
}

void SevenSegmentSL1255::set_c1(uint8_t value) {
	_c1=value;
}

void SevenSegmentSL1255::set_d1(uint8_t value) {
	_d1=value;
}

void SevenSegmentSL1255::set_e1(uint8_t value) {
	_e1=value;
}

void SevenSegmentSL1255::set_f1(uint8_t value) {
	_f1=value;
}

void SevenSegmentSL1255::set_g1(uint8_t value) {
	_g1=value;
}

void SevenSegmentSL1255::set_a0(uint8_t value) {
	_a2=value;
}

void SevenSegmentSL1255::set_b0(uint8_t value) {
	_b2=value;
}

void SevenSegmentSL1255::set_c0(uint8_t value) {
	_c2=value;
}

void SevenSegmentSL1255::set_d0(uint8_t value) {
	_d2=value;
}

void SevenSegmentSL1255::set_e0(uint8_t value) {
	_e2=value;
}

void SevenSegmentSL1255::set_f0(uint8_t value) {
	_f2=value;
}

void SevenSegmentSL1255::set_g0(uint8_t value) {
	_g2=value;
}

void SevenSegmentSL1255::set_a2(uint8_t value) {
	_a2=value;
}

void SevenSegmentSL1255::set_b2(uint8_t value) {
	_b2=value;
}

void SevenSegmentSL1255::set_c2(uint8_t value) {
	_c2=value;
}

void SevenSegmentSL1255::set_d2(uint8_t value) {
	_d2=value;
}

void SevenSegmentSL1255::set_e2(uint8_t value) {
	_e2=value;
}

void SevenSegmentSL1255::set_f2(uint8_t value) {
	_f2=value;
}

void SevenSegmentSL1255::set_g2(uint8_t value) {
	_g2=value;
}

void SevenSegmentSL1255::set_onValue(uint8_t value) {
	_onValue=value;
}

void SevenSegmentSL1255::set_offValue(uint8_t value) {
	_offValue=value;
}

void SevenSegmentSL1255::set_ssType(uint8_t value) {
	_ssType=value;
}

