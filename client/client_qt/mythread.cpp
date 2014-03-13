#include <cstdio>
#include "mythread.h"
#include "logreader.h"
#include "logsender.h"

void myThread::run()
{
	LogReader logreader;
	LogSender logsender;
	list<MatchedLogRec> matches=logreader.readLogs();
	logsender.initNetwork();
	char buf[128];
	while (matches.size()){
		sleep(1);
		MatchedLogRec mlog=matches.front();
		if (!logsender.sendMatches(mlog)) break;
		sprintf(buf,"%s:%d:%s",mlog.logname,mlog.pid,mlog.logip);
		emit mysig(QString(buf));
		matches.pop_front();
	}
	//保存发送失败数据并关闭连接
	logsender.saveSendFailed(matches);
}
