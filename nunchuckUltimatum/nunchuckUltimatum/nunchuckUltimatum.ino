/*
 Name:		nunchuckUltimatum.ino
 Created:	02-Dec-15 10:22:10 AM
 Author:	Zsert
*/
//scherm includes
#include <EEPROM.h>
#include <MI0283QT9.h>
#include <GraphicsLib.h>
#include <SPI.h>
#include <digitalWriteFast.h>

//avr includes
#include <avr/io.h>
#include <avr/interrupt.h>
#include <Wire\Wire.h>
//files
#include "highscores.h"
#include "nunchuckData.h"
#include "mainMenu.h"
#include "tutorial.h"

MI0283QT9 lcd;
int colour1 = RGB(123, 104, 238);
int colour2 = RGB(154, 205, 50);
int tekstColour = RGB(160, 82, 45);

int main()
{
	init();
	lcd.begin();
	Serial.begin(19200);
	lcd.touchStartCal();
	lcd.setOrientation(90);
	lcd.fillScreen(colour2);
	drawMenuScherm(lcd, colour1, colour2, tekstColour);

	while (1)
	{
		touchScreen(lcd, colour1, colour2, tekstColour);
		delay(40);
	}
}