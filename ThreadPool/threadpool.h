#ifndef _THREADPOOL_H
#define _THREADPOOL_H

typedef struct ThreadPool ThreadPool;
// 创建线程池并初始化
ThreadPool *threadPoolCreate(int min, int max, int queueSize);

//销毁线程池
int threadPoolDestroy(ThreadPool* pool);

//给线程池添加任务
void threadPoolAdd(ThreadPool* pool,void(*func)(void*),void* arg);

//获取线程池中工作的线程的个数
int threadPoolBusyNum(ThreadPool* pool);

//获取线程池中活的线程的个数
int threadPoolAliveNum(ThreadPool* pool);

//工作线程
void* worker(void* arg);

void* manager(void* arg);

void threadExit(ThreadPool* pool);

#endif // !_THREADPOOL_H

