//#include <avr/io.h>
//#include <avr/wdt.h>

#include "config.h"

#include "uart.h"
#include "temp.h" 
#include "lcd.h" 
#include "menu.h" 
#include "servo.h"
#include "twi.h" 
#include "pcf8583.h" 
#include "usb.h"
#include "usbdrv.h"
#include "button.h"

void buttons();
void main_page();

uint16_t c = 0;
uint8_t menu_flag = 0, 
	sec_tick = 0;

typedef struct {
	int x;
	char y;
} test_t;
test_t EEMEM estruct;

// przerwanie INT0 po przepełnieniu TIMER0 
ISR(TIMER1_COMPA_vect) { sec_tick = 1; } 

int main(void) {

	cli();
		init();
		lcd_init();
		menu_init();
		usb_init();

//		menu_flag = 1;
	sei();


	uart_send("Starting ...\r\n\n");

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

	//uart_send("Buttons check \r\n");

	if(button_pressed(BUTTON1)) {

		uart_send("startmenu\r\n");
			menu_flag = 1;
			menu_display(MENU_UP);
		uart_send("stopmenu\r\n");
	}
	else if(button_pressed(BUTTON2)) {
		uart_send("button 2\r\n");

		test_t t = { 1, 'c' };
		eeprom_write_block( (const void*)&t, (void*)&estruct, sizeof(t));
	}
	else if(button_pressed(BUTTON3)) {
		uart_send("button 3\r\n");
		
		uint8_t t = 100;
		eeprom_write_byte( (uint8_t*)&estruct.x, (uint8_t)t );
	}
	else if(button_pressed(BUTTON4)) {
		uart_send("button 4\r\n");

		test_t t;
		eeprom_read_block( (void*)&t, (const void*)&estruct, sizeof(t) );

		char buf[30];
		sprintf( buf, "int: %d, char: %c \r\n", t.x, t.y);
		uart_send(buf);
	}
}

void main_page() {

	int sec, min, hour;
	char time[10];

	//servo_move(1);

		char cbuf[20];
		sprintf(cbuf, "%d", c++);
		lcd_write(1, cbuf);


		sec = PCF_Read_Sec();
		min = PCF_Read_Min();
		hour =  PCF_Read_Hour();

		sprintf(time, "%.2d:%.2d:%.2d", hour, min, sec);
		lcd_write(2, time);


		char buffer[21];
		temp_read(1, buffer);
		lcd_write(4, buffer);
}

