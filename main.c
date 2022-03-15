#include <REGX51.H>
#include "delay.h"
#include "display_LED.h"
#include "display_SHU_CA.h"
#define uchar unsigned char
uchar LED_mode,count,run = 0;

time0() interrupt 1
{
	if (P2 != 0x0f)
	{
			switch (P2&0x0f)
		{
			case 0x0e : LED_mode = 1;run = 0;break;
			case 0x0d : LED_mode = 2;run = 0;break;
			case 0x0b : LED_mode = 3;run = 0;break;
			case 0x07 : LED_mode = 4,run = 1;break;
		}
	}
	TH0 = 0x06;
	TL0 = 0x06;
}

void main()
{
	P1 = 0xf0;                   //�ϵ磬��ȫ��LED
	TMOD = 0x02;                 //T0��ʱ����ʽ2
	TH0 = 0x06;                  //��ֵ���ã�0.25ms���ж�
	TL0 = 0x06;
	EA = 1;                      //���ܿ���
	ET0 = 1 ;                    //����T0�ж�
	TR0 = 1;                     //����T0����
	count=0;
	while(1)
	{
		display_LED (LED_mode);
		display_SHU_CA ();
	}
}