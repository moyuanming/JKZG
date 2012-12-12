//By GER.Cmd.buildgcc   CreateDate:2008-4-28 16:08:39
#ifndef _ExitEI_H_
#define _ExitEI_H_
struct MSG_EXITEI
{
      char ErrorNO[2];
      char Occ_Rec;
      char MARK;
};//endstructExitEI
#define  LENGHT_MSG_EXITEI 4
void InitMsgExitEI(void);
struct MSG_EXITEI *GetMsgExitEI(void);
void SetExitEIMsgErrorNO(char* InputErrorNO);
void SetExitEIMsgOcc_Rec(char InputOcc_Rec);
void SetExitEIMsgMARK(char InputMARK);
#endif //define t_tablename

