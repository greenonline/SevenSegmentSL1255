/*
SevenSegMapsLoop.ino

Cycles through the ASCII character set (codes 32 to 127), using the seven 
segment maps character digit2CharWrite(), digit1CharWrite() and
digit0CharWrite(), methods supplied in the SevenSeg1255 class, repeatedly.

Demonstrates the methods:
  begin();
  xfill();
  fillx();
  digit2CharWrite(int);
  digit1CharWrite(int);
  digit0CharWrite(int);

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

#define defaultDelay 1000

SevenSeg1255 sevenSeg1255;

// the setup function runs once when you press reset or power the board
void setup() {
  sevenSeg1255.begin(); // set the (default) pins to output
}

// the loop function runs over and over again forever
void loop() {
  
  
  sevenSeg1255.fillx();
  sevenSeg1255.xfill();
  delay(2000);
  for (int value=32; value<127; value++) {
    sevenSeg1255.digit2CharWrite(value); 
    delay(defaultDelay);   
  }   
  for (int value=32; value<127; value++) {
    sevenSeg1255.digit1CharWrite(value); 
    delay(defaultDelay);   
  }   
  for (int value=32; value<127; value++) {
    sevenSeg1255.digit0CharWrite(value); 
    delay(defaultDelay);   
  }
  delay(2000);
}
