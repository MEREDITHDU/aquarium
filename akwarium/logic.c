
#include "logic.h"

config_t EEMEM ee_config;
feeding_t EEMEM ee_feeding[10];
switch_t EEMEM ee_switch[20];
temperature_t EEMEM ee_temp;

void init() {
	uart_send("Starting ...\r\n\n");

	config_init();
	lcd_init();
	menu_init();
	usb_init();
}

// time
void  settime(uint8_t hour, uint8_t min, uint8_t sec) {
	cli();
	PCF_Set_Hour(hour);
	PCF_Set_Min(min);
	PCF_Set_Sec(sec);
	sei();
}
time_t gettime() {
	time_t t;
	cli();
	t.sec = PCF_Read_Sec();
	t.min = PCF_Read_Min();
	t.hour =  PCF_Read_Hour();
	sei();
	return t;
}
char* timetostr(time_t time, char* separator) {
	char* t = malloc( 6*sizeof(char) + 2*sizeof(separator));
	sprintf(t, "%.2d%s%.2d%s%.2d", time.hour, separator, time.min, separator, time.sec);
	return t;
}

// date 
void  setdate(uint8_t day, uint8_t month, uint8_t year) {
	cli();
	PCF_Set_Day(day);
	PCF_Set_Month(month);
	PCF_Set_Year(year % 100);
	sei();
}
date_t getdate() {
	date_t t;
	cli();
	t.day = PCF_Read_Day();
	t.month = PCF_Read_Month();
	t.year =  PCF_Read_Year();
	sei();
	return t;
}
char* datetostr(date_t date, char* separator) {
	char* t = malloc( 6*sizeof(char) + 2*sizeof(separator));

	int d = date.day;
	int m = date.month;
	int y = date.year;

	int day = (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7;

	char* dayname = malloc(4 * sizeof(char));
	switch(day) {
		case 0: strcpy(dayname, "nie"); break;
		case 1: strcpy(dayname, "pon"); break;
		case 2: strcpy(dayname, "wto"); break;
		case 3: strcpy(dayname, "śro"); break;
		case 4: strcpy(dayname, "czw"); break;
		case 5: strcpy(dayname, "pią"); break;
		case 6: strcpy(dayname, "sob"); break;
	}

	sprintf(t, "%s    %.2d%s%.2d%s%.2d", dayname, date.day, separator, date.month, separator, date.year);
	free(dayname);
	return t;
}

// temp
uint16_t gettemp(uint8_t dev) {

	int8_t digi;
	uint16_t deci, res;

	temp_read2(dev, &digi, &deci);
	res = digi*1000 + deci/10;

	return res;
}



