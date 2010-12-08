#include "../rtc.h"

void RTC_init(void)
{
#ifdef AS2
  TIMSK &=~_BV(TOIE2);  // Wy��cz przerwania TC2
  ASSR |= _BV(AS2);     // prze��cz TC2 z taktowania zegarem CPU
                        // na generator asynchoniczny 32768 Hz
  TCCR2 = _BV(CS22)|_BV(CS20);  // ustaw preskaler na podzia� przez 128
                        // aby generowa� przerwania dok�adnie co 1 sekund�
  while(ASSR&0x07);     // czekaj na uaktualnienie TC2
  TIMSK |= _BV(TOIE2);  // w��cz przerwania z TC2
#else
#ifdef AS0
// !!!!!!!!!!!! tu trzeba wpisa� inicjalizacj� (nie mam ATmega 103 lub 128) !!!!!!!!!!!!
#endif
#endif
}

struct_time RTC_time;  /// zmienna przechowuj�ca czas

//sprawdza rok przest�pny
char not_leap(void)
{
  if (!(RTC_time.year%100))            // je�li rok jest podzielny przez 100
    return (char)(RTC_time.year%400);  // sprawd� i zwr�� rok podzielny przez 400
  else                          // w przeciwnym wypadku
    return (char)(RTC_time.year%4);    // zwr�� rok podzielny przez 4
}

// zliczanie czasu
// w oparciu o ATMEL Application Note AVR134
#ifdef AS0
SIGNAL(SIG_OVERFLOW0)           // obs�uga przerwania od licznika 0
#else
#ifdef AS2
SIGNAL(SIG_OVERFLOW2)           // obs�uga przerwania od licznika 2
#endif
#endif
{
  if (++RTC_time.second==60)           // inkrementuj sekundy i sprawd� czy jest ich 60
  {                             // je�li tak to:
    RTC_time.second=0;                 // wyzeruj licznik sekund oraz
    if (++RTC_time.minute==60) // inkrementuj licznik minut i sprawd� czy jest ich 60
    {                           // je�li tak to:
      RTC_time.minute=0;               // wyzeruj licznik minut oraz
      if (++RTC_time.hour==24) // inkrementuj licznik godzin i sprawd� czy jest ich 24
      {                         // je�li tak to:
        RTC_time.hour=0;               // wyzeruj licznik godzin oraz
        if (++RTC_time.day==32)       // inkrementuj licznik dni i sprawd� czy jest ich 32
        {                       // je�li tak to:
          RTC_time.month++;            // inkrementuj licznik miesi�cy
          RTC_time.day=1;             // ustaw dzie� na 1
        }
        else if (RTC_time.day==31)    // je�eli dzie� r�wna si� 31
        {                       // to sprawd� czy s� to miesi�ce: 4, 6, 9, 11
          if ((RTC_time.month==4) || (RTC_time.month==6) || 
              (RTC_time.month==9) || (RTC_time.month==11))
          {                     // je�li tak to:
            RTC_time.month++;          // inkrementuj licznik miesi�cy
            RTC_time.day=1;           // ustaw dzie� na 1
          }
        }
        else if (RTC_time.day==30)    // je�eli dzie� r�wna si� 30
        {                       // to sprawd� czy
          if (RTC_time.month==2)       // jest to miesi�c 2 (luty)
          {                     // je�li tak to:
            RTC_time.month++;          // inkrementuj licznik miesi�cy
            RTC_time.day=1;           // ustaw dzie� na 1
          }
        }
        else if (RTC_time.day==29)    // je�eli dzie� r�wna si� 29
        {                       // to sprawd� czy:
          if ((RTC_time.month==2) && (not_leap())) // miesi�c 2 i rok nieprzest�pny
          {                     // je�li tak to:
            RTC_time.month++;          // inkrementuj licznik miesi�cy
            RTC_time.day=1;           // ustaw dzie� na 1
          }
        }
        if (RTC_time.month==13)        // je�li miesi�c wynosi 13
        {                       // to:
          RTC_time.month=1;            // ustaw miesi�c na 1 (stycze�)
          RTC_time.year++;             // inkrementuj licznik lat
        }
      }
    }
  }
}
