
#include "usb.h"

PROGMEM char usbHidReportDescriptor[22] = {    // USB report descriptor /
    0x06, 0x00, 0xff,              // USAGE_PAGE (Generic Desktop)
    0x09, 0x01,                    // USAGE (Vendor Usage 1)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x26, 0xff, 0x00,              //   LOGICAL_MAXIMUM (255)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x09, 0x00,                    //   USAGE (Undefined)
    0xb2, 0x02, 0x01,              //   FEATURE (Data,Var,Abs,Buf)
    0xc0                           // END_COLLECTION
};

/* The following variables store the status of the current data transfer */
//static uchar    currentAddress;
uint8_t	usb_bytes_left, usb_action;
char 	usb_buffer[100];

extern uint8_t temp_flag, reset_flag, busy;
extern tempmeasure_t measure;

enum { GETTIME = 0, 
	SETTIME, 
	GETTEMP, 
	SETDATE, 
	GETDATE, 
	RESET, 
	BACKLIGHT 
};


/*My functions  */

void usb_init() {
	DDRD  = 0x00; //  ~_BV(PD2) & ~_BV(PD4); 

	// enable watchdog
	wdt_enable(WDTO_1S);

	usbInit();
	usbDeviceDisconnect();  /* enforce re-enumeration, do this while interrupts are disabled! */
	uchar i = 0;
	while(--i){             /* fake USB disconnect for > 250 ms */
		wdt_reset();
		_delay_ms(1);
	}
	usbDeviceConnect();
}


void usbAction(int param) {

	switch(usb_action) {
		case GETTIME: {
				      char *time = timetostr ( gettime(), "/");	
				      strcpy(usb_buffer, time);
				      free(time);

				      usb_bytes_left = strlen(usb_buffer);
				      break;
			      }
		case SETTIME: {
				      uint8_t time[3], i = 0;
				      char *p = strtok(usb_buffer, "/");
				      while(p != NULL) {
					      time[i++] = atoi(p);
					      p = strtok(NULL, "/");
				      }
				      settime(time[0], time[1], time[2]);
				      break;
			      }
		case GETDATE: {
				      char *date = datetostr ( getdate(), "/");	
				      strcpy(usb_buffer, date);
				      free(date);

				      usb_bytes_left = strlen(usb_buffer);
				      break;
			      }
		case SETDATE: {
				      uint8_t date[3], i = 0;
				      char *p = strtok(usb_buffer, "/");
				      while(p != NULL) {
					      date[i++] = atoi(p);
					      p = strtok(NULL, "/");
				      }
				      setdate(date[0], date[1], date[2]);
				      break;
			      }
		case GETTEMP: {
				      //param is temp device number
				      int device = param;
				      uint16_t temp = measure.t1;
				     
				      sprintf(usb_buffer, "therm%d: %.2d.%.1d", device, temp/1000, temp%1000);

				      usb_bytes_left = strlen(usb_buffer);
				      uart_send("\r\nstart: ");

				      break;
			      }
	}
}


/* Driver functions */

usbMsgLen_t usbFunctionSetup(uchar data[8]) {
	usbRequest_t    *rq = (void *)data;
	usb_action = rq->bRequest;

	//@DEBUG
	/*char b[30];
	sprintf(&b, "%s: %d", "usbSetup", usb_action);
	uart_send(b);
	*/

	switch(usb_action) {
		case GETTIME: 
			usbAction(0);
			return USB_NO_MSG;
		case SETTIME: 
			usb_buffer[0] = '\0';
			usb_bytes_left = rq->wValue.bytes[0];
			return USB_NO_MSG;
		case GETDATE: 
			usbAction(0);
			return USB_NO_MSG;
		case SETDATE: 
			usb_buffer[0] = '\0';
			usb_bytes_left = rq->wValue.bytes[0];
			return USB_NO_MSG;
		case GETTEMP: 
			usbAction(rq->wValue.bytes[0]);
			return USB_NO_MSG;
		case RESET: 
			reset_flag = 1;
		        break;
		case BACKLIGHT: 
			if( 	 rq->wValue.bytes[0] == 1) lcd_backlight_on();
			else if( rq->wValue.bytes[0] == 3) lcd_backlight_fadeon();
			else if( rq->wValue.bytes[0] == 0) lcd_backlight_off();
			else if( rq->wValue.bytes[0] == 2) lcd_backlight_fadeoff();
		        break;
		default:
			//@DEBUG
			uart_send("usbFunSetup -> not handled");
	}

	return 0;
}



/* usbFunctionRead() is called when the host requests a chunk of data from
 * the device. For more information see the documentation in usbdrv/usbdrv.h.
 */
uchar   usbFunctionRead(uchar *data, uchar len) {

//	uart_send("usb function read"); UART_NL;
				      uart_send(".");
	
	if(len > usb_bytes_left)
		len = usb_bytes_left;

	usb_bytes_left -= len;

	strncpy((char*)data, usb_buffer, len);

	char *to = (char*) malloc(len);
	strcpy(to, usb_buffer+len);
	strcpy(usb_buffer, to);
	free(to);

	return len;
}

/* usbFunctionWrite() is called when the host sends a chunk of data to the
 * device. For more information see the documentation in usbdrv/usbdrv.h.
 */
uchar   usbFunctionWrite(uchar *data, uchar len) {
	
	//uart_send("usb function write"); UART_NL;

	if(len > usb_bytes_left)
		len = usb_bytes_left;
	usb_bytes_left -= len;

	strncat(usb_buffer, (char*)data, len);

	if(usb_bytes_left == 0) {
		//uart_send(usb_buffer); UART_NL;
		usbAction(0);
		usb_buffer[0] = '\0';
		return 1;               //* end of transfer 
	}

	//return 0; //* return 1 if this was the last chunk 
	return 0; //* return 1 if this was the last chunk 
}

void usb_keepalive() {
	wdt_reset();
	usbPoll();
}

//endof usb
