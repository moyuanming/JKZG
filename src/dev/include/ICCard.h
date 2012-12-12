

#ifndef __ICCard_H__
#define __ICCard_H__

typedef struct __GWCARDDATA
{
	unsigned char Version;    //版本号(0X10)
	unsigned char CityNo;	 //市编号
	unsigned char Plaza; 	 //收费站号(中心发的卡此处为0)
	unsigned char Usage; 	 //用途编号
	// 	0X10省中心发的公务卡
	// 	0X11市中心发的公务卡
	// 	0X12站发的公务卡
	// 	0X20省中心发的月票卡
	// 	0X21市中心发的月票卡
	// 	0X22站发的月票卡
	// 	0X50省中心发的优惠卡
	// 	0X51市中心发的优惠卡
	// 	0X52站发的优惠卡
	unsigned char CardSN[4];  //卡序列号(卡的实际序列号)
	unsigned char CardNo[4];	//卡号(8位BCD码表示)
	//公务卡号
	//月票卡号
	unsigned char BTime[7];   //启用时间(14位BCD码表示)YYYYMMDDHHMMSS
	unsigned char ETime[7];	//到期时间(14位BCD码表示)
	unsigned char Valid; 	 //IC卡状态(ASCII码1-使用中/0-无效)
	unsigned char PlateLen;   //车牌号长度
	unsigned char Plate[10];	//车牌号
	unsigned char CType; 	 //车型
	unsigned char Power; 	 //权限
	//0 省内
	//1 指定市
	//2 指定收费站
	unsigned char Area[10];	//免费区域
	unsigned char Percent;    //优惠率(2位BCD码表示)
	//01为表示为原价的1%，90为原价的99%
	unsigned char FeeMode[2];	//费额调整模式(2位BCD码表示)
	//最小单位为角，将进行过优惠的费额，用此数除后，对余数进行调整
	unsigned char Carry; 	 //进位方法，ASCII码表示
	//1四舍五入 2直接入 3直接舍
	unsigned char Character[20]; //车辆特征(2005-12-21修改)
	unsigned char Reserve[20];	//保留(可填任意数) (2005-12-21修改)
	unsigned char CRC[2];		//CRC(表达式为0X1021)
}Card;
Card * ICCard_GetCard(void);
int ICCard_UnLoad(void);
int ICCard_Load(void);
int ICCard_init(int pcom,long pspeed,long pe,char * pn);
int ICCard_getCard(void);
int ICCard_GetIsInit(void);
void ICCard_GetBCD(char * bcd,unsigned char * s,int len);
char * ICCard_GetBDate(void);
char * ICCard_GetEDate(void);
int ICCard_ValidateCardEndDate(time_t Currenttime);
int ICCard_ValidateCardStartDate(time_t Currenttime);
int ICCard_ValidateArea(void);
#endif
