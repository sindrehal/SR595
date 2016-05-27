#include "SR595.h"

SR595::SR595(int latchPin, int clockPin, int dataPin)
{
	_Output = 0;
	_latchPin = latchPin;
	_clockPin = clockPin;
	_dataPin = dataPin;

}

void SR595::init()
{
	pinMode(_latchPin, OUTPUT);
	pinMode(_clockPin, OUTPUT);
	pinMode(_dataPin, OUTPUT);
	clear();
}

void SR595::Write(int whichPin, int whichState)
{
	digitalWrite(_latchPin, LOW);
	bitWrite(_Output, whichPin, whichState);
	shiftOut(_dataPin, _clockPin, MSBFIRST, _Output);
	digitalWrite(_latchPin, HIGH);
}

void SR595::clear()
{
	digitalWrite(_latchPin, LOW);
	shiftOut(_dataPin, _clockPin, MSBFIRST, _Output);
	digitalWrite(_latchPin, HIGH);
}

SR595::~SR595()
{
}
