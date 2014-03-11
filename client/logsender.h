#ifndef  logsender_INC
#define  logsender_INC
#include "dms_data.h"
#include <list>
using std::list;
class LogSender{
private:
	char failSendFileName[50];
	int fd;
	unsigned short port;
	char serverip[20];
public:
	LogSender();
	~LogSender();
	void initNetwork();
	bool sendMatches(const MatchedLogRec& mlog);
	void sendMatches(list<MatchedLogRec>& matches);
	void readSendFailed(list<MatchedLogRec>& matches);
	void saveSendFailed(list<MatchedLogRec>& matches);
};

#endif   /* ----- #ifndef logsender_INC  ----- */
