# Nazwa pliku z funkcj� main() - BEZ ROZSZERZENIA!
TARGET = remote

# Lista plik�w zawieraj�cych konfiguracj� programu i sprz�tu
# ich zmiana powoduje przebudowanie ca�ego projektu
CONFIG = 

# Lista plik�w �r�d�owych w j�zyku C
SRC = $(TARGET).c

# typ mikrokontrolera
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
include $(USRLIB)/lcd/sources
include $(USRLIB)/remote/sources
include $(USRLIB)/uart/sources

# Dodatkowe biblioteki
# Zmiennoprzecinkowa wersja printf (wymaga biblioteki matematycznej)
#LDFLAGS += -Wl,-u,vfprintf -lprintf_flt
# Zmiennoprzecinkowa wersja scanf (wymaga biblioteki matematycznej)
#LDFLAGS += -Wl,-u,vfscanf -lscanf_flt
# Minimalna wersja printf
LDFLAGS += -Wl,-u,vfprintf -lprintf_min
# Biblioteka matematyczna
#LDFLAGS += -lm

include $(USRLIB)/avr_make
