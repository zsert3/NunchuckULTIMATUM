// 
// 
// 

#include "settings.h"
#include "eepromManager.h"
#include "mainMenu.h"
//#include "Buttonmaker.h"
//Gerard van Turennout


int settings_pushed = 0;
int setting = 0;

void placeButton(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour, char *text, int lcX, int lcY) {
	int arrSize = strlen(text);
	int buttonsizeX = 160;
	int buttonsizeY = 40;
	lcd.fillRoundRect(lcX, lcY, buttonsizeX, buttonsizeY, 10, landcolour);
	//a letter is 4x4 pixels
	lcd.drawText(lcX + (buttonsizeX/2) - (arrSize * 4), lcY + (buttonsizeY/2) - 4, text, tekstColour, landcolour, 1);
}



void placeSlider(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour, int lcX, int lcY) {
	int slidersizeX = 160;
	int slidersizeY = 40;
	int barthickness = slidersizeY / 8;
	int barpositionY = lcY + (slidersizeY / 2) - (barthickness / 2);
	int nobsize = slidersizeY / 2;
	int barLength = slidersizeX - 20;

	int maxBrightnes = getMaxbrightnes();
	int currentBrightness = getBrightnes();
	Serial.print("helderheid: ");
	Serial.println(currentBrightness);
	int size = barLength /(900.0 / currentBrightness);
	setBrightness(lcd, currentBrightness);
	//lcd.fillRect(lcX, lcY, slidersizeX, slidersizeY, landcolour);
	lcd.fillRect(lcX, lcY+(slidersizeY/4), slidersizeX, slidersizeY/2+ barthickness, landcolour);
	lcd.fillRect(lcX + (slidersizeX - barLength) / 2, barpositionY * 2, barLength, slidersizeY / 2, landcolour);
	lcd.fillRect(lcX+(slidersizeX-barLength)/2, barpositionY, barLength, barthickness, tekstColour);
	lcd.fillRect(lcX+ (slidersizeX - barLength)/2+ size, lcY + (nobsize+ barthickness) / 2, nobsize/2, nobsize,  tekstColour);
	
	//lcd.drawText(lcX + (buttonsizeX / 2) - (arrSize * 4), lcY + buttonsizeY, text, tekstColour, landcolour, 1);
}

void setBrightness(MI0283QT9 lcd, int currentBrightness) {
	lcd.led(getBrightnes() * 0.111 + 5);
}


int brightness() {
}


void touchScreenSettings(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour){ // Here we check if the touchscreen is pushed{
	if (lcd.touchRead()){
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();
		//settings_pushed = 0;

		if (pushX >= 40  && pushX <= 200 && pushY >= 60 && pushY <= 60 + 20){
			resetScore();
			basisschermHighScores(lcd, watercolour, landcolour, tekstcolour);
			terugButton(lcd, watercolour, landcolour, tekstcolour);
			setting = 0;
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 290 && pushY <= 320){
			lcd.fillRect(10, 290, 220, 30, watercolour);
			lcd.drawText(100, 300, "BACK", tekstcolour, watercolour, 1);
			setting = 0;
			drawMenuScherm(lcd, watercolour, landcolour, tekstcolour);
			//setting = 0;
		}

		if (pushX >= 40 && pushX <= 200 && pushY >= 180 && pushY <= 180 + 40) {
			setBrightnes(getMaxbrightnes() / ((200.0-40.0)/(pushX -40)));
			Serial.print(getBrightnes());
			placeSlider(lcd, watercolour, landcolour, tekstcolour, 40, 180);
			//setting = 0;
		}

	}
}

void basisschermSettings(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour){
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(60, 10, "SETTINGS", tekstcolour, watercolour, 2);
	setting = 1;

	placeButton(lcd, watercolour, landcolour, tekstcolour, "RESET SCORE",40,60);

	placeButton(lcd, watercolour, landcolour, tekstcolour, "", 40, 180);
	placeSlider(lcd, watercolour, landcolour, tekstcolour, 40, 180);

	terugButton(lcd, watercolour, landcolour, tekstcolour);

	do {
		touchScreenSettings(lcd, watercolour, landcolour, tekstcolour);
	} while (setting);
}
