#include "../led7seg.h"

u08 LED7SEG_KBD_key_pressed(void)
{
  u08 tmp=0;
#ifdef LED7SEG_KBD_ROW1_PORT		// je�li b�dzie obs�uga klawiatury
  if (LED7SEG_KBD_key_timer_old!=LED7SEG_KBD_key_timer)
  {
    tmp=1;
    LED7SEG_KBD_key_timer_old=LED7SEG_KBD_key_timer;
  }
#endif
  return tmp;
}
