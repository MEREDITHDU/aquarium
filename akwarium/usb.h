#ifndef __USB
#define __USB

#include "config.h"
#include "usbdrv.h"

void usb_init() ;
void usb_keepalive() ;
usbMsgLen_t usbFunctionSetup(uchar data[8]);

#endif
