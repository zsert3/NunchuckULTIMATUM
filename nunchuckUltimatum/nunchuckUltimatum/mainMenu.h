// mainMenu.h

#ifndef _MAINMENU_h
#define _MAINMENU_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "highscores.h"
#include "tutorial.h"

void drawMenuScherm(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
void touchScreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
void terugButton(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
#endif

