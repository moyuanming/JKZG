//By GER.Cmd.buildgcc   CreateDate:2008-4-28 16:08:40
#ifndef _ExitTR_H_
#define _ExitTR_H_
struct MSG_EXITTR
{
      char tranNo[4];
      char subtranNo;
      char FareTblVer[2];
      char CanopyStatus;
      char entrynetwork[2];
      char EntryPlaza[2];
      char EntryDateTime[14];
      char EntryLane[3];
      char EntryCollector[6];
      char EntrySignal[32];
      char ICCard_Type;
      char EntryClass;
      char ExitClass;
      char EntryType;
      char EntrySubType;
      char ExitType;
      char ExitSubType;
      char EntryDirection;
      char ExitDirection;
      char Receipt;
      char ReceiptNo[8];
      char Method_Pay;
      char Actual_pay[10];
      char TollFare[10];
      char ServiceCard[32];
      char NoOfficeCard;
      char SVCOldBalance[6];
      char SVCBalance[6];
      char DiscountRate[10];
      char Violation;
      char PassageLoopError;
      char PresenceLoopError;
      char DisputeType;
      char ICCardStatus;
      char TransSpecial;
      char ICBox[4];
      char ICCardNum[32];
      char Override;
      char ArrearTicketNo[8];
      char ExitSignal[32];
      char MARK;
};//endstructExitTR

#define  LENGHT_MSG_EXITTR 315
void InitMsgExitTR(void);
struct MSG_EXITTR *GetMsgExitTR(void);
void SetExitTRMsgtranNo(char * InputTranNo);
void SetExitTRMsgsubtranNo(char InputsubtranNo);
void SetExitTRMsgFareTblVer(char* InputFareTblVer);
void SetExitTRMsgCanopyStatus(int InputCanopyStatus);
void SetExitTRMsgentrynetwork(char* Inputentrynetwork);
void SetExitTRMsgEntryPlaza(char* InputEntryPlaza);
void SetExitTRMsgEntryDateTime(char* InputEntryDateTime);
void SetExitTRMsgEntryLane(char* InputEntryLane);
void SetExitTRMsgEntryCollector(char* InputEntryCollector);
void SetExitTRMsgEntrySignal(char* InputEntrySignal);
void SetExitTRMsgICCard_Type(char InputICCard_Type);
void SetExitTRMsgEntryClass(char InputEntryClass);
void SetExitTRMsgExitClass(char InputExitClass);
void SetExitTRMsgEntryType(char InputEntryType);
void SetExitTRMsgEntrySubType(char InputEntrySubType);
void SetExitTRMsgExitType(char InputExitType);
void SetExitTRMsgExitSubType(char InputExitSubType);
void SetExitTRMsgEntryDirection(char InputEntryDirection);
void SetExitTRMsgExitDirection(char InputExitDirection);
void SetExitTRMsgReceipt(char InputReceipt);
void SetExitTRMsgReceiptNo(char* InputReceiptNo);
void SetExitTRMsgMethod_Pay(char InputMethod_Pay);
void SetExitTRMsgActual_pay(int InputActual_pay);
void SetExitTRMsgTollFare(int InputTollFare);
void SetExitTRMsgServiceCard(char* InputServiceCard);
void SetExitTRMsgNoOfficeCard(char InputNoOfficeCard);
void SetExitTRMsgSVCOldBalance(char* InputSVCOldBalance);
void SetExitTRMsgSVCBalance(char* InputSVCBalance);
void SetExitTRMsgDiscountRate(int InputDiscountRate);
void SetExitTRMsgViolation(char InputViolation);
void SetExitTRMsgPassageLoopError(char InputPassageLoopError);
void SetExitTRMsgPresenceLoopError(char InputPresenceLoopError);
void SetExitTRMsgDisputeType(char InputDisputeType);
void SetExitTRMsgICCardStatus(char InputICCardStatus);
void SetExitTRMsgTransSpecial(char InputTransSpecial);
void SetExitTRMsgICBox(char* InputICBox);
void SetExitTRMsgICCardNum(char* InputICCardNum);
void SetExitTRMsgOverride(char InputOverride);
void SetExitTRMsgArrearTicketNo(char* InputArrearTicketNo);
void SetExitTRMsgExitSignal(char* InputExitSignal);
void SetExitTRMsgMARK(char InputMARK);
#endif //define t_tablename

