// Testowanie biblioteki funkcji matematycznych

#include <avr/io.h>		// dostêp do rejestrów
#include <math.h>		// funkcje matematyczne
#include <stdio.h>		// standardowe wejœcie/wyjœcie
#include "uart.h"		// obs³uga portu szeregowego

//----------------------------------------------------------

int main(void)		// program g³ówny
{
  float a,b,c,delta,sqrt_delta,x1,x2;

  UART_init();		// inicjalizacja portu szeregowego

  fdevopen(UART_putchar, UART_getchar, 0);

  printf_P(PSTR("Test biblioteki matematycznej\r\n"));

  while(1)		// pêtla nieskoñczona
  {
    printf_P(PSTR("\r\nRownanie kwadratowe"));
    printf_P(PSTR("\r\nPodaj wpolczynnik a: "));
    scanf("%f",&a);
    printf_P(PSTR("\r\nPodaj wpolczynnik b: "));
    scanf("%f",&b);
    printf_P(PSTR("\r\nPodaj wpolczynnik c: "));
    scanf("%f",&c);
    printf_P(PSTR("\r\nPostac rownania: %fx^2+%fx+%f=0"), a, b, c);
    delta=b*b-4*a*c;
    a*=2;	// od tej pory a nie jest potrzebne
		// wpisujemy tam 2*a 
    printf_P(PSTR("\r\nDelta: %f"),delta);
    if (delta<0)
    {
      printf_P(PSTR("\r\nDelta mniejsza od zera - brak pierwiastkow!!!"));
    }
    else if (delta==0)
    {
      printf_P(PSTR("\r\nDelta rowna zero - jeden pierwiastek"));
      x1=-b/a;
      printf_P(PSTR("\r\nx=%f\r\n"),x1);
    }
    else
    {
      printf_P(PSTR("\r\nDelta wieksza od zera - dwa pierwiastki!!!"));
      sqrt_delta=sqrt(delta);
      x1=(-b-sqrt_delta)/a;
      printf_P(PSTR("\r\nx1=%f"),x1);
      x2=(-b+sqrt_delta)/a;
      printf_P(PSTR("\r\nx2=%f"),x2);
    }
  }
}

