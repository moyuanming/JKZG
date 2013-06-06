#include "LocalIncludeFile.h"

void InLineUP()
{
    Setg_bZhuaPaiXianQuan(T);
    CaptureImg(IMG_FIRST);
}

void InLineDown()
{
    Setg_bZhuaPaiXianQuan(F);
}
void PassLineUP(void)
{
	
    Setg_bTongGuoXianQuan(TRUE);
	
    if((0==GetG_IsTuoche())&&(FALSE==Getg_bJiaoTong() ||FALSE==Getg_bLanGan()))
    {
		if(GetFunDoubleLane() && GetFrontCar() >0 )
		{
			return;
		}
        SetRingVoide(T);
        Set_WorkStation_49_WeiZhang();
        SetRing(T);
    }
    else
    {
		/*if(0!=GetG_IsTuoche())
		{
			return;
		}*/
        WorkStation(S_PASSLINEUP);
    }
}

void PassLineDown(void)
{
	Setg_bTongGuoXianQuan(F);
	//echoic("复合式收费：GetFrontCar() = <%d>",GetFrontCar());
	
	if(GetFunDoubleLane()  )
	{	MinusPasdCar();	
		if(GetFrontCar()>0)
		{			
			return;
		}
		
	}	
	
	if (10==GetWorkState()||46==GetWorkState())
	{
		PassLineUP();
	}
	if(0!=GetG_IsTuoche())//如果不等于0，说明拖车没有处理完。 直接返回。
    {
		//SetG_IsTuoche(0);
        return;
    }
    if(GetWorkState()==3||GetWorkState()==4|| GetWorkState()==7||51==GetWorkState()||10==GetWorkState()||46==GetWorkState())
    {
			++YaxianquanNum;
			YaxianquanNum=0;
            SetLanGan(F);
			SetJiaoTong(F);
            SendLaneInfo_default();
			if(46==GetWorkState())
			{
				Set_WorkStation_03_Main_Work("正常收费","等待来车");
				InitCarTypeKindCharge();
				SetG_Current_Handl_Charge(0.0);
			}
    }
    else if(GetWorkState()==8)
    {
        if(GetG_Car_Passed_Count() >=GetG_Car_Pass_Count())
        {
			SetLanGan(F);	
            SendLaneInfo_default();
        }
    }
    else
    {
        if(GetG_Urgent_Car_Team_Enabled())
        {
            char temp[100];
            AddG_Car_Pass_Count();
            memset(temp,'\0',100);
            sprintf(temp,"提示：\n车队已通过%d辆车，\n按【紧急键】键结束紧急车队。",GetG_Car_Pass_Count());
            UI_Show_Info(temp);
        }
    }
}

void SetYuPeng(BOOL  bFlag)
{
    if(Getg_bYuPeng() != bFlag)
    {
        Setg_bYuPeng(bFlag);

        if(bFlag)
        {
            G_CurrentSystemDevStatus.YuPeng  = 1;
            SendMsgGR(MSGGR_CANOPY_ON);
			//SetG_BillPrintFlag(4);
			SetG_weiZhangType(4);
            SendMsgInfo("顶棚灯消息","","雨棚灯打开");
            SendLaneInfo_default();
            Setg_bYuPengOpened(T);
        }
        else
        {
            G_CurrentSystemDevStatus.YuPeng  = 0;
            SendMsgGR(MSGGR_CANOPY_OFF);
            //SetG_BillPrintFlag(4);
            SetG_weiZhangType(4);
            SendMsgInfo("顶棚灯消息","","雨棚灯关闭");
            SendLaneInfo_default();
        }
		I_DEV_IOBoard_CommandSender(bFlag,T_LAMP_G,T_LAMP_R);
        
    }
}
void SetPassCar()
{
	//echoic("复合式收费：GetFunDoubleLane() =<%d><%d>",GetFunDoubleLane(),GetFunControlLane());
	if(GetFunDoubleLane())
	{	
		if(GetFunControlLane() == FALSE)
		{	
			SendUdpToControlPadCard();
		}
		AddPasdCar();
	}
	if(1!=GetG_IsTuoche())
	{
		//LogCAppLogDebug("Open Jiao Tong Open LanGan");
		I_DEV_IOBoard_CommandSender(T,C_LAMP_G|RL_1,C_LAMP_R);
		Setg_bJiaoTong(T);
		Setg_bLanGan(T);
		G_CurrentSystemDevStatus.LanGan = 1;
		G_CurrentSystemDevStatus.JIaoTong = 1;;
		SendLaneInfo("正在过车");
	}
    else
    {
        SetG_IsTuoche(GetG_IsTuoche()+1);
    }
}
void SetJiaoTong(BOOL bFlag)
{
	
    if(Getg_bJiaoTong() != bFlag)
    {
        Setg_bJiaoTong(bFlag);
		G_CurrentSystemDevStatus.JIaoTong = (bFlag?1:0);
		if(0==strcmp("SG",GetTFIDLL()))
		{
			echo("Setg_bJiaoTong <%d>",bFlag);
			//TFI_SG_SetTongXingDeng(bFlag);
		}
		else
		{
			I_DEV_IOBoard_CommandSender(bFlag,C_LAMP_G,C_LAMP_R);
		}
		
        
    }
}
void SetLanGan(BOOL bFlag)
{
	Setg_bLanGan(bFlag);
	G_CurrentSystemDevStatus.LanGan = (bFlag?1:0);
	I_DEV_IOBoard_CommandSender(bFlag,RL_1,0);
    
}
//#define  MONEYBOX
BOOL COM_RINGVOIDE = F;
void SetRingVoide(BOOL  bFla)
{
	//echoic("打开视频报警\n");
#ifdef MONEYBOX
	return;
#endif
	if (COM_RINGVOIDE!=bFla)
	{
		COM_RINGVOIDE =bFla;
		I_DEV_IOBoard_CommandSender(bFla,RL_2,0);
	}
}

