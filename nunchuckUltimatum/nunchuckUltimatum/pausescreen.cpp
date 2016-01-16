// 
// 
// 

#include "pauseScreen.h"
int8_t pushedPauseScreen = 0;
int8_t c_Button;
int8_t gamePaused;
int8_t release = 0;


void pauseScreen(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour)
{	
	c_Button = cbuttonPushed();
	if (c_Button == 0)
	{
		drawPauseScreen(lcd, waterColour, landColour, textColour);  
		gamePaused = 1;


		while (gamePaused == 1)  // Here we start a loop to check if the touchscreen get pushed
		{
			//if(gamePaused != 0)
			//{
				touchScreenPauseMenu(lcd, waterColour, landColour, textColour);
			//}
		}
		
	}
	c_Button = 0;	
}

void drawPauseScreen(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour)  // Here the pauseScreen gets drawed
{
	lcd.fillRect(10, 0, 220, 320, waterColour);
	lcd.drawText(75, 35, "PAUSED", textColour, waterColour, 2);
	lcd.drawText(60, 90, "HUIDIGE SCORE:", textColour, waterColour, 1);
	lcd.drawInteger(173, 90, getScore(), 10, textColour, waterColour, 1);
	placeButton(lcd, landColour, textColour, "CONTINUE", getXValueButtons(), 140, getWidthButtons(), 160);
	placeButton(lcd, landColour, textColour, "MAIN MENU", getXValueButtons(), 210, getWidthButtons(), 160);
}

void touchScreenPauseMenu(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour) // Here we check if the touchscreen is pushed
{
	c_Button = cbuttonPushed();
	// check if c_buttom button has been released
	if (c_Button == 1) {
		release = 1;
	}
	_delay_us(1500);
	// if c_button is pressed and has previously been released then it will continue the game and reset the values of the pauseScreen
	if (c_Button == 0 && release == 1)
	{
		release = 0;
		lcd.fillRect(10, 0, 220, 320, waterColour);
		setVisable();
		gamePaused = 0;
	}



	if (lcd.touchRead())
	{
		int16_t pushX = lcd.touchX();
		int16_t pushY = lcd.touchY();
		pushedPauseScreen = 0;

		if (pushX >= getXValueButtons() && pushX <= 200 && pushY >= 140 && pushY <= 180 && pushedPauseScreen == 0)
			//CONTINUE Button // Pushing this button continues the game
		{
			pushedPauseScreen = 1;
			placeButton(lcd, waterColour, textColour, "CONTINUE", getXValueButtons(), 140, getWidthButtons(), 160);
			setVisable();
			gamePaused = 0;
			release = 0;
			lcd.fillRect(10, 0, 220, 320, waterColour);	
		}

		if (pushX >= getXValueButtons() && pushX <= 200 && pushY >= 210 && pushY <= 250 && pushedPauseScreen == 0)
			//MAIN  MENU button  // pushing this button returns you to the main menu
		{
			pushedPauseScreen = 1;
			placeButton(lcd, waterColour, textColour, "MAIN MENU", getXValueButtons(), 210, getWidthButtons(), 160);
			scoreCalculator(getScore());
			setGameStarted(0);
			setPushed(0);
			resetLives();
			drawMenuScreen(lcd, waterColour, landColour, textColour);
			gamePaused = 0;
		}
	}
}

void setPauseScreenPushed(int8_t pausePushed)  //We have to set pausePused back to 0 if we want the touchscreen to work the next time we get to the paudescreen
{
	pushedPauseScreen = pausePushed;
}
