/*
SevenSeg1255.h - Library for the:
						SL-1255-30 Red Seven Segment display (Common Anode)
						SL-1256-30 Red Seven Segment display (Common Cathode)
						SL-2255-30 Green Seven Segment display (Common Anode)
						SL-2256-30 Green Seven Segment display (Common Cathode)
Created by Mark G. Jenkins March 13 2015
Released into the public domain.
-------------------------------------------------------------------------------
Copyright (c) 2015, Greenonline, coded by Mark Graham Jenkins.

SevenSeg1255 Library is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

SevenSeg1255 Library is distributed in the hope that it will be useful,
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

/*
   inverted functions (all on, active led is off) - could just invert onValue/offValue?
   alt - alternate segments
*/

#ifndef SevenSeg1255_h
#define SevenSeg1255_h

#include "Arduino.h"
#include "SevenSegmentMaps.h"

// Pin out: Display1 Segment Pin#
#define default_a1 2
#define default_b1 3
#define default_c1 4
#define default_d1 5
#define default_e1 6
#define default_f1 7
#define default_g1 8

// Pin out: Display2 Segment Pin#
#define default_a2 9
#define default_b2 10
#define default_c2 11
#define default_d2 12
#define default_e2 13
#define default_f2 14
#define default_g2 15

// Pin out: Display2 Segment Pin#
#define default_a0 default_a0
#define default_b0 default_b0
#define default_c0 default_c0
#define default_d0 default_d0
#define default_e0 default_e0
#define default_f0 default_f0
#define default_g0 default_g0

// 7 segment type, common anode, or cathode
// The value of the model basically denotes the ON value for an LED,
// so as SL-1255 has a ON for LOW (0), common anode , then SL-1255 is 0
// so as SL-1256 has a ON for HIGH (1), common cathode , then SL-1256 is 1
#define SL_1255 0
#define SL_1256 1
#define SL_2255 0
#define SL_2256 1

// On is LOW for SL-1255
// On is HIGH for SL-1256
#define default_onValue LOW
#define default_offValue HIGH

#define default_delay 500

class SevenSeg1255
{
    public:
      SevenSeg1255();
      SevenSeg1255(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1);
      SevenSeg1255(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2);
      SevenSeg1255(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2, uint8_t ssType);
      SevenSeg1255(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2, uint8_t onValue, uint8_t offValue);

      void begin(void);

      // Direct Draw methods
      // *** Most Significant Digit ***
      // Hex chars (2nd digit)
      void draw_0x(void);
      void draw_1x(void);
      void draw_2x(void);
      void draw_3x(void);
      void draw_4x(void);
      void draw_5x(void);
      void draw_6x(void);
      void draw_7x(void);
      void draw_8x(void);
      void draw_9x(void);
      void draw_Ax(void);
      void draw_ax(void);
      void draw_Bx(void);
      void draw_bx(void);
      void draw_Cx(void);
      void draw_cx(void);
      void draw_Dx(void);
      void draw_dx(void);
      void draw_Ex(void);
      void draw_ex(void);
      void draw_Fx(void);
      void draw_fx(void);

      // Extra Letters
      void draw_Gx(void);
      void draw_gx(void);
      void draw_Hx(void);
      void draw_hx(void);
      void draw_Ix(void);
      void draw_ix(void);
      void draw_Jx(void);
      void draw_jx(void);
      void draw_Kx(void);
      void draw_kx(void);
      void draw_Lx(void);
      void draw_lx(void);
      void draw_Mx(void);
      void draw_mx(void);
      void draw_Nx(void);
      void draw_nx(void);
      void draw_Ox(void);
      void draw_ox(void);
      void draw_Px(void);
      void draw_px(void);
      void draw_Qx(void);
      void draw_qx(void);
      void draw_Rx(void);
      void draw_rx(void);
      void draw_Sx(void);
      void draw_sx(void);
      void draw_Tx(void);
      void draw_tx(void);
      void draw_Ux(void);
      void draw_ux(void);
      void draw_Vx(void);
      void draw_vx(void);
      void draw_Wx(void);
      void draw_wx(void);
      void draw_Xx(void);
      void draw_xx(void);
      void draw_Yx(void);
      void draw_yx(void);
      void draw_Zx(void);
      void draw_zx(void);

      // Symbols
      void draw_degreex(void);

