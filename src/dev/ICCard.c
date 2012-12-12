#include "LocalIncludeFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <dlfcn.h>
#include "ICCard.h"
#define MaxKeyLen 1000
int (*pICCard_init)(int pcom,long pspeed,long pe,char * pn);
int (*pICCard_getCard)(Card * card);
int ICCard_isInit = 0;
static int BPS(int bps)
{
	int ret = B9600;
	switch( bps )
	{
		case 1200:
			ret = B1200;
			break;
		case 2400:
			ret = B2400;
			break;
		case 4800:
			ret = B4800;		
			break;
		case 9600:
			ret = B9600;
			break;
		case 19200:
			ret = B19200;
			break;
		case 38400:
			ret = B38400;
			break;
		case 115200:
			ret = B115200;
			break;
	}
	return ret;
}
Card ICCard_Card;
Card * ICCard_GetCard()
{
	return &ICCard_Card;
}
int ICCard_GetIsInit()
{
	return ICCard_isInit;
}
int ICCard_ReadKey(char * Key)
{
	FILE * LoadFinleFd;
	int len = 0;
	char   cn; 
	//echoic("KEY File %s",PARAPUBLICKEY_FILE);
    LoadFinleFd=fopen(PARAPUBLICKEY_FILE,"r");	
    if(LoadFinleFd<0)
    {	
        printf("opern %s error \n",PARAPUBLICKEY_FILE);	
    }
	echoic("read KEY");
    lseek(LoadFinleFd,SEEK_SET,0);	
	fgets(Key,MaxKeyLen,LoadFinleFd);
	echoic("end read KEY");
    close(LoadFinleFd);	
	return strlen(Key);
}
void   *handle = 0x00;
int ICCard_UnLoad(void)
{
	if(handle)
	{
		echoic("close libICCard.so");
		dlclose( handle );
	}
}
int ICCard_Load(void)
{
	char key[MaxKeyLen];
	int len = 0;
	ICCard_isInit = 0;
	echoic("load libICCard.so");
    handle = dlopen( "libICCard.so", RTLD_LAZY );
	if(handle)
	{
		pICCard_init    = dlsym( handle, "ICCard_init" );
		if(pICCard_init)
		{
			echoic("load func ICCard_init");
		}
		else
		{
			echoic("load func ICCard_init error");
		}
		pICCard_getCard    = dlsym( handle, "ICCard_getCard" );
		if(pICCard_getCard)
		{
			echoic("load func ICCard_getCard");
		}
		else
		{
			echoic("load func ICCard_getCard error");
		}
	}
	if(!pICCard_init||!pICCard_getCard)
	{
		echoic("load libICCard.so error");
		ICCard_UnLoad();
		return -1;
	}
	else
	{
		memset(key,0,MaxKeyLen);
		len = ICCard_ReadKey(key);
		echoic("len %d key %s",len,key);
		if(len>0)
		{
			echoic("COM%d speed %d",atoi(sys_ini.csc_tty),BPS(atoi(sys_ini.CSC_SPEED)));//atoi(sys_ini.csc_tty) BPS(atoi(sys_ini.CSC_SPEED))
			if(ICCard_init(atoi(sys_ini.csc_tty),(long)BPS(atoi(sys_ini.CSC_SPEED)),65537,key)==0)
			{
				ICCard_isInit = 1;
				echoic("load libICCard.so ok");
				return 0;
			}
		}
	}
	echoic("load libICCard.so error");
	ICCard_UnLoad();
	return -1;
}

int ICCard_init(int pcom,long pspeed,long pe,char * pn)
{
	echoic("go");
	if(pICCard_init)
	{
		echoic("go");
		return pICCard_init(pcom,pspeed,pe,pn);
	}
	return 1;
}
int ICCard_getCard()
{
	if(pICCard_getCard)
	{
		return pICCard_getCard(&ICCard_Card);
	}
	return 1;
}
void ICCard_GetBCD(char * bcd,unsigned char * s,int len)
{
	int i=0;
	unsigned char temp[3];
	memset(temp,0,3);
	for(i=0;i<len;i++)
	{
		//itoa((unsigned int)s[i],temp,16);
		sprintf(temp,"%02X",s[i]);
		bcd[i*2] = temp[0];
		bcd[i*2+1] = temp[1];
	}
}
char ICCard_BDate[20];
char * ICCard_GetBDate()
{
	memset(ICCard_BDate,0,20);
	ICCard_GetBCD(ICCard_BDate,ICCard_Card.BTime,4);
	return ICCard_BDate;
}
char ICCard_EDate[20];
char * ICCard_GetEDate()
{
	memset(ICCard_EDate,0,20);
	ICCard_GetBCD(ICCard_EDate,ICCard_Card.ETime,4);
	return ICCard_EDate;
}
int ICCard_ValidateCardEndDate(time_t Currenttime)
{
	if(ICCard_Card.Valid == '1'
		&&strcmp(GetFormatTime(DATETIME_FORMAT_YYYYMMDD,Currenttime),ICCard_GetEDate())>0)
	{	
		return 1;
	}
	return 0;
}
int ICCard_ValidateCardStartDate(time_t Currenttime)
{
	if(ICCard_Card.Valid == '1'
		&&strcmp(GetFormatTime(DATETIME_FORMAT_YYYYMMDD,Currenttime),ICCard_GetBDate())<0)
	{	
		return 1;
	}
	return 0;
}
int ICCard_ValidateArea()
{
	char temp[3];
	unsigned char PlazaNo = 0;
	unsigned char NetNo =	0;
	memset(temp,0,3);
	memcpy(temp,GetLanConfigPlazaNo(),2);
	PlazaNo = (unsigned char)atoi(temp);
	memset(temp,0,3);
	memcpy(temp,GetLanConfigNetNo(),2);
	NetNo = (unsigned char)atoi(temp);
	echoic("ICCard_ValidateArea %02d%02d",PlazaNo,NetNo);
	int i = 0;
	for(i=0;i<5;i++)
	{
		echoic("ICCard_ValidateArea %02d%02d",ICCard_Card.Area[i*2],ICCard_Card.Area[i*2+1]);
		if(ICCard_Card.Area[i*2]==NetNo)
		{
			if(ICCard_Card.Area[i*2+1]==0||ICCard_Card.Area[i*2+1]==PlazaNo)
			{
				echoic("ICCard_ValidateArea ok");
				return 1;
			}
		}
	}
	echoic("ICCard_ValidateArea error");
	return 0;
}