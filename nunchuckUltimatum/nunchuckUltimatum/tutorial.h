// tutorial.h

#ifndef _TUTORIAL_h
#define _TUTORIAL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h" 
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9\MI0283QT9.h>
#include "boot.h"


void basicscreenTutorial(MI0283QT9 lcd, int16_t waterColour, int16_t textColour);
#endif

