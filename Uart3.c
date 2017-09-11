#include "Uart.h"


unsigned char buy3 = 0;
unsigned char idata rxBuff3[rxBuffSize];
unsigned int rx3Index = 0;
unsigned char isRec3 = 0;
unsigned char isHand3 = 0;

void Uart3() interrupt 17 using 1
{
	unsigned char rByte;
	
	if(S3CON & commRI)
	{
		S3CON &= ~commRI;
		rByte = S3BUF;
		
		if(rx3Index >= wifiBuffSize)
		{
			rx3Index = 0;
		}
		
		if(rByte == 0x3b)
		{
			rx3Index = 0;
			isRec3 = 1;
		}
		
		if(isRec3)
		{
			rxBuff3[rx3Index++] = rByte;
		}
		
		
		if(rByte == 0x0d && isRec3)
		{
			isHand3 = 1;
			isRec3 = 0;
			rx3Index = 0;
		}	
	
	}
	
	if(S3CON & commTI)
	{
		S3CON &= ~commTI;
		buy3 = 0;
	}
}

void sendData3(char dat)
{
	while(buy3);
	
	buy3 = 1;
	S3BUF = dat;
	
}

void sendStr3(char *dat)
{
	while(*dat)
	{
		sendData3(*dat++);
	}
}

void sendStrlen3(char *dat,unsigned int len)
{
	unsigned int i;
	for(i=0;i<len;i++)
	{
		sendData3(*(dat+i));
	}
}

void parserData3()
{
	if(isHand3)
	{
		opt(rxBuff3);
		memset(rxBuff3,0,sizeof(rxBuff3));
		isHand3 = 0;
	}
}