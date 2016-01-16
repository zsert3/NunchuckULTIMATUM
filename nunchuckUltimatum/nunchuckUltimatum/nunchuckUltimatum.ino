/*
 Name:		nunchuckUltimatum.ino
 Created:	02-Dec-15 10:22:10 AM
 Author:	Zsert
*/
//scherm includes
#include "mainMenu.h"
#include "pausescreen.h"
#include "game.h"
//avr includes
#include <avr/io.h>
#include <avr/interrupt.h>
#include <Wire/Wire.h>
//files
#include <MI0283QT9.h>
#include <GraphicsLib.h>
#include <SPI.h>
#include <digitalWriteFast.h>
#include <EEPROM.h>

MI0283QT9 lcd;
int16_t watercolour = RGB(100, 149, 237); //waterkleur
int16_t landcolour = RGB(154, 205, 50); //landkleur
int16_t tekstcolour = RGB(160, 82, 45); //tekstkleur
int16_t treecolour = RGB(139, 69, 0); //boomkleur

int main()
{
	init();
	lcd.begin();
	calibratie();
	setBrightnes(getBrightnes(), lcd);
	lcd.touchRead();
	lcd.setOrientation(90);
	lcd.fillScreen(landcolour);
	drawMenuScreen(lcd, watercolour, landcolour, tekstcolour);//tekent het menuscherm
	int8_t i = 0;
	while (1)
	{
		
		if (getGameStarted() != 1)//checkt als de game gestart is
		{
			touchScreen(lcd, watercolour, landcolour, tekstcolour);//dit zorgt s
		}
		if (getGameStarted() == 1)
		{
			
			if (i == 0)
			{
				gameInitialisation(lcd, watercolour, landcolour, tekstcolour);//game initialzation
				i = 1;
			}
			do
			{
				game(lcd, watercolour, treecolour, landcolour, tekstcolour);
				pausescreen(lcd, watercolour, landcolour, tekstcolour);
			} while (getGameStarted() == 1);
			i = 0;
		}
	}
}

void calibratie()
{
# define LCD_WIDTH      320
# define LCD_HEIGHT     240

# define CAL_POINT_X1   20
# define CAL_POINT_Y1   20
# define CAL_POINT1     {CAL_POINT_X1,CAL_POINT_Y1}
# define CAL_POINT_X2   LCD_WIDTH-20 //300
# define CAL_POINT_Y2   LCD_HEIGHT/2 //120
# define CAL_POINT2     {CAL_POINT_X2,CAL_POINT_Y2}
# define CAL_POINT_X3   LCD_WIDTH/2   //160
# define CAL_POINT_Y3   LCD_HEIGHT-20 //220
# define CAL_POINT3     {CAL_POINT_X3,CAL_POINT_Y3}

# define TP_POINT_X1   558
# define TP_POINT_Y1   71
# define TP_POINT1     {TP_POINT_X1,TP_POINT_Y1}
# define TP_POINT_X2   966
# define TP_POINT_Y2   250
# define TP_POINT2     {TP_POINT_X2,TP_POINT_Y2}
# define TP_POINT_X3   768
# define TP_POINT_Y3   440
# define TP_POINT3     {TP_POINT_X3,TP_POINT_Y3}

	CAL_POINT lcd_points[3] = { CAL_POINT1, CAL_POINT2, CAL_POINT3 };
	CAL_POINT tp_points[3] = { TP_POINT1, TP_POINT2, TP_POINT3 };
	lcd.touchSetCal(lcd_points, tp_points);
}