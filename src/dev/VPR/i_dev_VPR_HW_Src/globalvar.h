#ifndef GLOBALVAR_H_
#define GLOBALVAR_H_
extern int letListning;
extern int socket_fd_send;
extern int socket_fd_receive;
extern void *g_pvinfo;
int g_nIni = 0;
time_t g_tmStart;
extern pthread_mutex_t g_mutex;
#endif
