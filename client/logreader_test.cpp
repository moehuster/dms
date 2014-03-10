#include "logreader.h"

int main(int argc, char *argv[])
{
	LogReader logreader;
	list<MatchedLogRec> matches=logreader.readLogs();
}				/* ----------  end of function main  ---------- */
