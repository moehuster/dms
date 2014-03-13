#ifndef  userdata_INC
#define  userdata_INC
#include "dms_data.h"
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class Producter{
private:
	int afd;
	void run();
	pthread_t tid;
	static void* recvdata(void* par);
public:
	Producter(int fd):afd(fd){}
	void start();
};

class Customer{
private:
	pthread_t tid;
	static void* senddata(void* par);
public:
	void start();
};
#endif   /* ----- #ifndef userdata_INC  ----- */
