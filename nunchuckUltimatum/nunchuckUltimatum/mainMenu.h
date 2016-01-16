// mainMenu.h

#ifndef _MAINMENU_h
#define _MAINMENU_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9.h>
#include "highscores.h"
#include "tutorial.h"
#include "settings.h"
#include "button.h"

void drawMenuScreen(MI0283QT9 lcd, int16_t watercolour, int16_t landcolour, int16_t tekstcolour);
void touchScreen(MI0283QT9 lcd, int16_t watercolour, int16_t landcolour, int16_t tekstcolour);
int8_t getGameStarted(void);
void setGameStarted(int8_t gameStarted);
void setpushed(int8_t Pushed);
#endif

