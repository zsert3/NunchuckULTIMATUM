//Gerard van Turennout
#include "eepromManager.h"


//the EEPROM should only be accesed through this struct else things could be overwritten
typedef struct s_eeprom {
	int	brightnes;
	int score[5];
} SAVED_DATA ;
SAVED_DATA EEMEM eeprom = { 0 };


// gets everything from the EEPROM
void getAll(SAVED_DATA *data) {
	// Read the data from eeprom into the 'temp' version in memory
	eeprom_read_block(data, &eeprom, sizeof(SAVED_DATA));
}


void getScore(int score[5]) {
	SAVED_DATA data;
	getAll(&data);
	score[0] = data.score[0];
	score[1] = data.score[1];
	score[2] = data.score[2];
	score[3] = data.score[3];
	score[4] = data.score[4];
}

void setScore(int score[5]) {
	// write score to EEPROM with the struct
	eeprom_write_block(score, &eeprom.score, sizeof(SAVED_DATA));
	}
void resetHighscore() {
	int score[] = { 0,0,0,0,0 };
	eeprom_write_block(score, &eeprom.score, sizeof(SAVED_DATA));
}


int getBrightnes() {
	SAVED_DATA data;
	getAll(&data);
	return data.brightnes;
}
int getMaxbrightnes() {
	//number for calculation purposes
	return 900;
}

void setBrightnes(int brightnes, MI0283QT9 lcd) {
	SAVED_DATA data;
	getAll(&data);
	//to prevent overwritting we first get all the data from the EEPROM and adjust what is changed then send it back
	data.brightnes = brightnes;
	eeprom_write_block(&data, &eeprom, sizeof(SAVED_DATA));
	lcd.led(brightnes * 0.111 + 5);
}