#include "carlist.h"
#include "wds_protocol.h"
#include "Weight_InterFace.h"

Wds_CarWeightInfo * GetFirstCarWeightInfo(Wds_CarWeightInfo * cwi) {
	int i = 0;
	if (cwi == NULL && Car_GetNum() <= 0) {
		return NULL;
	}
	cwi->AxleNumber = Car_GetCarAxlesNum(0);
	cwi->Speed = Car_GetCarSpeed(0);
	cwi->TotalWeight = Car_GetCarWeight(0);

	cwi->AxleArry[10].AxleType = 0;
	cwi->AxleArry[10].AxleWeight = 0;
	for (i = 0; i < cwi->AxleNumber; i++) {
		if (i >= MAX_CAR_AXLE - 1) {
			cwi->AxleArry[10].AxleType += Car_GetCarAxlesType(0, i);
			cwi->AxleArry[10].AxleWeight += Car_GetCarAxlesWeight(0, i);
		} else {
			cwi->AxleArry[i].AxleType = Car_GetCarAxlesType(0, i);
			cwi->AxleArry[i].AxleWeight = Car_GetCarAxlesWeight(0, i);
		}
	}
	return cwi;

}
void Finishing(void) {
	if (0 == Car_GetCarAxlesNum(1)) {
		Car_Delete(1);
	}
	if (1 == Car_GetCarAxlesNum(1)) {
		Axle_Insert(1, 1);
	}
}
void RemoveFirstCarWeightInfo(void) {
	Car_QueuePop();
	CarList_Change();
}
void ModifyAxlesNo(int inputAxesNo) {
	if (Car_GetNum() > 0) {
		if (inputAxesNo > Car_GetCarListAxlesNum() || inputAxesNo <= 0) {
			return;
		}
		int i = 0, j = 0;
		int c = Car_GetCarAxlesNum(0);
		if (c > inputAxesNo)//轴数小于当前轴数 拆车
		{
			Car_Insert(1);
			Car_SetCarOverload(1, Car_GetCarOverload(0));
			Car_SetCarSpeed(1, Car_GetCarSpeed(0));
			Car_SetCarAcceleration(1, Car_GetCarAcceleration(0));
			for (i = inputAxesNo; i < c; i++) {
				Car_SetCarAxlesWeight(1, j, Car_GetCarAxlesWeight(0,
						inputAxesNo));
				Car_SetCarAxlesType(1, j, Car_GetCarAxlesType(0, inputAxesNo));
				Car_SetCarAxlesSpace(1, j, Car_GetCarAxlesSpace(0, inputAxesNo));
				Axle_Delete(0, inputAxesNo);
				j++;
			}
		} else if (c < inputAxesNo)//轴数大于当前轴数 向后面车扩展
		{
			for (i = c; i < inputAxesNo; i++) {
				if (0 == Car_GetCarAxlesNum(1)) {
					Car_Delete(1);
				}
				Car_SetCarAxlesWeight(0, i, Car_GetCarAxlesWeight(1, 0));
				Car_SetCarAxlesType(0, i, Car_GetCarAxlesType(1, 0));
				Car_SetCarAxlesSpace(0, i, Car_GetCarAxlesSpace(1, 0));
				Axle_Delete(1, 0);
			}
			Finishing();
		}
	}
	CarList_Change();
}
void ModfiyCarAxlesByWeight(int cn, int InputWeight) {

	int i = 0, j = 0, k = 0, c = 0;
	int tempWeight = 0;
	int carnum = cn;

	c = Car_GetCarAxlesNum(0);
	for (i = 0; i < c; i++) {
		if (carnum == cn) {
			tempWeight += Car_GetCarAxlesWeight(cn, i);
		}
		if (tempWeight >= InputWeight && carnum == cn) {
			Car_SetCarAxlesWeight(cn, i, Car_GetCarAxlesWeight(cn, i)
					- (tempWeight - InputWeight));
			carnum = cn + 1;
			Car_Insert(carnum);
			Car_SetCarOverload(carnum, Car_GetCarOverload(cn));
			Car_SetCarSpeed(carnum, Car_GetCarSpeed(cn));
			if (tempWeight - InputWeight != 0) {
				Car_SetCarAcceleration(carnum, Car_GetCarAcceleration(cn));
				Car_SetCarAxlesWeight(carnum, j, tempWeight - InputWeight);
				Car_SetCarAxlesType(carnum, j, Car_GetCarAxlesType(cn, i));
				Car_SetCarAxlesSpace(carnum, j, Car_GetCarAxlesSpace(cn, i));
				j++;
			}
			k = i + 1;
		} else if (carnum == cn + 1) {
			Car_SetCarAxlesWeight(carnum, j, Car_GetCarAxlesWeight(cn, k));
			Car_SetCarAxlesType(carnum, j, Car_GetCarAxlesType(cn, k));
			Car_SetCarAxlesSpace(carnum, j, Car_GetCarAxlesSpace(cn, k));
			Axle_Delete(cn, k);
			j++;
		}
	}
	Finishing();
	CarList_Change();
}
void ModfiyAxlesByWeight(int InputWeight) {
	int i = 0;
	int tempWeight = 0;
	int axle = 0;
	if (Car_GetNum() > 0) {
		if (InputWeight > Car_GetCarListWeight() || InputWeight <= 0) {
			return;
		}
		if (InputWeight <= Car_GetCarWeight(0)) {//拆车
			ModfiyCarAxlesByWeight(0, InputWeight);
		} else {
			do {
				tempWeight += Car_GetCarWeight(i);
				axle += Car_GetCarAxlesNum(i++);
			} while (tempWeight < InputWeight);
			ModifyAxlesNo(axle);//合并轴
			ModfiyCarAxlesByWeight(0, InputWeight);//拆分重量
		}
	}
	CarList_Change();
}
void AddAxleByIndex(int index, Wds_AxleInfo *Axle) {
	Axle_Insert(0, index);
	Car_SetCarAxlesType(0, index, Axle->TiresType);
	Car_SetCarAxlesWeight(0, index, Axle->AxleWeight);
	CarList_Change();
}
void RemoveAxleByIndex(int index) {
	Axle_Delete(0, index);
	CarList_Change();
}
void AddCarWeightInfo(Wds_CarWeightInfo *CarWeightInfo) {
	Car_Insert(0);
	Car_SetCarSpeed(0, CarWeightInfo->Speed);
	int i = 0;
	for (i = 0; i < CarWeightInfo->AxleNumber; i++) {
		if (i < MAX_CAR_AXLE) {
			Car_SetCarAxlesType(0, i, CarWeightInfo->AxleArry[i].TiresType);
			Car_SetCarAxlesWeight(0, i, CarWeightInfo->AxleArry[i].AxleWeight);
		} else {
			Axle_Insert(0, i);
		}
	}
	CarList_Change();
}
