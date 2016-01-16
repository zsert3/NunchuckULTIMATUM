// button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9.h>
void placeButton(MI0283QT9 lcd, int16_t backgroundColour, int16_t textColour, char *text, uint8_t lcX, uint16_t lcY, uint8_t buttonSizeY, uint8_t buttonSizeX);
uint8_t getWidthButtons();
uint8_t getXValueButtons();
uint8_t getButtonLength();
uint8_t getButton1X();
uint8_t getButton2X();
uint8_t getButton3X();
uint8_t getButton4X();

#endif

