/*
Accessors.ino

Cycles through the accessor (getter and setter) methods supplied in the SevenSegmentSL1255 
class, and displays the variables values on the serial monitor, repeatedly. 
Changes the pin assignments dynamically and creates an effect in the process.

Demonstrates the methods:
  begin();
  get_<segment><digit>();
    i.e. get_a2();
  set_<segment><digit>(int);
    i.e. set_g1(int);

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

#define defaultDelay 2000

SevenSegmentSL1255 sevenSeg1255;

// Function that printf and related will use to print
int serial_putchar(char c, FILE* f) {
    if (c == '\n') serial_putchar('\r', f);
    return Serial.write(c) == 1? 0 : 1;
}

FILE serial_stdout;


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  // Set up stdout
  fdev_setup_stream(&serial_stdout, serial_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &serial_stdout;

  printf("Ready to Access\n");

  sevenSeg1255.begin(); // set the (default) pins to output
}

// the loop function runs over and over again forever
void loop() {
  
  // Getters

  //Get the segments of the Least Significant Digit, D0
  //a0...g0 is just an alias for a2...g2
  printf("\nPrinting values of Segments of Least Significant Digit (LSD), digit 2 (aka digit 0)\n");
  int a0 = sevenSeg1255.get_a0();
  printf("Segment a2 is %d\n", a0);
  int b0 = sevenSeg1255.get_b0();
  printf("Segment b2 is %d\n", b0);
  int c0 = sevenSeg1255.get_c0();
  printf("Segment c2 is %d\n", c0);
  int d0 = sevenSeg1255.get_d0();
  printf("Segment d2 is %d\n", d0);
  int e0 = sevenSeg1255.get_e0();
  printf("Segment e2 is %d\n", e0);
  int f0 = sevenSeg1255.get_f0();
  printf("Segment f2 is %d\n", f0);
  int g0 = sevenSeg1255.get_g0();
  printf("Segment g2 is %d\n", g0);

  delay(defaultDelay);              //Pause to make the serial port display readable

  //Get the segments of the Most Significant Digit, D1
  printf("\nPrinting values of Segments of Most Significant Digit (MSD), of digit 1\n");
  int a1 = sevenSeg1255.get_a1();
  printf("Segment a1 is %d\n", a1);
  int b1 = sevenSeg1255.get_b1();
  printf("Segment b1 is %d\n", b1);
  int c1 = sevenSeg1255.get_c1();
  printf("Segment c1 is %d\n", c1);
  int d1 = sevenSeg1255.get_d1();
  printf("Segment d1 is %d\n", d1);
  int e1 = sevenSeg1255.get_e1();
  printf("Segment e1 is %d\n", e1);
  int f1 = sevenSeg1255.get_f1();
  printf("Segment f1 is %d\n", f1);
  int g1 = sevenSeg1255.get_g1();
  printf("Segment g1 is %d\n", g1);

  delay(defaultDelay);              //Pause to make the serial port display readable

  //Get the segments of the Least Significant Digit, D2 = D0
  //a0...g0 is just an alias for a2...g2
  printf("\nPrinting values of Segments of Least Significant Digit (LSD), digit 2 (aka digit 0)\n");
  int a2 = sevenSeg1255.get_a2();
  printf("Segment a2 is %d\n", a2);
  int b2 = sevenSeg1255.get_b2();
  printf("Segment b2 is %d\n", b2);
  int c2 = sevenSeg1255.get_c2();
  printf("Segment c2 is %d\n", c2);
  int d2 = sevenSeg1255.get_d2();
  printf("Segment d2 is %d\n", d2);
  int e2 = sevenSeg1255.get_e2();
  printf("Segment e2 is %d\n", e2);
  int f2 = sevenSeg1255.get_f2();
  printf("Segment f2 is %d\n", f2);
  int g2 = sevenSeg1255.get_g2();
  printf("Segment g2 is %d\n", g2);

  delay(defaultDelay);              //Pause to make the serial port display readable

  //Get the logical value of On
  int onValue = sevenSeg1255.get_onValue();
  printf("The value of _onValue is %d\n", onValue);

  //Get the logical value of Off
  int offValue = sevenSeg1255.get_offValue();
  printf("The value of _offValue is %d\n", offValue);

  //Get the logical value of the seven segment type (SL-1255 or SL-1256)
  //Type is equal to the logical ON value
  int ssType = sevenSeg1255.get_ssType();
  printf("The value of _ssType is %d\n", ssType);

  delay(defaultDelay);              //Pause to make the serial port display readable
  
  // Draw a 'pattern' so that pin reassignment can be seen visually
  sevenSeg1255.draw_xE(); // Draw a 'E' on digit 2
  sevenSeg1255.draw_3x(); // Draw a '3' on digit 1
  
  // Setters

  //Set the segments of the Least Significant Digit, D0 (add or subtract 7)
  //a0...g0 is just an alias for a2...g2
  printf("Swap pin assignments for Segments of digit 2 (aka digit 0) with those of Digit 1\n");
  sevenSeg1255.set_a0(sevenSeg1255.get_a0()==default_a2 ? sevenSeg1255.get_a0()-7:sevenSeg1255.get_a0()+7);  // swap pins of a1 with a0
  sevenSeg1255.set_b0(sevenSeg1255.get_b0()==default_b2 ? sevenSeg1255.get_b0()-7:sevenSeg1255.get_b0()+7);  // swap pins of b1 with b0
  sevenSeg1255.set_c0(sevenSeg1255.get_c0()==default_c2 ? sevenSeg1255.get_c0()-7:sevenSeg1255.get_c0()+7);  // swap pins of c1 with c0
  sevenSeg1255.set_d0(sevenSeg1255.get_d0()==default_d2 ? sevenSeg1255.get_d0()-7:sevenSeg1255.get_d0()+7);  // swap pins of d1 with d0
  sevenSeg1255.set_e0(sevenSeg1255.get_e0()==default_e2 ? sevenSeg1255.get_e0()-7:sevenSeg1255.get_e0()+7);  // swap pins of e1 with e0
  sevenSeg1255.set_f0(sevenSeg1255.get_f0()==default_f2 ? sevenSeg1255.get_f0()-7:sevenSeg1255.get_f0()+7);  // swap pins of f1 with f0
  sevenSeg1255.set_g0(sevenSeg1255.get_g0()==default_g2 ? sevenSeg1255.get_g0()-7:sevenSeg1255.get_g0()+7);  // swap pins of g1 with g0

  //Display the segments
  
  delay(defaultDelay);              //Pause to make the serial port display readable

  //Set the segments of the Most Significant Digit, D1 (add or subtract 7)
  printf("Swap pin assignments for Segments of digit 1 with those of Digit 2 (aka digit 0)\n");
  sevenSeg1255.set_a1(sevenSeg1255.get_a1()==default_a1 ? sevenSeg1255.get_a1()+7:sevenSeg1255.get_a1()-7);  // swap pins of a2 with a1
  sevenSeg1255.set_b1(sevenSeg1255.get_b1()==default_b1 ? sevenSeg1255.get_b1()+7:sevenSeg1255.get_b1()-7);  // swap pins of b2 with b1
  sevenSeg1255.set_c1(sevenSeg1255.get_c1()==default_c1 ? sevenSeg1255.get_c1()+7:sevenSeg1255.get_c1()-7);  // swap pins of c2 with c1
  sevenSeg1255.set_d1(sevenSeg1255.get_d1()==default_d1 ? sevenSeg1255.get_d1()+7:sevenSeg1255.get_d1()-7);  // swap pins of d2 with d1
  sevenSeg1255.set_e1(sevenSeg1255.get_e1()==default_e1 ? sevenSeg1255.get_e1()+7:sevenSeg1255.get_e1()-7);  // swap pins of e2 with e1
  sevenSeg1255.set_f1(sevenSeg1255.get_f1()==default_f1 ? sevenSeg1255.get_f1()+7:sevenSeg1255.get_f1()-7);  // swap pins of f2 with f1
  sevenSeg1255.set_g1(sevenSeg1255.get_g1()==default_g1 ? sevenSeg1255.get_g1()+7:sevenSeg1255.get_g1()-7);  // swap pins of g2 with g1

  delay(defaultDelay);              //Pause to make the serial port display readable

  //Set the segments of the Least Significant Digit, D2 (add or subtract 7)
  //a0...g0 is just an alias for a2...g2
  
/* Commented out as it would revert the values of a0...g0 which were swapped above.
  printf("Swap pin assignments for Segments of digit 2 (aka digit 0) with those of Digit 1\n");
  sevenSeg1255.set_a2(sevenSeg1255.get_a2()==default_a2 ? sevenSeg1255.get_a2()-7:sevenSeg1255.get_a2()+7);  // swap pins of a1 with a2
  sevenSeg1255.set_b2(sevenSeg1255.get_b2()==default_b2 ? sevenSeg1255.get_b2()-7:sevenSeg1255.get_b2()+7);  // swap pins of b1 with b2
  sevenSeg1255.set_c2(sevenSeg1255.get_c2()==default_c2 ? sevenSeg1255.get_c2()-7:sevenSeg1255.get_c2()+7);  // swap pins of c1 with c2
  sevenSeg1255.set_d2(sevenSeg1255.get_d2()==default_d2 ? sevenSeg1255.get_d2()-7:sevenSeg1255.get_d2()+7);  // swap pins of d1 with d2
  sevenSeg1255.set_e2(sevenSeg1255.get_e2()==default_e2 ? sevenSeg1255.get_e2()-7:sevenSeg1255.get_e2()+7);  // swap pins of e1 with e2
  sevenSeg1255.set_f2(sevenSeg1255.get_f2()==default_f2 ? sevenSeg1255.get_f2()-7:sevenSeg1255.get_f2()+7);  // swap pins of f1 with f2
  sevenSeg1255.set_g2(sevenSeg1255.get_g2()==default_g2 ? sevenSeg1255.get_g2()-7:sevenSeg1255.get_g2()+7);  // swap pins of g1 with g2
*/
  delay(defaultDelay);              //Pause to make the serial port display readable
}
