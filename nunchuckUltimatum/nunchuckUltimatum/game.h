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

void gameInitialisation(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour);
void game(MI0283QT9 lcd, int16_t waterColour, int16_t treeColour, int16_t landColour, int16_t textColour);
void checkCollision(MI0283QT9 lcd, uint8_t x, uint16_t y, uint8_t size, int16_t waterColour, int16_t landColour, int16_t textColour);
void setBlocationX(uint16_t Blocationx);
void setBlocationY(uint16_t Blocationy);
void setVisable();

#endif

