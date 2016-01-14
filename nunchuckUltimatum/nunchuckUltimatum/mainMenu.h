// mainMenu.h

#ifndef _MAINMENU_h
#define _MAINMENU_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9\MI0283QT9.h>
#include "highscores.h"
#include "tutorial.h"
#include "settings.h"
#include "button.h"

void drawMenuScreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
void touchScreen(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour);
int getGameStarted(void);
void setGameStarted(int GameSTarted);
void setpushed(int Pushed);
#endif

