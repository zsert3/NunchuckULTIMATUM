// lives.h

#ifndef _LIVES_h
#define _LIVES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
	#include "pausescreen.h"
	void checkLives();
	void ledInit();
	void removeLive();
	void resetLives();
	void blinkLed();
	int getLives();
	void setLives(uint8_t live);
#endif



