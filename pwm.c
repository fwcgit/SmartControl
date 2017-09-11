#include "pwm.h"
#include "config.h"


#define PWMC 	 (*(unsigned int volatile xdata *) 0xFFF0)
#define PWMCKS (*(unsigned char volatile xdata *)0xFFF2)
#define PWM3T1 (*(unsigned int volatile xdata *)0xFF10)
#define PWM3T2 (*(unsigned int volatile xdata *)0xFF12)
#define PWM3CR (*(unsigned char volatile xdata *) 0xFF14)	
	
#define LV_AVG 0x4000L / 90
	
sbit fank = P4^5;

unsigned char board_fan_auto = 1;

void init_pwm()
{
	
	P_SW2 |= 0x80;
	PWMCFG = 0x02;
	PWMCKS = 0x08;
	PWMC = 0x4000L;
	
	PWM3T1 = 0x0000;
	PWM3T2 = 0x0A00;
	
	PWM3CR = 0x08;
	
}
void pwm_start()
{
		PWMCR = 0x02;
		PWMCR |= 0x40;
		PWMCR |= 0x80;
		P_SW2 &= ~0x80;	
}

void pwm_stop()
{
	PWMCR = 0x00;
	P_SW2 &= ~0x80;	
	fank = 1;
}

void pwm_adj(unsigned char lv)
{
	unsigned int avg = 0x4000L / 100;
	
	if(board_fan_auto == 0) return;
	
	if(PWMCR == 0x00)
	{
		PWMCR = 0x02;
		PWMCR |= 0x40;
		PWMCR |= 0x80;
	}
	
	if(lv > 75) lv = 75;
	
	P_SW2 |= 0x80;
	
	PWM3T2 = avg * lv;
	
	P_SW2 &= ~0x80;	
}

void pwm_adj_auto(unsigned char lv)
{
	unsigned int avg = 0x4000L / 100;
	
	if(PWMCR == 0x00)
	{
		PWMCR = 0x02;
		PWMCR |= 0x40;
		PWMCR |= 0x80;
	}
	
	if(lv > 75) lv = 75;
	
	P_SW2 |= 0x80;
	
	PWM3T2 = avg * lv;
	
	P_SW2 &= ~0x80;	
}

void pwm_isr() interrupt 22 using 1
{
    
    if (PWMIF & 0x40)
    {
        PWMIF &= ~0x40;
    }
}

void set_pwm_auto(unsigned char bol)
{
	board_fan_auto = bol;
}