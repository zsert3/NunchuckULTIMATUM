// boot.h

#ifndef _BOOT_h
#define _BOOT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9\MI0283QT9.h>
#include "obstacles.h"
#include "game.h"
void drawboot(MI0283QT9 lcd, int x, int y);
void resetBoat(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);

#endif

