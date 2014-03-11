#ifndef  dms_client_INC
#define  dms_client_INC
#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QTextBrowser>
#include <boost/shared_ptr.hpp>
using boost::shared_ptr;
class dmsClient : public QDialog{
	Q_OBJECT
private:
	shared_ptr<QTextBrowser> data;
	shared_ptr<QPushButton> start;
	shared_ptr<QPushButton> close;
public:
	dmsClient();
	~dmsClient();
public slots:
	//完成数据的发送和显示
	void startClient();
};
#endif   /* ----- #ifndef dms_client_INC  ----- */
