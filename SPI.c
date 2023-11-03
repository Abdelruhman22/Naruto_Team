#include "StdTypes.h"
#include "MemMap.h"
#include "SPI.h"

void SPI_INT(void)
{
	//slave or clock
	#if SPI_MODE
	setbit(SPCR,MSTR);
	//clock 2mhz
	#else
	clrbit(SPCR,MSTR);
	#endif
		
	
	//enable
	setbit(SPCR,SPE);
}

U8 SEND_RECIVE(U8 data)
{
	//write buffer
	SPDR=data;
	while(readbit(SPSR,SPIF));
	//read buffer
	return SPDR;
}

U8 RECIVE_PERIDOC(U8* pdata)
{
	if (readbit(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}

U8 SEND_NOblock(U8 data)
{
	SPDR=data;
}