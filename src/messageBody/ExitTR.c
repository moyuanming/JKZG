//By GER.Cmd.buildgcc   CreateDate:2008-4-28 16:08:40
#include "LocalIncludeFile.h"
struct MSG_EXITTR MsgExitTR;
void InitMsgExitTR(void)
{	
	memset((char *)&MsgExitTR,'0',sizeof(struct MSG_EXITTR));	
}
struct MSG_EXITTR *GetMsgExitTR(void)
{	
	return (struct MSG_EXITTR  *)&MsgExitTR;
}
void SetExitTRMsgtranNo(char * InputTranNo)
{	
    strncpy(MsgExitTR.tranNo,InputTranNo,sizeof(MsgExitTR.tranNo));	
}
void SetExitTRMsgsubtranNo(char InputsubtranNo)
{	
	MsgExitTR.subtranNo=InputsubtranNo;
}
void SetExitTRMsgFareTblVer(char* InputFareTblVer)
{	
    strncpy(MsgExitTR.FareTblVer,InputFareTblVer,sizeof(MsgExitTR.FareTblVer));	
}
/*************************************************************************************
* 顶棚灯状态
**************************************************************************************/
void SetExitTRMsgCanopyStatus(int InputCanopyStatus)
{	
    char temp[1];
    if(InputCanopyStatus==1)
	{	
		temp[0]='G';
	}
	else
	{	
		temp[0]='R';
	}
    MsgExitTR.CanopyStatus=temp[0];
}
/*************************************************************************************
* 入口路网号
**************************************************************************************/
void SetExitTRMsgentrynetwork(char* Inputentrynetwork)
{	
    strncpy(MsgExitTR.entrynetwork,Inputentrynetwork,sizeof(MsgExitTR.entrynetwork));	
}
/*************************************************************************************
* 入口站号
**************************************************************************************/
void SetExitTRMsgEntryPlaza(char* InputEntryPlaza)
{	
    strncpy(MsgExitTR.EntryPlaza,InputEntryPlaza,sizeof(MsgExitTR.EntryPlaza));	
}
void SetExitTRMsgEntryDateTime(char* InputEntryDateTime)
{	
    strncpy(MsgExitTR.EntryDateTime,InputEntryDateTime,sizeof(MsgExitTR.EntryDateTime));	
}
/*************************************************************************************
* 入口车道号
**************************************************************************************/
void SetExitTRMsgEntryLane(char* InputEntryLane)
{	
    strncpy(MsgExitTR.EntryLane,InputEntryLane,sizeof(MsgExitTR.EntryLane));	
}
void SetExitTRMsgEntryCollector(char* InputEntryCollector)
{	
    strncpy(MsgExitTR.EntryCollector,InputEntryCollector,sizeof(MsgExitTR.EntryCollector));	
}
void SetExitTRMsgEntrySignal(char* InputEntrySignal)
{	
    strncpy(MsgExitTR.EntrySignal,InputEntrySignal,sizeof(MsgExitTR.EntrySignal));	
}
void SetExitTRMsgICCard_Type(char InputICCard_Type)
{	
	MsgExitTR.ICCard_Type=InputICCard_Type;
}
void SetExitTRMsgEntryClass(char InputEntryClass)
{	
	MsgExitTR.EntryClass=InputEntryClass;
}
/*************************************************************************************
* 出口车种
**************************************************************************************/
void SetExitTRMsgExitClass(char InputExitClass)
{	
	MsgExitTR.ExitClass=InputExitClass;
}
void SetExitTRMsgEntryType(char InputEntryType)
{	
	MsgExitTR.EntryType=InputEntryType;
}
void SetExitTRMsgEntrySubType(char InputEntrySubType)
{	
	MsgExitTR.EntrySubType=InputEntrySubType;
}
/*************************************************************************************
* 出口车型
**************************************************************************************/
void SetExitTRMsgExitType(char InputExitType)
{	
	MsgExitTR.ExitType=InputExitType;
}
void SetExitTRMsgExitSubType(char InputExitSubType)
{	
MsgExitTR.ExitSubType=InputExitSubType;
}
/*************************************************************************************
* 入口方向 X：任意方向
**************************************************************************************/
void SetExitTRMsgEntryDirection(char InputEntryDirection)
{	
	MsgExitTR.EntryDirection=InputEntryDirection;
}
void SetExitTRMsgExitDirection(char InputExitDirection)
{	
	MsgExitTR.ExitDirection=InputExitDirection;
}
void SetExitTRMsgReceipt(char InputReceipt)
{	
	MsgExitTR.Receipt=InputReceipt;
}
void SetExitTRMsgReceiptNo(char* InputReceiptNo)
{	
    strncpy(MsgExitTR.ReceiptNo,InputReceiptNo,sizeof(MsgExitTR.ReceiptNo));	
}
/*************************************************************************************
* 缴款方式
**************************************************************************************/
void SetExitTRMsgMethod_Pay(char InputMethod_Pay)
{	
	MsgExitTR.Method_Pay=InputMethod_Pay;
}
/*************************************************************************************
* 实际缴纳的通行费金额
**************************************************************************************/
void SetExitTRMsgActual_pay(int InputActual_pay)
{	
    sprintf(MsgExitTR.Actual_pay,"%010d",InputActual_pay);	
}
/*************************************************************************************
* 应缴纳的通行费金额
**************************************************************************************/
void SetExitTRMsgTollFare(int InputTollFare)
{	
    sprintf(MsgExitTR.TollFare,"%010d",InputTollFare);	
}
/*************************************************************************************
* 卡号
**************************************************************************************/
void SetExitTRMsgServiceCard(char* InputServiceCard)
{   
	char p='@' ;
	char temp[sizeof(MsgExitTR.ServiceCard)+1];
	echoic("使用的卡号:::%s",InputServiceCard);
	if (InputServiceCard==NULL ||  strlen(InputServiceCard)<=0)
	{
		p='0';
	}
	echoic("填空字符:::%c",p );
	strncpy(MsgExitTR.ServiceCard,PadLeft(p,InputServiceCard,temp,sizeof(MsgExitTR.ServiceCard)),sizeof(MsgExitTR.ServiceCard));    
}
/*************************************************************************************
* 卡号
**************************************************************************************/
void SetExitTRMsgNoOfficeCard(char InputNoOfficeCard)
{	
	MsgExitTR.NoOfficeCard=InputNoOfficeCard;
}
void SetExitTRMsgSVCOldBalance(char* InputSVCOldBalance)
{	
    strncpy(MsgExitTR.SVCOldBalance,InputSVCOldBalance,sizeof(MsgExitTR.SVCOldBalance));	
}
void SetExitTRMsgSVCBalance(char* InputSVCBalance)
{	
    strncpy(MsgExitTR.SVCBalance,InputSVCBalance,sizeof(MsgExitTR.SVCBalance));	
}
/*************************************************************************************
* 优惠率
**************************************************************************************/
void SetExitTRMsgDiscountRate(int InputDiscountRate)
{	
    sprintf(MsgExitTR.DiscountRate,"%010d",InputDiscountRate);	
}
/*************************************************************************************
* 违章情况
**************************************************************************************/
void SetExitTRMsgViolation(char InputViolation)
{	
MsgExitTR.Violation=InputViolation;
}
void SetExitTRMsgPassageLoopError(char InputPassageLoopError)
{	
MsgExitTR.PassageLoopError=InputPassageLoopError;
}
void SetExitTRMsgPresenceLoopError(char InputPresenceLoopError)
{	
MsgExitTR.PresenceLoopError=InputPresenceLoopError;
}
void SetExitTRMsgDisputeType(char InputDisputeType)
{	
MsgExitTR.DisputeType=InputDisputeType;
}
void SetExitTRMsgICCardStatus(char InputICCardStatus)
{	
MsgExitTR.ICCardStatus=InputICCardStatus;
}
void SetExitTRMsgTransSpecial(char InputTransSpecial)
{	
MsgExitTR.TransSpecial=InputTransSpecial;
}
void SetExitTRMsgICBox(char* InputICBox)
{	
    strncpy(MsgExitTR.ICBox,InputICBox,sizeof(MsgExitTR.ICBox));	
}
void SetExitTRMsgICCardNum(char* InputICCardNum)
{	
    strncpy(MsgExitTR.ICCardNum,InputICCardNum,sizeof(MsgExitTR.ICCardNum));	
}
void SetExitTRMsgOverride(char InputOverride)
{	
MsgExitTR.Override=InputOverride;
}
void SetExitTRMsgArrearTicketNo(char* InputArrearTicketNo)
{	
    strncpy(MsgExitTR.ArrearTicketNo,InputArrearTicketNo,sizeof(MsgExitTR.ArrearTicketNo));	
}
void SetExitTRMsgExitSignal(char* InputExitSignal)
{	
    strncpy(MsgExitTR.ExitSignal,InputExitSignal,sizeof(MsgExitTR.ExitSignal));	
}
void SetExitTRMsgMARK(char InputMARK)
{	
	MsgExitTR.MARK=InputMARK;
}

//end_ExitTR
