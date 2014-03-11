#ifndef  dms_client_INC
#define  dms_client_INC
#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QTextBrowser>
#include <boost/shared_ptr.hpp>
#include "mythread.h"
using boost::shared_ptr;
class dmsClient : public QDialog{
	Q_OBJECT
private:
	shared_ptr<myThread> myth;
	shared_ptr<QTextBrowser> data;
	shared_ptr<QPushButton> start;
	shared_ptr<QPushButton> close;
public:
	dmsClient();
	~dmsClient();
public slots:
	//完成数据的发送和显示
	void startClient();
	void setData(QString par);
};
#endif   /* ----- #ifndef dms_client_INC  ----- */
