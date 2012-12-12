#include "LocalIncludeFile.h"
#include "mac.h"
#include "imf.h"
#include "3des.h"

/*----------------------------------------------------------------------
函数名称：      void WorkStation_0_Wait_Begin_Work(int nKey)
作用：          开启车道等待上班，下班后等上班。
参数：          int nKey 键盘键值
返回值：        无
后继：          WorkStation (1)
创建日期：      2005.10
创建人:         莫远明
最后修改日期:   2008.05
最后修改人:     王海伟
----------------------------------------------------------------------*/

void WorkStation_03_Main_Work(int nKey)
{
	switch (nKey)
	{
		case VK_1:
		case VK_2:
		case VK_3:
		case VK_4:
		case VK_5:
			SendLaneInfo("处理车型");
			UI_SetCarType(nKey);
			Set_WorkStation_04_General_Validate_Car_Type_And_First_OK(); 
			break;
		case VK_CLOSE_YPD:
			if (Getg_bYuPeng())
			{
				UI_Show_Info("提示：\n可以继续处理过车\n或按【下班】键下班\n或按【雨棚灯】键打开雨棚灯。");
				SetYuPeng(F);
			}
			else{
				//UI_Show_Info("YPD closed");
			}
			break;
		case VK_OPEN_YPD:
			if (!Getg_bYuPeng())
			{
				UI_Show_Info("提示：\n按【数字】键输入车型，\n按【车队】键处理车队。");
			}
			SetYuPeng(T);
			break;
		case VK_URGENT:
			Set_WorkStation_09_Handl_Urgent_Car_Team();
			break;
		case VK_CLOSE:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("请等车辆通过后关闭车道!");
			}
			else
			{
				Set_WorkStation_06_Closed_Road();
				SendMsgGR(MSGGR_CANOPY_OFF);
				SendLaneInfo_default();;
			}
			break;
		case VK_XIABAN:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("请等车辆通过后下班!");
			}
			else if (Getg_bYuPeng())
			{
				UI_Show_Help_Info("请先关闭雨棚灯再按【下班】键！");
			}
			else
			{
				SendLaneInfo("正在下班");
				Set_WorkStation_20_EndWorkOk();
			}
			break;
		case VK_MONI:
			if (1==atoi(sys_ini.SimulateEnabledFistTuoChe) && (1==GetG_IsTuoche()))
			{
				SetG_simulateWorkState(10);
				Set_WorkStation_45_SimulateOnceOk();
			}
			else
			{
				ErrorPressKey();
			}
			break;
		case VK_CHAHAO:
			Set_WorkStation_204_FreeCar();
			break;
		case S_PASSLINEUP:
			break;
		default:
			ErrorPressKey();
			break;
	}
}
void WorkStation_03_Main_Work3(int nKey)
{
	switch (nKey)
	{
		case VK_1:
		case VK_2:
		case VK_3:
		case VK_4:
		case VK_5:
			SendLaneInfo("处理车型");
			UI_SetCarType(nKey);
			Set_WorkStation_04_General_Validate_Car_Type_And_First_OK();
		 
			break;
		case VK_CLOSE_YPD:
			if (Getg_bYuPeng())
			{
				UI_Show_Info("提示：\n继续处理过车，\n按【下班】键下班，\n按【雨棚灯】键打开雨棚灯。");
			}
			SetYuPeng(F);
			break;
		case VK_OPEN_YPD:
			if (!Getg_bYuPeng())
			{
				UI_Show_Info("提示：\n按【数字】键输入车型，\n按【紧急】键处理紧急车队。");
			}
			SetYuPeng(T);
			break;
		case VK_CLOSE:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("请等车辆通过后关闭车道!");
			}
			else
			{
				Set_WorkStation_06_Closed_Road();
				SendMsgGR(MSGGR_CANOPY_OFF);
				SendLaneInfo_default();
			}
			break;
		case VK_URGENT:
			Set_WorkStation_09_Handl_Urgent_Car_Team();
			break;
		case VK_XIABAN:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("请等车辆通过后下班!");
			}
			else if (Getg_bYuPeng())
			{
				UI_Show_Help_Info("请先关闭雨棚灯再按【下班】键！");
			}
			else
			{
				Set_WorkStation_20_EndWorkOk();
			}
			break;
		case S_PASSLINEUP://模拟后连续压线圈两次报警
			if (1==YaxianquanNum)
			{
				SetRing(T);
				Set_WorkStation_49_WeiZhang();
			}
			else
			{
				SetJiaoTong(F);
			}
			break;
		default:
			ErrorPressKey();
			break;
	}
}
void WorkStation_03_Main_Work2(int nKey)
{
	switch (nKey)
	{
		case VK_1:
		case VK_2:
		case VK_3:
		case VK_4:
		case VK_5:
			if (Getg_bYuPeng()||1==GetYuPengState())
			{
				SetYuPengState(0);
				SendLaneInfo("处理车型");
				UI_SetCarType(nKey);
				Set_WorkStation_04_General_Validate_Car_Type_And_First_OK();
 
			}
			else
			{
				UI_Show_Help_Info("请首先打开雨棚灯再进行收费。");
			}
			break;
		case VK_CLOSE_YPD:
			if (Getg_bYuPeng())
			{
				UI_Show_Info("提示：\n继续处理过车，\n按【下班】键下班，\n按【雨棚灯】键打开雨棚灯。");
			}
			SetYuPeng(F);
			break;
		case VK_OPEN_YPD:
			if (!Getg_bYuPeng())
			{
				UI_Show_Info("提示：\n按【数字】键输入车型，\n按【车队】键处理车队。");
			}
			SetYuPengState(1);
			SetYuPeng(T);
			break;
		case VK_URGENT:
			Set_WorkStation_09_Handl_Urgent_Car_Team();
			break;
		case VK_CLOSE:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("请等车辆通过后关闭车道!");
			}
			else
			{
				Set_WorkStation_06_Closed_Road();
				SendMsgGR(MSGGR_CANOPY_OFF);
				SendLaneInfo_default();
			}
			break;
		case VK_XIABAN:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("请等车辆通过后下班!");
			}
			else if (Getg_bYuPeng())
			{
				UI_Show_Help_Info("请先关闭雨棚灯再按【下班】键！");
			}
			else
			{
				Set_WorkStation_20_EndWorkOk();
			}
			break;
		case VK_MONI:
			if (1==atoi(sys_ini.SimulateEnabledFistTuoChe) && 1==GetG_IsTuoche())
			{
				SetG_simulateWorkState(10);
				Set_WorkStation_45_SimulateOnceOk();
			}
			else
			{
				ErrorPressKey();
			}
			break;
		case VK_CHAHAO:
			Set_WorkStation_204_FreeCar();
			break;
		case S_PASSLINEUP:
			break;
		default:
			ErrorPressKey();
			break;
	}
}
/*----------------------------------------------------------------------
函数名称：      void WorkStation_4_General_Validate_Car_Type_And_First_OK(int nKey)
作用：          正常收费安下数字键后跳转到这个状态验证车型。
参数：          int nKey 键盘键值
返回值：        无
后继：          WorkStation (3，7，10)
创建日期：      2005.10
创建人:         莫远明
最后修改日期:   2008.07
最后修改人:     王海伟
----------------------------------------------------------------------*/
void WorkStation_04_General_Validate_Car_Type_And_First_OK(int nKey)
{
	switch (nKey)
	{
		case VK_1:
		case VK_2:
		case VK_3:
		case VK_4:
		case VK_5:
			UI_SetCarType( nKey);
			break;
		case VK_BEIYONG:
		case VK_LONGYONG:
		case VK_GONGWU:
		case VK_JUNCHE:
		case VK_LVSETONGDAO:
		case VK_RETURN:
			HandOnceOK(nKey,4);
#ifdef PCMACHINE
			CaptureImg(IMG_FIRST);
#endif
			break;
		case VK_YOUHUICARD:
			Set_WorkStation_23_Abate("优惠卡号");
			break;
		case VK_MOUNTHCARD:
			Set_WorkStation_23_Abate("月票卡号");
			break;
		case VK_CANCEL:
			if (Getg_tuocheNum()!=0)
			{
				Set_WorkStation_03_Main_Work3("正常收费","拖车模拟");
			}
			else
			{
				Set_WorkStation_03_Main_Work("正常收费","等待来车");
			}
			break;
		case VK_CLOSE_YPD:
			SetYuPeng(F);
			break;
		case VK_OPEN_YPD:
			SetYuPeng(T);
			break;
		default:
			{
				int  carKindIndex  ;
				carKindIndex = Validate_Car_Kind(nKey);
				if (carKindIndex!=0)
				{
					HandOnceOK( nKey,4);
				}
				else
				{
					ErrorPressKey();
				}
			}

			break;
	}
}

