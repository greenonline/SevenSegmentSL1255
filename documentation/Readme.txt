        *** SevenSegment SL-1255-30 Library ***
       =========================================

        *** Readme ***
       ================

       Version : 0.5.5

Brief
=====

This is an Arduino Library for the Sanyo SL-1255-30 two digit seven segment display (without decimal points).

Introduction
============

One day, in March 2015, whilst shopping for Arduino bits and pieces in Ban Mo, an electronics street market in BKK, I came across a large sheet of polystyrene bejewelled in Sanyo SL-1255-30 two digit seven segment displays, for 5 Baht each, which was displayed in the street outside a shop. I purchased one of the seven segment displays, took it home, and eventually realised that no libraries existed for the common cathode (?) device.  So I promptly set about writing my own sketch, which then evolved into an Arduino Library that was developed over the course of a couple of weeks. This is that library.

Synopsis
========
When the class is instantiated using the defaults then it will work with the Sanyo SL-1255 (red) and SL-2255 (green) dual seven segment displays, which are common cathode devices. The private member, _onValue, is LOW for the segments of these displays.

This library will also work with SL-1256 and SL-2256 (green) common anode(?) devices, just specify the ssType (seven segment type) parameter in the constructor using the predefined SL-1256 or SL-2256 macros. The private member, _onValue, is HIGH for the segments of these displays. Alternatively, it is possible to specify the onValue and offValue, instead of using the ssType parameter, using the appropriate constructor. Please see the constructor examples below.

The public methods supplied include (direct) draw, effects, as well as, the usual Arduino, begin() and write(), methods for ints and char arrays ([1] and [2]). The standard C++ getters and setters for accessing class members are also provided.  The various method types are briefly discussed below. The methods are often overridden to provide versatility and to suit various writing styles. This may appear confusing initially, although a simple subset of the methods is all that is required in order to get the library up and running with your display (constructor, begin, write).

Library Contents
================

    SevenSeg1255.h
    SevenSeg1255.cpp
    keywords.txt
    SevenSegmentMaps.h
    examples/Accessors/Accessors.ino
    examples/AccessorsPlus/AccessorsPlus.ino
    examples/Effects/Effects.ino
    examples/EffectsMulti/EffectsMulti.ino
    examples/EffectsByIndex/EffectsByIndex.ino
    examples/GetSetPinState/GetSetPinState.ino
    examples/GetSetSegmentState/GetSetSegmentState.ino
    examples/GetSetPinState/GetSetPinState.ino
    examples/GetSetStateAll/GetSetStateAll.ino
    examples/HelloWorld/HelloWorld.ino
    examples/SevenSegMaps/SevenSegMaps.ino
    examples/SevenSegMaps99Loop/SevenSegMaps99Loop.ino
    examples/SevenSegMapsLoop/SevenSegMapsLoop.ino
    documentation/Readme.txt
    documentation/QuickStart.txt
    documentation/7-seg display sl-1255-30 DSA-305501.pdf
    documentation/photos/breadboard01.jpg
    documentation/photos/breadboard02.jpg
    documentation/photos/breadboard03.jpg
    documentation/photos/SL-1255-30.jpg
    documentation/schematics/SL-1255_Nano_bb_fritzing-01.jpg
    documentation/schematics/SL-1255_Nano.fzz
    documentation/schematics/sevenSegmentASCIIMaps.jpg

Default Pinout
==============

Refer to SANYO SL-1255-30 datasheet, located at http://www.datasheetarchive.com/dlmain/Datasheets-16/DSA-305501.pdf

    pin 2 -> segment a1 (15)
    pin 3 -> segment b1 (13)
    pin 4 -> segment c1 (1)
    pin 5 -> segment d1 (3)
    pin 6 -> segment e1 (2)
    pin 7 -> segment f1 (14)
    pin 8 -> segment g1 (16)
    pin 9 -> segment a2 (10)
    pin 10 -> segment b2 (12)
    pin 11 -> segment c2 (8)
    pin 12 -> segment d2 (6)
    pin 13 -> segment e2 (7)
    pin 14 -> segment f2 (11)
    pin 15 -> segment g2 (9)
    Vcc    -> ANODE 1 (4)
    Vcc    -> ANODE 2 (5)

Constructor Methods
===================

There are five various overridden constructors. Please note that all constructors configure the pins for both digits. The reason is that this library is designed for the two digital SL-1255 display. If you only want to configure the pins for just one digit, then use a sign digit version of this library. Here is a list of the constructor types:

Default
-------

Sets up the two digits using the default pins Pin2 through to Pin16.

One Digit
---------

Sets up the most significant digit (MSD) with user defined pins and the least significant digit (LSD) with Pin10 though to Pin 16.

