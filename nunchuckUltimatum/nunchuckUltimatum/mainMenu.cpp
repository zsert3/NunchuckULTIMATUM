
#include "mainMenu.h"

void drawMenuScherm(MI0283QT9 lcd)
{
	lcd.begin();
	lcd.setOrientation(90);
	lcd.fillScreen(RGB(127, 255, 0));
	lcd.fillRect(10, 0, 220, 320, RGB(0, 0, 128));
	lcd.fillRect(40, 70, 160, 40, RGB(127, 255, 0));
	lcd.fillRect(40, 150, 160, 40, RGB(127, 255, 0));
	lcd.fillRect(40, 230, 160, 40, RGB(127, 255, 0));
	lcd.drawText(65, 20, "AQUATIC VESSEL", RGB(160, 82, 45), RGB(0, 0, 128), 1);
	lcd.drawText(80, 87, "START GAME", RGB(160, 82, 45), RGB(127, 255, 0), 1);
	lcd.drawText(83, 167, "HIGHSCORE", RGB(160, 82, 45), RGB(127, 255, 0), 1);
	lcd.drawText(87, 248, "TUTORIAL", RGB(160, 82, 45), RGB(127, 255, 0), 1);
}

void touchScreen(MI0283QT9 lcd)
{
	lcd.touchStartCal();
	if (lcd.touchRead())
	{
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();
		/*Serial.print("touchX: ");
		Serial.println(pushX);
		Serial.print("touchY: ");
		Serial.println(pushY);*/
		if (pushX >= 40 && pushX <= 200 && pushY >= 70 && pushY <= 110) {
			lcd.fillScreen(RGB(0, 0, 0));
		}
	}
}