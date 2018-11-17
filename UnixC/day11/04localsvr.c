#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/un.h>
#include <pthread.h>
typedef struct sockaddr* sa;

int fds[8];
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;

void* input(void* p)
{
	for(;;){
		printf("input:");
		char text[1000];
		scanf(" %[^\n]",text);
		if(strcmp(text,"quit")==0) break;
		int i;
		pthread_mutex_lock(&m);
		for(i=0; i<8; i++){
			if(fds[i]!=0)
				write(fds[i],text,strlen(text));
		}
		pthread_mutex_unlock(&m);
	}
	close(*(int*)p);
	unlink("furong");
	pthread_mutex_destroy(&m);
	exit(0);//结束进程
}
int main()
{
	int fd = socket(AF_LOCAL,SOCK_STREAM,0);
	struct sockaddr_un s;
	s.sun_family = AF_LOCAL;
	strcpy(s.sun_path,"furong");
	if(bind(fd,(sa)&s,sizeof(s))<0){
		perror("bind");return -1;
	}
	listen(fd, 5);
	pthread_t id;
	pthread_create(&id,NULL,input,&fd);//输入和广播
	for(;;){//主线程只负责接受客户端连接
		socklen_t len=sizeof(s);
		int c = accept(fd, (sa)&s, &len);
		if(c<0) continue;
		int i;
		pthread_mutex_lock(&m);
		for(i=0; i<8&&fds[i]!=0; i++){}
		if(i==8) close(c);
		else fds[i] = c;
		pthread_mutex_unlock(&m);
	}
}










