#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    pid_t pid = fork();  // fork保证不是组长进程
    if(pid != 0)
    {
        exit(0);
    }

    setsid();  // 创建新会话

    pid = fork();
    if(pid != 0)
    {
        exit(0);
    }

    chdir("/");  // 改变工作路径

    umask(0);  // 清除掩码

    int maxfd = getdtablesize();
    for(int i = 0; i < maxfd; i++)
    {
        close(i);
    }

    int fd = socket(AF_INET,SOCK_STREAM,0);
    //AF_INET---v4,AF_INET6---v6;
    //SOCK_STREAM---tcp,SOCK_DGRAM---udp
    if(fd<0)
    {
        perror("socket");
        return -1;
    }
    struct sockaddr_in si;//sockaddr_in6
    si.sin_family = AF_INET;
    si.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY就是0，表示本机IP地址
    si.sin_port = htons(8888);//1024以下的端口有专门用途
    //bind(int,sockaddr*,size_t);
    if(bind(fd,(struct sockaddr*)&si,sizeof(si))<0)
    {
        perror("bind");
        return -1;
    }
    listen(fd, 10);//允许同时有10个接入请求

    while(1)
    {
        struct sockaddr_in c;
        socklen_t len=sizeof(c);//必须初始化成本地套接信息长度
        int fc = accept(fd,(struct sockaddr*)&c,&len);//等待客户连接，返回一个跟客户相连的新套接字
        if(fc<0)
        {
            continue;
        }
        char ip[16];
        inet_ntop(AF_INET,&c.sin_addr,ip,sizeof(ip));
        printf("%s到此一游\n", ip);
        char msg[1000];
        sprintf(msg, "YOUR IP: %s, welcome to network\n", ip);
        write(fc, msg, strlen(msg));
        //close(fc);
    }

    exit(0);
}
