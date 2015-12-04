// highscores.h

#ifndef _HIGHSCORES_h
#define _HIGHSCORES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <digitalWriteFast\digitalWriteFast.h>
#include <SPI\SPI.h>
#include <GraphicsLib\GraphicsLib.h>
#include <MI0283QT9\MI0283QT9.h>


void basisschermHighScores(MI0283QT9 lcd, int colour1, int colour2, int tekstColour);

#endif

