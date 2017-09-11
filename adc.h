#ifndef ADC_H_
#define ADC_H_
#include "config.h"
#pragma SAVE
#pragma REGPARMS
void init_adc();
unsigned int getAdcResult(uchar ch);
unsigned int get_adc_hall();
unsigned int get_adc_battery();
unsigned int get_adc_ntc();
unsigned int get_adc_ref();
#pragma RESTORE
#endif