# Nazwa pliku z funkcj� main() - BEZ ROZSZERZENIA!
TARGET = test

# Lista plik�w zawieraj�cych konfiguracj� programu i sprz�tu
# ich zmiana powoduje przebudowanie ca�ego projektu
CONFIG = config.h

# Lista plik�w �r�d�owych w j�zyku C
SRC = $(TARGET).c

# Lista plik�w �r�d�owych w asemblerze (rozszerzenie S - DU�E S !)
ASRC = 

# typ mikrokontrolera
#MCU = at90s2313
#MCU = at90s8515
#MCU = atmega128
MCU = atmega163

# Format pliku wyj�ciowego (srec, ihex)
FORMAT = ihex

# Poziom optymalizacji (0, 1, 2, 3, s) 
# (Uwaga: 3 nie zawsze jest najlepszym wyborem)
OPT = s

# Katalog z bibliotekami u�ytkownika
USRLIB	= ../../lib

# Lista plik�w �r�d�owych bibliotek w j�zyku C
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
