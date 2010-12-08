# Nazwa pliku z funkcj¹ main() - BEZ ROZSZERZENIA!
TARGET = remote

# Lista plików zawieraj¹cych konfiguracjê programu i sprzêtu
# ich zmiana powoduje przebudowanie ca³ego projektu
CONFIG = 

# Lista plików Ÿród³owych w jêzyku C
SRC = $(TARGET).c

# typ mikrokontrolera
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
