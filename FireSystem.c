#include "StdTypes.h"
#include "ADC_Interface.h"
#include "DIO_Interface.h"
#include "Sensors_Interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Interface.h"
#include "FireSystem_Interface.h"
#include "FireSystem_private.h"
#include "FireSystem_Cfg.h"
#include "EEPROM.h"


u8 temp,smoke,fire=0;
u8 password[6];
u8 password_flag;

void FireSystem_Init (void)
{
	password_flag=EEPROM_read(0);
	if (password_flag==1)
	{
		EEPROM_read_array(1,6,password);
	}
	else
	{
		for (u8 i=1;i<7;i++)
		{
			password[i-1]=i;
		}
	}
}
static void fine_mode (void)
{
	DIO_WritePin(BlueLed,LOW);
	DIO_WritePin(GreenLed,HIGH);
	LCD_WriteStringGoto(0,6,"Fine");
	LCD_GoTo(1,0);
	LCD_WriteNumber(temp);
	LCD_WriteChar(' ');
}

static void heat_mode (void)
{
	smoke=POT_Read(Smoke_Sensor);
	if (smoke>50)
	{
		fire=1;
	}
	DIO_WritePin(GreenLed,LOW);
	DIO_WritePin(BlueLed,HIGH);
	LCD_WriteStringGoto(0,6,"Heat");
	LCD_GoTo(1,0);
	LCD_WriteNumber(temp);
	LCD_WriteChar(' ');
}

static void fire_mode (void)
{
	DIO_WritePin(GreenLed,LOW);
	DIO_WritePin(BlueLed,LOW);
	DIO_WritePin(RedLed,HIGH);
	LCD_WriteStringGoto(0,6,"Fire");
	LCD_GoTo(1,0);
	LCD_WriteNumber(temp);
	LCD_WriteChar(' ');
	DIO_WritePin(Buzzer,HIGH);
}

static Passowrd_check_type password_check (void)
{
	u8 temp[6]={0};
	u8 i=0,k=NO_KEY;
	Passowrd_check_type check=CORRECT;
	LCD_GoTo(1,0);
	while(i<6)
	{
		k=KEYPAD_GetKey();
		if (k>='0' && k<='9')
		{
			temp[i]=k-'0';
			LCD_WriteChar(k);
			i++;
		}
		else if (k=='C')
		{
			if(i>0)
			{
			i--;
			LCD_WriteStringGoto(1,i," ");
			LCD_GoTo(1,i);	
			}
		}
	}
	for (u8 i=0;i<6;i++)
	{
		if (temp[i]!=password[i])
		{
			check=NOT_CORRECT;
		}
	}
	return check;
}

static void menu_mode (void)
{
	u8 k=NO_KEY,flag=0;
	LCD_Clear();
	LCD_WriteString("Press 3 to Back");
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteString("1-Change Pass");
	LCD_WriteStringGoto(1,0,"2-Reset Pass");
	while (flag==0)
	{
		k=KEYPAD_GetKey();
		if (k=='1')
		{
			LCD_Clear();
			LCD_WriteString("  Old Password");
			if (password_check()==CORRECT)
			{
				u8 i=0;
				LCD_Clear();
				LCD_WriteString("  New Password");
				LCD_GoTo(1,0);
				while(i<6)
				{
					k=KEYPAD_GetKey();
					if (k>='0' && k<='9')
					{
						password[i]=k-'0';
						LCD_WriteChar(k);
						i++;
					}
					else if (k=='C')
					{
						if(i>0)
						{
							i--;
							LCD_WriteStringGoto(1,i," ");
							LCD_GoTo(1,i);
						}
					}
				}
				LCD_Clear();
				LCD_WriteStringGoto(1,6,"Done");
				EEPROM_write(0,1);
				EEPROM_InterruptEnable();
				EEPROM_EE_RDY_SetCallBack(change_password);
				_delay_ms(1000);
				LCD_Clear();
				
				flag=1;
			}
			else
			{
				LCD_Clear();
				LCD_WriteString("Invalid Password");
				_delay_ms(1000);
				LCD_Clear();
				flag=1;
			}
		}
		else if (k=='2')
		{
			password_flag=EEPROM_read(0);
			if (password_flag==1)
			{
				EEPROM_write(0,0);
				for (u8 i=1;i<7;i++)
				{
					password[i-1]=i;
				}
			}
			LCD_Clear();
			LCD_WriteString("Password Reset");
			LCD_GoTo(1,0);
			LCD_WriteString("To Default");
			_delay_ms(1000);
			flag=1;
			LCD_Clear();
		}
		else if (k=='3')
		{
			flag=1;
			LCD_Clear();
		}
	}
}

void Fire_system_Runnable (void)
{
	u8 k=NO_KEY;
	temp=POT_Read(Temp_Sensor);
	if (fire==0)
	{
		if (temp<50)
		{
			fine_mode();
		}
		else
		{
			heat_mode();
		}
		LCD_WriteStringGoto(1,10,"1-Menu");
		k=KEYPAD_GetKey();
		if (k=='1')
		{
			LCD_Clear();
			menu_mode();
		}
	}
	else
	{
		LCD_WriteStringGoto(1,7,"1-Disable");
		fire_mode();
		k=KEYPAD_GetKey();
		if (k=='1')
		{
			LCD_Clear();
			LCD_WriteString("Enter Password");
			if(password_check()==CORRECT)
			{
				fire=0;
				DIO_WritePin(Buzzer,LOW);
				DIO_WritePin(RedLed,LOW);
				LCD_Clear();
				LCD_WriteStringGoto(0,4,"Disabled");
				_delay_ms(1000);
			}
			else
			{
				LCD_Clear();
				LCD_WriteString("Invalid Password");
				_delay_ms(1000);
			}
			LCD_Clear();
		}
	}
}

static void change_password (void)
{
	EEPROM_write_array(1,password,6);
}