#include <REGX51.H>
#include "delay.h"
//#include "display_SHU_CA.h"
#define uchar unsigned char
uchar led[]={0xfe,0xfd,0xfb};        //LED�ƵĻ�������
char g;
void display_LED (uchar LED_mode)
{
	if (LED_mode == 1)            //ģʽ1���϶���
	{
		for (g=0;g<=2;g++)
		{
			P1 = led[g];
			delay(2000000);
		}
	}
	else if (LED_mode == 2)            //ģʽ2���¶���
	{
		for (g=2;g>=0;g--)
		{
			P1 = led[g];
			delay(2000000);
		}
	}
	else if (LED_mode == 3)            //ģʽ�� ȫ��
		P1 = 0xff;
//	else if (LED_mode == 4)            //ģʽ�� 
//		P1 = 0xf0;
	//display_SHU_CA ();
}