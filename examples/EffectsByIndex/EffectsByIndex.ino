/*
EffectsByIndex.ino

Cycles through the various effects supplied in the SevenSeg1255 class, using
the effects_x(int index) method, repeatedly.

Demonstrates the methods:
  begin();
  effect_0(uint8_t);
  effect_0(uint8_t, int);
  effect_1(uint8_t);
  effect_1(uint8_t, int);
  effect_2(uint8_t);
  effect_2(uint8_t, int);
  effect_3(uint8_t);
  effect_3(uint8_t, int);

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

#define defaultDelay 100

SevenSeg1255 sevenSeg1255;

// the setup function runs once when you press reset or power the board
void setup() {
  sevenSeg1255.begin(); // set the (default) pins to output
}

// the loop function runs over and over again forever
void loop() {
  
  uint8_t index;
  for (index=0; index<25; index++) // cycle throught the effect index (0 - 25)
    sevenSeg1255.effect_2(index);       // call each effect in turn, on the LSD
  for (index=0; index<25; index++) // cycle throught the effect index (0 - 25)
    sevenSeg1255.effect_2(index, defaultDelay);       // call each effect in turn, with specified delay, on the LSD
  for (index=0; index<25; index++) // cycle throught the effect index (0 - 25)
    sevenSeg1255.effect_1(index);       // call each effect in turn, on the MSD
  for (index=0; index<25; index++) // cycle throught the effect index (0 - 25)
    sevenSeg1255.effect_1(index, defaultDelay);       // call each effect in turn, with specified delay, on the MSD
  for (index=0; index<25; index++) // cycle throught the effect index (0 - 25)
    sevenSeg1255.effect_0(index);       // call each effect in turn, on the LSD
  for (index=0; index<25; index++) // cycle throught the effect index (0 - 25)
    sevenSeg1255.effect_0(index, defaultDelay);       // call each effect in turn, with specified delay, on the LSD
  for (index=0; index<25; index++) // cycle throught the effect index (0 - 25)
    sevenSeg1255.effect_3(index);       // call each effect in turn, on both digits
  for (index=0; index<25; index++) // cycle throught the effect index (0 - 25)
    sevenSeg1255.effect_3(index, defaultDelay);       // call each effect in turn, with specified delay, on both digits
}
