#include <avr/io.h>
#include <avr/common.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>

#include "config.h"

#include <util/delay.h> 
#include <stdlib.h>

#include "uart.h"
#include "temp2.h" 
#include "lcd.h" 

#include "servo.h"

int sec = 0, 
    min = 0, 
    hour = 0,
    day = 0,
    month = 0,
    year = 0;

int inc;

void uart_init(const int baudrate) ;
void init_devices(void) ;

//uint8_t eeval EEPROM_SECTION = 2;

ISR(TIMER1_COMPA_vect){    // przerwanie INT0 po przepełnieniu TIMER0 

	sei();
	char temp_buffer[20], time_buffer[20];

	sec++;
	if(sec == 60)  sec = 0, inc = 1;

	if(inc) min++, inc = 0;
	if(min == 60)  min = 0, inc = 1;

	if(inc) hour++, inc = 0;
	if(hour == 24)  hour = 0, inc = 1;

	sprintf(time_buffer, "%02d:%02d:%02d", hour, min, sec);

	write_command(LINE3);
	write_text(time_buffer);

	therm_read_temperature(temp_buffer);
	write_command(LINE4);
	write_text(temp_buffer);

	transmitString("dupa");
} 

//obsługa przerwania INT0 
int v = 1;
ISR(INT0_vect) 
{
	int i;
	//for(i=0;i<v;i++) write_text("x");

	//for(i=0; i<3; i++) {
	//	_delay_ms(200);
	//}
	//v++;

	write_command(LINE2);
	write_text("                    ");

	write_command(LINE2);
	write_text("int");
/*
	DDRD |= _BV(PD2);
	PORTD |= _BV(PD2);

	DDRD  &= ~_BV(PD6);
	PORTD &= ~_BV(PD6);
	DDRD  &= ~_BV(PD7);
	PORTD &= ~_BV(PD7);
*/
//	write_char( (PIND & (1<<PD6)) + 48);
//	write_char( (PIND & (1<<PD7)) + 48);

//	if( (PIND & (1<<PD6)) == 0) write_text("btn1");
//	if( (PIND & (1<<PD7)) == 0) write_text("btn2");
/*
	DDRD  &= ~_BV(PD2);
	PORTD &= ~_BV(PD2);

	DDRD  |= _BV(PD6);
	PORTD |= _BV(PD6);
	DDRD  |= _BV(PD7);
	PORTD |= _BV(PD7);
*/
}



int main(void) {

	init_devices();
	char buf[256];

	//lcd
	DDRC = 0xFF; PORTC = 0xFF;

	DDRB &= ~(_BV(PB2));

	//DDRD &= ~(_BV(PD2));
	//PORTD |= _BV(PD2);

	DDRD  &= ~_BV(PD2);
	PORTD |= _BV(PD2);

	/*
	DDRD  &= ~_BV(PD6);
	PORTD &= ~_BV(PD6);
	DDRD  &= ~_BV(PD7);
	PORTD &= ~_BV(PD7);
	*/

	DDRD  |= _BV(PD6);
	PORTD &= ~_BV(PD6);
	DDRD  |= _BV(PD7);
	PORTD &= ~_BV(PD7);

	

	int val, i;
	while(1) {

/*
		if(bit_is_clear(PINB, PB2)) {
			sec = min = hour = 0;
			while(bit_is_clear(PINB,PB2)) {}
		}
*/
		val = receiveByte();
		transmitByte( val + 48 );

		switch(val) {
			case 'q':

				for(i=0; i<25;i++) {
					servo_move(1);
					_delay_ms(50);
				}
				break;
			case 'w':

				//eprom_write_byte(&eeval, 'd');
				break;
		}
		TX_NL;
		
	}
	return 1;
}

void uart_init(const int baudrate) {
	UBRRH = (uint8_t)( baudrate>>8 );
	UBRRL = (uint8_t) baudrate;
	UCSRB = (1<<RXEN)|(1<<TXEN); 
}

void init_devices(void) {
	cli();
	uart_init(UART_BAUDRATE);

	//Obsluga INT0, INT1, T0, T1 
	GICR |= (1<<INT0); //|(1<<INT1); //wlaczenie zewn przerwania na INT0 i INT1 
	MCUCR=0; 
	//MCUCR |= (1<<ISC01); //opadające zbocze 
	MCUCR |= (1<<ISC11)|(1<<ISC10)|(1<<ISC01)|~(1<<ISC00); //narastajace zbocze 

	// timer interrupt
	TCCR1B |= (1 << WGM12); // Ustawia timer w tryb CTC
	OCR1A = 46875; // Ustawia wartość pożądaną na 1Hz dla preskalera 64
	TCCR1B |= (1 << CS12) ; // Ustawia timer z preskalerem Fcpu/64
	TIMSK |= (1 << OCIE1A); // Zezwolenie na przerwania dla CTC
	sei(); // Zezwolenie globalne na przerwania
}

