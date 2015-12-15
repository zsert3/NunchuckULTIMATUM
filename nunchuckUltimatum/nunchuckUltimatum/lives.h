// lives.h

#ifndef _LIVES_h
#define _LIVES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
	#include "pausescreen.h"
	void check_lives();
	void ledInit();
	void remove_live();
	void reset_lives();
	void blink_led();
	int get_lives();
#endif



