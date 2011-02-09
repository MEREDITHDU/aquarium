
#include "rtc.h"

unsigned int PCF_Write(unsigned char adr, unsigned char dat) {
        TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xf8) != TW_START)
	{
		return ((TWSR & 0xf8)<<8);
	}
	TWDR = SLA_W;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xf8) != TW_MT_SLA_ACK)
	{
	        return ((TWSR & 0xf8)<<8);
	}
	TWDR = adr;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xf8) != TW_MT_DATA_ACK)
	{
	        return ((TWSR & 0xf8)<<8);
	}
	TWDR = dat;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xf8) != TW_MT_DATA_ACK)
	{
	        return ((TWSR & 0xf8)<<8);
	}
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	return 0;
}

unsigned int PCF_Read(unsigned char adr) {
	unsigned int a = 0;
        TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

	if ((TWSR & 0xf8) != TW_START) {
	        return ((TWSR & 0xf8)<<8);
	}
	TWDR = SLA_W;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

	if ((TWSR & 0xf8) != TW_MT_SLA_ACK) {
	        return ((TWSR & 0xf8)<<8);
	}
	TWDR = adr;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

	if ((TWSR & 0xf8) != TW_MT_DATA_ACK) {
	        return ((TWSR & 0xf8)<<8);
	}
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

	if ((TWSR & 0xf8) != TW_REP_START) {
	        return ((TWSR & 0xf8)<<8);
	}
	TWDR = SLA_R;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

	if ((TWSR & 0xf8) != TW_MR_SLA_ACK) {
	        return ((TWSR & 0xf8)<<8);
	}
	TWCR = ((1<<TWINT) | (1<<TWEN)) & ~(1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
	_delay_ms(10);

	if ((TWSR & 0xf8) != TW_MR_DATA_NACK) {
	        return ((TWSR & 0xf8)<<8);
	}
	a = TWDR;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	return a;
}

unsigned int PCF_Start(void) {
	return PCF_Write(PCF_CTRL,PCF_Read(PCF_CTRL) & ~PCF_ST_CNT_FL);
}

unsigned int PCF_Stop(void) {
	return PCF_Write(PCF_CTRL,PCF_Read(PCF_CTRL) | PCF_ST_CNT_FL);
}

unsigned int PCF_Read_Mili(void) {
	unsigned int temp, temp2;
	temp = PCF_Read(PCF_MILI);
	temp2 = temp & (PCF_ERR_MSK | 0x0f);
	temp2 += ((temp&0xf0)>>4)*10;
	return temp2;
}

unsigned int PCF_Read_Sec(void) {
	unsigned int temp, temp2;
	temp = PCF_Read(PCF_SEC);
	temp2 = temp & (PCF_ERR_MSK | 0x0f);
	temp2 += ((temp&0xf0)>>4)*10;
	return temp2;
}

unsigned int PCF_Read_Min(void) {
	unsigned int temp, temp2;
	temp = PCF_Read(PCF_MIN);
	temp2 = temp & (PCF_ERR_MSK | 0x0f);
	temp2 += ((temp&0xf0)>>4)*10;
	return temp2;
}

unsigned int PCF_Read_Hour(void) {
	unsigned int temp, temp2;
	temp = PCF_Read(PCF_HOUR);
	temp2 = temp & (PCF_ERR_MSK | 0x0f);
	temp2 += ((temp&0x30)>>4)*10;
	return temp2;
}

unsigned int PCF_Read_Day(void) {
	unsigned int temp, temp2;
	temp = (PCF_Read(PCF_DAY));
	temp2 = temp & (PCF_ERR_MSK | 0x0f);
	temp2 += ((temp&0x30)>>4)*10;
	return temp2;
}

unsigned int PCF_Read_Month(void) {
	unsigned int temp, temp2;
        temp = (PCF_Read(PCF_MONTH));
	temp2 = temp & (PCF_ERR_MSK | 0x0f);
	temp2 += ((temp&0x10)>>4)*10;
	return temp2;
}

unsigned int PCF_Read_Year(void) {
	unsigned int temp, temp2;
        temp = PCF_Read(PCF_YEAR_BCD);
        if ((temp & PCF_ERR_MSK) != 0) return temp;
	temp2 = ((temp & 0xf0)>>4)*1000;
	temp2 += (temp & 0x0f)*100;
	temp = PCF_Read(PCF_YEAR_BCD+1);
	if ((temp & PCF_ERR_MSK) != 0) return temp;
	temp2 += ((temp & 0xf0)>>4)*10;
	temp2 += temp & 0x0f;
	return temp2;
}

unsigned int PCF_Set_Mili(unsigned char a) {
	unsigned char temp;
	unsigned int err;
	err = PCF_Stop();
	if (err != 0) return err;
	temp = ((a/10)<<4)+a-((a/10)*10);
	err = PCF_Write(PCF_MILI,temp);
	if (err != 0) return err;
	err = PCF_Start();
	if (err != 0) return err;
	return 0;
}

unsigned int PCF_Set_Sec(unsigned char a) {
	unsigned char temp;
	unsigned int err;
	err = PCF_Stop();
	if (err != 0) return err;
	temp = ((a/10)<<4)+a-((a/10)*10);
	err = PCF_Write(PCF_SEC,temp);
	if (err != 0) return err;
	err = PCF_Start();
	if (err != 0) return err;
	return 0;
}

unsigned int PCF_Set_Min(unsigned char a) {
	unsigned char temp;
	unsigned int err;
	err = PCF_Stop();
	if (err != 0) return err;
	temp = ((a/10)<<4)+a-((a/10)*10);
	err = PCF_Write(PCF_MIN,temp);
	if (err != 0) return err;
	err = PCF_Start();
	if (err != 0) return err;
	return 0;
}

unsigned int PCF_Set_Hour(unsigned char a) {
	unsigned char temp;
	unsigned int temp2, err;
	err = PCF_Stop();
	if (err != 0) return err;
	temp = ((a/10)<<4)+a-((a/10)*10);
	temp2 = PCF_Read(PCF_HOUR)&0b11000000;
	if ((temp2&PCF_ERR_MSK) != 0) return temp2;
	err = PCF_Write(PCF_HOUR,temp2 | temp);
	if (err != 0) return err;
	err = PCF_Start();
	if (err != 0) return err;
	return 0;
}

unsigned int PCF_Set_Day(unsigned char a) {
	unsigned char temp;
	unsigned int temp2, err;
	err = PCF_Stop();
	if (err != 0) return err;
	temp = ((a/10)<<4)+a-((a/10)*10);
	temp2 = PCF_Read(PCF_DAY)&0b11000000;
	if ((temp2&PCF_ERR_MSK) != 0) return temp2;
	err = PCF_Write(PCF_DAY,temp2 | temp);
	if (err != 0) return err;
	err = PCF_Start();
	if (err != 0) return err;
	return 0;
}

unsigned int PCF_Set_Month(unsigned char a) {
	unsigned char temp;
	unsigned int temp2, err;
	err = PCF_Stop();
	if (err != 0) return err;
	temp = ((a/10)<<4)+a-((a/10)*10);
	temp2 = PCF_Read(PCF_MONTH)&0b11100000;
	if ((temp2&PCF_ERR_MSK) != 0) return temp2;
	err = PCF_Write(PCF_MONTH,temp2 | temp);
	if (err != 0) return err;
	err = PCF_Start();
	if (err != 0) return err;
	return 0;
}

unsigned int PCF_Set_Year(unsigned int a) {
	unsigned char temp;
	unsigned int temp2, err;
	err = PCF_Stop();
	if (err != 0) return err;
	temp = (a&3)<<6;
	temp2 = PCF_Read(PCF_YEAR)&0b00111111;
	if ((temp2&PCF_ERR_MSK) != 0) return temp2;
	err = PCF_Write(PCF_YEAR,temp2 | temp);
	if (err != 0) return err;
	err = PCF_Start();
	if (err != 0) return err;
	temp = (a/1000)<<4;
	temp2 = a-((a/1000)*1000);
	temp |= temp2/100;
	err = PCF_Write(PCF_YEAR_BCD,temp);
	if (err != 0) return err;
	temp2 = a-((a/100)*100);
	temp = (temp2/10)<<4;
	temp2 = a-((a/10)*10);
	err = PCF_Write(PCF_YEAR_BCD+1,temp | temp2);
	if (err != 0) return err;
	return 0;
}
