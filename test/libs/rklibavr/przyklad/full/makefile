# Nazwa pliku z funkcj¹ main() - BEZ ROZSZERZENIA!
TARGET = full

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
#MCU = at90s8535
#MCU = atmega161
MCU = atmega163
#MCU = atmega16
#MCU = atmega32
#MCU = atmega128

# Poziom optymalizacji (0, 1, 2, 3, s) 
OPT = s

# Œcie¿ka do katalogu z bibliotekami u¿ytkownika
USRLIB	= ../../lib

# Lista plików Ÿród³owych bibliotek w jêzyku C
# (niepotrzebne mo¿na "zakomentowaæ" znakiem # (hash) na pocz¹tku linii)
SRCLIB =
#include $(USRLIB)/adc_pwm/sources
include $(USRLIB)/conv/sources
include $(USRLIB)/lcd/sources
include $(USRLIB)/i2c/sources
include $(USRLIB)/led7seg/sources
include $(USRLIB)/kbd/sources
include $(USRLIB)/delay/sources
include $(USRLIB)/pcf8583/sources
include $(USRLIB)/uart/sources

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

# Tu w³¹czamy w³aœciwy plik, w którym s¹ zapisane komendy
include $(USRLIB)/avr_make
