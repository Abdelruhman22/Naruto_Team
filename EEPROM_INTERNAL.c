#include "StdTypes.h"
#include "MemMap.h"
#include "EEPROM.h"

void EEPROM_write(U16 uiAddress,U8 ucData )
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start EEPROM write by setting EEWE */
	EECR |= (1<<EEWE);
}

U8 EEPROM_read(U16 uiAdress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address register */
	EEAR = uiAdress;
	/* Start EEPROM read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}

void EEPROM_writestring(U16 *uiAddress,U8 ucData,U8 i )
{
	
	while(EECR &(1<<EEWE));
	EEAR=uiAddress;
	EEDR=ucData;
	EECR|=(1<<EEMWE);
	EECR|=(1<<EEWE);
} 