      // Bitmap
      // uint8_t segmentMapCode is the bitwise byte of the segments to light (g1f1e1d1c1b1a1)
      void draw_bitmap2(uint8_t segmentMapCode);
      void draw_bitmapInvert2(uint8_t segmentMapCode);
      void draw2(uint8_t segmentMapCode); //just calls draw_bitmap2()
      void drawInvert2(uint8_t segmentMapCode); //just calls draw_bitmapInvert2()

      void draw_bitmap0(uint8_t segmentMapCode);
      void draw_bitmapInvert0(uint8_t segmentMapCode);
      void draw0(uint8_t segmentMapCode); //just calls draw_bitmap0()
      void drawInvert0(uint8_t segmentMapCode); //just calls draw_bitmapInvert0()

      void draw_bitmap1(uint8_t segmentMapCode);
      void draw_bitmapInvert1(uint8_t segmentMapCode);
      void draw1(uint8_t segmentMapCode); //just calls draw_bitmap1()
      void drawInvert1(uint8_t segmentMapCode); //just calls draw_bitmapInvert1()

      // Put
//      void putc(char character);
//      void putchar(char character);

      // Write
      // char character is the ascii code of the character to draw
      void digit2CharWrite(char character);
      // uint8_t value is the octal numerical value to draw (0-7)
      void digit2OctWrite(uint8_t value);
      // uint8_t value is the decimal numerical value to draw (0-9)
      void digit2DecWrite(uint8_t value);
      // uint8_t value is the numerical value to draw (0-F)
      void digit2HexWrite(uint8_t value);
      void digit2Write(uint8_t value);
      void write2(uint8_t value); //just calls digit2Write(uint8_t value)
      void digit2Write(char character);
      void write2(char character); //just calls digit2Write(char character)

      // char character is the ascii code of the character to draw
      void digit0CharWrite(char character);
      // uint8_t value is the octal numerical value to draw (0-7)
      void digit0OctWrite(uint8_t value);
      // uint8_t value is the decimal numerical value to draw (0-9)
      void digit0DecWrite(uint8_t value);
      // uint8_t value is the hexadecimal numerical value to draw (0-F)
      void digit0HexWrite(uint8_t value);
      void digit0Write(uint8_t value);
      void write0(uint8_t value); //just calls digit0Write(uint8_t value)
      void digit0Write(char character);
      void write0(char character); //just calls digit0Write(char character)

      // char character is the ascii code of the character to draw
      void digit1CharWrite(char character);
      // uint8_t value is the octal numerical value to draw (0-7)
      void digit1OctWrite(uint8_t value);
      // uint8_t value is the decimal numerical value to draw (0-9)
      void digit1DecWrite(uint8_t value);
      // uint8_t value is the hexadecimal numerical value to draw (0-F)
      void digit1HexWrite(uint8_t value);
      void digit1Write(uint8_t value);
      void write1(uint8_t value); //just calls digit1Write(uint8_t value)
      void digit1Write(char character);
      void write1(char character); //just calls digit1Write(char character)

      void write(uint8_t value); // have overload led?, prints two digits, calls write1 and write0, which each do only one digit (LSD, MSD?) <99
      void write(char characters[]);// two char array, string 2 characters

	  //Scroll Routines
	  //Default scroll() is to scroll left
      void scroll(char characters[]);// two char array, string 2 characters
      void scroll(char characters[], int delay);// two char array, string 2 characters
      void scroll(char characters[], int delay, int directionLeft);// two char array, string 2 characters

      void scrollLeft(char characters[]);// two char array, string 2 characters
      void scrollLeft(char characters[], int delay);// two char array, string 2 characters

      void scrollRight(char characters[]);// two char array, string 2 characters
      void scrollRight(char characters[], int delay);// two char array, string 2 characters

      void write(uint8_t value, uint8_t digit); // write to specific digit, calls digit1Write(uint8_t value) or digit0Write(uint8_t value) as appropriate
      void write(char character, uint8_t digit);// write to specific digit, calls digit1Write(char character) or digit0Write(char character) as appropriate


