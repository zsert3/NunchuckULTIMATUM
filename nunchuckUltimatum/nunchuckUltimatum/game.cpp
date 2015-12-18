
#include "game.h"


typedef struct {
	uint8_t osize;
	uint16_t olocationy;
	uint8_t olocationx;
}obstacles;


int joyx;
int joyy;
int blocationx = 110;
int blocationy = 270;
uint8_t newloc = 1;
uint8_t c;
int score = 0;
//uint8_t lives = 0;
//uint8_t blinkRed = 0;
//uint8_t odirection = 0;

obstacles obstacle[5];


void gameInitialisation(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	nunchuckInit();
	resetboat(lcd,watercolour, landcolour, tekstColour);
	ledInit();
	setlives(1);
}

void game(MI0283QT9 lcd, int watercolour, int treecolour, int landcolour, int tekstcolour)
{
	nunchuckGetData();
	joyx = nunchuckGetJoyX();
	joyy = nunchuckGetJoyY();
	
	if (joyy > 145) {
		if (blocationy > 0) {
			blocationy -= 4;
			lcd.fillRect(blocationx, blocationy + 25, 15, 4, RGB(100, 149, 237));
			newloc = 1;
		}
	}

	if (joyy < 105) {
		if (blocationy < 295) {
			blocationy += 4;
			lcd.fillRect(blocationx, blocationy - 4, 15, 4, RGB(100, 149, 237));
			newloc = 1;
		}
	}

	if (joyx > 145) {	//marge vanaf hoever van middelpunt bewegen
		blocationx += 4;	//snelheid boot, bij hoge waarde - breedte boot
		lcd.fillRect(blocationx - 4, blocationy, 4, 25, RGB(100, 149, 237));
		newloc = 1;
	}

	if (joyx < 105) {
		blocationx -= 4;
		lcd.fillRect(blocationx + 15, blocationy, 4, 25, RGB(100, 149, 237));
		newloc = 1;
	}

	if (newloc == 1)
		tekenboot(lcd, blocationx, blocationy);
	newloc = 0;

	lcd.drawText(17, 10, "Score", RGB(0, 0, 0), RGB(100, 149, 237), 1);
	lcd.drawInteger(17, 20, score, DEC, RGB(0, 0, 0), RGB(100, 149, 237), 1);

	for (c = 0; c < 5; c++) {
		lcd.fillRect((obstacle + c)->olocationx, (obstacle + c)->olocationy - 3, (obstacle + c)->osize, 3, RGB(100, 149, 237));
		lcd.fillRect((obstacle + c)->olocationx, (obstacle + c)->olocationy + 3, (obstacle + c)->osize, 4, RGB(139, 69, 0));
		check_collision(lcd, (obstacle + c)->olocationx, (obstacle + c)->olocationy, (obstacle + c)->osize, watercolour, landcolour, tekstcolour);
		(obstacle + c)->olocationy += 3;
	}

	if ((obstacle + 0)->olocationy >= 64 || (obstacle + 0)->osize == 0) {
		if ((obstacle + 4)->olocationy >= 160)score++;
		lcd.fillRect(11, 315, 219, 6, RGB(100, 149, 237));
		for (c = 4; c > 0; c--) {
			(obstacle + c)->olocationx = (obstacle + c - 1)->olocationx;
			(obstacle + c)->olocationy = (obstacle + c - 1)->olocationy;
			(obstacle + c)->osize = (obstacle + c - 1)->osize;
		}
		obstacle->olocationy = 0;
		obstacle->osize = (rand() % 5 + 5) * 10;
		obstacle->olocationx = (rand() % (9 - obstacle->osize / 10 + 13) + 1) * 10 + 1;

		check_lives();
	}
	}


void check_collision(MI0283QT9 lcd, uint8_t x, uint16_t y, uint8_t size, int watercolour, int landcolour, int tekstColour) {
	if (blocationy <= 5 || blocationx <= 11 || blocationx >= 215 || blocationy > 295 || blocationx > x - 15 && blocationx + 15 < x + size + 15 && ((y + 7 >= blocationy && y - 2 <= blocationy) || (y + 7 >= blocationy + 25 && y - 2 <= blocationy + 25) || (y + 7 >= blocationy + 12 && y - 2 <= blocationy + 12))) {
		if (get_lives() >= 3) {
			score = 0;
			reset_lives();
			//setlives(0);
			resetboat(lcd, watercolour, landcolour, tekstColour);
			setGameStarted(0);
			setpushed(0);
			drawMenuScherm(lcd, watercolour, landcolour, tekstColour);
			return;
		}
		else {
			remove_live();
			resetboat(lcd, watercolour, landcolour, tekstColour);
		}
		
	}
}


void resetboat(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour) {
	memset(obstacle, 0, sizeof(obstacle));
	newloc = 1;
	lcd.fillRect(230, 0, 10, 320, landcolour);
	lcd.fillRect(10, 0, 220, 320, watercolour);
	
	/*for (int b = 3; b >= 1; b--)
	{
		for (int i = 0; i <= 400; i += 20)
		{
			
			lcd.fillRect(10, i - 20, 220, 20, watercolour);
			lcd.drawInteger(90, i, b, 10, tekstColour, watercolour, 10);
		}
	}*/
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
void setScore(int Score)
{
	score = Score;
}