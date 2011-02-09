//#include <avr/io.h>
//#include <avr/wdt.h>

#include "logic.h"

#include "lcd.h"
#include "usb.h"
#include "usbdrv.h"

void buttons();
void main_page();

uint8_t menu_flag = 0, 
	temp_flag = 0,
	reset_flag = 0,
	sec_tick = 0,
	busy = 0;

tempmeasure_t measure;



// przerwanie INT0 po przepełnieniu TIMER0 
ISR(TIMER1_COMPA_vect) { sec_tick = 1; } 

int main(void) {
	uint8_t c = 0;

	cli(); init(); sei();

	uart_send("Starting .."); UART_NL;
	lcd_backlight_off();

	//temp_flag = (int*)malloc(sizeof(int));

	/* main event loop */
	while(1)  {   
		buttons();

		if(reset_flag) { 
			//@DEBUG
			uart_send("reseting"); UART_NL; 
			while(1); 
		}

		if(sec_tick) {
			main_page();

			cli();
			switch(c++ % 6) {
				case 0: measure.t1 = gettemp(1);
				case 2: measure.t2 = gettemp(2);
				case 4: measure.t2 = gettemp(3);
			}
			sei();

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

	if(busy) return;

	char* time = timetostr( gettime(), ":" );
	lcd_write(2, time);
	free(time);

	char* date = datetostr( getdate(), "/" );
	lcd_write(1, date);
	free(date);

	char b[20];
	uint16_t temp =  measure.t1;
	sprintf(b, "%.2d.%.1d", temp/1000, temp%1000);
	lcd_write(4, b);
}

