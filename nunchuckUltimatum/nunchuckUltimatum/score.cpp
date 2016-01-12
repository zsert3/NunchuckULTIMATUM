
#include "score.h"

int score;

void resetScore() {
	score = 0;
}

void drawScore(MI0283QT9 lcd, int watercolour) {
	lcd.drawText(17, 10, "Score", RGB(0, 0, 0), watercolour, 1);
	lcd.drawInteger(17, 20, score, DEC, RGB(0, 0, 0), watercolour, 1);
}

void increaseScore() {
	score++;
}

int getScore() {
	return score;
}

