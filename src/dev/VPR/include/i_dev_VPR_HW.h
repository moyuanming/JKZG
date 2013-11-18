#ifndef __i_dev_VPR_HW_H__
#define __i_dev_VPR_HW_H__
//typedef enum{TRUE=1,FALSE=!TRUE} BOOL;
typedef unsigned int UINT;
//typedef char BYTE;
BOOL VPR_Init(UINT uPort,int nHWYPort);
BOOL VPR_Quit(void);
BOOL VPR_Capture(void);
BOOL VPR_GetVehicleInfo(char *pchPlate,int *piByteBinImagLen,BYTE *pByteBinImage,int *piJpegImageLen,BYTE *pByteJpegImage);
int VPR_ComparePlate(int iFullCompare,int iRule,char *chPlateIn,char *chPlateOut);
BOOL VPR_ComparePlateBin(BYTE *lpBinImageIn,BYTE *lpBinImageOut);
BOOL VPR_CheckStatus(char *chVprDevStatus);
int createsvr(void);
void sigalrm_fn(int  sig);
void ReceiveMsg(void* argsvr);
int VPR_HW_Load(void);
int VPR_HW_UnLoad(void);
int VPR_HW_Open(void);
void VPR_HW_Close(void);
char * VPR_HW_GetCPHM(void);
void VPR_HW_ClearCPHM(void);
void VPR_HW_SetCPHM(char * _cphm);
#endif
