#include "Uart.h"
#include<string.h>

unsigned char buy1 = 0;
unsigned int rxIndex = 0;
unsigned char idata buff1[wifiBuffSize] ;

unsigned char isRec1 = 0;

unsigned char isHand = 0;

void Uart1() interrupt 4 using 1
{
	
	unsigned char rByte;
	
	if(RI)
	{
		RI = 0;
		
		rByte = SBUF;
		
		if(rxIndex >= wifiBuffSize)
		{
			rxIndex = 0;
		}
		if(rByte == 0x3b)
		{
			rxIndex = 0;
			isRec1 = 1;
		}
		
		if(isRec1 && !isHand)
		{
			buff1[rxIndex++] = rByte;
		}
		
		
		if(rByte == 0x0d && isRec1)
		{
			isHand = 1;
			isRec1 = 0;
			rxIndex = 0;
		}	
	}
	
	if(TI)
	{
		TI = 0;
		buy1 = 0;
	}
}

void sendData1(char dat)
{
		while(buy1);
	
		buy1 = 1;
		SBUF = dat;
}

void sendStr1(char *dat)
{
	while(*dat != '\0')
	{
		sendData1(*dat++);
	}
	sendData1(*dat++);
}

void sendStrlen1(char *dat,unsigned int len)
{
	unsigned int i;
	for(i=0;i<len;i++)
	{
		sendData1(*(dat+i));
	}
}


void parserData1()
{	
	if(isHand)
	{
		opt(buff1);
		memset(buff1,0,sizeof(buff1));
		isHand = 0;
	}
	
}




