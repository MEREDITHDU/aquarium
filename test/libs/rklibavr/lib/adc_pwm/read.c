/*-------------------------------------------------------------------------- */
/*	Przetwornik analogowo/cyfrowy					     */
/*	wykorzystuj�cy wbudowany komparator analogowy i wyj�cie PWM	     */
/*	UWAGA: czas przetwarzania ok. 560 ms !!!			     */
/*	Autor: Robert Krysztof						     */
/* 	WWW:	http://www.8051.prv.pl 					     */
/*	E-mail: robert.krysztof@wp.pl					     */
/* ------------------------------------------------------------------------- */

#include "../adc_pwm.h"

u08 ADC_PWM_read(void)		// przetwornik AC
{
  int8_t i;
  uint8_t analog=0;		// inicjalizuj zmienn� analog na 0
  for(i=7; i>=0; i--)		// zacznij od najstarszego bitu
  {
    analog|=_BV(i);		// ustaw i-ty bit zmiennej analog
    PWM_out(analog);		// wyprowad� warto�� na wyj�cie PWM
    delayms(70);		// poczekaj na ustabilizowan� warto�� napi�cia
    if (bit_is_clear(ACSR,ACO))	// je�li warto�� napi�cia by�a za niska
      analog&=~_BV(i);		// to wyzeruj ustawiony wsze�niej bit
  }
  return analog; // zwraca wartosc nap. w zakr. od 0 do 255
}
