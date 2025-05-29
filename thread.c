#include<unistd.h>
#include<pthread.h>
#include<stdio.h>

int count=0;
pthread_mutex_t lock;
void * threadfunc(void * args){
	pthread_mutex_lock(&lock);
	count++;
	printf("thread %d has started",count);
       sleep(1);
	printf("thread %d has finished",count);
 	pthread_mutex_unlock(&lock);

}
int main(){
	pthread_t t1,t2;
	pthread_mutex_init(&lock,NULL);
	pthread_create(&t2,NULL,&threadfunc,NULL);
	pthread_create(&t1,NULL,&threadfunc,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}

