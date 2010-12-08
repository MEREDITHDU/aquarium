# Katalog z bibliotekami u¿ytkownika
USRLIB	= ../../lib

########### change this lines according to your project ##################

#put the name of the target mcu here (at90s8515, at90s8535, attiny22, atmega603 etc.)
    MCU = atmega163
	
#put the name of the target file here (without extension)
	TARGET = main

#put your C sourcefiles here 
	SRC	= $(TARGET).c
	
#put additional assembler source file here
	ASRC    =

#additional libraries and object files to link
	LIB	=

#additional includes to compile
	INC	= 

# Lista plików Ÿród³owych bibliotek w jêzyku C
SRCLIB =
#include $(USRLIB)/adc/sources
#include $(USRLIB)/adc_pwm/sources
#include $(USRLIB)/conv/sources
#include $(USRLIB)/lcd/sources
#include $(USRLIB)/i2c/sources
#include $(USRLIB)/i2c_ee/sources
#include $(USRLIB)/kbd/sources
include $(USRLIB)/delay/sources
#include $(USRLIB)/pcf8583/sources
include $(USRLIB)/uart/sources
include $(USRLIB)/ps2kbd/sources
#include $(USRLIB)/spi/sources
#include $(USRLIB)/rtc/sources

#compiler flags
   CPFLAGS	= -g -O3 -w -Wa,-ahlms=$(<:.c=.lst) -Wno-cast-qual
#	CPFLAGS	= -g -O3 -Wall -Wstrict-prototypes -Wa,-ahlms=$(<:.c=.lst) -Wno-cast-qual

#linker flags
	LDFLAGS = -Wl,-Map=$(TARGET).map,--cref,-lm

########### you should not need to change the following line #############
include $(USRLIB)/avr_make
