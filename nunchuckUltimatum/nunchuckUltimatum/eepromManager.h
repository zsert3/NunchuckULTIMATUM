// eepromManager.h
//Gerard van Turennout

#ifndef _EEPROMMANAGER_h
#define _EEPROMMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

#include <EEPROM.h>

void getScore(int score[5]);
void setScore(int score[5]);
void resetScore();
int getBrightnes();
int getMaxbrightnes();
void setBrightnes(int brightnes);