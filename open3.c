#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
 int fd,w,r,r1,len;
 char buff[30],buff1[15];
 w= write(1,"enter the  data\n",15);
     printf("\n");   

 if (w<0){
    printf("\n Error in write\n");
     exit(0);
  }

 r=read(0,buff,30);


  len=strlen(buff1);
  buff1[len-1]='\0';

 fd=open(buff1,O_CREAT|O_WRONLY,0664);

write(1,"Enter your file name\n",21);

r1=read(0,buff1,15);



 write(fd,buff1,r1);
  return 0;
  }


