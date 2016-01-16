// lives.h

#ifndef _LIVES_h
#define _LIVES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
	#include "pauseScreen.h"
	void checkLives();
	void ledInit();
	void removeLive();
	void resetLives();
	void blinkLed();
	uint8_t getLives();
#endif



