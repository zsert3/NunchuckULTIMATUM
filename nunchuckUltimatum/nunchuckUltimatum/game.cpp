// 
// 
// 

#include "game.h"
typedef struct {
	int size;
	int location;
}obstacle;

int b = 0;
int joyx = 0;
int joyy = 0;
int blocationx = 110;
int blocationy = 270;
int obstacles[320] = { 0 };
obstacle obstacles1[80];

void gameInitialisation(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	nunchuckInit();
	resetboat(lcd,watercolour, landcolour, tekstColour);
}

void game(MI0283QT9 lcd, int watercolour, int treecolour, int landcolour, int tekstcolour)
{
	for (int i = 0; i < 320; i += 5) {
		if (obstacles[i] != 0) {
			//if((obstacles1 + i)->location != 0){			
			lcd.fillRect(obstacles[i] % 1000, i - 5, obstacles[i] / 100 + 8, 5, RGB(100, 149, 237)); //<-- deze kleur is het water
			//lcd.fillRect(obstacles[i] % 1000, i - 5, obstacles[i] / 100 + 8, 5, watercolour);

			//lcd.fillRect((obstacles1 + i)->location, (i - 1) * 4, (obstacles1 + i)->size, 4 , watercolour);	

			lcd.fillRect(obstacles[i] % 1000, i, obstacles[i] / 100 + 8, 6, RGB(139, 69, 0));//<-- deze kleur zijn de boomstammen
			//lcd.fillRect(obstacles[i] % 1000, i, obstacles[i] / 100 + 8, 6, treecolour);
			//lcd.drawRect(obstacles[i] % 1000, i, obstacles[i] / 100 + 8, 5, RGB(0, 0, 0));
			//lcd.fillRect((obstacles1 + i)->location, i * 4, (obstacles1 + i)->size, 6, treecolour);				
		}
	}
	if (obstacles[320] != 0)
		lcd.fillRect(11, 315, 219, 6, watercolour);
	for (int i = 320; i > 0; i--) {  //shift alle obstakels met 1
		obstacles[i] = obstacles[i - 1];
		//(obstacles1 + i)->location = (obstacles1 + i - 1)->location;
		//(obstacles1 + i)->size = (obstacles1 + i - 1)->size;
	}

	nunchuckGetData();
	joyx = nunchuckGetJoyX();
	joyy = nunchuckGetJoyY();


	if (joyy > 145) {
		if (blocationy > 0) {
			blocationy -= 2;
			lcd.fillRect(blocationx, blocationy + 25, 15, 2, watercolour);

		}
	}

	if (joyy < 105) {
		if (blocationy < 295) {
			blocationy += 2;
			lcd.fillRect(blocationx, blocationy - 2, 15, 2, watercolour);

		}
	}

	if (joyx > 145) {	//marge vanaf hoever van middelpunt bewegen
						//if (blocationx < 215) {
		blocationx += 2;	//snelheid boot, bij hoge waarde - breedte boot
		lcd.fillRect(blocationx - 2, blocationy, 2, 25, watercolour);

		//}
	}

	if (joyx < 105) {
		//if (blocationx > 10) {
		blocationx -= 2;
		lcd.fillRect(blocationx + 15, blocationy, 2, 25, watercolour);

		//}
	}
	if (nunchuckGetJoyX() == joyx && nunchuckGetJoyY() == joyy)
		tekenboot(lcd, blocationx, blocationy);
	//lcd.fillRect(blocationx, blocationy, 15, 25, RGB(156, 102, 31));
	//lcd.drawRect(blocationx, blocationy, 15, 25, RGB(0, 0, 0));

	b++;
	if (b == 55) {
		b = 0;
		int size = (rand() % 7 + 4) * 1000;
		int location = (rand() % (10 - (size / 1000) + 12) + 1) * 10 + 1;

		obstacles[0] = location + size;
		//obstacles[0] = ((rand() % 12 + 1) * 10 + 1) + ((rand() % 7 + 4) * 1000);

		//Serial.println(obstacles[16]);
		//obstacles1->location = (rand() % 15 + 2) * 10;
		//obstacles1->size = (rand() % 7 + 3) * 10;		
	}
	else {
		obstacles[0] = 0;
		//obstacles1->location = 0;
		//obstacles1->size = 0;
	}

	check_collision(lcd, blocationx,blocationy,watercolour, landcolour, tekstcolour);
	//for (int i = 0; i < 7; i++) {

	//	lcd.fillRect(blocationx, blocationy + 25 + i, 15, 1, RGB(255, 255, 255));
	//delay(1);


	//}
	//lcd.fillRect(blocationx, blocationy + 25 , 15, 7, watercolour);
	//delay(5);
}

void check_collision(MI0283QT9 lcd, int blocationx, int blocationy, int watercolour, int landcolour, int tekstcolour) {
	if (blocationx <= 11 || blocationx >= 215) { //oever
		resetboat(lcd, watercolour, landcolour, tekstcolour);
		return;
	}

	//for (int i = 0; i < 5; i++) {
	//	if(blocationx + 15 < obstacles[blocationy])
	//}

	for (int i = 0; i < 5; i++) { //voorkant
		if (blocationx > obstacles[blocationy + i] % 1000 - 15 && blocationx + 15 < obstacles[blocationy + i] % 1000 + obstacles[blocationy + i] / 100 + 20) {
			resetboat(lcd, watercolour, landcolour, tekstcolour);
			return;
		}
	}

	for (int i = 0; i < 5; i++) { //achterkant
		if (blocationx > obstacles[blocationy + 25 + i] % 1000 - 15 && blocationx + 15 < obstacles[blocationy + 25 + i] % 1000 + obstacles[blocationy + 25 + i] / 100 + 20) {
			resetboat(lcd, watercolour, landcolour, tekstcolour);
			return;
		}
	}

	for (int i = 0; i < 5; i++) { //achterkant
		if (blocationx > obstacles[blocationy + 13 + i] % 1000 - 15 && blocationx + 15 < obstacles[blocationy + 13 + i] % 1000 + obstacles[blocationy + 13 + i] / 100 + 20) {
			resetboat(lcd, watercolour, landcolour, tekstcolour);
			return;
		}
	}
}

void resetboat(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour) {
	memset(obstacles, 0, sizeof(obstacles));
	//lcd.fillRect(10, 0, 220, 320, watercolour);
	//lcd.fillRect(0, 0, 10, 320, landcolour);
	//lcd.fillRect(230, 0, 10, 320, landcolour);
	for (int b = 3; b >= 1; b--)
	{
		for (int i = 0; i <= 400; i += 20)
		{
			lcd.fillRect(40, i - 20, 150, 20, watercolour);
			lcd.drawInteger(90, i, b, 10, tekstColour, watercolour, 10);
		}
	}
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