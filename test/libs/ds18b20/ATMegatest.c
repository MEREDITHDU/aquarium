//  ATMega8 LCD Driver
//
//  (C) 2009 Radu Motisan , radu.motisan@gmail.com
//  www.pocketmagic.net
//  All rights reserved.
//
//  test.c: sample test for the HD44780 LCD functions
//  For more details visit the website.



#include "lcd.h"
#include <avr/pgmspace.h>

#include "therm_ds18b20.h"

char ch = 0;

int main()
{
	int i=0;
	lcd_init();
	
	DDRB |= 1;

	while(1)
	{
		i = (i+1)%10;
		//lcd_clrscr();
		lcd_home();

		
		char x[20] = {0};
		therm_read_temperature(x);
		lcd_string2("pocketmagic.net\nT=%s [%d]",x, i);

		for (int i=0;i<5;i++) //some delay
			_auxDelay(1000000);
		if (i%2)
		{
			PORTB |= 1;
		}
		else
		{
			PORTB &= 0xFE;
		}
	
	}
	return 0;
}
