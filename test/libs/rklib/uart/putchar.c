#include "../uart.h"

int UART_putchar(char c)    // wysy�a znak c na UART
{
#ifdef UART_DE_PORT
//  cbi(_UCR_,RXEN);			// zablokuj odbior 
  sbi(UART_DE_PORT,UART_DE_BIT);	// odblokuj nadajnik RS485
#endif
#ifdef UART_BUF_SIZE  // je�eli UART ma pracowa� na przerwaniach

  while((UART_BUF_SIZE - (UART_t_in - UART_t_out)) <= 2);  // Wait...
  // Add data to the transmit buffer, enable TXCIE
  UART_tbuf[UART_t_in & UART_TMASK] = c;
  UART_t_in++;
  sbi(_UCR_, UDRIE);      // w��cz przerwanie od pustego bufora

#else  // je�li UART pracuje bez u�ycia przerwa�
  _UDR_ = c;        // wpisz c do rejestru UDR
  loop_until_bit_is_set(_USR_,TXC);  // czekaj na zako�czenie transmisji
  sbi(_USR_,TXC);      // ustaw bit TXC w rej. USR
/*
  loop_until_bit_is_set(_USR_, UDRE);
  _UDR_=c;
*/
#ifdef UART_DE_PORT
  cbi(UART_DE_PORT,UART_DE_BIT);	// zablokuj nadajnik  RS485
//  sbi(_UCR_,RXEN);			// odblokuj odbior 
#endif

#endif  //UART_BUF_SIZE
  return 0;
}


