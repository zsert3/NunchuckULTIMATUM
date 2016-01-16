
#include "game.h"


//boat location data
uint16_t blocationx = 110;
uint16_t blocationy = 270;
uint8_t newloc = 1;


void gameInitialisation(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour)
{
	nunchuckInit();
	
	resetBoat(lcd,waterColour, landColour);
	ledInit();
	resetLives();
	resetObstaclespeed();
	resetScore();
}


void game(MI0283QT9 lcd, int16_t waterColour, int16_t treeColour, int16_t landColour, int16_t textColour)
{
	nunchuckGetData();
	int joyx = nunchuckGetJoyX();
	int joyy = nunchuckGetJoyY();
	
	//nunchuck up
	if (joyy > 145) {
		if (blocationy > 0) {
			blocationy -= 5;
			lcd.fillRect(blocationx, blocationy + 25, 15, 5, waterColour);  //removes part of the boat when it changes to another position
			newloc = 1;
		}
	}

	//nunchuck down
	if (joyy < 105) {
		if (blocationy < 295) {
			blocationy += 5;
			lcd.fillRect(blocationx, blocationy - 5, 15, 5, waterColour);
			newloc = 1;
		}
	}

	//nunchuck to the right
	if (joyx > 145) {	
		blocationx += 5;	
		lcd.fillRect(blocationx - 5, blocationy, 5, 25, waterColour);
		newloc = 1;
	}

	//nunchuck to the left
	if (joyx < 105) {
		blocationx -= 5;
		lcd.fillRect(blocationx + 15, blocationy, 5, 25, waterColour);
		newloc = 1;
	}
	//draw boat if location changed
	if (newloc == 1) {
		drawBoat(lcd, blocationx, blocationy);
		newloc = 0;
	}	
	drawScore(lcd,waterColour);
	drawObstacles(lcd);
	shiftObstacles(lcd);
	checkLives();
	
	//check the obstacles if the boat touches them
	for (uint8_t i = 0; i < 5; i++) {
		checkCollision(lcd, getObstaclex(i), getObstacley(i), getObstacles(i), waterColour, landColour, textColour);
	}
}
	
	


void checkCollision(MI0283QT9 lcd, uint8_t x, uint16_t y, uint8_t size, int16_t waterColour, int16_t landColour, int16_t textColour) {
		//check if loctation of the boat is the same as the obstacel
		if(blocationy <= 0 || blocationx <= 11 || blocationx >= 211 || blocationy > 290 || blocationx > x - 15 && blocationx + 15 < x + size + 15 && ((y + 8 >= blocationy && y - 2 <= blocationy) || (y + 8 >= blocationy + 25 && y - 2 <= blocationy + 25) || (y + 8 >= blocationy + 12 && y - 2 <= blocationy + 12))) {
			//reset everything from the game if the player has no lives
			resetBoat(lcd, waterColour, landColour);
			if (getLives() >= 3) {
				scoreCalculator(getScore());
				resetLives();
				setGameStarted(0);
				setPushed(0);
			
				basicschermGameOver(lcd, waterColour, landColour, textColour);
				resetScore();
				return;
			}
		else {
			removeLive();
		}
		
	}
}



void setBlocationX(uint16_t Blocationx)
{
	blocationx = Blocationx;
}


void setBlocationY(uint16_t Blocationy)
{
	blocationy = Blocationy;
}


void setVisable() {
	newloc = 1;
}

//set boat back to starting position
void resetBoat(MI0283QT9 lcd, int16_t waterColour, int16_t landColour) {
	resetObstacles();
	setVisable();
	lcd.fillRect(230, 0, 10, 320, landColour);
	lcd.fillRect(10, 0, 220, 320, waterColour);
	setBlocationX(110);
	setBlocationY(270);
}
