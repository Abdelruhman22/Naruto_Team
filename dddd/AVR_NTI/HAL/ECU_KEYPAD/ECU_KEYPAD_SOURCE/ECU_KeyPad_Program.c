

#include"../ECU_KEYPAD_HEADRS/ECU_KeyPad_Interface.h"

// Initialize the keypad with custom column and row pins using the keypad_t structure
// This function sets up the keypad by configuring pin directions and initial values.
// It takes a pointer to a keypad_t structure as an argument.

KeypadStatus ECU_KEYPAD_init(keypad_t *keypad) {
    KeypadStatus status = KEYPAD_OK; // Initialize the status

    int i = 0;
    // Loop through the columns and rows to set pin directions and values
    for (i = 0; i < 4; i++) {
        if (Mcal_Dio_Std_Set_Pin_Direction(&keypad->col_pins[i]) != DIO_OK) {
            status = KEYPAD_ERROR;
            break;  // Exit the loop on error
        }
        if (Mcal_Dio_Std_Set_Pin_Value(&keypad->row_pins[i], HIGH) != DIO_OK) {
            status = KEYPAD_ERROR;
            break;  // Exit the loop on error
        }
        if (Mcal_Dio_Std_Set_Pin_Direction(&keypad->row_pins[i]) != DIO_OK) {
            status = KEYPAD_ERROR;
            break;  // Exit the loop on error
        }
    }

    return status; // Return the status
}

//////////////////////////////////////////////////////////////////////////////////////////////////

// Get the key pressed on the keypad with custom column and row pins using the keypad_t structure
KeypadStatus ECU_KEYPAD_Get_Key(keypad_t *keypad) {
    KeypadStatus status = KEYPAD_OK; // Initialize the status
    u8 row_counter = 0;
    u8 col_counter = 0;
    u8 val = 1;
    *keypad->ret_val = 10; // Initialize the return value to an invalid value

    // Loop through the columns
    for (col_counter = 0; col_counter < 4; col_counter++) {
        if (col_counter == 0) {
            if (Mcal_Dio_Std_Set_Pin_Value(&keypad->row_pins[3], HIGH) != DIO_OK) {
                status = KEYPAD_ERROR;
                break;  // Exit the loop on error
            }
        }
        if (col_counter > 0) {
            if (Mcal_Dio_Std_Set_Pin_Value(&keypad->row_pins[col_counter - 1], HIGH) != DIO_OK) {
                status = KEYPAD_ERROR;
                break;  // Exit the loop on error
            }
        }
        if (Mcal_Dio_Std_Set_Pin_Value(&keypad->row_pins[col_counter], LOW) != DIO_OK) {
            status = KEYPAD_ERROR;
            break;  // Exit the loop on error
        }

        // Loop through the rows
        for (row_counter = 0; row_counter < 4; row_counter++) {
            if (Mcal_Dio_Std_Get_Pin_Value(&keypad->col_pins[row_counter], &val) != DIO_OK) {
                status = KEYPAD_ERROR;
                break;  // Exit the loop on error
            }

            // If the value is LOW, assign the corresponding key to the return value
            if (val == LOW) {
                *keypad->ret_val = keys[col_counter][row_counter];
                val = 1; // Reset val for the next iteration
            }
        }

        // Add a delay of 50 ms (possibly for debouncing)
        _delay_ms(50);
    }

    return status; // Return the status
}
