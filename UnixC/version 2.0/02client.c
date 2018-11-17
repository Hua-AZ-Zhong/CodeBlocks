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
	if(argc!=3){
		printf("%s serverip port\n", argv[0]);
		return 0;
	}
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd < 0)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in c;
	c.sin_family = AF_INET;
	inet_pton(AF_INET, argv[1], &c.sin_addr);
	c.sin_port = htons(atoi(argv[2]));
	if(connect(fd, (struct sockaddr*)&c, sizeof(c)) < 0)
	{
		perror("connect");
		return -1;
	}
	printf("Connect successfully !\n");
	char msg[1000];
	for(;;){
		int n = recv(fd, msg, sizeof(msg), 0);
		if(n <= 0) 
			break;
		send(STDOUT_FILENO, msg, n, 0);
		printf("please input:");
		scanf(" %[^\n]", msg);
		strcat(msg,"\n");
		send(fd, msg, strlen(msg), 0);
		if(msg[0] == 'q') 
			break;
	}
	close(fd);
}










