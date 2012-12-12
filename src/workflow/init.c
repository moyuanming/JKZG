#include "../global/include/LocalIncludeFile.h"
#include "MemSyncFile.h"
#define AT91_SET 1
#define AT91_CLEAR 2
#define AT91_READ 3
#define AT91_INIT_IN 4
#define AT91_INIT_OUT 5
#define AT91_RESET 6

void I_DEV_Weight_Init(void)
{
	int fd = Serial_Open(GetWeightCOM());
	Serial_Set_Speed(fd, atoi(sys_ini.weight_speed));
	Wds_Run(fd);
}
static void Init_DevInit(void)
{	
	I_DEV_IOBoard_Init();
    I_DEV_LED_Init();
    I_DEV_Printer_Init();
	if(EnabledVideo())
	{
		Create_camera();
	}
	if(EnabledWeight()&&UI_DISPLAY_RESOLUTION==DISPPLAY_800_600)
	{
		I_DEV_Weight_Init();
	}
	if (TRUE==GetEnableIC())
	{
		echoic("启用了IC卡,开始初始化...");
		SyncToDo("SYNCREMOTE");  
		WF_IC_Init(    UI_Get_From_Handl( )  );

	}
	if(GetEnableCJIC())
	{
		ICCard_Load();
	}
	SetCloseDev();	
}
static void Init_SEM(void)
{	
	sem_init(&Device_semt,0,0); 
	InitImgSync();
	PostImgSync();
	postLogcSync();	
}


static Init_Config()
{
	LoadAppFunction();
	LoadCommunctionConfig();
	LoadGetParameterFileList();	
	LoadLanConfig();
	read_sys_ini_file();
	InitKeyBoard_KeyMap(); 
}
static Init_Parameter()
{

	LoadCurrentUseParameterVersionNumber();
	LoadParameter(ISLOADFIRST);	
	LoadLanKey();
}
static Init_MsgThread()
{
	DB_Init();	
	Init_UDP_Socket();
	Init_TCP_Socket();
}
static Init_Message()
{
	LoadMemSyncFile();
	InitMsgMsgGR();	
	InitMsgExitTR();	
	InitMsgExitBS();
	ReadBillNumber();	
}
//系统初始化
void init(void)
{	
      // build_all_conf_file();
	Init_SEM();
	Init_Config();
	Init_MsgThread();
	Init_Parameter();
	Init_DevInit();
	Init_Message();
    setLed();	
    SetWorkState( 0);	
	Setg_CurrentLaneState(10);	
    SendTCOMsg(MSGTCO_CMD_RETTIME, "");	//请求时间
    SendTCOMsg(MSGTCO_CMD_BILLNUMBER,"");	//请求票据号。CheckBilNumber用来决定是否使用服务器指定的票据号码
	SynOn=1;
	

}



void system_close(void)
{	
    serial_close(LED_COM);	
    I_DEV_Printer_Close();
    sem_destroy(&Device_semt);	
    return;
}

void readItemInsysConfigFile(char *SystemFile,char *ItemName ,char *ItemValue)
{	
    char *ini_addr_ptr;
    int len;
    ini_addr_ptr = strstr(SystemFile,ItemName);	
	if(ini_addr_ptr == NULL)
	{
		ItemValue[0] = '0';
		ItemValue[1] = 0x00;
		fprintf(stderr,"Load Config Item Error ItemName =<%s>",ItemName);
		return ItemValue;
	}
    ini_addr_ptr = strchr(ini_addr_ptr,'<')+1;
    len=strchr(ini_addr_ptr,'>')-ini_addr_ptr;
    strncpy(ItemValue,ini_addr_ptr,len);	
}


