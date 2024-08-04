#include "stm32f4xx.h"


void LED_Show(unsigned char i, unsigned char status)
{
	if(i == 1)	//绿色，pf7
	{
		if(status == 0)	//关
		{
			GPIOF_ODR |= (1 << 7);
		}
		else if(status  == 1)	//开
		{
			GPIOF_ODR |= (1 << 6);
			GPIOF_ODR |= (1 << 8);
			GPIOF_ODR &= ~(1 << 7);
		}
	}
	else if(i == 2)	//红色,pf6
	{
		if(status == 0)	//关
		{
			GPIOF_ODR |= (1 << 6);
		}
		else if(status  == 1)	//开
		{
			GPIOF_ODR |= (1 << 7);
			GPIOF_ODR |= (1 << 8);
			GPIOF_ODR &= ~(1 << 6);
		}
	}
	else if(i == 3)	//蓝色,pf8
	{
		if(status == 0)	//关
		{
			GPIOF_ODR |= (1 << 8);
		}
		else if(status  == 1)	//开
		{
			GPIOF_ODR |= (1 << 7);
			GPIOF_ODR |= (1 << 6);
			GPIOF_ODR &= ~(1 << 8);
		}
	}
}

int main(void)
{
	unsigned char color;
	unsigned int num, i;
	num = 1500;
	i = 0;
	//打开AHB外设时钟
	RCC_AHB1ENR |= (1<<5);
	
	//确定GPIOF-pin7工作模式
	GPIOF_MODER &= ~((0x03) << 7);
	GPIOF_MODER |= (1<<14);
	
	//确定GPIOF-pin6工作模式
	GPIOF_MODER &= ~((0x03) << 6);
	GPIOF_MODER |= (1<<12);
	
	//确定GPIOF-pin8工作模式
	GPIOF_MODER &= ~((0x03) << 8);
	GPIOF_MODER |= (1<<16);
	
	while(1)
	{
		
		for(int j = 0; j < num; j++)
		{
			LED_Show(color, 0);
			i = 0;
			while(i++ < j);
			LED_Show(color, 1);
			i = num - j;
			while(i--);
		}
		
		color++;
		color = color > 3 ? 1 : color;
		
		for(int j = 0; j < num; j++)
		{
			LED_Show(color, 1);
			i = 0;
			while(i++ < j);
			LED_Show(color, 0);
			i = num - j;
			while(i--);
		}

	}
}


void SystemInit(void)
{
	//null
}

