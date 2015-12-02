/*
 Name:		nunchuckUltimatum.ino
 Created:	02-Dec-15 10:22:10 AM
 Author:	Zsert
*/



//includes voor het scherm
#include <digitalWriteFast.h>
#include <SPI.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>

//avr includes
#include <avr/io.h>
//files
#include "nunchuckData.h"
#include "mainMenu.h"
MI0283QT9 lcd;
int main()
{
	init();
	lcd.begin();
	lcd.touchStartCal();
	Serial.begin(19200);
	lcd.setOrientation(90);
	drawMenuScherm(lcd);



	while (1)
	{
		touchScreen(lcd);
		delay(40);
	}
}
