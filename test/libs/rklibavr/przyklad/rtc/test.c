#include <avr/io.h>
#include "uart.h"
#include "rtc.h"

/* ------------------------------------------------------------------------- */
/* ----------------		 Program glowny 	    ---------------- */
/* ------------------------------------------------------------------------- */

int main(void)
{
  uint8_t last_second=0;   // przechowuje ostatnio wyœwietlon¹ sekundê

  RTC_time.year=2004;          // zainicjuj rok
  RTC_time.month=4;            // zainicjuj miesi¹c
  RTC_time.day=8;             // zainicjuj dzieñ
  RTC_time.hour=12;            // zainicjuj godzinê
  UART_init();
  RTC_init();

  sei();                // w³¹cz obs³ugê przerwañ

  while(1)              // pêtla nieskoñczona
  {
    if ((last_second)!=(RTC_time.second))      // jeœli zmieni³a siê sekunda
    {
      last_second=RTC_time.second;     // zapamiêtaj obecn¹ sekundê
      UART_putint(RTC_time.year,10);	// wyœwietl rok
      UART_putchar('-');
      UART_putint(RTC_time.month,10);	// wyœwietl miesi¹c
      UART_putchar('-');
      UART_putint(RTC_time.day,10);	// wyœwietl dzien
      UART_putchar(' ');
      UART_putint(RTC_time.hour,10);	// wyœwietl godzinê
      UART_putchar(':');
      UART_putint(RTC_time.minute,10);	// wyœwietl minutê
      UART_putchar(':');
      UART_putint(RTC_time.second,10);	// sekundê
      UART_putchar('\r');
    }
  }
}

/* ------------------------------------------------------------------------- */
/*				Koniec programu                		     */
/* ------------------------------------------------------------------------- */


