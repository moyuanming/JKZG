#ifndef __opinionValidateInformation_H__
#define __opinionValidateInformation_H__


int ChangCode(int nKey);
int Validate_Abate_Number(char *abateNumber);

void  HandOnceOK(int keyboardValue,int currentworkstate);
 void ShowInformatiom(int carTypeIndex,int carKindIndex,float spcCharge);
void ShowInformatiom_fee(void);
int  Validate_Car_Type_lane(void);
int Validate_Car_Kind(int keyboardValue);
void KeyPressHandl(int carTypeIndex,int carKindIndex,int currentworkstate);
int Validate_Abate_CarNumber(void);
#endif

