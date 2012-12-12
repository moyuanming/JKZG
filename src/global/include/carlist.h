#ifndef __CarList_H__
#define __CarList_H__

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1;
#endif

#ifndef FALSE
#define FALSE 0;
#endif

#ifndef echo
#define echo(fmt, args...)	  printf("ECHO:::: [%s:%d]: " fmt "\n", __FILE__, __LINE__ , ## args)
#endif

typedef void (*CarList_Change_Event_Func)(void);
void CarListInit(void);
void CarListDestroy(void);
void Car_QueuePop(void);
void Car_StackPop(void);

int Car_GetNum(void);
int Car_GetCarOverload(int carnum);
void Car_SetCarOverload(int carnum, int Overload);
int Car_GetCarSpeed(int carnum);
void Car_SetCarSpeed(int carnum, int Speed);
int Car_GetCarAcceleration(int carnum);
void Car_SetCarAcceleration(int carnum, int Acceleration);
int Car_GetCarAxlesNum(int carnum);
int Car_GetCarAxlesType(int carnum, int i);
void Car_SetCarAxlesType(int carnum, int i, int type);
int Car_GetCarAxlesWeight(int carnum, int i);
void Car_SetCarAxlesWeight(int carnum, int i, int weight);
int Car_GetCarAxlesSpace(int carnum, int i);
void Car_SetCarAxlesSpace(int carnum, int i, int Space);
void Car_CarAxlesClear(int carnum);
void Car_QueuePush(void);

int Car_Insert(int carnum);
int Axle_Insert(int carnum,int i);
void Axle_Delete(int carnum,int i);
void Car_Delete(int carnum);

int Car_GetCarListAxlesNum(void);
int Car_GetCarWeight(int carnum);
int Car_GetCarListWeight(void);

void Set_CarList_Change_Event(CarList_Change_Event_Func func) ;
void CarList_Change(void) ;
#endif
