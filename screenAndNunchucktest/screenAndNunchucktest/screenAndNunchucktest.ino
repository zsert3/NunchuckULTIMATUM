//includes voor het scherm
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <SPI.h>


//avr includes
#include <Arduino.h>
#include <avr\io.h>
#include <avr\interrupt.h>
#include <Wire.h>


uint8_t nunchuck_buf[6];


int i;
int joyx;
int joyy;
MI0283QT9 lcd;
int vorigelocatieX;
int vorigelocatieY;
volatile uint8_t teller = 0;
volatile int seconden = 0;

double vermenigvuldigFactorX = (double)320 / (double)223;
double vermenigvuldigFactorY = (double)240 / (double)223;

ISR(TIMER2_OVF_vect)
{
	teller++;
	if (teller >= 31)
	{
		seconden++;
		teller = 0;
	}
}

int main()
{
	basics();
	LCDinit();
	nunchuckInit();
	timerSetup();

	while (1)
	{
		if (i > 50)
		{
			i = 0;
			nunchuckgetdata();

			joyx = vermenigvuldigFactorX * nunchuck_joyx();			// voor beter bereik op scherm
			joyy = vermenigvuldigFactorY *  (240 - nunchuck_joyy());
			if (vorigelocatieX != joyx || vorigelocatieY != joyy)
			{
				//lcd.fillCircle(vorigelocatieX, vorigelocatieY, 10, RGB(0,0,0));
				bootjeWeg(vorigelocatieX, vorigelocatieY, RGB(0, 0, 0));
			}
			//Serial.print("Joystick coordinaten: ");
			//Serial.print(joyx);
			//Serial.print(", ");
			//Serial.println(joyy);
			lcd.setOrientation(0);
			lcd.drawText(10, 10, "Joystick coordinaten: ", RGB(255, 255, 255), RGB(0, 0, 0), 1);
			lcd.drawText(15, 20, "X-as ", RGB(255, 255, 255), RGB(0, 0, 0), 1);
			lcd.drawText(100, 20, "Y-as ", RGB(255, 255, 255), RGB(0, 0, 0), 1);
			lcd.drawInteger(25, 30, joyx, DEC, RGB(255, 255, 255), RGB(0, 0, 0), 1);
			lcd.drawInteger(110, 30, joyy, DEC, RGB(255, 255, 255), RGB(0, 0, 0), 1);
			//lcd.drawPixel(joyx, joyy, RGB(0,255,0));
			//lcd.drawLine(joyx, 0, joyx, 320, RGB(0,255,0));
			//lcd.drawLine(0, joyy, 320, joyy, RGB(0,0,255));
			//lcd.fillCircle(joyx, joyy, 2, RGB(0,0,255)); // aanwijzer
			bootje(joyx, joyy);
			vorigelocatieX = joyx;
			vorigelocatieY = joyy;
			lcd.drawInteger(250, 200, seconden, DEC, RGB(255, 255, 255), RGB(0, 0, 0), 1); //dit is de timer

		}
		i++;
		delay(1);
		//Serial.println(teller);
	}

}

void bootje(uint_least16_t x, uint_least16_t y)
{
	lcd.drawRect(x - 5, y - 2, 11, 15, RGB(139, 69, 19));
	lcd.drawRect(x - 4, y - 1, 9, 13, RGB(139, 35, 35));
	lcd.drawLine(x - 3, y, x - 3, y + 10, RGB(139, 69, 19));
	lcd.drawLine(x - 2, y, x - 2, y + 10, RGB(139, 35, 35));
	lcd.drawLine(x - 1, y, x - 1, y + 10, RGB(139, 69, 19));
	lcd.drawLine(x, y, x, y + 10, RGB(139, 35, 35));
	lcd.drawLine(x + 1, y, x + 1, y + 10, RGB(139, 69, 19));
	lcd.drawLine(x + 2, y, x + 2, y + 10, RGB(139, 35, 35));
	lcd.drawLine(x + 3, y, x + 3, y + 10, RGB(139, 69, 19));
}


void bootjeWeg(uint_least16_t x, uint_least16_t y, uint_least16_t color)
{
	lcd.drawRect(x - 5, y - 2, 11, 15, color);
	lcd.drawRect(x - 4, y - 1, 9, 13, color);
	lcd.drawLine(x - 3, y, x - 3, y + 10, color);
	lcd.drawLine(x - 2, y, x - 2, y + 10, color);
	lcd.drawLine(x - 1, y, x - 1, y + 10, color);
	lcd.drawLine(x, y, x, y + 10, color);
	lcd.drawLine(x + 1, y, x + 1, y + 10, color);
	lcd.drawLine(x + 2, y, x + 2, y + 10, color);
	lcd.drawLine(x + 3, y, x + 3, y + 10, color);
}

void timerSetup()
{
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
	TIMSK2 |= (1 << TOIE2);
	TCNT2 = 0;
	sei();
}

void nunchuckInit()
{
	nunchuck_init();
	Serial.println("Nunchuck is ready\n");
}

void basics()
{
	init();
	Serial.begin(19200);
	//Serial.println(vermenigvuldigFactorX);
	//Serial.println(vermenigvuldigFactorY);
}

void LCDinit()
{
	lcd.begin();
	lcd.fillScreen(RGB(0, 0, 0));
}

void nunchuck_init()
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

int nunchuckgetdata()
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

int nunchuck_joyx()
{
	return nunchuck_buf[0];
}

int nunchuck_joyy()
{
	return nunchuck_buf[1];
}

char nunchuck_decode_byte(char x)
{
	x = (x ^ 0x17) + 0x17;
	return x;
}

void nunchuck_send_request()
{
	Wire.beginTransmission(0x52);// transmit to device 0x52
#if (ARDUINO >= 100)
	Wire.write((uint8_t)0x00);// sends one byte
#else
	Wire.send((uint8_t)0x00);// sends one byte
#endif
	Wire.endTransmission();// stop transmitting
}