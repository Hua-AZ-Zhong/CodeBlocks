#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if(argc!=2){
		printf("%s PORT\n", argv[0]);
		return 0;
	}
	int skt = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in s;
	s.sin_family = AF_INET;
	s.sin_addr.s_addr = INADDR_ANY;
	s.sin_port = htons(atoi(argv[1]));
	typedef struct sockaddr* sa;
	if(bind(skt, (sa)&s, sizeof(s))<0){
		perror("bind");
		return -1;
	}
	//s ip port text 发送信息
	//r 接收信息
	//a text 回复信息
	//q 退出
	char cmd;
	char ip[16];
	short port;
	char text[1000];
	for(;;){
		printf("s/r/a/q:");
		scanf(" %c", &cmd);
		if(cmd=='q') break;
		if(cmd=='s'){//s ip port text
			scanf("%s%hd %[^\n]",ip,&port,text);
			s.sin_family = AF_INET;
			inet_pton(AF_INET, ip, &s.sin_addr);
			s.sin_port = htons(port);
			sendto(skt,text,strlen(text)+1,0,(sa)&s,sizeof(s));
		}
		else if(cmd=='r'){
			socklen_t len = sizeof(s);
			int n = recvfrom(skt, text, sizeof(text), MSG_DONTWAIT, (sa)&s, &len);
			if(n<0){puts("没有数据");continue;}
			inet_ntop(AF_INET,&s.sin_addr,ip,sizeof(ip));
			printf("%s %hd:%s\n", ip, ntohs(s.sin_port), text);
		}
		else if(cmd=='a'){//a text
			scanf(" %[^\n]", text);
			sendto(skt,text,strlen(text)+1,0,(sa)&s,sizeof(s));
		}
		else{//非法命令
			puts("非法命令!");
			fflush(stdin);//有些系统可能不管用
		}
	}
	close(skt);
}






