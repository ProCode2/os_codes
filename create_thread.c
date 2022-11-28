#include<pthread.h>
#include<stdio.h>
void *func(void *str);
int main(){
    pthread_t thread;


    pthread_create(&thread, NULL, func, NULL);
    pthread_join(thread, NULL);

    printf("Main process\n");
    return 0;
}

void *func(void *str){
      printf("Inside thread\n");
}
