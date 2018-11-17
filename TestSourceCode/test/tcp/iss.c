/*************************************************************************
> File Name: tcpserver.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年03月23日 星期一 17时33分33秒
*************************************************************************/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "Convert.h"

struct Param
{
	int fc;
	char ip[16];
};

void* func(void* p)
{
	struct Param* r = p;
	int fn = open("back.txt", O_RDWR|O_CREAT, 0777);
	for(;;)
	{
		char msg[10000000];
	/*	char buf[10000000];*/
		int n = recv(r->fc, msg, sizeof(msg)-1, 0);
		if(n <= 0) 
			break;
		send(r->fc, msg, n, 0);
		msg[n] = '\0';
		printf("%s:%s\n",r->ip, msg);
       /* int num = sizeof(msg);
		int i = 0;
		for (i = 0; i < num; i++)
			buf[i] = msg[i];*/
        write(fn , msg, sizeof(msg));
		close(fn);
	}
	close(r->fc);
	printf("%s Exit !\n", r->ip);
	free(p);
}

int main()
{
	int fd = socket(AF_INET,SOCK_STREAM,0);
	/*AF_INET---v4,AF_INET6---v6;*/
	/*SOCK_STREAM---tcp,SOCK_DGRAM---udp*/
	if(fd < 0)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in si;/*sockaddr_in6*/
	si.sin_family = AF_INET;
	si.sin_addr.s_addr = htonl(INADDR_ANY);
	si.sin_port = htons(8888);
	if(bind(fd, (struct sockaddr*)&si, sizeof(si)) < 0)
	{
		perror("bind");
		return -1;
	}
	listen(fd, 10);
	for(;;)
	{
		struct sockaddr_in c;
		socklen_t len=sizeof(c);
		int fc = accept(fd, (struct sockaddr*)&c, &len);
		if(fc < 0) 
			continue;
		char ip[16];
		inet_ntop(AF_INET, &c.sin_addr, ip, sizeof(ip));
		printf("%s I'm here !\n", ip);
		char msg[10000000];
		sprintf(msg, "YOUR IP: %s, welcome to network\n", ip);
		/*send(fc, msg, strlen(msg), 0);*/
		struct Param* p = malloc(sizeof(struct Param));
		p->fc = fc;
		strcpy(p->ip, ip);
		func(p);
	}
	close(fd);
}
