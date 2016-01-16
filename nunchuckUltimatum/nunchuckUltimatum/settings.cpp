// 
// 
// 
#include "settings.h"
int8_t setting = 0;

//Gerard van Turennout




void placeSlider(MI0283QT9 lcd, int16_t landColour, int16_t textColour, int lcX, int lcY,int prevBrightness) {
	
	int sliderSizeX = 160;
	int sliderSizeY = 40;
	//slider bar dimentions
	int barThickness = sliderSizeY / 8;
	int barLength = sliderSizeX - 20;
	//slider bar location 
	int barPositionY = lcY + (sliderSizeY / 2) - (barThickness / 2);
	
	//nob size
	int nobSize = sliderSizeY / 2;
	
	//nob position calculation on to the bar based on the brightness
	int maxBrightnes = getMaxbrightnes();
	int currentBrightness = getBrightnes();
	
	//removes previous knob
	if(prevBrightness){
		//calculates pixels removed from left border based on maximum brightness compared to total bar length
		int prevSize = barLength /(900.0 / prevBrightness);
		//removes knob
		//roplaces previous knob location with background color
		lcd.fillRect(lcX+ (sliderSizeX - barLength)/2+ prevSize, lcY + (nobSize+ barThickness) / 2, nobSize/2, nobSize,  landColour);
		//redraws bar
	}
	else{
		//draws back ground
		lcd.fillRect(lcX, lcY+(sliderSizeY/4), sliderSizeX, sliderSizeY/2+ barThickness, landColour);
		//draw slider rect
		lcd.drawRect(lcX+(sliderSizeX-barLength)/2-1, lcY + (nobSize + barThickness) / 2-1, barLength+3, nobSize+2, textColour);
	}
	//draws nob
	//calculates pixels removed from left border based on maximum brightness compared to total bar length
	int size = barLength /(900.0 / currentBrightness);
	lcd.fillRect(lcX+ (sliderSizeX - barLength)/2+ size, lcY + (nobSize+ barThickness) / 2, nobSize/2, nobSize,  textColour);
	
}

// Here we check if the touchscreen is pushed
void touchScreenSettings(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour){ 
	if (lcd.touchRead()){
		int16_t pushX = lcd.touchX();
		int16_t pushY = lcd.touchY();
		int prevBrightness;
		//button touch sensors
		
		
		if (pushX >= getXValueButtons()  && pushX <= 200 && pushY >= getButton1X() && pushY <= 80){
			resetHighscore();
			lcd.drawText(70, 75, "SCORE GERESET", textColour, landColour, 1);
		} 

		//brightness slider
		if (pushX >= getXValueButtons() && pushX <= 200 && pushY >= 180 && pushY <= 220) {
			//responds but is not part of the true size of the slider
			if (pushX > 200 - 10) {
				pushX = 190;
			}
			//brightness is set to the bar press location - bar positions X and Y
			prevBrightness = getBrightnes();
			setBrightnes(getMaxbrightnes() / ((200.0-40.0)/(pushX -40)), lcd);
			
			placeSlider(lcd, landColour, textColour, 40, 180, prevBrightness);
		}

		//back button
		if (pushX >= getXValueButtons() && pushX <= 200 && pushY >= 295 && pushY <= 320) {
			lcd.fillRect(10, 290, 220, 30, waterColour);
			lcd.drawText(100, 300, "BACK", textColour, waterColour, 1);
			setting = 0;
			drawMenuScreen(lcd, waterColour, landColour, textColour);
			//setPushed(0);
		}
	}
}
//draws settings menu
void basicScreenSettings(MI0283QT9 lcd, int16_t waterColour, int16_t landColour, int16_t textColour){
	lcd.fillRect(10, 0, 220, 320, waterColour);
	lcd.drawText(60, 10, "SETTINGS", textColour, waterColour, 2);
	//turns on the loop
	setting = 1;

	placeButton(lcd, landColour, textColour, "RESET SCORE", getXValueButtons(), getButton1X(), getWidthButtons(), getButtonLength());
	placeButton(lcd, landColour, textColour, "", getXValueButtons(), 160, 60, getButtonLength());
	//sets text above slider
	lcd.drawText(80, 170, "HELDERHEID", textColour, landColour, 1);
	placeSlider(lcd, landColour, textColour, getXValueButtons(), 180,0);
	//draws back button from mainMenu.ccp
	placeButton(lcd, landColour, textColour, "BACK", 0, 290, 30, 240);

	do {
		touchScreenSettings(lcd, waterColour, landColour, textColour);
	} while (setting);
}
