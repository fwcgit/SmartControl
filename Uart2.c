#include "Uart.h"

unsigned char buy2 = 0;
unsigned int rxIndex2 = 0;

unsigned char  idata buff2[rxBuffSize] ;
unsigned char isRec2 = 0;
unsigned char isHand2 = 0;

void Uart2() interrupt 8 using 1
{
	unsigned char rByte;
	if(S2CON & commRI)
	{
		S2CON &= ~commRI;
		rByte = S2BUF;

		if(rxIndex2 >= rxBuffSize)
		{
			rxIndex2 = 0;
		}
		
		if(rByte == 0x3b)
		{
			rxIndex2 = 0;
			isRec2 = 1;
		}
		
		if(isRec2)
		{
			buff2[rxIndex2++] = rByte;
		}

		if(rByte == 0x0d && isRec2)
		{
			isHand2 = 1;
			isRec2 = 0;
			rxIndex2 = 0;
		}
	}
	
	if(S2CON & commTI)
	{
		S2CON &= ~commTI;
		buy2 = 0;
	}
}

void sendData2(char dat)
{
	while(buy2);
	
		buy2 = 1;
		S2BUF = dat;
	
}

void sendStr2(char *dat)
{
	while(*dat)
	{
		sendData2(*dat++);
	}
}

void sendStrlen2(char *dat,unsigned int len)
{
	unsigned int i;
	for(i=0;i<len;i++)
	{
		sendData2(*(dat+i));
	}
	
}


void parserData2()
{
	if(isHand2)
	{
		opt(buff2);
		memset(buff2,0,sizeof(buff2));
		isHand2 = 0;
	}
}

void connect_server()
{
	sendStr2("AT+CIPSTART=\"TCP\",\"192.168.31.94\",8080\r\n");
}



