#include "StdTypes.h"
#include <util/delay.h>

#include "Utils.h"
#include "DIO_Interface.h"


void print_7seg (char n)
{
	DIO_Pin_type Pin [4]={PINB0,PINB1,PINB2,PINB4};
	for (int i=0;i<4;i++)
	{
		if (READ_BIT(n,i))
		{
			DIO_WritePin(Pin[i],HIGH);
		}
		else
		{
			DIO_WritePin(Pin[i],LOW);
		}
	}
}

void counter_7Seg (int n)
{
	signed int x=n;
	signed int temp=0;
	signed int digit=0;

	DIO_Pin_type COM [4]={PINA3,PINA2,PINB5,PINB6};

	for (int k=0;k<3;k++)
	{
		DIO_WritePin(COM[k],HIGH);
	}

	while (x>=0)
	{

		for (int j=0;j<10;j++)
		{
			temp=x;
			for (int i=0;i<4;i++)
					{
						digit=temp%10;
						temp=temp/10;
						print_7seg(digit);
						DIO_WritePin(COM[i],LOW);
						_delay_ms(5);
						DIO_WritePin(COM[i],HIGH);
					}
		}
		x--;
	}
}
