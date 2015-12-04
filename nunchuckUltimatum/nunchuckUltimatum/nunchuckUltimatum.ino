/*
 Name:		nunchuckUltimatum.ino
 Created:	02-Dec-15 10:22:10 AM
 Author:	Zsert
*/
//scherm includes
#include <MI0283QT9.h>
#include <GraphicsLib.h>
#include <SPI.h>
#include <digitalWriteFast.h>

//avr includes
#include <avr/io.h>
#include <avr/interrupt.h>
#include <Wire\Wire.h>
//files
#include "game.h"
#include "highscores.h"
#include "mainMenu.h"
#include "tutorial.h"

int watercolour = RGB(123, 104, 238); //waterkleur
int landcolour = RGB(154, 205, 50); //landkleur
int tekstColour = RGB(160, 82, 45); //tekstkleur
int treecolour = RGB(139, 69, 0); //boomkleur
extern int gameStarted = 0;
extern MI0283QT9 lcd;

int main()
{
	init();
	lcd.begin();
	Serial.begin(19200);
	lcd.touchStartCal();
	lcd.setOrientation(90);
	lcd.fillScreen(landcolour);
	drawMenuScherm(lcd, watercolour, landcolour, tekstColour);

	while (1)
	{
		touchScreen(lcd, watercolour, landcolour, tekstColour);
		if (gameStarted == 1)
		{

			//link naar bastiaan's code
		}
	}
}