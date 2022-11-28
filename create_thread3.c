#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *func(void *str);
int main(){
      pthread_t thread;


    pthread_create(&thread,NULL,func,NULL);
   pthread_join(thread,NULL);
     printf("main process\n");
     for(int i=20; i<=24;i++){
      sleep(1);
     printf("%d\t",i);
    }
  printf("\n");
    return 0;
  }

  void *func(void *str){
   printf("Thread \n");
     for(int i=0;i<=4;i++){     
          sleep(1);   
 printf("%d\t",i);
     }
    printf("\n");
   }

