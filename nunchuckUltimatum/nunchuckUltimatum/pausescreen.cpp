// 
// 
// 

#include "pausescreen.h"
int pushedPauseScreen = 0;
int c_Button;
int gamePaused;
//uint8_t nunchuck_buf[6];

void pausescreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)
{
	nunchuckGetData();
	c_Button = nunchuckGetc_button();
	
	if ((c_Button >> 1) & 1)
	{
		c_Button = 1;
	}
	else
	{
		c_Button = 0;
	}

	Serial.println(c_Button);

	if (c_Button == 0)
	{
		drawpausescreen(lcd, watercolour, landcolour, tekstcolour);
		gamePaused = 1;


		while (gamePaused == 1)
		{
			if(gamePaused != 0)
			{

				touchScreenPauseMenu(lcd, watercolour, landcolour, tekstcolour);
				Serial.println("In while");

			}
		}
		
	}
	c_Button = 0;	
}

void drawpausescreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)
{
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(65, 10, "PAUSED", tekstcolour, watercolour, 2);
	lcd.fillRoundRect(40, 150, 160, 40, 10, landcolour);
	lcd.drawText(83, 167, "CONTINUE", tekstcolour, landcolour, 1);
	lcd.fillRoundRect(40, 230, 160, 40, 10, landcolour);
	lcd.drawText(87, 248, "MAIN MENU", tekstcolour, landcolour, 1);

}

void touchScreenPauseMenu(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)
{
	if (lcd.touchRead())
	{
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();
		//Serial.print("touchX: ");
		//Serial.println(pushX);
		//Serial.print("touchY: ");
		//Serial.println(pushY);
	

		if (pushX >= 40 && pushX <= 200 && pushY >= 150 && pushY <= 190 && pushedPauseScreen == 0)
			//CONTINUE Button
		{
			pushedPauseScreen = 1;
			Serial.println("CONTINUE");

			gamePaused = 0;
			lcd.fillRect(10, 0, 220, 320, watercolour);
			


			
	
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 230 && pushY <= 270 && pushedPauseScreen == 0)
			//MAIN  MENU button
		{
			pushedPauseScreen = 1;
			Serial.println("MainMenu");
			setGameStarted(0);
			Serial.println(getGameStarted());
			drawMenuScherm(lcd, watercolour, landcolour, tekstcolour);
			setpushed(0);
			gamePaused = 0;
			
			
			
		}
		
	}
}

void setPauseScreenPushed(int pausePushed)
{
	pushedPauseScreen = pausePushed;
}
