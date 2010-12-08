#include "../uart.h"

void UART_getstr (char *s)
{
  uint8_t i=0;
  uint8_t ch=0;
  do
  {
    WDR();			// restart licznika Watchdoga
    ch=UART_getchar();		// pobieraj znak
    s[i]=ch;			// wstaw go do �a�cucha i inkrementuj
    i++;			// inkrementuj ilo�� znak�w odebranych
  }
  while ((ch != 10) && (ch != 13) && (i <= UART_MAX_GETSTR));
// dop�ki nie napotka znak�w ko�ca linii lub nie przekroczy d�ugo�ci MAX_GETSTR
  s[i-1]=0;			// wstaw 0 na koniec �a�cucha
}
