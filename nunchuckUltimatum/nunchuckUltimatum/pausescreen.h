// pausescreen.h

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

void pausescreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour);
void drawpausescreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
void touchScreenPauseMenu(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
void setPauseScreenPushed(int pausePushed);