/*----------------------------------------------------------------------
函数名称：      void WorkStation_6_Closed_Road(int nKey)
作用：          临时封闭车道，按开启键开启。
参数：          int nKey 键盘键值
返回值：        无
后继：          WorkStation (2)
创建日期：      2005.10
创建人:         莫远明
最后修改日期:   2005.10
最后修改人:     莫远明
----------------------------------------------------------------------*/
void WorkStation_06_Closed_Road(int nKey)
{
	if (nKey == VK_OPEN)
	{
		Set_WorkStation_02_Handl_Input_Password();
	}
	else
	{
		ErrorPressKey();
	}

}
/*----------------------------------------------------------------------
函数名称：      void WorkStation_7_General_Second_OK(int nKey)
作用：          正常收费第一次确认后跳转状态，进行第二次确认或取消收费。
参数：          int nKey 键盘键值
返回值：        无
后继：          WorkStation (3，10)
创建日期：      2005.10
创建人:         莫远明
最后修改日期:   2005.10 ,2006-12-15
最后修改人:     莫远明
----------------------------------------------------------------------*/
int WorkStation_07_FUN_General_Second_OK_7(int Flag )
{
	int ret = 1;	
	if (1==GetG_BillPrintFlag())
	{
		if (postPrinter(T))
		{
			CaptureImg(IMG_SECOND);
			SetG_simulateEnabled(T);
			SetG_reprintbillnum(0);
			if (Flag)
			{
				Set_WorkStation_10_Up_Parapet_Pass();
			}
			else
			{
				SetPassCar();
			}
		}
		else
		{
			setLed();
			SendMsgEI(MSGEI_PRINTER_ERROR ,MSGEI_STATUS_MSGINFO,"打印机故障");	//lzp// 打印机故障   MSGEI 事件处理
			UI_Show_Help_Info("打印机故障！");
			ret = 0;
		}
	}
	else
	{
		CaptureImg(IMG_SECOND);
		SetG_simulateEnabled(T);
		SetG_reprintbillnum(0);
		if (Flag)
		{
			Set_WorkStation_10_Up_Parapet_Pass();
		}
		else
		{
			SetPassCar();
		}
	}
	return ret;
}
/**
 * 等待二次确认，确认为现金支付
 * 
 * @param nKey
 */
