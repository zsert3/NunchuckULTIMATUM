
#include "mainMenu.h"

void drawMenuScherm(MI0283QT9 lcd, int colour1, int colour2)
{
	lcd.fillScreen(colour2);
	lcd.fillRect(10, 0, 220, 320, colour1);
	lcd.fillRect(40, 70, 160, 40, colour2);
	lcd.fillRect(40, 150, 160, 40, colour2);
	lcd.fillRect(40, 230, 160, 40, colour2);
	lcd.drawText(65, 10, "AQUATIC", RGB(160, 82, 45), colour1, 2);
	lcd.drawText(75, 30, "VESSEL", RGB(160, 82, 45), colour1, 2);
	lcd.drawText(80, 87, "START GAME", RGB(160, 82, 45), colour2, 1);
	lcd.drawText(83, 167, "HIGHSCORE", RGB(160, 82, 45), colour2, 1);
	lcd.drawText(87, 248, "TUTORIAL", RGB(160, 82, 45), colour2, 1);
}

void touchScreen(MI0283QT9 lcd)
{
	if (lcd.touchRead())
	{
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();
		Serial.print("touchX: ");
		Serial.println(pushX);
		Serial.print("touchY: ");
		Serial.println(pushY);
		if (pushX >= 40 && pushX <= 200 && pushY >= 70 && pushY <= 110) {
			lcd.fillScreen(RGB(0, 0, 0));
		}
	}
}