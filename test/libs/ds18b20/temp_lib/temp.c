
#include "temp.h"


void read_temp() {
	uint8_t gSensorIDs[OW_ROMCODE_SIZE];

	uint16_t decicelsius;
	uint8_t diff, i, subzero, cel, cel_frac_bits;

	OW_set_bus(&PORTC,5);
	//	DS18X20_find_sensor(&diff, &gSensorIDs[0]);


	DS18X20_start_meas( DS18X20_POWER_PARASITE, NULL );
	delayms(DS18B20_TCONV_12BIT);
	DS18X20_read_meas_single(0x10, &subzero, &cel, &cel_frac_bits);
	decicelsius = DS18X20_temp_to_decicel(subzero, cel, cel_frac_bits);

}
