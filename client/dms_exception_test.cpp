#include "dms_exception.h"
#include <cstdio>

int main(int argc, char *argv[])
{
	dmsException *e = new dmsClientException("dms client backup exception");
	puts(e->what());
}				/* ----------  end of function main  ---------- */
