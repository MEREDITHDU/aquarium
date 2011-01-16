
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

	PCF_Set_Hour(hour);
	PCF_Set_Min(min);
	PCF_Set_Sec(sec);
}

time_t gettime() {
	time_t t;

	t.sec = PCF_Read_Sec();
	t.min = PCF_Read_Min();
	t.hour =  PCF_Read_Hour();

	return t;
}

char* timetostr(time_t time, char* separator) {
	char* t = malloc( 6*sizeof(char) + 2*sizeof(separator));
	sprintf(t, "%.2d%s%.2d%s%.2d", time.hour, separator, time.min, separator, time.sec);
	return t;
}

// temp
uint16_t gettemp(uint8_t dev) {
	
	int8_t digi;
	uint16_t deci, res;

	temp_read2(dev, &digi, &deci);

	res = digi*1000 + deci/10;

	//char b[25];
	//sprintf(b, "%d | %d %d \r\n", res , digi, deci );
	//uart_send(b);

	return res;
}



