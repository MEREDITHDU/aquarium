# Name: Makefile
# Project: Server Monitor
# Author: Marcin Rim


DEVICE = atmega32
AVRDUDE = avrdude -c stk500v2 -P avrdoper -p $(DEVICE)
FCPU = 12000000

CFLAGS = -Wall -Os  -I. -Iusb -Iusb/usbdrv -L/usr/avr/
# -Wl,-u,vfprintf -lprintf_flt -lm #full printf with float
#-DDEBUG_LEVEL=2
COMPILE = avr-gcc $(CFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU)

SRC = main.c \
	logic.c \
	config.c \
	menu.c \
	uart.c \
	servo.c \
	temp.c \
	lcd.c \
	button.c \
	rtc.c \
	usb.c \
	usb/usbdrv/usbdrv.c \
	usb/usbdrv/usbdrvasm.c 


OBJECTS += $(SRC:.c=.o) $(SRCLIB:.c=.o)

# symbolic targets:
all:	clean main.hex

.c.o:
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@

.c.s:
	$(COMPILE) -S $< -o $@



# file targets:
main.bin:	$(OBJECTS)
	$(COMPILE) -o main.bin $(OBJECTS)

main.hex:	main.bin
	rm -f main.hex main.eep.hex
	avr-objcopy -j .text -j .data -O ihex main.bin main.hex

clean:
	rm -f main.hex main.lst main.obj main.cof main.list main.map main.eep.hex main.bin *.o main.s 
	rm -f usb/*.o usb/usbdrv/*.o 


# flash
flash:	all
	$(AVRDUDE) -U flash:w:main.hex:i 
	
fuse_int:
	#$(AVRDUDE) -U lfuse:w:0xe4:m -U hfuse:w:0xd9:m
	$(AVRDUDE) -U lfuse:w:0xe4:m -U hfuse:w:0xd1:m

fuse_ext:
	$(AVRDUDE) -U lfuse:w:0xdd:m -U hfuse:w:0xd1:m #eeprom save
	#$(AVRDUDE) -U lfuse:w:0xdd:m -U hfuse:w:0xd9:m




