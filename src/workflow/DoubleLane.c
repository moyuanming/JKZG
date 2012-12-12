#include "LocalIncludeFile.h"
int CarCount = 0;
int GetFrontCar()
{
	return CarCount;
}
void  SetFrontCar(int Input)
{
	 CarCount = Input;
}
void AddPasdCar()
{
	CarCount++;
}
void MinusPasdCar()
{
	CarCount = 	--CarCount <0 ? 0:CarCount;	
}
void HandleFrontMsg()
{
	if(GetFunDoubleLane() && GetFunControlLane())
	{	 
		if(GetWorkState() == 3 && Getg_bZhuaPaiXianQuan() == FALSE)
		{
			SetPassCar();
		}
		else
		{
			AddPasdCar();
		}
	}
}