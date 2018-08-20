#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/socket.h>

int check_ip(char *string);
int check_port(char *string);

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("Usage:\n    %s server_ip server_port\n", argv[0]);
        return -1;
    }

    if(!check_ip(argv[1]))
    {
        printf("The Server IP is invalid!\n");
        return -1;
    }

    if(!check_port(argv[2]))
    {
        printf("The Server Port contains non-digit character!\n");
        return -1;
    }

    printf("Pre-Check Passed!\n");

    struct sockaddr_in server;
    memset(&server, 0x00, sizeof(server));
    server.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server.sin_addr);
    server.sin_port = htons(atoi(argv[2]));

    int fd=0;
    int conn_ret=-1;
    while(1)
    {
        if(fd=socket(AF_INET,SOCK_STREAM,0)==-1)
        {
            printf("Create socket error!\n");
            return -1;
        }

        if(conn_ret=connect(fd, (struct sockaddr*)&server, sizeof(struct sockaddr))==-1)
        {
            close(fd);
            printf("Try to connect to <%s>, port:<%s>.\n", argv[1],argv[2]);
            sleep(1);
            continue;
        }
        else if(conn_ret == 0)
        {
            printf("Connected to server!\n");
        }
    }

    return 0;
}

int check_ip(char *string)
{
    if(string == NULL || *string == '\0')
    {
        return 0;
    }

    struct sockaddr_in  ipv4;
    struct sockaddr_in6 ipv6;

    if(inet_pton(AF_INET,string,&ipv4.sin_addr)==1)
        return 1;
    else if(inet_pton(AF_INET6,string,&ipv6.sin6_addr)==1)
        return 1;

    return 0;
}

int check_port(char *string)
{
    return (strspn(string,"0123456789")==strlen(string));
}
