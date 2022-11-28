#include<stdio.h>
#include <stdlib.h>
#include<error.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<memory.h>

#define SERVER_FIFO "/tmp/addition_fifo_server"
#define MAX_NUMBERS 500

int main(){
    
   int fd,fd_client,bytes_read,i;
   char buf[4096];
   char *return_fifo;
   char *num[MAX_NUMBERS];

if ((mkfifo(SERVER_FIFO,0664) == -1) && (errno != EEXIST)){
      perror("mkfifo");
      exit(1);
    }
if ((fd =open(SERVER_FIFO,O_RDONLY))==-1)
     perror("open");

while(1){
      //get message
  memset(buf,'\0',sizeof(buf));

if ((bytes_read = read (fd,buf,sizeof(buf))) ==-1)
       perror("read");
if (bytes_read == 0)
     continue;


if(bytes_read > 0){

   return_fifo = strtok (buf, ", \n");
   i=0;
 num[i]=strtok(NULL, ", \n");
 while(num[i] != NULL && i< MAX_NUMBERS)
    num[++i]=strtok(NULL, ", \n");
 int total_numbers = i;
double sum =0;
unsigned int error = 0;
char *ptr;

for(i=0;i<total_numbers;i++){
    double f=strtod(num[i], &ptr);
if(*ptr){
  error = 1;
   break;
  }

 sum +=f;
  }

/* send result */


if((fd_client = open (return_fifo,O_WRONLY))==-1){
    perror("open : Client fifo");
    continue;

  }

if(error)
   sprintf(buf,"Error in input.\n");
 else
   sprintf(buf,"Sum = %.8g\n",sum);

 if(write(fd_client,buf,strlen(buf)) != strlen(buf))
     perror("write");
 if(close(fd_client) == -1)
    perror("close");
  }
 }
}




    








