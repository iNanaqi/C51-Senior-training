#include <REGX51.H>
#include "delay.h"
//#include "display_SHU_CA.h"
#define uchar unsigned char
uchar led[]={0xfe,0xfd,0xfb};        //LED灯的花样数据
char g;
void display_LED (uchar LED_mode)
{
	if (LED_mode == 1)            //模式1自上而下
	{
		for (g=0;g<=2;g++)
		{
			P1 = led[g];
			delay(2000000);
		}
	}
	else if (LED_mode == 2)            //模式2自下而上
	{
		for (g=2;g>=0;g--)
		{
			P1 = led[g];
			delay(2000000);
		}
	}
	else if (LED_mode == 3)            //模式三 全灭
		P1 = 0xff;
//	else if (LED_mode == 4)            //模式四 
//		P1 = 0xf0;
	//display_SHU_CA ();
}