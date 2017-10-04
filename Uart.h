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
协议
数据包总长度为10个字节
第一个字节为包起始0x3A
第二个字节为设备类型
第三个字节为设备控制动作
第四个字节为设备指令

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
