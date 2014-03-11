#include "logsender.h"
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

LogSender::LogSender():port(8899)
{
	strcpy(failSendFileName,"sendfail.dat");
	strcpy(serverip,"127.0.0.1");
}

LogSender::~LogSender()
{
}

bool LogSender::sendMatches(const MatchedLogRec& mlog)
{
	int sfd=send(fd,&mlog,sizeof(mlog),0);
	return sfd<=0?false:true;
}

void LogSender::sendMatches(list<MatchedLogRec>& matches)
{
	readSendFailed(matches);
	initNetwork();
	//循环发送数据,发送一条就删除一条
	while (matches.size()){
		send(fd,&matches.front(),sizeof(MatchedLogRec),0);
		matches.pop_front();
	}
	saveSendFailed(matches);
}

void LogSender::initNetwork()
{
	fd=socket(PF_INET,SOCK_STREAM,0);
	if (fd==-1){
		perror("socket");
		return;
	}
	struct sockaddr_in addr;
	addr.sin_family=PF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr=inet_addr(serverip);
	int cfd=connect(fd,(sockaddr*)&addr,sizeof(addr));
	if (cfd==-1){
		perror("connect");
		return;
	}
}

void LogSender::readSendFailed(list<MatchedLogRec>& matches)
{
}

void LogSender::saveSendFailed(list<MatchedLogRec>& matches)
{
	close(fd);
}
