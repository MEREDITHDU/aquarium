#include <avr/io.h>
#include <avr/common.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>

#include "config.h"

#include <util/delay.h> 
#include <stdlib.h>

#include "uart.h"
#include "temp.h" 
#include "lcd.h" 
#include "servo.h"

//uint8_t eeval EEPROM_SECTION = 2;

int v = 1;
ISR(TIMER1_COMPA_vect){    // przerwanie INT0 po przepełnieniu TIMER0 

		if((v++ % 2) == 0) {
			LED2_ON
		}
		else {
			LED2_OFF
		}

		transmitString("x");

} 

//obsługa przerwania INT0 
ISR(INT0_vect) 
{
	
}



int main(void) {

	init_uc();

	lcd_init();

	write_command(LINE1);
	write_text("dupa");
	
	while(1) {

		int i = 0;
		for(i=0; i< 10; i++) _delay_ms(100);

		//char x = receiveByte();
		//transmitByte(x+48);
	}
	return 1;
}


