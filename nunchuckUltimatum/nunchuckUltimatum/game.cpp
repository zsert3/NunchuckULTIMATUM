
#include "game.h"


int joyx;
int joyy;
int blocationx = 110;
int blocationy = 270;
uint8_t newloc = 1;


void gameInitialisation(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	nunchuckInit();
	resetBoat(lcd,watercolour, landcolour, tekstColour);
	ledInit();
	resetLives();
	resetObstaclespeed();
	
	//aftellen voor game start
	for (int b = 3; b >= 1; b--)
	{
		for (int i = 0; i <= 400; i += 20)
		{
			lcd.fillRect(10, i - 20, 220, 20, watercolour);
			lcd.drawInteger(90, i, b, 10, tekstColour, watercolour, 10);
		}
	}
}


void game(MI0283QT9 lcd, int watercolour, int treecolour, int landcolour, int tekstcolour)
{
	nunchuckGetData();
	joyx = nunchuckGetJoyX();
	joyy = nunchuckGetJoyY();
	
	//nunchuck omhoog
	if (joyy > 145) {
		if (blocationy > 0) {
			blocationy -= 5;
			lcd.fillRect(blocationx, blocationy + 25, 15, 5, RGB(100, 149, 237));  //verwijder deel van boot dat veranderd
			newloc = 1;
		}
	}

	//nunchuck omlaag
	if (joyy < 105) {
		if (blocationy < 295) {
			blocationy += 5;
			lcd.fillRect(blocationx, blocationy - 5, 15, 5, RGB(100, 149, 237));
			newloc = 1;
		}
	}

	//nunchuck naar rechts
	if (joyx > 145) {	
		blocationx += 5;	
		lcd.fillRect(blocationx - 5, blocationy, 5, 25, RGB(100, 149, 237));
		newloc = 1;
	}

	//nunchuck naar links
	if (joyx < 105) {
		blocationx -= 5;
		lcd.fillRect(blocationx + 15, blocationy, 5, 25, RGB(100, 149, 237));
		newloc = 1;
	}

	//teken boot als locatie veranderd
	if (newloc == 1) {
		tekenboot(lcd, blocationx, blocationy);
		newloc = 0;
	}

	
	drawScore(lcd);

	drawObstacles(lcd);

	shiftObstacles(lcd);

	checkLives();

	//obstakels langs gaan om te checken of de boot ze raakt
	for (uint8_t i = 0; i < 5; i++) {
		checkCollision(lcd, getObstaclex(i), getObstacley(i), getObstacles(i), watercolour, landcolour, tekstcolour);
	}
	}
	
	


void checkCollision(MI0283QT9 lcd, uint8_t x, uint16_t y, uint8_t size, int watercolour, int landcolour, int tekstColour) {
		//check of bootlocatie overeenkomt met obstakel
		if(blocationy <= 0 || blocationx <= 11 || blocationx >= 211 || blocationy > 290 || blocationx > x - 15 && blocationx + 15 < x + size + 15 && ((y + 8 >= blocationy && y - 2 <= blocationy) || (y + 8 >= blocationy + 25 && y - 2 <= blocationy + 25) || (y + 8 >= blocationy + 12 && y - 2 <= blocationy + 12))) {
			//reset alle gegevens wanneer de gebruiker geen levens meer heeft
			resetBoat(lcd, watercolour, landcolour, tekstColour);
			if (getLives() >= 3) {
				scoreCalculator(getScore());
				resetLives();
				setGameStarted(0);
				setpushed(0);
			
				basisschermGameOver(lcd, watercolour, landcolour, tekstColour);
				resetScore();
				return;
			}
		else {
			removeLive();
		}
		
	}
}


void resetBoat(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour) {
	resetObstacles();
	newloc = 1;
	lcd.fillRect(230, 0, 10, 320, landcolour);
	lcd.fillRect(10, 0, 220, 320, watercolour);
	setBlocationX(110);
	setBlocationY(270);
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
