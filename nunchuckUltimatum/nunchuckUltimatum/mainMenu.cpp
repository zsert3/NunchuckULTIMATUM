
#include "mainMenu.h"
int pushed = 0;
int gameStarted = 0;



void drawMenuScherm(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(65, 10, "AQUATIC", tekstColour, watercolour, 2);
	lcd.drawText(75, 30, "VESSEL", tekstColour, watercolour, 2);
	lcd.fillRoundRect(40, 60, 160, 40, 10, landcolour);
	lcd.drawText(80, 77, "START GAME", tekstColour, landcolour, 1);
	lcd.fillRoundRect(40, 125, 160, 40, 10, landcolour);
	lcd.drawText(83, 143, "HIGHSCORE", tekstColour, landcolour, 1);
	lcd.fillRoundRect(40, 190, 160, 40, 10, landcolour);
	lcd.drawText(87, 205, "TUTORIAL", tekstColour, landcolour, 1);
	lcd.fillRoundRect(40, 255, 160, 40, 10, landcolour);
	lcd.drawText(88, 273, "SETTINGS", tekstColour, landcolour, 1);
}

void terugButton(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	lcd.fillRect(10, 290, 220, 30, landcolour);
	lcd.drawText(100, 300, "BACK", tekstColour, landcolour, 1);

}

void touchScreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	if (lcd.touchRead())
	{
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();
		setPauseScreenPushed(0);
		//Serial.print("touchX: ");
		//Serial.println(pushX);
		//Serial.print("touchY: ");
		//Serial.println(pushY);
		
		if (pushX >= 40 && pushX <= 200 && pushY >= 60 && pushY <= 100 && pushed == 0) 
		{
			pushed = 1;
			lcd.fillRoundRect(40, 60, 160, 40, 10, watercolour);
			lcd.drawText(80, 77, "START GAME", tekstColour, watercolour, 1);
			//lcd.fillRect(10, 0, 220, 320, watercolour);
			gameStarted = 1;
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 125 && pushY <= 165 && pushed == 0)
		{
			pushed = 1;
			lcd.fillRoundRect(40, 125, 160, 40, 10, watercolour);
			lcd.drawText(83, 143, "HIGHSCORE", tekstColour, watercolour, 1);
			basisschermHighScores(lcd, watercolour, landcolour, tekstColour);
			terugButton(lcd, watercolour, landcolour, tekstColour);
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 190 && pushY <= 230 && pushed == 0)
		{
			pushed = 1;
			lcd.fillRoundRect(40, 190, 160, 40, 10, watercolour);
			lcd.drawText(87, 205, "TUTORIAL", tekstColour, watercolour, 1);
			basisschermTutorial(lcd, watercolour, landcolour, tekstColour);
			terugButton(lcd, watercolour, landcolour, tekstColour);
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 255 && pushY <= 295 && pushed == 0)
		{
			pushed = 1;
			lcd.fillRoundRect(40, 255, 160, 40, 10, watercolour);
			lcd.drawText(87, 273, "SETTINGS", tekstColour, watercolour, 1);
			basisschermSettings(lcd, watercolour, landcolour, tekstColour);
			terugButton(lcd, watercolour, landcolour, tekstColour);
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 290 && pushY <= 320 && pushed == 1)
		{
			lcd.fillRect(10, 290, 220, 30, watercolour);
			lcd.drawText(100, 300, "BACK", tekstColour, watercolour, 1);
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

void setpushed(int Pushed)
{
	pushed = Pushed;
}

