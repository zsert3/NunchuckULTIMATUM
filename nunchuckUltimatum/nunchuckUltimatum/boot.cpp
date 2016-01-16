
#include "boot.h"

//this function draws the boat dynamic on the LCD panel
void drawboot(MI0283QT9 lcd, int x, int y) {
	uint8_t breete = 15;
	uint8_t lengte = 25;
	uint8_t stapgroote = 3;
	uint8_t stap = 1;
	lcd.drawRect(x, y, breete, lengte, RGB(0, 0, 0));
	lcd.fillRect(x + 1, y + 1, breete - 2, lengte - 2, RGB(156, 102, 31));
	int mastPositie = -2;
	lcd.fillCircle(x + breete / 2, y + lengte / 2 + mastPositie, (breete + lengte) / 12, RGB(82, 82, 82));
	lcd.fillTriangle(x, y + lengte / 2 - (breete + lengte) / 12 + mastPositie, x + breete - 1, y + lengte / 2 - (breete + lengte) / 12 + mastPositie, x + breete / 2, y - 2 + lengte / 2 - (breete + lengte) / 12 + mastPositie, RGB(255, 255, 255));
}