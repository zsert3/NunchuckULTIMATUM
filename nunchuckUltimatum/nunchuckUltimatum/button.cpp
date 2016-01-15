// 
// 
// 

#include "button.h"
int8_t arrSize = 0;
int8_t widthButtons = 40;
int8_t XwaardeButtons = 40;
int8_t buttonLength = 160;
int8_t button1X = 60;
int8_t button2X = 125;
int8_t button3X = 190;
int8_t button4X = 255;

void placeButton(MI0283QT9 lcd, int16_t backgroundcolour, int16_t tekstcolour, char *text, uint8_t lcX, uint16_t lcY, uint8_t buttonsizeY, uint8_t buttonsizeX) {
	arrSize = strlen(text);
	//toegevoegt als eventueele mee gegeven variable
	lcd.fillRoundRect(lcX, lcY, buttonsizeX, buttonsizeY, 10, backgroundcolour);
	//a letter is 4x4 pixels
	lcd.drawText(lcX + (buttonsizeX / 2) - (arrSize * 4), lcY + (buttonsizeY / 2) - 4, text, tekstcolour, backgroundcolour, 1);
}

uint8_t getWidthButtons()
{
	return widthButtons;
}

uint8_t getXwaardeButtons()
{
	return XwaardeButtons;
}

uint8_t getButtonLength()
{
	return buttonLength;
}

uint8_t getButton1X()
{
	return button1X;
}

uint8_t getButton2X()
{
	return button2X;
}

uint8_t getButton3X()
{
	return button3X;
}

uint8_t getButton4X()
{
	return button4X;
}