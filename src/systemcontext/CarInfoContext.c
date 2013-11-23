// ***************************************************************
//  UserContext   version:  1.0   ·  date: 5/05/2008
//  -------------------------------------------------------------
//  车、车队过车信息事务上下文
//  -------------------------------------------------------------
//  Copyright (C) 2008 - All Rights Reserved
// ***************************************************************
#include "LocalIncludeFile.h"
/*******************************************************************************/
 //紧急车队
/*******************************************************************************/
volatile BOOL G_Urgent_Car_Team_Enabled = F;
void SetG_Urgent_Car_Team_Enabled(BOOL  value)
{	
    G_Urgent_Car_Team_Enabled=value;
}

int GetG_Urgent_Car_Team_Enabled(void)
{	
    return G_Urgent_Car_Team_Enabled;
}

/*******************************************************************************/
////普通车队过车数量
/*******************************************************************************/
volatile int G_Car_Pass_Count=0;

void AddG_Car_Pass_Count(void)
{	
    ++G_Car_Pass_Count;
}

void DesG_Car_Pass_Count(void)
{	
    G_Car_Pass_Count--;
}


void SetG_Car_Pass_Count(int value)
{	
    G_Car_Pass_Count=value;
}

int GetG_Car_Pass_Count(void)
{	
    return G_Car_Pass_Count;
}

/*******************************************************************************/
////车队通过的车辆的数量
/*******************************************************************************/
volatile int G_Car_Passed_Count=0;

void AddG_Car_Passed_Count(void)
{	
    ++G_Car_Passed_Count;
}

void SetG_Car_Passed_Count(int value)
{	
    G_Car_Passed_Count=value;
}


int GetG_Car_Passed_Count(void)
{	
    return G_Car_Passed_Count;
}

/*******************************************************************************/
////在提示列表中显示最大车辆列表数
/*******************************************************************************/
volatile int G_Max_Show_Car_Pass_Count=7;
void SetG_Max_Show_Car_Pass_Count(int value)
{	
    G_Max_Show_Car_Pass_Count=value;
}
/*****************************************/
int GetG_Max_Show_Car_Pass_Count(void)
{	
    return G_Max_Show_Car_Pass_Count;
}

/*******************************************************************************/
////当前显示车辆的开始索引
/*******************************************************************************/
volatile int G_Show_Car_Tem_Index=0;
void SetG_Show_Car_Tem_Index(int value)
{	
    G_Show_Car_Tem_Index=value;
}

void AddG_Show_Car_Tem_Index(void)
{	
    ++G_Show_Car_Tem_Index;
}

void DesG_Show_Car_Tem_Index(void)
{	
    G_Show_Car_Tem_Index--;
}


int GetG_Show_Car_Tem_Index(void)
{	
    return G_Show_Car_Tem_Index;
}

/*******************************************************************************/
//由那个状态违章 违章处理完后将自动返回到这个状态
/*******************************************************************************/
volatile int G_weiZhangState=0;

void SetG_weiZhangState(int  value)
{	
    G_weiZhangState=value;
}

int GetG_weiZhangState(void)
{	
    return G_weiZhangState;
}

/*******************************************************************************
//违章类型
0-	正常
1-	违章
2-	后退
3-	误报警
4-   为了发送SendMsgInfo消息的方便，发消息时它对应空字符
******************************************************************************/
volatile int G_weiZhangType;

void SetG_weiZhangType(int  value)
{	
     G_weiZhangType=value;
}

int GetG_weiZhangType(void)
{	
    return  G_weiZhangType;
}

/*******************************************************************************/
//模拟类型
/*******************************************************************************/
volatile int G_simulateType=0;
void SetG_simulateType(int  value)
{	
     G_simulateType=value;
}

int GetG_simulateType(void)
{	
    return  G_simulateType;
}

/*******************************************************************************/
//用来控制多次模拟操作 模拟操作中只有重打票据可以连续做
/*******************************************************************************/
volatile BOOL G_simulateEnabled = T;
void SetG_simulateEnabled(BOOL value)
{	
     G_simulateEnabled=value;
}

int GetG_simulateEnabled(void)
{	
    return  G_simulateEnabled;
}

