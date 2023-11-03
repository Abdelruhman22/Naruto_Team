
#define  KEYPAD_PRG  1

#include <util/delay.h>
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "KeyPad_Interface.h"
#include "KeyPad_Cfg.h"


DIO_Pin_type Row[4]={PINC5,PINC4,PINC3,PINC2};
DIO_Pin_type Col[4]={PIND7,PIND6,PIND5,PIND3};

void KEYPAD_Init(void)
{
	for (u8 r=0;r<ROWS;r++)
	{
		DIO_WritePin(Row[r],HIGH);
	}
}


u8 KEYPAD_GetKey(void)
{
	u8 r,c,key=NO_KEY;

	for (r=0;r<ROWS;r++)
	{
		DIO_WritePin(Row[r],LOW);
		for (c=0;c<COLS;c++)
		{
			if (DIO_ReadPin(Col[c])==LOW)
			{
				key=KeysArr[r][c];
				_delay_ms(10);
				while(DIO_ReadPin(Col[c])==LOW);
				_delay_ms(10);
			}
		}
		DIO_WritePin(Row[r],HIGH);
	}

	return key;

}
