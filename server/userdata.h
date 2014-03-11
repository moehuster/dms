#ifndef  databuffer_INC
#define  databuffer_INC
#include "dms_data.h"
#include <cstdio>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
class Producter{
private:
	int afd;
	pthread_t tid;
	void run();
	static void* recvdata(void* par)
	{   //线程函数没有this指针
		((Producter*)par)->run();
		return NULL;
	}
public:
	Producter(int fd):afd(fd){}
	void start()
	{
		pthread_create(&tid,0,recvdata,this);
	}
};
void Producter::run()
{
	MatchedLogRec mlog;
	for (;;){
		int rfd=recv(afd,&mlog,sizeof(mlog),0);
		if (rfd<=0) break;
		printf("%d: %s:%s\n",afd,mlog.logname,mlog.logip);
	}
	close(afd);
}
#endif   /* ----- #ifndef databuffer_INC  ----- */
