#ifndef  dms_exception_INC
#define  dms_exception_INC
#include <cstring>
#include <exception>
using std::exception;

class dmsException : public exception{
private:
	char msg[128];
public:
	dmsException(){strcpy(msg,"dms exception");}
	dmsException(const char* str){strcpy(msg,str);}
	const char* what()const throw(){return msg;}
};

class dmsClientException : public dmsException{
public:
	dmsClientException(const char* str):dmsException(str){}
	dmsClientException():dmsException("dms client exception"){}
};

class dmsMatchException : public dmsClientException{
public:
	dmsMatchException(const char* str):dmsClientException(str){}
	dmsMatchException():dmsClientException("dms match exception"){}
};
#endif   /* ----- #ifndef dms_exception_INC  ----- */
