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
#include "lives.h"
#include "mainMenu.h"
#include "obstacles.h"
#include "score.h"
#include "gameover.h"

void gameInitialisation(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
void game(MI0283QT9 lcd, int watercolour, int treecolour, int landcolour, int tekstcolour);
void checkCollision(MI0283QT9 lcd, uint8_t x, uint16_t y, uint8_t size, int watercolour, int landcolour, int tekstColour);
void setBlocationX(int Blocationx);
void setBlocationY(int Blocationy);
void setVisable();

#endif

