#include "gameover.h"
int GameOverPushed = 0;

//draw gameover screen
void basicschermGameOver(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)
{
	GameOverPushed = 0;
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(40, 30, "GAME OVER!", tekstcolour, watercolour, 2);
	lcd.drawText(80, 90, "SCORE:", tekstcolour, watercolour, 1);
	lcd.drawInteger(130, 90, getScore(), 10, tekstcolour, watercolour, 1);
	placeButton(lcd, landcolour, tekstcolour, "RETRY", getXwaardeButtons(), 140, 40, 160);
	placeButton(lcd, landcolour, tekstcolour, "MAIN MENU", getXwaardeButtons(), 210, 40, 160);
	do
	{
		touchScreenGameOver(lcd, watercolour, landcolour, tekstcolour);
	} while (!GameOverPushed);
}

void touchScreenGameOver(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)
{

	if (lcd.touchRead())
	{
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();
		//checked if there is a push between x 40 t/m 200 en y 140 t/m 180
		if (pushX >= getXwaardeButtons() && pushX <= 200 && pushY >= 140 && pushY <= 180 && GameOverPushed == 0)
		{
			placeButton(lcd, watercolour, tekstcolour, "RETRY", getXwaardeButtons(), 140, getWidthButtons(), 160);
			GameOverPushed = 1;
			resetObstaclespeed();
			setGameStarted(1);
			lcd.fillRect(10, 0, 220, 320, watercolour);
		}
		//checked if there is a push between x 40 t/m 200 en y 210 t/m 250
		if (pushX >= getXwaardeButtons() && pushX <= 200 && pushY >= 210 && pushY <= 250 && GameOverPushed == 0)
		{
			placeButton(lcd, watercolour, tekstcolour, "MAIN MENU", getXwaardeButtons(), 210, getWidthButtons(), 160);
			GameOverPushed = 1;
			drawMenuScreen(lcd, watercolour, landcolour, tekstcolour);
		}
	}
}