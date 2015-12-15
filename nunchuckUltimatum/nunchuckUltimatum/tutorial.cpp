// 
// 
// 

#include "tutorial.h"



void basisschermTutorial(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)  // The tutorial screens gets drawed here
{
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(60, 10, "TUTORIAL", tekstColour, watercolour, 2);
	lcd.drawText(90, 40, "Welcome", tekstColour, watercolour, 1);
	lcd.drawText(30, 55, "to aquatic vessel!", tekstColour, watercolour, 1);
	lcd.drawText(30, 70, "The goal is to avoid", tekstColour, watercolour, 1);
	lcd.drawText(30, 85, "the logs in the water", tekstColour, watercolour, 1);
	lcd.drawText(30, 100, "and get a HiScore,", tekstColour, watercolour, 1);
	lcd.drawText(30, 115, "also be weary of", tekstColour, watercolour, 1);
	lcd.drawText(30, 130, "the river banks.", tekstColour, watercolour, 1);
	lcd.drawText(30, 160, "Use the nunchuck", tekstColour, watercolour, 1);
	lcd.drawText(30, 175, "thumstick to move", tekstColour, watercolour, 1);
	lcd.drawText(30, 190, "your boat.", tekstColour, watercolour, 1);
	lcd.drawText(100, 220, "enjoy!", tekstColour, watercolour, 1);
	
	tekenboot(lcd, 110, 240);
	

	
}
