
#include "config.h"

void config_init() {

	//Obsluga INT0, INT1, T0, T1 
	/*
	GICR |= (1<<INT0); //|(1<<INT1); //wlaczenie zewn przerwania na INT0 i INT1 
	MCUCR=0; 
	//MCUCR |= (1<<ISC01); //opadające zbocze 
	MCUCR |= (1<<ISC11)|(1<<ISC10)|(1<<ISC01)|~(1<<ISC00); //narastajace zbocze 
	*/

	PORTC = 0xFF;
	DDRC =0x00;

	PORTB = 0x00;
	DDRB =0xFF;


	// timer interrupt
	TCCR1B |= (1 << WGM12); // Ustawia timer w tryb CTC
	OCR1A = 46875; // Ustawia wartość pożądaną na 1Hz dla preskalera 64
	TCCR1B |= (1 << CS12) ; // Ustawia timer z preskalerem Fcpu/64
	TIMSK |= (1 << OCIE1A); // Zezwolenie na przerwania dla CTC

	// uart
	UBRRH = (uint8_t)( UART_BAUDRATE>>8 );
	UBRRL = (uint8_t) UART_BAUDRATE;
	UCSRB = (1<<RXEN)|(1<<TXEN); 

}

