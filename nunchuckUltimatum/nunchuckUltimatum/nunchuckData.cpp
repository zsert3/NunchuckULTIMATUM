// 
// 
// 

#include "nunchuckData.h"


uint8_t nunchuck_buf[6];

void nunchuckInit()
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

int nunchuckGetData()
{
	int cnt = 0;
	Wire.requestFrom(0x52, 6);// request data from nunchuck
	while (Wire.available()) {
		// receive byte as an integer
#if (ARDUINO >= 100)
		nunchuck_buf[cnt] = nunchuckDecodeByte(Wire.read());
#else
		nunchuck_buf[cnt] = nunchuck_decode_byte(Wire.receive());
#endif
		cnt++;
	}
	nunchuckSendRequest();  // send request for next data payload
							  // If we recieved the 6 bytes, then go print them
	if (cnt >= 5) {
		return 1;   // success
	}
	return 0; //failure
}

void nunchuckSendRequest()
{
	Wire.beginTransmission(0x52);// transmit to device 0x52
#if (ARDUINO >= 100)
	Wire.write((uint8_t)0x00);// sends one byte
#else
	Wire.send((uint8_t)0x00);// sends one byte
#endif
	Wire.endTransmission();// stop transmitting
}

int nunchuckGetJoyX()
{
	return nunchuck_buf[0];
}

int nunchuckGetJoyY()
{
	return nunchuck_buf[1];
}

int cbuttonPushed()
{
	nunchuckGetData();  // Reviving the state of the C Button of the nunchuck
	int c_Button = nunchuck_buf[5];

	if ((c_Button >> 1) & 1)  // determing the state of the C button
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char nunchuckDecodeByte(char x)
{
	x = (x ^ 0x17) + 0x17;
	return x;
}

