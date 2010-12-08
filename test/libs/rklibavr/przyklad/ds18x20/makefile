# Nazwa pliku z funkcj¹ main() - BEZ ROZSZERZENIA!
TARGET = main

# typ mikrokontrolera
#MCU = at90s2313
#MCU = at90s8515
#MCU = atmega163
MCU = atmega32
#MCU = atmega128

# Katalog z bibliotekami u¿ytkownika
USRLIB	= ../../lib

# Lista plików Ÿród³owych bibliotek w jêzyku C
SRCLIB =
#include $(USRLIB)/adc_pwm/sources
#include $(USRLIB)/conv/sources
include $(USRLIB)/lcd/sources
#include $(USRLIB)/i2c/sources
#include $(USRLIB)/led7seg/sources
#include $(USRLIB)/kbd/sources
include $(USRLIB)/delay/sources
#include $(USRLIB)/pcf8583/sources
include $(USRLIB)/uart/sources
include $(USRLIB)/onewire/sources
include $(USRLIB)/ds18x20/sources

# Lista plików Ÿród³owych w jêzyku C
SRC = $(TARGET).c

# Lista plików Ÿród³owych w asemblerze (rozszerzenie S - DU¯E S !)
ASRC = 

# Format pliku wyjœciowego (srec, ihex)
FORMAT = ihex

# Poziom optymalizacji (0, 1, 2, 3, s) 
# (Uwaga: 3 nie zawsze jest najlepszym wyborem)
OPT = s

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

include $(USRLIB)/avr_make
