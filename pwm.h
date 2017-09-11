#ifndef _PWM_H_
#define _PWM_H_
//sfr P_SW2 0xBA
sfr PWMCFG = 0xF1;
sfr PWMCR = 0xF5;
sfr PWMIF = 0xF6;

void init_pwm();
void pwm_start();
void pwm_stop();
void pwm_adj(unsigned char lv);
void pwm_adj_auto(unsigned char lv);
void set_pwm_auto(unsigned char bol);
#endif