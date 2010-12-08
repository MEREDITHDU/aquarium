# Nazwa pliku z funkcj¹ main() - BEZ ROZSZERZENIA!
TARGET = testadpw

# Lista plików Ÿród³owych w jêzyku C
SRC = $(TARGET).c

# Lista plików Ÿród³owych w asemblerze (rozszerzenie S - DU¯E S !)
ASRC = 

# typ mikrokontrolera
MCU = at90s8515
#MCU = atmega128
#MCU = atmega163

# Format pliku wyjœciowego (srec, ihex)
FORMAT = ihex

# Poziom optymalizacji (0, 1, 2, 3, s) 
# (Uwaga: 3 nie zawsze jest najlepszym wyborem)
OPT = s

# Katalog z bibliotekami u¿ytkownika
USRLIB	= ../../lib

# Lista plików Ÿród³owych bibliotek w jêzyku C
SRCLIB =
include $(USRLIB)/adc_pwm/sources
include $(USRLIB)/conv/sources
#include $(USRLIB)/lcd/sources
#include $(USRLIB)/i2c/sources
#include $(USRLIB)/i2c_ee/sources
#include $(USRLIB)/kbd/sources
include $(USRLIB)/delay/sources
#include $(USRLIB)/pcf8583/sources
include $(USRLIB)/uart/sources

# Dodaje opcje dla bibliotek u¿ytkownika
USERLIBS = usrlib.a

# Dodatkowe biblioteki
#
# Minimalna wersja printf
#LDFLAGS += -Wl,-u,vfprintf -lprintf_min
#
# Zmiennoprzecinkowa wersja printf (wymaga biblioteki matematycznej)
#LDFLAGS += -Wl,-u,vfprintf -lprintf_flt
#
# Biblioteka matematyczna
#LDFLAGS += -lm

# Programator uisp
PROG	= stk200
#PROG	= avr910 -dserial=/dev/ttyS1

include $(USRLIB)/avr_make
