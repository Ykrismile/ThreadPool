#include <stdio.h>
#include "threadpool.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
void taskFunc(void* arg) {
    int num = *(int*)arg;
    printf("thread is working ,number = %d,tid = %ld\n", num, pthread_self());
    sleep(1);
}

int main()
{
    ThreadPool* pool = threadPoolCreate(3, 10, 100);
    for (int i = 0; i < 100; i++) {
        int* num = (int*)malloc(sizeof(int));
        *num = i + 100;
        threadPoolAdd(pool, taskFunc, num);
    }
    sleep(10);
    threadPoolDestroy(pool);
    sleep(5);
    return 0;
}