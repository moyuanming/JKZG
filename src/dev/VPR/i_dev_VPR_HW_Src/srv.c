#ifndef SRV_C_
#define SRV_C_
#include "hwydef.h"
#include "srv.h"
#include "config.h"
#include <signal.h>
#endif

int letListning = 0;
int socket_fd_send = 0;
int  socket_fd_receive = 0;
void *g_pvinfo=0;
int  socket_udp = 0;
int g_nStatus = 0;
int g_nCount = 0;
pthread_mutex_t g_mutex;

void SendAck (void* argsvr)
{
	while (1)
	{
		IsNormal();
		sleep(40);
	}
}

BOOL startSvr(UINT nport, int nHWYPort)
{
  
	count = 0;
    if(0 != UDPReady(nport))
        return FALSE;
   
    int nHWYPort1 = nHWYPort;
	printf("nport=%d nHWYPort= %d nHWYPort1=%d \r\n",nport,nHWYPort,nHWYPort1);   
    if(SendReady(nHWYPort1) != 0)
    {
        letListning=0;
        return FALSE;
    }
    int nReuslt = RcvReady(nHWYPort1+1);
    if(nReuslt == 0)
    {
		pthread_t ackID;
		int ret = pthread_create(&ackID, NULL,(void *)SendAck,NULL);
		if(ret != 0)
		{
			return FALSE;
		}
        pthread_mutex_init (&g_mutex,NULL);

	
		memset(chPlate,0,sizeof(chPlate));
	
	count = 0;
	FILE *stream;
	char line[100];
	memset(chPlate,0,1000*20);

	if( (stream = fopen( "./etcno.txt", "r" )) != NULL )
	{
		while(fgets( line, 100, stream ) != NULL)
		{
			int nLine = strlen(line);
			memcpy(chPlate[count],line,nLine-1);
		//	printf("%s\r\n",chPlate[count]);
			count++;
		}
		fclose( stream );
	}
 
        return TRUE;
    }
    else
    {
        letListning=0;
        return FALSE;
    }
}

