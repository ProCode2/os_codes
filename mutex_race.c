#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

pthread_mutex_t l;

void *fun1();
void *fun2();
 int count=7;
int main(){
    pthread_mutex_init(&l,NULL);

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
  pthread_mutex_lock(&l);
   x=count;
 printf("thread1 reads value of shared variable = %d\n",x);

    x++;

 printf("local updation by thread1 = %d\n",x);

    sleep(1);
  count=x;
  pthread_mutex_unlock(&l);

 printf("value of shared value thread1 = %d\n\n\n",count);   
  }



void *fun2(){
     int y;
  pthread_mutex_lock(&l);
   y=count;
 printf("thread2 reads value of shared variable = %d\n",y);

    y--;

 printf("local updation by thread2 = %d\n",y);

    sleep(1);
  count=y;
 pthread_mutex_unlock(&l);
 printf("value of shared value thread2 = %d\n\n\n",count);   
  }
