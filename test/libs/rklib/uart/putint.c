#include "../uart.h"
#include <stdlib.h>

void UART_putint(int value, u08 radix)	// wysy�a na port szeregowy tekst 
					// przedtawiaj�cy value z podstaw� radix
{
  char string[17];			// bufor na wynik funkcji itoa
  itoa(value, string, radix);		// konwersja value na ASCII
  UART_putstr(string);			// wy�lij string na port szeregowy
}