void WorkStation_07_General_Second_OK(int nKey)
{
	switch (nKey)
	{
		case   CSC_CARDENTER:
			{
				int ret;
				ret=UseCardToPay();
				switch (ret )
				{
					case PAYRET_OK://  0  //返回正常
						//说明一切正常
						break;
					case  PAYRET_READCARDERROR://  1//读卡失败
						UI_Show_Help_Info("抱歉！读卡失败，请重试!");
						break;
					case  PAYRET_READCARDKEYOLD://  1//读卡失败
						UI_Show_Help_Info("抱歉！卡密钥已过期!");
						break;
					case  PAYRET_READCARDKEYNOTFOND://  1//读卡失败
						UI_Show_Help_Info("抱歉！未找到卡信息!");
						break;
					case  PAYRET_CARDTYPEINVALID:// 2//卡类型无效。
						UI_Show_Help_Info("抱歉！此卡不是有效的可支付卡!");
						break;
					case PAYRET_CARTYPEERROR:
						UI_Show_Help_Info("抱歉，车型不符!");
						break;
					case PAYRET_PRINTERERROR:
						UI_Show_Help_Info("打印机故障，请修复打印机后再刷卡!");
						break;
					default:
						UI_Show_Help_Info("抱歉！无效卡");//未处理的返回值
						break;
				}
				echoic("这里刷卡%s",       GetCardNOByString());
			}
			break;
		case  CSC_CARDEXIT:
			echoic("卡已经被拿走了  卡号是 %s",     GetCardNOByString());
			break;
		case VK_RETURN:
			if (0==GetG_IsTuoche())
			{				
				if (0==Getg_bLanGan())
				{
					//暂时去掉落干才能确认的判断，针对乌拉泊平凡出现不落干，会出现前一辆车落干
					WorkStation_07_FUN_General_Second_OK_7(1);
				}
				else
				{
					UI_Show_Help_Info("按键无效，请按提示进行操作。");
				}
			}
			else
			{
				WorkStation_07_FUN_General_Second_OK_7(1);
			}
			CaptureImg('0');
			break;
		case VK_DOWN:
			LogCAppLogDebug("强制落干");
			SetLanGan(F);
			break;
		case VK_QIANKUAN:
			Set_WorkStation_42_HandArrearageNumber(7);
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
			SendLaneInfo("正在模拟");
			if (0==GetG_IsTuoche())
			{					
				Set_WorkStation_45_SimulateOnceOk();
			}
			else
			{					
				Set_WorkStation_53_SimulateOnceOkTuoche();
			}			
			break;

		default:
			ErrorPressKey();
			break;
	}
}

