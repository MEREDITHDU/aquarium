# Nazwa pliku z funkcj� main() - BEZ ROZSZERZENIA!
TARGET = math

# typ mikrokontrolera
#MCU = at90s2313
#MCU = at90s8515
MCU = atmega163
#MCU = atmega128

# Katalog z bibliotekami u�ytkownika
USRLIB	= ../../lib

# Lista plik�w �r�d�owych bibliotek w j�zyku C
SRCLIB =
#include $(USRLIB)/conv/sources
#include $(USRLIB)/lcd/sources
#include $(USRLIB)/i2c/sources
#include $(USRLIB)/led7seg/sources
#include $(USRLIB)/kbd/sources
#include $(USRLIB)/delay/sources
#include $(USRLIB)/pcf8583/sources
include $(USRLIB)/uart/sources

# Lista plik�w �r�d�owych w j�zyku C
SRC = $(TARGET).c

# Lista plik�w �r�d�owych w asemblerze (rozszerzenie S - DU�E S !)
ASRC = 

# Format pliku wyj�ciowego (srec, ihex)
FORMAT = ihex

# Poziom optymalizacji (0, 1, 2, 3, s) 
# (Uwaga: 3 nie zawsze jest najlepszym wyborem)
OPT = s

# Dodatkowe biblioteki
# Zmiennoprzecinkowa wersja printf (wymaga biblioteki matematycznej)
LDFLAGS += -Wl,-u,vfprintf -lprintf_flt
# Zmiennoprzecinkowa wersja scanf (wymaga biblioteki matematycznej)
LDFLAGS += -Wl,-u,vfscanf -lscanf_flt
# Minimalna wersja printf
#LDFLAGS += -Wl,-u,vfprintf -lprintf_min
# Biblioteka matematyczna
LDFLAGS += -lm

include $(USRLIB)/avr_make
