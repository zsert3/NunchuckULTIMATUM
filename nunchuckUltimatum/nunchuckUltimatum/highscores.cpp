#include "highscores.h"


typedef struct s_eeprom {
	int score[5];
} SAVED_DATA;
SAVED_DATA EEMEM eeprom[] = { 0,0,0,0,0 };


void restore(int *score) {
	// Read the data from eeprom into the 'temp' version in memory
	eeprom_read_block(score, &eeprom, sizeof(SAVED_DATA));
}

void save(int *score) {
	// Gather all variables to be saved into the structure
	eeprom_write_block(score, &eeprom, sizeof(SAVED_DATA));
}


//ns = nieuw score
void scoreCalculator(int ns) {
	int score[5];
	int i;
	restore(score);
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
		save(score);
	}
}



void basisschermHighScores(MI0283QT9 lcd, int watercolour, int landcolour, int tekstColour)
{
	int score[] = { 0,0,0,0,0 };	
	restore(score);
	
	int i = 4;
	lcd.fillRect(10, 0, 220, 320, watercolour);
	lcd.drawText(40, 10, "HIGHSCORES", tekstColour, watercolour, 2);

	char str[15];
	
	while (i >= 0) {
		sprintf(str, "%d", score[i]);
		lcd.drawText(50 , 50 + (120 - (i * 30)), str, tekstColour, watercolour, 2);
		i--;
	}
}





