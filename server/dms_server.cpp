#include "userdata.h"
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

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
	Customer cust;
	cust.start();
	for (;;){
		struct sockaddr_in caddr;
		socklen_t clen=sizeof(caddr);
		int afd=accept(fd,(sockaddr*)&addr,&clen);
		if (afd==-1){
			perror("accept");
			return 3;
		}
		Producter prod(afd);
		prod.start();
	}
	close(fd);
}				/* ----------  end of function main  ---------- */
