
#include "game.h"


//typedef struct {
//	uint8_t osize;
//	uint16_t olocationy;
//	uint8_t olocationx;
//}obstacles;


int joyx;
int joyy;
int blocationx = 110;
int blocationy = 270;
uint8_t newloc = 1;
//uint8_t obstaclespeed = 1;
uint8_t c;
uint8_t ie;
int score = 0;
//uint8_t lives = 0;
//uint8_t blinkRed = 0;
//uint8_t odirection = 0;

//obstacles obstacle[5];


void gameInitialisation(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	//reset_obstacles();
	nunchuckInit();
	resetboat(lcd,watercolour, landcolour, tekstColour);
	ledInit();
	setlives(1);
	set_obstaclespeed(1);
}

void game(MI0283QT9 lcd, int watercolour, int treecolour, int landcolour, int tekstcolour)
{
	nunchuckGetData();
	joyx = nunchuckGetJoyX();
	joyy = nunchuckGetJoyY();
	
	if (joyy > 145) {
		if (blocationy > 0) {
			blocationy -= 5;
			lcd.fillRect(blocationx, blocationy + 25, 15, 5, RGB(100, 149, 237));
			newloc = 1;
		}
	}

	if (joyy < 105) {
		if (blocationy < 295) {
			blocationy += 5;
			lcd.fillRect(blocationx, blocationy - 5, 15, 5, RGB(100, 149, 237));
			newloc = 1;
		}
	}

	if (joyx > 145) {	//marge vanaf hoever van middelpunt bewegen
		blocationx += 5;	//snelheid boot, bij hoge waarde - breedte boot
		lcd.fillRect(blocationx - 5, blocationy, 5, 25, RGB(100, 149, 237));
		newloc = 1;
	}

	if (joyx < 105) {
		blocationx -= 5;
		lcd.fillRect(blocationx + 15, blocationy, 5, 25, RGB(100, 149, 237));
		newloc = 1;
	}

	if (newloc == 1) {
		tekenboot(lcd, blocationx, blocationy);
		newloc = 0;
	}

	lcd.drawText(17, 10, "Score", RGB(0, 0, 0), RGB(100, 149, 237), 1);
	lcd.drawInteger(17, 20, score, DEC, RGB(0, 0, 0), RGB(100, 149, 237), 1);

	draw_obstacles(lcd);

	if (get_obstacley(0) >= 64) {
		score++;
		if (score % 20 == 19 && get_obstaclespeed() <= 3)set_obstaclespeed((score + 19) / 19);
	}

	shift_obstacles(lcd);

	check_lives();

	for (uint8_t i = 0; i < 5; i++) {
		check_collision(lcd, get_obstaclex(i), get_obstacley(i), get_obstacles(i), watercolour, landcolour, tekstcolour);
	}
	}
	
	


void check_collision(MI0283QT9 lcd, uint8_t x, uint16_t y, uint8_t size, int watercolour, int landcolour, int tekstColour) {
	if (blocationy <= 0 || blocationx <= 11 || blocationx >= 211 || blocationy > 290 || blocationx > x - 15 && blocationx + 15 < x + size + 15 && ((y + 8 >= blocationy && y - 2 <= blocationy) || (y + 8 >= blocationy + 25 && y - 2 <= blocationy + 25) || (y + 8 >= blocationy + 12 && y - 2 <= blocationy + 12))) {
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
			Serial.println("test");
			remove_live();
			resetboat(lcd, watercolour, landcolour, tekstColour);
		}
		
	}
}


void resetboat(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour) {
	reset_obstacles();
	//memset(obstacle, 0, sizeof(obstacle));
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