/*
DrawAlphaNum.ino

Cycles through the direct draw character methods supplied in the SevenSegmentSL1255 class, repeatedly.

Demonstrates the methods:
  begin();
  draw_<char>x();
  draw_x<char>();
  draw_<char>_0();
  draw_<char>_1();
  draw_<char>_2();

If you're unsure which pins to use to connect the seven segment display to on your
Arduino model, check the readme that came with this package or the documentation 
at https://github.com/greenonline/

This example code is in the public domain.

Created by Mark G. Jenkins March 13 2015
Modified 5 Apr 2015
Released into the public domain.
-------------------------------------------------------------------------------
Copyright (c) 2015, Greenonline, coded by Mark Graham Jenkins.
http://greenonline.co.uk

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

    SevenSegmentSL1255
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
 
#include "SevenSegmentSL1255.h"

#define defaultDelay 500

SevenSegmentSL1255 sevenSeg1255;

// the setup function runs once when you press reset or power the board
void setup() {
  sevenSeg1255.begin(); // set the (default) pins to output
}

// the loop function runs over and over again forever
void loop() {
      // *** Most Significant Digit ***
      // Hex chars (2nd digit)
       sevenSeg1255.draw_0x();
       delay(defaultDelay);
       sevenSeg1255.draw_1x();
       delay(defaultDelay);
       sevenSeg1255.draw_2x();
       delay(defaultDelay);
       sevenSeg1255.draw_3x();
       delay(defaultDelay);
       sevenSeg1255.draw_4x();
       delay(defaultDelay);
       sevenSeg1255.draw_5x();
       delay(defaultDelay);
       sevenSeg1255.draw_6x();
       delay(defaultDelay);
       sevenSeg1255.draw_7x();
       delay(defaultDelay);
       sevenSeg1255.draw_8x();
       delay(defaultDelay);
       sevenSeg1255.draw_9x();
       delay(defaultDelay);
       sevenSeg1255.draw_Ax();
       delay(defaultDelay);
       sevenSeg1255.draw_ax();
       delay(defaultDelay);
       sevenSeg1255.draw_bx();
       delay(defaultDelay);
       sevenSeg1255.draw_Cx();
       delay(defaultDelay);
       sevenSeg1255.draw_cx();
       delay(defaultDelay);
       sevenSeg1255.draw_dx();
       delay(defaultDelay);
       sevenSeg1255.draw_Ex();
       delay(defaultDelay);
       sevenSeg1255.draw_ex();
       delay(defaultDelay);
       sevenSeg1255.draw_Fx();
       delay(defaultDelay);

      // Extra Letters
       sevenSeg1255.draw_Gx();
       delay(defaultDelay);
       sevenSeg1255.draw_gx();
       delay(defaultDelay);
       sevenSeg1255.draw_Hx();
       delay(defaultDelay);
       sevenSeg1255.draw_hx();
       delay(defaultDelay);
       sevenSeg1255.draw_Ix();
       delay(defaultDelay);
       sevenSeg1255.draw_ix();
       delay(defaultDelay);
       sevenSeg1255.draw_Jx();
       delay(defaultDelay);
       sevenSeg1255.draw_jx();
       delay(defaultDelay);
       sevenSeg1255.draw_Kx();
       delay(defaultDelay);
       sevenSeg1255.draw_kx();
       delay(defaultDelay);
       sevenSeg1255.draw_Lx();
       delay(defaultDelay);
       sevenSeg1255.draw_lx();
       delay(defaultDelay);
       sevenSeg1255.draw_Mx();
       delay(defaultDelay);
       sevenSeg1255.draw_mx();
       delay(defaultDelay);
       sevenSeg1255.draw_Nx();
       delay(defaultDelay);
       sevenSeg1255.draw_nx();
       delay(defaultDelay);
       sevenSeg1255.draw_Ox();
       delay(defaultDelay);
       sevenSeg1255.draw_ox();
       delay(defaultDelay);
       sevenSeg1255.draw_Px();
       delay(defaultDelay);
       sevenSeg1255.draw_px();
       delay(defaultDelay);
       sevenSeg1255.draw_Qx();
       delay(defaultDelay);
       sevenSeg1255.draw_qx();
       delay(defaultDelay);
       sevenSeg1255.draw_Rx();
       delay(defaultDelay);
       sevenSeg1255.draw_rx();
       delay(defaultDelay);
       sevenSeg1255.draw_Sx();
       delay(defaultDelay);
       sevenSeg1255.draw_sx();
       delay(defaultDelay);
       sevenSeg1255.draw_Tx();
       delay(defaultDelay);
       sevenSeg1255.draw_tx();
       delay(defaultDelay);
       sevenSeg1255.draw_Ux();
       delay(defaultDelay);
       sevenSeg1255.draw_ux();
       delay(defaultDelay);
       sevenSeg1255.draw_Vx();
       delay(defaultDelay);
       sevenSeg1255.draw_vx();
       delay(defaultDelay);
       sevenSeg1255.draw_Wx();
       delay(defaultDelay);
       sevenSeg1255.draw_wx();
       delay(defaultDelay);
       sevenSeg1255.draw_Xx();
       delay(defaultDelay);
       sevenSeg1255.draw_xx();
       delay(defaultDelay);
       sevenSeg1255.draw_Yx();
       delay(defaultDelay);
       sevenSeg1255.draw_yx();
       delay(defaultDelay);
       sevenSeg1255.draw_Zx();
       delay(defaultDelay);
       sevenSeg1255.draw_zx();
       delay(defaultDelay);

      // Symbols
       sevenSeg1255.draw_degreex();
       delay(defaultDelay);


      // *** Least Significant Digit ***
      // Hex chars (1st digit)
       sevenSeg1255.draw_x0();
       delay(defaultDelay);
       sevenSeg1255.draw_x1();
       delay(defaultDelay);
       sevenSeg1255.draw_x2();
       delay(defaultDelay);
       sevenSeg1255.draw_x3();
       delay(defaultDelay);
       sevenSeg1255.draw_x4();
       delay(defaultDelay);
       sevenSeg1255.draw_x5();
       delay(defaultDelay);
       sevenSeg1255.draw_x6();
       delay(defaultDelay);
       sevenSeg1255.draw_x7();
       delay(defaultDelay);
       sevenSeg1255.draw_x8();
       delay(defaultDelay);
       sevenSeg1255.draw_x9();
       delay(defaultDelay);
       sevenSeg1255.draw_xA();
       delay(defaultDelay);
       sevenSeg1255.draw_xa();
       delay(defaultDelay);
       sevenSeg1255.draw_xb();
       delay(defaultDelay);
       sevenSeg1255.draw_xC();
       delay(defaultDelay);
       sevenSeg1255.draw_xc();
       delay(defaultDelay);
       sevenSeg1255.draw_xd();
       delay(defaultDelay);
       sevenSeg1255.draw_xE();
       delay(defaultDelay);
       sevenSeg1255.draw_xe();
       delay(defaultDelay);
       sevenSeg1255.draw_xF();
       delay(defaultDelay);

      // Extra Letters
       sevenSeg1255.draw_xG();
       delay(defaultDelay);
       sevenSeg1255.draw_xg();
       delay(defaultDelay);
       sevenSeg1255.draw_xH();
       delay(defaultDelay);
       sevenSeg1255.draw_xh();
       delay(defaultDelay);
       sevenSeg1255.draw_xI();
       delay(defaultDelay);
       sevenSeg1255.draw_xi();
       delay(defaultDelay);
       sevenSeg1255.draw_xJ();
       delay(defaultDelay);
       sevenSeg1255.draw_xj();
       delay(defaultDelay);
       sevenSeg1255.draw_xK();
       delay(defaultDelay);
       sevenSeg1255.draw_xk();
       delay(defaultDelay);
       sevenSeg1255.draw_xL();
       delay(defaultDelay);
       sevenSeg1255.draw_xl();
       delay(defaultDelay);
       sevenSeg1255.draw_xM();
       delay(defaultDelay);
       sevenSeg1255.draw_xm();
       delay(defaultDelay);
       sevenSeg1255.draw_xN();
       delay(defaultDelay);
       sevenSeg1255.draw_xn();
       delay(defaultDelay);
       sevenSeg1255.draw_xO();
       delay(defaultDelay);
       sevenSeg1255.draw_xo();
       delay(defaultDelay);
       sevenSeg1255.draw_xP();
       delay(defaultDelay);
       sevenSeg1255.draw_xp();
       delay(defaultDelay);
       sevenSeg1255.draw_xQ();
       delay(defaultDelay);
       sevenSeg1255.draw_xq();
       delay(defaultDelay);
       sevenSeg1255.draw_xR();
       delay(defaultDelay);
       sevenSeg1255.draw_xr();
       delay(defaultDelay);
       sevenSeg1255.draw_xS();
       delay(defaultDelay);
       sevenSeg1255.draw_xs();
       delay(defaultDelay);
       sevenSeg1255.draw_xT();
       delay(defaultDelay);
       sevenSeg1255.draw_xt();
       delay(defaultDelay);
       sevenSeg1255.draw_xU();
       delay(defaultDelay);
       sevenSeg1255.draw_xu();
       delay(defaultDelay);
       sevenSeg1255.draw_xV();
       delay(defaultDelay);
       sevenSeg1255.draw_xv();
       delay(defaultDelay);
       sevenSeg1255.draw_xW();
       delay(defaultDelay);
       sevenSeg1255.draw_xw();
       delay(defaultDelay);
       sevenSeg1255.draw_xX();
       delay(defaultDelay);
       sevenSeg1255.draw_xx(); //this is why x no good
       delay(defaultDelay);
       sevenSeg1255.draw_xY();
       delay(defaultDelay);
       sevenSeg1255.draw_xy();
       delay(defaultDelay);
       sevenSeg1255.draw_xZ();
       delay(defaultDelay);
       sevenSeg1255.draw_xz();
       delay(defaultDelay);

      // Symbols
       sevenSeg1255.draw_xdegree();
       delay(defaultDelay);
       
       
      // *** Most Significant Digit ***
      // Hex chars (2nd digit)
       sevenSeg1255.draw_0_1();
       delay(defaultDelay);
       sevenSeg1255.draw_1_1();
       delay(defaultDelay);
       sevenSeg1255.draw_2_1();
       delay(defaultDelay);
       sevenSeg1255.draw_3_1();
       delay(defaultDelay);
       sevenSeg1255.draw_4_1();
       delay(defaultDelay);
       sevenSeg1255.draw_5_1();
       delay(defaultDelay);
       sevenSeg1255.draw_6_1();
       delay(defaultDelay);
       sevenSeg1255.draw_7_1();
       delay(defaultDelay);
       sevenSeg1255.draw_8_1();
       delay(defaultDelay);
       sevenSeg1255.draw_9_1();
       delay(defaultDelay);
       sevenSeg1255.draw_A_1();
       delay(defaultDelay);
       sevenSeg1255.draw_a_1();
       delay(defaultDelay);
       sevenSeg1255.draw_b_1();
       delay(defaultDelay);
       sevenSeg1255.draw_C_1();
       delay(defaultDelay);
       sevenSeg1255.draw_c_1();
       delay(defaultDelay);
       sevenSeg1255.draw_d_1();
       delay(defaultDelay);
       sevenSeg1255.draw_E_1();
       delay(defaultDelay);
       sevenSeg1255.draw_e_1();
       delay(defaultDelay);
       sevenSeg1255.draw_F_1();
       delay(defaultDelay);

      // Extra Letters
       sevenSeg1255.draw_G_1();
       delay(defaultDelay);
       sevenSeg1255.draw_g_1();
       delay(defaultDelay);
       sevenSeg1255.draw_H_1();
       delay(defaultDelay);
       sevenSeg1255.draw_h_1();
       delay(defaultDelay);
       sevenSeg1255.draw_I_1();
       delay(defaultDelay);
       sevenSeg1255.draw_i_1();
       delay(defaultDelay);
       sevenSeg1255.draw_J_1();
       delay(defaultDelay);
       sevenSeg1255.draw_j_1();
       delay(defaultDelay);
       sevenSeg1255.draw_K_1();
       delay(defaultDelay);
       sevenSeg1255.draw_k_1();
       delay(defaultDelay);
       sevenSeg1255.draw_L_1();
       delay(defaultDelay);
       sevenSeg1255.draw_l_1();
       delay(defaultDelay);
       sevenSeg1255.draw_M_1();
       delay(defaultDelay);
       sevenSeg1255.draw_m_1();
       delay(defaultDelay);
       sevenSeg1255.draw_N_1();
       delay(defaultDelay);
       sevenSeg1255.draw_n_1();
       delay(defaultDelay);
       sevenSeg1255.draw_O_1();
       delay(defaultDelay);
       sevenSeg1255.draw_o_1();
       delay(defaultDelay);
       sevenSeg1255.draw_P_1();
       delay(defaultDelay);
       sevenSeg1255.draw_p_1();
       delay(defaultDelay);
       sevenSeg1255.draw_Q_1();
       delay(defaultDelay);
       sevenSeg1255.draw_q_1();
       delay(defaultDelay);
       sevenSeg1255.draw_R_1();
       delay(defaultDelay);
       sevenSeg1255.draw_r_1();
       delay(defaultDelay);
       sevenSeg1255.draw_S_1();
       delay(defaultDelay);
       sevenSeg1255.draw_s_1();
       delay(defaultDelay);
       sevenSeg1255.draw_T_1();
       delay(defaultDelay);
       sevenSeg1255.draw_t_1();
       delay(defaultDelay);
       sevenSeg1255.draw_U_1();
       delay(defaultDelay);
       sevenSeg1255.draw_u_1();
       delay(defaultDelay);
       sevenSeg1255.draw_V_1();
       delay(defaultDelay);
       sevenSeg1255.draw_v_1();
       delay(defaultDelay);
       sevenSeg1255.draw_W_1();
       delay(defaultDelay);
       sevenSeg1255.draw_w_1();
       delay(defaultDelay);
       sevenSeg1255.draw_X_1();
       delay(defaultDelay);
       sevenSeg1255.draw_x_1();
       delay(defaultDelay);
       sevenSeg1255.draw_Y_1();
       delay(defaultDelay);
       sevenSeg1255.draw_y_1();
       delay(defaultDelay);
       sevenSeg1255.draw_Z_1();
       delay(defaultDelay);
       sevenSeg1255.draw_z_1();
       delay(defaultDelay);

      // Symbols
       sevenSeg1255.draw_degree_1();
       delay(defaultDelay);
       
      // *** Least Significant Digit ***
      // Hex chars (1st digit)
       sevenSeg1255.draw_0_0();
       delay(defaultDelay);
       sevenSeg1255.draw_1_0();
       delay(defaultDelay);
       sevenSeg1255.draw_2_0();
       delay(defaultDelay);
       sevenSeg1255.draw_3_0();
       delay(defaultDelay);
       sevenSeg1255.draw_4_0();
       delay(defaultDelay);
       sevenSeg1255.draw_5_0();
       delay(defaultDelay);
       sevenSeg1255.draw_6_0();
       delay(defaultDelay);
       sevenSeg1255.draw_7_0();
       delay(defaultDelay);
       sevenSeg1255.draw_8_0();
       delay(defaultDelay);
       sevenSeg1255.draw_9_0();
       delay(defaultDelay);
       sevenSeg1255.draw_A_0();
       delay(defaultDelay);
       sevenSeg1255.draw_a_0();
       delay(defaultDelay);
       sevenSeg1255.draw_b_0();
       delay(defaultDelay);
       sevenSeg1255.draw_C_0();
       delay(defaultDelay);
       sevenSeg1255.draw_c_0();
       delay(defaultDelay);
       sevenSeg1255.draw_d_0();
       delay(defaultDelay);
       sevenSeg1255.draw_E_0();
       delay(defaultDelay);
       sevenSeg1255.draw_e_0();
       delay(defaultDelay);
       sevenSeg1255.draw_F_0();
       delay(defaultDelay);

      // Extra Letters
       sevenSeg1255.draw_G_0();
       delay(defaultDelay);
       sevenSeg1255.draw_g_0();
       delay(defaultDelay);
       sevenSeg1255.draw_H_0();
       delay(defaultDelay);
       sevenSeg1255.draw_h_0();
       delay(defaultDelay);
       sevenSeg1255.draw_I_0();
       delay(defaultDelay);
       sevenSeg1255.draw_i_0();
       delay(defaultDelay);
       sevenSeg1255.draw_J_0();
       delay(defaultDelay);
       sevenSeg1255.draw_j_0();
       delay(defaultDelay);
       sevenSeg1255.draw_K_0();
       delay(defaultDelay);
       sevenSeg1255.draw_k_0();
       delay(defaultDelay);
       sevenSeg1255.draw_L_0();
       delay(defaultDelay);
       sevenSeg1255.draw_l_0();
       delay(defaultDelay);
       sevenSeg1255.draw_M_0();
       delay(defaultDelay);
       sevenSeg1255.draw_m_0();
       delay(defaultDelay);
       sevenSeg1255.draw_N_0();
       delay(defaultDelay);
       sevenSeg1255.draw_n_0();
       delay(defaultDelay);
       sevenSeg1255.draw_O_0();
       delay(defaultDelay);
       sevenSeg1255.draw_o_0();
       delay(defaultDelay);
       sevenSeg1255.draw_P_0();
       delay(defaultDelay);
       sevenSeg1255.draw_p_0();
       delay(defaultDelay);
       sevenSeg1255.draw_Q_0();
       delay(defaultDelay);
       sevenSeg1255.draw_q_0();
       delay(defaultDelay);
       sevenSeg1255.draw_R_0();
       delay(defaultDelay);
       sevenSeg1255.draw_r_0();
       delay(defaultDelay);
       sevenSeg1255.draw_S_0();
       delay(defaultDelay);
       sevenSeg1255.draw_s_0();
       delay(defaultDelay);
       sevenSeg1255.draw_T_0();
       delay(defaultDelay);
       sevenSeg1255.draw_t_0();
       delay(defaultDelay);
       sevenSeg1255.draw_U_0();
       delay(defaultDelay);
       sevenSeg1255.draw_u_0();
       delay(defaultDelay);
       sevenSeg1255.draw_V_0();
       delay(defaultDelay);
       sevenSeg1255.draw_v_0();
       delay(defaultDelay);
       sevenSeg1255.draw_W_0();
       delay(defaultDelay);
       sevenSeg1255.draw_w_0();
       delay(defaultDelay);
       sevenSeg1255.draw_X_0();
       delay(defaultDelay);
       sevenSeg1255.draw_x_0();
       delay(defaultDelay);
       sevenSeg1255.draw_Y_0();
       delay(defaultDelay);
       sevenSeg1255.draw_y_0();
       delay(defaultDelay);
       sevenSeg1255.draw_Z_0();
       delay(defaultDelay);
       sevenSeg1255.draw_z_0();
       delay(defaultDelay);

      // Symbols
       sevenSeg1255.draw_degree_0();
       delay(defaultDelay);
       
// *** Least Significant Digit (using SL-1255 notion of LSD is digit 2) ***
      // Hex chars (1st digit)
       sevenSeg1255.draw_0_2();
       delay(defaultDelay);
       sevenSeg1255.draw_1_2();
       delay(defaultDelay);
       sevenSeg1255.draw_2_2();
       delay(defaultDelay);
       sevenSeg1255.draw_3_2();
       delay(defaultDelay);
       sevenSeg1255.draw_4_2();
       delay(defaultDelay);
       sevenSeg1255.draw_5_2();
       delay(defaultDelay);
       sevenSeg1255.draw_6_2();
       delay(defaultDelay);
       sevenSeg1255.draw_7_2();
       delay(defaultDelay);
       sevenSeg1255.draw_8_2();
       delay(defaultDelay);
       sevenSeg1255.draw_9_2();
       delay(defaultDelay);
       sevenSeg1255.draw_A_2();
       delay(defaultDelay);
       sevenSeg1255.draw_a_2();
       delay(defaultDelay);
       sevenSeg1255.draw_b_2();
       delay(defaultDelay);
       sevenSeg1255.draw_C_2();
       delay(defaultDelay);
       sevenSeg1255.draw_c_2();
       delay(defaultDelay);
       sevenSeg1255.draw_d_2();
       delay(defaultDelay);
       sevenSeg1255.draw_E_2();
       delay(defaultDelay);
       sevenSeg1255.draw_e_2();
       delay(defaultDelay);
       sevenSeg1255.draw_F_2();
       delay(defaultDelay);

      // Extra Letters
       sevenSeg1255.draw_G_2();
       delay(defaultDelay);
       sevenSeg1255.draw_g_2();
       delay(defaultDelay);
       sevenSeg1255.draw_H_2();
       delay(defaultDelay);
       sevenSeg1255.draw_h_2();
       delay(defaultDelay);
       sevenSeg1255.draw_I_2();
       delay(defaultDelay);
       sevenSeg1255.draw_i_2();
       delay(defaultDelay);
       sevenSeg1255.draw_J_2();
       delay(defaultDelay);
       sevenSeg1255.draw_j_2();
       delay(defaultDelay);
       sevenSeg1255.draw_K_2();
       delay(defaultDelay);
       sevenSeg1255.draw_k_2();
       delay(defaultDelay);
       sevenSeg1255.draw_L_2();
       delay(defaultDelay);
       sevenSeg1255.draw_l_2();
       delay(defaultDelay);
       sevenSeg1255.draw_M_2();
       delay(defaultDelay);
       sevenSeg1255.draw_m_2();
       delay(defaultDelay);
       sevenSeg1255.draw_N_2();
       delay(defaultDelay);
       sevenSeg1255.draw_n_2();
       delay(defaultDelay);
       sevenSeg1255.draw_O_2();
       delay(defaultDelay);
       sevenSeg1255.draw_o_2();
       delay(defaultDelay);
       sevenSeg1255.draw_P_2();
       delay(defaultDelay);
       sevenSeg1255.draw_p_2();
       delay(defaultDelay);
       sevenSeg1255.draw_Q_2();
       delay(defaultDelay);
       sevenSeg1255.draw_q_2();
       delay(defaultDelay);
       sevenSeg1255.draw_R_2();
       delay(defaultDelay);
       sevenSeg1255.draw_r_2();
       delay(defaultDelay);
       sevenSeg1255.draw_S_2();
       delay(defaultDelay);
       sevenSeg1255.draw_s_2();
       delay(defaultDelay);
       sevenSeg1255.draw_T_2();
       delay(defaultDelay);
       sevenSeg1255.draw_t_2();
       delay(defaultDelay);
       sevenSeg1255.draw_U_2();
       delay(defaultDelay);
       sevenSeg1255.draw_u_2();
       delay(defaultDelay);
       sevenSeg1255.draw_V_2();
       delay(defaultDelay);
       sevenSeg1255.draw_v_2();
       delay(defaultDelay);
       sevenSeg1255.draw_W_2();
       delay(defaultDelay);
       sevenSeg1255.draw_w_2();
       delay(defaultDelay);
       sevenSeg1255.draw_X_2();
       delay(defaultDelay);
       sevenSeg1255.draw_x_2();
       delay(defaultDelay);
       sevenSeg1255.draw_Y_2();
       delay(defaultDelay);
       sevenSeg1255.draw_y_2();
       delay(defaultDelay);
       sevenSeg1255.draw_Z_2();
       delay(defaultDelay);
       sevenSeg1255.draw_z_2();
       delay(defaultDelay);

      // Symbols
       sevenSeg1255.draw_degree_2();
       delay(defaultDelay);
}
