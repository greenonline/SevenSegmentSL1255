/*
GetSetPinState.ino

Cycles through the getPinState() and setPinState() methods supplied in the SevenSeg1255 
class, and displays on the serial monitor, repeatedly.

Note: Runs correctly on ATMega 2560/1280 (Arduino Mega boards). May not run on ATMega 328 hardware (Arduino Nano 
and Uno boards), due to (static) memory restrictions with the strings used for the serial monitor feedback, 
which may cause low memory issues.

Demonstrates the methods:
  begin();
  getPinState(int);
  setPinState(int, int);
  get_a1();
  get_b1();
  get_c1();
  get_d1();
  get_e1();
  get_f1();
  get_g1();
  get_a2();
  get_b2();
  get_c2();
  get_d2();
  get_e2();
  get_f2();
  get_g2();
  get_a0();
  get_b0();
  get_c0();
  get_d0();
  get_e0();
  get_f0();
  get_g0();
  
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
  

  // get and set Pin State
  printf("\n\nUsing getPinState() and setPinState() methods in a for loop\n");
  printf("***********************************************************\n");

  //Only works if pins are sequential from a1, b1, c1, ... a2, b2, ... g2.
  for (int pin=sevenSeg1255.get_a1();pin<=sevenSeg1255.get_g2();pin++) {
    printf("\nState of Pin %d is %d\n", pin, sevenSeg1255.getPinState(pin));
    printf("Inverting State of Pin %d\n", pin);
    sevenSeg1255.setPinState(pin, !sevenSeg1255.getPinState(pin)); //Invert pin state
    printf("State of Pin %d is %d\n", pin, sevenSeg1255.getPinState(pin));
  }

  delay(defaultDelay);              //Pause to make the serial port display readable

  printf("\n\nUsing getPinState() and setPinState() methods using acessors (getters)\n");
  printf("**********************************************************************\n");

  //This works for non-sequential pins
  printf("\nPrinting state of pins of Least Significant Digit (LSD), digit 2 (aka digit 0)\n");
  printf("State of Pin %d connected to a2 is %d\n", sevenSeg1255.get_a2(), sevenSeg1255.getPinState(sevenSeg1255.get_a2()));
  printf("State of Pin %d connected to b2 is %d\n", sevenSeg1255.get_b2(), sevenSeg1255.getPinState(sevenSeg1255.get_b2()));
  printf("State of Pin %d connected to c2 is %d\n", sevenSeg1255.get_c2(), sevenSeg1255.getPinState(sevenSeg1255.get_c2()));
  printf("State of Pin %d connected to d2 is %d\n", sevenSeg1255.get_d2(), sevenSeg1255.getPinState(sevenSeg1255.get_d2()));
  printf("State of Pin %d connected to e2 is %d\n", sevenSeg1255.get_e2(), sevenSeg1255.getPinState(sevenSeg1255.get_e2()));
  printf("State of Pin %d connected to f2 is %d\n", sevenSeg1255.get_f2(), sevenSeg1255.getPinState(sevenSeg1255.get_f2()));
  printf("State of Pin %d connected to g2 is %d\n", sevenSeg1255.get_g2(), sevenSeg1255.getPinState(sevenSeg1255.get_g2()));

  delay(defaultDelay);              //Pause to make the serial port display readable

  printf("\nPrinting state of pins of Most Significant Digit (MSD), digit 1\n");
  printf("State of Pin %d connected to a1 is %d\n", sevenSeg1255.get_a1(), sevenSeg1255.getPinState(sevenSeg1255.get_a1()));
  printf("State of Pin %d connected to b1 is %d\n", sevenSeg1255.get_b1(), sevenSeg1255.getPinState(sevenSeg1255.get_b1()));
  printf("State of Pin %d connected to c1 is %d\n", sevenSeg1255.get_c1(), sevenSeg1255.getPinState(sevenSeg1255.get_c1()));
  printf("State of Pin %d connected to d1 is %d\n", sevenSeg1255.get_d1(), sevenSeg1255.getPinState(sevenSeg1255.get_d1()));
  printf("State of Pin %d connected to e1 is %d\n", sevenSeg1255.get_e1(), sevenSeg1255.getPinState(sevenSeg1255.get_e1()));
  printf("State of Pin %d connected to f1 is %d\n", sevenSeg1255.get_f1(), sevenSeg1255.getPinState(sevenSeg1255.get_f1()));
  printf("State of Pin %d connected to g1 is %d\n", sevenSeg1255.get_g1(), sevenSeg1255.getPinState(sevenSeg1255.get_g1()));

  delay(defaultDelay);              //Pause to make the serial port display readable

  printf("\nPrinting state of pins of Least Significant Digit (LSD), digit 0 (aka digit 2)\n");
  printf("State of Pin %d connected to a0 is %d\n", sevenSeg1255.get_a0(), sevenSeg1255.getPinState(sevenSeg1255.get_a0()));
  printf("State of Pin %d connected to b0 is %d\n", sevenSeg1255.get_b0(), sevenSeg1255.getPinState(sevenSeg1255.get_b0()));
  printf("State of Pin %d connected to c0 is %d\n", sevenSeg1255.get_c0(), sevenSeg1255.getPinState(sevenSeg1255.get_c0()));
  printf("State of Pin %d connected to d0 is %d\n", sevenSeg1255.get_d0(), sevenSeg1255.getPinState(sevenSeg1255.get_d0()));
  printf("State of Pin %d connected to e0 is %d\n", sevenSeg1255.get_e0(), sevenSeg1255.getPinState(sevenSeg1255.get_e0()));
  printf("State of Pin %d connected to f0 is %d\n", sevenSeg1255.get_f0(), sevenSeg1255.getPinState(sevenSeg1255.get_f0()));
  printf("State of Pin %d connected to g0 is %d\n", sevenSeg1255.get_g0(), sevenSeg1255.getPinState(sevenSeg1255.get_g0()));

  delay(defaultDelay);              //Pause to make the serial port display readable
   
  printf("\n\n**** Loop Ends ****\n\n");
}