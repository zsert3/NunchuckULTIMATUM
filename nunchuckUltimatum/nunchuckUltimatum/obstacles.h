// obstacles.h

#ifndef _OBSTACLES_h
#define _OBSTACLES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9.h>

void draw_obstacles(MI0283QT9 lcd);
void shift_obstacles(MI0283QT9 lcd);
void reset_obstacles();
void set_obstaclespeed(uint8_t speed);
uint8_t get_obstaclespeed();
uint8_t get_obstaclex(uint8_t i);
uint16_t get_obstacley(uint8_t i);
uint8_t get_obstacles(uint8_t i);

typedef struct {
	uint8_t osize;
	uint16_t olocationy;
	uint8_t olocationx;
}obstacles;

#endif

