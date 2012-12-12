#include "LocalIncludeFile.h"

BOOL WorkFlow_Peccancy(int nKey)
{
	BOOL ok=F;
	if (Getg_bWeiZhang())
	{
		WorkFlow_WeiZhang(nKey);
		ok=TRUE;
	}
	else if (nKey==VK_WEIZHANG)
	{
		Set_WorkStation_49_WeiZhang();
		SetRing(T);
		ok=TRUE;
	}
	return ok;
}
void WorkFlow_WeiZhang(int nKey)
{

		if (GetG_weiZhangState()==0)
		{
			WorkStation_49_WeiZhang(nKey);
		}
		else if (GetG_weiZhangState()==1)
		{
			WorkStation_59_WeiZhangHandl(nKey);
		}
		else if (2 == GetG_weiZhangState())
		{
			WorkStation_40_InPutWzCarType(nKey);
		}
		else if (3 == GetG_weiZhangState())
		{
			WorkStation_41_WzOK(nKey);
		}
}
void WorkStation_40_InPutWzCarType(nKey)
{
	switch (nKey)
	{
		case VK_1:
			wzCarType=1;
			SetG_weiZhangState(3);
			Set_WorkStation_41_WzOK("一型车");
			break;
		case VK_2:
			wzCarType=2;
			SetG_weiZhangState(3);
			Set_WorkStation_41_WzOK("二型车");
			break;
		case VK_3:
			wzCarType=3;
			SetG_weiZhangState(3);
			Set_WorkStation_41_WzOK("三型车");
			break;
		case VK_4:
			wzCarType=4;
			SetG_weiZhangState(3);
			Set_WorkStation_41_WzOK("四型车");
			break;
		case VK_5:
			SetG_weiZhangState(3);
			wzCarType=5;
			Set_WorkStation_41_WzOK("五型车");
			break;
		case VK_6:
			SetG_weiZhangState(3);
			wzCarType=6;
			Set_WorkStation_41_WzOK("其他或未知");
			break;
		case VK_CANCEL:
			SetG_weiZhangState(0);
			UI_Show_Info("提示: 请选择线圈报警原因\n1. 闯道\n2. 倒车\n3. 误报警");
			Setg_CurrentLaneState(7);
			break;
		default:
			ErrorPressKey();
			break;
	}
}

void WorkStation_41_WzOK(int nKey)
{
	switch (nKey)
	{
		case VK_RETURN:
			Setg_Violation(1);
			AddMsgTotal_Violation();
			AddExitESMsgTotal_Violation();
			switch (wzCarType)
			{
				case 1:
					SendMessageWzCar(wzCarType);
					break;
				case 2:
					SendMessageWzCar(wzCarType);
					break;
				case 3:
					SendMessageWzCar(wzCarType);
					break;
				case 4:
					SendMessageWzCar(wzCarType);
					break;
				case 5:
					SendMessageWzCar(wzCarType);
					break;
			}
			SendTcoWaingMsg("闯道车");
			SetWorkSationEndWz();
			break;
		case VK_CANCEL:
			SetG_weiZhangState(2);
			Set_WorkStation_40_InPutWzCarType();
			break;
		default:
			ErrorPressKey();
			break;
	}
}
void WorkStation_49_WeiZhang(int nKey)
{
	switch (nKey)
	{
		case VK_1:
			SetG_weiZhangState(2);
			Set_WorkStation_40_InPutWzCarType();
			break;
		case VK_2:
			SetG_weiZhangType(2);
			Set_WorkStation_59_WeiZhangHandl("倒车");
			break;
		case VK_3:
			SetG_weiZhangType(3);
			Set_WorkStation_59_WeiZhangHandl("误报警");
			break;
		default:
			ErrorPressKey();
			break;
	}
}
void WorkStation_59_WeiZhangHandl(int nKey)
{
	switch (nKey)
	{
		case VK_RETURN:
			SetWorkSationEndWz();
			if (GetG_weiZhangType()==2)
			{
				SendMsgInfo("违章消息","","倒车");
				SetG_weiZhangType(0);
			}
			else if (GetG_weiZhangType()==3)
			{
				SendMsgInfo("违章消息","","误报警");
				SetG_weiZhangType(0);
			}
			break;
		case VK_CANCEL:
			SetG_weiZhangState(0);
			UI_Show_Info("提示: 请选择线圈报警原因\n1. 闯道\n2. 倒车\n3. 误报警");
			Setg_CurrentLaneState(7);
			break;
		default:
			ErrorPressKey();
			UI_Show_Help_Info("按键无效，请按提示进行操作。");
			break;
	}
}
