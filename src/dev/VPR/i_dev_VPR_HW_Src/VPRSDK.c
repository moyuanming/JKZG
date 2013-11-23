#include "VPRSDK.h"
#include "srv.h"
#include "globalvar.h"
#include "time.h"
#include "signal.h"
BOOL VPR_Init(unsigned int uPort,int nHWYPort)
{
printf("%d  %d  \r\n",uPort,nHWYPort);
    signal(SIGPIPE,SIG_IGN);
    BOOL bSuccess = FALSE; 
    if(0==letListning)
    {
        bSuccess = startSvr(uPort,nHWYPort);
        if(TRUE == bSuccess)
        {
            g_nIni = 1;
            time(&g_tmStart);
        }
        return bSuccess;
    }
    else
    {
        g_nIni = 1;
        return TRUE;
    }
}

int VPR_ComparePlate(int iFullCompare,int iRule,char *chPlateIn,char *chPlateOut)
{
    if(chPlateIn == NULL || chPlateOut == NULL )
    {
        return -1;
    }
    if(0 != iFullCompare)
    {
        if(0 == strcmp(chPlateIn,chPlateOut))    
            return 0;
        else
            return 3;    
    }
    else
    {
        int nCount = 0;
        int i = 0;
        for(i = 0;i<strlen(chPlateIn);i++)
        {
            if(((unsigned char)chPlateIn[i])>127)
            {
                if(strlen(chPlateOut) > i+2)
                {
                    if(0 == memcmp(chPlateIn+i,chPlateOut+i,2))
                        nCount++;
                }
                i++;
            }
            else
            {
                if(chPlateOut[i] == chPlateIn[i])
                {
                    nCount++;
                }
            }
        }
        int fl = (float)nCount*100/(float)iRule;
        if(fl >= 100) 
            return 0;
        else if(fl<100 && fl>=85)
            return 1;
        else if(fl<85 && fl>=70)
            return 2;
        else
            return 3;
    }
}

BOOL VPR_Quit()
{
    g_nIni = 0;
    return StopServer();
}

BOOL VPR_Capture()
{
    return Trigger();
}
BOOL VPR_GetVehicleInfo_Plate(char *pchPlate)
{
	 if(pchPlate == NULL)
    {
        return FALSE;
   	}
    pthread_mutex_lock (&g_mutex);
    TYPE_STRUCT_Fro_Equi_Data *info=(TYPE_STRUCT_Fro_Equi_Data *)g_pvinfo;
    g_pvinfo=0;
    pthread_mutex_unlock (&g_mutex);
    if(0 == info)
    {
        return FALSE;
    }
	printf("plate = %s\n",info->D_b_Plate);
    if(0 == strlen((char *)info->D_b_Plate))
        strcpy(pchPlate,"无车牌");
    else
        strcpy(pchPlate,(char *)info->D_b_Plate);
    int nLen = 280;
    free(info);
    return TRUE;

}
BOOL VPR_GetVehicleInfo(char *pchPlate,int *piByteBinImagLen,BYTE *pByteBinImage,int *piJpegImageLen,BYTE *pByteJpegImage)
{
    if(pchPlate == NULL || piByteBinImagLen == NULL || piJpegImageLen == NULL || pByteJpegImage == NULL)
    {
        return FALSE;
   	}
    pthread_mutex_lock (&g_mutex);
    TYPE_STRUCT_Fro_Equi_Data *info=(TYPE_STRUCT_Fro_Equi_Data *)g_pvinfo;
    g_pvinfo=0;
    pthread_mutex_unlock (&g_mutex);
    if(0 == info)
    {
        return FALSE;
    }
	printf("plate = %s\n",info->D_b_Plate);
    if(0 == strlen((char *)info->D_b_Plate))
        strcpy(pchPlate,"无车牌");
    else
        strcpy(pchPlate,(char *)info->D_b_Plate);
    int nLen = 280;
    *piByteBinImagLen = nLen;
    memcpy(pByteBinImage,info->D_b_Two,280);
    nLen = info->m_nSpecialLen;
    *piJpegImageLen = nLen;
    if(0 != info->D_b_Special)
    {
        memcpy(pByteJpegImage,info->D_b_Special,info->m_nSpecialLen);
        free(info->D_b_Special);
    }
    free(info);
    return TRUE;
}

BOOL VPR_ComparePlateBin(BYTE *lpBinImageIn,BYTE *lpBinImageOut)
{
    if( lpBinImageIn == NULL || lpBinImageOut == NULL )
    {
        return FALSE;
   	}
    int i = 0;
    for(i = 0;i < 280;i++)
    {
        if(lpBinImageIn[i] != lpBinImageOut[i])
        {
            return FALSE;
        }
    }
    return TRUE;
}

BOOL VPR_CheckStatus(char *chVprDevStatus)
{
    if( chVprDevStatus == NULL )
    {
        return FALSE;
   	}
    if(0 == g_nIni)
    {
        strcpy(chVprDevStatus,"??óD3?ê??ˉéè±?");
            return FALSE;
    }
    time_t tmEnd ;
    time(&tmEnd);
    int nDif = difftime(tmEnd,g_tmStart);
    if(nDif < 30)
    {
        strcpy(chVprDevStatus,"éè±??y3￡");
        return TRUE;
    }
    IsNormal();
    if(0 != socket_fd_send)
    {
        strcpy(chVprDevStatus,"éè±??y3￡");
        return TRUE;
    }
    else
    {
        strcpy(chVprDevStatus,"éè±?í???1ê??");
        return FALSE;
    }
}

