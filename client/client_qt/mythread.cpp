#include "mythread.h"

void myThread::run()
{
	sleep(5);
	emit mysig("send data to server 1");
	sleep(2);
	emit mysig("send data to server 2");
	sleep(2);
	emit mysig("send data to server 3");
	sleep(2);
	emit mysig("send data to server 4");
	sleep(2);
	emit mysig("send data to server 5");
	sleep(1);
	emit mysig("send over");
}
