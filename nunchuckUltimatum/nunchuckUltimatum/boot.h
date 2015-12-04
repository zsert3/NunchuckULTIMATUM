// boot.h

#ifndef _BOOT_h
#define _BOOT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MI0283QT9\MI0283QT9.h>
void tekenboot(int x, int y);
void resetboat(int obstacles[], int blocationx, int blocationy);

#endif

