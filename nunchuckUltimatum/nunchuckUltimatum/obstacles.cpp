
#include "obstacles.h"

obstacles obstacle[5];
uint8_t i;
uint8_t obstaclespeed = 1;

void drawObstacles(MI0283QT9 lcd) {
	for (i = 0; i < 5; i++) {
		lcd.fillRect((obstacle + i)->olocationx, (obstacle + i)->olocationy - obstaclespeed, (obstacle + i)->osize, obstaclespeed, RGB(100, 149, 237));
		lcd.fillRect((obstacle + i)->olocationx, (obstacle + i)->olocationy + obstaclespeed, (obstacle + i)->osize, 8 - obstaclespeed, RGB(139, 69, 0));
		(obstacle + i)->olocationy += obstaclespeed;
	}
}

void shiftObstacles(MI0283QT9 lcd) {
	if ((obstacle + 0)->olocationy >= 64 || (obstacle + 0)->osize == 0) {
		lcd.fillRect((obstacle + 4)->olocationx, (obstacle + 4)->olocationy - obstaclespeed, (obstacle + 4)->osize, obstaclespeed, RGB(100, 149, 237));
		//increase score when there is an new obstacle
		increaseScore();
		//increase speed when the score is dividable by 19 (max speed is 4)
		if (getScore() % 20 == 19 && getObstaclespeed() <= 3)increaseObstaclespeed();
		//shift every obstacle by 1 to make space for a new obstacle
		for (i = 4; i > 0; i--) 
		{
		*(obstacle + i) = *(obstacle + i - 1);
		}
		obstacle->osize = (rand() % 5 + 5) * 10;
		obstacle->olocationx = (rand() % (9 - obstacle->osize / 10 + 13) + 1) * 10 + 1;
		obstacle->olocationy = 0;
	}
}


void resetObstaclespeed() {
	obstaclespeed = 1;
}


void resetObstacles() {
	memset(obstacle, 0, sizeof(obstacle));
}


void increaseObstaclespeed() {
	obstaclespeed++;
}


uint8_t getObstaclespeed() {
	return obstaclespeed;
}


uint8_t getObstaclex(uint8_t i) {
	return (obstacle + i)->olocationx;
}


uint16_t getObstacley(uint8_t i) {
	return (obstacle + i)->olocationy;
}


uint8_t getObstacles(uint8_t i) {
	return (obstacle + i)->osize;
}



