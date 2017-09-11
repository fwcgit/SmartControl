#include "DHT.h"
#include <intrins.h>
#include "utils.h"
#include "config.h"

sbit DIO = P4^4;

void DHT_Start()
{

	DIO = 1;
	Delay2us();
	DIO = 0;
	Delay20ms();
	DIO = 1;
	Delay40us();

}

unsigned char DHT_ReadChar()
{
	unsigned char i,val;
	unsigned char to;
	val = 0;
	for(i = 0 ;i < 8 ;i++)
	{
		to = 400;
		while(!DIO && to--);
		Delay60us();
		val <<=1;
		if(DIO == 1) ++val;
		to = 400;
		while(DIO && to--);
	}
	return val;
}

void DHT_ReadData(void(*dht)(unsigned int temp,unsigned int hum))
{
	unsigned char check,TH,TL,HH,HL;
	unsigned int temp,hum;
	
	DHT_Start();
	if(DIO == 0)
	{
		Delay80us();
		if(DIO)
		{
			Delay80us();
			HH = DHT_ReadChar();
			HL = DHT_ReadChar();
			
			TH = DHT_ReadChar();
			TL= DHT_ReadChar();
		
			check = DHT_ReadChar();
			
			Delay25ms();
			
			DIO = 1;
		
			if((HH+HL+TH+TL) == check)
			{
				
					hum = HH;
					hum <<= 8;
					hum |= HL;
				
					temp = TH;
					temp <<= 8;
					temp |= TL;
				
					dht(temp,hum);
			}
		}
	}
}

