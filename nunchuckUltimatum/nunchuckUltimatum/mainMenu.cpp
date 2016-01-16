
#include "mainMenu.h"
int8_t pushed = 0;
int8_t gameStarted = 0;


//draws menuscreen
void drawMenuScreen(MI0283QT9 lcd, int16_t watercolour, int16_t landcolour, int16_t tekstcolour)
{
	pushed = 0;
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(65, 10, "AQUATIC", tekstcolour, watercolour, 2);
	lcd.drawText(75, 30, "VESSEL", tekstcolour, watercolour, 2);
	placeButton(lcd, landcolour, tekstcolour, "START GAME", getXwaardeButtons(), getButton1X(), getWidthButtons(), getButtonLength());
	placeButton(lcd, landcolour, tekstcolour, "HIGHSCORE", getXwaardeButtons(), getButton2X(), getWidthButtons(), getButtonLength());
	placeButton(lcd, landcolour, tekstcolour, "TUTORIAL", getXwaardeButtons(), getButton3X(), getWidthButtons(), getButtonLength());
	placeButton(lcd, landcolour, tekstcolour, "SETTINGS", getXwaardeButtons(), getButton4X(), getWidthButtons(), getButtonLength());
}

void touchScreen(MI0283QT9 lcd, int16_t watercolour, int16_t landcolour, int16_t tekstcolour)
{
	// checkt if the touchpanel is touched
	if (lcd.touchRead())
	{
		//the values that the touchpanel submits is set here in a variable
		int16_t pushX = lcd.touchX();
		int16_t pushY = lcd.touchY();
		setPauseScreenPushed(0);

		//the pushed variable is a value which is used to check if a button is pressed or not
		//start game button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 en y 60 t/m 100
		if (pushX >= getXwaardeButtons() && pushX <= getXwaardeButtons() + getButtonLength() && pushY >= getButton1X() && pushY <= getButton1X() + getWidthButtons() && pushed == 0)
		{
			pushed = 1;
			placeButton(lcd, watercolour, tekstcolour, "START GAME", getXwaardeButtons(), 60, getWidthButtons(), getButtonLength());
			gameStarted = 1;
		}
		//hightscore button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 en y 125 t/m 165
		if (pushX >= getXwaardeButtons() && pushX <= getXwaardeButtons() + getButtonLength() && pushY >= getButton2X() && pushY <= getButton2X() + getWidthButtons() && pushed == 0)
		{
			pushed = 1;
			placeButton(lcd, watercolour, tekstcolour, "HIGHSCORE", getXwaardeButtons(), 125, getWidthButtons(), getButtonLength());
			basicscreenHighScores(lcd, watercolour, tekstcolour);
			placeButton(lcd, landcolour, tekstcolour, "BACK", 0, 290, 30, 240);
		}
		//tutorial button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 en y 190 t/m 230
		if (pushX >= getXwaardeButtons() && pushX <= getXwaardeButtons() + getButtonLength() && pushY >= getButton3X() && pushY <= getButton3X() + getWidthButtons() && pushed == 0)
		{
			pushed = 1;
			placeButton(lcd, watercolour, tekstcolour, "TUTORIAL", getXwaardeButtons(), 190, getWidthButtons(), getButtonLength());
			basicscreenTutorial(lcd, watercolour, tekstcolour);
			placeButton(lcd, landcolour, tekstcolour, "BACK", 0, 290, 30, 240);
		}
		//settings button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 en y 255 t/m 292
		if (pushX >= getXwaardeButtons() && pushX <= getXwaardeButtons() + getButtonLength() && pushY >= getButton4X() && pushY <= getButton4X() + getWidthButtons() - 3 && pushed == 0)
		{
			pushed = 1;
			placeButton(lcd, watercolour, tekstcolour, "SETTINGS", getXwaardeButtons(), 255, getWidthButtons(), getButtonLength());
			basicscreenSettings(lcd, watercolour, landcolour, tekstcolour);
		}
		//if variable pushed is 1 only then is the back button available
		//back button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 en y 293 t/m 320
		if (pushX >= 10 && pushX <= 230 && pushY >= 293 && pushY <= 320 && pushed == 1)//??? check deze regel nog een keer op fouten
		{
			lcd.fillRect(10, 290, 220, 30, watercolour);
			lcd.drawText(100, 300, "BACK", tekstcolour, watercolour, 1);
			drawMenuScreen(lcd, watercolour, landcolour, tekstcolour);
		}
	}
}

int8_t getGameStarted()
{
	return gameStarted;
}

void setGameStarted(int8_t gameStarted)
{
	gameStarted = gameStarted;
}

void setpushed(int8_t Pushed)
{
	pushed = Pushed;
}

