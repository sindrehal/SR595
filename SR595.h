/***************************************************
This is a library for Shift Register SN75HC595 on Arduino / ESP8266 with Arduino

Author:		Sindre Halbjørhus - sindre@ihemsedal.no

MIT License

Copyright (c) 2016 Sindre Halbjørhus

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

All text above must be included in any redistribution
****************************************************/

/*
Pin connected to latch pin (ST_CP / RCLK) pin 12 of 74HC595
Pin connected to clock pin (SH_CP / SRCLK) pin 11 of 74HC595
Pin connected to Data in (DS / SER) pin 14 of 74HC595
*/

#pragma once
#include "Arduino.h"

#ifndef SR595_H_
#define SR595_H_

class SR595
{
public:
	SR595(int, int, int);
	~SR595();
	void init();
	void Write(int, int);
private:
	byte _Output;
	int _latchPin;
	int _clockPin;
	int _dataPin;
	void clear();
};

#endif // !SR595_H_