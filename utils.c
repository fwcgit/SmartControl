#include "utils.h"
#include <intrins.h>

void Delay1000ms()		//@24.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 92;
	j = 50;
	k = 238;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay8us()		//@24.000MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 45;
	while (--i);
}

void Delay480us()		//@24.000MHz
{
	unsigned char i, j;

	i = 12;
	j = 49;
	do
	{
		while (--j);
	} while (--i);
}

void Delay205us()		//@24.000MHz
{
	unsigned char i, j;

	i = 5;
	j = 198;
	do
	{
		while (--j);
	} while (--i);
}

void Delay15us()		//@24.000MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 87;
	while (--i);
}

void Delay45us()		//@24.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 9;
	do
	{
		while (--j);
	} while (--i);
}
void Delay25us()		//@24.000MHz
{
	unsigned char i, j;

	i = 1;
	j = 146;
	do
	{
		while (--j);
	} while (--i);
}

void Delay20ms()		//@24.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 2;
	j = 211;
	k = 231;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay40us()		//@24.000MHz
{
	unsigned char i, j;

	i = 1;
	j = 236;
	do
	{
		while (--j);
	} while (--i);
}

void Delay2us()		//@24.000MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 9;
	while (--i);
}
void Delay60us()		//@24.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 99;
	do
	{
		while (--j);
	} while (--i);
}

void Delay80us()		//@24.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 219;
	do
	{
		while (--j);
	} while (--i);
}

void Delay25ms()		//@24.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 3;
	j = 72;
	k = 161;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay1us()		//@24.000MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 3;
	while (--i);
}
