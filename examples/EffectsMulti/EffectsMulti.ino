/*
EffectsMulti.ino

Cycles through the various effects, each effect three times (or the value of the 
#define maxLoop), supplied in the SevenSegmentSL1255 class, repeatedly.

Demonstrates the methods:
  begin();
  blankx(void);
  fillx(void);
  flashx(int);
  blank_1(void);
  fill_1(void);
  flash_1(int);
  rotateOnSegment_1(int);
  rotateOffSegment_1(int);
  sequentiallyTurnOnAllSegments_1(int);
  sequentiallyTurnOffAllSegments_1(int);
  figure8Clock_1(int);
  figure8Anticlock_1(int);
  figure8ClockInvert_1(int);
  figure8AnticlockInvert_1(int);
  rotateTopClock_1(int);
  rotateTopAnticlock_1(int);
  rotateTopClockInvert_1(int);
  rotateTopAnticlockInvert_1(int);
  rotateBottomClock_1(int);
  rotateBottomAnticlock_1(int);
  rotateBottomClockInvert_1(int);
  rotateBottomAnticlockInvert_1(int);
  rotateBothClock_1(int);
  rotateBothAnticlock_1(int);
  rotateBothClockInvert_1(int);
  rotateBothAnticlockInvert_1(int);
  rotateCircleClock_1(int);
  rotateCircleAnticlock_1(int);
  rotateCircleClockInvert_1(int);
  rotateCircleAnticlockInvert_1(int);
  
  xblank(void);
  xfill(void);
  xflash(int);
  blank_0(void);
  fill_0(void);
  flash_0(int);
  rotateOnSegment_0(int);
  rotateOffSegment_0(int);
  sequentiallyTurnOnAllSegments_0(int);
  sequentiallyTurnOffAllSegments_0(int);
  figure8Clock_0(int);
  figure8Anticlock_0(int);
  figure8ClockInvert_0(int);
  figure8AnticlockInvert_0(int);
  rotateTopClock_0(int);
  rotateTopAnticlock_0(int);
  rotateTopClockInvert_0(int);
  rotateTopAnticlockInvert_0(int);
  rotateBottomClock_0(int);
  rotateBottomAnticlock_0(int);
  rotateBottomClockInvert_0(int);
  rotateBottomAnticlockInvert_0(int);
  rotateBothClock_0(int);
  rotateBothAnticlock_0(int);
  rotateBothClockInvert_0(int);
  rotateBothAnticlockInvert_0(int);
  rotateCircleClock_0(int);
  rotateCircleAnticlock_0(int);
  rotateCircleClockInvert_0(int);
  rotateCircleAnticlockInvert_0(int);
  
  blank_2(void);
  fill_2(void);
  flash_2(int);
  rotateOnSegment_2(int);
  rotateOffSegment_2(int);
  sequentiallyTurnOnAllSegments_2(int);
  sequentiallyTurnOffAllSegments_2(int);
  figure8Clock_2(int);
  figure8Anticlock_2(int);
  figure8ClockInvert_2(int);
  figure8AnticlockInvert_2(int);
  rotateTopClock_2(int);
  rotateTopAnticlock_2(int);
  rotateTopClockInvert_2(int);
  rotateTopAnticlockInvert_2(int);
  rotateBottomClock_2(int);
  rotateBottomAnticlock_2(int);
  rotateBottomClockInvert_2(int);
  rotateBottomAnticlockInvert_2(int);
  rotateBothClock_2(int);
  rotateBothAnticlock_2(int);
  rotateBothClockInvert_2(int);
  rotateBothAnticlockInvert_2(int);
  rotateCircleClock_2(int);
  rotateCircleAnticlock_2(int);
  rotateCircleClockInvert_2(int);
  rotateCircleAnticlockInvert_2(int);
  
  blank_3(void);
  fill_3(void);
  flash_3(int);
  rotateOnSegment_3(int);
  rotateOffSegment_3(int);
  sequentiallyTurnOnAllSegments_3(int);
  sequentiallyTurnOffAllSegments_3(int);
  figure8Clock_3(int);
  figure8Anticlock_3(int);
  figure8ClockInvert_3(int);
  figure8AnticlockInvert_3(int);
  rotateTopClock_3(int);
  rotateTopAnticlock_3(int);
  rotateTopClockInvert_3(int);
  rotateTopAnticlockInvert_3(int);
  rotateBottomClock_3(int);
  rotateBottomAnticlock_3(int);
  rotateBottomClockInvert_3(int);
  rotateBottomAnticlockInvert_3(int);
  rotateBothClock_3(int);
  rotateBothAnticlock_3(int);
  rotateBothClockInvert_3(int);
  rotateBothAnticlockInvert_3(int);
  rotateCircleClock_3(int);
  rotateCircleAnticlock_3(int);
  rotateCircleClockInvert_3(int);
  rotateCircleAnticlockInvert_3(int);
  
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

#define defaultDelay 100
#define maxLoop 3

SevenSegmentSL1255 sevenSeg1255;

// the setup function runs once when you press reset or power the board
void setup() {
  sevenSeg1255.begin(); // set the (default) pins to output
}

// the loop function runs over and over again forever
void loop() {
  int loop;
  // Effects for the Most Significant digit
  sevenSeg1255.blankx();
  sevenSeg1255.fillx();
  for (loop=0; loop<3; loop++)
    sevenSeg1255.flashx(defaultDelay);
  sevenSeg1255.blank_1();
  sevenSeg1255.fill_1();
  for (loop=0; loop<3; loop++)
    sevenSeg1255.flash_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateOnSegment_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateOffSegment_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.sequentiallyTurnOnAllSegments_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.sequentiallyTurnOffAllSegments_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.figure8Clock_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.figure8Anticlock_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.figure8ClockInvert_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.figure8AnticlockInvert_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateTopClock_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateTopAnticlock_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateTopClockInvert_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateTopAnticlockInvert_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateBottomClock_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateBottomAnticlock_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateBottomClockInvert_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateBottomAnticlockInvert_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateBothClock_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateBothAnticlock_1(defaultDelay);
  for (loop=0; loop<3; loop++)
    sevenSeg1255.rotateBothClockInvert_1(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothAnticlockInvert_1(defaultDelay);
//  sevenSeg1255.rotatebothaltclock_1(defaultDelay); //not required, call top and then bottom
//  sevenSeg1255.rotatebothaltanticlock_1(defaultDelay);//not required, call top and then bottom
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleClock_1(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleAnticlock_1(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleClockInvert_1(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleAnticlockInvert_1(defaultDelay);
  
  // Effects for the Least Significant digit
  sevenSeg1255.xblank();
  sevenSeg1255.xfill();
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.xflash(defaultDelay);
  sevenSeg1255.blank_0();
  sevenSeg1255.fill_0();
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.flash_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateOnSegment_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateOffSegment_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.sequentiallyTurnOnAllSegments_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.sequentiallyTurnOffAllSegments_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8Clock_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8Anticlock_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8ClockInvert_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8AnticlockInvert_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopClock_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopAnticlock_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopClockInvert_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopAnticlockInvert_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomClock_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomAnticlock_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomClockInvert_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomAnticlockInvert_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothClock_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothAnticlock_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothClockInvert_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothAnticlockInvert_0(defaultDelay);
//  rotatebothaltclock_0(defaultDelay); //not required, call top and then bottom
//  rotatebothaltanticlock_0(defaultDelay);//not required, call top and then bottom
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleClock_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleAnticlock_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleClockInvert_0(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleAnticlockInvert_0(defaultDelay);

  // Effects for the Most Significant digit
  // Using SL-1255 notion of least significant digit is digit 2
  sevenSeg1255.xblank();
  sevenSeg1255.xfill();
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.xflash(defaultDelay);
  sevenSeg1255.blank_2();
  sevenSeg1255.fill_2();
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.flash_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateOnSegment_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateOffSegment_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.sequentiallyTurnOnAllSegments_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.sequentiallyTurnOffAllSegments_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8Clock_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8Anticlock_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8ClockInvert_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8AnticlockInvert_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopClock_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopAnticlock_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopClockInvert_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopAnticlockInvert_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomClock_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomAnticlock_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomClockInvert_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomAnticlockInvert_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothClock_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothAnticlock_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothClockInvert_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothAnticlockInvert_2(defaultDelay);
//  sevenSeg1255.rotatebothaltclock_2(defaultDelay); //not required, call top and then bottom
//  sevenSeg1255.rotatebothaltanticlock_2(defaultDelay);//not required, call top and then bottom
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleClock_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleAnticlock_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleClockInvert_2(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleAnticlockInvert_2(defaultDelay);

  // Effects for both digits
  sevenSeg1255.xblankx();
  sevenSeg1255.xfillx();
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.xflashx(defaultDelay);
  sevenSeg1255.blank_3();
  sevenSeg1255.fill_3();
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.flash_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateOnSegment_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateOffSegment_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.sequentiallyTurnOnAllSegments_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.sequentiallyTurnOffAllSegments_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8Clock_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8Anticlock_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8ClockInvert_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.figure8AnticlockInvert_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopClock_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopAnticlock_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopClockInvert_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateTopAnticlockInvert_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomClock_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomAnticlock_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomClockInvert_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBottomAnticlockInvert_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothClock_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothAnticlock_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothClockInvert_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateBothAnticlockInvert_3(defaultDelay);
//  sevenSeg1255.rotatebothaltclock_3(defaultDelay); //not required, call top and then bottom
//  sevenSeg1255.rotatebothaltanticlock_3(defaultDelay);//not required, call top and then bottom
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleClock_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleAnticlock_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleClockInvert_3(defaultDelay);
  for (loop=0; loop<maxLoop; loop++)
    sevenSeg1255.rotateCircleAnticlockInvert_3(defaultDelay);
}