      // *** Most Significant Digit ***
      // Effects
      void effect_1(uint8_t index); //effect catalogue
      void effect_1(uint8_t index, int totaldelay); //effect catalogue
      void blankx(void);
      void fillx(void);
      void flashx(int totaldelay);
      void blank_1(void);
      void fill_1(void);
      void flash_1(int totaldelay);
      void rotateOnSegment_1(int totaldelay);
      void rotateOffSegment_1(int totaldelay);
      void sequentiallyTurnOnAllSegments_1(int totaldelay);
      void sequentiallyTurnOffAllSegments_1(int totaldelay);
      void figure8Clock_1(int totaldelay);
      void figure8Anticlock_1(int totaldelay);
      void figure8ClockInvert_1(int totaldelay);
      void figure8AnticlockInvert_1(int totaldelay);
      void rotateTopClock_1(int totaldelay);
      void rotateTopAnticlock_1(int totaldelay);
      void rotateTopClockInvert_1(int totaldelay);
      void rotateTopAnticlockInvert_1(int totaldelay);
      void rotateBottomClock_1(int totaldelay);
      void rotateBottomAnticlock_1(int totaldelay);
      void rotateBottomClockInvert_1(int totaldelay);
      void rotateBottomAnticlockInvert_1(int totaldelay);
      void rotateBothClock_1(int totaldelay);
      void rotateBothAnticlock_1(int totaldelay);
      void rotateBothClockInvert_1(int totaldelay);
      void rotateBothAnticlockInvert_1(int totaldelay);
//      void rotatebothaltclock_1(int totaldelay); //not required, call top and then bottom
//      void rotatebothaltanticlock_1(int totaldelay);//not required, call top and then bottom
      void rotateCircleClock_1(int totaldelay);
      void rotateCircleAnticlock_1(int totaldelay);
      void rotateCircleClockInvert_1(int totaldelay);
      void rotateCircleAnticlockInvert_1(int totaldelay);


      // *** Least Significant Digit ***
      // Direct Draw methods
      // Hex chars (1st digit)
      void draw_x0(void); // conflict with number placement
      void draw_x1(void); // conflict with number placement
      void draw_x2(void);
      void draw_x3(void);
      void draw_x4(void);
      void draw_x5(void);
      void draw_x6(void);
      void draw_x7(void);
      void draw_x8(void);
      void draw_x9(void);
      void draw_xA(void);
      void draw_xa(void);
      void draw_xB(void);
      void draw_xb(void);
      void draw_xC(void);
      void draw_xc(void);
      void draw_xD(void);
      void draw_xd(void);
      void draw_xE(void);
      void draw_xe(void);
      void draw_xF(void);
      void draw_xf(void);

      // Extra Letters
      void draw_xG(void);
      void draw_xg(void);
      void draw_xH(void);
      void draw_xh(void);
      void draw_xI(void);
      void draw_xi(void);
      void draw_xJ(void);
      void draw_xj(void);
      void draw_xK(void);
      void draw_xk(void);
      void draw_xL(void);
      void draw_xl(void);
      void draw_xM(void);
      void draw_xm(void);
      void draw_xN(void);
      void draw_xn(void);
      void draw_xO(void);
      void draw_xo(void);
      void draw_xP(void);
      void draw_xp(void);
      void draw_xQ(void);
      void draw_xq(void);
      void draw_xR(void);
      void draw_xr(void);
      void draw_xS(void);
      void draw_xs(void);
      void draw_xT(void);
      void draw_xt(void);
      void draw_xU(void);
      void draw_xu(void);
      void draw_xV(void);
      void draw_xv(void);
      void draw_xW(void);
      void draw_xw(void);
      void draw_xX(void);
//      void draw_xx(void); // conflict - MSD or LSD?
      void draw_xY(void);
      void draw_xy(void);
      void draw_xZ(void);
      void draw_xz(void);

      // Symbols
      void draw_xdegree(void);

      // Effects
      void effect_0(uint8_t index); //effect catalogue
      void effect_0(uint8_t index, int totaldelay); //effect catalogue
      void blank_0(void);
      void fill_0(void);
      void flash_0(int totaldelay);
      void rotateOnSegment_0(int totaldelay);
      void rotateOffSegment_0(int totaldelay);
      void sequentiallyTurnOnAllSegments_0(int totaldelay);
      void sequentiallyTurnOffAllSegments_0(int totaldelay);
      void figure8Clock_0(int totaldelay);
      void figure8Anticlock_0(int totaldelay);
      void figure8ClockInvert_0(int totaldelay);
      void figure8AnticlockInvert_0(int totaldelay);
      void rotateTopClock_0(int totaldelay);
      void rotateTopAnticlock_0(int totaldelay);
      void rotateTopClockInvert_0(int totaldelay);
      void rotateTopAnticlockInvert_0(int totaldelay);
      void rotateBottomClock_0(int totaldelay);
      void rotateBottomAnticlock_0(int totaldelay);
      void rotateBottomClockInvert_0(int totaldelay);
      void rotateBottomAnticlockInvert_0(int totaldelay);
      void rotateBothClock_0(int totaldelay);
      void rotateBothAnticlock_0(int totaldelay);
      void rotateBothClockInvert_0(int totaldelay);
      void rotateBothAnticlockInvert_0(int totaldelay);
//      void rotatebothaltclock_0(int totaldelay); //not required, call top and then bottom
//      void rotatebothaltanticlock_0(int totaldelay);//not required, call top and then bottom
      void rotateCircleClock_0(int totaldelay);
      void rotateCircleAnticlock_0(int totaldelay);
      void rotateCircleClockInvert_0(int totaldelay);
      void rotateCircleAnticlockInvert_0(int totaldelay);

