
#include "score.h"

int score;

//score resetten
void resetScore() {
	score = 0;
}

//score tekenen
void drawScore(MI0283QT9 lcd) {
	lcd.drawText(17, 10, "Score", RGB(0, 0, 0), RGB(100, 149, 237), 1);
	lcd.drawInteger(17, 20, score, DEC, RGB(0, 0, 0), RGB(100, 149, 237), 1);
}

//score met 1 verhogen
void increaseScore() {
	score++;
}

//score teruggeven
int getScore() {
	return score;
}

