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
void resetScore();
int getBrightnes();
int getMaxbrightnes();
void setBrightnes(int brightnes);
void writeCalData(MI0283QT9 lcd);
uint8_t readCalData(MI0283QT9 lcd);