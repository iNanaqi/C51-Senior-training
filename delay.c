#include <REGX51.H>
void delay(unsigned char time)     //��ʱ����
	{ 	     
	unsigned int h=1500000;
	for(;time>0;time--)
		for(;h>0;h--);
  } 