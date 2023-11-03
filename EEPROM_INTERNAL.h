


#ifndef EEPROM_H_
#define EEPROM_H_



void EEPROM_writestring(U16 uiAddress[],U8 ucData,U8 i );
U8 EEPROM_read(U16 uiAdress);
void EEPROM_write(U16 uiAddress,U8 ucData );



#endif /* EEPROM_H_ */