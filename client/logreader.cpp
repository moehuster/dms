#include "logreader.h"
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <arpa/inet.h>
using namespace std;

LogReader::LogReader()
{
	puts("LogReader()");
}

LogReader::~LogReader()
{
	puts("~LogReader()");
}

list<MatchedLogRec> LogReader::readLogs()
{
	backup();
	readFailLogins();
	readBackupFile();
	printf("logins:%zu\n",logins.size());
	printf("logouts:%zu\n",logouts.size());
	matchLogRec();
	printf("matches:%zu\n",matches.size());
	printf("logins:%zu\n",logins.size());
	printf("logouts:%zu\n",logouts.size());
	saveFailLogins();
	return matches;
}

void LogReader::backup()
{
	puts("1. backup log file");
	strcpy(backFileName,"wtmpx");
}

void LogReader::readFailLogins()
{
	puts("2. read fail logins file");
}

void LogReader::readBackupFile()
{
	puts("3. read backup log file");
	// logtype-7: logins
	// logtype-8: logouts
	int fd=open(backFileName,O_RDONLY);
	if (fd==-1){
		perror("open");
		return;
	}
	struct stat flog={0};
	fstat(fd,&flog);
	printf("%zu\n",flog.st_size);
	int count=flog.st_size/372;
	LogRec log;
	for (int i=0; i<count; ++i){
		read(fd,&log.logname,32);//login name
		lseek(fd,36,SEEK_CUR);
		read(fd,&log.pid,4);     //process id
		log.pid=htonl(log.pid);
		read(fd,&log.logtype,2); //logtype
		log.logtype=htons(log.logtype);
		lseek(fd,6,SEEK_CUR);
		read(fd,&log.logtime,4); //logtime(msc)
		log.logtime=htonl(log.logtime);
		lseek(fd,30,SEEK_CUR);
		read(fd,&log.logip,257); //login ip
		lseek(fd,1,SEEK_CUR);
		printf("%s: %hd\n",log.logname,log.logtype);
		if (log.logname[0]!='.'){
			if (log.logtype==7)
				logins.push_back(log);
			else if (log.logtype==8)
				logouts.push_back(log);
		}
	}
	close(fd);
}

void LogReader::matchLogRec()
{
	puts("4. match log record");
	/*
	 * 1. 从登出集合中循环取出一条登出记录
	 * 2. 在登入集合中循环查找
	 * 3. 找到匹配记录,加入匹配集合,删除登入记录
	 * 4. 如果本次没找到,继续查找,直到查找结束
	 * 5. 清空登出集合
	 */
	typedef list<LogRec>::iterator iter;
	for (iter oit=logouts.begin(); oit!=logouts.end(); ++oit){
		for (iter iit=logins.begin(); iit!=logins.end(); ++iit){
			if (!strcmp(iit->logname,oit->logname) &&
				iit->pid == oit->pid &&
				!strcmp(iit->logip,oit->logip)){
				MatchedLogRec mlog;
				strcpy(mlog.logname, iit->logname);
				mlog.pid = iit->pid;
				mlog.logintime = iit->logtime;
				mlog.logouttime = oit->logtime;
				mlog.durations = oit->logtime-iit->logtime;
				strcpy(mlog.logip,iit->logip);
				matches.push_back(mlog);
				logins.erase(iit);
				break;
			}
		}
	}
	logouts.clear();
}

void LogReader::saveFailLogins()
{
	puts("5. save fail logins");
}
