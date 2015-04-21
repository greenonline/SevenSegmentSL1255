/*
SevenSegMaps.ino

Cycles through the draw seven segment maps character methods supplied in the 
SevenSeg1255 class, repeatedly.

Demonstrates the methods:
  begin();
  xfill();
  fillx();
  draw_bitmap0(int);
  draw_bitmapInvert0(int);
  draw0(int);
  drawInvert0(int);
  draw_bitmap1(int);
  draw_bitmapInvert1(int);
  draw1(int);
  drawInvert1(int);
  draw_bitmap2(int);
  draw_bitmapInvert2(int);
  draw2(int);
  drawInvert2(int);
  
  digit0CharWrite(char);
  digit0OctWrite(uint8_t);
  digit0DecWrite(uint8_t);
  digit0HexWrite(uint8_t);
  digit0Write(uint8_t);
  write0(uint8_t);
  digit0Write(char);
  write0(char);
  digit1CharWrite(char);
  digit1OctWrite(uint8_t);
  digit1DecWrite(uint8_t);
  digit1HexWrite(uint8_t);
  digit1Write(uint8_t);
  write1(uint8_t);
  digit1Write(char);
  write1(char);
  digit2CharWrite(char);
  digit2OctWrite(uint8_t);
  digit2DecWrite(uint8_t);
  digit2HexWrite(uint8_t);
  digit2Write(uint8_t);
  write2(uint8_t);
  digit2Write(char);
  write2(char);
  
  write(char);
  write(int);
  scroll(char);
  scroll(char,int);
  write(char,int)
  write(int, int);

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

SevenSeg1255 sevenSeg1255;

// the setup function runs once when you press reset or power the board
void setup() {
  sevenSeg1255.begin(); // set the (default) pins to output
}

// the loop function runs over and over again forever
void loop() {
  uint8_t segmentMapCode = 33;
  uint8_t value = 5;
  uint8_t digit = 1;
  char character = 32;
  char characters[] = {'a', 'b', '\0'};
  char characterString[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
  
  // Bitmap
  sevenSeg1255.draw_bitmap0(segmentMapCode++);
  delay(defaultDelay);
  sevenSeg1255.draw_bitmapInvert0(segmentMapCode++);
  delay(defaultDelay);
  sevenSeg1255.draw0(segmentMapCode++); //just calls draw_bitmap0()
  delay(defaultDelay);
  sevenSeg1255.drawInvert0(segmentMapCode++); //just calls draw_bitmapInvert0()      
  delay(defaultDelay);

  sevenSeg1255.draw_bitmap1(segmentMapCode++);
  delay(defaultDelay);
  sevenSeg1255.draw_bitmapInvert1(segmentMapCode++);
  delay(defaultDelay);
  sevenSeg1255.draw1(segmentMapCode++); //just calls draw_bitmap1()
  delay(defaultDelay);
  sevenSeg1255.drawInvert1(segmentMapCode++); //just calls draw_bitmapInvert1()
  delay(defaultDelay);

  sevenSeg1255.draw_bitmap2(segmentMapCode++);
  delay(defaultDelay);
  sevenSeg1255.draw_bitmapInvert2(segmentMapCode++);
  delay(defaultDelay);
  sevenSeg1255.draw2(segmentMapCode++); //just calls draw_bitmap0()
  delay(defaultDelay);
  sevenSeg1255.drawInvert2(segmentMapCode++); //just calls draw_bitmapInvert0()      
  delay(defaultDelay);

      // Put
//      void putc(char character);
//      void putchar(char character);

  // Write
  sevenSeg1255.digit0CharWrite(character);
  delay(defaultDelay);
  sevenSeg1255.digit0OctWrite(value);
  delay(defaultDelay);
  sevenSeg1255.digit0DecWrite(value);
  delay(defaultDelay);
  sevenSeg1255.digit0HexWrite(value);
  delay(defaultDelay);
  sevenSeg1255.digit0Write(value);
  delay(defaultDelay);
  sevenSeg1255.write0(value); //just calls digit0Write(int value)
  delay(defaultDelay);
  sevenSeg1255.digit0Write(character);
  delay(defaultDelay);
  sevenSeg1255.write0(character); //just calls digit0Write(char character)
  delay(defaultDelay);

  sevenSeg1255.digit1CharWrite(character);
  delay(defaultDelay);
  sevenSeg1255.digit1OctWrite(value);
  delay(defaultDelay);
  sevenSeg1255.digit1DecWrite(value);
  delay(defaultDelay);
  sevenSeg1255.digit1HexWrite(value);
  delay(defaultDelay);
  sevenSeg1255.digit1Write(value);
  delay(defaultDelay);
  sevenSeg1255.write1(value); //just calls digit1Write(int value)
  delay(defaultDelay);
  sevenSeg1255.digit1Write(character);
  delay(defaultDelay);
  sevenSeg1255.write1(character); //just calls digit1Write(char character)
  delay(defaultDelay);

  sevenSeg1255.digit2CharWrite(character);
  delay(defaultDelay);
  sevenSeg1255.digit2OctWrite(value);
  delay(defaultDelay);
  sevenSeg1255.digit2DecWrite(value);
  delay(defaultDelay);
  sevenSeg1255.digit2HexWrite(value);
  delay(defaultDelay);
  sevenSeg1255.digit2Write(value);
  delay(defaultDelay);
  sevenSeg1255.write2(value); //just calls digit1Write(int value)
  delay(defaultDelay);
  sevenSeg1255.digit2Write(character);
  delay(defaultDelay);
  sevenSeg1255.write2(character); //just calls digit1Write(char character)
  delay(defaultDelay);

  sevenSeg1255.write(value); // have overload led?, prints two digits, calls write1 and write0, which each do only one digit (LSD, MSD?) <99
  delay(defaultDelay);
  sevenSeg1255.write(characters);// two char array, string 2 characters
  delay(defaultDelay);

  sevenSeg1255.scroll(characterString);// two char array, string 2 characters
  delay(defaultDelay);
  sevenSeg1255.scroll(characterString, defaultDelay);// two char array, string 2 characters
  delay(defaultDelay);

  sevenSeg1255.write(value, digit); // write to specific digit, calls digit1Write(int value) or digit0Write(int value) as appropriate
  delay(defaultDelay);
  sevenSeg1255.write(character, digit);// write to specific digit, calls digit1Write(char character) or digit0Write(char character) as appropriate
  delay(defaultDelay);

// Tests out of range: value, character and character2
  if (value > maxValue)
    value=0;
  if (segmentMapCode > maxSegmentMapCode)
    character=0;
  if (character > maxCharacter)
    character=0;
}