void  SetMoney(BOOL bFlag)
{
	if (COM_RINGVOIDE!=bFlag)
	{
		COM_RINGVOIDE =bFlag;
		//I_DEV_IOBoard_CommandSender(bFlag,RL_2,0);
	}
}
int MoneyTimer = 0;
int GetMoneyTimer()
{
	if(MoneyTimer<=3)
	{
		MoneyTimer++;
	}
	return MoneyTimer;
}
void OpenMoneyBox(void)
{
#ifdef MONEYBOX
	echoic("打开钱箱\n");
	MoneyTimer = 0;
	I_DEV_IOBoard_CommandSender(F,RL_2,0);
#endif
}
void CloseMoneyBox(void)
{
#ifdef MONEYBOX
	echoic("关闭钱箱\n");
	I_DEV_IOBoard_CommandSender(T,RL_2,0);
#endif
}
void SetRing(BOOL bFlag)
{
    if(Getg_Ring() !=bFlag )
    {
        Setg_Ring(bFlag);
		G_CurrentSystemDevStatus.Ring =(bFlag?1:0);
		if(0==strcmp("SG",GetTFIDLL()))
		{
			echo("SetRing <%d>",bFlag);
			TFI_SG_SetHuangShan(bFlag);
		}
		else
		{
			I_DEV_IOBoard_CommandSender(bFlag,ALARM_LAMP,0);
		}
		

    }
}
void SetCloseDev()
{
    I_DEV_IOBoard_CommandSender(T,T_LAMP_R|C_LAMP_R|RL_2,T_LAMP_G|C_LAMP_G|RL_1|FOG_LAMP |ALARM_LAMP);
    I_DEV_IOBoard_CommandSender(F,RL_2,0);

    sleep(1);
}
int  getJiaoTongDengState(void)
{
    int ret;
    if(Getg_bJiaoTong())
    {
        ret = 1;
    }
    else
    {
        ret = 0;
    }

    return ret;
}

char  *GetJiaoTongDengState_Str(void)
{
    if(1==getJiaoTongDengState())
    {
        return "1";
    }
    else
    {
        return "0";
    }
}

int  getGetPrintState(void)
{
    return 1;// autio(g_printfState);
}

int getLanGanState(void)
{
    int ret;
    if(Getg_bLanGan())
    {
        ret = 1;
    }
    else
    {
        ret = 0;
    }

    return ret;
}

char  *GetLanGanState_Str(void)
{
    if(1==getLanGanState())
    {
        return "1";
    }
    else
    {
        return "0";
    }
}

int getTongGuoXianQuan(void)
{
    int ret;
    if(Getg_bTongGuoXianQuan())
    {
        ret = 1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}
int  getZhuaPaiXianQuan()
{
    int ret;
    if(Getg_bZhuaPaiXianQuan())
    {
        ret = 1;
    }
    else
    {
        ret = 0;
    }

    return ret;
}

