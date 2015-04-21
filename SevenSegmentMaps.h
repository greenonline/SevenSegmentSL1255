/*
   SevenSegmentMaps.h - Library for the SL-1255-30 Seven Segment display (Common Anode)
   Binary Maps for Seven Segments
   Created by Mark G. Jenkins March 30 2015
   Released into the public domain.
*/

#define alphanum_A 119
#define alphanum_B 127
#define alphanum_C 57
#define alphanum_D 63
#define alphanum_E 121
#define alphanum_F 113
#define alphanum_G 61
#define alphanum_H 118
#define alphanum_I 48
#define alphanum_J 30
#define alphanum_K 118
#define alphanum_L 56
#define alphanum_M 21
#define alphanum_N 55
#define alphanum_O 63
#define alphanum_P 115
#define alphanum_Q 107
#define alphanum_R 119
#define alphanum_S 109
#define alphanum_T 120
#define alphanum_U 62
#define alphanum_V 62
#define alphanum_W 42
#define alphanum_X 118
#define alphanum_Y 102
#define alphanum_Z 91

// Letter defines are prefixed with c

#define alphanum_a 95
#define alphanum_b 124
#define alphanum_c 88
#define alphanum_d 94
#define alphanum_e 123
#define alphanum_f 113
#define alphanum_g 111
#define alphanum_h 116
#define alphanum_i 16
#define alphanum_j 12
#define alphanum_k 118
#define alphanum_l 48
#define alphanum_m 20
#define alphanum_n 84
#define alphanum_o 92
#define alphanum_p 115
#define alphanum_q 103
#define alphanum_r 80
#define alphanum_s 109
#define alphanum_t 120
#define alphanum_u 28
#define alphanum_v 28
#define alphanum_w 20
#define alphanum_x 118
#define alphanum_y 110
#define alphanum_z 91

// Number defines are prefixed with d
// dt indicate a 'tail', or serif
/*
#define d0 63
#define d1 6
#define d2 91
#define d3 79
#define d4 102
#define d5 109
#define d6 125
#define d7 7
#define dt7 39 // with lead tail/droppy head
#define d8 127
#define d9 103
#define dt9 111 // with tail
*/
#define alphanum_0 63
#define alphanum_1 6
#define alphanum_2 91
#define alphanum_3 79
#define alphanum_4 102
#define alphanum_5 109
#define alphanum_6 125
#define alphanum_7 7
#define alphanum_t7 39 // with lead tail/droppy head
#define alphanum_8 127
#define alphanum_9 103
#define alphanum_t9 111 // with tail

// Symbols
#define degree 99

// ASCII
#define ascii_NUL 0
#define ascii_SOH 0
#define ascii_STX 0
#define ascii_ETX 0
#define ascii_EOT 0
#define ascii_ENQ 0
#define ascii_ACK 0
#define ascii_BEL 0
#define ascii_BS 0
#define ascii_TAB 0
#define ascii_LF 0
#define ascii_VT 0
#define ascii_FF 0
#define ascii_CR 0
#define ascii_SO 0
#define ascii_SI 0
#define ascii_DLE 0
#define ascii_DC1 0
#define ascii_DC2 0
#define ascii_DC3 0
#define ascii_DC4 0
#define ascii_NAK 0
#define ascii_SYN 0
#define ascii_ETB 0
#define ascii_CAN 0
#define ascii_EM 0
#define ascii_SUB 0
#define ascii_ESC 0
#define ascii_FS 0
#define ascii_GS 0
#define ascii_RS 0
#define ascii_US 0
#define ascii_space 0
#define ascii_exclamation 10
#define ascii_doublequote 34
#define ascii_hash 99
#define ascii_dollar alphanum_5
#define ascii_percent 82
#define ascii_ampersand 127
#define ascii_singlequote 2
#define ascii_leftparentese 57
#define ascii_rightparentese 15
#define ascii_asterisk 70
#define ascii_plus 70
#define ascii_comma 16
#define ascii_minus 64
#define ascii_period 4
#define ascii_forwardslash 82
#define ascii_0 alphanum_0
#define ascii_1 alphanum_1
#define ascii_2 alphanum_2
#define ascii_3 alphanum_3
#define ascii_4 alphanum_4
#define ascii_5 alphanum_5
#define ascii_6 alphanum_6
#define ascii_7 alphanum_7
#define ascii_8 alphanum_8
#define ascii_9 alphanum_9
#define ascii_colon 48
#define ascii_semicolon 48
#define ascii_lessthan 88
#define ascii_equals 72
#define ascii_greaterthan 76
#define ascii_interrogation 83
#define ascii_at alphanum_a
#define ascii_A alphanum_A
#define ascii_B alphanum_B
#define ascii_C alphanum_C
#define ascii_D alphanum_D
#define ascii_E alphanum_E
#define ascii_F alphanum_F
#define ascii_G alphanum_G
#define ascii_H alphanum_H
#define ascii_I alphanum_I
#define ascii_J alphanum_J
#define ascii_K alphanum_K
#define ascii_L alphanum_L
#define ascii_M alphanum_M
#define ascii_N alphanum_N
#define ascii_O alphanum_O
#define ascii_P alphanum_P
#define ascii_Q alphanum_Q
#define ascii_R alphanum_R
#define ascii_S alphanum_S
#define ascii_T alphanum_T
#define ascii_U alphanum_U
#define ascii_V alphanum_V
#define ascii_W alphanum_W
#define ascii_X alphanum_X
#define ascii_Y alphanum_Y
#define ascii_Z alphanum_Z
#define ascii_leftbracket 57
#define ascii_backslash 100
#define ascii_rightbracket 15
#define ascii_circumflex 35
#define ascii_underscore 8
#define ascii_accent 32
#define ascii_a alphanum_a
#define ascii_b alphanum_b
#define ascii_c alphanum_c
#define ascii_d alphanum_d
#define ascii_e alphanum_e
#define ascii_f alphanum_f
#define ascii_g alphanum_g
#define ascii_h alphanum_h
#define ascii_i alphanum_i
#define ascii_j alphanum_j
#define ascii_k alphanum_k
#define ascii_l alphanum_l
#define ascii_m alphanum_m
#define ascii_n alphanum_n
#define ascii_o alphanum_o
#define ascii_p alphanum_p
#define ascii_q alphanum_q
#define ascii_r alphanum_r
#define ascii_s alphanum_s
#define ascii_t alphanum_t
#define ascii_u alphanum_u
#define ascii_v alphanum_v
#define ascii_w alphanum_w
#define ascii_x alphanum_x
#define ascii_y alphanum_y
#define ascii_z alphanum_z
#define ascii_leftbrace 57
#define ascii_pipe 6
#define ascii_rightbrace 15
#define ascii_cedilla 1
#define ascii_DEL 0

// Lines
#define tophalf 35
#define bottomhalf 28
#define topleft 32
#define bottomleft 16
#define topright 2
#define bottomright 4
#define topleftcorner 33
#define bottomleftcorner 24
#define toprightcorner 3
#define bottomrightcorner 12
#define topline 1
#define midline 64
#define bottomline 8


