//By GER.Cmd.buildgcc   CreateDate:2008-4-28 16:08:39
#ifndef _ExitHt_H_
#define _ExitHt_H_
//Ð¡Ê±¼ÇÂ¼
struct MSG_EXITHT
{
	struct MSG_HEAD  EXITES_HEAD;
	char Total_Traffic[10];
	char Total_Violation[10];
	char total_emergency[10];
	char total_official[10];
	struct  CARKINDUNTYPE CarInfoContext[12];
	char Opentime[10];
	char MARK;
};//endstructExitHt
#define  LENGHT_MSG_EXITHT 1276


#define  LENGHT_MSG_EXITHTHEAD 72+40
#define  LENGHT_MSG_EXITHTEND 111+1
#define  LENGHT_MSG_NEWEXITHT (MSG_NewTifficStatLenght+LENGHT_MSG_EXITHTHEAD+LENGHT_MSG_EXITHTEND)


void InitMsgExitHt(void);
struct MSG_EXITHT *GetMsgExitHt(void);
void SetExitHtMsgTotal_Traffic(void);
void AddMsgTotal_Violation(void);
void AddMsgtotal_emergency(void);
void SetExitHtMsgtotal_emergency(void);
void AddMsgtotal_official(void);
 
void SetExitHtMsgOpentime(char * InputOpentime);
void SetExitHtMsgMARK(char InputMARK);
void LoadMsgExitHT(void);
void CheckHourSend(void);
void CheckHourSend_extracted(void);
void SendHT(char *MessageBody);
void Sync_ExitHT(void);
#endif //define t_tablename


