#include<stdio.h>
#include<pthread.h>
const int NUM_THREAD = 5;

void *PrintHello(void *threadID) {
    int tid =(int)threadID;
    printf("hello,I am thread %d\n",tid);
    pthread_exit(NULL);
    return NULL;
}
int _tmian(int argc,char *argv[])
{
    pthread_t thread[NUM_THREAD];
    int rc;
    for(int t=0;t< NUM_THREAD;t++){
        printf("Creating thread %d\n", t);
        rc = pthread_create(&thread[t],NULL,PrintHello,(void*)t);
    }
    pthread_exit(NULL);
    return 0;
}