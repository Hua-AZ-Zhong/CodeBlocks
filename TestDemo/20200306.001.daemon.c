#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

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

    while(1)
    {
        FILE * fp = fopen("/tmp/test20200306.log", "a");
        if(fp == NULL)
        {
            exit(0);
        }

        time_t tv;  // 获取时间
        time(&tv);

        fprintf(fp, "TIME is %s", asctime(localtime(&tv)));
        fclose(fp);

        sleep(5);
    }

    exit(0);
}
