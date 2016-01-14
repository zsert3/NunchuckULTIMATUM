// 
// 
// 

#include "tutorial.h"

void basicscreenTutorial(MI0283QT9 lcd, int watercolour, int tekstColour)  // The tutorial screens gets drawed here
{
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(60, 10, "TUTORIAL", tekstColour, watercolour, 2);
	lcd.drawText(90, 40, "Welcome", tekstColour, watercolour, 1);
	lcd.drawText(30, 55, "to aquatic vessel!", tekstColour, watercolour, 1);
	lcd.drawText(30, 70, "Use the thumstick of", tekstColour, watercolour, 1);
	lcd.drawText(30, 85, "the nunckuck to avoid", tekstColour, watercolour, 1);
	lcd.drawText(30, 100, "incomming logs and", tekstColour, watercolour, 1);
	lcd.drawText(30, 115, "the river banks.", tekstColour, watercolour, 1);
	lcd.drawText(30, 130, "Press C to pause", tekstColour, watercolour, 1);
	lcd.drawText(30, 145, "the game.", tekstColour, watercolour, 1);
	lcd.drawText(30, 175, "Get that Highscore", tekstColour, watercolour, 1);
	lcd.drawText(30, 190, "and goodluck!", tekstColour, watercolour, 1);
	lcd.drawText(70, 220, "ENJOY!", tekstColour, watercolour, 2);	
	drawboot(lcd, 110, 250);
}