	  // Using SL-1255 Notion of LSD Digit 0 is Digit 2
	  // Effects (1st digit) (Least Significant)
      void effect_2(uint8_t index); //effect catalogue
      void effect_2(uint8_t index, int totaldelay); //effect catalogue
      void xblank(void);
      void xfill(void);
      void xflash(int totaldelay);
      void blank_2(void);
      void fill_2(void);
      void flash_2(int totaldelay);
      void rotateOnSegment_2(int totaldelay);
      void rotateOffSegment_2(int totaldelay);
      void sequentiallyTurnOnAllSegments_2(int totaldelay);
      void sequentiallyTurnOffAllSegments_2(int totaldelay);
      void figure8Clock_2(int totaldelay);
      void figure8Anticlock_2(int totaldelay);
      void figure8ClockInvert_2(int totaldelay);
      void figure8AnticlockInvert_2(int totaldelay);
      void rotateTopClock_2(int totaldelay);
      void rotateTopAnticlock_2(int totaldelay);
      void rotateTopClockInvert_2(int totaldelay);
      void rotateTopAnticlockInvert_2(int totaldelay);
      void rotateBottomClock_2(int totaldelay);
      void rotateBottomAnticlock_2(int totaldelay);
      void rotateBottomClockInvert_2(int totaldelay);
      void rotateBottomAnticlockInvert_2(int totaldelay);
      void rotateBothClock_2(int totaldelay);
      void rotateBothAnticlock_2(int totaldelay);
      void rotateBothClockInvert_2(int totaldelay);
      void rotateBothAnticlockInvert_2(int totaldelay);
//      void rotatebothaltclock_2(int totaldelay); //not required, call top and then bottom
//      void rotatebothaltanticlock_2(int totaldelay);//not required, call top and then bottom
      void rotateCircleClock_2(int totaldelay);
      void rotateCircleAnticlock_2(int totaldelay);
      void rotateCircleClockInvert_2(int totaldelay);
      void rotateCircleAnticlockInvert_2(int totaldelay);



      // *** Most Significant Digit ***
      // Hex chars (2nd digit)
      void draw_0_1(void);
      void draw_1_1(void);
      void draw_2_1(void);
      void draw_3_1(void);
      void draw_4_1(void);
      void draw_5_1(void);
      void draw_6_1(void);
      void draw_7_1(void);
      void draw_8_1(void);
      void draw_9_1(void);
      void draw_A_1(void);
      void draw_a_1(void);
      void draw_B_1(void);
      void draw_b_1(void);
      void draw_C_1(void);
      void draw_c_1(void);
      void draw_D_1(void);
      void draw_d_1(void);
      void draw_E_1(void);
      void draw_e_1(void);
      void draw_F_1(void);
      void draw_f_1(void);

      // Extra Letters
      void draw_G_1(void);
      void draw_g_1(void);
      void draw_H_1(void);
      void draw_h_1(void);
      void draw_I_1(void);
      void draw_i_1(void);
      void draw_J_1(void);
      void draw_j_1(void);
      void draw_K_1(void);
      void draw_k_1(void);
      void draw_L_1(void);
      void draw_l_1(void);
      void draw_M_1(void);
      void draw_m_1(void);
      void draw_N_1(void);
      void draw_n_1(void);
      void draw_O_1(void);
      void draw_o_1(void);
      void draw_P_1(void);
      void draw_p_1(void);
      void draw_Q_1(void);
      void draw_q_1(void);
      void draw_R_1(void);
      void draw_r_1(void);
      void draw_S_1(void);
      void draw_s_1(void);
      void draw_T_1(void);
      void draw_t_1(void);
      void draw_U_1(void);
      void draw_u_1(void);
      void draw_V_1(void);
      void draw_v_1(void);
      void draw_W_1(void);
      void draw_w_1(void);
      void draw_X_1(void);
      void draw_x_1(void);
      void draw_Y_1(void);
      void draw_y_1(void);
      void draw_Z_1(void);
      void draw_z_1(void);

