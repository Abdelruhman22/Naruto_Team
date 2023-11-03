#include "../ADC_HEADERS/ADC_INTERFACE.h"
#include "../../../STD_TYPES.h"



/**
 * @brief Initialize ADC Module
 *
 * This function initializes the ADC module for usage.
 *
 * @return Std_ReturnType - Returns ADC_OK on success or ADC_ERROR on error.
 */
Std_ReturnType ADC1_init_mine(void) {
    Std_ReturnType ret = E_OK;
    // Set ADC prescaler to 128
    ADCSRA_reg = 0b10000111;
    // Set the reference and adjust as needed
    ADMUX_reg = 0b01000001;
    return ret;
}

/**
 * Read ADC Value
 *
 * This function reads the ADC value from the specified channel.
 *
 * config - The ADC configuration including channel and ret_val.
 *
 *  Std_ReturnType - Returns ADC_OK on success or ADC_ERROR on error.
 */
Std_ReturnType ADC_Read_mine(const ADCConfig* config) {
    Std_ReturnType ret = E_OK;
    // Set the ADC channel
    ADMUX_reg |= config->channel;
    // Start the conversion
    ADCSRA_reg |= 1 << 6;
    // Wait for the conversion to complete
    while ((ADCSRA_reg & 1 << 6));
    // Read the ADC value
    *(config->ret_val) = (u16)(ADCL_reg + (ADCH_reg << 8));
    return ret;
}
