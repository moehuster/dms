#ifndef  logreader_INC
#define  logreader_INC
#include "dms_data.h"
#include <list>
using std::list;
class LogReader{
private:
	char logFileName[50];
	char backFileName[50];
	char failLoginsFile[50];
	list<LogRec> logins;
	list<LogRec> logouts;
	list<MatchedLogRec> matches;
public:
	LogReader();
	~LogReader();
	list<MatchedLogRec> readLogs();
private:
	void backup();
	void readFailLogins();
	void readBackupFile();
	void matchLogRec();
	void saveFailLogins();
};
#endif   /* ----- #ifndef logreader_INC  ----- */
