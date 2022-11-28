#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


int main(){
 int fd,w,r;
 char buff[30];
 w= write(1,"enter the  data\n",15);
     printf("\n");   

 if (w<0){
    printf("\n Error in write\n");
     exit(0);
  }

 r=read(0,buff,30);
 

fd=open("target.txt",O_CREAT|O_WRONLY,0664);

write(fd,buff,r);
  return 0;
  }

