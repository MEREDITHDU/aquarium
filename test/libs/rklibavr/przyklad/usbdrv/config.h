#define F_CPU		12000000 //częstotliwość zegara w Hz

/////////////////////////////////////////////////////////////////////////

/* Name: usbconfig.h
 * Project: AVR USB driver
 * Author: Christian Starkjohann
 * Creation Date: 2005-04-01
 * Tabsize: 4
 * Copyright: (c) 2005 by OBJECTIVE DEVELOPMENT Software GmbH
 * License: Proprietary, free under certain conditions. See Documentation.
 * This Revision: $Id: usbconfig.h 43 2005-04-10 21:04:36Z cs $
 */


/*
General Description:
This file contains parts of the USB driver which can be configured and can or
must be adapted to your hardware.
*/

/* ---------------------------- Hardware Config ---------------------------- */

#define USBRDV_CFG_IOPORT          PORTB
/* This is the port where the USB bus is connected. When you configure it to
 * "PORTB", the registers PORTB, PINB (=PORTB+2) and DDRB (=PORTB+1) will be
 * used.
 */
#define USBRDV_CFG_DMINUS_BIT      0
/* This is the bit number in USBRDV_CFG_IOPORT where the USB D- line is connected.
 * This MUST be bit 0. All other values will result in a compile error!
 */
#define USBRDV_CFG_DPLUS_BIT       1
/* This is the bit number in USBRDV_CFG_IOPORT where the USB D+ line is connected.
 * This may be any bit in the port. Please note that D+ must also be connected
 * to interrupt pin INT0!
 */

/* --------------------------- Functional Range ---------------------------- */

#define USBRDV_CFG_HAVE_INTRIN_ENDPOINT    0
/* Define this to 1 if you want to compile a version with two endpoints: The
 * default control endpoint 0 and an interrupt-in endpoint 1.
 */
#define USBRDV_CFG_IMPLEMENT_HALT          0
/* Define this to 1 if you also want to implement the ENDPOINT_HALT feature
 * for endpoint 1 (interrupt endpoint). Although you may not need this feature,
 * it is required by the standard. We have made it a config option because it
 * bloats the code considerably.
 */
#define USBRDV_CFG_INTR_POLL_INTERVAL      10
/* If you compile a version with endpoint 1 (interrupt-in), this is the poll
 * interval. The value is in milliseconds and must not be less than 10 ms for
 * low speed devices.
 */
#define USBRDV_CFG_IS_SELF_POWERED         1
/* Define this to 1 if the device has its own power supply. Set it to 0 if the
 * device is powered from the USB bus.
 */
#define USBRDV_CFG_MAX_BUS_POWER           20
/* Set this variable to the maximum USB bus power consumption of your device.
 * The value is in milliamperes. [It will be divided by two since USB
 * communicates power requirements in units of 2 mA.]
 */
#define USBRDV_CFG_SAMPLE_EXACT            0
/* This variable affects Sampling Jitter for USB receiving. When it is 0, the
 * driver guarantees a sampling window of 1/2 bit. The USB spec requires
 * that the receiver has at most 1/4 bit sampling window. The 1/2 bit window
 * should still work reliably enough because we work at low speed. If you want
 * to meet the spec, set this value to 1. This will unroll a loop which
 * results in bigger code size.
 * If you have problems with long cables, try setting this value to 1.
 */
#define USBRDV_CFG_IMPLEMENT_FN_WRITE      0
/* Set this to 1 if you want usbFunctionWrite() to be called for control-out
 * transfers. Set it to 0 if you don't need it and want to save a couple of
 * bytes.
 */
#define USBRDV_CFG_IMPLEMENT_FN_READ       0
/* Set this to 1 if you need to send control replies which are generated
 * "on the fly" when usbFunctionRead() is called. If you only want to send
 * data from a static buffer, set it to 0 and return the data from
 * usbFunctionSetup(). This saves a couple of bytes.
 */

/* -------------------------- Device Description --------------------------- */

