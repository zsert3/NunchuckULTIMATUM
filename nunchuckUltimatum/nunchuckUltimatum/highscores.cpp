// 
// 
// 

#include "highscores.h"



void basisschermHighScores(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(40, 10, "HIGHSCORES", tekstColour, watercolour, 2);
}

