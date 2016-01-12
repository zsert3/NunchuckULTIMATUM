// 
// 
// 
#include "settings.h"

//Gerard van Turennout

int setting = 0;

void placeButton(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour, char *text, int lcX, int lcY, int buttonsizeY) {
	int arrSize = strlen(text);
	//toegevoegt als eventueele meeg gegeven variable
	int buttonsizeX = 160;
	lcd.fillRoundRect(lcX, lcY, buttonsizeX, buttonsizeY, 10, landcolour);
	//a letter is 4x4 pixels
	lcd.drawText(lcX + (buttonsizeX/2) - (arrSize * 4), lcY + (buttonsizeY/2) - 4, text, tekstColour, landcolour, 1);
}



void placeSlider(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour, int lcX, int lcY,int prevBrightness) {
	
	int slidersizeX = 160;
	int slidersizeY = 40;
	//slider bar dimentions
	int barthickness = slidersizeY / 8;
	int barLength = slidersizeX - 20;
	//slider bar location 
	int barpositionY = lcY + (slidersizeY / 2) - (barthickness / 2);
	
	//nob size
	int nobsize = slidersizeY / 2;
	
	//nob position calculation on to the bar based on the brightness
	int maxBrightnes = getMaxbrightnes();
	int currentBrightness = getBrightnes();
	
	//removes previous knob
	if(prevBrightness){
		//calculates pixels removed from left border based on maximum brightness compared to total bar length
		int prevSize = barLength /(900.0 / prevBrightness);
		//removes knob
		//roplaces previous knob location with background color
		lcd.fillRect(lcX+ (slidersizeX - barLength)/2+ prevSize, lcY + (nobsize+ barthickness) / 2, nobsize/2, nobsize,  landcolour);
		//redraws bar
	}
	else{
		//draws back ground
		lcd.fillRect(lcX, lcY+(slidersizeY/4), slidersizeX, slidersizeY/2+ barthickness, landcolour);
		//draw slider rect
		lcd.drawRect(lcX+(slidersizeX-barLength)/2-1, lcY + (nobsize + barthickness) / 2-1, barLength+3, nobsize+2, tekstColour);
	}
	//draws nob
	//calculates pixels removed from left border based on maximum brightness compared to total bar length
	int size = barLength /(900.0 / currentBrightness);
	lcd.fillRect(lcX+ (slidersizeX - barLength)/2+ size, lcY + (nobsize+ barthickness) / 2, nobsize/2, nobsize,  tekstColour);
	
}

// Here we check if the touchscreen is pushed
void touchScreenSettings(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour){ 
	if (lcd.touchRead()){
		int pushX = lcd.touchX();
		int pushY = lcd.touchY();
		int prevBrightness;
		//button touch sensors
		
		
		if (pushX >= 40  && pushX <= 200 && pushY >= 60 && pushY <= 60 + 20){
			resetHighscore();
			lcd.drawText(70, 75, "SCORE GERESET", tekstcolour, landcolour, 1);
		} 

		//brightness slider
		if (pushX >= 40 && pushX <= 200 && pushY >= 180 && pushY <= 180 + 40) {
			//responds but is not part of the true size of the slider
			if (pushX > 200 - 10) {
				pushX = 190;
			}
			//brightness is set to the bar press location - bar positions X and Y
			prevBrightness = getBrightnes();
			setBrightnes(getMaxbrightnes() / ((200.0-40.0)/(pushX -40)), lcd);
			
			placeSlider(lcd, watercolour, landcolour, tekstcolour, 40, 180, prevBrightness);
		}

		//back button
		if (pushX >= 40 && pushX <= 200 && pushY >= 295 && pushY <= 320) {
			lcd.fillRect(10, 290, 220, 30, watercolour);
			lcd.drawText(100, 300, "BACK", tekstcolour, watercolour, 1);
			setting = 0;
			drawMenuScreen(lcd, watercolour, landcolour, tekstcolour);
			//setpushed(0);
		}
	}
}
//draws settings menu
void basicscreenSettings(MI0283QT9 lcd, int watercolour, int landcolour, int tekstcolour){
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(60, 10, "SETTINGS", tekstcolour, watercolour, 2);
	//turns on the loop
	setting = 1;

	placeButton(lcd, watercolour, landcolour, tekstcolour, "RESET SCORE",40,60, 40);
	placeButton(lcd, watercolour, landcolour, tekstcolour, "", 40, 160, 60);
	//sets text above slider
	lcd.drawText(80, 170, "HELDERHEID", tekstcolour, landcolour, 1);
	placeSlider(lcd, watercolour, landcolour, tekstcolour, 40, 180,0);
	//draws back button from mainMenu.ccp
	backButton(lcd, watercolour, landcolour, tekstcolour);

	do {
		touchScreenSettings(lcd, watercolour, landcolour, tekstcolour);
	} while (setting);
}