int UDPReady(unsigned int uPort)
{
    if ((socket_udp = socket (AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        return -1;
    }
    struct sockaddr_in st_srv_addr;
    bzero(&st_srv_addr, sizeof(st_srv_addr));
    st_srv_addr.sin_family = AF_INET;
    st_srv_addr.sin_port = htons (uPort);
    if(connect(socket_udp, (struct sockaddr *)&st_srv_addr, sizeof(st_srv_addr)) == -1)
    {
        return -1;
    }
    return 0;
}

BOOL StopServer()
{
    letListning=0;
    return TRUE;
}

BOOL Trigger()
{
    if(socket_fd_send>0)
    {
        unsigned char ch[11] ={0xAA,0x55,0x80,0x00,0x00,0x00,0x00,0xAA,0xF0,0x0F,0x55};
        if((send(socket_fd_send,ch,11,MSG_NOSIGNAL))<11)
        {
            socket_fd_send = 0;
            return FALSE;
        }
        else
            return TRUE;
    }
    return FALSE;
}

void IsNormal()
{
   if(socket_fd_send !=0 )
{
    if(g_nStatus == 0)
    {
	if(g_nCount ==2)
	{
	   socket_fd_send = 0;
	   g_nCount = 0;
	   return;
	}
	g_nCount++;
    }
    else
    {
	g_nCount = 0;
    }
}
    g_nStatus = 0;

    printf("socket_fd_send=%d\n",socket_fd_send);
    if(socket_fd_send>0)
    {
        unsigned char ch[9] ={0xAA,0x55,0x90,0x00,0x00,0xAA,0xF0,0x0F,0x55};
	int nResult = send(socket_fd_send,ch,9,0);
	printf("nResult=%d\n",nResult);
        if(nResult<9)
        {
            socket_fd_send = 0;
        }
     }

}

int RcvReady (int nport)
{
    int i_srv_fd;
    int opt = 1;
    struct sockaddr_in st_srv_addr;
    st_srv_addr.sin_family = AF_INET;
    st_srv_addr.sin_port = htons (nport);
    st_srv_addr.sin_addr.s_addr = htonl (INADDR_ANY);
    memset(&(st_srv_addr.sin_zero), 0, sizeof (st_srv_addr.sin_zero));
    if ((i_srv_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return -1;
    }
    setsockopt( i_srv_fd, SOL_SOCKET, SO_REUSEADDR, (const char *)&opt, sizeof(int));
    
    if(bind (i_srv_fd, (struct sockaddr *) &st_srv_addr, sizeof (struct sockaddr)) == -1)
    {    
        return -2;
    }
    if (listen (i_srv_fd, 10) < 0)
    {
        return -3;
    }
    return Accept(i_srv_fd);
    
}

int Accept (int srv_fd)
{
    pthread_t acceptSvrID;
    letListning=1;
    int *p=(int *)malloc(sizeof(int));
    *p=srv_fd;
    int ret=pthread_create(&acceptSvrID,NULL,(void *) AcceptSvr,(void *)p);
    if(ret!=0)
    {
        return -1;
    }
    return 0;
}

void AcceptSvr (void* argsvr)
{
    int  socket_fd;
    struct sockaddr_in st_cli_addr;
    socklen_t socket_len = sizeof (struct sockaddr);
    while(letListning)
    {
        if ((socket_fd = accept (*((int *)argsvr),(struct sockaddr *) &st_cli_addr, &socket_len)) < 0)
        {
        }
        else
        {
            socket_fd_receive=socket_fd;
            pthread_t reiveID;
            int *p=(int *)malloc(sizeof(int));
            *p=socket_fd;
            int ret=pthread_create(&reiveID,NULL,(void *) FrontinfoRecv,(void *)p);
		printf("listen receive\n");
            if(ret!=0)
            {
            }
        }
    }
    close(*((int *)argsvr));
    free(argsvr);
}

void FrontinfoRecv (void * socket_fd)
{
    chData = malloc(FRO_MAX_PIC_LEN);
    TYPE_STRUCT_Fro_Equi_Data  *B_S_front_data=0;
    while(1)
    {
        int nResult = RecvPakagePiece (*(int *)socket_fd);
        if(nResult < 0)
        {
		
            close(*((int *)socket_fd));
            socket_fd_receive = 0;
            free(socket_fd);
            break;
        }
        if(0==B_S_front_data)
        {
            B_S_front_data=malloc(sizeof(TYPE_STRUCT_Fro_Equi_Data));
            memset(B_S_front_data,0,sizeof(TYPE_STRUCT_Fro_Equi_Data));
            B_S_front_data->D_b_Special = malloc(FRO_MAX_PIC_LEN);
        }
        switch(chData[3])
        {
        case 0x00:
            {
				
                memcpy(B_S_front_data->D_b_Plate,chData+10,64);
		printf("srv plate = %s\n",B_S_front_data->D_b_Plate);
            }
            break;
 	case 0x01:
            {
		
                memcpy(B_S_front_data->D_b_Plate,chData+10,64);
		printf("srv 01 plate = %s\n",chData+10);
            }
            break;
        case 0x20:
            break;
        case 0x30:
            {
                DealTwoImage(B_S_front_data->D_b_Two);
            }
            break;
        case 0x60:
            {
                B_S_front_data->m_nSpecialLen = nResult;
                memcpy(B_S_front_data->D_b_Special,chData+10,nResult);
		printf("receive big image\n");
            }
            break;
        case 0x50:
            {
		printf("receive tail \n");
                pthread_mutex_lock (&g_mutex);
                if(0 != g_pvinfo)
                {
                    if(0 != ((TYPE_STRUCT_Fro_Equi_Data  *)g_pvinfo)->D_b_Special)
                    {
                        free(((TYPE_STRUCT_Fro_Equi_Data  *)g_pvinfo)->D_b_Special);
                    }
                    free(((TYPE_STRUCT_Fro_Equi_Data  *)g_pvinfo));
                }
		
		pipei(chPlate,count,(char*)B_S_front_data->D_b_Plate);
			
		
		
                g_pvinfo=B_S_front_data;
                pthread_mutex_unlock (&g_mutex);
                char chData[4] = {1,2,3,4};
                write(socket_udp, chData, 4);
                B_S_front_data=0;
            }
            break;
        default:
            break;
        }     
        memset(chData,0,FRO_MAX_PIC_LEN);
    }
    free(chData);
    chData = 0;
}

int RecvPakagePiece (int v_srv_fd)
{
    int nResult = 0;
    unsigned char ch;
    bool bFind = false;
    while(!bFind)
    {
        nResult = (recv (v_srv_fd, (unsigned char *)&ch, 1, 0));
        if(nResult <= 0)
        {
printf("recv < 0\n");
            return (-1);
        }
        D_Head[0] = D_Head[1];
        D_Head[1] = D_Head[2];
        D_Head[2] = ch;
        D_Head[3] = 0x00;
        //if(*((int *)D_Head) == DATA_TYPE)
        if(D_Head[0] == 0xAA && D_Head[1] == 0x55 && D_Head[2] == 0xff)
        {
	    printf("D_Head[0] == 0xAA && D_Head[1] == 0x55 && D_Head[2] == 0xff\n");
            bFind = true;
            memcpy(chData,D_Head,3);
            memset(D_Head,0,4);
            break;
        }
	else if(D_Head[0] == 0xAA && D_Head[1] == 0x55 && D_Head[2] == 0x90)
	{
		g_nStatus = 1;
		printf("find normal back\n");
	}
    } //end of while
    int n = FRO_HEAD_LEN_LEN;
    int m=3;
    while(n>0)
    {
        nResult = recv (v_srv_fd, chData+m, n, 0);
        if(nResult <= 0)
        {
            return (-1);
        }
        m+=nResult;
        n-=nResult;
    }
    if(chData[3] == 0xF0)
   {
	printf("chData[3] = 0xF0\n");
		return 0;
	}
    unsigned int dwLength1 = (unsigned int)(*((unsigned short *)(chData+4)))+4;
    unsigned int dwLength2 = (unsigned int)(*((unsigned short *)(chData+6)))+4;

	
printf("chData[3] = %d\n",chData[3]);
    if(chData[3]==0x60)
    {
        unsigned char bLen[4] = {chData[4],chData[5],chData[6],chData[7]};
        unsigned int nLen = *((unsigned int *)bLen)+4;
	printf("big len=%d\n",nLen);
        if(nLen<FRO_MAX_PIC_LEN)
        {
            dwLength1 = nLen;
        }
        else
        {
            return(-1);
        }
    }
    else
   {
     if(dwLength1 != dwLength2)
     {
	return 0;
     }
   }
    nResult=0;
    unsigned int nTotalLen = dwLength1;
    while(dwLength1>0)
    {
        nResult = recv (v_srv_fd, chData+m, dwLength1, 0);
        if(nResult <= 0)
        {
            return (-1);
        }
        else
        {
            dwLength1 = dwLength1-nResult;
            m+=nResult;
        }
    }
    return nTotalLen-6;
}

void DealTwoImage(unsigned char chTwo[280])
{
    unsigned char chd[2];
    chd[0]=chData[10];
    chd[1]=chData[11];
    unsigned int nWidth = (unsigned int)(*((unsigned short *)(chd)));
    unsigned char ch[280]={0xFF};
    int nWidth1=nWidth/16;
    int nRealWidth = nWidth1*16 / 2;    
    if((nRealWidth%8 == 0) && (nRealWidth%2 == 0))
        nRealWidth = nRealWidth/8 ;
    else
        nRealWidth = (nRealWidth/8) + 1;
    int h=0;    
    chd[0]=chData[12];
    chd[1]=chData[13];
    unsigned int nHeight = (unsigned int)(*((unsigned short *)(chd)));
    if(nHeight>20) nHeight=20;
    if(nRealWidth>14) nRealWidth=14;
    for(;h<nHeight;h++)
    {
        memcpy(ch+h*14,chData+14+h*nRealWidth,nRealWidth);
    }
    unsigned char ch1[280];
    memset((void *)ch1,0,280);
    int i=0;
    for(;i<280;i++)
    {
        unsigned char b0=(ch[i] << 7) & 128;
        unsigned char b1=(ch[i] << 5) & 64;
        unsigned char b2=(ch[i] << 3) & 32;
        unsigned char b3=(ch[i] << 1) & 16;
        unsigned char b4=(ch[i] >> 1) & 8;
        unsigned char b5=(ch[i] >> 3) & 4;
        unsigned char b6=(ch[i] >> 5) & 2;
        unsigned char b7=(ch[i] >> 7) & 1;
        ch1[i]=(unsigned char)(b0 | b1 | b2 | b3 | b4 | b5 | b6 | b7);
    }
    memcpy(chTwo,ch1,280);  
} 

int SendReady (int nport)
{
    int i_srv_fd;     
    int opt = 1;     
    struct sockaddr_in st_srv_addr;
    //int port = 9504;
    st_srv_addr.sin_family = AF_INET;
    st_srv_addr.sin_port = htons (nport);
    st_srv_addr.sin_addr.s_addr = htonl (INADDR_ANY);
    memset(&(st_srv_addr.sin_zero), 0, sizeof (st_srv_addr.sin_zero));
    if ((i_srv_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return -1;
    }
    setsockopt( i_srv_fd, SOL_SOCKET, SO_REUSEADDR, (const char *)&opt, sizeof(int));
    if ( bind (i_srv_fd, (struct sockaddr *) &st_srv_addr, sizeof (struct sockaddr)) == -1)
    {      
        return -2;
    }
    if (listen (i_srv_fd, 10) < 0)
    {
        return -3;
    }
    return AcceptSend(i_srv_fd);
}

int AcceptSend (int srv_fd)
{
    pthread_t acceptSvrID;
    letListning=1;
    int *p=(int *)malloc(sizeof(int));
    *p=srv_fd;
    int ret=pthread_create(&acceptSvrID,NULL,(void *) AcceptSvrForSend,(void *)p);
    if(ret!=0)
    {
        return -1;
    }
    return 0;
}

void AcceptSvrForSend (void* argsvr)
{
    int  socket_fd;
    struct sockaddr_in st_cli_addr;
    socklen_t socket_len = sizeof (struct sockaddr);
    while(letListning)
    {
        if ((socket_fd = accept (*((int *)argsvr),(struct sockaddr *) &st_cli_addr, &socket_len)) < 0)
        {
            //exit (1);
        }
        else
        {
            socket_fd_send=socket_fd;
	    printf("listen send = %d\n",socket_fd_send);
        }
    }
    close(*((int *)argsvr));
    free(argsvr);
}
int xiangsi(char ch1, char ch2)
{
	if ((ch1=='A' || ch1=='4') && (ch2=='A' || ch2=='4'))
		return 1;

	if ((ch1=='D' || ch1=='Q' || ch1=='O' || ch1=='0') && (ch2=='D' || ch2=='Q' || ch2=='O' || ch2=='0'))
		return 1;

	if ((ch1=='B' || ch1=='8') && (ch2=='B' || ch2=='8'))
		return 1;

	if ((ch1=='T' || ch1=='1' || ch1=='7') && (ch2=='T' || ch2=='1' || ch2=='7'))
		return 1;
	if ((ch1=='G' || ch1=='6') && (ch2=='G' || ch2=='6'))
		return 1;
	if ((ch1=='Z' || ch1=='2') && (ch2=='Z' || ch2=='2'))
		return 1;
	if ((ch1=='S' || ch1=='5') && (ch2=='S' || ch2=='5'))
		return 1;

	return 0;
}

int GetPiPeiNum(char ch1[20], char ch2[20], int *er_x, int *han, int *xs)
{
	int n=0, max=0;

	int s1=strlen(ch1),s2=strlen(ch2);
	int x=0, txs=0;
	
	*er_x = 0;

	int k = 0;

	*han =0;
	*xs = 0;

	for( k=0; k<5; k++ )
	{

		n = 0;
		x = 0;
		txs =0;
		int i=0;
		for( i=0; i<s1 && i+k<s2; i++ )
		{

			if( ch1[i]>127 )
			{

				if( ch2[i+k]>127 )
				{

					if( ch1[i]==ch2[i+k] && ch1[i+1] && ch2[i+k+1] )
					{

						*han = 1;
						i++;
						n ++;
						continue;
					}
				}
				i++;
				continue;
			}

			if( ch2[i+k]>127 )
			{
				i++;
				continue;
			}
			
			if(ch1[i]==ch2[i+k])
				n ++;
			else
			{
				x++;
				if (xiangsi(ch1[i], ch2[i+k]))		//字符相似
					txs += 1;
			}
		}

		if( max < n )
		{
			max = n;
//			m_k = -k;
			*er_x = x;		//
			*xs = txs;
		}
		if( k==0 )
			continue;

		n=0;
		x = 0;
		txs =0;
		for( i=0; i+k<s1 && i<s2; i++ )
		{
			if( ch1[i+k]>127 )
			{
				if( ch2[i]>127 )
				{
					if( ch1[i+k]==ch2[i] && ch1[i+k+1] && ch2[i+1] )
					{
						*han = 1;
						i++;
						n ++;
						continue;
					}
				}
				i++;
				continue;
			}
			if( ch2[i]>127 )
			{
				i++;
				continue;
			}
			if(ch1[i+k]==ch2[i])
				n ++;
			else
			{
				x++;
				if (xiangsi(ch1[i+k], ch2[i]))	//字符相似
					txs += 1;
			}
		}
		
		if( max < n )
		{
			max = n;
//			m_k = k;
			*er_x = x;		//
			*xs = txs;
		}
	}
	
	return max;
}

void pipei(char arr_str[1000][20], int num, char res[64])
{

	int i=0;
	for (i=0; i<num; i++)
	{
		int er_x=0;	//字母或数字不同的个数
		int han=0;	//判断汉字是否相同
		int xs=0;		//判断当字符不一样时, 是否相似的个数
		int j = 0;
		
		int s = GetPiPeiNum(arr_str[i], res, &er_x, &han, &xs);	//返回值为字符相同的个数
		
		if (s>=5 && er_x<=2 && (s+xs>=7 || s+xs>=6 && han==0))
		{
			memset(res, 0, 20);
			for (j=0; j<strlen(arr_str[i]); j++)
			{
				res[j] = arr_str[i][j];
			}
			break;
		}
	}
	
}
