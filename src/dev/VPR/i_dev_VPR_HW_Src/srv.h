#ifndef SRV_H_
#define SRV_H_

unsigned char D_Head[4];
unsigned char* chData;
int count;
char chPlate[1000][20];
BOOL startSvr(UINT nport, int nHWYPort);
BOOL StopServer(void);
BOOL Trigger(void);
void IsNormal(void);
int UDPReady(unsigned int uPort);
int AcceptSend (int srv_fd);
int SendReady (int nport);
int RecvPakagePiece (int v_srv_fd);
int RcvReady (int nport);
void AcceptSvrForSend (void* argsvr);
int Accept (int old_srv_fd);
void AcceptSvr (void* argsvr);
void FrontinfoRecv (void * socket_fd);
void DealTwoImage(unsigned char chTwo[280]);
void SendAck (void* argsvr);
int xiangsi(char ch1, char ch2);
int GetPiPeiNum(char  ch1[20], char ch2[20], int *er_x, int *han, int *xs);
void pipei(char arr_str[1000][20], int num, char res[64]);
#endif
