#include "dms_data.h"
#include <cstdio>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;
void* receive_data(void* par);

int main(int argc, char *argv[])
{
	int fd=socket(PF_INET, SOCK_STREAM, 0);
	if (fd==-1){
		perror("socket");
		return 1;
	}
	struct sockaddr_in addr;
	addr.sin_family = PF_INET;
	addr.sin_port = htons(8899);
	addr.sin_addr.s_addr = INADDR_ANY;
	int bfd=bind(fd,(sockaddr*)&addr,sizeof(addr));
	if (bfd==-1){
		perror("bind");
		return 2;
	}
	listen(fd,10);
	for (;;){
		struct sockaddr_in caddr;
		socklen_t clen=sizeof(caddr);
		int afd=accept(fd,(sockaddr*)&addr,&clen);
		if (afd==-1){
			perror("accept");
			return 3;
		}
		pthread_t pid;
		pthread_create(&pid,0,receive_data,&afd);
	}
	close(fd);
}				/* ----------  end of function main  ---------- */

void* receive_data(void* par)
{
	int fd=*((int*)par);
	MatchedLogRec mlog;
	for (;;){
		int rfd=recv(fd,&mlog,sizeof(mlog),0);
		if (rfd<=0) break;
		printf("%d: %s:%s\n",fd,mlog.logname,mlog.logip);
	}
	return (void*)close(fd);
}
