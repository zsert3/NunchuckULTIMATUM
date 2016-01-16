
#include "obstacles.h"

obstacles obstacle[5];
uint8_t i;
uint8_t obstaclespeed = 1;

void drawObstacles(MI0283QT9 lcd) {
	for (i = 0; i < 5; i++) {
		lcd.fillRect((obstacle + i)->oLocationx, (obstacle + i)->oLocationy - obstaclespeed, (obstacle + i)->oSize, obstaclespeed, RGB(100, 149, 237));
		lcd.fillRect((obstacle + i)->oLocationx, (obstacle + i)->oLocationy + obstaclespeed, (obstacle + i)->oSize, 8 - obstaclespeed, RGB(139, 69, 0));
		(obstacle + i)->oLocationy += obstaclespeed;
	}
}

void shiftObstacles(MI0283QT9 lcd) {
	if ((obstacle + 0)->oLocationy >= 64 || (obstacle + 0)->oSize == 0) {
		lcd.fillRect((obstacle + 4)->oLocationx, (obstacle + 4)->oLocationy - obstaclespeed, (obstacle + 4)->oSize, obstaclespeed, RGB(100, 149, 237));
		//increase score when there is an new obstacle
		increaseScore();
		//increase speed when the score is dividable by 19 (max speed is 4)
		if (getScore() % 20 == 19 && getObstaclespeed() <= 3)increaseObstaclespeed();
		//shift every obstacle by 1 to make space for a new obstacle
		for (i = 4; i > 0; i--) 
		{
		*(obstacle + i) = *(obstacle + i - 1);
		}
		obstacle->oSize = (rand() % 5 + 5) * 10;
		obstacle->oLocationx = (rand() % (9 - obstacle->oSize / 10 + 13) + 1) * 10 + 1;
		obstacle->oLocationy = 0;
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
	return (obstacle + i)->oLocationx;
}


uint16_t getObstacley(uint8_t i) {
	return (obstacle + i)->oLocationy;
}


uint8_t getObstacles(uint8_t i) {
	return (obstacle + i)->oSize;
}



