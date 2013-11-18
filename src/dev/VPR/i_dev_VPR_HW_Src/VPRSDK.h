#ifndef VPRSDK_H_
#define VPRSDK_H_
#include "hwydef.h"
BOOL VPR_Init(UINT uPort,int nHWYPort);
BOOL VPR_Quit(void);
BOOL VPR_Capture(void);
BOOL VPR_GetVehicleInfo(char *pchPlate,int *piByteBinImagLen,BYTE *pByteBinImage,int *piJpegImageLen,BYTE *pByteJpegImage);
int  VPR_ComparePlate(int iFullCompare,int iRule,char *chPlateIn,char *chPlateOut);
BOOL VPR_ComparePlateBin(BYTE *lpBinImageIn,BYTE *lpBinImageOut);
BOOL VPR_CheckStatus(char *chVprDevStatus);
#endif /*VPRSDK_H_*/

