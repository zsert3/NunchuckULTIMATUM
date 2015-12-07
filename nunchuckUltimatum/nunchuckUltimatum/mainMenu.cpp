
#include "mainMenu.h"
int pushed = 0;
int gameStarted = 0;



void drawMenuScherm(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(65, 10, "AQUATIC", tekstColour, watercolour, 2);
	lcd.drawText(75, 30, "VESSEL", tekstColour, watercolour, 2);
	lcd.fillRoundRect(40, 70, 160, 40, 10, landcolour);
	lcd.drawText(80, 87, "START GAME", tekstColour, landcolour, 1);
	lcd.fillRoundRect(40, 150, 160, 40, 10, landcolour);
	lcd.drawText(83, 167, "HIGHSCORE", tekstColour, landcolour, 1);
	lcd.fillRoundRect(40, 230, 160, 40, 10, landcolour);
	lcd.drawText(87, 248, "TUTORIAL", tekstColour, landcolour, 1);
}

void terugButton(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	lcd.fillRect(10, 290, 220, 30, landcolour);
	lcd.drawText(100, 300, "Terug", tekstColour, landcolour, 1);
}

void touchScreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	if (lcd.touchRead())
	{
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();
		//Serial.print("touchX: ");
		//Serial.println(pushX);
		//Serial.print("touchY: ");
		//Serial.println(pushY);
		if (pushX >= 40 && pushX <= 200 && pushY >= 70 && pushY <= 110 && pushed == 0) 
		{
			pushed = 1;
			lcd.fillRect(10, 0, 220, 320, watercolour);
			gameStarted = 1;
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 150 && pushY <= 190 && pushed == 0)
		{
			pushed = 1;
			lcd.fillRect(40, 150, 160, 40, watercolour);
			lcd.drawText(83, 167, "HIGHSCORE", tekstColour, watercolour, 1);
			basisschermHighScores(lcd, watercolour, landcolour, tekstColour);
			terugButton(lcd, watercolour, landcolour, tekstColour);
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 230 && pushY <= 270 && pushed == 0)
		{
			pushed = 1;
			lcd.fillRect(40, 230, 160, 40, watercolour);
			lcd.drawText(87, 248, "TUTORIAL", tekstColour, watercolour, 1);
			basisschermTutorial(lcd, watercolour, landcolour, tekstColour);
			terugButton(lcd, watercolour, landcolour, tekstColour);
		}
		if (pushX >= 40 && pushX <= 200 && pushY >= 290 && pushY <= 320 && pushed == 1)
		{
			lcd.fillRect(10, 290, 220, 30, watercolour);
			lcd.drawText(100, 300, "Terug", tekstColour, watercolour, 1);
			drawMenuScherm(lcd, watercolour, landcolour, tekstColour);
			pushed = 0;
		}
	}
}

int getPushed()
{
	return pushed;
}

int getGameStarted()
{
	return gameStarted;
}

void setGameStarted(int gameSTArted)
{
	gameStarted = gameSTArted;
}


