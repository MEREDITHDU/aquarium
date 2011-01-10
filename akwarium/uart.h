#ifndef _UART
#define _UART

#define CHAR 0
#define INT  1
#define LONG 2

#define UART_NL {uart_sendByte(0x0d); uart_sendByte(0x0a);}

unsigned char 	uart_receiveByte(void);
void 		uart_sendByte(unsigned char);
void 		uart_sendHex( unsigned char dataType, unsigned long data );
void 		uart_send(char*);


#endif
