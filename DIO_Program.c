#include "DIO_Interface.h"
#include "DIO_Register.h"


ErrorStateType DIO_EsSetPortValue (PORT_INDEX port, u8 value)
{
    ErrorStateType Ereturn=E_NOT_OK;

    switch (port)
    {

    case PORT_A:
        if (DDRA==0xFF)
        {
            PORTA=0xFF;
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
            PORTB=0xFF;
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
            PORTC=0xFF;
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
            PORTD=0xFF;
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