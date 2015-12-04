// 
// 
// 

#include "boot.h"

void tekenboot(int x, int y) {
	uint8_t breete = 15;
	uint8_t lengte = 25;
	uint8_t stapgroote = 3;
	uint8_t stap = 1;
	lcd.drawRect(x, y, breete, lengte, RGB(0, 0, 0));
	//lcd.drawTriangle(x, y, x + breete - 1, y, x + breete / 2, y - 5, RGB(0, 0, 0));
	lcd.fillRect(x + 1, y + 1, breete - 2, lengte - 2, RGB(156, 102, 31));
	//lcd.fillTriangle(x, y + 1, x + breete - 1, y + 1, x + breete / 2, y - 5, RGB(156, 102, 31));
	int mastPositie = -2;
	lcd.fillCircle(x + breete / 2, y + lengte / 2 + mastPositie, (breete + lengte) / 12, RGB(82, 82, 82));
	lcd.fillTriangle(x, y + lengte / 2 - (breete + lengte) / 12 + mastPositie, x + breete - 1, y + lengte / 2 - (breete + lengte) / 12 + mastPositie, x + breete / 2, y - 2 + lengte / 2 - (breete + lengte) / 12 + mastPositie, RGB(255, 255, 255));
}

void resetboat(int obstacles[], int blocationx, int blocationy) {
	memset(obstacles, 0, sizeof(obstacles));
	lcd.fillRect(10, 0, 220, 320, RGB(100, 149, 237));
	lcd.fillRect(0, 0, 10, 320, RGB(61, 145, 64));
	lcd.fillRect(230, 0, 10, 320, RGB(61, 145, 64));
	blocationx = 110;
	blocationy = 270;
}
