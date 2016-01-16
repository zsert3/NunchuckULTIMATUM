
#include "lives.h"

uint8_t lives = 1;
uint8_t blinkRed;

void checkLives() {
	switch (lives) {
	case 1: PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2); break; //every led is on
	case 2:	PORTC &= ~(1 << PORTC2); break; //yellow and green led turned on
	case 3: PORTC &= ~(1 << PORTC1); blinkLed(); break; //red led is flashing
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

int8_t getLives() {
	return lives;
}







