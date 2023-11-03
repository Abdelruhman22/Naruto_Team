 


#ifndef SPI_H_
#define SPI_H_


#define MASTER 1
#define SLAVE 0

#define SPI_MODE MASTER

	
void SPI_INT(void);
U8 SEND_RECIVE(U8 data);
U8 RECIVE_PERIDOC(U8* pdata);
U8 SEND_NOblock(U8 data);


#endif /* SPI_H_ */