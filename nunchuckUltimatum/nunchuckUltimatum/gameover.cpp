// 
// 
// 

#include "gameover.h"


void basisschermGameOver(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)
{
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(60, 10, "GAME OVER!", tekstcolour, watercolour, 2);

	lcd.fillRoundRect(40, 130, 160, 40, 10, landcolour);
	lcd.drawText(83, 147, "CONTINUE", tekstcolour, landcolour, 1);
	lcd.fillRoundRect(40, 210, 160, 40, 10, landcolour);
	lcd.drawText(87, 228, "MAIN MENU", tekstcolour, landcolour, 1);

}
