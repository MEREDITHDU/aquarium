#include <avr/io.h>
#include <avr/pgmspace.h>

#include "remote.h"
#include "delay.h"
#include "uart.h"
#include "lcd.h"

int main(void)
{
  LCD_init();
  UART_init();
  
  sbi(DDRC,5);
  sbi(DDRC,4);
  sbi(DDRC,3);
  sbi(DDRC,2);
  sbi(DDRD,7);
  sbi(DDRD,5);
  sbi(DDRD,4);

  LCD_putstr_P(PSTR("IR-Code: "));
  u16 code;
  u08 key=0;
  while(1)
  {
    WDR();
    if (REMOTE_active())
    {
      if ((code = REMOTE_get()))
      {
        LCD_xy(9,0);
	LCD_putint(code,16);
//	UART_putstr_P(PSTR("REMOTE_code 0x"));
//	UART_putint(code,16);
        UART_putstr_P(PSTR("Key "));
	switch (code)
	{
	  case REMOTE_code1 : key=1; break;
	  case REMOTE_code2 : key=2; break;
	  case REMOTE_code3 : key=3; break;
	  case REMOTE_code4 : key=4; break;
	  case REMOTE_code5 : key=5; break;
	  case REMOTE_code6 : key=6; break;
	  case REMOTE_code7 : key=7; break;
	  case REMOTE_code8 : key=8; break;
	  case REMOTE_code9 : key=9; break;
	  case REMOTE_code10 : key=10; break;
	  case REMOTE_code11 : key=11; break;
	  case REMOTE_code12 : key=12; break;
	  case REMOTE_code13 : key=13; break;
	  case REMOTE_code14 : key=14; break;
	  case REMOTE_code15 : key=15; break;
	  case REMOTE_code16 : key=16; break;
	  case REMOTE_code17 : key=17; break;
	  case REMOTE_code18 : key=18; break;
	  case REMOTE_code19 : key=19; break;
	  case REMOTE_code20 : key=20; break;
	  case REMOTE_code21 : key=21; break;
	  case REMOTE_code22 : key=22; break;
	  case REMOTE_code23 : key=23; break;
	  case REMOTE_code24 : key=24; break;
	  case REMOTE_code25 : key=25; break;
	  case REMOTE_code26 : key=26; break;
	  case REMOTE_code27 : key=27; break;
	  case REMOTE_code28 : key=28; break;
	}
	UART_putint(key,10);
	UART_putstr_P(PSTR("\n\r"));
	switch (key)
	{
	  case 1 : tbi(PORTC,5); break;
	  case 2 : tbi(PORTC,4); break;
	  case 3 : tbi(PORTC,3); break;
	  case 4 : tbi(PORTC,2); break;
	  case 5 : tbi(PORTD,4); break;
	  case 6 : tbi(PORTD,5); break;
	  case 7 : tbi(PORTD,7); break;
        }
	code = 0;
      }
    }
  }
}

