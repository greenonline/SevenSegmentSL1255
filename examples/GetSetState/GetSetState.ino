/*
GetSetState.ino 

Cycles through the getState_<segment>() and setState_<segment>() methods supplied in the SevenSeg1255 
class, and displays on the serial monitor, repeatedly.

Demonstrates the methods:
  begin();
  getState_<segment><digit>();
    i.e. getState_b1();

  setState_<segment><digit>(int);
    i.e. setState_g0(int);

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

    SevenSeg1255
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
 
#include "SevenSeg1255.h"

#define defaultDelay 2000

SevenSeg1255 sevenSeg1255;

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

  printf("Ready to Get and Set States\n");

  sevenSeg1255.begin(); // set the (default) pins to output
}

// the loop function runs over and over again forever
void loop() {
  
  // Get State
  printf("\n\nUsing getState() methods\n");
  printf("************************\n");

  //Get the segments of the Least Significant Digit, D0
  //a0...g0 is just an alias for a2...g2
  printf("\nPrinting states of Segments of Least Significant Digit (LSD), digit 2 (aka digit 0)\n");
  int a0 = sevenSeg1255.getState_a0();
  printf("Segment a2 is %d\n", a0);
  int b0 = sevenSeg1255.getState_b0();
  printf("Segment b2 is %d\n", b0);
  int c0 = sevenSeg1255.getState_c0();
  printf("Segment c2 is %d\n", c0);
  int d0 = sevenSeg1255.getState_d0();
  printf("Segment d2 is %d\n", d0);
  int e0 = sevenSeg1255.getState_e0();
  printf("Segment e2 is %d\n", e0);
  int f0 = sevenSeg1255.getState_f0();
  printf("Segment f2 is %d\n", f0);
  int g0 = sevenSeg1255.getState_g0();
  printf("Segment g2 is %d\n", g0);

  delay(defaultDelay);              //Pause to make the serial port display readable

  //Get the segments of the Most Significant Digit, D1
  printf("\nPrinting states of Segments of Most Significant Digit (MSD), of digit 1\n");
  int a1 = sevenSeg1255.getState_a1();
  printf("Segment a1 is %d\n", a1);
  int b1 = sevenSeg1255.getState_b1();
  printf("Segment b1 is %d\n", b1);
  int c1 = sevenSeg1255.getState_c1();
  printf("Segment c1 is %d\n", c1);
  int d1 = sevenSeg1255.getState_d1();
  printf("Segment d1 is %d\n", d1);
  int e1 = sevenSeg1255.getState_e1();
  printf("Segment e1 is %d\n", e1);
  int f1 = sevenSeg1255.getState_f1();
  printf("Segment f1 is %d\n", f1);
  int g1 = sevenSeg1255.getState_g1();
  printf("Segment g1 is %d\n", g1);

  delay(defaultDelay);              //Pause to make the serial port display readable

  //Get the segments of the Least Significant Digit, D2 = D0
  //a0...g0 is just an alias for a2...g2
  printf("\nPrinting values of Segments of Least Significant Digit (LSD), digit 2 (aka digit 0)\n");
  int a2 = sevenSeg1255.getState_a2();
  printf("Segment a2 is %d\n", a2);
  int b2 = sevenSeg1255.getState_b2();
  printf("Segment b2 is %d\n", b2);
  int c2 = sevenSeg1255.getState_c2();
  printf("Segment c2 is %d\n", c2);
  int d2 = sevenSeg1255.getState_d2();
  printf("Segment d2 is %d\n", d2);
  int e2 = sevenSeg1255.getState_e2();
  printf("Segment e2 is %d\n", e2);
  int f2 = sevenSeg1255.getState_f2();
  printf("Segment f2 is %d\n", f2);
  int g2 = sevenSeg1255.getState_g2();
  printf("Segment g2 is %d\n", g2);

  delay(defaultDelay);              //Pause to make the serial port display readable

  // Set State
  printf("\n\nUsing setState() methods\n");
  printf("************************\n");

  //Set the segments of the Least Significant Digit, D0
  //a0...g0 is just an alias for a2...g2
  printf("Inverting Segments of digit 2 (aka digit 0)\n");
  sevenSeg1255.setState_a0(!sevenSeg1255.getState_a0());  // invert state of a2
  sevenSeg1255.setState_b0(!sevenSeg1255.getState_b0());  // invert state of b2
  sevenSeg1255.setState_c0(!sevenSeg1255.getState_c0());  // invert state of c2
  sevenSeg1255.setState_d0(!sevenSeg1255.getState_d0());  // invert state of d2
  sevenSeg1255.setState_e0(!sevenSeg1255.getState_e0());  // invert state of e2
  sevenSeg1255.setState_f0(!sevenSeg1255.getState_f0());  // invert state of f2
  sevenSeg1255.setState_g0(!sevenSeg1255.getState_g0());  // invert state of g2

  //Display the segments
  
  delay(defaultDelay);              //Pause to make the serial port display readable

  //Set the segments of the Most Significant Digit, D1
  printf("Inverting Segments of digit 1\n");
  sevenSeg1255.setState_a1(!sevenSeg1255.getState_a1());  // invert state of a1
  sevenSeg1255.setState_b1(!sevenSeg1255.getState_b1());  // invert state of b1
  sevenSeg1255.setState_c1(!sevenSeg1255.getState_c1());  // invert state of c1
  sevenSeg1255.setState_d1(!sevenSeg1255.getState_d1());  // invert state of d1
  sevenSeg1255.setState_e1(!sevenSeg1255.getState_e1());  // invert state of e1
  sevenSeg1255.setState_f1(!sevenSeg1255.getState_f1());  // invert state of f1
  sevenSeg1255.setState_g1(!sevenSeg1255.getState_g1());  // invert state of g1

  delay(defaultDelay);              //Pause to make the serial port display readable

  //Set the segments of the Least Significant Digit, D2
  //a0...g0 is just an alias for a2...g2
/* Commented out as it would invert Digit 2 twice (already done above as Digit 0)
  printf("Inverting Segments of digit 2\n");
  sevenSeg1255.setState_a2(!sevenSeg1255.getState_a2());  // invert state of a2
  sevenSeg1255.setState_b2(!sevenSeg1255.getState_b2());  // invert state of b2
  sevenSeg1255.setState_c2(!sevenSeg1255.getState_c2());  // invert state of c2
  sevenSeg1255.setState_d2(!sevenSeg1255.getState_d2());  // invert state of d2
  sevenSeg1255.setState_e2(!sevenSeg1255.getState_e2());  // invert state of e2
  sevenSeg1255.setState_f2(!sevenSeg1255.getState_f2());  // invert state of f2
  sevenSeg1255.setState_g2(!sevenSeg1255.getState_g2());  // invert state of g2

  delay(defaultDelay);              //Pause to make the serial port display readable
*/

  printf("\n\n**** Loop Ends ****\n\n");
}