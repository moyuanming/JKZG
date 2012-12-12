//By GER.Cmd.buildgcc   CreateDate:2008-4-28 16:08:39
#include "LocalIncludeFile.h"

struct MSG_YPKLIST     YPKListRecord[MAXPAEAMRECORDS];
struct PARAM_HEAD	YPKListHead ;


int  ParseRecordYPKList(char *RecordStr,int Rowindex)
{	
	strncpy((char *)&YPKListRecord[Rowindex],RecordStr,sizeof(struct MSG_YPKLIST));	
	return 0;
}

int LoadYPKListRecord(int IsFirst)
{	
	int ret=0;
	ret= LoadRecord(PARAYPKLIST_FILE,&YPKListHead,YPKListSTRLENGTH,ParseRecordYPKList,FRAE,IsFirst);	
	strncpy(GetMsgRevision()->YPKListVer,YPKListHead.VerNo,2);	

	return ret;
}


/*********************************************************************************************************************
检测 月票卡  ，如果月票卡参数表中存在 这样的 卡号   函数返回1，否则返回0
*********************************************************************************************************************/
char YPK_CarNo[10];
char * Get_YPK_CarNo()
{
	return YPK_CarNo;
}
void Set_YPK_CarNo(char * no)
{
	memset(YPK_CarNo,0x00,10);
	memcpy(YPK_CarNo,no,4);
}

int CheckCardNumber(char *Inputcardnumber)
{	
	int i ;
	int  rowscount;
	if(GetG_IsIC()==1)
	{
		return 1;
	}
	rowscount=atoi(YPKListHead.Recordcount);	
	for(i=0;i<rowscount;i++)
	{	
			if(0==strncmp(YPKListRecord[i].CardNumber,Inputcardnumber,atoi(sys_ini.MonthCardMaxLengh))&&0==strncmp("0",YPKListRecord[i].Status,1))
			{	
				Set_YPK_CarNo(YPKListRecord[i].CardNumber+4);
				return 1;
			}

	}
	return 0;
}
int ValidateYPKCarStartDate(char *Inputcardnumber,time_t Currenttime)
{	
	int i ;
	int  rowscount;
	rowscount=atoi(YPKListHead.Recordcount);	
	for(i=0;i<rowscount;i++)
	{	
			if(0==strncmp(YPKListRecord[i].CardNumber,Inputcardnumber,atoi(sys_ini.MonthCardMaxLengh))&&0==strncmp("0",YPKListRecord[i].Status,1)
			   &&strcmp(GetFormatTime(DATETIME_FORMAT_YYYYMMDD,Currenttime),YPKListRecord[i].BeginDate)<0)
			{	
				return 1;
			}
	}
	return 0;
}
int ValidateYPKCarEndDate(char *Inputcardnumber,time_t Currenttime)
{	
	int i ;
	int  rowscount;
	rowscount=atoi(YPKListHead.Recordcount);	
	for(i=0;i<rowscount;i++)
	{	
			if(0==strncmp(YPKListRecord[i].CardNumber,Inputcardnumber,atoi(sys_ini.MonthCardMaxLengh))&&0==strncmp("0",YPKListRecord[i].Status,1)
			   &&strcmp(GetFormatTime(DATETIME_FORMAT_YYYYMMDD,Currenttime),YPKListRecord[i].EndDate)>0)
			{	
				return 1;
			}
	}
	return 0;
}
char tempEndTime[9];
char * GetYPKCarEndDate(char *Inputcardnumber)
{	
	int i ;
	int  rowscount;
	memset(tempEndTime,0x00,sizeof(tempEndTime));	
	rowscount=atoi(YPKListHead.Recordcount);	
	for(i=0;i<rowscount;i++)
	{	
			if(0==strncmp(YPKListRecord[i].CardNumber,Inputcardnumber,atoi(sys_ini.MonthCardMaxLengh))&&0==strncmp("0",YPKListRecord[i].Status,1))
			{	
				strncpy(tempEndTime,YPKListRecord[i].EndDate,sizeof(YPKListRecord[i].EndDate));	
				return tempEndTime;
			}
	}
	return tempEndTime;
}


char tempStartTime[9];
char * GetYPKCarStartTime(char *Inputcardnumber)
{	
	int i ;
	int  rowscount;
	memset(tempStartTime,0x00,sizeof(tempStartTime));	
	rowscount=atoi(YPKListHead.Recordcount);	
	for(i=0;i<rowscount;i++)
	{	
			if(0==strncmp(YPKListRecord[i].CardNumber,Inputcardnumber,atoi(sys_ini.MonthCardMaxLengh))&&0==strncmp("0",YPKListRecord[i].Status,1))
			{	
				strncpy(tempStartTime,YPKListRecord[i].BeginDate,sizeof(YPKListRecord[i].BeginDate));	
				return tempStartTime;
			}
	}
	return tempStartTime;
}

char tempCarP[10];
char * GetCarP(char *Inputcardnumber)
{	
	int i ;
	int  rowscount;
	char temp[5];
	memset(temp,0x00,sizeof(temp));	
	memset(tempCarP,0x00,sizeof(tempCarP));	
	rowscount=atoi(YPKListHead.Recordcount);	
	for(i=0;i<rowscount;i++)
	{	
		if(0==strncmp(YPKListRecord[i].CardNumber,Inputcardnumber,atoi(sys_ini.MonthCardMaxLengh))&&0==strncmp("0",YPKListRecord[i].Status,1))
		{	
			strncpy(temp,YPKListRecord[i].CardNumber+4,4);	
			sprintf(tempCarP,"车号：%s",temp);
			return tempCarP;
		}
	}
	return tempCarP;
}