/*******************************************************************************/
//标识是那个工作状态进行的模拟操作 不同的工作状态决定模拟完成后将回到什么状态
/*******************************************************************************/
volatile int G_simulateWorkState=0;
void SetG_simulateWorkState(int value)
{	
     G_simulateWorkState=value;
}

int GetG_simulateWorkState(void)
{	
    return  G_simulateWorkState;
}

/*******************************************************************************/
//是否可以重打票据 （只有收费车和免费车可以重打票据）
/*******************************************************************************/
volatile BOOL G_billRePrintEnabled;
void SetG_billRePrintEnabled(BOOL  value)
{	
     G_billRePrintEnabled=value;
}

int GetG_billRePrintEnabled(void)
{	
    return  G_billRePrintEnabled;
}

/*******************************************************************************/
 //重打票据次数
/*******************************************************************************/
volatile int G_reprintbillnum=0;
void SetG_reprintbillnum(int value)
{	
     G_reprintbillnum=value;
}
void AddG_reprintbillnum(void)
{	
    G_reprintbillnum++;
}
int GetG_reprintbillnum(void)
{	
    return  G_reprintbillnum;
}

/*******************************************************************************/
//票据号不一致的时候
/*******************************************************************************/
void SetbillNumber_str(char * value)
{	
    SetbillCount( atoi(value));	
	writeBillNumber();	
}
char tempbillNumber_str[9];
char * GetbillNumber_str(void)
{	
    memset(tempbillNumber_str,'0',sizeof(tempbillNumber_str));	
    tempbillNumber_str[8]=0x00;
    sprintf(tempbillNumber_str,"%3.3s%05d",GetLanConfigLaneNo(),GetbillCount());	
    return tempbillNumber_str;
}
/*******************************************************************************/

/*******************************************************************************/
volatile BOOL G_Loop_Enable = T;
void SetG_Loop_Enable(BOOL  value)
{	
     G_Loop_Enable=value;
}

int GetG_Loop_Enable(void)
{	
    return  G_Loop_Enable;
}

/*******************************************************************************/
//车队标示在产生消息时用到
/*******************************************************************************/

int carTem = 0;
void SetcarTem(int value)
{	
     carTem=value;
}

int GetcarTem(void)
{	
    return carTem;
}

/*******************************************************************************/
////是在进行车队处理
/*******************************************************************************/

volatile BOOL  G_Car_Team_Enabled=F;
void SetG_Car_Team_Enabled(BOOL value)
{	
     G_Car_Team_Enabled=value;
}

int GetG_Car_Team_Enabled(void)
{	
    return  G_Car_Team_Enabled;
}

/*******************************************************************************/
//车牌号
/*******************************************************************************/
char G_CarNumber[9] ;
void  SETG_CarNumber_end(int value)
{	
    G_CarNumber[value] = '\0';
}

void  InitG_CarNumber(void)
{	
        memset(G_CarNumber, '\0', 9);	
}
void SetG_CarNumber(char *value)
{	
    strncpy(G_CarNumber,value,sizeof(G_CarNumber));	
}

char *GetG_CarNumber(void)
{	
    return G_CarNumber;
}
/*******************************************************************************/
//
/*******************************************************************************/
int G_BeforWzWorkstation = -1;
void SetG_BeforWzWorkstation(int value)
{	
     G_BeforWzWorkstation=value;
}

int GetG_BeforWzWorkstation(void)
{	
    return G_BeforWzWorkstation;
}

/*******************************************************************************/
//
/*******************************************************************************/
int G_BeforWzLaneState = -1;
void SetG_BeforWzLaneState(int value)
{	
     G_BeforWzLaneState=value;
}

int GetG_BeforWzLaneState(void)
{	
    return G_BeforWzLaneState;
}

/*******************************************************************************
*票据打印标志
*0 不要
*1只一次就正确打印出收据
2 备用手撕票
3 重打的次数(16进制)
4-   为了发送SendMsgInfo消息的方便，发消息时它对应空字符
*******************************************************************************/
int G_BillPrintFlag = -1;
void SetG_BillPrintFlag(int value)
{	
     G_BillPrintFlag=value;
}

int GetG_BillPrintFlag(void)
{	
    return G_BillPrintFlag;
}

/*******************************************************************************/
// 欠款单号
/*******************************************************************************/
char G_ArrearageNumber[20];

