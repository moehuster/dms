#ifndef  logdao_INC
#define  logdao_INC
#include "dms_data.h"
struct Logdao{
	void connect(char* pass);
	void savedata(MatchedLogRec& mlog);
	void commit();
	void disconnect();
};
#endif   /* ----- #ifndef logdao_INC  ----- */
