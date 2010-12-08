# Nazwa pliku z funkcj¹ main() - BEZ ROZSZERZENIA!
TARGET = test

# Lista plików zawieraj¹cych konfiguracjê programu i sprzêtu
# ich zmiana powoduje przebudowanie ca³ego projektu
CONFIG = config.h

# Lista plików Ÿród³owych w jêzyku C
SRC = $(TARGET).c

# Lista plików Ÿród³owych w asemblerze (rozszerzenie S - DU¯E S !)
ASRC = 

# typ mikrokontrolera
#MCU = at90s2313
#MCU = at90s8515
#MCU = atmega128
MCU = atmega163

# Format pliku wyjœciowego (srec, ihex)
FORMAT = ihex

# Poziom optymalizacji (0, 1, 2, 3, s) 
# (Uwaga: 3 nie zawsze jest najlepszym wyborem)
OPT = s

# Katalog z bibliotekami u¿ytkownika
USRLIB	= ../../lib

# Lista plików Ÿród³owych bibliotek w jêzyku C
SRCLIB =
include $(USRLIB)/led7seg/sources
#include $(USRLIB)/conv/sources
#include $(USRLIB)/lcd/sources
#include $(USRLIB)/i2c/sources
#include $(USRLIB)/i2c_ee/sources
#include $(USRLIB)/kbd/sources
include $(USRLIB)/delay/sources
#include $(USRLIB)/pcf8583/sources
#include $(USRLIB)/uart/sources

include $(USRLIB)/avr_make
