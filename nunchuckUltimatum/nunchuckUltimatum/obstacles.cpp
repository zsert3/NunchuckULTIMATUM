// 
// 
// 

#include "obstacles.h"

obstacles obstacle[5];
uint8_t i;
uint8_t obstaclespeed = 1;

void drawObstacles(MI0283QT9 lcd) {
	obstaclespeed = 4;
	for (i = 0; i < 5; i++) {
		lcd.fillRect((obstacle + i)->olocationx, (obstacle + i)->olocationy - obstaclespeed, (obstacle + i)->osize, obstaclespeed, RGB(100, 149, 237));
		lcd.fillRect((obstacle + i)->olocationx, 8 - (obstacle + i)->olocationy + obstaclespeed, (obstacle + i)->osize, obstaclespeed, RGB(139, 69, 0));
		//lcd.fillRect((obstacle + i)->olocationx, (obstacle + i)->olocationy + obstaclespeed, (obstacle + i)->osize, 8 - obstaclespeed, RGB(139, 69, 0));
		//if ((obstacle + i)->olocationx >= 180) {
		//	lcd.fillRect((obstacle + i)->olocationx - (obstacle + i)->osize, (obstacle + i)->olocationy - obstaclespeed, 90 - (obstacle + i)->osize, obstaclespeed, RGB(100, 149, 237));
		//	lcd.fillRect((obstacle + i)->olocationx - (obstacle + i)->osize, (obstacle + i)->olocationy + obstaclespeed, 90 - (obstacle + i)->osize, 8 - obstaclespeed, RGB(139, 69, 0));
		//}
		//else {
		//	lcd.fillRect((obstacle + i)->olocationx + (obstacle + i)->osize, (obstacle + i)->olocationy - obstaclespeed, 90 - (obstacle + i)->osize, obstaclespeed, RGB(100, 149, 237));
		//	lcd.fillRect((obstacle + i)->olocationx + (obstacle + i)->osize, (obstacle + i)->olocationy + obstaclespeed, 90 - (obstacle + i)->osize, 8 - obstaclespeed, RGB(139, 69, 0));
		//}
		//check_collision(lcd, (obstacle + c)->olocationx, (obstacle + c)->olocationy, (obstacle + c)->osize, watercolour, landcolour, tekstcolour);
		(obstacle + i)->olocationy += obstaclespeed;
	}
}

void shiftObstacles(MI0283QT9 lcd) {
	if ((obstacle + 0)->olocationy >= 64 || (obstacle + 0)->osize == 0) {
		lcd.fillRect((obstacle + 4)->olocationx, (obstacle + 4)->olocationy - obstaclespeed, (obstacle + 4)->osize, obstaclespeed, RGB(100, 149, 237));
		for (i = 4; i > 0; i--) {
			*(obstacle + i) = *(obstacle + i - 1);
		}
		//if (rand() % 3 == 1) {
		//	obstacle->omoving = 1;
		//	obstacle->odirection = 2;
		//	obstacle->osize = 40;
		//	obstacle->olocationx = (rand() % 17 + 1) * 10 + 2;
		//}
		//else {
			obstacle->osize = (rand() % 5 + 5) * 10;
		//obstacle->osize = 90;
			obstacle->olocationx = (rand() % (9 - obstacle->osize / 10 + 13) + 1) * 10 + 1;
		//}
		obstacle->olocationy = 0;
	}
}

void set_obstaclespeed(uint8_t speed) {
	obstaclespeed = speed;
}

void reset_obstacles() {
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



