
#include "LocalIncludeFile.h"

int ChangCode(int nKey)
{	
    if (nKey == 11)
    {	
        nKey = 48;
    }
    else
    {	
        nKey = nKey + 47;
    }
    return nKey;
}


int Validate_Abate_Number(char *abateNumber)
{	
    int ret = -1;
    int  carTypeIndex,carKindIndex;
    float spcCharge;
	volatile int YHL = 0;
	volatile int adjustmod = 0;
	volatile int carrymod = 0;
    carTypeIndex = -1;
    carKindIndex = -1;
	
	
	if(0==Getg_AbateType())
	{	
		if(1==CheckYHKCardNumber(abateNumber))
		{	
			carKindIndex=GetCarKindIndex(VK_YOUHUICARD);
			carTypeIndex=Validate_Car_Type_lane();	
			if(GetG_IsIC()==1)
			{
				Validate_Car_Kind(0==Getg_AbateType()?VK_YOUHUICARD:VK_MOUNTHCARD);
				echoic("%02X %02X%02X %02X",ICCard_GetCard()->Percent,
				ICCard_GetCard()->FeeMode[0],
				ICCard_GetCard()->FeeMode[1],
				ICCard_GetCard()->Carry
				);
				YHL = (unsigned int)ICCard_GetCard()->Percent;
				adjustmod = (int)((int)(ICCard_GetCard()->FeeMode[0])|(int)(ICCard_GetCard()->FeeMode[1])<<8);
				carrymod = ICCard_GetCard()->Carry;
				echoic("YHL = %d adjustmod = %d carrymod = %d",YHL,adjustmod,carrymod);
				spcCharge = (float)GetFactMoney(GetFareValue(Validate_Car_Type_lane()),YHL,adjustmod,carrymod);	
			}
			else
			{
				spcCharge = (float)GetFactMoney(GetFareValue(Validate_Car_Type_lane()),GetYHRate(GetYHCode(abateNumber)),GetAdjustMode(GetYHCode(abateNumber)),GetCarryMode(GetYHCode(abateNumber)));	
			}
			Setg_DiscountRate((float)GetFareValue(Validate_Car_Type_lane()),spcCharge);	
			ShowInformatiom(carTypeIndex,carKindIndex,spcCharge);	
			ret=1;
		}
	}
	else
	{	
		//检测月票卡信息
		if(1==CheckCardNumber(abateNumber))
		{	
			carKindIndex=GetCarKindIndex(VK_MOUNTHCARD);;
			carTypeIndex=Validate_Car_Type_lane();	
			spcCharge = 0;
			ShowInformatiom(carTypeIndex,carKindIndex,spcCharge);	
			ret=1;
		}
	}
	
	return  ret ;
}
/*----------------------------------------------------------------------
函数名称：      int Validate_Abate_CarNumber()
作用：          对优惠车辆的车号进行确认如果车号正确给相应的变量赋值和显示相应
                的信息系
参数：          char *abateNumber       存储数据的变量
返回值：        返回类型    int
                返回结果    返回卡号索引，如果-1优惠车号输入不正确，


创建日期：      2006.4.6
创建人:         莫远明
最后修改日期:   2006.4.6
最后修改人:     王海伟
----------------------------------------------------------------------*/
int Validate_Abate_CarNumber()
{	
 
    int ret = -1;
    return  ret ;
}
void  HandOnceOK(int keyboardValue,int currentworkstate)
{	
    int carTypeIndex;
    int carKindIndex;
    carKindIndex = Validate_Car_Kind(keyboardValue);	
    if(-1 ==carKindIndex)
    {	
        UI_Show_Help_Info("按键无效，请按提示进行操作。");	
    }
    else
    {	
        carTypeIndex = Validate_Car_Type_lane();	
        if(-1==carTypeIndex)
        {	
            switch(currentworkstate)
            {	
                case 4:
                    Set_WorkStation_03_Main_Work("正常收费","等待来车");	
                    SendLaneInfo("等待来车");	
                    break;               
                default:
                    break;
            }
            UI_Show_Help_Info("车型输入不正确请重新输入!");	
        }
        else
        {	
                KeyPressHandl( carTypeIndex, carKindIndex,currentworkstate);	
        }
    }
 
}
void KeyPressHandl(int carTypeIndex,int carKindIndex,int currentworkstate)
{	
	char tempOnceOk[2];
	char tempCarExitPlain[9];
	memset(tempOnceOk,0x00,sizeof(tempOnceOk));	
	memset(tempCarExitPlain,0x00,sizeof(tempCarExitPlain));	
    ShowInformatiom(carTypeIndex,carKindIndex,0);	
	strncpy(tempOnceOk,CarKindRecord[carKindIndex].onceOk,sizeof(CarKindRecord[carKindIndex].onceOk));	
	if(atoi(tempOnceOk))
    {		
        SetG_billRePrintEnabled(F);	
        SetG_simulateEnabled(T);	
        SetG_reprintbillnum(0);	
        SetG_billRePrintEnabled(F);	
        switch(currentworkstate)
        {	
            case 4:
                Set_WorkStation_10_Up_Parapet_Pass();	
                break;          
            default:
                break;
        }
    }
    else
    {	
        SetG_billRePrintEnabled(T);	
		strncpy(tempCarExitPlain,CarKindRecord[carKindIndex].carKindExplian,sizeof(CarKindRecord[carKindIndex].carKindExplian));	
		echo("tempCarExitPlain=%s",tempCarExitPlain);	
		if(0!=strcmp(trim(tempCarExitPlain),"收费车"))
        {	
            SetRingVoide(T);	
			if (0==GetCarKindChargeComputeMethod_byindex(carKindIndex))
			{
				char tmptempCarExitPlain[10];
				memset(tmptempCarExitPlain,0x00,10);
				sprintf(tmptempCarExitPlain,"车种:%s",tempCarExitPlain);
				SendTcoWaingMsg(tmptempCarExitPlain);
			}
			
        }
		else
		{
			OpenMoneyBox();
		}
        switch(currentworkstate)
        {	
			case 4:
				if (CarKindRecord[Getg_CurrentCarKindIndex()].IsEnterCarNum=='1' )
				{
					Set_WorkStation_66_InputCarNo("输入车牌号");
				}
				else
				{
					Set_WorkStation_07_General_Second_OK("正常收费","请核实并确认");	
				}              
                break;       
            default:
                break;
        }
    }
	

}
int  Validate_Car_Type_lane()
{	
    int ret = -1;
    SETG_Car_Type_end(Getg_carTypeLen());	
	ret=atoi(GetG_Car_Type())-1;
	return ret;
}
#define SYS_DEBUG  1
int Validate_Car_Kind(int keyboardValue)
{	
    int ret = -1;
    int carKindIndex;
	char tempKeyboardValue[3];
	memset(tempKeyboardValue,0x00,sizeof(tempKeyboardValue));
    for(carKindIndex=0;carKindIndex<GetG_Lane_carKindCount();	 carKindIndex++)
    {	
      
		strncpy(tempKeyboardValue,CarKindRecord[carKindIndex].keyboardValue,sizeof(CarKindRecord[carKindIndex].keyboardValue));	
        if(keyboardValue == atoi(tempKeyboardValue))
        {	
            ret = carKindIndex;
            break;
        }
    }
    return ret;
}
BOOL inline isInteger(float data)
{	
    int temp;
    temp = data*10;
    temp = temp % 10;
    if(0==temp)
    {	
        return T;
    }
    else
    {	
        return F;
    }
}
/*************************************************************************************
*函数名称：      void ShowInformatiom(int carTypeIndex,int   carKindIndex ,float spcCharge)
*创建日期：      2005.10
*创建人:         莫远明
*最后修改日期:   2008.07
*最后修改人:     王海伟
*将指定消息添加到消息队列
*添加一个参数来特殊车辆的金额
**************************************************************************************/

