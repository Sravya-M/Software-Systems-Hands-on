/*
MT2019114
Run this program like gcc 06.c -lpthread
pthread_create is creating the thread.
pthread_join - function waits for thread specified by thread to terminate. If that thread has already terminated, then pthread_join returns immediately.
*/  

#include <pthread.h>
#include <stdio.h>

void thread_func(void){
	printf("Thread id is %lu\n", pthread_self());
}

int main(void){
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_create ( &thread1, NULL, (void *) thread_func, NULL);
	pthread_create ( &thread2, NULL, (void *) thread_func, NULL);
	pthread_create ( &thread3, NULL, (void *) thread_func, NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
	return 0;
}
