#include <intrins.h>
//Delay n milliseconds for STC15 @12.000MHz , change it as you need.
//Accurate Range from 1 - 10 ms .
void delay(unsigned char count)		
{
	unsigned char i, j;

	i = 12*count;
	j = 169;
	do
	{
		while (--j);
	} while (--i);
}

//Delay n seconds for STC15 @12.000MHz , change it as you need. 
//Accurate Range from ? .
void DELAYs(unsigned char count){
	
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 46*count;
	j = 153;
	k = 245;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
