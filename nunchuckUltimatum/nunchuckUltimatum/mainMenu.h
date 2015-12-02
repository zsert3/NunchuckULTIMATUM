// mainMenu.h

#ifndef _MAINMENU_h
#define _MAINMENU_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <digitalWriteFast\digitalWriteFast.h>
#include <SPI\SPI.h>
#include <GraphicsLib\GraphicsLib.h>
#include <MI0283QT9\MI0283QT9.h>

void drawMenuScherm(MI0283QT9 lcd);
void touchScreen(MI0283QT9 lcd);
#endif

