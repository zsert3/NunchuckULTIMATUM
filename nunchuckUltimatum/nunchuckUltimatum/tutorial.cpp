// 
// 
// 

#include "tutorial.h"

void basicscreenTutorial(MI0283QT9 lcd, int16_t waterColour, int16_t textColour)  // The tutorial screens gets drawed here
{
	lcd.fillRect(10, 0, 220, 320, waterColour);
	lcd.drawText(60, 10, "TUTORIAL", textColour, waterColour, 2);
	lcd.drawText(90, 40, "Welcome", textColour, waterColour, 1);
	lcd.drawText(30, 55, "to aquatic vessel!", textColour, waterColour, 1);
	lcd.drawText(30, 70, "Use the thumstick of", textColour, waterColour, 1);
	lcd.drawText(30, 85, "the nunckuck to avoid", textColour, waterColour, 1);
	lcd.drawText(30, 100, "incomming logs and", textColour, waterColour, 1);
	lcd.drawText(30, 115, "the river banks.", textColour, waterColour, 1);
	lcd.drawText(30, 130, "Press C to pause", textColour, waterColour, 1);
	lcd.drawText(30, 145, "the game.", textColour, waterColour, 1);
	lcd.drawText(30, 175, "Get that Highscore", textColour, waterColour, 1);
	lcd.drawText(30, 190, "and goodluck!", textColour, waterColour, 1);
	lcd.drawText(70, 220, "ENJOY!", textColour, waterColour, 2);	
	drawBoat(lcd, 110, 250);
}


