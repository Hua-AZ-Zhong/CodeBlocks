#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>//for isxxx(char)
typedef struct sockaddr* sa;
typedef struct {
	int s;
	char ip[16];
}client;
#define MAX 100
client cs[MAX];
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
void broadcast(int c, void* msg, int n)
{
	write(STDOUT_FILENO,msg,n);
	pthread_mutex_lock(&m);
	int i;
	for(i=0; i<MAX; i++){
		if(cs[i].s!=0&&cs[i].s!=c)
			write(cs[i].s,msg,n);
	}
	pthread_mutex_unlock(&m);
}
void* func(void* p)
{
	client* q = p;
	char ip[16];
	pthread_mutex_lock(&m);
	int c = q->s;
	strcpy(ip, q->ip);
	pthread_mutex_unlock(&m);
	char msg[1000];
	int n = sprintf(msg, "欢迎%s进入房间\n",ip);
	broadcast(0,msg,n);//对所有客户端广播
	int iplen = sprintf(msg, "%s说:", ip);
	char* info = msg+iplen;//info指向冒号后面
	for(;;){
		int len = read(c,info,sizeof(msg)-iplen);
		if(len<=0) break;
		if(info[0]=='q'&&isspace(info[1])) break;
		broadcast(c,msg,len+iplen);
	}
	pthread_mutex_lock(&m);
	q->s = 0;
	pthread_mutex_unlock(&m);
	close(c);
	n = sprintf(msg, "%s离开了\n", ip);
	broadcast(0,msg,n);
}
int main()
{
	int s = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in si;
	si.sin_family = AF_INET;
	si.sin_addr.s_addr = INADDR_ANY;
	si.sin_port = htons(8888);
	if(bind(s,(sa)&si,sizeof(si))<0){
		perror("bind");return -1;
	}
	listen(s, 5);
	for(;;){
		socklen_t len = sizeof(si);
		int c = accept(s,(sa)&si,&len);
		if(c<0) continue;
		int i;
		pthread_mutex_lock(&m);
		for(i=0; i<MAX&&cs[i].s!=0; i++){}
		if(i==MAX){
			write(c,"full\n",5);close(c);
		}
		else{
			cs[i].s = c;
			inet_ntop(AF_INET,&si.sin_addr,cs[i].ip,16);
			pthread_t id;
			pthread_create(&id, NULL, func, &cs[i]);
		}
		pthread_mutex_unlock(&m);
	}



}