void  InitG_ArrearageNumber(void)
{	
    memset(G_ArrearageNumber,'\0',20);	
}

void  SETG_ArrearageNumber_end(int value)
{	
     G_ArrearageNumber[value-1]='\0';
}

void SetG_ArrearageNumber(char *value)
{	
    strncpy(G_ArrearageNumber,value,sizeof(G_ArrearageNumber));	
}

char *GetG_ArrearageNumber(void)
{	
    return G_ArrearageNumber;
}
/*******************************************************************************/
//欠款额
/*******************************************************************************/

int G_ArrearageCharge=0;
void SetG_ArrearageCharge(int value)
{	
     G_ArrearageCharge=value;
}

int GetG_ArrearageCharge(void)
{	
    return G_ArrearageCharge;
}

/*******************************************************************************/
//欠款额
/*******************************************************************************/
char G_ArrearageChargeChar[20];

void  SETG_ArrearageChargeChar_end(int value)
{	
     G_ArrearageChargeChar[value-1]='\0';
}


void InitG_ArrearageChargeChar(void)
{	
    memset(G_ArrearageChargeChar,'\0',20);	
}

void SetG_ArrearageChargeChar(char *value)
{	
    strncpy(G_ArrearageChargeChar,value,sizeof(G_ArrearageChargeChar));	
}

char *GetG_ArrearageChargeChar(void)
{	
    return G_ArrearageChargeChar;
}
/*******************************************************************************/
//是否有夹杂在普通车队的其他车辆
/*******************************************************************************/
BOOL inCarTeamOtherCar =F;
void SetinCarTeamOtherCar(BOOL   value)
{	
    inCarTeamOtherCar=value;
}
BOOL GetinCarTeamOtherCar(void)
{	
    return inCarTeamOtherCar;
}
/*******************************************************************************/
//当前处理车的车型
/*******************************************************************************/
char G_Current_Handl_Car_Type[4];
void InitG_Current_Handl_Car_Type()
{	
	memset(G_Current_Handl_Car_Type,' ',4);	
    I_DEV_VDM_CarType(" ");	
}
void SetG_Current_Handl_Car_Type(char *value)
{	
    strncpy(G_Current_Handl_Car_Type,value,sizeof(G_Current_Handl_Car_Type));	
    I_DEV_VDM_CarType(value);	
}

char *GetG_Current_Handl_Car_Type(void)
{	
    return G_Current_Handl_Car_Type;
}
int Get_Current_Car_Type_Index(void)
{	
	int ret = -1;
	ret=atoi(GetG_Current_Handl_Car_Type())-1;
	return ret;
}
/*******************************************************************************/
////当前处理车的车种
/*******************************************************************************/
char G_Current_Handl_Car_Kind[9];
int G_Current_Handl_Car_Kind_int =0;
void InitG_Current_Handl_Car_Kind()
{	
	memset(G_Current_Handl_Car_Kind,' ',9);	
    G_Current_Handl_Car_Kind_int=-2;
   I_DEV_VDM_CarKind(G_Current_Handl_Car_Kind_int);	
}
void SetG_Current_Handl_Car_Kind(char *value)
{	
    strncpy(G_Current_Handl_Car_Kind,value,sizeof(G_Current_Handl_Car_Kind));	
}

char *GetG_Current_Handl_Car_Kind(void)
{	
    return G_Current_Handl_Car_Kind;
}

void SetG_Current_Handl_Car_Kind_INT(int value)
{	
  G_Current_Handl_Car_Kind_int=value;
}

int GetG_Current_Handl_Car_Kind_INT(void)
{	
    return G_Current_Handl_Car_Kind_int;
}

/*******************************************************************************/
////当前处理车辆的金额
/*******************************************************************************/
volatile float G_Current_Handl_Charge=0;
void SetG_Current_Handl_Charge(float value)
{	
    G_Current_Handl_Charge=value;
	I_DEV_VDM_Cash((int)value);
}
float GetG_Current_Handl_Charge(void)
{	
    return G_Current_Handl_Charge;
}
float Get_G_Current_Actual_pay(void)
{	
	return G_Current_Handl_Charge;
}
volatile float G_Current_Toll_Fare=0;
float Get_G_Current_Toll_Fare(void)
{	
	return G_Current_Toll_Fare;
}
void Set_G_Current_Toll_Fare(float value)
{	
	G_Current_Toll_Fare=value;
	echoic("Get_G_Current_Actual_pay <%f>Get_G_Current_Toll_Fare<%f><%f><%f>",Get_G_Current_Actual_pay(),value,G_Current_Toll_Fare,Get_G_Current_Toll_Fare());
}






