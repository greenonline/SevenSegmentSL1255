/*
GetSetSegmentState.ino

Cycles through the getSegmentState() and setSegmentState() methods supplied in the SevenSegmentSL1255 
class, and displays on the serial monitor, repeatedly.

Demonstrates the methods:
  begin();
  getSegmentState(char);
  setSegmentState(char, int);

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

  printf("Ready to Get and Set States\n");

  sevenSeg1255.begin(); // set the (default) pins to output
}

// the loop function runs over and over again forever
void loop() {
  
  // get and set Segment State

  printf("\n\nUsing getSegmentState() and setSegmentState() methods in for loop\n");
  printf("*****************************************************************\n");
  //This works for both sequential and non-sequential pins
  for (char digitNumber='0';digitNumber<='2';digitNumber++) {
    for (char segmentLetter='a';segmentLetter<='g';segmentLetter++) {
    
      char segment[3];		// Create character representation (i.e. a string) of segment name
      segment[0]=segmentLetter;
      segment[1]=digitNumber;
      segment[2]='\0';
      
      printf("State of Segment %s is %d\n", segment, sevenSeg1255.getSegmentState(segment));
      printf("Inverting State of Segment %s\n", segment);
      sevenSeg1255.setSegmentState(segment, !sevenSeg1255.getSegmentState(segment)); //Invert segment state
      printf("State of Segment %s is %d\n", segment, sevenSeg1255.getSegmentState(segment));
    }
  }

  delay(defaultDelay);              //Pause to make the serial port display readable

  printf("\n\nUsing getSegmentState() and setSegmentState() methods\n");
  printf("*****************************************************\n");

  // Getting and setting (inverting) the segments of digit 0
  printf("\n\nUsing getSegmentState() and setSegmentState() methods for digit 0\n");
  printf("*****************************************************************\n");
  printf("\nState of Segment %s is %d\n", "a0", sevenSeg1255.getSegmentState("a0"));
  printf("Inverting State of Segment %s\n", "a0");
  sevenSeg1255.setSegmentState("a0", !sevenSeg1255.getSegmentState("a0")); //Invert segment state
  printf("State of Segment %s is %d\n", "a0", sevenSeg1255.getSegmentState("a0"));

  printf("\nState of Segment %s is %d\n", "b0", sevenSeg1255.getSegmentState("b0"));
  printf("Inverting State of Segment %s\n", "b0");
  sevenSeg1255.setSegmentState("b0", !sevenSeg1255.getSegmentState("b0")); //Invert segment state
  printf("State of Segment %s is %d\n", "b0", sevenSeg1255.getSegmentState("b0"));

  printf("\nState of Segment %s is %d\n", "c0", sevenSeg1255.getSegmentState("c0"));
  printf("Inverting State of Segment %s\n", "c0");
  sevenSeg1255.setSegmentState("c0", !sevenSeg1255.getSegmentState("c0")); //Invert segment state
  printf("State of Segment %s is %d\n", "c0", sevenSeg1255.getSegmentState("c0"));

  printf("\nState of Segment %s is %d\n", "d0", sevenSeg1255.getSegmentState("d0"));
  printf("Inverting State of Segment %s\n", "d0");
  sevenSeg1255.setSegmentState("d0", !sevenSeg1255.getSegmentState("d0")); //Invert segment state
  printf("State of Segment %s is %d\n", "d0", sevenSeg1255.getSegmentState("d0"));

  printf("\nState of Segment %s is %d\n", "e0", sevenSeg1255.getSegmentState("e0"));
  printf("Inverting State of Segment %s\n", "e0");
  sevenSeg1255.setSegmentState("e0", !sevenSeg1255.getSegmentState("e0")); //Invert segment state
  printf("State of Segment %s is %d\n", "e0", sevenSeg1255.getSegmentState("e0"));

  printf("\nState of Segment %s is %d\n", "f0", sevenSeg1255.getSegmentState("f0"));
  printf("Inverting State of Segment %s\n", "f0");
  sevenSeg1255.setSegmentState("f0", !sevenSeg1255.getSegmentState("f0")); //Invert segment state
  printf("State of Segment %s is %d\n", "f0", sevenSeg1255.getSegmentState("f0"));

  printf("\nState of Segment %s is %d\n", "g0", sevenSeg1255.getSegmentState("g0"));
  printf("Inverting State of Segment %s\n", "g0");
  sevenSeg1255.setSegmentState("g0", !sevenSeg1255.getSegmentState("g0")); //Invert segment state
  printf("State of Segment %s is %d\n", "g0", sevenSeg1255.getSegmentState("g0"));

  delay(defaultDelay);              //Pause to make the serial port display readable

  // Getting and setting (inverting) the segments of digit 1
  printf("\n\nUsing getSegmentState() and setSegmentState() methods for digit 1\n");
  printf("*****************************************************************\n");
  printf("\nState of Segment %s is %d\n", "a1", sevenSeg1255.getSegmentState("a1"));
  printf("Inverting State of Segment %s\n", "a1");
  sevenSeg1255.setSegmentState("a1", !sevenSeg1255.getSegmentState("a1")); //Invert segment state
  printf("State of Segment %s is %d\n", "a1", sevenSeg1255.getSegmentState("a1"));

  printf("\nState of Segment %s is %d\n", "b1", sevenSeg1255.getSegmentState("b1"));
  printf("Inverting State of Segment %s\n", "b1");
  sevenSeg1255.setSegmentState("b1", !sevenSeg1255.getSegmentState("b1")); //Invert segment state
  printf("State of Segment %s is %d\n", "b1", sevenSeg1255.getSegmentState("b1"));

  printf("\nState of Segment %s is %d\n", "c1", sevenSeg1255.getSegmentState("c1"));
  printf("Inverting State of Segment %s\n", "c1");
  sevenSeg1255.setSegmentState("c1", !sevenSeg1255.getSegmentState("c1")); //Invert segment state
  printf("State of Segment %s is %d\n", "c1", sevenSeg1255.getSegmentState("c1"));

  printf("\nState of Segment %s is %d\n", "d1", sevenSeg1255.getSegmentState("d1"));
  printf("Inverting State of Segment %s\n", "d1");
  sevenSeg1255.setSegmentState("d1", !sevenSeg1255.getSegmentState("d1")); //Invert segment state
  printf("State of Segment %s is %d\n", "d1", sevenSeg1255.getSegmentState("d1"));

  printf("\nState of Segment %s is %d\n", "e1", sevenSeg1255.getSegmentState("e1"));
  printf("Inverting State of Segment %s\n", "e1");
  sevenSeg1255.setSegmentState("e1", !sevenSeg1255.getSegmentState("e1")); //Invert segment state
  printf("State of Segment %s is %d\n", "e1", sevenSeg1255.getSegmentState("e1"));

  printf("\nState of Segment %s is %d\n", "f1", sevenSeg1255.getSegmentState("f1"));
  printf("Inverting State of Segment %s\n", "f1");
  sevenSeg1255.setSegmentState("f1", !sevenSeg1255.getSegmentState("f1")); //Invert segment state
  printf("State of Segment %s is %d\n", "f1", sevenSeg1255.getSegmentState("f1"));

  printf("\nState of Segment %s is %d\n", "g1", sevenSeg1255.getSegmentState("g1"));
  printf("Inverting State of Segment %s\n", "g1");
  sevenSeg1255.setSegmentState("g1", !sevenSeg1255.getSegmentState("g1")); //Invert segment state
  printf("State of Segment %s is %d\n", "g1", sevenSeg1255.getSegmentState("g1"));

  delay(defaultDelay);              //Pause to make the serial port display readable

  // Getting and setting (inverting) the segments of digit 2
  printf("\n\nUsing getSegmentState() and setSegmentState() methods for digit 2\n");
  printf("*****************************************************************\n");
  printf("\nState of Segment %s is %d\n", "a2", sevenSeg1255.getSegmentState("a2"));
  printf("Inverting State of Segment %s\n", "a2");
  sevenSeg1255.setSegmentState("a2", !sevenSeg1255.getSegmentState("a2")); //Invert segment state
  printf("State of Segment %s is %d\n", "a2", sevenSeg1255.getSegmentState("a2"));

  printf("\nState of Segment %s is %d\n", "b2", sevenSeg1255.getSegmentState("b2"));
  printf("Inverting State of Segment %s\n", "b2");
  sevenSeg1255.setSegmentState("b2", !sevenSeg1255.getSegmentState("b2")); //Invert segment state
  printf("State of Segment %s is %d\n", "b2", sevenSeg1255.getSegmentState("b2"));

  printf("\nState of Segment %s is %d\n", "c2", sevenSeg1255.getSegmentState("c2"));
  printf("Inverting State of Segment %s\n", "c2");
  sevenSeg1255.setSegmentState("c2", !sevenSeg1255.getSegmentState("c2")); //Invert segment state
  printf("State of Segment %s is %d\n", "c2", sevenSeg1255.getSegmentState("c2"));

  printf("\nState of Segment %s is %d\n", "d2", sevenSeg1255.getSegmentState("d2"));
  printf("Inverting State of Segment %s\n", "d2");
  sevenSeg1255.setSegmentState("d2", !sevenSeg1255.getSegmentState("d2")); //Invert segment state
  printf("State of Segment %s is %d\n", "d2", sevenSeg1255.getSegmentState("d2"));

  printf("\nState of Segment %s is %d\n", "e2", sevenSeg1255.getSegmentState("e2"));
  printf("Inverting State of Segment %s\n", "e2");
  sevenSeg1255.setSegmentState("e2", !sevenSeg1255.getSegmentState("e2")); //Invert segment state
  printf("State of Segment %s is %d\n", "e2", sevenSeg1255.getSegmentState("e2"));

  printf("\nState of Segment %s is %d\n", "f2", sevenSeg1255.getSegmentState("f2"));
  printf("Inverting State of Segment %s\n", "f2");
  sevenSeg1255.setSegmentState("f2", !sevenSeg1255.getSegmentState("f2")); //Invert segment state
  printf("State of Segment %s is %d\n", "f2", sevenSeg1255.getSegmentState("f2"));

  printf("\nState of Segment %s is %d\n", "g2", sevenSeg1255.getSegmentState("g2"));
  printf("Inverting State of Segment %s\n", "g2");
  sevenSeg1255.setSegmentState("g2", !sevenSeg1255.getSegmentState("g2")); //Invert segment state
  printf("State of Segment %s is %d\n", "g2", sevenSeg1255.getSegmentState("g2"));

  delay(defaultDelay);              //Pause to make the serial port display readable

  printf("\n\n**** Loop Ends ****\n\n");
}