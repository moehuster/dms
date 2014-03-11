#include "dms_client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc,argv);
	dmsClient dmsc;
	dmsc.show();
	return app.exec();
}				/* ----------  end of function main  ---------- */
