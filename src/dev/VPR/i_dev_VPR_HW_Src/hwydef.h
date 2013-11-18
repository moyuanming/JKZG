#ifndef HWYDEF_H_
#define HWYDEF_H_
typedef unsigned int UINT;
typedef char BYTE;
#define FRO_HEAD_TYPE_LEN      3
#define FRO_HEAD_LEN_LEN       5
#define FRO_MAX_PIC_LEN        102400*5
#define DATA_TYPE              16733610
typedef enum{FALSE =0,TRUE=!FALSE } BOOL;
typedef enum{false =0,true=!false } bool;
typedef  struct  tagTYPE_STRUCT_Fro_Equi_Data
{
    unsigned char    D_b_Plate[64];
    unsigned char*   D_b_Special;
    unsigned int     m_nSpecialLen;
    unsigned char    D_b_Two[280];
} TYPE_STRUCT_Fro_Equi_Data;

#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <sched.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/resource.h>
#include   <ctype.h>
#include "time.h"
#include "sys/time.h"

#endif
