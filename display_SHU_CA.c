#include <REGX51.H>
#define uchar unsigned char
#include "delay.h"
uchar code m_table[]={0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09};     //字段码镜像0~9
uchar i,j,k;
uchar GE,SHI;
extern uchar run,count;
bit K_GE,K_SHI;

void display_SHU_CA ()
{
	//count=0;
	for(k=0;k<99;k++)
{
	if (run == 0) return ;           //标志位，若run==0，跳出当前循环
	if(count == 99) continue;        //若99 则跳到下一个循环99~00
	SHI = m_table[count/10];         //取十位
	for(i=0;i<8;i++)
{
	K_SHI=SHI&0x01;                   //K_SHI定义为bit，取最低位
	P3_5=K_SHI;
	P3_4=1;                           //电平反转
	P3_4=0;	
	SHI>>=1;                          //右移一位
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