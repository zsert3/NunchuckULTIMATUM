// obstacles.h

#ifndef _OBSTACLES_h
#define _OBSTACLES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9.h>

void drawObstacles(MI0283QT9 lcd);
void shiftObstacles(MI0283QT9 lcd);
void resetObstacles();
void setObstaclespeed(uint8_t speed);
void increaseObstaclespeed();
uint8_t getObstaclespeed();
uint8_t getObstaclex(uint8_t i);
uint16_t getObstacley(uint8_t i);
uint8_t getObstacles(uint8_t i);

typedef struct {
	uint8_t osize;
	uint16_t olocationy;
	uint8_t olocationx;
	uint8_t omoving;
	int8_t odirection;
}obstacles;

#endif