/*----------------------------------------------------------------------
函数名称：      void WorkStation_10_Up_Parapet_Pass(int nKey)
作用：          正常收费二次确认抬杆放行时工作状态。
参数：          int nKey 键盘键值
返回值：        无
后继：          WorkStation (3，21)
创建日期：      2005.10
创建人:         莫远明
最后修改日期:   2005.10
最后修改人:     莫远明
----------------------------------------------------------------------*/
void WorkStation_10_Up_Parapet_Pass(int nKey)
{
	switch (nKey)
	{
		case S_PASSLINEUP:
			if (0!=GetG_IsTuoche())
			{
				AddYCQK("被拖车");
				SetJiaoTong(F);
				SetG_IsTuoche(0);//硬托             SetG_IsTuoche(GetG_IsTuoche()-1)//软拖
			}
			AfterOfTransDo(1,F);
			SetJiaoTong(F);
			SendMsgInfo("过车消息","","普通过车");	   //qq
			InitCarTypeKindCharge();
			SendLaneInfo_default();
			SendLaneInfo("等待来车");
			LedClare(T);
			Set_WorkStation_03_Main_Work("正常收费","等待来车");
			break;
		case VK_CLOSE_YPD:
			SetYuPeng(F);
			break;
		case VK_OPEN_YPD:
			SetYuPeng(T);
			break;
		case VK_MONI:			
			SetG_simulateWorkState(10);
			SendLaneInfo("正在模拟");
			Set_WorkStation_46_SimulateTwoOk();			
			break;
		default:
			ErrorPressKey();
			break;
	}
}







void WorkStation_28_CarNumber_Second_OK(int nKey)
{

	switch (nKey)
	{
		
		case VK_RETURN:
			SetG_simulateEnabled( T);
			SetG_reprintbillnum(0);
			Set_WorkStation_10_Up_Parapet_Pass();
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


/*-------------------------------------------------------------------------------------------------------------------
函数名称：     WorkStation_50_DataExporter(int nKey)
作用：           用usb设备导出车道数据
参数：          int nKey 键盘键值
返回值：        无
后继：          WorkStation (20)
创建日期：      2008.6
最后修改日期:   2008.6
--------------------------------------------------------------------------------------------------------------------*/
int  itWorking=0;
void WorkStation_50_DataExporter(int nKey)
{
	switch (nKey)
	{
		case VK_CANCEL:
			if (0==itWorking)
			{
				Set_WorkStation_30_SelectWorkMod();
			}
			else
			{
				UI_Show_Help_Info("正在导出数据，请稍候....");
			}
			break;
		case VK_RETURN:
			itWorking=1;
			DataExporter();
			itWorking=0;
			break;
		default:
			ErrorPressKey();
			break;
	}
}