      // Symbols
      void draw_degree_1(void);

      // *** Least Significant Digit ***
      // Hex chars (1st digit)
      void draw_0_0(void);
      void draw_1_0(void);
      void draw_2_0(void);
      void draw_3_0(void);
      void draw_4_0(void);
      void draw_5_0(void);
      void draw_6_0(void);
      void draw_7_0(void);
      void draw_8_0(void);
      void draw_9_0(void);
      void draw_A_0(void);
      void draw_a_0(void);
      void draw_B_0(void);
      void draw_b_0(void);
      void draw_C_0(void);
      void draw_c_0(void);
      void draw_D_0(void);
      void draw_d_0(void);
      void draw_E_0(void);
      void draw_e_0(void);
      void draw_F_0(void);
      void draw_f_0(void);

      // Extra Letters
      void draw_G_0(void);
      void draw_g_0(void);
      void draw_H_0(void);
      void draw_h_0(void);
      void draw_I_0(void);
      void draw_i_0(void);
      void draw_J_0(void);
      void draw_j_0(void);
      void draw_K_0(void);
      void draw_k_0(void);
      void draw_L_0(void);
      void draw_l_0(void);
      void draw_M_0(void);
      void draw_m_0(void);
      void draw_N_0(void);
      void draw_n_0(void);
      void draw_O_0(void);
      void draw_o_0(void);
      void draw_P_0(void);
      void draw_p_0(void);
      void draw_Q_0(void);
      void draw_q_0(void);
      void draw_R_0(void);
      void draw_r_0(void);
      void draw_S_0(void);
      void draw_s_0(void);
      void draw_T_0(void);
      void draw_t_0(void);
      void draw_U_0(void);
      void draw_u_0(void);
      void draw_V_0(void);
      void draw_v_0(void);
      void draw_W_0(void);
      void draw_w_0(void);
      void draw_X_0(void);
      void draw_x_0(void); //conflict with old name
      void draw_Y_0(void);
      void draw_y_0(void);
      void draw_Z_0(void);
      void draw_z_0(void);

      // Symbols
      void draw_degree_0(void);

      // *** Least Significant Digit (using SL-1255 notion of LSD is digit 2) ***
      // Hex chars (1st digit)
      void draw_0_2(void);
      void draw_1_2(void);
      void draw_2_2(void);
      void draw_3_2(void);
      void draw_4_2(void);
      void draw_5_2(void);
      void draw_6_2(void);
      void draw_7_2(void);
      void draw_8_2(void);
      void draw_9_2(void);
      void draw_A_2(void);
      void draw_a_2(void);
      void draw_B_2(void);
      void draw_b_2(void);
      void draw_C_2(void);
      void draw_c_2(void);
      void draw_D_2(void);
      void draw_d_2(void);
      void draw_E_2(void);
      void draw_e_2(void);
      void draw_F_2(void);
      void draw_f_2(void);

      // Extra Letters
      void draw_G_2(void);
      void draw_g_2(void);
      void draw_H_2(void);
      void draw_h_2(void);
      void draw_I_2(void);
      void draw_i_2(void);
      void draw_J_2(void);
      void draw_j_2(void);
      void draw_K_2(void);
      void draw_k_2(void);
      void draw_L_2(void);
      void draw_l_2(void);
      void draw_M_2(void);
      void draw_m_2(void);
      void draw_N_2(void);
      void draw_n_2(void);
      void draw_O_2(void);
      void draw_o_2(void);
      void draw_P_2(void);
      void draw_p_2(void);
      void draw_Q_2(void);
      void draw_q_2(void);
      void draw_R_2(void);
      void draw_r_2(void);
      void draw_S_2(void);
      void draw_s_2(void);
      void draw_T_2(void);
      void draw_t_2(void);
      void draw_U_2(void);
      void draw_u_2(void);
      void draw_V_2(void);
      void draw_v_2(void);
      void draw_W_2(void);
      void draw_w_2(void);
      void draw_X_2(void);
      void draw_x_2(void);
      void draw_Y_2(void);
      void draw_y_2(void);
      void draw_Z_2(void);
      void draw_z_2(void);

