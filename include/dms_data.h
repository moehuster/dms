#ifndef  dms_data_INC
#define  dms_data_INC
// login and logout records
struct LogRec{
	char logname[32];
	int pid;
	short logtype;
	int logtime;
	char logip[257];
};
// matched records
struct MatchedLogRec{
	char logname[32];
	int pid;
	int logintime;
	int logouttime;
	int durations;
	char logip[257];
	char labip[20];
};
#endif   /* ----- #ifndef dms_data_INC  ----- */
