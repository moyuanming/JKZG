#include "LocalIncludeFile.h"

void WorkStation_23_Abate(int nKey)
{
	int MaxLengh;
	int cardtype = 0;
	switch (nKey)
	{
	case VK_0:
	case VK_1:
	case VK_2:
	case VK_3:
	case VK_4:
	case VK_5:
	case VK_6:
	case VK_7:
	case VK_8:
	case VK_9:
		
		 GetG_AbateNumber()[strlen( GetG_AbateNumber())] = ChangCode(nKey);
		 UI_Show_Input_Text(GetG_AbateNumber());
		if (0==Getg_AbateType())
		{
			MaxLengh = atoi(sys_ini.AbateMaxLengh);
		}
		else
		{
			MaxLengh = atoi(sys_ini.MonthCardMaxLengh);
		}
		if (MaxLengh== strlen(GetG_AbateNumber()) )
		{
			Set_WorkStation_52_VKABATE_OK();
		}
		break;
	case VK_CANCEL:
		AddCancelCount();
		if (GetCancelCount() ==1)
		{
			Set_WorkStation_23_Abate("");
		}
		else
		{
			Set_WorkStation_03_Main_Work("正常收费","等待来车");
		}
		break;
	case VK_RETURN:
		if(ICCard_GetIsInit())
		{
			switch(ICCard_getCard())
			{
			case -1://读卡失败
				UI_Show_Help_Info("读卡失败");
				break;
			case -2://解密失败
				UI_Show_Help_Info("解卡失败");
				break;
			case 0://成功
				cardtype = ICCard_GetCard()->Usage/0x10;
				if(ICCard_ValidateArea()&&((cardtype==5&&Getg_AbateType()==0)||(cardtype==2&&Getg_AbateType()==1))&&ICCard_GetCard()->CType==atoi(GetG_Car_Type()))//优惠卡月票卡
				{
					SetG_IsIC(1);
					ICCard_GetBCD(GetG_AbateNumber(),ICCard_GetCard()->CardNo,4);
					Set_WorkStation_52_ICVKABATE_OK();
					SetG_IsIC(0);
				}
				else if(!ICCard_ValidateArea())
				{
					UI_Show_Help_Info("非该站使用");
				}
				else if(ICCard_GetCard()->CType!=atoi(GetG_Car_Type()))
				{
					UI_Show_Help_Info("车型不符");
				}
				else
				{
					UI_Show_Help_Info("读卡失败");
				}
				break;
			default:
				UI_Show_Help_Info("读卡失败");
				break;
			}
			break;
		}
	default:
		ErrorPressKey();
		break;
	}
}