      // Symbols
      void draw_degree_2(void);

// Simultaneous Effects on digits 1 and 2
      // Effects
      void effect_3(uint8_t index); //effect catalogue
      void effect_3(uint8_t index, int totaldelay); //effect catalogue
      void xblankx(void);
      void xfillx(void);
      void xflashx(int totaldelay);
      void blank_3(void);
      void fill_3(void);
      void flash_3(int totaldelay);
      void rotateOnSegment_3(int totaldelay);
      void rotateOffSegment_3(int totaldelay);
      void sequentiallyTurnOnAllSegments_3(int totaldelay);
      void sequentiallyTurnOffAllSegments_3(int totaldelay);
      void figure8Clock_3(int totaldelay);
      void figure8Anticlock_3(int totaldelay);
      void figure8ClockInvert_3(int totaldelay);
      void figure8AnticlockInvert_3(int totaldelay);
      void rotateTopClock_3(int totaldelay);
      void rotateTopAnticlock_3(int totaldelay);
      void rotateTopClockInvert_3(int totaldelay);
      void rotateTopAnticlockInvert_3(int totaldelay);
      void rotateBottomClock_3(int totaldelay);
      void rotateBottomAnticlock_3(int totaldelay);
      void rotateBottomClockInvert_3(int totaldelay);
      void rotateBottomAnticlockInvert_3(int totaldelay);
      void rotateBothClock_3(int totaldelay);
      void rotateBothAnticlock_3(int totaldelay);
      void rotateBothClockInvert_3(int totaldelay);
      void rotateBothAnticlockInvert_3(int totaldelay);
//      void rotatebothaltclock_3(int totaldelay); //not required, call top and then bottom
//      void rotatebothaltanticlock_3(int totaldelay);//not required, call top and then bottom
      void rotateCircleClock_3(int totaldelay);
      void rotateCircleAnticlock_3(int totaldelay);
      void rotateCircleClockInvert_3(int totaldelay);
      void rotateCircleAnticlockInvert_3(int totaldelay);

      //Get State
	  uint8_t getPinState(uint8_t pin); // pass pin number 2, 3, 4, ..., 16
      uint8_t getPinFromSegment(char segment[]);
	  uint8_t getSegmentState(char segment[]); // pass segment name a1...g1, a2...g2
      // get the state for each segment
      // of digit 1
      uint8_t getState_a1(void);
      uint8_t getState_b1(void);
      uint8_t getState_c1(void);
      uint8_t getState_d1(void);
      uint8_t getState_e1(void);
      uint8_t getState_f1(void);
      uint8_t getState_g1(void);
      // get the state for each segment
      // of digit 2 (aka digit 0)
      uint8_t getState_a0(void);
      uint8_t getState_b0(void);
      uint8_t getState_c0(void);
      uint8_t getState_d0(void);
      uint8_t getState_e0(void);
      uint8_t getState_f0(void);
      uint8_t getState_g0(void);
      // get the state for each segment
      // of digit 2 (aka digit 0)
      uint8_t getState_a2(void);
      uint8_t getState_b2(void);
      uint8_t getState_c2(void);
      uint8_t getState_d2(void);
      uint8_t getState_e2(void);
      uint8_t getState_f2(void);
      uint8_t getState_g2(void);

      //Set State
	  void setPinState(uint8_t pin, uint8_t value);				// pass pin number 2, 3, 4, ..., 16
// static 2 (for C99) force two characters array (should be 3?)
	  void setSegmentState(char segment[/*static 2*/], uint8_t value); // pass segment name a1...g1, a2...g2
      // set the state for each segment
      // of digit 1
      void setState_a1(uint8_t value);
      void setState_b1(uint8_t value);
      void setState_c1(uint8_t value);
      void setState_d1(uint8_t value);
      void setState_e1(uint8_t value);
      void setState_f1(uint8_t value);
      void setState_g1(uint8_t value);
      // set the state for each segment
      // of digit 2 (aka digit 0)
      void setState_a0(uint8_t value);
      void setState_b0(uint8_t value);
      void setState_c0(uint8_t value);
      void setState_d0(uint8_t value);
      void setState_e0(uint8_t value);
      void setState_f0(uint8_t value);
      // set the state for each segment
      // of digit 2 (aka digit 0)
      void setState_g0(uint8_t value);
      void setState_a2(uint8_t value);
      void setState_b2(uint8_t value);
      void setState_c2(uint8_t value);
      void setState_d2(uint8_t value);
      void setState_e2(uint8_t value);
      void setState_f2(uint8_t value);
      void setState_g2(uint8_t value);


