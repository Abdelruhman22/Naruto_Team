
#ifndef HAL_ECU_KEYPAD_ECU_KEYPAD_HEADRS_ECU_KEYPAD_INTERFACE_H_
#define HAL_ECU_KEYPAD_ECU_KEYPAD_HEADRS_ECU_KEYPAD_INTERFACE_H_
//#include "../../../MCAL/MCAL_DIO/DIO_HEADERS/MCAL_DIO_INTERFACE.h"
#include"../../../MCAL/MCAL_DIO/DIO_HEADERS/MCAL_DIO_INTERFACE.h"
#include<util\delay.h>

//Row = Input Pull Up
//Column = Output High

u8 keys[4][4]={

		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'s','0','=','+'}




};
//////////////////////////////////////////////////////////////////////////////////////

// Define an enum for error status return
typedef enum {
    KEYPAD_OK,       // No error
    KEYPAD_ERROR,    // General error
    KEYPAD_INVALID,  // Invalid value
    // Add more error codes as needed
} KeypadStatus;


// Define a structure to hold column and row pins and the return value
typedef struct {
    u8 col_pins[4];   // Array of column pins
    u8 row_pins[4];   // Array of row pins
    u8 *ret_val;      // Pointer to the return value
} keypad_t;

////////////////////////////////////////////////////////////////////////////////////

KeypadStatus ECU_KEYPAD_init(keypad_t *keypad);
KeypadStatus ECU_KEYPAD_Get_Key(keypad_t *keypad);


#endif /* HAL_ECU_KEYPAD_ECU_KEYPAD_HEADRS_ECU_KEYPAD_INTERFACE_H_ */


/*keypad_t keypad;//row =inpput pull up
//col = output  high
keypad.col[0].direction=OUTPUT;
keypad.col[0].pin=pin7;
keypad.col[0].port_index=PORT_D;

keypad.col[1].direction=OUTPUT;
keypad.col[1].pin=pin6;
keypad.col[1].port_index=PORT_D;


keypad.col[2].direction=OUTPUT;
keypad.col[2].pin=pin5;
keypad.col[2].port_index=PORT_D;


keypad.col[3].direction=OUTPUT;
keypad.col[3].pin=pin3;
keypad.col[3].port_index=PORT_D;


keypad.row[0].direction=PULL_UP;
keypad.row[0].pin=pin5;
keypad.row[0].port_index=PORT_C;

keypad.row[1].direction=PULL_UP;
keypad.row[1].pin=pin4;
keypad.row[1].port_index=PORT_C;


keypad.row[2].direction=PULL_UP;
keypad.row[2].pin=pin3;
keypad.row[2].port_index=PORT_C;


keypad.row[3].direction=PULL_UP;
keypad.row[3].pin=pin2;
keypad.row[3].port_index=PORT_C;


*/
