#include "utils.h"
#include "device.h"

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

void buzzer_hint()
{
		buzzer = 1;
		Delay20ms();
		buzzer = 0;
}

