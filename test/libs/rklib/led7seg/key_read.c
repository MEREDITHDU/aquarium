#include "../led7seg.h"

u08 LED7SEG_KBD_key_read(void)
{
  u08 tmp=0;		// czytaj klawisz z bufora
#ifdef LED7SEG_KBD_ROW1_PORT		// je�li b�dzie obs�uga klawiatury
  if (LED7SEG_KBD_key_pressed()==0) 
  {
    tmp=LED7SEG_KBD_key;
    LED7SEG_KBD_key=0;	// wpisz po odczycie 0
  }
#endif
  return tmp;		// zwr�� kod klawisza
}
