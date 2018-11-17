#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
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
		int n = recv(r->fc, msg, sizeof(msg)-1, 0);
		if(n <= 0) break;
		if(msg[0] == 'q') break;
		send(r->fc, msg, n, 0);
		msg[n] = '\0';
		printf("%s:%s\n",r->ip, msg);
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
	for(;;){
		struct sockaddr_in c;
		socklen_t len=sizeof(c);
		int fc = accept(fd, (struct sockaddr*)&c, &len);
		if(fc < 0) 
			continue;
		char ip[16];
		inet_ntop(AF_INET, &c.sin_addr, ip, sizeof(ip));
		printf("%s I'm here !\n", ip);
		char msg[1000];
		sprintf(msg, "YOUR IP: %s, welcome to network\n", ip);
		send(fc, msg, strlen(msg), 0);
		struct Param* p = malloc(sizeof(struct Param));
		p->fc = fc;
		strcpy(p->ip, ip);
		func(p);
	}
}








