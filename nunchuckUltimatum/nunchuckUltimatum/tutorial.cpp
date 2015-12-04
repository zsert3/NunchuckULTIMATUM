// 
// 
// 

#include "tutorial.h"

void basisschermTutorial(MI0283QT9 lcd, int colour1, int colour2, int tekstColour)
{
	lcd.setOrientation(270);
	lcd.fillRect(10, 0, 220, 320, colour1);
	lcd.setOrientation(90);
	lcd.drawText(60, 10, "Tutorial", tekstColour, colour1, 2);
}
