/*
Hello World.ino

Left scrolls the message "Hello World" across the two digits of the seven segement display
using the scroll method supplied in the SevenSeg1255 class, repeatedly.

Right scrolls the message "Goodbye Love" across the two digits of the seven segement display
using the scroll method supplied in the SevenSeg1255 class, repeatedly.

Demonstrates the methods:
  begin();
  xblank();
  blankx();
  scroll(char);
  scroll(char, int);
  scroll(char, int, int);
  scrollLeft(char);
  scrollLeft(char, int);
  scrollRight(char);
  scrollRight(char, int);

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

#define defaultDelay 500
#define maxValue 100
#define maxSegmentMapCode 100
#define maxCharacter 100

#define directionLeft 1
#define directionRight 0


SevenSeg1255 sevenSeg1255;

// the setup function runs once when you press reset or power the board
void setup() {
  sevenSeg1255.begin(); // set the (default) pins to output
}

// the loop function runs over and over again forever
void loop() {
  uint8_t value1 = 69;
  uint8_t value2 = 22;
  char characters1[] = {'a', 'b', '\0'};
  char characters2[] = {'s', 's', '\0'};
  char characterString1[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
  char characterString2[] = {'G', 'o', 'o', 'd', 'b', 'y', 'e', ' ', 'L', 'o', 'v', 'e', '\0'};
    
  sevenSeg1255.write(value1); // have overload led?, prints two digits, calls write1 and write0, which each do only one digit (LSD, MSD?) <99
  delay(defaultDelay);
  sevenSeg1255.write(characters1);// two char array, string 2 characters
  delay(defaultDelay);

  sevenSeg1255.scrollLeft(characterString1);// two char array, string 2 characters
  delay(defaultDelay);
  sevenSeg1255.scrollLeft(characterString1, defaultDelay);// two char array, string 2 characters
  delay(defaultDelay);

  sevenSeg1255.write(value2); // have overload led?, prints two digits, calls write1 and write0, which each do only one digit (LSD, MSD?) <99
  delay(defaultDelay);
  sevenSeg1255.write(characters2);// two char array, string 2 characters
  delay(defaultDelay);

  sevenSeg1255.scrollRight(characterString2);// two char array, string 2 characters
  delay(defaultDelay);
  sevenSeg1255.scrollRight(characterString2, defaultDelay);// two char array, string 2 characters
  delay(defaultDelay);

  sevenSeg1255.write(value1); // have overload led?, prints two digits, calls write1 and write0, which each do only one digit (LSD, MSD?) <99
  delay(defaultDelay);
  sevenSeg1255.write(characters1);// two char array, string 2 characters
  delay(defaultDelay);

  sevenSeg1255.scroll(characterString1);// two char array, string 2 characters
  delay(defaultDelay);
  sevenSeg1255.scroll(characterString2, defaultDelay, directionLeft);// two char array, string 2 characters
  delay(defaultDelay);

  sevenSeg1255.write(value2); // have overload led?, prints two digits, calls write1 and write0, which each do only one digit (LSD, MSD?) <99
  delay(defaultDelay);
  sevenSeg1255.write(characters2);// two char array, string 2 characters
  delay(defaultDelay);

  sevenSeg1255.scroll(characterString1);// two char array, string 2 characters
  delay(defaultDelay);
  sevenSeg1255.scroll(characterString2, defaultDelay, directionRight);// two char array, string 2 characters
  delay(defaultDelay);
}
