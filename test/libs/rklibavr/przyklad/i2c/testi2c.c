#include <avr/io.h>
#include "uart.h"
#include "i2c.h"

/* ------------------------------------------------------------------------- */
/* ----------------		 Program glowny 	    ---------------- */
/* ------------------------------------------------------------------------- */

int main(void)
{ 
  u08 adr;
  u08 ack;
  UART_init();
  for (adr=0; adr<=127; adr++)
  {
    I2C_start();
    ack=I2C_write((adr<<1)|1);
    I2C_read(1);
    I2C_stop();
    if (ack>0)
    {
      UART_putstr_P(PSTR("\r\nAdres I2C="));
      UART_puthexU08(adr);
      UART_putstr_P(PSTR(" ACK="));
      UART_puthexU08(ack);
    }
  }
  UART_putstr_P(PSTR("\r\n"));
  while(1);
}

/* ------------------------------------------------------------------------- */
/*		Koniec programu		                 		     */
/* ------------------------------------------------------------------------- */