      //Accessors
      //getters
      // get the pin assignments for each segment
      // of digit 1
      uint8_t get_a1(void);
      uint8_t get_b1(void);
      uint8_t get_c1(void);
      uint8_t get_d1(void);
      uint8_t get_e1(void);
      uint8_t get_f1(void);
      uint8_t get_g1(void);
      // get the pin assignments for each segment
      // of digit 2 (aka digit 0)
      uint8_t get_a0(void);
      uint8_t get_b0(void);
      uint8_t get_c0(void);
      uint8_t get_d0(void);
      uint8_t get_e0(void);
      uint8_t get_f0(void);
      uint8_t get_g0(void);
      // get the pin assignments for each segment
      // of digit 2 (aka digit 0)
      uint8_t get_a2(void);
      uint8_t get_b2(void);
      uint8_t get_c2(void);
      uint8_t get_d2(void);
      uint8_t get_e2(void);
      uint8_t get_f2(void);
      uint8_t get_g2(void);

      uint8_t get_onValue(void);
      uint8_t get_offValue(void);
      uint8_t get_ssType(void);


      //setters
      // set the pin assignments for each segment
      // of digit 1
      void set_a1(uint8_t value);
      void set_b1(uint8_t value);
      void set_c1(uint8_t value);
      void set_d1(uint8_t value);
      void set_e1(uint8_t value);
      void set_f1(uint8_t value);
      void set_g1(uint8_t value);
      // set the pin assignments for each segment
      // of digit 2 (aka digit 0)
      void set_a0(uint8_t value);
      void set_b0(uint8_t value);
      void set_c0(uint8_t value);
      void set_d0(uint8_t value);
      void set_e0(uint8_t value);
      void set_f0(uint8_t value);
      void set_g0(uint8_t value);
      // set the pin assignments for each segment
      // of digit 2 (aka digit 0)
      void set_a2(uint8_t value);
      void set_b2(uint8_t value);
      void set_c2(uint8_t value);
      void set_d2(uint8_t value);
      void set_e2(uint8_t value);
      void set_f2(uint8_t value);
      void set_g2(uint8_t value);

      void set_onValue(uint8_t value);
      void set_offValue(uint8_t value);
      void set_ssType(uint8_t value);


    private:
      void init(void);
      void init(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1);
      void init(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2);
      void init(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2, uint8_t ssType);
      void init(uint8_t a1, uint8_t b1, uint8_t c1, uint8_t d1, uint8_t e1, uint8_t f1, uint8_t g1, uint8_t a2, uint8_t b2, uint8_t c2, uint8_t d2, uint8_t e2, uint8_t f2, uint8_t g2, uint8_t onValue, uint8_t offValue);

	  // The segments
	  // Digit 1
      uint8_t _a1;
      uint8_t _b1;
      uint8_t _c1;
      uint8_t _d1;
      uint8_t _e1;
      uint8_t _f1;
      uint8_t _g1;

	  // Digit 2
//      uint8_t _a0;
//      uint8_t _b0;
//      uint8_t _c0;
//      uint8_t _d0;
//      uint8_t _e0;
//      uint8_t _f0;
//      uint8_t _g0;

      uint8_t _a2;
      uint8_t _b2;
      uint8_t _c2;
      uint8_t _d2;
      uint8_t _e2;
      uint8_t _f2;
      uint8_t _g2;

      uint8_t _onValue;
      uint8_t _offValue;

      uint8_t _ssType; // seven segment type, 0 (SL-1255) or 1 (SL-1256)

      static const uint8_t _asciiTable[128]; // = {s0, s1, s2, s3, s4, s5, s6, s7, s8, s9};
      static const uint8_t _hexTable[16];   // = {s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sb, sC, sd, sE, sF}; //for hexWrite()
      static const uint8_t _decTable[10];   // = {s0, s1, s2, s3, s4, s5, s6, s7, s8, s9}; //for decWrite()
      static const uint8_t _octTable[8];    // = {s0, s1, s2, s3, s4, s5, s6, s7}; //for octWrite()

};


#endif
