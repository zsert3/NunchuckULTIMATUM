// 
// Gerard van Turennout
// 

#include "lives.h"

uint8_t lives = 1;
uint8_t blinkRed;

void checkLives() {
	switch (lives) {
	//case by case life settings
	case 1: PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2); break;
	case 2:	PORTC &= ~(1 << PORTC2); break;
	case 3: PORTC &= ~(1 << PORTC1); blinkLed(); break; //PORTC &= ~(1 << PORTC1); break;
	//case 4: resetLives();  break;
	}
}

void ledInit() {
	DDRC = 0b00000111;
}

void blinkLed() {
	PORTC ^= (1 << PORTC0);
}

void removeLive() {
	lives++;
}

void resetLives() {
	lives = 1;
	PORTC &= ~(7 << PORTC0);
}

void setLives(uint8_t live) {
	lives = live;
}

int getLives() {
	return lives;
}







