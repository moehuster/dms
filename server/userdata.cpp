#include <deque>
#include <cstdio>
#include <unistd.h>
#include "userdata.h"

static std::deque<MatchedLogRec> datas;
static pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  pcon=PTHREAD_COND_INITIALIZER;
static pthread_cond_t  ccon=PTHREAD_COND_INITIALIZER;

void* Producter::recvdata(void* par)
{   //线程函数没有this指针
	((Producter*)par)->run();
	return NULL;
}

void Producter::start()
{
	pthread_create(&tid,0,recvdata,this);
}

void Producter::run()
{
	int rfd;
	MatchedLogRec mlog;
	while ((rfd=recv(afd,&mlog,sizeof(mlog),0))>0){
		printf("%d: %s:%s\n",afd,mlog.logname,mlog.logip);
		pthread_mutex_lock(&mutex);
		while (datas.size()>10240)
			pthread_cond_wait(&pcon,&mutex);
		datas.push_back(mlog);
		pthread_cond_signal(&ccon);
		pthread_mutex_unlock(&mutex);
	}
	close(afd);
}

void* Customer::senddata(void* par)
{
//	LogDao logdao;
//	logdao.connect("user/pass");
//	for (;;){
//		logdao.savedata();
//		logdao.commit();
//	}
//	logdao.disconnect();
	pthread_mutex_lock(&mutex);
	while (datas.empty())
		pthread_cond_wait(&ccon,&mutex);
	MatchedLogRec mlog=datas.front();
	datas.pop_front();
	pthread_cond_broadcast(&pcon);
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void Customer::start()
{
	pthread_create(&tid,0,senddata,NULL);
}
