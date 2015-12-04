// game.h

#ifndef _GAME_h
#define _GAME_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9\MI0283QT9.h>
#include "nunchuckData.h"
#include "boot.h"

int blocationx = 110;
int blocationy = 270;
int obstacles[320] = { 0 };
//obstacle obstacles1[80];
int joyx;
int joyy;
int b;

typedef struct {
	int size;
	int location;
}obstacle;

void gameInitialisation(void);
void game(MI0283QT9 lcd, int watercolour, int treecolour);
void check_collision(void);
#endif

