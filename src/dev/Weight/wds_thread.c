/*
 * wds_thread.c
 *
 *  Created on: 2011-3-30
 *      Author: root
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "serial.h"
#include "wds_protocol.h"
#include "wds_thread.h"

int wds_isRunning = 0;

void WDS_DLL_DevCheckThread(void) {
	//BOOL *p_isRunning = &m_isRunning;
	while (wds_isRunning) {
		wds_GetUpdateDateTime();
		wds_GetWeightStat();
		wds_GetCarNum();
		sleep(30);
	}
}

static pthread_t WdsWriteComThread;
int CreateDalWDSThreadWrite(void) {
	int ret;
	pthread_attr_t new_attr;
	pthread_attr_init(&new_attr);
	pthread_attr_setdetachstate(&new_attr, PTHREAD_CREATE_DETACHED);
	ret = pthread_create(&WdsWriteComThread, &new_attr,
			(void *) WDS_DLL_DevCheckThread, NULL);
	pthread_attr_destroy(&new_attr);
	return ret;
}

void WDS_DLL_ReceiveThread(void) {
	//BOOL *p_isRunning = &m_isRunning;
	while (wds_isRunning) {
		wds_Receive();
	}
}

static pthread_t WdsReadComThread;
int CreateDalWDSThreadRead(void) {
	int ret;
	pthread_attr_t new_attr;
	pthread_attr_init(&new_attr);
	pthread_attr_setdetachstate(&new_attr, PTHREAD_CREATE_DETACHED);
	ret = pthread_create(&WdsReadComThread, &new_attr,
			(void *) WDS_DLL_ReceiveThread, NULL);
	pthread_attr_destroy(&new_attr);
	return ret;
}

void Wds_Thead_Init(int fd) {
	wds_setFD(fd);
	wds_isRunning = 1;
}
void Wds_Run(int fd) {
	Wds_Thead_Init(fd);
	CreateDalWDSThreadRead();
	CreateDalWDSThreadWrite();
}
void Wds_Close(void) {
	wds_isRunning = 0;
}
