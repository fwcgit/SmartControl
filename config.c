#include "config.h"

void init_io()
{
	P0M1 = 0x00;
	P0M0 = 0x80;
	
	P1M1 = 0xFC;
	P1M0 = 0x00;
	
	P3M1 = 0x00;
	P3M0 = 0x00;
	
	P4M1 = 0x10;
	P4M0 = 0x10;
}

void init_uart_io()
{
	AUXR1 = 0x40; // 串口1P3.6 p3.7
	
	P_SW2 |= 0x02;
	
	//串工作方式10位异步收发（8位数据）
	SCON = 0x50; 
	
	S2CON = 0x50; 
	
	S3CON = 0x10; 
	
	T2L = (65536 - (FOSC/4/BAUD));
	T2H = (65536 - (FOSC/4/BAUD))>>8;
	
	AUXR = 0x14; 
	AUXR |= 0x01; 
	
	ES = 1; 
	IE2 |= 0x19;
}
void init_adc_io()
{
	P1ASF = 0x3C;
	PCON2 = 0x20;
}

void init_timer0()
{
	AUXR &= 0x7F; 
	TMOD &= 0xFF;
	TL0 = 0xE0;
	TH0 = 0xB1;
	ET0 = 1;
}
void start_timer0()
{
	TR0 = 1;
}