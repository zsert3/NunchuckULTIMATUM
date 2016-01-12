// gameover.h

#ifndef _GAMEOVER_h
#define _GAMEOVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9.h>
#include "mainMenu.h"

void basicschermGameOver(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
void touchScreenGameOver(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour);

#endif

