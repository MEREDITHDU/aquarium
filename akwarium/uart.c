#include <avr/io.h>
#include <avr/pgmspace.h>

#include "uart.h"

unsigned char uart_receiveByte( void ) {
	unsigned char data, status;
	while(!(UCSRA & (1<<RXC))); 	// Wait for incomming data
	
	status = UCSRA;
	data = UDR;
	
	return(data);
}

void uart_sendByte( unsigned char data ) {
	while ( !(UCSRA & (1<<UDRE)) ) ;        /* Wait for empty transmit buffer */
	UDR = data; 			        /* Start transmition */
}

void uart_sendHex( unsigned char dataType, unsigned long data )
{
	unsigned char count, i, temp;
	char dataString[] = "0x        ";

	if (dataType == CHAR) count = 2;
	if (dataType == INT) count = 4;
	if (dataType == LONG) count = 8;

	for(i=count; i>0; i--)
	{
		temp = data % 16;
		if((temp>=0) && (temp<10)) dataString [i+1] = temp + 0x30;
		else dataString [i+1] = (temp - 10) + 0x41;

		data = data/16;
	}

	uart_send(dataString);
}

/*
void uart_sendString_F(char* string)
{
	while (pgm_read_byte(&(*string)))
		transmitByte(pgm_read_byte(&(*string++)));
	TX_NL;
}
*/

void uart_send(char* string) {
	while (*string)
		uart_sendByte(*string++);
}

