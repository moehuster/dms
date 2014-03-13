#include "dms_client.h"

dmsClient::dmsClient():
	myth(new myThread()),
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
	connect(myth.get(),SIGNAL(mysig(QString)),this,SLOT(setData(QString)));
}

dmsClient::~dmsClient()
{
}

//完成数据的发送和显示
void dmsClient::startClient()
{
	data->append("client start");
	myth->start();
}

void dmsClient::setData(QString par)
{
	data->append(par);
}
