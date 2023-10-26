#include "DIO_Interface.h"
#include "DIO_Register.h"

ErrorStateType DIO_EsSetPortDirection(PORT_INDEX port, u8 direction )
{
    ErrorStateType Ereturn = E_NOT_OK;

    switch (port)
    {

        case PORT_A:
            DDRA = direction;
            Ereturn = E_OK;
            break;

        case PORT_B:
            DDRB = direction;
            Ereturn = E_OK;
            break;

        case PORT_C:
            DDRC = direction;
            Ereturn = E_OK;
            break;

        case PORT_D:
            DDRD = direction;
            Ereturn = E_OK;
            break;

        default :

    }
    return Ereturn;
}


ErrorStateType DIO_EsSetPinDirection (Pin_t  *Pin_obj)
{
    ErrorStateType Ereturn = E_NOT_OK;

    if (Pin_obj == NULL_PTR)
    {
        Ereturn=E_NULL_Pointer;
    }
    else
    {
        if(Pin_obj->PORT_INDEX  ==  PORT_A)
        {
            if (READ_BIT (DDRA, (Pin_obj->PIN_INDEX) )
            {
                if (Pin_obj->Pin_Direction  ==  PIN_INPUT)
                {
                    CLEAR_BIT(DDRA, (Pin_obj->PIN_INDEX) );        //Configure the pin to be PIN_INPUT
                    Ereturn=E_OK;
                }
                else if (Pin_obj->Pin_Direction  ==  PIN_OUTPUT)
                {
                    SET_BIT(DDRA, (Pin_obj->PIN_INDEX) );        //Configure the pin to be PIN_OUTPUT
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
        else if(Pin_obj->PORT_INDEX == PORT_B)
        {
            if (READ_BIT (DDRB, (Pin_obj->PIN_INDEX) )
            {
                if (Pin_obj->Pin_Direction == PIN_INPUT)
                {
                    CLEAR_BIT(DDRB, (Pin_obj->PIN_INDEX) );        //Configure the pin to be PIN_INPUT
                    Ereturn=E_OK;
                }
                else if (Pin_obj->Pin_Direction == PIN_OUTPUT)
                {
                    SET_BIT(DDRB, (Pin_obj->PIN_INDEX) );        //Configure the pin to be PIN_OUTPUT
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
        else if(Pin_obj->PORT_INDEX == PORT_C)
        {
            if (READ_BIT (DDRC, (Pin_obj->PIN_INDEX) )
            {
                if (Pin_obj->Pin_Direction == PIN_INPUT)
                {
                    CLEAR_BIT(DDRC, (Pin_obj->PIN_INDEX) );        //Configure the pin to be PIN_INPUT
                    Ereturn=E_OK;
                }
                else if (Pin_obj->Pin_Direction == PIN_OUTPUT)
                {
                    SET_BIT(DDRC, (Pin_obj->PIN_INDEX) );        //Configure the pin to be PIN_OUTPUT
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
        else if(Pin_obj->PORT_INDEX == PORT_D)
        {
			if (READ_BIT (DDRD, (Pin_obj->PIN_INDEX) )
            {
                if (Pin_obj->Pin_Direction == PIN_INPUT)
                {
                    CLEAR_BIT(DDRD, (Pin_obj->PIN_INDEX) );        //Configure the pin to be PIN_INPUT
                    Ereturn=E_OK;
                }
                else if (Pin_obj->Pin_Direction == PIN_OUTPUT)
                {
                    SET_BIT(DDRD, (Pin_obj->PIN_INDEX) );        //Configure the pin to be PIN_OUTPUT
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
