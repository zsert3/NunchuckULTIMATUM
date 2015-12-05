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

MI0283QT9 lcd;
//int watercolour = RGB(123, 104, 238); //waterkleur
int watercolour = RGB(100, 149, 237); //waterkleur

int landcolour = RGB(154, 205, 50); //landkleur
int tekstColour = RGB(160, 82, 45); //tekstkleur
int treecolour = RGB(139, 69, 0); //boomkleur

int main()
{
	init();
	lcd.begin();
	Serial.begin(19200);
	//lcd.touchStartCal();
	lcd.setOrientation(90);
	//lcd.fillScreen(landcolour);
	//drawMenuScherm(lcd, watercolour, landcolour, tekstColour);

	while (1)
	{
		gameInitialisation(lcd, watercolour, landcolour);
		setGameStarted(1);
		do
		{
			game(lcd, watercolour, treecolour, landcolour);
		} while (getGameStarted() == 1);
		//touchScreen(lcd, watercolour, landcolour, tekstColour);
		//setGameStarted(0);

	}
}