char tempCharge[12];
char * GetG_Current_Handl_Charge_str()
{	

	if(0==(int)G_Current_Handl_Charge)
	{	
		memset(tempCharge,' ',12);	
		return tempCharge;
	}
	else
	{	
		memset(tempCharge,' ',12);	
		sprintf(tempCharge,"%d",(int)G_Current_Handl_Charge);	
		return tempCharge;
	}
}
/*******************************************************************************/
////当前车队的总金额
/*******************************************************************************/

int G_Current_Car_Team_Charge_Total=0;
void SetG_Current_Car_Team_Charge_Total(int value)
{	
    G_Current_Car_Team_Charge_Total=value;
}

int GetG_Current_Car_Team_Charge_Total(void)
{	
    return G_Current_Car_Team_Charge_Total;
}

/*******************************************************************************/
////显示处理车队车辆信息
/*******************************************************************************/
char G_Show_Handl_Car_Information[300];
void SetG_Show_Handl_Car_Information(char *value)
{	
    strncpy(G_Show_Handl_Car_Information,value,sizeof(G_Show_Handl_Car_Information));	
}

void InitG_Show_Handl_Car_Information(void)
{	
     memset(G_Show_Handl_Car_Information, '\0', 300);	
}

void strcatG_Show_Handl_Car_Information(char * value)
{	
        strcat(G_Show_Handl_Car_Information, value);	
}


char *GetG_Show_Handl_Car_Information(void)
{	
    return G_Show_Handl_Car_Information;
}
/*******************************************************************************/
////车型
/*******************************************************************************/
char G_Car_Type[9];

void InitG_Car_Type(void)
{	
    memset(G_Car_Type, '\0', 9);	
}

void SETG_Car_Type_end(int value)
{	
        G_Car_Type[value] = '\0';
}


void SetG_Car_Type(char* value)
{	
    strncpy(G_Car_Type,value,sizeof(G_Car_Type));	
}
char  *GetG_Car_Type(void)
{	
    return G_Car_Type;
}


/**
 * 发送监控呼叫
 */
void SendTcoWaingMsg(char *Msg)
{
	char title[80];
	char context[80];
	char path [80];
	memset(title,0x00,strlen(title));
	memset(context,0x00,strlen(context));
	memset(path,0x00,strlen(path));
	if (EnabledCallTCS()==F)
	{
		return;
	}
	if (0== 1 && GetDevCStatePlazaServerState())
	{
		return;
	}
	InitMsgTCO();   
	GetMsgTCO()->MsgType =MSGTCO_CMD_TCOWAING ;
	sprintf(title,"%s%-60s","提示",SUBSTRING(GetMsgHead()->LaneNo));
	strncpy(GetMsgTCO()->MsgTitle,title,sizeof(GetMsgTCO()->MsgTitle));
	sprintf(context,"%-60s",Msg);
	strncpy(GetMsgTCO()->MsgContext,context,sizeof(GetMsgTCO()->MsgContext));
	sprintf(path,"%-60s",BuildTCOImage(MSGTCO_CMD_TCOWAING,Msg));
	strncpy(GetMsgTCO()->MsgImagePath,path,sizeof(GetMsgTCO()->MsgImagePath));
	SendMessageToQueue(ID_TCOMSG ); 
	echoic("消息%s \n图片地址%s",Msg,SUBSTRING(GetMsgTCO()->MsgImagePath));
}
char _YCQK[100];
void InitYCQK(void)
{
	memset(_YCQK,0x00,100);
}
void AddYCQK(char * tmp)
{
	int l=0;
	if (tmp==NULL || strlen(tmp)>32)
	{
		return;
	}
	if (strlen(_YCQK)>0)
	{
		l =strlen(_YCQK)+strlen(tmp);
		echoic("LLLLLLLLLLLLLLL=%d   :::%s",l,_YCQK);
		if (l<=31)
		{
			sprintf(_YCQK,"%s/%s",_YCQK,tmp);
			_YCQK[33]=0;
		}
	}
	else
	{
		sprintf(_YCQK,"%s",tmp);
	}
}
char * GetYCQK(void)
{
	strncpy(_YCQK,_YCQK,32);
	return _YCQK;
}
struct Information_Node * Create_InforNode()
{
	struct Information_Node * Node;
	Node = (struct Information_Node * ) malloc (INFORMATION_NODE_LEN); 
	Node->Next = NULL;
	Node->Back = NULL;
	strcpy(Node->Car_Type , GetG_Car_Type());  
	strcpy(Node->Car_Kind, Getg_CurrentCarKindExplain());  
	strcpy(Node->Car_Team,GetG_Car_Team_Enabled() ? "车队:":"");   
	Node->Charge = GetG_Current_Handl_Charge();    
	return Node;
}
void FreeG_Head_Information_Node()
{
	struct Information_Node * Node;
	Node = G_Head_Information_Node->Next ;
	while (G_Head_Information_Node != Node)
	{
		G_Head_Information_Node->Next = Node->Next;
		free(Node); 
		Node = G_Head_Information_Node->Next;
	}

}

