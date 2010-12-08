#include <stdio.h> 
#include <avr/io.h> 

int uart_putchar(char c) 
{ 
loop_until_bit_is_set(USR, UDRE); 
UDR = c; 
return 0; 
} 

int main(void) 
{ 
UBRR = 0x17;  //0x17;                               
UCR = (1<<RXCIE)|(1<<TXEN)|(1<<RXEN);          
fdevopen(uart_putchar,NULL, 0); 
unsigned char x; 
x=123; 
printf("test"); 
printf("%d",x); 
} 

