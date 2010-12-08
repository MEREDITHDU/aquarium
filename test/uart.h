#ifndef _UART
#define _UART

#define CHAR 0
#define INT  1
#define LONG 2

#define TX_NL {transmitByte(0x0d); transmitByte(0x0a);}
//#define TX_NL {transmitByte(0x0d);}

//void init_uart(const int);
unsigned char receiveByte(void);
void transmitByte(unsigned char);
void transmitString_F(char*);
void transmitString(char*);
void transmitHex( unsigned char dataType, unsigned long data );


#endif
