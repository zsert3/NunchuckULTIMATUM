// button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9.h>
void placeButton(MI0283QT9 lcd, int backgroundcolour, int tekstcolour, char *text, int lcX, int lcY, int buttonsizeY, int buttonsizeX);
int getWidthButtons();
int getXwaardeButtons();
int getButtonLength();
int getButton1X();
int getButton2X();
int getButton3X();
int getButton4X();

#endif

