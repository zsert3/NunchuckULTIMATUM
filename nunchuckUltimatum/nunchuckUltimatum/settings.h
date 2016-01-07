// settings.h

#ifndef _SETTINGS_h
#define _SETTINGS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9\MI0283QT9.h>
#include <avr/io.h>

void basisschermSettings(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
void setBrightness(MI0283QT9 lcd, int currentBrightness);

#endif

