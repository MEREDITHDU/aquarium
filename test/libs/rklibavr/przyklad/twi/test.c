#include <avr/io.h>
#include "twi.h"
#include "uart.h"
#include "debug.h"
#include "delay.h"

u08 dat[128];

int main(void)
{
  TWI_init();
  UART_init();
  sei();
    
  while(1) 
  {
    TWI_read(0x50,dat,128);	// Czytaj 24c02 EEPROM (A0=A1=A2 = 0)
    DEBUG_hextable(dat,128);  

    TWI_write(0x50,dat,128);	// Zapisz do PCF8583 (A0 = 1)
  
    TWI_read(0x51,dat,128);	// Czytaj z PCF8583 (A0 = 1)
    DEBUG_hextable(dat,128); 
    delayms(500);
  }
}
