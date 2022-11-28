#include<stdio.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	int fd[2],r,rv,buf[50];
	pipe(fd);
	rv=fork();
	if(rv==0)
	{
		close(fd[0]);
		write(fd[1],"hi\n",3);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		r=read(fd[0],buf,sizeof(buf));
		write(1,buf,r);
	}
	return 0;
}
