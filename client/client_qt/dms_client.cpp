#include "dms_client.h"

dmsClient::dmsClient():
	data(new QTextBrowser(this)),
	start(new QPushButton("start",this)),
	close(new QPushButton("close",this))
{
	this->resize(500,600);
	data->resize(460,460);
	data->move(20,20);
	start->move(150,540);
	close->move(300,540);
	connect(close.get(),SIGNAL(clicked()),this,SLOT(close()));
	connect(start.get(),SIGNAL(clicked()),this,SLOT(startClient()));
}

dmsClient::~dmsClient()
{
}

void dmsClient::startClient()
{
	data->append("client start");
	sleep(10);
	data->append("send data to server");
	sleep(10);
	data->append("client stop");
}
