// nunchuckData.h

#ifndef _NUNCHUCKDATA_h
#define _NUNCHUCKDATA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
void nunchuckInit(void);
void nunchuckGetData(void);
void nunchuckSendRequest(void);
int nunchuckGetJoyX(void);
int nunchuckGetJoyY(void);
char nunchuckDecodeByte(char x);

#endif//nunchuckData.h

