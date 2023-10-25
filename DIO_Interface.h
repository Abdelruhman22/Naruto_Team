/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mohamed Ali Eltaher Ali
 *  Layer  : MCAL
 *  SWC    : DIO/GPIO
 *
 */ 

 

#ifndef   DIO_INTERFACE_H_
#define   DIO_INTERFACE_H_


typedef enum {
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,


	}PIN_INDEX;

typedef enum{
	PORT_A ,
	PORT_B ,
	PORT_C ,
	PORT_D
	
	}PORT_INDEX;

typedef enum{
    PIN_LOW=0 ,
    PIN_HIGH
}PinValue_t;

typedef enum{
    PIN_INPUT =0 ,
    PIN_OUTPUT 
}Pin_Direction;

typedef enum{
    PORT_INPUT =0x00 ,
    PORT_OUTPUT =0xFF
}Port_Direction;


typedef struct 
{
 u8 PORT_INDEX:2,
 u8 PIN_INDEX:3,
 u8 Pin_Direction:1,
 u8 PinValue_t:1
    
}Pin_t;

 
typedef enum{                 
	E_OK=0 ,
    E_NOK_OK,
    E_NULL_Pointer
	
 }ErrorStateType;
 
 
/*
                                        ProtoTypes
*/

 
ErrorStateType DIO_EsSetPinDirection       (Pin_t  Pin_obj  );
ErrorStateType DIO_EsSetPinValue           (Pin_t  Pin_obj  );
ErrorStateType DIO_EsReadPinValue          (Pin_t  Pin_obj , PinValue_t *value );
ErrorStateType DIO_EsTogglePin             (Pin_t  Pin_obj  );


ErrorStateType DIO_EsSetPortValue          (PORT_INDEX port , u8 value );
ErrorStateType DIO_EsReadPortValue         (PORT_INDEX port , u8 * return_value );
ErrorStateType DIO_EsTogglePort            (PORT_INDEX port  );




#endif