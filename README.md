# SevenSegmentSL1255
Arduino Library for Sanyo SL-1255, SL-1256, SL-2255, SL-2256 Seven Segment LED Displays

        *** SevenSegment SL-1255-30 Library ***
       =========================================

       Version : 0.5

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
keywords.text
sevensegmentmaps.h
readme
Examples/

Constructor Methods
===================

There are five various overridden constructors:

Default
-------

Sets up the two digits using the default pins Pin2 through to Pin16.

One Segment
-----------

Sets up the most significant digit (MSD) with user defined pins and the least significant digit (LSD) with Pin10 though to Pin 16.

Two segments
------------

Sets up the most significant digit (MSD) and the least significant digit (LSD) with user defined pins.

Segments with ssType
--------------------

Sets up the most significant digit (MSD) and the least significant digit (LSD) with user defined pins and allows the user to specify the Seven Segment type (by the parameter ssType) using a pre-defined model {SL1255, SL1256, SL2255, SL2256} which are set to either 0 or 1 (equivalent to the OnValue being HIGH or LOW respectively).

Segments with onValue and offValue
-----------------------------------

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

These methods provide various effects, to rotate or flash the lit segments, or clear functions. Experiment with them to see what they do. A 'catalogue' method, effect(), exists that is called with an index to call the various functions. You can cycle throughout the effects by putting this method in a for loop and calling it repeatedly, increasing the value of the passed index. This forms part of the example sketch. The value of the index parameter is between 0 and 25. A delay parameter can also be used, which effectively specifies the speed of the effect.

Getters and Setters
===================
These methods provide access to the private members of the class - the individual segments (_a0, _b0, _c0, … _g0, _a1, _b1, … _g1), the on and off values (_onValue and _offValue) and the seven segment type (_ssType)

Example Sketches
================
Some examples have been include to familiarise the user with the various methods available. These focus on the areas outlined in the Methods sections, so there is an example demonstrating the direct draw functions, another for the effects, one illustrating the accessor methods, the getters and setters (making use of the serial port to write and display values of the private members), and finally a simple Arduino write example. It is this write example that ail probably be the most pertinent to everyday display projects.

Conclusion
==========
Please enjoy using this library. It may be a little heavyweight, as it is an "everything-but-the-kitchen-sink" type library, with many member methods overridden and duplicated with different function names, in order to accommodate new Arduino users, by adhering to Arduino naming standards and conventions, as well as some non standard functions, included for the convenience, and amusement, of advanced users.

If you would prefer to employ a light weight version of this library that has been cut down, for memory economics, please consider using SevenSegLiteSL1255

Developer Notes:
================
Below is a scratch pad for ideas which are completed, in progress and/or pipe dreams.

To Do
=====

Provide printf() and putchar() functions

Provide a scroll function (left and right)

Add 7 segment display chip (7447/5447) routines

Test common anode (buy SL-1256 display)

Add functionality or extra mega pins

Delete test code and test print statements

Test the functions

Add keywords

Add second digit functions

Complete standard letters function naming

Add methods .a, .b .c which call draw_ax etc.
  - or write(int); write(char);

CamelCase function names

Need to be able to print strings

Constructor for only one or other display digit. Maybe pins are used by something else, inputs for example.

Make the class extensible, supporting more (chained) displays 

Create lite version (cut down class)

total delay vs delay between segments

complete camelCase, remove underscores (draw_Ax vs drawA1, drawA2 vs drawCharacterA1))

Provide example code sketches

Why have to specify both OnValue and OffValue, when logically you should only have to specify the OnValue, and the OffValue can take the complement.

Need constructor to set the LSD and default the MSD.

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

digit1Write();
digit2Write();
.Write calls digit1Write and digit2Write, depending on LSD or MSD

Catalogue of effects
  - effect(int) {} //cycle thru effects

Need to be able to print numbers, use array of codes

Need to be able to count
  - could have case statement, that calls draw_11, draw_21 etc., depending on value passed

Provide draw_rotateCircle() as well as figure of 8

Explain the use of constructor in read me (ssType vs on/offValue)





