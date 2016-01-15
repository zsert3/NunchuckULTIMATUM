// highscores.h


#if defined(ARDUINO) && ARDUINO >= 100
//	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9.h>
#include <avr/io.h>
#include <EEPROM.h>
#include "eepromManager.h"

void basicscreenHighScores(MI0283QT9 lcd, int watercolour, int tekstColour);
void scoreCalculator(int ns);
