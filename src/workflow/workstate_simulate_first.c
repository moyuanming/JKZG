#include "LocalIncludeFile.h"

void WorkStation_45_SimulateOnceOk_MoNITuoche(void)
{
	Addg_tuocheNum();
	SetG_IsTuoche(1);
	if (WorkStation_07_FUN_General_Second_OK_7(0))
	{
		AddExitESMsgCounter4();
		SendLaneInfo("拖车模拟");
		SendMsgInfo("模拟消息","","处理拖车");
		AddYCQK("拖车");
		SetExitTRMsgDisputeType('4');
		TransDoTuoche();
		SendMsgInfo("过车消息","","普通过车");
		InitMsgExitTR();
		SendLaneInfo_default();
		Set_WorkStation_03_Main_Work3("正常收费","模拟拖车");
		InitCarTypeKindCharge(); 
	}
}
void WorkStation_45_SimulateOnceOk(int nKey)
{
	switch (nKey)
	{
		case VK_1:
			Setg_DisputeType(1);
			AddExitESMsgCounter2();
			SendLaneInfo("更改车型");
			SendMsgInfo("模拟消息","","更改车型");
			AddYCQK("更改车型");
			InitCarTypeKindCharge();
			SendLaneInfo_default();
			SetExitTRMsgDisputeType('2');
			AfterOfTransDo(0,F);
			Set_WorkStation_03_Main_Work("正常收费","等待来车");
			break;
		case VK_2:
			Setg_DisputeType(1);
			AddExitESMsgCounter3();
			SendLaneInfo("更改车种");
			SendMsgInfo("模拟消息","","更改车种");
			AddYCQK("更改车种");
			InitCarTypeKindCharge();
			SendLaneInfo_default();
			SetExitTRMsgDisputeType('3');
			AfterOfTransDo(0,F);
			Set_WorkStation_03_Main_Work("正常收费","等待来车");
			break;
		case VK_3:
			WorkStation_45_SimulateOnceOk_MoNITuoche();
			break;
		case VK_CANCEL:
			//是否可以取消模拟状态
			if (1==atoi(sys_ini.SimulateEnabledCancel))
			{
				Set_WorkStation_07_General_Second_OK(GetG_SaveBeforTipOne(),GetG_SaveBeforTipTwo());
			}
			else
			{
				ErrorPressKey();
			}
			break;
	default:
		ErrorPressKey();
		break;
	}
}
void WorkStation_53_SimulateOnceOkTuoche(int nKey)
{
	switch (nKey)
	{
		case VK_3:
			ErrorPressKey();			
		default:
			WorkStation_45_SimulateOnceOk(nKey);
			break;
	}
}

