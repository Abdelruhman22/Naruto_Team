#include "DIO_Interface.h"
#include "DIO_Register.h"
#define SET_BIT(REG,BIT)       ( REG=REG | (1<<BIT) )
#define CLR_BIT(REG,BIT)       ( REG=REG & (~(1<<BIT)) )
#define READ_BIT(REG,BIT)          ( (REG>>BIT)&1 )
#define TOOGLE_BIT(REG_BIT)    ( REG= REG ^ (1<<BIT) )

ErrorStateType DIO_EsSetPortValue (PORT_INDEX port, u8 value)
{
    ErrorStateType Ereturn=E_NOT_OK;

    switch (port)
    {

    case PORT_A:
        if (DDRA==0xFF)
        {
            PORTA=value;
            Ereturn=E_OK
        }
        else
        {
            // Do Nothing
        }
        break;
    case PORT_B:
        if (DDRB==0xFF)
        {
            PORTB=value;
            Ereturn=E_OK
        }
        else
        {
            // Do Nothing
        }
        break;
    case PORT_C:
        if (DDRC==0xFF)
        {
            PORTC=value;
            Ereturn=E_OK
        }
        else
        {
            // Do Nothing
        }
        break;
    case PORT_D:
        if (DDRD==0xFF)
        {
            PORTD=value;
            Ereturn=E_OK
        }
        else
        {
            // Do Nothing
        }
        break;

        return Ereturn;
    }
}

