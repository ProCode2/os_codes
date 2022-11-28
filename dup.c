#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>



int main(){

     int fd,fd1,fd2;
  fd=open("dupp.txt",O_RDONLY | O_RDWR ,0644);

  printf("1st fd =%d\n",fd);

  int r = write(fd,"I am a student\n",15);
  printf("%d", r);
 fd1=dup(fd);
 printf("2nd file descriptor=%d\n",fd1);
  write(fd1, "CEMK\n",5);
 fd2=dup2(fd1,6);
 printf("3rd file descriptor = %d\n",fd2);

 write(fd2,"Hello World\n",12);

  close(fd);
 close(fd1);
close(fd2);















}
