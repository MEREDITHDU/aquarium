# Name: Makefile
# Project: Server Monitor
# Author: Marcin Rim


DEVICE = atmega32
AVRDUDE = avrdude -c stk500v2 -P avrdoper -p $(DEVICE)

CFLAGS = -Wall -Os -I. -L/usr/avr/#-DDEBUG_LEVEL=2

COMPILE = avr-gcc $(CFLAGS) -mmcu=$(DEVICE) 

SRC = main.c uart.c servo.c temp.c lcd.c config.c 
OBJECTS += $(SRC:.c=.o) $(SRCLIB:.c=.o)


# symbolic targets:
all:	clean main.hex

.c.o:
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -c $< -o $@

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


# flash
flash:	all
	$(AVRDUDE) -U flash:w:main.hex:i 
	
fuse_int:
	$(AVRDUDE) -U lfuse:w:0xe4:m -U hfuse:w:0xd9:m

fuse_ext:
	$(AVRDUDE) -U lfuse:w:0xdd:m -U hfuse:w:0xd9:m




