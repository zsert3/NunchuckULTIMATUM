#ifndef _OBSTACLES_h
#define _OBSTACLES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9.h>
#include "score.h"

void drawObstacles(MI0283QT9 lcd);
void shiftObstacles(MI0283QT9 lcd);
void resetObstacles();
void increaseObstaclespeed();
void resetObstaclespeed();
uint8_t getObstaclespeed();
uint8_t getObstaclex(uint8_t i);
uint16_t getObstacley(uint8_t i);
uint8_t getObstacles(uint8_t i);

typedef struct {
	uint8_t oSize;
	uint16_t oLocationy;
	uint8_t oLocationx;
}obstacles;

#endif