Two Digits
----------

Sets up the most significant digit (MSD) and the least significant digit (LSD) with user defined pins.

Two Digits with ssType
----------------------

Sets up the most significant digit (MSD) and the least significant digit (LSD) with user defined pins and allows the user to specify the Seven Segment type (by the parameter ssType) using a pre-defined model {SL1255, SL1256, SL2255, SL2256} which are set to either 0 or 1 (equivalent to the OnValue being HIGH or LOW respectively).

Two Digits with onValue and offValue
------------------------------------

Sets up the most significant digit (MSD) and the least significant digit (LSD) with user defined pins and allows the user to specify the LED on state (using the parameter OnValue) to LOW or HIGH, and the LED off state (using the parameter OffValue) should be set to the complement of the OnValue, i.e. if OnValue is LOW, the OffValue should be HIGH.

Draw Methods
============

These direct draw methods are derived from the first attempts at writing test code to get the SL-1255 working with the Arduino. They are left in place for completeness, and someone may find them useful. However, they have been largely superseded by the Write methods, although the drawBitmap() methods [read as drawSevenSegmentMaps()] are still useful and form the man body of the drawing routines. Most of the direct draw methods are deprecated in the Lite version of this library SevenSegLite1255. The direct draw methods use the non-standard (Arduino) naming convention of draw_Xx, where the position of the 'x' denotes which segment is being written to. So, draw_Ax() displays an 'A' character on digit1, and draw_xh() displays an 'h' character on digit 0.  This differs from the drawBitmap and Write methods that use a more conventional '0' and '1', in the method name, to denote the least significant and most significant digit of the display (and '2' to denote both digits). 

Begin Methods
=============

These methods assign the pins of the Arduino, and should be called from the setup() function in the Arduino sketch

Write Methods
=============
These methods enable the user to pass a numeric (octal, decimal or hexadecimal) value or alphanumeric (or ASCII) character to the method to display on either or both of the display's digits.

Effects Methods
===============

These methods provide various visual effects that may be employed on the seven segment display. For example, various methods exist which:
  - rotate the segment that is illuminated in a number of different ways, or;
  - blank() the display (all segments are switched off), or;
  - fill() the display (all segments are switched on), or;
  - flash() the lit segments (all segments are alternately switched on and then after a specified delay switched off).

The best way to understand them is to experiment with each of them to see what they do. The blank(), fill() and flash() methods are the simplest to understand, and are probably the most useful. 

These effect methods can be called directly or via an index parameter. A 'catalogue' method, effect(), is also provided that can be called using the index parameter to call the various functions. You can cycle throughout the effects by putting this method in a for loop and calling it repeatedly, increasing the value of the passed index. This forms part of the example sketch, EffectsByIndex. The value of the index parameter is between 0 and 25, as there are 26 different effects. 

A delay parameter can also be used, which effectively specifies the speed of the effect, i.e. the delay between successive segments being illuminated.

Note: This delay is not the total delay, i.e. the total duration of the effect, but the delay between the actuating of the individual segments of the effect. So the total duration of the effect becomes equal to the delay multiplied by the number of segments used in the effect. So, the total duration of some effects may be longer than that of others. 

Getters and Setters
===================
These methods provide access to the private members of the class - the individual segments (_a0, _b0, _c0, … _g0, _a1, _b1, … _g1), the on and off values (_onValue and _offValue) and the seven segment type (_ssType)

Example Sketches
================
Some examples have been include to familiarise the user with the various methods available. These focus on the areas outlined in the Methods sections, so there is an example demonstrating the direct draw functions, another for the effects, one illustrating the accessor methods, the getters and setters (making use of the serial port to write and display values of the private members), and finally a couple of simple Arduino write examples. It is this write example that ail probably be the most pertinent to everyday display projects.

Conclusion
==========
Please enjoy using this library. It may be a little heavyweight, as it is an "everything-but-the-kitchen-sink" type library, with many member methods overridden and duplicated with different function names, in order to accommodate new Arduino users, by adhering to Arduino naming standards and conventions, as well as some non standard functions, included for the convenience, and amusement, of advanced users.

If you would prefer to employ a light weight version of this library that has been cut down, for memory economics, please consider using SevenSegLiteSL1255

Known Issues
============

1. The method draw_xx() is ambiguous by nature, due to the naming convention. Does it draw on the first or segment digit? Hence, use draw_Hx() ad draw_xH() as they produce the same character as draw_xx(), "X"

2. Digit 2 (the right hand digit), in the library, is referred to as digit 0, in the interest of least significant and most significant digits. This may cause confusion, as it conflicts with the data sheet for the SL-1255-30. Hence the draw0() methods have been replicated with draw2() methods for completeness. However as that conflicts with the binary notion of draw2() for writing to both digits (0 and 1) simultaneously, "3" has been used to signify both digits (or the effects methods only). If you want to display a two character string then just use the write() or scroll() methods, as a draw3() method has not be provided for, see example sketch HelloWorld.ino.