void read_sys_ini_file(void)
{	
    char read_ini_ptr[MAXSYSINI];
    int sysinifd;
    echoic("正在装载配置杂项...");
    memset(&sys_ini,0x00,sizeof(sys_ini));	
    sysinifd=open(LANEOLDCONFIG_FILE,O_RDONLY);	
    if(sysinifd<0)
    {	
        exit(0);	
    }
    lseek(sysinifd,SEEK_SET,0);	
    if(read(sysinifd,read_ini_ptr,MAXSYSINI)<0)
    {	
        close(sysinifd);	
        exit(0);	
    }
    close(sysinifd);	
    
    //[Simulate]
    readItemInsysConfigFile(read_ini_ptr,"SimulateEnabledCancel",sys_ini.SimulateEnabledCancel);	
    readItemInsysConfigFile(read_ini_ptr,"SimulateEnabledFistTuoChe",sys_ini.SimulateEnabledFistTuoChe);	



    //[ArrearageHand]
    readItemInsysConfigFile(read_ini_ptr,"MaxArrearageNumber",sys_ini.MaxArrearageNumber);	
    readItemInsysConfigFile(read_ini_ptr,"IsInPueArrearageCharege",sys_ini.IsInPueArrearageCharege);	

    //[CardMaxLengh]
    readItemInsysConfigFile(read_ini_ptr,"AbateMaxLengh",sys_ini.AbateMaxLengh);	
    readItemInsysConfigFile(read_ini_ptr,"MonthCardMaxLengh",sys_ini.MonthCardMaxLengh);	

    //[OnceOK]
    readItemInsysConfigFile(read_ini_ptr,"OneBitCarType",sys_ini.OneBitCarType);	
    readItemInsysConfigFile(read_ini_ptr,"OnceOkEnabledCancel",sys_ini.OnceOkEnabledCancel);	

    //[ProFunction]	
    readItemInsysConfigFile(read_ini_ptr,"EnabledLanGanKey",sys_ini.EnabledLanGanKey);	
    readItemInsysConfigFile(read_ini_ptr,"RushCancelTime",sys_ini.RushCancelTime);	

    //[LedFunction]
    readItemInsysConfigFile(read_ini_ptr,"LedSoundEnabled",sys_ini.LedSoundEnabled);	
    readItemInsysConfigFile(read_ini_ptr,"GoodBeySay",sys_ini.GoodBeySay);	
    readItemInsysConfigFile(read_ini_ptr,"HelloEnabled",sys_ini.HelloEnabled);	
    readItemInsysConfigFile(read_ini_ptr,"HelloSay",sys_ini.HelloSay);	
    readItemInsysConfigFile(read_ini_ptr,"SetVolume",sys_ini.SetVolume);	
  
	//[print]
	readItemInsysConfigFile(read_ini_ptr,"print_tty",sys_ini.print_tty);    

	readItemInsysConfigFile(read_ini_ptr,"reprintbillnum",sys_ini.reprintbillnum);  

	//[Led]
	readItemInsysConfigFile(read_ini_ptr,"led_tty",sys_ini.led_tty);    
	//ic卡
	readItemInsysConfigFile(read_ini_ptr,"csc_tty",sys_ini.csc_tty); 
	readItemInsysConfigFile(read_ini_ptr,"CSC_SPEED",sys_ini.CSC_SPEED);    
	//[weight]
	readItemInsysConfigFile(read_ini_ptr,"weight_tty",sys_ini.weight_tty); 
	readItemInsysConfigFile(read_ini_ptr,"weight_speed",sys_ini.weight_speed);   

	echoic("装载配置杂项完成");
}

char var_csccom[20];
char* GetCSCCOM(void)
{
	memset(var_csccom,0x00,20);
	sprintf(var_csccom,"/dev/COM%d",atoi(sys_ini.csc_tty));	
	echoic("IC卡串口:Com%d  速率 %s",atoi(sys_ini.csc_tty), (sys_ini.CSC_SPEED));
	return var_csccom;
}
char var_weightcom[20];
char * GetWeightCOM(void)
{
	memset(var_weightcom,0x00,20);
	sprintf(var_weightcom,"/dev/COM%d",atoi(sys_ini.weight_tty));
	echoic("计重设备串口:Com%d  速率 %s",atoi(sys_ini.weight_tty), (sys_ini.weight_speed));
	return var_weightcom;
}
//获得设备配置信息和一些业务配置信息
 struct  sys_ini_t *  GetSysConfig(void)
{
	return &sys_ini ;
}
