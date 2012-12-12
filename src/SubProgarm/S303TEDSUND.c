#include "LocalIncludeFile.h"
BOOL U_SBtn_Flag=0;
int main(int args, const char* arg[])
{
	
	if(args == 3)
	{
		int ComNo = atoi(arg[1]);
		int Sund = atoi(arg[2]);
		unsigned char SoundNUMBER[4] = {0x0A,0x46,0x15,0x00};
		unsigned char Hello[4] = {0x0A, 0x46, 0x0E,0x00};
		SoundNUMBER[2] +=Sund;
		if(serial_init(ComNo,B9600)<0)
		{	
			echo("费显串口初始化失败,检查收费程序是否关闭！");	
			return;
		}
		serial_write(ComNo,SoundNUMBER,4);
		printf("成功设置【%d】端口费显显示音量为【%d】\n请听3秒钟后的音量！\n",ComNo,Sund);
		sleep(3);
		serial_write(ComNo,Hello,4);
		

	}
	else
	{
		printf(	"参数传递不正确,第一个参数为串口号第二参数为音量，音量1到7 1表示最大音量!\n",args);
	}
}