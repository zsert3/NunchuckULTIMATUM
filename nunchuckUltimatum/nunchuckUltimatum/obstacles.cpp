// 
// 
// 

#include "obstacles.h"

obstacles obstacle[5];
uint8_t i;
uint8_t obstaclespeed = 1;

void draw_obstacles(MI0283QT9 lcd) {
	for (i = 0; i < 5; i++) {
		lcd.fillRect((obstacle + i)->olocationx, (obstacle + i)->olocationy - obstaclespeed, (obstacle + i)->osize, obstaclespeed, RGB(100, 149, 237));
		lcd.fillRect((obstacle + i)->olocationx, (obstacle + i)->olocationy + obstaclespeed, (obstacle + i)->osize, 8 - obstaclespeed, RGB(139, 69, 0));
		//check_collision(lcd, (obstacle + c)->olocationx, (obstacle + c)->olocationy, (obstacle + c)->osize, watercolour, landcolour, tekstcolour);
		(obstacle + i)->olocationy += obstaclespeed;
	}
}

void shift_obstacles(MI0283QT9 lcd) {
	if ((obstacle + 0)->olocationy >= 64 || (obstacle + 0)->osize == 0) {
		lcd.fillRect((obstacle + 4)->olocationx, (obstacle + 4)->olocationy - obstaclespeed, (obstacle + 4)->osize, obstaclespeed, RGB(100, 149, 237));
		for (i = 4; i > 0; i--) {
			*(obstacle + i) = *(obstacle + i - 1);
		}
		obstacle->olocationy = 0;
		obstacle->osize = (rand() % 5 + 5) * 10;
		obstacle->olocationx = (rand() % (9 - obstacle->osize / 10 + 13) + 1) * 10 + 1;
	}
}

void set_obstaclespeed(uint8_t speed) {
	obstaclespeed = speed;
}

void reset_obstacles() {
	memset(obstacle, 0, sizeof(obstacle));
}

uint8_t get_obstaclespeed() {
	return obstaclespeed;
}

uint8_t get_obstaclex(uint8_t i) {
	return (obstacle + i)->olocationx;
}

uint16_t get_obstacley(uint8_t i) {
	return (obstacle + i)->olocationy;
}

uint8_t get_obstacles(uint8_t i) {
	return (obstacle + i)->osize;
}



