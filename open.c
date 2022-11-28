#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


int main(){

  int fd,r,w;
 char buff[500];

 fd=open("open.txt",O_RDONLY);
 r= read(fd,buff,500);
 w=write(1,buff,r);

  if (w<0){
    printf("\n Error in write\n");
     exit(0);
  }



  return 0;
  }

