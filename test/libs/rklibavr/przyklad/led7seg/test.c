/*--------------------------------------------------------------------- */
/*	Demo wyœwietlania multipleksowanego				*/
/*	Autor: Robert Krysztof						*/
/* 	WWW:	http://www.8051.prv.pl 					*/
/*	E-mail: robert.krysztof@wp.pl					*/
/*--------------------------------------------------------------------- */

#include <avr/io.h>
#include "led7seg.h"
#include "delay.h"

u16 liczba;

void key_event1(void)		// reakcja na naciœniêcie klawisza 1
{
  liczba+=1000;			// zwiêksz liczbê o 1000
  LED7SEG_putU16(liczba);	// wyœwietlaj wartoœæ
  LED7SEG_commas=_BV(0);	
}

void key_event2(void)		// reakcja na naciœniêcie klawisza 2
{
  liczba+=100;			// zwiêksz liczbê o 100
  LED7SEG_putU16(liczba);	// wyœwietlaj wartoœæ 
  LED7SEG_commas=_BV(1);
}

void key_event3(void)		// reakcja na naciœniêcie klawisza 3
{
  liczba+=10;			// zwiêksz liczbê o 10
  LED7SEG_putU16(liczba);	// wyœwietlaj wartoœæ 
  LED7SEG_commas=_BV(2);
}

void key_event4(void)		// reakcja na naciœniêcie klawisza 4
{
  liczba+=1;			// zwiêksz liczbê o 1
  LED7SEG_putU16(liczba);	// wyœwietlaj wartoœæ 
  LED7SEG_commas=_BV(3);
}

void key_event5(void)		// reakcja na naciœniêcie klawisza 5
{
  LED7SEG_putU08(255);		// wyœwietlaj wartoœæ
}

void key_event6(void)		// reakcja na naciœniêcie klawisza 6
{
  LED7SEG_putU16(1234);		// wyœwietlaj wartoœæ 
}

void key_event7(void)		// reakcja na naciœniêcie klawisza 7
{
  LED7SEG_putU16(5678);		// wyœwietlaj wartoœæ 
}

void key_event8(void)		// reakcja na naciœniêcie klawisza 8
{
  LED7SEG_putstr(":;KM");
  LED7SEG_commas=_BV(0)|_BV(1)|_BV(2)|_BV(3);	
}

void key_event9(void)		// reakcja na naciœniêcie klawisza 9
{
  LED7SEG_putstr("ABCD");
}

void key_event10(void)		// reakcja na naciœniêcie klawisza 10
{
  LED7SEG_putstr("EFGH");
}

void key_event11(void)		// reakcja na naciœniêcie klawisza 11
{
  LED7SEG_putstr("IJKL");
}

void key_event12(void)		// reakcja na naciœniêcie klawisza 12
{
  LED7SEG_putstr("MNOP");
}

void key_event13(void)		// reakcja na naciœniêcie klawisza 13
{
  LED7SEG_putstr("QRST");
}

void key_event14(void)		// reakcja na naciœniêcie klawisza 14
{
  LED7SEG_putstr("UVW=");
}

void key_event15(void)		// reakcja na naciœniêcie klawisza 15
{
  LED7SEG_putstr("YZ[]");
}

void key_event16(void)		// reakcja na naciœniêcie klawisza 16
{
  LED7SEG_clear();		// kasuj wyœwietlacz
}


/*--------------------------------------------------------------------- */
/* -------------------		Program glowny 	    ------------------- */
/*--------------------------------------------------------------------- */

int main(void)
{                
  LED7SEG_init();		// inicjalizacja wyœwietlacza
  sei();                       	// w³¹cz obs³ugê przerwañ
  
  while(1)			// pêtla nieskoñczona
  {
    switch (LED7SEG_KBD_key_read())		// czytaj klawisz
    {
      case 1: key_event1();	// reakcja na naciœniêcie klawisza 1
	break;
      case 2: key_event2();	// reakcja na naciœniêcie klawisza 2
	break;
      case 3: key_event3();	// reakcja na naciœniêcie klawisza 3
	break;
      case 4: key_event4();	// reakcja na naciœniêcie klawisza 4
	break;
      case 5: key_event5();	// reakcja na naciœniêcie klawisza 5
	break;
      case 6: key_event6();	// reakcja na naciœniêcie klawisza 6
	break;
      case 7: key_event7();	// reakcja na naciœniêcie klawisza 7
	break;
      case 8: key_event8();	// reakcja na naciœniêcie klawisza 8
	break;
      case 9: key_event9();	// reakcja na naciœniêcie klawisza 9
	break;
      case 10: key_event10();	// reakcja na naciœniêcie klawisza 10
	break;
      case 11: key_event11();	// reakcja na naciœniêcie klawisza 11
	break;
      case 12: key_event12();	// reakcja na naciœniêcie klawisza 12
	break;
      case 13: key_event13();	// reakcja na naciœniêcie klawisza 13
	break;
      case 14: key_event14();	// reakcja na naciœniêcie klawisza 14
	break;
      case 15: key_event15();	// reakcja na naciœniêcie klawisza 15
	break;
      case 16: key_event16();	// reakcja na naciœniêcie klawisza 16
	break;
    }
    delayms(10);		// musi byæ lekkie opóŸnienie
  }
}

/*--------------------------------------------------------------------- */
/*			Koniec programu		              		*/
/*--------------------------------------------------------------------- */
