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
#include <MI0283QT9\MI0283QT9.h>
#include <EEPROM.h>

void getScore(int score[5]);
void setScore(int score[5]);
void setBrightnes(int brightnes, MI0283QT9 lcd);
void resetHighscore();
int getBrightnes();
int getMaxbrightnes();