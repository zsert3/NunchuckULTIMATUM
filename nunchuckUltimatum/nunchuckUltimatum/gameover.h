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

void basicschermGameOver(MI0283QT9 lcd, int16_t watercolour, int16_t landcolour, int16_t tekstcolour);
void touchScreenGameOver(MI0283QT9 lcd, int16_t watercolour, int16_t landcolour, int16_t tekstcolour);

#endif

