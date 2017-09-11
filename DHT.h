#ifndef _DHT_H_
#define _DHT_H_
#include <reg52.h>
extern void DHT_Start();
extern unsigned char DHT_ReadChar();
extern void DHT_ReadData(void(*dht)(unsigned int temp,unsigned int hum));

#endif