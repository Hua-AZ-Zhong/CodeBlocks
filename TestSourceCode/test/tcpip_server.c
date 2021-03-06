#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int check_port(char *string);

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage:\n    %s port\n", argv[0]);
        return -1;
    }

    if(!check_port(argv[1]))
    {
        printf("The port contains non-digit character!\n");
        return -1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(atoi(argv[1]));
    int fd = socket(AF_INET,SOCK_STREAM,0);
    printf("fd = %d\n", fd);
    if(fd<0)
    #if 0
    int fd;
    if(fd=socket(AF_INET,SOCK_STREAM,0)<0)
    #endif
    {
        printf("Create socket error!\n");
        return -1;
    }
    int ret=0;
    if(ret=bind(fd,(struct sockaddr*)&server,sizeof(server))<0)
    {
        printf("Bind socket error %d!\n", ret);
        return -1;
    }
    listen(fd,1);
    
    printf("listen() is okay!\n");

    struct sockaddr_in client;
    int fd_client;
    fd_client=accept(fd, (struct sockaddr*)&client, (socklen_t*)sizeof(client));
    return 0;
}

int check_port(char *string)
{
    return (strspn(string,"0123456789")==strlen(string));
}
