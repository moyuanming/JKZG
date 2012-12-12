#ifndef __SERIAL_H__
#define __SERIAL_H__
#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1;
#endif

#ifndef FALSE
#define FALSE 0;
#endif



void Serial_Set_Speed(int fd, int speed);
int Serial_Set_Parity(int fd, int databits, int stopbits, int parity);
int Serial_Open(char *Dev);
int Serial_Close(int fd);
int Serial_Read(int fd, unsigned char *byReadBuf, int nReadLen);
int Serial_Write(int fd, unsigned char *byWriteBuf, int nWriteLen);

#endif
