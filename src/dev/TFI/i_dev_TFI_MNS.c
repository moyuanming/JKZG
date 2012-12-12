#include "LocalIncludeFile.h"
/* 石河子公路局 玛纳斯收费站 老费显协议 */
/* 显示费额  0A  46  C1  F1  F2  F3  0D */
unsigned char ShowCmd[7] = {0x0A,0x46,0x01,0x00,0x00,0x05,0x0D};	
void  TFI_MNS_LedShow ( char CarType , int charge )
{
	unsigned char C_charge[3] ;
	sprintf(C_charge,"%03d",charge);
	ShowCmd[2]=CarType;
	ShowCmd[3]=C_charge[0];
	ShowCmd[4]=C_charge[1];
	ShowCmd[5]=C_charge[2];
	echoic("MNSTFIShow <%0x %0x %0x %0x %0x %0x %0x>",
		ShowCmd[0],
		ShowCmd[1],
		ShowCmd[2],
		ShowCmd[3],
		ShowCmd[4],
		ShowCmd[5],
		ShowCmd[6]);
	serial_write(LED_COM,ShowCmd,7);	
}
/*清屏命令：0A  B  0D*/
unsigned char ClearCmd[3] = {0x0A,  0x0B,  0x0D};
void   TFI_MNS_clean ( )
{
	serial_write(LED_COM,ClearCmd,3);
}

