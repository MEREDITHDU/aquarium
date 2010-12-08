# Nazwa pliku z funkcj¹ main() - BEZ ROZSZERZENIA!
TARGET = terminal

# Lista plików, których zmiana powoduje przebudowanie projektu
CONFIG = config.h

# Lista plików Ÿród³owych w jêzyku C
SRC = $(TARGET).c

# typ mikrokontrolera
MCU = atmega32

# Format pliku wyjœciowego (srec, ihex)
FORMAT = ihex

# Poziom optymalizacji (0, 1, 2, 3, s) 
# (Uwaga: 3 nie zawsze jest najlepszym wyborem)
OPT = s

# Katalog z bibliotekami u¿ytkownika
USRLIB	= ../../lib

# Lista plików Ÿród³owych bibliotek w jêzyku C
SRCLIB =
include $(USRLIB)/lcd/sources
include $(USRLIB)/kbd/sources
include $(USRLIB)/uart/sources

include $(USRLIB)/avr_make
