#ifndef __i_dev_VPR__
#define __i_dev_VPR__
int CPSB_Load(void);
int CPSB_UnLoad(void);
int DVR_Open(void);
void DVR_Close(void);
char * GetCPHM(void);
void ClearCPHM(void);
void i_dev_VPR_ReceivePlate(void );
#endif
