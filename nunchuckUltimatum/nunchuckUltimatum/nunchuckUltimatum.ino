/*
 Name:		nunchuckUltimatum.ino
 Created:	02-Dec-15 10:22:10 AM
 Author:	Zsert
*/


#include "nunchuckData.h"
#include "mainMenu.h"
#include <digitalWriteFast\digitalWriteFast.h>
#include <SPI\SPI.h>
#include <GraphicsLib\GraphicsLib.h>
#include <MI0283QT9\MI0283QT9.h>
MI0283QT9 lcd;
int main()
{
	drawMenuScherm(lcd);
	while (1)
	{

	}
}
