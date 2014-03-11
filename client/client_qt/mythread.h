#ifndef  mythread_INC
#define  mythread_INC
#include <QThread>
#include <QString>
class myThread : public QThread{
	Q_OBJECT
public:
	// 完成发送数据并发射信号
	void run();

public: signals:
	void mysig(QString data);
};
#endif   /* ----- #ifndef mythread_INC  ----- */
