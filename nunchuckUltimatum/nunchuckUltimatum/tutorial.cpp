// 
// 
// 

#include "tutorial.h"

void basicscreenTutorial(MI0283QT9 lcd, int16_t watercolour, int16_t tekstcolour)  // The tutorial screens gets drawed here
{
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(60, 10, "TUTORIAL", tekstcolour, watercolour, 2);
	lcd.drawText(90, 40, "Welcome", tekstcolour, watercolour, 1);
	lcd.drawText(30, 55, "to aquatic vessel!", tekstcolour, watercolour, 1);
	lcd.drawText(30, 70, "Use the thumstick of", tekstcolour, watercolour, 1);
	lcd.drawText(30, 85, "the nunckuck to avoid", tekstcolour, watercolour, 1);
	lcd.drawText(30, 100, "incomming logs and", tekstcolour, watercolour, 1);
	lcd.drawText(30, 115, "the river banks.", tekstcolour, watercolour, 1);
	lcd.drawText(30, 130, "Press C to pause", tekstcolour, watercolour, 1);
	lcd.drawText(30, 145, "the game.", tekstcolour, watercolour, 1);
	lcd.drawText(30, 175, "Get that Highscore", tekstcolour, watercolour, 1);
	lcd.drawText(30, 190, "and goodluck!", tekstcolour, watercolour, 1);
	lcd.drawText(70, 220, "ENJOY!", tekstcolour, watercolour, 2);	
	drawboot(lcd, 110, 250);
}


