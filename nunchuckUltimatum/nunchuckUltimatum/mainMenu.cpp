
#include "mainMenu.h"
int8_t pushed = 0;
int8_t gameStarted = 0;


//draws menuscreen
void drawMenuScreen(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour)
{
	pushed = 0;
	lcd.fillRect(10, 0, 220, 320, waterColour);
	lcd.drawText(65, 10, "AQUATIC", textColour, waterColour, 2);
	lcd.drawText(75, 30, "VESSEL", textColour, waterColour, 2);
	placeButton(lcd, landColour, textColour, "START GAME", getXValueButtons(), getButton1X(), getWidthButtons(), getButtonLength());
	placeButton(lcd, landColour, textColour, "HIGHSCORE", getXValueButtons(), getButton2X(), getWidthButtons(), getButtonLength());
	placeButton(lcd, landColour, textColour, "TUTORIAL", getXValueButtons(), getButton3X(), getWidthButtons(), getButtonLength());
	placeButton(lcd, landColour, textColour, "SETTINGS", getXValueButtons(), getButton4X(), getWidthButtons(), getButtonLength());
}

void touchScreen(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour)
{
	// checkt if the touchpanel is touched
	if (lcd.touchRead())
	{
		//the values that the touchpanel submits is set here in a variable
		int16_t pushX = lcd.touchX();
		int16_t pushY = lcd.touchY();
		setPauseScreenPushed(0);

		//the pushed variable is a value which is used to check if a button is pressed or not
		//start game button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 and y 60 t/m 100
		if (pushX >= getXValueButtons() && pushX <= getXValueButtons() + getButtonLength() && pushY >= getButton1X() && pushY <= getButton1X() + getWidthButtons() && pushed == 0)
		{
			pushed = 1;
			placeButton(lcd, waterColour, textColour, "START GAME", getXValueButtons(), 60, getWidthButtons(), getButtonLength());
			gameStarted = 1;
		}
		//hightscore button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 and y 125 t/m 165
		if (pushX >= getXValueButtons() && pushX <= getXValueButtons() + getButtonLength() && pushY >= getButton2X() && pushY <= getButton2X() + getWidthButtons() && pushed == 0)
		{
			pushed = 1;
			placeButton(lcd, waterColour, textColour, "HIGHSCORE", getXValueButtons(), 125, getWidthButtons(), getButtonLength());
			basicscreenHighScores(lcd, waterColour, textColour);
			placeButton(lcd, landColour, textColour, "BACK", 0, 290, 30, 240);
		}
		//tutorial button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 and y 190 t/m 230
		if (pushX >= getXValueButtons() && pushX <= getXValueButtons() + getButtonLength() && pushY >= getButton3X() && pushY <= getButton3X() + getWidthButtons() && pushed == 0)
		{
			pushed = 1;
			placeButton(lcd, waterColour, textColour, "TUTORIAL", getXValueButtons(), 190, getWidthButtons(), getButtonLength());
			basicscreenTutorial(lcd, waterColour, textColour);
			placeButton(lcd, landColour, textColour, "BACK", 0, 290, 30, 240);
		}
		//settings button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 and y 255 t/m 292
		if (pushX >= getXValueButtons() && pushX <= getXValueButtons() + getButtonLength() && pushY >= getButton4X() && pushY <= getButton4X() + getWidthButtons() - 3 && pushed == 0)
		{
			pushed = 1;
			placeButton(lcd, waterColour, textColour, "SETTINGS", getXValueButtons(), 255, getWidthButtons(), getButtonLength());
			basicScreenSettings(lcd, waterColour, landColour, textColour);
		}
		//if variable pushed is 1 only then is the back button available
		//back button, checkt if the touchpanel is touched at the coordinates x 40 t/m 200 and y 293 t/m 320
		if (pushX >= 10 && pushX <= 230 && pushY >= 293 && pushY <= 320 && pushed == 1)//??? check deze regel nog een keer op fouten
		{
			lcd.fillRect(10, 290, 220, 30, waterColour);
			lcd.drawText(100, 300, "BACK", textColour, waterColour, 1);
			drawMenuScreen(lcd, waterColour, landColour, textColour);
		}
	}
}

int8_t getGameStarted()
{
	return gameStarted;
}

void setGameStarted(int8_t gameStarted1)
{
	gameStarted = gameStarted1;
}

void setPushed(int8_t Pushed)
{
	pushed = Pushed;
}

