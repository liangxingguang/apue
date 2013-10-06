#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int fd, var;
//	char filename[256];
	if(argc != 2)
	{
		perror("--");
		printf("please input filename \n");
	}
//	filename = argv[1];
	if((var = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
	{
		strerror(errno);
		printf("fcntl file error\n");
	}

	switch(var & O_ACCMODE)
	{
		case O_RDONLY:
			printf("Read only\n");
			break;
		case O_WRONLY:
			printf("Write only\n");
			break;
		case O_RDWR:
			printf("Read and Write\n");
			break;
		default:
			break;
	}

	if(var & O_APPEND)
	{
		printf("append\n");
	}
	if(var & O_NONBLOCK)
	{
		printf("noblocking");
	}
	exit(0);
}
