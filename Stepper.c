#include "Stepper.h"

void Stepper_Bipolar_CW(void)
{
	
	DIO_InitPin2(IN1,OUTPUT_HIGH);
	DIO_InitPin2(IN2,OUTPUT_LOW);
	DIO_InitPin2(IN3,OUTPUT_LOW);
	DIO_InitPin2(IN4,OUTPUT_LOW);
	
//	_delay_ms(500);	
// 	DIO_InitPin2(IN1,OUTPUT_LOW);
// 	DIO_InitPin2(IN2,OUTPUT_LOW);
// 	DIO_InitPin2(IN3,OUTPUT_HIGH);
// 	DIO_InitPin2(IN4,OUTPUT_LOW);
// 	_delay_ms(500);
// 	DIO_InitPin2(IN1,OUTPUT_LOW);
// 	DIO_InitPin2(IN2,OUTPUT_HIGH);
// 	DIO_InitPin2(IN3,OUTPUT_LOW);
// 	DIO_InitPin2(IN4,OUTPUT_LOW);
// 	_delay_ms(500);
// 	DIO_InitPin2(IN1,OUTPUT_LOW);
// 	DIO_InitPin2(IN2,OUTPUT_LOW);
// 	DIO_InitPin2(IN3,OUTPUT_LOW);
// 	DIO_InitPin2(IN4,OUTPUT_HIGH);
// 	_delay_ms(500);
}

void Stepper_Bipolar_CCW(void)
{
		DIO_InitPin2(IN1,OUTPUT_LOW);
		DIO_InitPin2(IN2,OUTPUT_LOW);
		DIO_InitPin2(IN3,OUTPUT_LOW);
		DIO_InitPin2(IN4,OUTPUT_HIGH);
		
//		_delay_ms(500);		
// 		DIO_InitPin2(IN1,OUTPUT_LOW);
// 		DIO_InitPin2(IN2,OUTPUT_HIGH);
// 		DIO_InitPin2(IN3,OUTPUT_LOW);
// 		DIO_InitPin2(IN4,OUTPUT_LOW);
// 		_delay_ms(500);
// 		DIO_InitPin2(IN1,OUTPUT_LOW);
// 		DIO_InitPin2(IN2,OUTPUT_LOW);
// 		DIO_InitPin2(IN3,OUTPUT_HIGH);
// 		DIO_InitPin2(IN4,OUTPUT_LOW);
// 		_delay_ms(500);
// 		DIO_InitPin2(IN1,OUTPUT_HIGH);
// 		DIO_InitPin2(IN2,OUTPUT_LOW);
// 		DIO_InitPin2(IN3,OUTPUT_LOW);
// 		DIO_InitPin2(IN4,OUTPUT_LOW);
// 		_delay_ms(500);
}
