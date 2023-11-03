
#ifndef MCAL_MCAL_ADC_ADC_HEADERS_ADC_INTERFACE_H_
#define MCAL_MCAL_ADC_ADC_HEADERS_ADC_INTERFACE_H_

#include"ADC_PRIVATE.h"

#include "../../../STD_TYPES.h"

/********************************** Error Status Enumeration *******************************/

typedef enum {
    ADC_OK,       // No error
    ADC_ERROR,    // General error
    ADC_INVALID,  // Invalid value
} ADCStatus;

/********************************** Software Interfaces Declarations *******************************/

typedef struct {
    u8 channel;   // The ADC channel to read from
    u16* ret_val; // Pointer to store the ADC value
} ADCConfig;

/********************************** Software Interfaces Declarations *******************************/

Std_ReturnType ADC1_init_mine(void);
Std_ReturnType ADC_Read_mine(const ADCConfig* config);

#endif /* MCAL_MCAL_ADC_ADC_HEADERS_ADC_INTERFACE_H_ */
/*ecample using lm35 to calculate temperature
 * 	ADC1_init_mine();
		ECU_Lcd_4Bit_Send_Command(&lcd_obj,_LCD_CLEAR);
		_delay_ms(10);
		ECU_Lcd_4Bit_Send_Command(&lcd_obj,_LCD_RETURN_HOME);
		charr_receive='d';
		_delay_ms(10);
		ECU_Lcd_4Bit_Send_char(&lcd_obj,charr_receive);
		_delay_ms(10);

		ADC_Read_mine(1,&charr_send);
		millvolte =((u16)((u32)charr_send*5000UL)/256UL);
		u8 temp=millvolte/10;
	 ECU_Lcd_convert_int_to_string((u32)temp, str) ;

		ECU_Lcd_4Bit_Send_str(&lcd_obj,str);

		//ECU_Lcd_4Bit_Send_char(&lcd_obj,charr_receive);
		UART_vidSendByte(temp);
 */
