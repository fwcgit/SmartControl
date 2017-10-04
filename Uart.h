#ifndef UART_H_
#define UART_H_

#include "config.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"utils.h"
#include<reg52.h>

#define sendBuffSize 10
#define rxBuffSize 15
#define wifiBuffSize 20

#define commRI 0x01
#define commTI 0x02

#define PACK_START 0x3A;
#define PACK_STOP 0x0D;

//sfr S2CON = 0x9A;
sfr S2BUF = 0x9B;
//sfr S3CON = 0xAC;
sfr S3BUF = 0xAD;
sfr IAP_CONTR = 0xC7;

/***
Э��
���ݰ��ܳ���Ϊ10���ֽ�
��һ���ֽ�Ϊ����ʼ0x3A
�ڶ����ֽ�Ϊ�豸����
�������ֽ�Ϊ�豸���ƶ���
���ĸ��ֽ�Ϊ�豸ָ��

***/
#pragma SAVE
#pragma REGPARMS

extern void sendData1(char dat);
extern void sendData2(char dat);
extern void sendData3(char dat);
extern void sendData4(char dat);

extern void sendStr1(char *dat);
extern void sendStr2(char *dat);
extern void sendStrlen2(char *dat,unsigned int len);
extern void sendStrlen1(char *dat,unsigned int len);
extern void sendStr3(char *dat);
extern void sendStrlen3(char *dat,unsigned int len);
extern void sendStr4(char *dat);


extern void handData();
extern void parserData1();
extern void parserData2();
extern void parserData3();

extern void opt(unsigned char *dat);
extern void toilet_room_data(unsigned int temp,unsigned humidity);

extern void connect_server();

#pragma RESTORE
#endif
