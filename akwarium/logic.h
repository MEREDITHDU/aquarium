#ifndef __LOGIC
#define __LOGIC

#include "uart.h"
#include "temp.h" 
#include "lcd.h" 
#include "menu.h" 
#include "servo.h"
#include "twi.h" 
#include "rtc.h" 
#include "button.h"

#include "usb.h"
#include "usbdrv.h"

/* Types */
typedef struct {
	int min, hour, sec;
} time_t;

typedef struct {
	uint8_t feeding_switch_preoff;
	uint8_t feeding_switch_poston;
} config_t;

typedef struct {
	time_t time;
} feeding_t;

typedef struct {
	time_t time;
	uint8_t switch_id;
} switch_t;

typedef struct {
	uint8_t min, max, switch_id;
} temperature_t;

/* Common functions */
void init();

// time
void   settime(uint8_t hour, uint8_t min, uint8_t sec);
time_t gettime();
char*  timetostr(time_t time, char* separator);

// temp
uint16_t gettemp(uint8_t dev);




#endif
