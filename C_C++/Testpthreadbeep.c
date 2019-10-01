#include<stdio.h>
#include<pthread.h>
#include<windows.h>
void *beep(void)
{
    Beep(500,10000);
    printf("Hello World");
    pthread_exit(NULL);
}
int main(){

     pthread_t threads;
     pthread_create(&threads, NULL, beep,(void *)0);
     Sleep (10000);
}