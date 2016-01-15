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
#include "button.h"

void basicscreenSettings(MI0283QT9 lcd, int16_t watercolour, int16_t landcolour, int16_t tekstcolour);
#endif

