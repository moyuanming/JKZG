#include "LocalIncludeFile.h"
//	E 未付款(违章时)
//	D欠款
//	1
//	2 SVC
//	3公务
//	4月票
//	5信用卡
//	6军警
//	7绿色通道
//	8标准集装箱
//	9标准罐车
//	T 车队
char * GetMethodPayText(char Index)
{
	char *ret = "";
	switch (Index)
	{
	case  MP_NotPay		:
		ret = "未付款";
		break;
	case  MP_QIAN_KUAN	:
		ret = "欠款";
		break;
	case  MP_XIAN_JIN	:
		ret = "现金";
		break;
	case  MP_SVC		:
		ret = "SVC";
		break;
	case  MP_OFFICE		:
		ret = "公务";
		break;
	case  MP_MONTH		:
		ret = "月票";
		break;
	case  MP_CREDIT		:
		ret = "信用卡";
		break;
	case  MP_POLICE		:
		ret = "军警";
		break;
	case  MP_LVSETD		:
		ret = "绿色通道";
		break;
	case  MP_JI_ZHUANG_XIANG :
		ret = "集装箱";
		break;
	case  MP_GUAN_CHE		:
		ret = "罐车";
		break;
	case  MP_TEAM			:
		ret = "车队";
		break; 
	}
	return ret;

}

