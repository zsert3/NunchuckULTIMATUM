// 
// 
// 

#include "highscores.h"



void basisschermHighScores(MI0283QT9 lcd, int colour1, int colour2, int tekstColour)
{
	lcd.fillRect(10, 0, 220, 320, colour1);
	lcd.drawText(40, 10, "HIGHSCORES", tekstColour, colour1, 2);
}

