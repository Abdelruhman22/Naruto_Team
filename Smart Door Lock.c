#define F_CPU  8000000UL
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "StdTypes.h"
#include "MemMap.h"
#include "Stepper.h"
#include "DIO_INTERFACE.h"
#include "LCD_Interface.h"
#include "KeyPad_CFG.h"
#include "KeyPad_Interface.h"
// #include "ADC_Interface.h"
// #include "sensors_CFG.h"
// #include "sensors_Interface.h"
#include "EXT_INTERRUPT.h"
#include "EEPROM.h"
#include "Timer.h"

#include "Smart Door Lock.h"


#define start_address 110
#define size_password 5

U8 Entered_Pass[5],Readed_pass[5];
U8 welc=0,counts=0,key=NO_KEY;


void Enter_New_pass(void)
{
	LCD_Clear();
	LCD_GoTo(1,0);
	LCD_String("New_Password: ");
	for (U8 i=0,j=0;i<size_password ;)
	{
		U8 pass=0;
		key=GET_KEY();
		if (key!=NO_KEY)
		{
			LCD_GoTo(2,i+5);
			LCD_Numbers(key-'0');
			_delay_ms(50);
			LCD_GoTo(2,i+5);
			LCD_Char('*');
			EEPROM_write(start_address+j,key-'0');
			i++;
			j+=2;
		}
	}
	Read_pass();
	LCD_Clear();
}

void Read_pass(void)
{
	for (U8 i=0,j=0;i<size_password;i++,j+=2)
	{
		Readed_pass[i]=EEPROM_read(start_address+j);
	}
	
}

void Welocome(void)
{
	if (welc==0)
	{
		LCD_GoTo(1,0);
		LCD_String("Smart Door Proj");
		_delay_ms(100);
		LCD_GoTo(1,0);
		LCD_String("                  ");
		welc=1;
	}
	LCD_GoTo(1,0);
	LCD_String("1-Enter pass");
	LCD_GoTo(2,0);
	LCD_String("2-change pass");
}

U8 Enter_pass(void)
{
	LCD_Clear();
	LCD_GoTo(1,0);
	LCD_String("Password: ");
	for (U8 i=0;i<size_password ;)
	{
		key=GET_KEY();
		if (key=='C')
		{
			i=0;
			LCD_GoTo(1,i+10);
			LCD_String("        ");
		}
		if (key!=NO_KEY && key!='C')
		{
			LCD_GoTo(1,i+10);
			LCD_Char('*');
			Entered_Pass[i]=key-'0';
			i++;
		}
	}
	return 1;
}

U8 Check_pass(void)
{
	U8 ret=1;
	Read_pass();
	LCD_Clear();
	for (U8 i=0;i<size_password;i++)
	{
		if (Entered_Pass[i]!=Readed_pass[i])
		{
			ret=0;
		}
	}
	return ret;
}

void Wrong_pass(void)
{
	LCD_Clear();
	LCD_String("!Incorrect!  ");
	counts++;
	LCD_Numbers(counts);
	_delay_ms(80);
	
	if (counts==3)
	{
		LCD_GoTo(2,0);
		LCD_String("You're Blocked!");
		_delay_ms(5000);
		counts=0;
	}
	LCD_Clear();
}

void door_open(void)
{
	LCD_GoTo(1,0);
	LCD_String("Door's opened");
	Stepper_Bipolar_CCW();
	_delay_ms(1000);
}

void door_closed(void)
{
	Stepper_Bipolar_CW();
}

//INIT_function 

void Smart_Door_lock_init(void)
{
	DIO_INIT();
	LCD_Init();
	Keypad_Init();
}

void Smart_Door_lock_runnable(void)
{
	
	Welocome();//Welcome and shows options
	door_closed();//shows that door is closed and set led to be red
 	key=GET_KEY();//get the key for two options weather entering the password or change it
	
 	if (key!=NO_KEY && key=='1')
	{
		if (Enter_pass())//entering the password
		{
			if (Check_pass())//checking the password
			{
				door_open();//open the door and led set to be green	
			}
			else
			{
				Wrong_pass();//tells if it's incorrect password and if it's the third be blocked for a while 
			}
		}	
	}
	else if (key!=NO_KEY && key=='2')
	{
		Enter_New_pass();//creat and save new password in EEPROM
	}
	
}


