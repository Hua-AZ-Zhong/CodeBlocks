#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
int flag=0;
pthread_mutex_t m;
pthread_cond_t c=PTHREAD_COND_INITIALIZER;
void* thread1(void* p)
{
	for(;;){
		pthread_mutex_lock(&m);
		if(flag==0)
			pthread_cond_wait(&c,&m);//进入等待，自动解锁互斥量，等到通知后加锁互斥量，结束等待
		pthread_mutex_unlock(&m);
		write(1,p,1);
		sleep(1);
	}
}
int main()
{
	pthread_t id1, id2;
	pthread_mutex_init(&m,NULL);
	pthread_create(&id1, NULL, thread1, ".");
	pthread_create(&id2, NULL, thread1, "*");
	for(;;){
		char ch;
		scanf(" %c", &ch);
		pthread_mutex_lock(&m);
		if(ch=='a') flag=1,pthread_cond_signal(&c);
		else if(ch=='b') flag=1,pthread_cond_broadcast(&c);
		else flag=0;
		pthread_mutex_unlock(&m);
	}
}

