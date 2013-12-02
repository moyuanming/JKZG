#include "LocalIncludeFile.h"
#include "i_dev_VPR_HW.h"

#define SERV_PORT 5000
#define MAXLEN 102400*5
int socket_svr = 0;
int VPR_HW_isInit = 0;
char cphm[32];
int VPR_HW_UnLoad(void)
{
	return VPR_Quit();
}
void sigalrm_fn(int  sig)
{
	VPR_Capture();
}

int VPR_HW_Load(void)
{
	int result=0;
	VPR_HW_ClearCPHM();
	echo_vpr("Init  VPR.....");
	if ( createsvr())
	{
		result= VPR_HW_Open();
	}
	return result;
}
int VPR_HW_Open(void)
{
	echo_vpr("Open VPR HW  By %d  and  %d",5000,8888);//GetVPRPort());
	BOOL bResult = VPR_Init(SERV_PORT,  8888);//GetVPRPort());
	if(TRUE == bResult)
	{
		echo_vpr("init success");
		//signal(SIGALRM,sigalrm_fn);
	}
	else
	{
		echo_vpr("init fail");
	}
	return  bResult;

}
void VPR_HW_Close(void)
{

}
void VPR_HW_ClearCPHM(void)
{
	memset(cphm,0x00,sizeof(cphm ));
	sprintf(cphm,"%s","未识别");
}
void VPR_HW_SetCPHM(char * _cphm)
{
	memset(cphm,0x00,sizeof(cphm ));
	sprintf(cphm,"%s",_cphm);

}
char * VPR_HW_GetCPHM( void)
{
	return		cphm;
}


int createsvr(void)
{
	struct sockaddr_in servaddr ;
	socket_svr = socket(AF_INET, SOCK_DGRAM, 0); /* create a socket */
	if(socket_svr <= 0)
		return -1;
	/* init servaddr */
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	/* bind address and port to socket */
	if(bind(socket_svr, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
	{
		perror("bind error");
		return -1;
	}
	pthread_t udpID;
	int *p=(int *)malloc(sizeof(int));
	*p=socket_svr;
	int ret=pthread_create(&udpID,NULL,(void *) ReceiveMsg,(void *)p);
	if(ret!=0){
		printf("getinfo thread error\n");
		return -1;
	}
	return TRUE;
}


void ReceiveMsg(void* argsvr)
{
	struct sockaddr_in servaddr, cliaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	socklen_t len = sizeof(cliaddr);
	unsigned char chPlate[16];
	for(;;)
	{ 
		/* waiting for receive data */
		char mesg[4] = {0x00};
		unsigned char mm[4] = {1,2,3,5};
		echo_vpr("waiting for receive data");
		recvfrom(*((int *)argsvr), mesg, 4, 0, (struct sockaddr *)&servaddr, &len);
		if(0 == memcmp(mesg,mm,4))
		{
			memset(chPlate,0,16);
			if(TRUE == VPR_GetVehicleInfo_Plate((char* )chPlate))
			{
				echo_vpr("plate:%s\n",chPlate);
				if (strlen((char*)chPlate)>0 &&  strncmp((char*)chPlate ,"无车牌",6)!=0)
				{
					VPR_HW_SetCPHM((char * )chPlate);
					i_dev_VPR_ReceivePlate();
				}
				else 
				{
					echo_vpr("无车牌");
				}
			}
		}
	}
}
