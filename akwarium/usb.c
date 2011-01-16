
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
uint8_t	usb_bytes_left;
char 	usb_buffer[100];
uint8_t usb_action;

enum { GETTIME = 0, SETTIME, GETTEMP };

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
		case GETTEMP: {
				      //param is temp device number
				      int device = param;
				      double temp = gettemp(device);

				      sprintf(usb_buffer, "%f C", temp);
				      uart_send(usb_buffer);
				      usb_bytes_left = strlen(usb_buffer);
				      break;
			      }


	}
}


/* Driver functions */

usbMsgLen_t usbFunctionSetup(uchar data[8]) {
	usbRequest_t    *rq = (void *)data;
	usb_action = rq->bRequest;

	if(usb_action == GETTIME) {
		usbAction(0);
		return USB_NO_MSG;
	}
	else if(usb_action == SETTIME) {
		usb_buffer[0] = '\0';
		usb_bytes_left = rq->wValue.bytes[0];
		return USB_NO_MSG;
	}
	else if(usb_action == GETTEMP) {
		usbAction(rq->wValue.bytes[0]);
		return USB_NO_MSG;
	}

	return 0;
}



/* usbFunctionRead() is called when the host requests a chunk of data from
 * the device. For more information see the documentation in usbdrv/usbdrv.h.
 */
uchar   usbFunctionRead(uchar *data, uchar len) {

//	uart_send("usb function read"); UART_NL;
	
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

	return 0; //* return 1 if this was the last chunk 
}

void usb_keepalive() {
	wdt_reset();
	usbPoll();
}

//endof usb
