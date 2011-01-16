//#include <avr/io.h>
//#include <avr/wdt.h>

#include "logic.h"

#include "lcd.h"
#include "usb.h"
#include "usbdrv.h"

void buttons();
void main_page();

uint8_t menu_flag = 0, 
	sec_tick = 0;

// przerwanie INT0 po przepełnieniu TIMER0 
ISR(TIMER1_COMPA_vect) { sec_tick = 1; } 

int main(void) {

	cli(); init(); sei();

	/* main event loop */
	while(1)  {   
		buttons();

		if(sec_tick) {
			main_page();
			sec_tick = 0;
		}

		usb_keepalive();
	}
}

void buttons() {
	if(button_pressed(BUTTON1)) {
		uart_send("startmenu\r\n");
			menu_flag = 1;
			menu_display(MENU_UP);
		uart_send("stopmenu\r\n");
	}
	else if(button_pressed(BUTTON2)) {
		uart_send("button 2\r\n");
		//test_t t = { 1, 'c' };
		//eeprom_write_block( (const void*)&t, (void*)&estruct, sizeof(t));
	}
	else if(button_pressed(BUTTON3)) {
		uart_send("button 3\r\n");
		//uint8_t t = 100;
		//eeprom_write_byte( (uint8_t*)&estruct.x, (uint8_t)t );
	}
	else if(button_pressed(BUTTON4)) {
		uart_send("button 4\r\n");
		//test_t t;
		//eeprom_read_block( (void*)&t, (const void*)&estruct, sizeof(t) );
		//char buf[30];
		//sprintf( buf, "int: %d, char: %c \r\n", t.x, t.y);
		//uart_send(buf);
	}
}

void main_page() {

	char* time = timetostr( gettime(), ":" );
	lcd_write(2, time);
	free(time);


	char b[20];
	uint16_t temp =  gettemp(1);
	sprintf(b, "%.2d.%.1d", temp/1000, temp%1000);
	lcd_write(4, b);
}

