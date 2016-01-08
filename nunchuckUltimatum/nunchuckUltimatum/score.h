// score.h

#ifndef _SCORE_h
#define _SCORE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <MI0283QT9\MI0283QT9.h>

void drawScore(MI0283QT9 lcd);
void increaseScore();
void resetScore();
int getScore();

#endif

