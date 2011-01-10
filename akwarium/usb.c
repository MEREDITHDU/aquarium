
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

void usb_init() {

	//PORTD |=  _BV(PD2) | _BV(PD4); 
	//DDRD  &=  ~_BV(PD2) & ~_BV(PD4); 

	//PORTD = 0x00; // _BV(PD2) | _BV(PD4); 
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

usbMsgLen_t usbFunctionSetup(uchar data[8]) {
	//usbRequest_t    *rq = (void *)data;

	/* The following requests are never used. But since they are required by
	 * the specification, we implement them in this example.
	 */
	return 0;   /* default for not implemented requests: return no data back to host */
}

void usb_keepalive() {
	wdt_reset();
	usbPoll();
}

//endof usb
