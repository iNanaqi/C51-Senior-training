#include <REGX51.H>
#define uchar unsigned char
#include "delay.h"
uchar code m_table[]={0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09};     //�ֶ��뾵��0~9
uchar i,j,k;
uchar GE,SHI;
extern uchar run,count;
bit K_GE,K_SHI;

void display_SHU_CA ()
{
	//count=0;
	for(k=0;k<99;k++)
{
	if (run == 0) return ;           //��־λ����run==0��������ǰѭ��
	if(count == 99) continue;        //��99 ��������һ��ѭ��99~00
	SHI = m_table[count/10];         //ȡʮλ
	for(i=0;i<8;i++)
{
	K_SHI=SHI&0x01;                   //K_SHI����Ϊbit��ȡ���λ
	P3_5=K_SHI;
	P3_4=1;                           //��ƽ��ת
	P3_4=0;	
	SHI>>=1;                          //����һλ
}	

	GE = m_table[count%10];
		for(j=0;j<8;j++)
{
	K_GE=GE&0x01;
	P3_5=K_GE;
	P3_4=1;
	P3_4=0;	
	GE>>=1;
}
	count++;
	delay(100);
}
	
count=99;
	for(k=99;k>0;k--)
{
	if (run == 0) return ;
	if(count==0) continue;
	SHI = m_table[count/10];
	for(i=0;i<8;i++)
{
	K_SHI=SHI&0x01;
	P3_5=K_SHI;
	P3_4=1;
	P3_4=0;	
	SHI>>=1;
}	

	GE = m_table[count%10];
		for(j=0;j<8;j++)
{
	K_GE=GE&0x01;
	P3_5=K_GE;
	P3_4=1;
	P3_4=0;	
	GE>>=1;
}
	count--;
	delay(100);
}
}