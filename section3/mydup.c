#include<stdio.h>
#include<unistd.h>
#include<limits.h>

#define MAXSIZEFD 6535

int mydup2(int fd1, int fd2)
{
	int fdmap[MAXSIZEFD]={0};
	int index = 0;
	if(fd1 == fd2)
		return fd2;
	close(fd2);

	while(1)
 	{
		int temp = dup(fd1);
		if( temp == fd2)
 		{
			while(index >=0)
			{
				close(fdmap[index]);
				index--;
 			}
			return temp;
		}
		fdmap[index] = temp;
		index++;
		if(index >= MAXSIZEFD)
		{
			for(;index >= 0; index--)
			{
				close(fdmap[index]);
 			}
			printf("is out of number of fd count in the systeme\n");
			break;
 		}
	}

	return -1;
}

int main(void)
{
	printf("test\n");
	int tem = mydup2(1,33);
	printf("%d\n",tem);
	return 0;
}
