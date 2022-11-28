#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *func(void *str);
int main(){
      pthread_t thread;
int a[2]={3,6};
  void *result;
    pthread_create(&thread,NULL,func,(void *)a);
   pthread_join(thread,&result);
     printf("main process\n");
       printf("Return from thread = %s\n",(char *)result);
  printf("\n");
    return 0;
  }

  void *func(void *str){
        int *r=str;

       int sum;
      sum=r[0]+r[1];
   printf("Thread \n");
    printf("Sum = %d\n",sum);

     pthread_exit("Sum calculated");
   }

