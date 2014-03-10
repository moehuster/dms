#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/*
 * 构建一个高速访问文件的场景,测试数据备份是否连续
 */
int main()
{
	double data = 1.0;
	char datastr[50]={0};
	for (;;){
		int fd=open("wtmpx.dat",O_RDWR|O_CREAT|O_APPEND,0644);
		if (fd==-1){
			perror("open");
			return 1;
		}
		sprintf(datastr,"%f\n",data);
		write(fd,datastr,strlen(datastr));
		data += 1.0;
		close(fd);
	}
}