3. Arduino Nano does not enough enough digital pins (two pins short), and so A0 and A1 are used as D15 and D16. D0 and D1 should not be used, as they are used for Rx and Tx respectively.

Developer Notes:
================
Below is a scratch pad for ideas which are completed, in progress and/or pipe dreams.

To Do
=====

Provide printf() and putchar() functions

Add 7 segment display chip (7447/5447) routines

Test common anode (buy SL-1256 display)

Add functionality for extra mega pins

Delete test code and test print statements

Test the functions

Complete standard letters function naming

Add methods .a, .b .c which call draw_ax etc.
  - or write(int); write(char);

Need to be able to print strings

Make the class extensible, supporting more (chained) displays 

Create lite version (cut down class)

For the effects methods decide whether to pass totalDelay vs delayBetweenSegments

Complete camelCase of method and variable names, remove underscores (draw_Ax vs drawA1, drawA2 vs drawCharacterA1))

Why do you have to specify both OnValue and OffValue, when logically you should only have to specify the OnValue, and the OffValue can take the complement.

Constructor for only one or other display digit
  - Maybe pins are used by something else, inputs for example.
  - Need constructor to set the LSD pins and default the MSD pins.

Better name for lite class:
Seg71255
Seg7x25x
ss1255
ssx25x

Define default pinouts for models;
Define memory for large amounts of strings too;
  - have constructor to take Arduino model define:
    #define nano
    #define uno
    #define mega

Check octal write example

Add shift (left and right) method
  - scroll by one character

Add invertDisplay() effect

Add graphicEqualiser() effect.

Add sequentialHorizontalBars() effect

Add hyphen to class name, SL-1255?


Done
====

Have predefined bitmaps (seven segment maps)
  - use Seven Segment code: 7 bit number, i.e. bit 0 = a, bit 6 = g, [bit 7 = dp]
  #define A 119 (1, 2, 4, 8, 16, 32, 64)
  - include odd glyphs like underline, mid line, top line, side lines, and combinations thereof (similar to ZX81 character set)
  - drawBitmap(){}
  - drawBitmapInvert(){}

Array of char glyphs
  - change defines from d1, d2, etc. to actual literals
  - add convertor function (for use by putc, printf)
  - hash table

Can use draw bitmap to rotate effects, etc.

Should constructor declare the pinout, normally done in setup()
RESOLVED - no, goes in begin()

Created digit write methods:
  - digit1Write();
  - digit2Write();


Created .write() which calls digit1Write and digit2Write, depending on LSD or MSD

Catalogue of effects
  - effect(int) {} //cycle thru effects

Need to be able to print numbers, use array of codes

Need to be able to count
  - could have case statement, that calls draw_11, draw_21 etc., depending on value passed

Provide draw_rotateCircle() as well as figure of 8

Explain the use of constructor in read me (ssType vs on/offValue)

Added default pinout to readme

Added SL-1255 pins to pin out

Added two draw seven segment maps loop examples:
  - ASCII and;
  - 0 through to 99

Added keywords

Added second digit functions

Added method allowing user to specify digit in parameter, thus draw(int char, int digit)

Called draw_a1() from draw_ax(), and draw_a2() from draw_xa()

Provided example code sketches

Added getPinState() methods - use Arduino Port States?
  - used digitalRead(pin);
  - added getSegmentState(char[2] segment);

Added example for getState() and setState(), GetSetState.ino

Added use of D0, D1, A0 and A1 pins on Nano to the Readme

Changed digit0 refs (a0-g0) to digit2 (a2-g2), as per data sheet.

Defined draw(char) methods

Defined write(char) methods

Added the method effect3(), for both digits simultaneously, as opposed to sequentially.

Provided a scroll function (left and right)

Fixed parameter discrepancy between drawBitmapX(int character) and writeX(char character) methods
  - (int character) became (int sevensegmentCode)

Explained fill(), blank() and flash() in Readme.txt and QuickStart.txt

Added QuickStart.txt doc:
  - pinout
  - routines (begin, etc)
  - basic example

Included ASCII bitmap picture:
  - Draw in GIMP
  - Use grid for alignment
  - Have empty seven segment template

Added Fritzing diagram

Added photo of SL-1255 display

Added SL-1255 data sheet

Changed class and file names from SevenSeg1255 to SevenSegSL1255

Changed low fat repository name from SevenSegLite1255 to SevenSegmentSL1255Lite

Put all docs, photos and schematics in documentation/ directory




