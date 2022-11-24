/*
 * 7 SEGMENTO-2.c
 *
 * Created: 11/11/2022 11:48:56 p. m.
 * Author : Martin
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

const char Display[16] = {
	0b00111111,
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01101111,
	0b01110111,
	0b01111100,
	0b00111001,
	0b01011110,
	0b01111001,
	0b01110001
};


int main()
{
	DDRB &= ~ 0b11111110;
	DDRD |=  0b01111111;
	int a = 0;

	while (1)
	{
		PORTB = 0xFF;
		PORTC = 0xFF;
		PORTD = Display[a];
		_delay_ms(100);

		if ((PINB & (1 << PORTB1)) == 0)
		{
			a++;
			_delay_ms(200);
			if (a == 16)
			a = 0;
		}
		if ((PINC & (1 << PORTC4)) == 0)
		{
			a--;
			_delay_ms(200);
			if (a < 0)
			a = 0;
		}
	}
}

