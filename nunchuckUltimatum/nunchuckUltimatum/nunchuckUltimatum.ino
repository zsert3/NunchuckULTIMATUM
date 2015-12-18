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
#include "gameover.h"
#include "lives.h"
#include "pausescreen.h"
//overig
#include <EEPROM.h>

MI0283QT9 lcd;
//int watercolour = RGB(123, 104, 238); //waterkleur
int watercolour = RGB(100, 149, 237); //waterkleur

int landcolour = RGB(154, 205, 50); //landkleur
int tekstColour = RGB(160, 82, 45); //tekstkleur
int treecolour = RGB(139, 69, 0); //boomkleur
int c_button = 0;

int main()
{
	init();
	lcd.begin();
	Serial.begin(19200);
	lcd.touchStartCal();
	lcd.setOrientation(90);
	lcd.fillScreen(landcolour);
	drawMenuScherm(lcd, watercolour, landcolour, tekstColour);//tekent het menuscherm
	int i = 0;
	while (1)
	{
		
		if (getGameStarted() != 1)//checkt als de game gestart is
		{
			Serial.println("In da if");
			touchScreen(lcd, watercolour, landcolour, tekstColour);//dit zorgt s
		}
		//setGameStarted(0);
		if (getGameStarted() == 1)
		{
			if (i == 0)
			{
				gameInitialisation(lcd, watercolour, landcolour, tekstColour);//game initialzation
				i = 1;
			}
			do
			{
				game(lcd, watercolour, treecolour, landcolour, tekstColour);
				pausescreen(lcd, watercolour, landcolour, tekstColour);
			} while (getGameStarted() == 1);
			Serial.println("Uit de Loop");
			i = 0;
		}
		


	}
}