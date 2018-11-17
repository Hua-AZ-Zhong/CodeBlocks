/*	话机：socket         
		绑定：bind
		多路：listen
		等待：accept           
		接通：新socket
总机等别的电话，分机跟客户通信
		通信：反复write/read   
		挂断分机：close          */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
struct Param{
	int fc;
	char ip[16];
};
void* func(void* p)
{
	struct Param* r = p;
	for(;;){
		char msg[1000];
		int n = read(r->fc, msg, sizeof(msg)-1);//读取来自客户端的信息
		if(n<=0) break;//检查是否出错、关闭
		if(msg[0]=='q') break;//q退出
		write(r->fc, msg, n);//原样回发到客户端
		msg[n] = '\0';//加上字符串结束标记
		printf("%s:%s\n",r->ip,msg);//显示
	}
	close(r->fc);
	printf("%s退出\n", r->ip);
	free(p);//释放动态内存
}

int main()
{
	int fd = socket(AF_INET,SOCK_STREAM,0);
	//AF_INET---v4,AF_INET6---v6;
	//SOCK_STREAM---tcp,SOCK_DGRAM---udp
	if(fd<0){perror("socket");return -1;}
	struct sockaddr_in si;//sockaddr_in6
	si.sin_family = AF_INET;
	si.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY就是0，表示本机IP地址
	si.sin_port = htons(8888);//1024以下的端口有专门用途
	//bind(int,sockaddr*,size_t);
	if(bind(fd,(struct sockaddr*)&si,sizeof(si))<0){
		perror("bind");return -1;}
	listen(fd, 10);//允许同时有10个接入请求
	for(;;){
		struct sockaddr_in c;
		socklen_t len=sizeof(c);//必须初始化成本地套接信息长度
		int fc = accept(fd,(struct sockaddr*)&c,&len);//等待客户连接，返回一个跟客户相连的新套接字
		if(fc<0) continue;
		char ip[16];
		inet_ntop(AF_INET,&c.sin_addr,ip,sizeof(ip));
		printf("%s到此一游\n", ip);
		char msg[1000];
		sprintf(msg, "YOUR IP: %s, welcome to network\n", ip);
		write(fc, msg, strlen(msg));
		//close(fc);
		pthread_t id;
		struct Param* p = malloc(sizeof(struct Param));
		p->fc = fc;
		strcpy(p->ip, ip);
		pthread_create(&id, NULL, func, p);
	}
}








