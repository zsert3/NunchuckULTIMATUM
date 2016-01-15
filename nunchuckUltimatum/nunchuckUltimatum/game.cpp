
#include "game.h"



int blocationx = 110;
int blocationy = 270;
uint8_t newloc = 1;


void gameInitialisation(MI0283QT9 lcd, int16_t watercolour, int16_t landcolour, int16_t tekstcolour)
{
	nunchuckInit();
	
	resetBoat(lcd,watercolour, landcolour);
	ledInit();
	resetLives();
	resetObstaclespeed();
	resetScore();
	
	////countdown for game
	//for (int b = 3; b >= 1; b--)
	//{
	//	for (int i = 0; i <= 400; i += 40)
	//	{
	//		lcd.fillRect(10, i - 40, 220, 40, watercolour);
	//		lcd.drawInteger(90, i, b, 10, tekstcolour, watercolour, 10);
	//	}
	//}
}


void game(MI0283QT9 lcd, int16_t watercolour, int16_t treecolour, int16_t landcolour, int16_t tekstcolour)
{
	nunchuckGetData();
	int joyx = nunchuckGetJoyX();
	int joyy = nunchuckGetJoyY();
	
	//nunchuck up
	if (joyy > 145) {
		if (blocationy > 0) {
			blocationy -= 5;
			lcd.fillRect(blocationx, blocationy + 25, 15, 5, watercolour);  //verwijder deel van boot dat veranderd
			newloc = 1;
		}
	}

	//nunchuck down
	if (joyy < 105) {
		if (blocationy < 295) {
			blocationy += 5;
			lcd.fillRect(blocationx, blocationy - 5, 15, 5, watercolour);
			newloc = 1;
		}
	}

	//nunchuck to the right
	if (joyx > 145) {	
		blocationx += 5;	
		lcd.fillRect(blocationx - 5, blocationy, 5, 25, watercolour);
		newloc = 1;
	}

	//nunchuck to the left
	if (joyx < 105) {
		blocationx -= 5;
		lcd.fillRect(blocationx + 15, blocationy, 5, 25, watercolour);
		newloc = 1;
	}

	//teken boot als locatie veranderd
	//draw boat if location changed
	if (newloc == 1) {
		drawboot(lcd, blocationx, blocationy);
		newloc = 0;
	}

	
	drawScore(lcd,watercolour);

	drawObstacles(lcd);

	shiftObstacles(lcd);

	checkLives();


	//check obstakles if the boat touches them
	for (uint8_t i = 0; i < 5; i++) {
		checkCollision(lcd, getObstaclex(i), getObstacley(i), getObstacles(i), watercolour, landcolour, tekstcolour);
	}
}
	
	


void checkCollision(MI0283QT9 lcd, uint8_t x, uint16_t y, uint8_t size, int16_t watercolour, int16_t landcolour, int16_t tekstcolour) {
		//check if loctation of the boat is the same as the obstacel
		if(blocationy <= 0 || blocationx <= 11 || blocationx >= 211 || blocationy > 290 || blocationx > x - 15 && blocationx + 15 < x + size + 15 && ((y + 8 >= blocationy && y - 2 <= blocationy) || (y + 8 >= blocationy + 25 && y - 2 <= blocationy + 25) || (y + 8 >= blocationy + 12 && y - 2 <= blocationy + 12))) {
			//reset everything from the game if the player has no lives
			resetBoat(lcd, watercolour, landcolour);
			if (getLives() >= 3) {
				scoreCalculator(getScore());
				resetLives();
				setGameStarted(0);
				setpushed(0);
			
				basicschermGameOver(lcd, watercolour, landcolour, tekstcolour);
				resetScore();
				return;
			}
		else {
			removeLive();
		}
		
	}
}



void setBlocationX(int Blocationx)
{
	blocationx = Blocationx;
}


void setBlocationY(int Blocationy)
{
	blocationy = Blocationy;
}


void setVisable() {
	newloc = 1;
}


void resetBoat(MI0283QT9 lcd, int16_t watercolour, int16_t landcolour) {
	resetObstacles();
	setVisable();
	lcd.fillRect(230, 0, 10, 320, landcolour);
	lcd.fillRect(10, 0, 220, 320, watercolour);
	setBlocationX(110);
	setBlocationY(270);
}
