/*--------------------------------------------------------------------- */
/*	Demo wy�wietlania multipleksowanego				*/
/*	Autor: Robert Krysztof						*/
/* 	WWW:	http://www.8051.prv.pl 					*/
/*	E-mail: robert.krysztof@wp.pl					*/
/*--------------------------------------------------------------------- */

#include <avr/io.h>
#include "led7seg.h"
#include "delay.h"

u16 liczba;

void key_event1(void)		// reakcja na naci�ni�cie klawisza 1
{
  liczba+=1000;			// zwi�ksz liczb� o 1000
  LED7SEG_putU16(liczba);	// wy�wietlaj warto��
  LED7SEG_commas=_BV(0);	
}

void key_event2(void)		// reakcja na naci�ni�cie klawisza 2
{
  liczba+=100;			// zwi�ksz liczb� o 100
  LED7SEG_putU16(liczba);	// wy�wietlaj warto�� 
  LED7SEG_commas=_BV(1);
}

void key_event3(void)		// reakcja na naci�ni�cie klawisza 3
{
  liczba+=10;			// zwi�ksz liczb� o 10
  LED7SEG_putU16(liczba);	// wy�wietlaj warto�� 
  LED7SEG_commas=_BV(2);
}

void key_event4(void)		// reakcja na naci�ni�cie klawisza 4
{
  liczba+=1;			// zwi�ksz liczb� o 1
  LED7SEG_putU16(liczba);	// wy�wietlaj warto�� 
  LED7SEG_commas=_BV(3);
}

void key_event5(void)		// reakcja na naci�ni�cie klawisza 5
{
  LED7SEG_putU08(255);		// wy�wietlaj warto��
}

void key_event6(void)		// reakcja na naci�ni�cie klawisza 6
{
  LED7SEG_putU16(1234);		// wy�wietlaj warto�� 
}

void key_event7(void)		// reakcja na naci�ni�cie klawisza 7
{
  LED7SEG_putU16(5678);		// wy�wietlaj warto�� 
}

void key_event8(void)		// reakcja na naci�ni�cie klawisza 8
{
  LED7SEG_putstr(":;KM");
  LED7SEG_commas=_BV(0)|_BV(1)|_BV(2)|_BV(3);	
}

void key_event9(void)		// reakcja na naci�ni�cie klawisza 9
{
  LED7SEG_putstr("ABCD");
}

void key_event10(void)		// reakcja na naci�ni�cie klawisza 10
{
  LED7SEG_putstr("EFGH");
}

void key_event11(void)		// reakcja na naci�ni�cie klawisza 11
{
  LED7SEG_putstr("IJKL");
}

void key_event12(void)		// reakcja na naci�ni�cie klawisza 12
{
  LED7SEG_putstr("MNOP");
}

void key_event13(void)		// reakcja na naci�ni�cie klawisza 13
{
  LED7SEG_putstr("QRST");
}

void key_event14(void)		// reakcja na naci�ni�cie klawisza 14
{
  LED7SEG_putstr("UVW=");
}

void key_event15(void)		// reakcja na naci�ni�cie klawisza 15
{
  LED7SEG_putstr("YZ[]");
}

void key_event16(void)		// reakcja na naci�ni�cie klawisza 16
{
  LED7SEG_clear();		// kasuj wy�wietlacz
}


/*--------------------------------------------------------------------- */
/* -------------------		Program glowny 	    ------------------- */
/*--------------------------------------------------------------------- */

int main(void)
{                
  LED7SEG_init();		// inicjalizacja wy�wietlacza
  sei();                       	// w��cz obs�ug� przerwa�
  
  while(1)			// p�tla niesko�czona
  {
    switch (LED7SEG_KBD_key_read())		// czytaj klawisz
    {
      case 1: key_event1();	// reakcja na naci�ni�cie klawisza 1
	break;
      case 2: key_event2();	// reakcja na naci�ni�cie klawisza 2
	break;
      case 3: key_event3();	// reakcja na naci�ni�cie klawisza 3
	break;
      case 4: key_event4();	// reakcja na naci�ni�cie klawisza 4
	break;
      case 5: key_event5();	// reakcja na naci�ni�cie klawisza 5
	break;
      case 6: key_event6();	// reakcja na naci�ni�cie klawisza 6
	break;
      case 7: key_event7();	// reakcja na naci�ni�cie klawisza 7
	break;
      case 8: key_event8();	// reakcja na naci�ni�cie klawisza 8
	break;
      case 9: key_event9();	// reakcja na naci�ni�cie klawisza 9
	break;
      case 10: key_event10();	// reakcja na naci�ni�cie klawisza 10
	break;
      case 11: key_event11();	// reakcja na naci�ni�cie klawisza 11
	break;
      case 12: key_event12();	// reakcja na naci�ni�cie klawisza 12
	break;
      case 13: key_event13();	// reakcja na naci�ni�cie klawisza 13
	break;
      case 14: key_event14();	// reakcja na naci�ni�cie klawisza 14
	break;
      case 15: key_event15();	// reakcja na naci�ni�cie klawisza 15
	break;
      case 16: key_event16();	// reakcja na naci�ni�cie klawisza 16
	break;
    }
    delayms(10);		// musi by� lekkie op�nienie
  }
}

/*--------------------------------------------------------------------- */
/*			Koniec programu		              		*/
/*--------------------------------------------------------------------- */
