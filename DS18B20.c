#include "Uart.h"
#include "DS18B20.h"
#include "utils.h"
sbit ds = P0^6;


void dsInit()
{
	ds = 1;
	Delay8us();
	ds = 0;
	Delay480us();
	ds = 1;
	Delay205us();

}

bit dsReadBit()
{
	unsigned int ci = 0;
	bit bat;
	ds = 0;
	Delay8us();
	ds = 1;
	Delay15us();
	bat = ds;
	Delay45us();
	return (bat);
}

unsigned char dsReadByte()
{
	unsigned char i = 0;
	unsigned char dat;
	dat = 0;

	for( i = 8;i > 0 ; i--)
	{
		ds = 0;
		Delay1us();
		dat >>= 1;
		ds = 1;
		Delay8us();
		if(ds)
		{
			dat |= 0x80;
		}
		
		Delay45us();
	}

	return (dat);
}

void dsWriteByte(unsigned char dat)
{
	unsigned char i = 0;
	for( i = 8 ;i > 0 ; i--)
	{
		ds = 0;
		Delay1us();
		ds = dat & 0x01;
		Delay45us();
		ds = 1;
		dat >>= 1;
		Delay8us();
	}
}

void startTemp()
{
 	dsInit();
	Delay480us();
	dsWriteByte(0xcc);
	dsWriteByte(0x44);	
}

uint getTemp()
{

	uchar a,b;
	uint result;
	
	dsInit();
	dsWriteByte(0xcc);
	dsWriteByte(0x44);
	
	dsInit();
	dsWriteByte(0xcc);
	dsWriteByte(0xbe);
	
	a = dsReadByte();
	b = dsReadByte();
	
	result = b & 0xff;
	result = result << 8;
	result = result | (a & 0xff);
	
	return result;
}


