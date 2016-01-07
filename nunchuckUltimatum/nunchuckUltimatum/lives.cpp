// 
// 
// 

#include "lives.h"

uint8_t lives = 1;
uint8_t blinkRed;

void check_lives() {
	switch (lives) {
	case 1: PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2); break;
	case 2:	PORTC &= ~(1 << PORTC2); break;
	case 3: PORTC &= ~(1 << PORTC1); blink_led(); break; //PORTC &= ~(1 << PORTC1); break;
	//case 4: reset_lives();  break;
	}
}

void ledInit() {
	DDRC = 0b00000111;
}

void blink_led() {
	PORTC ^= (1 << PORTC0);
}

void remove_live() {
	lives++;
}

void reset_lives() {
	lives = 0;
	PORTC &= ~(7 << PORTC0);
}

void setlives(uint8_t live) {
	lives = live;
}

int get_lives() {
	return lives;
}







