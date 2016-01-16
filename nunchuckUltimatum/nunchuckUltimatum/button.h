// button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9.h>
void placeButton(MI0283QT9 lcd, int16_t backgroundcolour, int16_t tekstcolour, char *text, uint8_t lcX, uint16_t lcY, uint8_t buttonsizeY, uint8_t buttonsizeX);
int8_t getWidthButtons();
int8_t getXwaardeButtons();
int8_t getButtonLength();
int8_t getButton1X();
int8_t getButton2X();
int8_t getButton3X();
int8_t getButton4X();

#endif

