
ErrorStateType DIO_EsSetPortDirection(PORT_INDEX port, u8 direction )
{
    ErrorStateType Ereturn = E_NOT_OK;

    switch (port)
    {

        case PORT_A:
            PORTA = direction;
            Ereturn = E_OK; 
            break;
            
        case PORT_B:
            PORTC = direction;
            Ereturn = E_OK;
            break;
            
        case PORT_C:
            PORTC = direction;
            Ereturn = E_OK;
            break;
            
        case PORT_D:
            PORTD = direction;
            Ereturn = E_OK;
            break;
        
        default :
        
    }
    return Ereturn;
}


ErrorStateType DIO_EsSetPinValue (Pin_t  *Pin_obj)
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
                if (Pin_obj->Pin_Direction  ==  LOW)
                {
                    CLEAR_BIT(PORTA, (Pin_obj->PIN_INDEX) );        //Configure the pin to be low
                    Ereturn=E_OK;
                }
                else if (Pin_obj->Pin_Direction  ==  HIGH)
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
        else if(Pin_obj->PORT_INDEX == PORT_B)
        {
            if (READ_BIT (DDRB, (Pin_obj->PIN_INDEX) )
            {
                if (Pin_obj->Pin_Direction == LOW)
                {
                    CLEAR_BIT(PORTB, (Pin_obj->PIN_INDEX) );        //Configure the pin to be low
                    Ereturn=E_OK;
                }
                else if (Pin_obj->Pin_Direction == HIGH)
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
        else if(Pin_obj->PORT_INDEX == PORT_C)
        {
            if (READ_BIT (DDRC, (Pin_obj->PIN_INDEX) )
            {
                if (Pin_obj->Pin_Direction == LOW)
                {
                    CLEAR_BIT(PORTC, (Pin_obj->PIN_INDEX) );        //Configure the pin to be low
                    Ereturn=E_OK;
                }
                else if (Pin_obj->Pin_Direction == HIGH)
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
        else if(Pin_obj->PORT_INDEX == PORT_D)
        {
			if (READ_BIT (DDRC, (Pin_obj->PIN_INDEX) )
            {
                if (Pin_obj->Pin_Direction == LOW)
                {
                    CLEAR_BIT(PORTC, (Pin_obj->PIN_INDEX) );        //Configure the pin to be low
                    Ereturn=E_OK;
                }
                else if (Pin_obj->Pin_Direction == HIGH)
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
