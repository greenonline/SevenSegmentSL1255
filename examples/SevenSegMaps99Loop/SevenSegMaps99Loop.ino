/*
SevenSeg99Loop.ino

Cycles 00 through 99, using the seven segment maps character write() method 
supplied in the SevenSegmentSL1255 class, repeatedly.

Demonstrates the methods:
  begin();
  write(int);

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
  for (int value=0; value<=99; value++){ // count from 0 to 99
    sevenSeg1255.write(value);		// write the value
    delay(defaultDelay);
  }
    
}
