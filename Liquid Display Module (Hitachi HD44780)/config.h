#ifndef _CONFIG_H
#define _CONFIG_H

#include <reg51.h>

sbit  LCM_E =  P3^5;
sbit  LCM_RW = P3^6;
sbit  LCM_RS = P3^7;

#define LCM_DB	P0

sbit LCM_DB6 = LCM_DB^6;
sbit LCM_DB7 = LCM_DB^7;


void delay(unsigned char );
void DELAYs(unsigned char );

#endif
