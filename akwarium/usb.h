#ifndef __USB
#define __USB

#include "logic.h"

#include "uart.h"
#include "usbdrv.h"

void usb_init() ;
void usb_keepalive() ;

void usbAction(int);

usbMsgLen_t usbFunctionSetup(uchar data[8]);
uchar   usbFunctionRead(uchar *data, uchar len);
uchar   usbFunctionWrite(uchar *data, uchar len);

#endif
