// nunchuckData.h

#ifndef _NUNCHUCKDATA_h
#define _NUNCHUCKDATA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <Wire\Wire.h>

void nunchuckInit();
int nunchuckGetData();
void nunchuckSendRequest();
int nunchuckGetJoyX();
int nunchuckGetJoyY();
int cbuttonPushed();
char nunchuckDecodeByte(char x);

#endif
