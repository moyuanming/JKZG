#include "LocalIncludeFile.h"



void WorkStation_09_Handl_Urgent_Car_Team(int nKey)
{
	switch (nKey)
	{
	case VK_RETURN:
		SetRingVoide(T);
		Set_WorkStation_13_Urgent_Car_Team_Passing();
		break;
	case VK_CANCEL:
		Set_WorkStation_03_Main_Work("正常收费","等待来车");
		break;
	case VK_CLOSE_YPD:
		SetYuPeng(F);
		break;
	case VK_OPEN_YPD:
		SetYuPeng(T);
		break;
	default:
		ErrorPressKey();
		break;
	}
}

void WorkStation_13_Urgent_Car_Team_Passing(int nKey)
{
	switch (nKey)
	{

		case VK_URGENT:
			Set_WorkStation_16_Handl_Urgent_Car_Team_End();
			break;
		case S_PASSLINEUP:
			AddMsgtotal_emergency();
			AddExitESMsgTotal_Emergency();
			AfterOfTransDo(1,T);
			setLed();
			break;
		case VK_CLOSE_YPD:
			SetYuPeng(F);
			break;
		case VK_OPEN_YPD:
			SetYuPeng(T);
			break;
		default:
			ErrorPressKey();
			break;
	}
}

void WorkStation_16_Handl_Urgent_Car_Team_End(int nKey)
{
	switch (nKey)
	{
	case VK_RETURN:
		SetLanGan(F);
		SetJiaoTong(F);
		SendMsgEI(MSGEI_CARTEAM_END ,MSGEI_STATUS_MSGINFO,"紧急车已过");
		SendMsgEM('1');
		SendLaneInfo_default();
		SetG_weiZhangType(4);
		SendMsgInfo("紧急车队","","紧急过车");	 //qq
		Set_WorkStation_03_Main_Work("正常收费","等待来车");
		SetFrontCar(0);
		break;
	case VK_CANCEL:
		Set_WorkStation_13_Urgent_Car_Team_Passing();
		break;
	case VK_CLOSE_YPD:
		SetYuPeng(F);
		break;
	case VK_OPEN_YPD:
		SetYuPeng(T);
		break;
	default:
		ErrorPressKey();
		break;
	}
}


