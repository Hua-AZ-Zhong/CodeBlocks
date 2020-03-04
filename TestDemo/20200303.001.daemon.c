//session.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main()
{
    pid_t pid, sid;
    pid = fork();
    if(pid < 0)
    {
        perror("fork erro");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("child process pid: %d\n", getpid());
        printf("Group ID of child pgid: %d\n", getpgid(pid)); //获取进程组ID
        printf("Session ID of child is:%d\n",getsid(pid)); //获取会话ID
        sleep(5);
 
        sid = setsid(); //创建一个会话，将自己ID设置为进程组ID，即新会话ID

        printf("child process pid is %d\n", getpid());
        printf("Group ID of child is: %d\n", getpgid(pid));
        printf("Session Id of child is:%d\n", sid);
        //sleep(5);
        //exit(0);
    }
 
    return 0;
}
