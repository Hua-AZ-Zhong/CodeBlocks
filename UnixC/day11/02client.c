#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
	if(argc!=3){//命令格式不正确就提示用户
		printf("%s serverip port\n",argv[0]);
		return 0;
	}
	int fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd<0){perror("socket");return -1;}
	struct sockaddr_in c;
	c.sin_family = AF_INET;
	inet_pton(AF_INET,argv[1],&c.sin_addr);//应该加上检查是否成功
	c.sin_port = htons(atoi(argv[2]));
	if(connect(fd, (struct sockaddr*)&c,sizeof(c))<0){
		perror("connect");return -1;
	}
	printf("连接成功\n");
	char msg[1000];
	for(;;){
		int n = read(fd, msg, sizeof(msg));//读取来自服务器的数据
		//int n=recv(fd,msg,sizeof(msg),0);
		if(n<=0) break;//出错跳出
		write(STDOUT_FILENO,msg,n);//显示到屏幕上
		printf("输入:");//fgets(msg,sizeof(msg),stdin);
		scanf(" %[^\n]", msg);//读取用户输入行
		strcat(msg,"\n");//追加换行符
		write(fd, msg, strlen(msg));//发送到服务器
		//send(fd,msg,strlen(msg),0);
		if(msg[0]=='q') break;//q退出
	}
	close(fd);//关闭套接字
}










