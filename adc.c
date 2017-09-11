#include "config.h"
#include "ADC.h"
#include "intrins.h"
#include "Uart.h"
#include "utils.h"
#include <reg52.h>

#define ADC_POWER 			0x80
#define ADC_FLAG  			0x10
#define ADC_SPEED 			0x40
#define ADC_START 			0x08
#define ADC_CH_NTC 			0x02
#define ADC_CH_HALL			0x03
#define ADC_CH_BATTERY 	0x04
#define ADC_CH_REF 			0x05


void init_adc()
{
	ADC_RES = 0;
	ADC_RESL = 0;
	ADC_CONTR = ADC_POWER | ADC_SPEED;
	Delay1000ms();                
}

uint getAdcResult(uchar ch)
{
	
	uint result ;
	
	ADC_RES = 0;
	ADC_RESL = 0;
		
	ADC_CONTR = ADC_POWER | ADC_SPEED | ch | ADC_START;
	
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 

	while (!(ADC_CONTR & ADC_FLAG));
	
	ADC_CONTR &= ~ADC_FLAG; 
		
	result = ADC_RES;
	result = result << 8 ;
	result = result | ADC_RESL;
	
	return result;

}


unsigned int get_adc_hall()
{
	uint sum;
	uint i = 0;
	
	getAdcResult(ADC_CH_HALL);
	
	for(i = 0 ; i < 16 ; i++)
	{
		sum += getAdcResult(ADC_CH_HALL);
	}
	
	return sum >>= 4;
}
unsigned int get_adc_battery()
{
	uint sum;
	uint i = 0;
	
	getAdcResult(ADC_CH_BATTERY);
	
	for(i = 0 ; i < 16 ; i++)
	{
		sum += getAdcResult(ADC_CH_BATTERY);
	}
	
	return sum >>= 4;
}
unsigned int get_adc_ntc()
{
	uint sum;
	uint i = 0;
	
	getAdcResult(ADC_CH_NTC);
	getAdcResult(ADC_CH_NTC);
	
	for(i = 0 ; i < 64 ; i++)
	{
		sum += getAdcResult(ADC_CH_NTC);
	}
	
	return sum  = sum / 64;
}
unsigned int get_adc_ref()
{
	uint sum;
	uint i = 0;
	
	getAdcResult(ADC_CH_REF);

	for(i = 0 ; i < 16 ; i++)
	{
		sum += getAdcResult(ADC_CH_REF);
	}
	
	return sum  = sum >> 4;
}

