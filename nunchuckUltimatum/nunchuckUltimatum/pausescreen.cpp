// 
// 
// 

#include "pausescreen.h"
int pushedPauseScreen = 0;
int c_Button;
int gamePaused;

void pausescreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)
{	
	cbuttonPushed(lcd, watercolour, landcolour, tekstcolour);

	if (c_Button == 0)
	{
		drawpausescreen(lcd, watercolour, landcolour, tekstcolour);  
		gamePaused = 1;


		while (gamePaused == 1)  // Here we start a loop to check if the touchscreen get pushed
		{
			if(gamePaused != 0)
			{
				touchScreenPauseMenu(lcd, watercolour, landcolour, tekstcolour);
			}
		}
		
	}
	c_Button = 0;	
}

void drawpausescreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)  // Here the pausescreen gets drawed
{
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(75, 35, "PAUSED", tekstcolour, watercolour, 2);
	lcd.fillRoundRect(40, 75, 160, 40, 10, landcolour);
	lcd.drawText(60, 90, "HUIDIGE SCORE:", tekstcolour, landcolour, 1);
	lcd.drawInteger(173, 90, getScore(), 10, tekstcolour, landcolour, 1);
	lcd.fillRoundRect(40, 140, 160, 40, 10, landcolour);
	lcd.drawText(83, 157, "CONTINUE", tekstcolour, landcolour, 1);
	lcd.fillRoundRect(40, 210, 160, 40, 10, landcolour);
	lcd.drawText(87, 228, "MAIN MENU", tekstcolour, landcolour, 1);

}

void touchScreenPauseMenu(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour) // Here we check if the touchscreen is pushed
{
	cbuttonPushed(lcd, watercolour, landcolour, tekstcolour);
	Serial.println("Button");
	if (c_Button == 0)
	{
		cbuttonPushed(lcd, watercolour, landcolour, tekstcolour);
		lcd.fillRect(10, 0, 220, 320, watercolour);
		set_visable();
		gamePaused = 0;
		/*if (c_Button == 1)
		{
			lcd.fillRect(10, 0, 220, 320, watercolour);
			gamePaused = 0;
		}*/
	}

	if (lcd.touchRead())
	{
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();
		pushedPauseScreen = 0;
		//Serial.print("touchX: ");
		//Serial.println(pushX);
		//Serial.print("touchY: ");
		//Serial.println(pushY);

		if (pushX >= 40 && pushX <= 200 && pushY >= 140 && pushY <= 180 && pushedPauseScreen == 0)
			//CONTINUE Button // Pushing this button continues the game
		{
			pushedPauseScreen = 1;
			lcd.fillRect(40, 140, 160, 40, watercolour);
			lcd.drawText(83, 157, "CONTINUE", tekstcolour, watercolour, 1);
			set_visable();
			gamePaused = 0;
			lcd.fillRect(10, 0, 220, 320, watercolour);	
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 210 && pushY <= 250 && pushedPauseScreen == 0)
			//MAIN  MENU button  // pushing this button returns you to the main menu
		{
			pushedPauseScreen = 1;
			lcd.fillRect(40, 210, 160, 40, watercolour);
			lcd.drawText(87, 228, "MAIN MENU", tekstcolour, watercolour, 1);
			scoreCalculator(getScore());
			setScore(0);
			reset_lives();
			setGameStarted(0);
			setpushed(0);
			drawMenuScherm(lcd, watercolour, landcolour, tekstcolour);
			gamePaused = 0;
		}
	}
}

void cbuttonPushed(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)
{
	nunchuckGetData();  // Revriving the state of the C Button of the nunchuck
	c_Button = nunchuckGetc_button();

	if ((c_Button >> 1) & 1)  // determing the state of the C button
	{
		c_Button = 1;
	}
	else
	{
		c_Button = 0;
	}
}

void setPauseScreenPushed(int pausePushed)  //We have to set pausePused back to 0 if we want the touchscreen to work the next time we get to the paudescreen
{
	pushedPauseScreen = pausePushed;
}
