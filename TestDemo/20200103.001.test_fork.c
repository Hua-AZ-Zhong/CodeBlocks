#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        printf("fork() error, return value = [%d]\n", pid);
    }
    else if(pid == 0)
    {
        printf("I'm the child process, my pid=[%d], my father pid=[%d]\n", getpid(), getppid());
    }
    else
    {
        printf("I'm the father process, my pid=[%d], child pid is [%d]\n", getpid(), pid);
        system("sleep 30");
    }

    return 0;
}
