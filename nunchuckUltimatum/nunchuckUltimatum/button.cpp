// 
// 
// 

#include "button.h"
//array size 
int8_t arrSize = 0;
int8_t widthButtons = 40;
int8_t xValueButtons = 40;
int8_t buttonLength = 160;
int8_t button1X = 60;
int8_t button2X = 125;
int8_t button3X = 190;
int8_t button4X = 255;

void placeButton(MI0283QT9 lcd, int16_t backgroundColour, int16_t textColour, char *text, uint8_t lcX, uint16_t lcY, uint8_t buttonSizeY, uint8_t buttonSizeX) {
	//add text if there is any text
	//calculates the length of the text
	arrSize = strlen(text);
	lcd.fillRoundRect(lcX, lcY, buttonSizeX, buttonSizeY, 10, backgroundColour);
	//a letter is 4x4 pixels
	lcd.drawText(lcX + (buttonSizeX / 2) - (arrSize * 4), lcY + (buttonSizeY / 2) - 4, text, textColour, backgroundColour, 1);
}

int8_t getWidthButtons()
{
	return widthButtons;
}

int8_t getXValueButtons()
{
	return xValueButtons;
}

int8_t getButtonLength()
{
	return buttonLength;
}

int8_t getButton1X()
{
	return button1X;
}

int8_t getButton2X()
{
	return button2X;
}

int8_t getButton3X()
{
	return button3X;
}

int8_t getButton4X()
{
	return button4X;
}