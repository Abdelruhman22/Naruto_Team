#include "StdTypes.h"
#include "MemMap.h"
#include "EXT_INTERRUPT.h"


/****************************Pointer to functions to be assigned to ISR*********************************/

static void (*INT0_Fptr) (void)=NULLPTR;
static void (*INT1_Fptr) (void)=NULLPTR;
static void (*INT2_Fptr) (void)=NULLPTR;

/************************************Enable/Disable functions***********************************/
	
void EXI_Enable(ExInterruptSource_type Interrupt)
{
	switch(Interrupt){
		case EX_INT0:
		setbit(GICR,INT0);
		break;
		case EX_INT1:
		setbit(GICR,INT1);
		break;
		case EX_INT2:
		setbit(GICR,INT2);
		break;
	}
}

void EXI_Disable(ExInterruptSource_type Interrupt)
{
	switch(Interrupt){
		case EX_INT0:
		clrbit(GICR,INT0);
		break;
		case EX_INT1:
		clrbit(GICR,INT1);
		break;
		case EX_INT2:
		clrbit(GICR,INT2);
		break;
	}
}

void EXI_Init(void)
{
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	EXI_TriggerEdge(EX_INT1,FALLING_EDGE);
	EXI_TriggerEdge(EX_INT2,FALLING_EDGE);
}


/************************************Control function*****************************/
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge)
{
	switch(Interrupt){
		case EX_INT0:
		switch(Edge){
			case LOW_LEVEL:
			clrbit(MCUCR,ISC00);
			clrbit(MCUCR,ISC01);
			break;
			case ANY_LOGIC_CHANGE:
			setbit(MCUCR,ISC00);
			clrbit(MCUCR,ISC01);
			break;
			case FALLING_EDGE:
			clrbit(MCUCR,ISC00);
			setbit(MCUCR,ISC01);
			break;
			case RISING_EDGE:
			setbit(MCUCR,ISC00);
			setbit(MCUCR,ISC01);
			break;
			
		}
		break;
		case EX_INT1:
		switch(Edge){
			case LOW_LEVEL:
			clrbit(MCUCR,ISC10);
			clrbit(MCUCR,ISC11);
			break;
			case ANY_LOGIC_CHANGE:
			setbit(MCUCR,ISC10);
			clrbit(MCUCR,ISC11);
			break;
			case FALLING_EDGE:
			clrbit(MCUCR,ISC10);
			setbit(MCUCR,ISC11);
			break;
			case RISING_EDGE:
			setbit(MCUCR,ISC10);
			setbit(MCUCR,ISC11);
			break;
			
		}
		break;
		case EX_INT2:
		switch(Edge){
			case FALLING_EDGE:
			clrbit(MCUCSR,ISC2);
			break;
			case RISING_EDGE:
			setbit(MCUCSR,ISC2);
			break;
			default:
			clrbit(MCUCSR,ISC2);
		}
		break;
	}
}
/************************************Call back functions*********************************************/
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void))
{
	switch(Interrupt){
		case EX_INT0:
		INT0_Fptr=LocalPtr;
		break;
		case EX_INT1:
		INT1_Fptr=LocalPtr;
		break;
		case EX_INT2:
		INT2_Fptr=LocalPtr;
		break;
		
	}
}
/*******************************ISR********************************/

ISR(INT0_vect)
{
	if (INT0_Fptr!=NULLPTR)
	{
		INT0_Fptr();
	}
	
	
}
ISR(INT1_vect,ISR_NOBLOCK)
{
	//EX_func1();
	
	if (INT1_Fptr!=NULLPTR)
	{
		INT1_Fptr();
	}
}
ISR(INT2_vect)
{
	if (INT2_Fptr!=NULLPTR)
	{
		INT2_Fptr();
	}
	
}
 