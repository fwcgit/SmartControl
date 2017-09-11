#ifndef _CONFIG_H_
#define _CONFIG_H_
#include<reg52.h>
#define FOSC 24000000L //系统晶振24MHZ
#define BAUD 9600 // 波特率

typedef unsigned int uint;
typedef unsigned char uchar;

sfr P4 = 0xc0;

sfr P0M1 = 0x93;
sfr P0M0 = 0x94;
sfr P1M1 = 0x91;
sfr P1M0 = 0x92;
sfr P2M1 = 0x95;
sfr P2M0 = 0x96;
sfr P3M1 = 0xb1;
sfr P3M0 = 0xb2;
sfr P4M1 = 0xb3;
sfr P4M0 = 0xb4;
sfr P5M1 = 0xc9;
sfr P5M0 = 0xca;

sfr IE2 = 0xAF;
sfr AUXR = 0x8E;
sfr AUXR1 = 0xA2;
sfr P_SW2 = 0xBA;
sfr S2CON = 0x9A;
sfr S3CON = 0xAC;
sfr T2H = 0xD6;
sfr T2L = 0xD7;
sfr P1ASF = 0x9D;
sfr ADC_CONTR = 0xBC;
sfr PCON2 = 0x97;

sfr ADC_RES = 0xBD;
sfr ADC_RESL = 0xBE;

void init_io();
void init_uart_io();
void init_timer0();
void init_adc_io();
void start_timer0();

#endif