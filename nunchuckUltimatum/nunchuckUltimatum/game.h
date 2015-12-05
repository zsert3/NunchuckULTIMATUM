// game.h

#ifndef _GAME_h
#define _GAME_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9.h>
#include "nunchuckData.h"
#include "boot.h"

void gameInitialisation(MI0283QT9 lcd, int watercolour, int landcolour);
void game(MI0283QT9 lcd, int watercolour, int treecolour, int landcolour);
void check_collision(MI0283QT9 lcd, int blocationx, int blocationy, int watercolour, int landcolour);
void resetboat(MI0283QT9 lcd, int watercolour, int landcolour);
void setBlocationX(int Blocationx);
void setBlocationY(int Blocationy);

#endif

