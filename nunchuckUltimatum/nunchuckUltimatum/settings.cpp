// 
// 
// 

#include "settings.h"


void basisschermSettings(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(60, 10, "SETTINGS", tekstColour, watercolour, 2);

}