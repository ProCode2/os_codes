#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<semaphore.h>

sem_t s;



void *fun1();
void *fun2();
 int count=7;
int main(){
   sem_init(&s,0,1);

   
   pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,fun1,NULL);

   pthread_create(&thread2,NULL,fun2,NULL);
   
    pthread_join(thread1,NULL);
    
     pthread_join(thread2,NULL);
     printf("Final value of Count = %d\n",count);
 
   return 0;
  }

  void *fun1(){
     int x;
 sem_wait(&s);
   x=count;
 printf("thread1 reads value of shared variable = %d\n",x);
   

    x++;

 printf("local updation by thread1 = %d\n",x);

    sleep(1);
  count=x;
 sem_post(&s);

 printf("value of shared value thread1 = %d\n\n\n",count);   
  }



void *fun2(){
     int y;

sem_wait(&s);
   y=count;
 printf("thread2 reads value of shared variable = %d\n",y);
   

    y--;

 printf("local updation by thread2 = %d\n",y);

    sleep(1);
  count=y;
 sem_post(&s);
 printf("value of shared value thread2 = %d\n\n\n",count);   
  }
