
#include "mainMenu.h"
int pushed = 0;
int gameStarted = 0;
int pushX = 0;
int pushY = 0;


//draws menuscreen
void drawMenuScreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	pushed = 0;
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

void backButton(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	lcd.fillRect(10, 290, 220, 30, landcolour);
	lcd.drawText(100, 300, "BACK", tekstColour, landcolour, 1);

}

void touchScreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	// checkt if the touchpanel is touched
	if (lcd.touchRead())
	{
		//the values that the touchpanel submits is set here in a variable
		pushX = lcd.touchX();
		pushY = lcd.touchY();
		setPauseScreenPushed(0);

		//the pushed variable is a value which is used to check if a button is pressed or not
		//start game button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 en y 60 t/m 100
		if (pushX >= 40 && pushX <= 200 && pushY >= 60 && pushY <= 100 && pushed == 0) 
		{
			pushed = 1;
			lcd.fillRoundRect(40, 60, 160, 40, 10, watercolour);
			lcd.drawText(80, 77, "START GAME", tekstColour, watercolour, 1);
			gameStarted = 1;
		}
		//hightscore button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 en y 125 t/m 165
		if (pushX >= 40 && pushX <= 200 && pushY >= 125 && pushY <= 165 && pushed == 0)
		{
			pushed = 1;
			lcd.fillRoundRect(40, 125, 160, 40, 10, watercolour);
			lcd.drawText(83, 143, "HIGHSCORE", tekstColour, watercolour, 1);
			basicscreenHighScores(lcd, watercolour, landcolour, tekstColour);
			backButton(lcd, watercolour, landcolour, tekstColour);
		}
		//tutorial button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 en y 190 t/m 230
		if (pushX >= 40 && pushX <= 200 && pushY >= 190 && pushY <= 230 && pushed == 0)
		{
			pushed = 1;
			lcd.fillRoundRect(40, 190, 160, 40, 10, watercolour);
			lcd.drawText(87, 205, "TUTORIAL", tekstColour, watercolour, 1);
			basicscreenSettings(lcd, watercolour, landcolour, tekstColour);
			backButton(lcd, watercolour, landcolour, tekstColour);
		}
		//settings button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 en y 255 t/m 292
		if (pushX >= 40 && pushX <= 200 && pushY >= 255 && pushY <= 292 && pushed == 0)
		{
			pushed = 1;
			lcd.fillRoundRect(40, 255, 160, 40, 10, watercolour);
			lcd.drawText(87, 273, "SETTINGS", tekstColour, watercolour, 1);
			basicscreenSettings(lcd, watercolour, landcolour, tekstColour);
		}
		//if variable pushed is 1 only then is the back button available
		//back button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 en y 293 t/m 320
		if (pushX >= 40 && pushX <= 200 && pushY >= 293 && pushY <= 320 && pushed == 1)
		{
			lcd.fillRect(10, 290, 220, 30, watercolour);
			lcd.drawText(100, 300, "BACK", tekstColour, watercolour, 1);
			drawMenuScreen(lcd, watercolour, landcolour, tekstColour);
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

