// pauseScreen.h

#ifndef _PAUSESCREEN_h
#define _PAUSESCREEN_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9\MI0283QT9.h>
#include "mainMenu.h"
#include "nunchuckData.h"
#include "game.h"
#include "boot.h"
#include "button.h"

#endif

void pauseScreen(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour);
void drawPauseScreen(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour);
void touchScreenPauseMenu(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour);
void setPauseScreenPushed(int8_t pausePushed);


