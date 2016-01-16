//Gerard van Turennout


#include "highscores.h"


//ns = new score
void scoreCalculator(int ns) {
	int score[5];
	uint8_t i;
	getScore(score);
	//if it is higher then the lowest score action must be taken
	if (ns > score[0]) {
		i = 0;
		while (i < 4) {
			i++;
			//if it is higher then the next score this score moves one step down and we move towards the next score
			if (ns > score[i]) {
				score[i - 1] = score[i];
			}
			else {
				// if they are equal or lower we stop and replace the current score
				score[i - 1] = ns;
				//to end the loop
				i = 4;
			}
		}
		//if it is higher then the highest score replace this one
		if (ns > score[i]) {
			score[i] = ns;
		}
		//store score in EEPROM
		setScore(score);
	}
}



void basicscreenHighScores(MI0283QT9 lcd, int16_t waterColour, int16_t textColour)
{
	//get scores from EEPROM
	int score[] = { 0,0,0,0,0 };	
	getScore(score);
	int8_t i = 4;
	lcd.fillRect(10, 0, 220, 320, waterColour);
	lcd.drawText(40, 10, "HIGHSCORES", textColour, waterColour, 2);

	char str[15];
	//write score as a string and draw it as a text
	while (i >= 0) {
		sprintf(str, "%d", score[i]);
		lcd.drawText(50 , 50 + (120 - (i * 30)), str, textColour, waterColour, 2);
		i--;
	}
}





