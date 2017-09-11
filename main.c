#include<reg52.h>
#include "config.h"
#include "utils.h"
#include "Uart.h"
#include "adc.h"
#include "DS18B20.h"
#include "DHT.h"
#include <math.h>
#include "pwm.h"
#include "device.h"

void uploadingStatu();
uchar get_ntc_temp(uint ntc,uint ref);
void pwm_fank(uint adc_temp);

sbit work_led = P2^5;

uint timer0_count = 0;
uchar init_is_connect_server = 1;

uint dht_humidity = 0;
uint dht_temp = 0;

void DHT_Result(unsigned int temp,unsigned int hum)
{
	dht_humidity = hum;
	dht_temp = temp;
}

void main(void)
{
	buzzer = 0;
	
	init_io();
	init_uart_io();
	init_adc_io();
	init_adc();
	init_timer0();
	
	start_timer0();
	
	init_pwm();
	
	EA = 1;
	
	while(1)
	{
		
		handData();
		
		if(timer0_count >= 300)//1Ãë
		{
			timer0_count = 0;
			work_led = !work_led;
			
			uploadingStatu();
		}
		
		if(timer0_count >= 5 && init_is_connect_server)
		{
				init_is_connect_server = 0;
				connect_server();
		}
	}
}

void uploadingStatu()
{
	uint hall,battery,ntc,ref,ds_temp;
	uchar datas[18];
	
	hall = 0;
	battery = 0;
	ntc = 0;
	ref = 0;
	
	ref = get_adc_ref();
	hall = get_adc_hall();
	battery = get_adc_battery();
	ntc = get_adc_ntc();
	
	ds_temp = getTemp();
	
	DHT_ReadData(&DHT_Result);
	
	datas[0] = 0x3A;
	datas[1] = 0x53;
	datas[2] = hall >> 8;
	datas[3] = hall;
	datas[4] = battery >> 8;
	datas[5] = battery;
	datas[6] = ntc >> 8;
	datas[7] = ntc;
	datas[8] = ref >> 8;
	datas[9] = ref;
	datas[10] = get_ntc_temp(ntc,ref);
	datas[11] = ds_temp >> 8;
	datas[12] = ds_temp;
	datas[13] = dht_humidity >> 8;
	datas[14] = dht_humidity;
	datas[15] = dht_temp >> 8;
	datas[16] = dht_temp;
	datas[17] = 0x0D;

	sendStrlen3(datas,18);
	
	pwm_fank(ds_temp);
}

void pwm_fank(uint adc_temp)
{
	uchar flag = adc_temp &0xf800;
	
	uint temp = adc_temp * 0.0625;
	
	uint lv = 0;
	
	if(flag) temp = 0;
	
	if(temp > 0 && temp <= 10)
	{
			pwm_stop();
	}
	else 
	{
		
		pwm_adj(temp - 10);
	}
}



uchar get_ntc_temp(uint ntc,uint ref)
{
	float temp;
	float t2 ;
	float ntc_r;
	float t_25;
	float ntc_ln;
	float ln ;
	float res_v;
	
	res_v = ntc * 248.0 / ref-5.0;
	ntc_r = (5.0 - res_v/100.0) / (res_v/100.0/10.0);
	
	t_25 = log(10);
	ntc_ln = log(ntc_r);
	ln = t_25 - ntc_ln;
	
	ln = ln / 3950.0;
	t2 = 1.0/298.15;
	t2 = t2-ln;
	temp = 1.0/t2;
	temp = temp - 273.15;
	
	return (uchar)temp;
}

void timer0_isr() interrupt 1 using 1
{
	timer0_count++;
}