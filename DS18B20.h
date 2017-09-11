#ifndef DS18B20_H_
#define DS18B20_H_
bit dsReadBit();
extern unsigned char dsReadByte();
extern void dsWriteByte(unsigned char dat);
extern void dsInit();
extern unsigned int getTemp();
extern void startTemp();
#endif