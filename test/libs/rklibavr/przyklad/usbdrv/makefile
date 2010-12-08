# Nazwa pliku z funkcj¹ main() - BEZ ROZSZERZENIA!
TARGET = main

# Lista plików Ÿród³owych w jêzyku C
SRC = $(TARGET).c

# typ mikrokontrolera
MCU = at90s2313
#MCU = atmega163
#MCU = atmega128
#MCU = atmega32

# Format pliku wyjœciowego (srec, ihex)
FORMAT = ihex

# Poziom optymalizacji (0, 1, 2, 3, s) 
# (Uwaga: 3 nie zawsze jest najlepszym wyborem)
OPT = s

# Katalog z bibliotekami u¿ytkownika
USRLIB	= ../../lib

# Lista plików Ÿród³owych bibliotek w jêzyku C
SRCLIB =
#include $(USRLIB)/lcd/sources
#include $(USRLIB)/uart/sources
#include $(USRLIB)/kbd/sources
#include $(USRLIB)/delay/sources
include $(USRLIB)/usbdrv/sources

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
