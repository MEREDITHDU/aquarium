// PS-2 Keyboard interface test program

#include <avr/io.h>
#include <avr/interrupt.h>

#include "uart.h"
#include "delay.h"
#include "ps2kbd.h"

void initialize(void)
{
   cli();
   
   PORTB = 0xFD;
   DDRB = 0x02;     // Port B pin 1 as test pin

   PORTD = 0x5F;
   DDRD = 0xA0;     // All inputs with pullups.  UART will override.
                    // Pin5 - Out as RunLED, Pin7-out as RF module power

   PS2KBD_init();
   UART_init();       

   GIMSK= 0x40;        // Enable INT0 interrupt
   
   sei();
}

int main(void)
{
    unsigned char key;
    
    initialize();
    while(1)
    {
        key=PS2KBD_getchar();
        UART_putchar(key);
        delayms(100);
    }
    return 1;
}

