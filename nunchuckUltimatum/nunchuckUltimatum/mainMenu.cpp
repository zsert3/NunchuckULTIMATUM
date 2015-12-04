
#include "mainMenu.h"
int pushed = 0;



void drawMenuScherm(MI0283QT9 lcd, int colour1, int colour2, int tekstColour)
{
	lcd.fillScreen(colour2);
	lcd.fillRect(10, 0, 220, 320, colour1);
	lcd.fillRect(40, 70, 160, 40, colour2);
	lcd.fillRect(40, 150, 160, 40, colour2);
	lcd.fillRect(40, 230, 160, 40, colour2);
	lcd.drawText(65, 10, "AQUATIC", tekstColour, colour1, 2);
	lcd.drawText(75, 30, "VESSEL", tekstColour, colour1, 2);
	lcd.drawText(80, 87, "START GAME", tekstColour, colour2, 1);
	lcd.drawText(83, 167, "HIGHSCORE", tekstColour, colour2, 1);
	lcd.drawText(87, 248, "TUTORIAL", tekstColour, colour2, 1);
}

void terugButton(MI0283QT9 lcd, int colour1, int colour2, int tekstColour)
{
	lcd.fillRect(10, 290, 220, 30, colour2);
	lcd.drawText(100, 300, "Terug", tekstColour, colour2, 1);
}

void touchScreen(MI0283QT9 lcd, int colour1, int colour2, int tekstColour)
{
	if (lcd.touchRead())
	{
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();
		Serial.print("touchX: ");
		Serial.println(pushX);
		Serial.print("touchY: ");
		Serial.println(pushY);
		if (pushX >= 40 && pushX <= 200 && pushY >= 70 && pushY <= 110 && pushed == 0) 
		{
			pushed = 1;
			lcd.setOrientation(270);
			lcd.fillRect(10, 0, 220, 320, RGB(123, 104, 238));
			lcd.setOrientation(90);
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 150 && pushY <= 190 && pushed == 0)
		{
			pushed = 1;
			basisschermHighScores(lcd, colour1, colour2, tekstColour);
			terugButton(lcd, colour1, colour2, tekstColour);
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 230 && pushY <= 270 && pushed == 0)
		{
			pushed = 1;
			basisschermTutorial(lcd, colour1, colour2, tekstColour);
			terugButton(lcd, colour1, colour2, tekstColour);
		}
		if (pushX >= 40 && pushX <= 200 && pushY >= 290 && pushY <= 320 && pushed == 1)
		{
			drawMenuScherm(lcd, colour1, colour2, tekstColour);
			pushed = 0;
		}
	}
}

int getPushed()
{
	return pushed;
}


