#ifndef _DEVICE_H_
#define _DEVICE_H_
#include "config.h"
sbit K1 = P0^0;
sbit K2 = P0^1;
sbit K3 = P0^2;
sbit K4 = P0^3;
sbit K5 = P0^4;
sbit buzzer = P0^7;

extern void change_power_type(unsigned char type);
extern void change_light_off_on(unsigned char off_on);
extern void change_socket_off_on(unsigned char off_on);
extern void change_air_fan_off_on(unsigned char off_on);
extern void buzzer_hint();
extern void d_fan_open(unsigned char off_on);
extern void d_fan_head(unsigned char off_on);
extern void ir_cmd(unsigned char *olddat);
#endif