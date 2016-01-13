// 
// 
// 

#include "button.h"
int arrSize = 0;
int widthButtons = 40;
int XwaardeButtons = 40;
int buttonLength = 160;
int button1X = 60;
int button2X = 125;
int button3X = 190;
int button4X = 255;

void placeButton(MI0283QT9 lcd, int backgroundcolour, int tekstcolour, char *text, int lcX, int lcY, int buttonsizeY, int buttonsizeX) {
	arrSize = strlen(text);
	//toegevoegt als eventueele mee gegeven variable
	lcd.fillRoundRect(lcX, lcY, buttonsizeX, buttonsizeY, 10, backgroundcolour);
	//a letter is 4x4 pixels
	lcd.drawText(lcX + (buttonsizeX / 2) - (arrSize * 4), lcY + (buttonsizeY / 2) - 4, text, tekstcolour, backgroundcolour, 1);
}

int getWidthButtons()
{
	return widthButtons;
}

int getXwaardeButtons()
{
	return XwaardeButtons;
}

int getButtonLength()
{
	return buttonLength;
}

int getButton1X()
{
	return button1X;
}

int getButton2X()
{
	return button2X;
}

int getButton3X()
{
	return button3X;
}

int getButton4X()
{
	return button4X;
}