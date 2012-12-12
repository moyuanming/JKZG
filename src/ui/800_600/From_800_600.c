
#include "LocalIncludeFile.h"
#include "UI_Macro.h"
#include "800_600.h"
#include "From_800_600.h"


#define BIGFONT_SIZE 40

static HWND From_Handl=HWND_INVALID;
HWND  UI_Out_800_600_Get_From_Handl(void)
{	
	return From_Handl;
}
void UI_Out_800_600_Set_From_Handl(HWND hwnd)
{	
	From_Handl=hwnd;
}

void UI_Out_800_600_LoadRes ( void )
{
	LoadBitmap ( HDC_SCREEN , &bmBaojingG , "/EMRCV3/BIN/res/button/BaojingG.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &bmBaojingA , "/EMRCV3/BIN/res/button/BaojingA.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &bmAutoLanganDown , "/EMRCV3/BIN/res/button/AutoLanganDown.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &bmAutoLanganUp , "/EMRCV3/BIN/res/button/AutoLanganUp.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &bmHandLanganUp , "/EMRCV3/BIN/res/button/bmPrintG.bmp" ) ;
	LoadBitmap ( HDC_SCREEN , &bmHandLanganDown , "/EMRCV3/BIN/res/button/bmPrintR.bmp" ) ;
	LoadBitmap ( HDC_SCREEN , &bmJiaotongR , "/EMRCV3/BIN/res/button/JiaotongR.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &bmJiaotongG , "/EMRCV3/BIN/res/button/JiaotongG.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &bmCarGo , "/EMRCV3/BIN/res/button/CarGo.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &bmCarArrived , "/EMRCV3/BIN/res/button/CarArrive.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &bmYupengG , "/EMRCV3/BIN/res/button/YupengG.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &bmYupengR , "/EMRCV3/BIN/res/button/YupengR.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &bmGuanggeGo , "/EMRCV3/BIN/res/button/GuanggeGo.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &bmGuanggeArrived , "/EMRCV3/BIN/res/button/GuanggeArrived.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &axlet1 , "/EMRCV3/BIN/res/button/axlet1.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &axlet2 , "/EMRCV3/BIN/res/button/axlet2.gif" ) ;
	LoadBitmap ( HDC_SCREEN , &axlet3 , "/EMRCV3/BIN/res/button/axlet3.gif" ) ;
	
}
void UI_Out_800_600_SetMainFromColor ( int nBkColor )
{

	HDC hDC  = GetClientDC ( UI_Out_800_600_Get_From_Handl() ) ;
	SetBrushColor ( hDC , nBkColor ) ;
	FillBox ( hDC , 0 , 0 , 800 , 2 ) ;
	FillBox ( hDC , 0 , 24 , 800 , 1 ) ;
	FillBox ( hDC , 0 , 48 , 800 , 3 ) ;
	FillBox ( hDC , 0 , 149 , 800 , 3 ) ;
	FillBox ( hDC , 0 , 171 , 800 , 9 ) ;
	FillBox ( hDC , 0 , 204 , 800 , 4 ) ;
	FillBox ( hDC , 0 , 306 , 360 , 2 ) ;
	FillBox ( hDC , 360 , 482 , 325 , 2 ) ;
	FillBox ( hDC , 360 , 507 , 440 , 2 ) ;
	FillBox ( hDC , 0 , 597 , 800 , 3 ) ;
	FillBox ( hDC , 0 , 0 , 1 , 24 ) ;
	FillBox ( hDC , 799 , 0 , 1 , 24 ) ;
	FillBox ( hDC , 0 , 24 , 4 , 600 - 24 ) ;
	FillBox ( hDC , 796 , 24 , 4 , 600 - 24 ) ;
	FillBox ( hDC , 168 , 24 , 3 , 180 - 24 ) ;
	FillBox ( hDC , 339 , 24 , 3 , 180 - 24 ) ;
	FillBox ( hDC , 460 , 24 , 3 , 180 - 24 ) ;
	FillBox ( hDC , 581 , 24 , 3 , 180 - 24 ) ;
	FillBox ( hDC , 357 , 171 , 3 , 600 - 171 ) ;
	FillBox ( hDC , 683 , 149 , 3 , 509 - 149 ) ;
	FillBox ( hDC , 621 , 149 , 3 , 180 - 149 ) ;
	FillBox ( hDC , 530 , 171 , 3 , 208 - 171 ) ;
	ReleaseDC ( hDC ) ;

}

void UI_InitMenu(UI_Object ** Menu,int length,UI_Object *parent)
{
	HWND hWnd = UI_Out_800_600_Get_From_Handl ( ) ;
	int i=0;
	for(i=0;i<length;i++)
	{
		Menu[i] = create_Object ( hWnd ) ;
		set_Parent(parent,Menu[i]);
		Menu[i]->type = RadioButton;
		if(i==0)
		{
			Menu[i]->isGroup = TRUE;
		}
	}
}
void Init_GUI_Var ( void )
{
	HWND hWnd = UI_Out_800_600_Get_From_Handl ( ) ;
	gui_title = create_Object ( hWnd ) ;
	gui_car_title = create_Object ( hWnd ) ;
	gui_carType_title = create_Object ( hWnd ) ;
	gui_PassCharge_title = create_Object ( hWnd ) ;
	gui_Payment_title = create_Object ( hWnd ) ;
	gui_EquipmentState_title = create_Object ( hWnd ) ;
	gui_car = create_Object ( hWnd ) ;
	gui_carType = create_Object ( hWnd ) ;
	gui_Payment = create_Object ( hWnd ) ;
	gui_PassCharge = create_Object ( hWnd ) ;
	gui_EquipmentState = create_Object ( hWnd ) ;
	gui_Baojing = create_Object ( hWnd ) ;
	gui_Jiaotong = create_Object ( hWnd ) ;
	gui_Langan = create_Object ( hWnd ) ;
	gui_ZhuaPaiXianQuan_title = create_Object ( hWnd ) ;
	gui_TongGuoXianQuan_title = create_Object ( hWnd ) ;
	gui_ZhuaPaiXianQuan = create_Object ( hWnd ) ;
	gui_TongGuoXianQuan = create_Object ( hWnd ) ;
	gui_CarNoInfo = create_Object ( hWnd ) ;
	gui_RorwardEnterInfo = create_Object ( hWnd ) ;
	gui_ForwardChargeInfo = create_Object ( hWnd ) ;
	gui_ForwardPaymentInfo = create_Object ( hWnd ) ;
	gui_PassCarNum = create_Object ( hWnd ) ;
	gui_AutoLanganState = create_Object ( hWnd ) ;
	gui_WeightInfo = create_Object ( hWnd ) ;
	gui_OperateInfo = create_Object ( hWnd ) ;
	gui_WorkMode1 = create_Object ( hWnd ) ;
	gui_WorkMode2 = create_Object ( hWnd ) ;
	gui_CurrentWeightInfo = create_Object ( hWnd ) ;
	gui_Information = create_Object ( hWnd ) ;
	gui_Video = create_Object ( hWnd ) ;
	gui_InputDataArea = create_Object ( hWnd ) ;
	gui_ArrivedCarWeightInfo = create_Object ( hWnd ) ;
	gui_CardBoxInfo = create_Object ( hWnd ) ;
	gui_Yupeng = create_Object ( hWnd ) ;
	gui_Print = create_Object ( hWnd ) ;
	gui_Event_title = create_Object ( hWnd ) ;
	gui_Event = create_Object ( hWnd ) ;
	gui_CurrentTime = create_Object ( hWnd ) ;
	//登录窗体
	gui_Login_USR_Panel = create_Object ( hWnd ) ;
	gui_Login_USR = create_Object ( hWnd ) ;
	gui_Login_PWD_Panel = create_Object ( hWnd ) ;
	gui_Login_PWD = create_Object ( hWnd ) ;
	//欠款
	gui_QK_QKD_Panel = create_Object ( hWnd ) ;
	gui_QK_QKD = create_Object ( hWnd ) ;
	gui_QK_QK_Panel = create_Object ( hWnd ) ;
	gui_QK_QK = create_Object ( hWnd ) ;
	//优惠卡界面元素初始化
	gui_YH_Panel = create_Object ( hWnd ) ;
	gui_YH_YHK = create_Object ( hWnd ) ;
	

	gui_title->x = 1 ;
	gui_title->y = 2 ;
	gui_title->width = 796 ;
	gui_title->height = 21 ;
	gui_title->border.width = 0 ;
	gui_title->background.color = SUBTITLECOLOR ;
	gui_title->text.color = TITLE_TEXT_COLOR ;
	gui_title->text.align = DT_LEFT ;

	//第一行
	set_XYWH ( gui_car_title , RtCarText ) ;
	gui_car_title->text.info = "车型" ;

	set_XYWH ( gui_carType_title , RtEnterInfoText ) ;
	gui_carType_title->text.info = "车种" ;

	set_XYWH ( gui_PassCharge_title , RtPassChargeText ) ;
	gui_PassCharge_title->text.info = "金额" ;

	set_XYWH ( gui_Payment_title , RtPaymentText ) ;
	gui_Payment_title->text.info = "支付方式" ;

	set_XYWH ( gui_EquipmentState_title , RtEquipmentState ) ;
	gui_EquipmentState_title->text.info = "设备状态" ;


	//第二行
	set_XYWH ( gui_car , RtCarTextInfo ) ;
	gui_car->text.info = "？" ;
	gui_car->text.size = BIGFONT_SIZE ;
	gui_car->text.type = "ttf" ;
	gui_car->text.family = "msyh" ;
	gui_car->text.weight = FONT_WEIGHT_BOOK ;
	set_Font ( & ( gui_car->text ) ) ;

	set_XYWH ( gui_carType , RtEnterInfo ) ;
	gui_carType->text.size = BIGFONT_SIZE ;
	gui_carType->text.type = "ttf" ;
	gui_carType->text.family = "msyh" ;
	gui_carType->text.weight = FONT_WEIGHT_BOOK ;
	set_Font ( & ( gui_carType->text ) ) ;

	set_XYWH ( gui_PassCharge , RtPassChargeInfo ) ;
	gui_PassCharge->text.size = BIGFONT_SIZE ;
	gui_PassCharge->text.type = "ttf" ;
	gui_PassCharge->text.family = "msyh" ;
	gui_PassCharge->text.weight = FONT_WEIGHT_BOOK ;
	set_Font ( & ( gui_PassCharge->text ) ) ;

	set_XYWH ( gui_Payment , RtPaymentInfo ) ;
	gui_Payment->text.size = BIGFONT_SIZE ;
	gui_Payment->text.type = "ttf" ;
	gui_Payment->text.family = "msyh" ;
	gui_Payment->text.weight = FONT_WEIGHT_BOOK ;
	set_Font ( & ( gui_Payment->text ) ) ;


	set_XYWH ( gui_EquipmentState , RtEquipmentStateInfo ) ;

	set_XYWH ( gui_Baojing , RtBaojing ) ;
	gui_Baojing->border.width = 0 ;
	gui_Baojing->background.image = &bmBaojingG ;
	set_Parent ( gui_EquipmentState , gui_Baojing ) ;

	set_XYWH ( gui_Jiaotong , RtJiaotong ) ;
	gui_Jiaotong->border.width = 0 ;
	gui_Jiaotong->background.image = &bmJiaotongR ;
	set_Parent ( gui_EquipmentState , gui_Jiaotong ) ;

	set_XYWH ( gui_Langan , RtLangan ) ;
	gui_Langan->border.width = 0 ;
	gui_Langan->background.image = &bmAutoLanganDown ;
	set_Parent ( gui_EquipmentState , gui_Langan ) ;

	set_XYWH ( gui_ZhuaPaiXianQuan_title , RtZhuaPaiXianQuanText ) ;
	gui_ZhuaPaiXianQuan_title->border.width = 0 ;
	gui_ZhuaPaiXianQuan_title->text.info = "到达" ;
	set_Parent ( gui_EquipmentState , gui_ZhuaPaiXianQuan_title ) ;

	set_XYWH ( gui_TongGuoXianQuan_title , RtTongGuoXianQuanText ) ;
	gui_TongGuoXianQuan_title->border.width = 0 ;
	gui_TongGuoXianQuan_title->text.info = "离开" ;
	set_Parent ( gui_EquipmentState , gui_TongGuoXianQuan_title ) ;

	set_XYWH ( gui_ZhuaPaiXianQuan , RtZhuaPaiXianQuan ) ;
	gui_ZhuaPaiXianQuan->border.width = 0 ;
	gui_ZhuaPaiXianQuan->background.image = &bmCarGo ;
	set_Parent ( gui_EquipmentState , gui_ZhuaPaiXianQuan ) ;

	set_XYWH ( gui_TongGuoXianQuan , RtTongGuoXianQuan ) ;
	gui_TongGuoXianQuan->border.width = 0 ;
	gui_TongGuoXianQuan->background.image = &bmCarGo ;
	set_Parent ( gui_EquipmentState , gui_TongGuoXianQuan ) ;


	//第三行
	set_XYWH ( gui_CarNoInfo , RtCarNoInfo ) ;

	set_XYWH ( gui_RorwardEnterInfo , RtRorwardEnterInfo ) ;

	set_XYWH ( gui_ForwardChargeInfo , RtForwardChargeInfo ) ;

	set_XYWH ( gui_ForwardPaymentInfo , RtForwardPaymentInfo ) ;

	set_XYWH ( gui_PassCarNum , RtPassCarNum ) ;
	gui_PassCarNum->text.info = "轴数" ;

	set_XYWH ( gui_AutoLanganState , RtAutoLanganState ) ;
	gui_AutoLanganState->text.info = "重量" ;

	set_XYWH ( gui_WeightInfo , RtWeightInfo ) ;
	gui_WeightInfo->text.info = "重量" ;


	//第四行
	set_XYWH ( gui_OperateInfo , RtOperateInfo ) ;
	gui_OperateInfo->text.align=DT_LEFT;
	
	set_XYWH ( gui_WorkMode1 , RtWorkMode1 ) ;

	set_XYWH ( gui_WorkMode2 , RtWorkMode2 ) ;

	set_XYWH ( gui_CurrentWeightInfo , RtCurrentWeightInfo ) ;


	//第五行
	set_XYWH ( gui_Information , RtInformation ) ;
	gui_Information->padding = 5 ;
	gui_Information->text.isSingleline = F ;
	gui_Information->text.align = DT_LEFT ;
	gui_Information->text.valign = DT_TOP ;

	set_XYWH ( gui_Video , RtVideo ) ;
	Create_camera (  ) ;


	//右边
	set_XYWH ( gui_InputDataArea , RtInputDataArea ) ;

	set_XYWH ( gui_CurrentTime , RtCurrentTime ) ;


	//计重
	set_XYWH ( gui_ArrivedCarWeightInfo , RtArrivedCarWeightInfo ) ;
	gui_ArrivedCarWeightInfo->background.color = WHITE_COLOR ;


	//事件区
	set_XYWH ( gui_CardBoxInfo , RtCardBoxInfo ) ;

	set_XYWH ( gui_Yupeng , RtYupeng ) ;
	gui_Yupeng->border.width = 0 ;
	gui_Yupeng->background.image = &bmYupengG ;
	set_Parent ( gui_CardBoxInfo , gui_Yupeng ) ;

	set_XYWH ( gui_Print , RtPrint ) ;
	gui_Print->border.width = 0 ;
	gui_Print->background.image = &bmHandLanganUp ;
	set_Parent ( gui_CardBoxInfo , gui_Print ) ;

	set_XYWH ( gui_Event_title , RtEventText ) ;
	gui_Event_title->border.width = 0 ;
	gui_Event_title->text.info = "事件报警" ;
	set_Parent ( gui_CardBoxInfo , gui_Event_title ) ;

	set_XYWH ( gui_Event , RtEvent ) ;
	gui_Event->border.width = 5 ;
	gui_Event->background.color = KAXIANG_BACK_COLOR ;
	set_Parent ( gui_CardBoxInfo , gui_Event ) ;


	//登录界面元素初始化
	set_XYWH ( gui_Login_USR_Panel , RtLoginUSRPanel ) ;
	set_Parent ( gui_InputDataArea , gui_Login_USR_Panel ) ;
	gui_Login_USR_Panel->ispanel = T ;
	gui_Login_USR_Panel->padding = gui_Login_USR_Panel->paneltext.size / 2 ;
	gui_Login_USR_Panel->paneltext.info = "工号：" ;

	set_XYWH ( gui_Login_USR , RtLoginUSR ) ;
	set_Parent ( gui_Login_USR_Panel , gui_Login_USR ) ;
	gui_Login_USR->background.color = WHITE_COLOR ;
	gui_Login_USR->text.align = DT_LEFT ;

	set_XYWH ( gui_Login_PWD_Panel , RtLoginPWDPanel ) ;
	set_Parent ( gui_InputDataArea , gui_Login_PWD_Panel ) ;
	gui_Login_PWD_Panel->ispanel = T ;
	gui_Login_PWD_Panel->padding = gui_Login_PWD_Panel->paneltext.size / 2 ;
	gui_Login_PWD_Panel->paneltext.info = "密码：" ;

	set_XYWH ( gui_Login_PWD , RtLoginPWD ) ;
	set_Parent ( gui_Login_PWD_Panel , gui_Login_PWD ) ;
	gui_Login_PWD->background.color = WHITE_COLOR ;
	gui_Login_PWD->text.align = DT_LEFT ;


	//欠款界面元素初始化
	set_XYWH ( gui_QK_QKD_Panel , RtLoginUSRPanel ) ;
	set_Parent ( gui_InputDataArea , gui_QK_QKD_Panel ) ;
	gui_QK_QKD_Panel->ispanel = T ;
	gui_QK_QKD_Panel->padding = gui_QK_QKD_Panel->paneltext.size / 2 ;
	gui_QK_QKD_Panel->paneltext.info = "欠款单号：" ;

	set_XYWH ( gui_QK_QKD , RtLoginUSR ) ;
	set_Parent ( gui_QK_QKD_Panel , gui_QK_QKD ) ;
	gui_QK_QKD->background.color = WHITE_COLOR ;
	gui_QK_QKD->text.align = DT_LEFT ;

	set_XYWH ( gui_QK_QK_Panel , RtLoginPWDPanel ) ;
	set_Parent ( gui_InputDataArea , gui_QK_QK_Panel ) ;
	gui_QK_QK_Panel->ispanel = T ;
	gui_QK_QK_Panel->padding = gui_QK_QK_Panel->paneltext.size / 2 ;
	gui_QK_QK_Panel->paneltext.info = "欠款金额：" ;

	set_XYWH ( gui_QK_QK , RtLoginPWD ) ;
	set_Parent ( gui_QK_QK_Panel , gui_QK_QK ) ;
	gui_QK_QK->background.color = WHITE_COLOR ;
	gui_QK_QK->text.align = DT_LEFT ;


	//优惠卡界面元素初始化
	set_XYWH ( gui_YH_Panel , RtLoginUSRPanel ) ;
	set_Parent ( gui_InputDataArea , gui_YH_Panel ) ;
	gui_YH_Panel->ispanel = T ;
	gui_YH_Panel->padding = gui_YH_Panel->paneltext.size / 2 ;
	//gui_YH_Panel->paneltext.info = "优惠卡号：" ;

	set_XYWH ( gui_YH_YHK , RtLoginUSR ) ;
	set_Parent ( gui_YH_Panel , gui_YH_YHK ) ;
	gui_YH_YHK->background.color = WHITE_COLOR ;
	gui_YH_YHK->text.align = DT_LEFT ;

	//菜单分组
	gui_MenuFrom = create_Object ( hWnd ) ;
	set_Parent ( gui_InputDataArea , gui_MenuFrom ) ;
	gui_MenuFrom->type = GroupBox;
	set_XYWH ( gui_MenuFrom , RtMenu ) ;
	//gui_MenuFrom->x = 5 ;
	//gui_MenuFrom->y = 5 ;
	//gui_MenuFrom->width = gui_MenuFrom->parent->width - gui_MenuFrom->parent->padding * 2 - 10 ;
	//gui_MenuFrom->height = gui_MenuFrom->parent->height - gui_MenuFrom->parent->padding * 2 - 10 ;
	gui_MenuFrom->padding = gui_MenuFrom->paneltext.size / 2 + 10 ;
	//菜单
	UI_InitMenu(gui_Menu,MaxMenu,gui_MenuFrom);
	//模拟
	UI_InitMenu(gui_MenuMoni,MaxMenuMoni,gui_MenuFrom);
	gui_MenuMoni[0]->text.info="1:通行模拟";
	gui_MenuMoni[1]->text.info="2:更改车型/车种";
	gui_MenuMoni[2]->text.info="3:被拖车";
	gui_MenuMoni[3]->text.info="4:重打票据";
	gui_MenuMoni[4]->text.info="5:补票";

}
void Draw_GUI ( void )
{
	Draw_Object ( gui_title ) ;
	Draw_Object ( gui_car_title ) ;
	Draw_Object ( gui_carType_title ) ;
	Draw_Object ( gui_PassCharge_title ) ;
	Draw_Object ( gui_Payment_title ) ;
	Draw_Object ( gui_EquipmentState_title ) ;
	Draw_Object ( gui_car ) ;
	Draw_Object ( gui_carType ) ;
	Draw_Object ( gui_PassCharge ) ;
	Draw_Object ( gui_Payment ) ;
	Draw_Object ( gui_EquipmentState ) ;
	Draw_Object ( gui_Baojing ) ;
	Draw_Object ( gui_Jiaotong ) ;
	Draw_Object ( gui_Langan ) ;
	Draw_Object ( gui_ZhuaPaiXianQuan_title ) ;
	Draw_Object ( gui_TongGuoXianQuan_title ) ;
	Draw_Object ( gui_ZhuaPaiXianQuan ) ;
	Draw_Object ( gui_TongGuoXianQuan ) ;
	Draw_Object ( gui_CarNoInfo ) ;
	Draw_Object ( gui_RorwardEnterInfo ) ;
	Draw_Object ( gui_ForwardChargeInfo ) ;
	Draw_Object ( gui_ForwardPaymentInfo ) ;
	Draw_Object ( gui_PassCarNum ) ;
	Draw_Object ( gui_AutoLanganState ) ;
	Draw_Object ( gui_WeightInfo ) ;
	Draw_Object ( gui_OperateInfo ) ;
	Draw_Object ( gui_WorkMode1 ) ;
	Draw_Object ( gui_WorkMode2 ) ;
	Draw_Object ( gui_CurrentWeightInfo ) ;
	Draw_Object ( gui_Information ) ;
	Draw_Object ( gui_Video ) ;
	Draw_Object ( gui_InputDataArea ) ;
	Draw_Object ( gui_CurrentTime ) ;
	Draw_Object ( gui_ArrivedCarWeightInfo ) ;
	Draw_Object ( gui_CardBoxInfo ) ;
	Draw_Object ( gui_Yupeng ) ;
	Draw_Object ( gui_Print ) ;
	Draw_Object ( gui_Event_title ) ;
	Draw_Object ( gui_Event ) ;
}

void Draw_CarAxle_GUI(void)
{
	HWND hWnd = UI_Out_800_600_Get_From_Handl ( ) ;
	int carnum = Car_GetNum();
	int i,j,caraxlenum,height;
	char anstr[20],awstr[20];
	UI_Object gui_car,gui_axle,gui_w,gui_t;
	height = 15;
	init_Object(&gui_car);
	gui_car.hWnd = hWnd;
	gui_car.parent = gui_ArrivedCarWeightInfo;
	gui_car.width = gui_ArrivedCarWeightInfo->width-(gui_ArrivedCarWeightInfo->padding+gui_ArrivedCarWeightInfo->border.width)*2;
	gui_car.background.color = gui_ArrivedCarWeightInfo->background.color;

	int g1,g3;
	g1=25;
	g3=37;

	init_Object(&gui_axle);
	gui_axle.hWnd = hWnd;
	gui_axle.parent = &gui_car;
	gui_axle.width = g1;
	gui_axle.background.color = gui_car.background.color;
	gui_axle.border.width = 0;
	gui_axle.height = height;
	gui_axle.text.size=10;
	
	init_Object(&gui_t);
	gui_t.hWnd = hWnd;
	gui_t.parent = &gui_car;
	gui_t.width = gui_car.width - (gui_car.padding+gui_car.border.width)*2-g1-g3;
	gui_t.x = g1;
	gui_t.background.color = gui_car.background.color;
	gui_t.border.width = 0;
	gui_t.height = height;
	gui_t.text.size=10;
	
	init_Object(&gui_w);
	gui_w.hWnd = hWnd;
	gui_w.parent = &gui_car;
	gui_w.width = g3;
	gui_w.x = gui_axle.width+gui_t.width;
	gui_w.background.color = gui_car.background.color;
	gui_w.border.width = 0;
	gui_w.height = height;
	gui_w.text.size=10;
	

	int y=0,y1=0;;
	Draw_Object(gui_ArrivedCarWeightInfo);
	echo("carnum=%d",carnum);
	for(i=0;i<carnum;i++)
	{
		caraxlenum = Car_GetCarAxlesNum(i);
		echo("caraxlenum=%d",caraxlenum);
		if(caraxlenum>0)
		{
			gui_car.height = caraxlenum*height+gui_car.padding*2;
			gui_car.y = y;
			y += gui_car.height;
			Draw_Object(&gui_car);
			echo("Draw_Car");
			y1=0;
			if(i==carnum-1)
			{
				gui_axle.background.color = GLOAB_BACK_COLOR;
				gui_t.background.color = GLOAB_BACK_COLOR;
				gui_w.background.color = GLOAB_BACK_COLOR;
			}
			for(j=0;j<caraxlenum;j++)
			{
				gui_axle.y = y1;
				gui_t.y = y1;
				gui_w.y = y1;
				y1 += height;
				if(j==0)
				{
					sprintf(anstr,"%02d",Car_GetCarAxlesNum(i));
					gui_axle.text.info = anstr;
				}
				else
				{
					gui_axle.text.info = "";
				}
				
				switch(Car_GetCarAxlesType(i, j))
				{
				case 1:
					gui_t.background.image = &axlet1;
					break;
				case 2:
					gui_t.background.image = &axlet2;
					break;
				case 3:
					gui_t.background.image = &axlet3;
					break;
				default:
					gui_t.background.image = &axlet1;
					break;
				}
				sprintf(awstr,"%03d",Car_GetCarAxlesWeight(i, j));
				gui_w.text.info = awstr;
				Draw_Object(&gui_axle);
				Draw_Object(&gui_t);
				Draw_Object(&gui_w);
				echo("CarAxlesNum:%d;CarAxlesType:%d;CarAxlesWeight:%d;CarAxlesSpace:%d;",Car_GetCarAxlesNum(i),Car_GetCarAxlesType(i, j),Car_GetCarAxlesWeight(i, j),Car_GetCarAxlesSpace(i,j));
			}
		}
	}
}
void UI_Out_800_600_InitFrom(HWND hWnd)
{
	Set_CarList_Change_Event(Draw_CarAxle_GUI);
	UI_Out_800_600_Set_From_Handl(hWnd);
	Init_GUI_Var();
	Draw_GUI();
	UI_Out_800_600_SetMainFromColor ( BTN_BORDER_COLOR ) ;
	
}

void Draw_InputDataArea_GUI ( void )
{
	Draw_Object ( gui_InputDataArea ) ;
}

void UI_Out_800_600_Draw_LoginFrom_GUI ( void )
{
	//重绘区域
	Draw_InputDataArea_GUI ( ) ;
	//绘制登录区域
	Draw_Object ( gui_Login_USR_Panel ) ;
	Draw_Object ( gui_Login_USR ) ;
	set_Text(gui_Login_USR,"");
	Draw_Object ( gui_Login_PWD_Panel ) ;
	Draw_Object ( gui_Login_PWD ) ;
	set_Text(gui_Login_PWD,"");

}
void UI_Out_800_600_Set_UserNumber(char *UserNumber)
{

	set_Text(gui_Login_USR,UserNumber);

}
void UI_Out_800_600_Set_Pwd(char *UserNumber)
{

	set_Text(gui_Login_PWD,UserNumber);

}
void Draw_QKFrom_GUI ( void )
{
	//重绘区域
	Draw_InputDataArea_GUI ( ) ;
	//绘制登录区域
	Draw_Object ( gui_QK_QKD_Panel ) ;
	Draw_Object ( gui_QK_QKD ) ;
	Draw_Object ( gui_QK_QK_Panel ) ;
	Draw_Object ( gui_QK_QK ) ;

}
void Draw_YHFrom_GUI ( char * Type )
{
	//重绘区域
	Draw_InputDataArea_GUI ( ) ;
	//绘制登录区域
	gui_YH_Panel->paneltext.info = Type ;
	Draw_Object ( gui_YH_Panel ) ;
	Draw_Object ( gui_YH_YHK ) ;

}
void Draw_MenuFrom_GUI ( char *menuName , UI_Object ** Menu,int length)
{
	Draw_InputDataArea_GUI ( ) ;
	gui_MenuFrom->text.info =  menuName;// info ;
	Draw_Object ( gui_MenuFrom ) ;
	int i=0,y=0;
	for(i=0;i<length;i++)
	{
		Menu[i]->height = MenuItemItem;
		Menu[i]->width = gui_MenuFrom->width-((gui_MenuFrom->border.width+gui_MenuFrom->padding)*2);
		Menu[i]->y = y;
		y+=Menu[i]->height;
		Draw_Object ( Menu[i] ) ;
	}
}
void Draw_MenuForArray(char *menuName , char ** Menu,int length)
{
	Draw_InputDataArea_GUI ( ) ;
	gui_MenuFrom->text.info =  menuName;// info ;
	Draw_Object ( gui_MenuFrom ) ;
	int i=0,y=0;
	for(i=0;i<MaxMenu;i++)
	{
		if(i<length)
		{
			gui_Menu[i]->height = MenuItemItem;
			gui_Menu[i]->width = gui_MenuFrom->width-((gui_MenuFrom->border.width+gui_MenuFrom->padding)*2);
			gui_Menu[i]->y = y;
			gui_Menu[i]->text.info = Menu[i];
			y+=gui_Menu[i]->height;
			Draw_Object ( gui_Menu[i] ) ;
		}
		else
		{
			UI_Hide(gui_Menu[i]);
		}
	}
}
void Draw_MenuMoni_GUI(void)
{
	Draw_MenuFrom_GUI("模拟菜单",gui_MenuMoni,MaxMenuMoni);
}
void Set_MenuMoni_Enable(int index,int flag)
{
	if(index>=0&&index<MaxMenuMoni)
	{
		set_Enable(gui_MenuMoni[index],flag);
	}
}
void Set_MenuMoni_Check(int index,int flag)
{
	if(index>=0&&index<MaxMenuMoni)
	{
		set_RadioButtonCheck(gui_MenuMoni[index],flag);
	}
}
void UI_Out_800_600_Show_Input(char * Type)
{
	Draw_YHFrom_GUI(Type);
}
void UI_Out_800_600_Show_Input_Text(char * Text)
{
	
	set_Text(gui_YH_YHK,Text);
}
/*****************************************
 *标题信息
 *****************************************/
void UI_Out_800_600_Set_From_Title(char* szTitle)
{
	set_Text ( gui_title , szTitle ) ;
}
char Now_Car_Type [ 50 ] ;
void UI_Out_800_600_ShowOperatorInfo(char *pszInfo)
{
	set_Text ( gui_OperateInfo , pszInfo ) ;
}
void UI_Out_800_600_Show_Edit(int nEditAt, char *pszInfo)
{
	char temp [ 50 ] ;
	int i ;
	switch ( nEditAt )
	{
		case 0 ://车型
			set_Text ( gui_car , pszInfo ) ;
			break ;
		case 1 ://车种			
			set_Text ( gui_carType ,pszInfo) ;			
			break ;
		case 2 ://金额
			set_Text ( gui_PassCharge , pszInfo ) ;
			break ;
		case 3 :
			set_Text ( gui_Payment , pszInfo ) ;
			break ;
		case 9 :
			set_Text ( gui_Information , pszInfo ) ;
			break ;
		case 4 :
			set_Text ( gui_WorkMode2 , pszInfo ) ;
			break ;
		case 50 :
			set_Text ( gui_Login_USR , pszInfo ) ;
			break ;
		case 51 :
			for ( i = 0 ; i < strlen ( pszInfo ) ; i++ )
			{
				temp [ i ] = '*' ;
			}
			temp [ strlen ( GetG_Password ( ) ) ] = '\0' ;
			set_Text ( gui_Login_PWD , temp ) ;
			break ;
		case 60 :
			set_Text ( gui_QK_QKD , pszInfo ) ;
			break ;
		case 61 :
			set_Text ( gui_QK_QK , pszInfo ) ;
			break ;
		case 70 :
			set_Text ( gui_YH_YHK , pszInfo ) ;
			break ;
	}
}

void UI_Out_800_600_Show_BigFont(int nEditAt, short sVal,BOOL Flag)
{
	char cVal [ 200 ] ;
	memset ( cVal , 0x00 , 200 ) ;
	switch ( nEditAt )
	{
		case 0 ://车型
			sprintf ( cVal , "%d" , sVal ) ;
			set_Text ( gui_car , cVal ) ;
			break ;
		case 1 ://车种

			break ;
		case 2 ://金额
			sprintf ( cVal , "%d" , sVal ) ;
			set_Text ( gui_PassCharge , cVal ) ;
			break ;
	}
}
void UI_Out_800_600_ShowTime_MMI(char * szInfo )
{
	set_Text ( gui_CurrentTime , szInfo ) ;
}

///*****************************************
// *报警信息
// *****************************************/
void AlarmInformationText ( char color , char * information )
{
	if ( 'G' == color )
	{
		gui_Event->background.color = GLOAB_BACK_COLOR ;
	}
	else if ( 'R' == color )
	{
		gui_Event->background.color = REDALARM_COLOR ;
	}
	else if ( 'B' == color )
	{
		gui_Event->background.color = KAXIANG_BACK_COLOR ;
	}
	gui_Event->text.color = ALARMBOXTEXTCOLOR ;
	set_Text ( gui_Event , information ) ;
}
void UI_Out_800_600_ClearAbateChargeEditC(void)
{
	set_Text ( gui_PassCharge , "" ) ;
}
void UI_Out_800_600_Set_Help_Info(char *pszInfo)
{
	if(pszInfo[0]==0)
	{
		AlarmInformationText('G',pszInfo);
	}
	else
	{
		AlarmInformationText('R',pszInfo);
	}
}
void UI_Out_800_600_Show_Info(char *pszInfo)
{
	UI_Out_800_600_Show_Info_ByColor(pszInfo,TISHI_BACK_COLOR,RGB(250, 250, 250));
}
void UI_Out_800_600_Show_Info_ByColor(char *pszInfo, unsigned int  bc,unsigned int  tc)
{
	gui_Event->background.color = bc ;
	gui_Event->text.color = tc ;
	set_Text ( gui_Information , pszInfo ) ;
}
void UI_Out_800_600_ShowDeviceState_MMI(int btnindex,BOOL bFlag)
{
	switch ( btnindex )
	{
		case 1 :
			set_BackGround_Image ( gui_Yupeng , F == bFlag ? &bmYupengR : &bmYupengG ) ;
			break ;
		case 9 :
			set_BackGround_Image ( gui_Print , F == bFlag ? &bmHandLanganDown : &bmHandLanganUp ) ;
			break ;
		case 7 :
			set_BackGround_Image ( gui_Baojing , F == bFlag ? &bmBaojingG : &bmBaojingA ) ;
			break ;
		case 2 :
			set_BackGround_Image ( gui_Jiaotong , F == bFlag ? &bmJiaotongR : &bmJiaotongG ) ;
			break ;
		case 3 :
			set_BackGround_Image ( gui_Langan , F == bFlag ? &bmAutoLanganDown : &bmAutoLanganUp ) ;
			break ;
		case 4 :
			set_BackGround_Image ( gui_ZhuaPaiXianQuan , F == bFlag ? &bmCarGo : &bmCarArrived ) ;
			break ;
		case 5 :
			set_BackGround_Image ( gui_TongGuoXianQuan , F == bFlag ? &bmCarGo : &bmCarArrived ) ;
			break ;

	}
}
