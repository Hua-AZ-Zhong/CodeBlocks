#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

const char* list[10]={"魏冬冬","赵午俊","王治达","陈尧尧","王贝贝","刘岳","刘超","谢飞","叶逊舜","牛高翔"};
int pos=0;//关键数据，用互斥量控制对它的访问
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;

void* func(void* p)
{
	for(;;){
		pthread_mutex_lock(&m);//访问pos前先加锁互斥量
		if(pos>=10) break;
		printf("%s号咨询美女为%s服务\n",(char*)p,list[pos]);
		pos++;
		pthread_mutex_unlock(&m);//访问完毕pos解锁
		sleep(8);//模拟服务时间
	}
	pthread_mutex_unlock(&m);//队列空了解锁互斥量
}

int main()
{
	pthread_t id1, id2, id3;
	pthread_create(&id1,NULL,func,"1");
	pthread_create(&id2,NULL,func,"2");
	pthread_create(&id3,NULL,func,"3");
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_join(id3,NULL);
}

