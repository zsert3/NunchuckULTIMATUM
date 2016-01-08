//Gerard van Turennout


#include "highscores.h"
#include "eepromManager.h"

//ns = nieuw score
void scoreCalculator(int ns) {
	int score[5];
	int i;
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



void basisschermHighScores(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	//haal scores op uit EEPROM
	int score[] = { 0,0,0,0,0 };	
	getScore(score);
	int i = 4;
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(40, 10, "HIGHSCORES", tekstColour, watercolour, 2);

	char str[15];
	//schrijf scores weg als string en draw text
	while (i >= 0) {
		sprintf(str, "%d", score[i]);
		lcd.drawText(50 , 50 + (120 - (i * 30)), str, tekstColour, watercolour, 2);
		i--;
	}
}





