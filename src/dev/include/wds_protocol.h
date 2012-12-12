#ifndef __WDS_PROTOCOL_H__
#define __WDS_PROTOCOL_H__
#ifndef NULL
#define NULL 0
#endif

typedef struct wds_protocol {
	unsigned char * msg_data;
	unsigned char order_type;
	unsigned char msg_length;
} TWdsProtocol;
typedef TWdsProtocol * PTWdsProtocol;

void wds_setFD(int pfd);
void wds_Receive(void);
void wds_GetFirstWeightInfo(void);
void wds_GetTempWeightInfo(void);
void wds_GetCarNum(void);
void wds_GetWeightStat(void);
void wds_GetUpdateDateTime(void);
void wds_DropFirstInfo(void);
#endif
