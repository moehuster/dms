#include "logreader.h"
#include "logsender.h"

int main(int argc, char *argv[])
{
	LogReader logreader;
	LogSender logsender;
	list<MatchedLogRec> matches = logreader.readLogs();
	logsender.sendMatches(matches);
}				/* ----------  end of function main  ---------- */
