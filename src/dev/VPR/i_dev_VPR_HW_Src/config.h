#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifndef _CONFIG_H_
#define _CONFIG_H_
#define LINE_LEN      128
#define ERR_NONE      0
#define ERR_NOFILE    2
#define ERR_READFILE  3
#define ERR_FORMAT    4
#define ERR_NOTHING   5
int getconfigstr(const char* section,const char* keyname,char* keyvalue,unsigned int len,const char* filename);
int getconfigint(const char* section,const char* keyname,int* keyvalue,const char* filename);
#endif   
    
  

