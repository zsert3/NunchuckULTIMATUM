// 
// 
// 

#include "nunchuckData.h"
#include <Wire.h>

uint8_t nunchuck_buf[6];

void nunchuckInit(void)
{
	Wire.begin();                // join i2c bus as master
	Wire.beginTransmission(0x52);// transmit to device 0x52
#if (ARDUINO >= 100)
	Wire.write((uint8_t)0x40);// sends memory address
	Wire.write((uint8_t)0x00);// sends sent a zero.
#else
	Wire.send((uint8_t)0x40);// sends memory address
	Wire.send((uint8_t)0x00);// sends sent a zero.
#endif
	Wire.endTransmission();// stop transmitting
}

void nunchuckGetData(void)
{
	int cnt = 0;
	Wire.requestFrom(0x52, 6);// request data from nunchuck
	while (Wire.available()) {
		// receive byte as an integer
#if (ARDUINO >= 100)
		nunchuck_buf[cnt] = nunchuck_decode_byte(Wire.read());
#else
		nunchuck_buf[cnt] = nunchuck_decode_byte(Wire.receive());
#endif
		cnt++;
	}
	nunchuck_send_request();  // send request for next data payload
							  // If we recieved the 6 bytes, then go print them
	if (cnt >= 5) {
		return 1;   // success
	}
	return 0; //failure
}

void nunchuckSendRequest(void)
{
	Wire.beginTransmission(0x52);// transmit to device 0x52
#if (ARDUINO >= 100)
	Wire.write((uint8_t)0x00);// sends one byte
#else
	Wire.send((uint8_t)0x00);// sends one byte
#endif
	Wire.endTransmission();// stop transmitting
}

int nunchuckGetJoyX(void)
{
	return nunchuck_buf[0];
}

int nunchuckGetJoyY(void)
{
	return nunchuck_buf[1];
}
char nunchuckDecodeByte(char x)
{
	x = (x ^ 0x17) + 0x17;
	return x;
}

