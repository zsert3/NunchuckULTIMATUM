// highscores.h


#if defined(ARDUINO) && ARDUINO >= 100
//	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9.h>
//#include <avr\eeprom.h>
#include <avr/io.h>
#include <EEPROM.h>

void basisschermHighScores(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
void scoreCalculator(int ns);
