#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<error.h>
int set_fl(int fd, int flags)
{
	int val;
	if((var = fcntl(fd, F_GETFL, 0)) < 0)
	{
		printf("fcntl F_GETFL error\n");
		exit(1);
	}
	val |= flags;
	if(fcntl(fd, F_SETFL, val) < 0)
	{
		printf("fcntl F_SETFL error\n");
		exit(1);
	}
	return 0;


}

int main(int argc, char* argv[])
{
	int fd;
	int flage = 0;
	if(argc != 3)
	{
		printf("Usage:my argument1 argument2\n");
		eixt(1);
	}
	if((fd = open(argv[1])) < 0)
	{
		printf("open the file %s failed\n",argv[1]);
		exit(1);
	}
	if(:)
}
