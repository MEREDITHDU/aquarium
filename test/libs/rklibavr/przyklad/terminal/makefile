# Nazwa pliku z funkcj� main() - BEZ ROZSZERZENIA!
TARGET = terminal

# Lista plik�w, kt�rych zmiana powoduje przebudowanie projektu
CONFIG = config.h

# Lista plik�w �r�d�owych w j�zyku C
SRC = $(TARGET).c

# typ mikrokontrolera
MCU = atmega32

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
include $(USRLIB)/kbd/sources
include $(USRLIB)/uart/sources

include $(USRLIB)/avr_make