void WorkStation_204_FreeCar(int nKey)
{
	int MaxLengh;
	char temp[500];
	static int is_return =F;
	switch (nKey)
	{
	case VK_0:
	case VK_1:
	case VK_2:
	case VK_3:
	case VK_4:
	case VK_5:
	case VK_6:
	case VK_7:
	case VK_8:
	case VK_9:
		if(strlen( GetG_AbateNumber())<3)
		{
			GetG_AbateNumber()[strlen( GetG_AbateNumber())] = ChangCode(nKey);
			UI_Show_Input_Text(GetG_AbateNumber());
		}
		else if(is_return==F)
		{
			UI_Show_Help_Info("请按【确认】键确认车牌号码！");
		}
		else
		{
			ErrorPressKey();
		}
		break;
	case VK_RETURN:
		
		if(strlen( GetG_AbateNumber())<=3&&is_return==F)
		{
			sprintf(temp,"提示：\n请核对信息：\n%s\n按【确认】键返回。\n按【公务】键直接放行\n按【取消】键取消。",GetCarInfo(GetG_AbateNumber()));
			UI_Show_Info(temp);
			is_return=T;
		}
		else if(is_return==T)
		{
			AddCancelCount();
			InitG_AbateNumber();
			Set_WorkStation_03_Main_Work("正常收费","等待来车");
			is_return=F;
		}
		else
		{
			UI_Show_Help_Info("请输入后三位车牌号再按【确认】键！");
		}
		break;
	case VK_GONGWU:
		if(strlen( GetG_AbateNumber())<=3&&is_return==T)
		{
			if(GetCarInfoStaue()==T)
			{
				UI_SetCarType( VK_1);
				HandOnceOK(nKey,4);
				InitG_AbateNumber();
				is_return=F;
			}
			else
			{
				UI_Show_Help_Info("未查到车！请按【确认】键返回。或按【取消】键取消。");
			}
		}
		else
		{
			ErrorPressKey();
		}
		
		break;
	case VK_CANCEL:
		if(strlen( GetG_AbateNumber())>0)
		{
			Set_WorkStation_204_FreeCar();
		}
		else
		{
			AddCancelCount();
			InitG_AbateNumber();
			Set_WorkStation_03_Main_Work("正常收费","等待来车");
		}
		is_return=F;
		break;
	default:
		ErrorPressKey();
		break;
	}
}
void WorkStation_47_FavourCardOK(int nKey)
{
	switch (nKey)
	{
	case VK_RETURN:	//过车模拟
		WorkStation_07_FUN_General_Second_OK_7(1);			
		break;
	case VK_CANCEL:
		if (1==atoi(sys_ini.OnceOkEnabledCancel))
		{
			Set_WorkStation_03_Main_Work("正常收费","等待来车");
		}
		else
		{
			ErrorPressKey();
		}
		break;
	case VK_CLOSE_YPD:
		SetYuPeng(F);
		break;
	case VK_OPEN_YPD:
		SetYuPeng(T);
		break;
	case VK_MONI:		
		if (0==GetG_IsTuoche())
		{
			SendLaneInfo("正在模拟");
			Set_WorkStation_45_SimulateOnceOk();
		}
		else
		{
			SendLaneInfo("正在模拟");
			Set_WorkStation_53_SimulateOnceOkTuoche();
		}	
		break;
	default:
		ErrorPressKey();
		break;
	}
}
void WorkStation_52_Abate_OK(int nKey)
{
	int ret;
	char tempNetNo[3];
	char tempPlazaNo[3];
	memset(tempNetNo,0x00,sizeof(tempNetNo));
	memset(tempPlazaNo,0x00,sizeof(tempPlazaNo));
	switch (nKey)
	{
	case VK_RETURN:
		ret = Validate_Abate_Number(GetG_AbateNumber());
		if (-1==ret)
		{
			char tempInfo[250];
			HandOnceOK(VK_RETURN,4);
			sprintf(tempInfo,"提示：\n卡号输入错误，按收费车处理。\n按【确认】键抬杆，"
				"\n按【欠款】键处理欠款，\n按【模拟】键处理拖车模拟、更改车型、车种。");
			UI_Show_Info(tempInfo);
		}
		else
		{
			char temp[20];
			char tempInfo[250];
			time_t Currenttime = time(NULL);
			memset(temp,'\0',20);
			memset(tempInfo,'\0',250);
			strcpy(temp,GetG_AbateNumber());
			strncpy(tempNetNo,GetLanConfigNetNo(),2);
			strncpy(tempPlazaNo,GetLanConfigPlazaNo(),2);
			if (0==Getg_AbateType())
			{
				if (GetG_IsIC()?ICCard_ValidateCardEndDate(Currenttime):ValidateYHCarEndDate(GetG_AbateNumber(),Currenttime))
				{
					UI_ClearAbateChargeEditC();
					HandOnceOK(VK_RETURN,4);
					sprintf(tempInfo,"提示：\n该卡号已到期，按收费车处理。\n按【确认】键抬杆，"
						"\n按【欠款】键处理欠款，\n按【模拟】键处理拖车模拟、更改车型、车种。");
					UI_Show_Info(tempInfo);
				}
				else if (GetG_IsIC()?ICCard_ValidateCardStartDate(Currenttime):ValidateYHCarStartDate(GetG_AbateNumber(),Currenttime))
				{
					UI_ClearAbateChargeEditC();
					HandOnceOK(VK_RETURN,4);
					sprintf(tempInfo,"提示：\n该卡号未启用，按收费车处理。生效日期：%s。\n按【确认】键抬杆，"
						"\n按【欠款】键处理欠款，\n按【模拟】键处理拖车模拟、更改车型、车种。",
						GetG_IsIC()?ICCard_GetBDate():GetYHCarStartDate(GetG_AbateNumber()));
					UI_Show_Info(tempInfo);
				}
				else
				{
					Set_WorkStation_47_FavourCardOK("正常收费","请核实并确认",
						GetG_IsIC()?ICCard_GetBDate():GetYHCarStartDate(GetG_AbateNumber()),
						GetG_IsIC()?ICCard_GetEDate():GetYHCarEndDate(GetG_AbateNumber()));
				}
			}
			else
			{
				if (GetG_IsIC()?ICCard_ValidateCardEndDate(Currenttime):ValidateYPKCarEndDate(GetG_AbateNumber(),Currenttime))
				{

					UI_ClearAbateChargeEditC();
					HandOnceOK(VK_RETURN,4);
					sprintf(tempInfo,"提示：\n该卡号已到期，按收费车处理。失效日期：%s。\n按【确认】键抬杆"
						"\n按【欠款】键处理欠款\n按【模拟】键处理拖车模拟、更改车型、车种。",
						GetG_IsIC()?ICCard_GetEDate():GetYPKCarEndDate(GetG_AbateNumber()));
					UI_Show_Info(tempInfo);
				}
				else if (GetG_IsIC()?ICCard_ValidateCardStartDate(Currenttime):ValidateYPKCarStartDate(GetG_AbateNumber(),Currenttime))
				{
					UI_ClearAbateChargeEditC();
					HandOnceOK(VK_RETURN,4);
					sprintf(tempInfo,"提示：\n该卡号未启用，按收费车处理。\n按【确认】键抬杆"
						"\n按【欠款】键处理欠款\n按【模拟】键处理拖车模拟、更改车型、车种。");
					UI_Show_Info(tempInfo);
				}
				else
				{
					Set_WorkStation_47_FavourCardOK("正常收费","请核实并确认",
						GetG_IsIC()?ICCard_GetBDate():GetYPKCarStartTime(GetG_AbateNumber()),
						GetG_IsIC()?ICCard_GetEDate():GetYPKCarEndDate(GetG_AbateNumber()));
				}
			}

		}
		break;
	case VK_CANCEL:
		AddCancelCount();
		if (GetCancelCount() ==1)
		{
			Set_WorkStation_23_Abate("请输入卡号");
		}
		else
		{
			Set_WorkStation_03_Main_Work("正常收费","等待来车");
		}
		break;
	default:
		ErrorPressKey();
		break;
	}
}

