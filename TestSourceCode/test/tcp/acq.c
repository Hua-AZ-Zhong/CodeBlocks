/*************************************************************************
> File Name: tcpclient.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年03月23日 星期一 17时32分55秒
*************************************************************************/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        printf("%s server_ip_address port\n", argv[0]);
        return 0;
    }

    /*创建socket套接字*/
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    /*AF_INET---ipv4, AF_INET6---ipv6;*/
    /*SOCK_STREAM---TCP, SOCK_DGRAM---UDP*/

    if(fd < 0)
    {
        perror("create socket error !");
        return -1;
    }

    struct sockaddr_in client;
    client.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &client.sin_addr);
    client.sin_port = htons(atoi(argv[2]));
    int ret = connect(fd, (struct sockaddr*)&client, sizeof(client));
    if(ret < 0)
    {
        perror("connect ip_addr and port error !");
        return -1;
    }
    printf("Connect successfully !\n");
    char msg[1000];
    for(;;)
    {
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