/* #define  USBRDV_CFG_VENDOR_ID       0xlow, 0xhigh */
/* USB vendor ID for the device, low byte first. If you have registered your
 * own Vendor ID, define it here. Otherwise you use obdev's free shared
 * VID/PID pair. Be sure to read USBID-License.txt for rules!
 */
/* #define  USBRDV_CFG_DEVICE_ID       0xlow, 0xhigh */
/* This is the ID of the product, low byte first. It is interpreted in the
 * scope of the vendor ID. If you have registered your own VID with usb.org
 * or if you have licensed a PID from somebody else, define it here. Otherwise
 * you use obdev's free shared VID/PID pair. Be sure to read the rules in
 * USBID-License.txt!
 */
#define USBRDV_CFG_DEVICE_VERSION  0x00, 0x01
/* Version number of the device: Minor number first, then major number.
 */
//#define USBRDV_CFG_VENDOR_NAME     'w', 'w', 'w', '.', 'o', 'b', 'd', 'e', 'v', '.', 'a', 't'
//#define USBRDV_CFG_VENDOR_NAME_LEN 12
#define USBRDV_CFG_VENDOR_NAME     'w', 'w', 'w', '.', 'f', 'r', 'e', 'e', 'p', 'g', 's', '.', 'c', 'o', 'm', '/', 'r', 'o', 'b', 'k', 'r', 'y', '/'
#define USBRDV_CFG_VENDOR_NAME_LEN 23
/* These two values define the vendor name returned by the USB device. The name
 * must be given as a list of characters under single quotes. The characters
 * are interpreted as Unicode (UTF-16) entities.
 * If you don't want a vendor name string, undefine these macros.
 * ALWAYS define a vendor name containing your Internet domain name if you use
 * obdev's free shared VID/PID pair. See the file USBID-License.txt for
 * details. 
 */
//#define USBRDV_CFG_DEVICE_NAME     'P', 'o', 'w', 'e', 'r', 'S', 'w', 'i', 't', 'c', 'h'
//#define USBRDV_CFG_DEVICE_NAME_LEN 11
#define USBRDV_CFG_DEVICE_NAME     'r', 'k', 'l', 'i', 'b', 'a', 'v', 'r', '_', 'u', 's', 'b', 'd', 'r', 'v'
#define USBRDV_CFG_DEVICE_NAME_LEN 15
/* Same as above for the device name. If you don't want a device name, undefine
 * the macros. See the file USBID-License.txt before you assign a name.
 */
#define USBRDV_CFG_SERIAL_NUMBER_LENGTH  0
/* Set this define to the number of charcters in the serial number if your
 * device should have a serial number to uniquely identify each hardware
 * instance. You must supply the serial number in a string descriptor with the
 * name "usbCfgSerialNumberStringDescriptor", e.g.:
 * #define USBRDV_CFG_SERIAL_NUMBER_LENGTH  5
 * int usbCfgSerialNumberStringDescriptor[] PROGMEM = {
 *     USBRDV_STRING_DESCRIPTOR_HEADER(USBRDV_CFG_SERIAL_NUMBER_LENGTH),
 *     '1', '2', '3', '4', '5'
 * };
 * See usbdrv.h for more information about the USBRDV_STRING_DESCRIPTOR_HEADER()
 * macro or usbdrv.c for example string descriptors.
 * You may want to put "usbCfgSerialNumberStringDescriptor" at a constant
 * flash memory address (with magic linker commands) so that you don't need
 * to recompile if you change it. 
 */
#define USBRDV_CFG_DEVICE_CLASS    0xff
#define USBRDV_CFG_DEVICE_SUBCLASS 0
/* See USB specification if you want to conform to an existing device class.
 */
#define USBRDV_CFG_INTERFACE_CLASS     0
#define USBRDV_CFG_INTERFACE_SUBCLASS  0
#define USBRDV_CFG_INTERFACE_PROTOCOL  0
/* See USB specification if you want to conform to an existing device class or
 * protocol.
 */
#define USBRDV_CFG_HID_REPORT_DESCRIPTOR_LENGTH    0   /* total length of report descriptor */
/* Define this to the length of the HID report descriptor, if you implement
 * an HID device. Otherwise don't define it or define it to 0.
 */
