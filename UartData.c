#include "Uart.h"
#include "device.h"
#include "pwm.h"

void handData()
{
	parserData1();
	parserData2();
	parserData3();
}

void opt(unsigned char *dat)
{
		if(*dat == 0x3b)
		{
			
			if(*(dat+1) == 0x4a)//继电器设备
			{
				
				if(*(dat+2) == 0x53)//子设备
				{
					
					if(*(dat+3)  == 0x01)//市电
					{
						change_power_type(0);
						
					}
					else if(*(dat+3) == 0x02)//太阳能
					{
						change_power_type(1);
					}
				}
				else if(*(dat+2) == 0x54)
				{
					if(*(dat+3)  == 0x01)//灯开
					{
						change_light_off_on(0);
					}
					else if(*(dat+3) == 0x02)//灯关
					{
						change_light_off_on(1);
					}
				}
				else if(*(dat+2) == 0x55)
				{
					if(*(dat+3)  == 0x01)//插座开
					{
						change_socket_off_on(0);
					}
					else if(*(dat+3) == 0x02)//插座关
					{
						change_socket_off_on(1);
					}
				}
				else if(*(dat+2) == 0x56)
				{
					if(*(dat+3)  == 0x01)//风扇开
					{
						change_air_fan_off_on(0);
					}
					else if(*(dat+3) == 0x02)//风扇关
					{
						change_air_fan_off_on(1);
					}
				}
			}
			else if(*(dat+1) == 0x5a)//板载风扇
			{
				if(*(dat+2) == 0x5b)
				{
					set_pwm_auto(0);
					
					pwm_start();
					
				}
				else if(*(dat+2) == 0x5c)
				{
					set_pwm_auto(0);
					
					pwm_stop();
				}
				else if(*(dat+2) == 0x5d)
				{
					set_pwm_auto(0);
					
					pwm_adj_auto(*(dat+3));
				}
				else if(*(dat+2) == 0x5e)
				{
					set_pwm_auto(1);
				}
					
			}
			else if(*(dat+1) == 0xca)
			{
				//set_Time(dat);
				
			}
			else if(*(dat+1) == 0xdd)
			{
				buzzer_hint();
				IAP_CONTR = 0x60;
			}
		}
}