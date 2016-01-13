// 
// 
// 

#include "pausescreen.h"
int pushedPauseScreen = 0;
int c_Button;
int gamePaused;
int release = 0;


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
	lcd.drawText(60, 90, "HUIDIGE SCORE:", tekstcolour, watercolour, 1);
	lcd.drawInteger(173, 90, getScore(), 10, tekstcolour, watercolour, 1);
	placeButton(lcd, landcolour, tekstcolour, "CONTINUE", getXwaardeButtons(), 140, getWidthButtons(), 160);
	placeButton(lcd, landcolour, tekstcolour, "MAIN MENU", getXwaardeButtons(), 210, getWidthButtons(), 160);
}

void touchScreenPauseMenu(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour) // Here we check if the touchscreen is pushed
{
	cbuttonPushed(lcd, watercolour, landcolour, tekstcolour);
	// check if c_buttom button has been released
	if (c_Button == 1) {
		release = 1;
	}
	_delay_us(100);
	// if c_button is pressed and has previously been released then it will continue the game and reset the values of the pausescreen
	if (c_Button == 0 && release == 1)
	{
		release = 0;
		lcd.fillRect(10, 0, 220, 320, watercolour);
		setVisable();
		gamePaused = 0;
	}



	if (lcd.touchRead())
	{
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();
		pushedPauseScreen = 0;

		if (pushX >= getXwaardeButtons() && pushX <= 200 && pushY >= 140 && pushY <= 180 && pushedPauseScreen == 0)
			//CONTINUE Button // Pushing this button continues the game
		{
			pushedPauseScreen = 1;
			placeButton(lcd, watercolour, tekstcolour, "CONTINUE", getXwaardeButtons(), 140, getWidthButtons(), 160);
			setVisable();
			gamePaused = 0;
			lcd.fillRect(10, 0, 220, 320, watercolour);	
		}

		if (pushX >= getXwaardeButtons() && pushX <= 200 && pushY >= 210 && pushY <= 250 && pushedPauseScreen == 0)
			//MAIN  MENU button  // pushing this button returns you to the main menu
		{
			pushedPauseScreen = 1;
			placeButton(lcd, watercolour, tekstcolour, "MAIN MENU", getXwaardeButtons(), 210, getWidthButtons(), 160);
			scoreCalculator(getScore());
			resetScore();
			resetLives();
			setGameStarted(0);
			setpushed(0);
			drawMenuScreen(lcd, watercolour, landcolour, tekstcolour);
			gamePaused = 0;
		}
	}
}

void cbuttonPushed(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour)
{
	nunchuckGetData();  // Reviving the state of the C Button of the nunchuck
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
