#include "utils.h"
#include "device.h"
#include "Uart.h"

void change_power_type(unsigned char type)
{
	if(type == 0)
	{
		K4 =1;
		Delay1000ms();
		K5 = 1;
	}
	else
	{
		K5 = 0;
		Delay1000ms();
		K4 =0;
	}
}
void change_light_off_on(unsigned char off_on)
{
	if(off_on == 0)
	{
		K3 = 1;
	}
	else
	{
		K3 = 0;
	}
}
void change_socket_off_on(unsigned char off_on)
{
	if(off_on == 0)
	{
		K2 = 1;
	}
	else
	{
		K2 = 0;
	}
}
void change_air_fan_off_on(unsigned char off_on)
{
	if(off_on == 0)
	{
		K1 = 1;
	}
	else
	{
		K1 = 0;
	}
}

void d_fan_open(unsigned char off_on)
{
	pdata unsigned char dat[5];
	dat[0] = 0x3C;
	dat[1] = 0xA0;
	dat[2] = off_on == 1? 0x01 : 0x02;
	dat[3] = 0x02;
	dat[4] = 0x0d;
	sendStrlen3(dat,5);
}
void d_fan_head(unsigned char off_on)
{
	pdata unsigned char dat[5];
	dat[0] = 0x3C;
	dat[1] = 0xA0;
	dat[2] = off_on == 1? 0x01 : 0x02;
	dat[3] = off_on == 1? 0x01 : 0x02;
	dat[4] = 0x0d;
	sendStrlen3(dat,5);
}

void ir_cmd(unsigned char *olddat)
{
	pdata unsigned char dat[5];
	dat[0] = *olddat;
	dat[1] = *(olddat+1);
	dat[2] = *(olddat+2);
	dat[3] = *(olddat+3);
	dat[4] = 0x0d;
	sendStrlen3(dat,5);
}

void buzzer_hint()
{
		buzzer = 1;
		Delay20ms();
		buzzer = 0;
}

