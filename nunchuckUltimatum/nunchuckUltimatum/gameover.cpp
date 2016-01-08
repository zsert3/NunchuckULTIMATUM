// 
// 
// 
//author: Nieck Eikelenoom
#include "gameover.h"
int GameOverPushed = 0;


void basisschermGameOver(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)
{
	GameOverPushed = 0;
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(40, 30, "GAME OVER!", tekstcolour, watercolour, 2);
	lcd.drawText(80, 90, "SCORE:", tekstcolour, watercolour, 1);
	lcd.drawInteger(130, 90, getScore(), 10, tekstcolour, watercolour, 1);
	lcd.fillRoundRect(40, 140, 160, 40, 10, landcolour);
	lcd.drawText(103, 157, "RETRY", tekstcolour, landcolour, 1);
	lcd.fillRoundRect(40, 210, 160, 40, 10, landcolour);
	lcd.drawText(87, 228, "MAIN MENU", tekstcolour, landcolour, 1);
	do
	{
		touchScreenGameOver(lcd, watercolour, landcolour, tekstcolour);
	} while (!GameOverPushed);
	Serial.println("uit doloop");
}

void touchScreenGameOver(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)
{
	if (lcd.touchRead())
	{
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();

		if (pushX >= 40 && pushX <= 200 && pushY >= 140 && pushY <= 180 && GameOverPushed == 0)
		{
			lcd.fillRoundRect(40, 140, 160, 40,10, watercolour);
			lcd.drawText(103, 157, "RETRY", tekstcolour, watercolour, 1);
			GameOverPushed = 1;
			setlives(1);
			set_obstaclespeed(1);
			setGameStarted(1);
			lcd.fillRect(10, 0, 220, 320, watercolour);
			Serial.println("touchGO");
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 210 && pushY <= 250 && GameOverPushed == 0)
		{
			lcd.fillRoundRect(40, 210, 160, 40, 10, watercolour);
			lcd.drawText(87, 228, "MAIN MENU", tekstcolour, watercolour, 1);
			GameOverPushed = 1;
			drawMenuScherm(lcd, watercolour, landcolour, tekstcolour);
		}
	}
}