void Add_Handl_Car_Information(int Index)
{	
    char StrTemp[9];
    int i = 0;
   struct  Information_Node *P, *P1;
    P = Create_InforNode();	

    AddG_Car_Pass_Count();	
    //AddExitESMsgTotal_MotorCade();	
    if (GetG_Car_Pass_Count() > GetG_Max_Show_Car_Pass_Count())
    {	
        SetG_Show_Car_Tem_Index(GetG_Car_Pass_Count() -GetG_Max_Show_Car_Pass_Count());	
    }
    memset(StrTemp, '\0', 9);	
    if(GetG_Car_Team_Enabled())
    {	
        if (GetG_Car_Pass_Count()<10)
        {	
            sprintf(StrTemp,"第0%d辆",GetG_Car_Pass_Count());	
        }
        else
        {	
            sprintf(StrTemp,"第%d辆",GetG_Car_Pass_Count());	
        }
    }
    else
    {	
        strcpy(StrTemp,"非车队");	
    }
    strcpy(P->Car_Team,StrTemp);	
    P1 = G_Head_Information_Node;
    if (Index==0)
    {	
        if(GetG_Car_Team_Enabled())
        {	
            //还是车队的时候插在后面
            P->Back= P1->Back;
            P1->Back->Next= P;
            P->Next = P1;
            P1->Back = P;
        }
        else
        {	
            //不是的时候插在后面
            P->Next= P1->Next;
            P1->Next->Back= P;
            P->Back = P1;
            P1->Next = P;


        }

    }
    else
    {	
        for (i=0;i<Index;i++)
        {	
            P1 = P1->Next;
        }
        P->Next= P1->Next;
        P1->Next->Back= P;
        P->Back = P1;
        P1->Next = P;
    }



}

void Reduce_Handl_Car_Information()
{	
    struct Information_Node *P;
    char Strtemp[9];
    int Count =0;
    AddG_Car_Passed_Count();	
    //AddMsgtotal_official();	
    P = G_Head_Information_Node->Next ;

    while(P !=G_Head_Information_Node)
    {	
        Count ++;
        if (Count ==GetG_Car_Passed_Count())
        {	
            memset(Strtemp, '\0', 9);	
            sprintf(Strtemp,"*%s",P->Car_Team);	
            strcpy(P->Car_Team,Strtemp);	
            break;
        }
        P = P->Next;
    }
}
void Delete_Handl_Car_Information(int index)
{	
    struct Information_Node *P;
    P = G_Head_Information_Node->Back;
    if (P==G_Head_Information_Node)
    {	
        //Set_WorkStation_05_Start_Car_Team();	
    }
    else
    {	
        if (-1==index)
        {	
            DesG_Car_Pass_Count();	
            G_Head_Information_Node->Back = P->Back;
            P->Back->Next = G_Head_Information_Node;
            free(P);	
            //Show_Handl_Car_Information("提示：普通车队列表\n");	

        }
        else
        {	
            int i;
            P=G_Head_Information_Node;
            for(i=0;i<=index;i++)
            {	
                P=P->Next;
            }
            P->Back->Next=P->Next;
            P->Next->Back = P->Back;
            free(P);	
        }
    }
}