void ShowInformatiom_fee(void)
{
	
	UI_SetCarMoney((short)GetG_Current_Handl_Charge());
	LedShowCharge(GetG_Current_Handl_Car_Type()[0],(int)GetG_Current_Handl_Charge());
}
void ShowInformatiom(int carTypeIndex,int carKindIndex,float spcCharge)
{	
	char tempNetNo[3];
	char tempPlazaNo[3];
	char tempCarType[1];
	char tempImageIndex[2];
	char tempCarKindType[9];
	char tempCarExitPlain[9];
	float tempTollFare;
	float tmpCTF;
	tmpCTF=0.0;
	echo("int carTypeIndex %d,int carKindIndex %d,float spcCharge %f",  carTypeIndex,  carKindIndex,  spcCharge);
	memset(tempNetNo,0x00,sizeof(tempNetNo));	
	memset(tempPlazaNo,0x00,sizeof(tempPlazaNo));	
	memset(tempImageIndex,0x00,sizeof(tempImageIndex));	
	memset(tempCarKindType,0x00,sizeof(tempCarKindType));	
	tempTollFare=0.0;
	SetG_Current_Handl_Charge(0.0);
	tempTollFare=(float)GetFareValue(carTypeIndex);	
	echoic("原始金额:%f",tempTollFare);
	Set_G_Current_Toll_Fare(tempTollFare);
	echoic("Get_G_Current_Actual_pay <%f>Get_G_Current_Toll_Fare<%f>",Get_G_Current_Actual_pay(),Get_G_Current_Toll_Fare());
	strncpy(tempNetNo,GetLanConfigNetNo(),2);	
	strncpy(tempPlazaNo,GetLanConfigPlazaNo(),2);	
	strncpy(tempCarKindType,CarKindRecord[carKindIndex].carKindType,8);	
	tempCarKindType[8] = 0x00;
	sprintf(tempCarType,"%d",carTypeIndex+1);	
	if(0==strcmp(trim(tempCarKindType),"是"))
    {	
		strncpy(tempNetNo,GetLanConfigNetNo(),2);	
		strncpy(tempPlazaNo,GetLanConfigPlazaNo(),2);	
		if(0==atoi(CarKindRecord[carKindIndex].BillFlag))
		{	
			SetG_Current_Handl_Charge(0);	
		}
		else
		{	
			SetG_Current_Handl_Charge(tempTollFare);	
		}
    }
    else
    {	
        SetG_Current_Handl_Charge(spcCharge);	
    }
	echoic("根据是否为车种计算后为 %f",GetG_Current_Handl_Charge());
	//--------------------------------------------------------------------------------------------
	tmpCTF=GetCarKindChargeComputeMethod_byindex(carKindIndex);
	echoic("计算方法 %f",tmpCTF);
	tmpCTF= GetG_Current_Handl_Charge()* tmpCTF ;
	
	SetG_Current_Handl_Charge(tmpCTF);
	echoic("计算后得到的金额 %f  ",GetG_Current_Handl_Charge());
	Setg_CurrentCarTypeStand(atoi(GetG_Car_Type()));	
	strncpy(tempCarExitPlain,CarKindRecord[carKindIndex].carKindExplian,sizeof(CarKindRecord[carKindIndex].carKindExplian));	
	Setg_CurrentCarKindExplain(tempCarExitPlain);	
	SetG_Current_Handl_Car_Type(GetG_Car_Type());	
	SetG_Current_Handl_Car_Kind(Getg_CurrentCarKindExplain());		
	SetG_BillPrintFlag(CarKindRecord[carKindIndex].BillFlag[0]=='1' ? 1:0);	
	SendLaneInfo_default();	
    UI_SetCarKind(carKindIndex);
	ShowInformatiom_fee();
	
	if (0==strncmp(CarKindRecord[carKindIndex].carKindExplian,"优惠卡车",4) )
	{
		
		memset(g_currentPrint.Charge,0x00,10);
		sprintf(g_currentPrint.Charge,"%3.0f/%1.0f",GetG_Current_Handl_Charge(),tempTollFare);
		memset(g_currentPrint.carType,0x00,10);
		sprintf(g_currentPrint.carType,"%sY",GetG_Car_Type());
	}
	else
	{
		memset(g_currentPrint.Charge,0x00,10);

		sprintf(g_currentPrint.Charge,"%5.0f",GetG_Current_Handl_Charge());
		memset(g_currentPrint.carType,0x00,10);

		strcpy(g_currentPrint.carType,GetG_Car_Type());
	}
	Setg_CurrentCartypeIndex(carTypeIndex);
	Setg_CurrentCarKindIndex(GetCarKindInt(carKindIndex));
	echoic("最后金额 %f",GetG_Current_Handl_Charge());
	echoic("Get_G_Current_Actual_pay <%f>Get_G_Current_Toll_Fare<%f>",Get_G_Current_Actual_pay(),Get_G_Current_Toll_Fare());

}
//----------------------------------------------------------------






