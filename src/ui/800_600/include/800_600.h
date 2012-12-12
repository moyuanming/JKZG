#ifndef __800_600_H__
#define __800_600_H__

RECT RtBaojing = { 5 , 11 , 50 , 54 } ;
RECT RtJiaotong = { 5 , 54 , 50 , 91 } ;
RECT RtLangan = { 50 , 12 , 128 , 91 } ;
RECT RtZhuaPaiXianQuan = { 164 , 12 , 203 , 44 } ;
RECT RtTongGuoXianQuan = { 164 , 55 , 203 , 87 } ;
RECT RtZhuaPaiXianQuanText = { 132 , 20 , 156 , 44 } ;
RECT RtTongGuoXianQuanText = { 132 , 62 , 156 , 86 } ;
RECT RtYupeng = { 5 , 17 , 69 , 81 } ;
RECT RtPrint = { 75 , 17 , 180 , 72 } ;
//编辑框
RECT RtCarText = { 4 , 25 , 167 , 47 } ; //车辆文本框
RECT RtEquipmentState = { 583 , 25 , 795 , 47 } ; //设备状态文本框
RECT RtEnterInfoText = { 171 , 25 , 338 , 47 } ;//入口信息
RECT RtPassChargeText = { 342 , 25 , 459 , 47 } ; //通行费
RECT RtPaymentText = { 463 , 25 , 580 , 47 } ; //付款

//第二行
RECT RtCarTextInfo = { 4 , 51 , 167 , 148 } ; //车辆信息框
RECT RtEquipmentStateInfo = { 583 , 51 , 795 , 148 } ;//设备状态信息框
RECT RtEnterInfo = { 171 , 51 , 338 , 148 } ; //入口信息
RECT RtPassChargeInfo = { 342 , 51 , 459 , 148 } ; //通行费信息
RECT RtPaymentInfo = { 463 , 51 , 580 , 148 } ; //付款信息

//第三行
RECT RtCarNoInfo = { 4 , 152 , 167 , 170 } ;
RECT RtRorwardEnterInfo = { 171 , 152 , 338 , 170 } ;
RECT RtForwardChargeInfo = { 342 , 152 , 459 , 170 } ;
RECT RtForwardPaymentInfo = { 463 , 152 , 580 , 170 } ;

RECT RtPassCarNum = { 583 , 152 , 620 , 170 } ;
RECT RtAutoLanganState = { 624 , 152 , 682 , 170 } ;
RECT RtWeightInfo = { 685 , 152 , 795 , 170 } ;

//第四行
//线
RECT RtOperateInfo = { 4 , 180 , 356 , 203 } ;
RECT RtWorkMode1 = { 360 , 180 , 529 , 203 } ;
RECT RtWorkMode2 = { 533 , 180 , 682 , 203 } ;
RECT RtCurrentWeightInfo = { 685 , 180 , 795 , 203 } ;

RECT RtInformation = { 4 , 208 , 356 , 305 } ;

RECT RtVideo = { 4 , 308 , 356 , 596 } ;//352,288

RECT RtInputDataArea = { 360 , 208 , 682 , 481 } ;

RECT RtCurrentTime = { 360 , 484 , 682 , 506 } ;

RECT RtArrivedCarWeightInfo = { 685 , 208 , 795 , 506 } ;

RECT RtCardBoxInfo = { 360 , 509 , 795 , 596 } ;

//事件
RECT RtEvent = { 180 , 17 , 425 , 72 } ;
RECT RtEventText = { 180 , 1 , 425 , 16 } ;

//用户名
RECT RtLoginUSRPanel = { 5+40 , 5+20 , 205+40 , 50+20 } ;
RECT RtLoginUSR = { 5 , 5 , 180 , 25 } ;
RECT RtLoginPWDPanel = { 5+40 , 10+20+50 , 205+40 , 5+20+50 +50} ;
RECT RtLoginPWD = { 5 , 5 , 180 , 25 } ;

//菜单选项
RECT RtMenu = {45,25,245,170};

/***************************************************************
 *声明类开关量信号位图
 ***************************************************************/
BITMAP bmSLstop ;
BITMAP bmBaojingG , bmBaojingA , bmAutoLanganDown , bmAutoLanganUp , bmYupengR , bmCarArrived , bmJiaotongR ,
        bmJiaotongG , bmCarGo , bmGuanggeArrived , bmYupengG , bmHandLanganUp , bmHandLanganDown , bmGuanggeGo , bmLup ,axlet1,axlet2,axlet3;
/***************************************************************
 *声明类信号按钮
 ***************************************************************/

#endif 

