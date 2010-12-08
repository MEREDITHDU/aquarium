#include <avr/io.h>
#include "uart.h"
#include "adc.h"
#include "delay.h"


#define	BUF_SIZE	1024

uint8_t bufor[BUF_SIZE];
/* ------------------------------------------------------------------------- */
/* ----------------		 Program glowny 	    ---------------- */
/* ------------------------------------------------------------------------- */

int main(void)
{
  uint16_t i;
  UART_init();
  ADC_init();
  ADC_set_prescaler(ADC_PRESCALE_DIV32);
//  sei();                // w³¹cz obs³ugê przerwañ

  while(1)              // pêtla nieskoñczona
  {
    for(i=0;i<BUF_SIZE;i++)
      bufor[i]=ADC_convert_8bit(0);
    for(i=0;i<BUF_SIZE;i++)
    {
      UART_putint(bufor[i],10);
      UART_putchar(13);
    }
    delayms(300);
/*  
    UART_putint(ADC_convert_10bit(0),10);
    UART_putchar(' ');
    UART_putint(ADC_convert_10bit(1),10);
    UART_putchar(' ');
    UART_putint(ADC_convert_10bit(2),10);
    UART_putchar('\r');
*/
  }
  ADC_off();
}

/* ------------------------------------------------------------------------- */
/*				Koniec programu                		     */
/* ------------------------------------------------------------------------- */


