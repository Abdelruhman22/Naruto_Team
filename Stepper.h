

#ifndef STEPPER_H_
#define STEPPER_H_

#include "StdTypes.h"
#include "DIO_INTERFACE.h"
#define F_CPU  8000000UL
#include <util/delay.h>

#define IN1  PINC2
#define IN2  PINC3
#define IN3  PINC4
#define IN4  PINC5
extern U8 open;
extern U8 closed;

void Stepper_Bipolar_CW(void);
void Stepper_Bipolar_CCW(void);



#endif /* STEPPER_H_ */