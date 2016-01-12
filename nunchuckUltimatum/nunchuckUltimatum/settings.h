// settings.h

#ifndef _SETTINGS_h
#define _SETTINGS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9\MI0283QT9.h>
#include "eepromManager.h"
#include "mainMenu.h"

void basicscreenSettings(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
#endif