ErrorStateType DIO_EsSetPinValue (Pin_t  *Pin_obj)
{
    ErrorStateType Ereturn=E_NOT_OK;

    if (Pin_obj==NULL_PTR)
    {
        Ereturn=E_NULL_Pointer;
    }
    else
    {
        if(Pin_obj->PORT_INDEX==PORT_A)
        {
            if (READ_BIT (DDRA, (Pin_obj->PIN_INDEX) )
            {
                if (Pin_obj->PinValue_t==LOW)
                {
                    CLEAR_BIT(PORTA, (Pin_obj->PIN_INDEX) );        //Configure the pin to be low
                    Ereturn=E_OK;
                }
                else if (Pin_obj->PinValue_t==HIGH)
                {
                    SET_BIT(PORTA, (Pin_obj->PIN_INDEX) );        //Configure the pin to be high
                    Ereturn=E_OK;
                }
                else
                {
                    // Do Nothing
                }
            }
            else
            {
                // Do Nothing
            }
        }
        else if(Pin_obj->PORT_INDEX==PORT_B)
        {
            if (READ_BIT (DDRB, (Pin_obj->PIN_INDEX) )
            {
                if (Pin_obj->PinValue_t==LOW)
                {
                    CLEAR_BIT(PORTB, (Pin_obj->PIN_INDEX) );        //Configure the pin to be low
                    Ereturn=E_OK;
                }
                else if (Pin_obj->PinValue_t==HIGH)
                {
                    SET_BIT(PORTB, (Pin_obj->PIN_INDEX) );        //Configure the pin to be high
                    Ereturn=E_OK;
                }
                else
                {
                    // Do Nothing
                }
            }
            else
            {
                // Do Nothing
            }
        }
        else if(Pin_obj->PORT_INDEX==PORT_C)
        {
            if (READ_BIT (DDRC, (Pin_obj->PIN_INDEX) )
            {
                if (Pin_obj->PinValue_t==LOW)
                {
                    CLEAR_BIT(PORTC, (Pin_obj->PIN_INDEX) );        //Configure the pin to be low
                    Ereturn=E_OK;
                }
                else if (Pin_obj->PinValue_t==HIGH)
                {
                    SET_BIT(PORTC, (Pin_obj->PIN_INDEX) );        //Configure the pin to be high
                    Ereturn=E_OK;
                }
                else
                {
                    // Do Nothing
                }
            }
            else
            {
                // Do Nothing
            }
        }
        else if(Pin_obj->PORT_INDEX==PORT_D)
        {
			if (READ_BIT (DDRC, (Pin_obj->PIN_INDEX) )
            {
                if (Pin_obj->PinValue_t==LOW)
                {
                    CLEAR_BIT(PORTC, (Pin_obj->PIN_INDEX) );        //Configure the pin to be low
                    Ereturn=E_OK;
                }
                else if (Pin_obj->PinValue_t==HIGH)
                {
                    SET_BIT(PORTC, (Pin_obj->PIN_INDEX) );        //Configure the pin to be high
                    Ereturn=E_OK;
                }
                else
                {
                    // Do Nothing
                }
            }
            else
            {
                // Do Nothing
            }
		}
    }
	return Ereturn;
}

ErrorStateType DIO_EsTogglePin (Pin_t  *Pin_obj)
{
	ErrorStateType Ereturn=E_NOT_OK;

    if (Pin_obj==NULL_PTR)
    {
        Ereturn=E_NULL_Pointer;
    }
    else
    {
        if(Pin_obj->PORT_INDEX==PORT_A)
        {
            if (READ_BIT (DDRA, (Pin_obj->PIN_INDEX) )
            {
                TOGGLE_BIT(PORTA, (Pin_obj->PIN_INDEX) );
                    Ereturn=E_OK;
            }
            else
            {
                // Do Nothing
            }
        }
        else if(Pin_obj->PORT_INDEX==PORT_B)
        {
            if (READ_BIT (DDRB, (Pin_obj->PIN_INDEX) )
            {
                TOGGLE_BIT(PORTB, (Pin_obj->PIN_INDEX) ); 
                    Ereturn=E_OK;
            }
            else
            {
                // Do Nothing
            }
        }
        else if(Pin_obj->PORT_INDEX==PORT_C)
        {
            if (READ_BIT (DDRC, (Pin_obj->PIN_INDEX) )
            {
                TOGGLE_BIT(PORTA, (Pin_obj->PIN_INDEX) ); 
                    Ereturn=E_OK;
            }
            else
            {
                // Do Nothing
            }
        }
        else if(Pin_obj->PORT_INDEX==PORT_D)
        {
			if (READ_BIT (DDRC, (Pin_obj->PIN_INDEX) )
            {
                TOGGLE_BIT(PORTA, (Pin_obj->PIN_INDEX) ); 
                    Ereturn=E_OK;
            }
            else
            {
                // Do Nothing
            }
		}
		else
		{
			// Do Nothing
		}
	}
	return Ereturn;
}

ErrorStateType DIO_EsReadPinValue (Pin_t  Pin_obj , PinValue_t *value )
{
      ErrorStateType Ereturn=E_OK;
   
   if(Pin_obj.PORT_INDEX <= PORT_D && Pin_obj.PIN_INDEX <=PINA7)
   {
switch(Pin_obj.PORT_INDEX)
{
case PORT_A:
 *value = READ_BIT(PORTA,Pin_obj.PIN_INDEX);
break;

case PORT_B:
 *value = READ_BIT(PORTB,Pin_obj.PIN_INDEX);
break;
case PORT_C:
 *value = READ_BIT(PORTC,Pin_obj.PIN_INDEX);
break;

case PORT_D:
 *value = READ_BIT(PORTD,Pin_obj.PIN_INDEX);
break;

default:
// Do Nothing
break;
}
   }
else
   {
      Ereturn=E_NOT_OK;
   }
return Ereturn;
}

ErrorStateType DIO_EsReadPortValue(PORT_INDEX port , u8 * return_value )
{
      ErrorStateType Ereturn=E_OK;
   
   if(port <= PORT_D)
   {
    switch (port)
    {

    case PORT_A:
            *return_value = PORTA;
        break;

        case PORT_B:
            *return_value = PORTB;
        break;

        case PORT_C:
            *return_value= PORTC;
        break;

     case PORT_D:
            *return_value = PORTD;
        break;
    }
   }
else
   {
      Ereturn=E_NOT_OK;
   }
return Ereturn;
}