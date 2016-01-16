#include "gameover.h"
int8_t GameOverPushed = 0;

//draw gameover screen
void basicschermGameOver(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour)
{
	GameOverPushed = 0;
	lcd.fillRect(10, 0, 220, 320, waterColour);
	lcd.drawText(40, 30, "GAME OVER!", textColour, waterColour, 2);
	lcd.drawText(80, 90, "SCORE:", textColour, waterColour, 1);
	lcd.drawInteger(130, 90, getScore(), 10, textColour, waterColour, 1);
	placeButton(lcd, landColour, textColour, "RETRY", getXValueButtons(), 140, 40, 160);
	placeButton(lcd, landColour, textColour, "MAIN MENU", getXValueButtons(), 210, 40, 160);
	do
	{
		touchScreenGameOver(lcd, waterColour, landColour, textColour);
	} while (!GameOverPushed);
}

void touchScreenGameOver(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour)
{

	if (lcd.touchRead())
	{
		int16_t pushX = lcd.touchX();
		int16_t pushY = lcd.touchY();
		//checked if there is a push between x 40 t/m 200 and y 140 t/m 180
		if (pushX >= getXValueButtons() && pushX <= 200 && pushY >= 140 && pushY <= 180 && GameOverPushed == 0)
		{
			placeButton(lcd, waterColour, textColour, "RETRY", getXValueButtons(), 140, getWidthButtons(), 160);
			GameOverPushed = 1;
			resetObstaclespeed();
			setGameStarted(1);
			lcd.fillRect(10, 0, 220, 320, waterColour);
		}
		//checked if there is a push between x 40 t/m 200 and y 210 t/m 250
		if (pushX >= getXValueButtons() && pushX <= 200 && pushY >= 210 && pushY <= 250 && GameOverPushed == 0)
		{
			placeButton(lcd, waterColour, textColour, "MAIN MENU", getXValueButtons(), 210, getWidthButtons(), 160);
			GameOverPushed = 1;
			drawMenuScreen(lcd, waterColour, landColour, textColour);
		}
	}
}