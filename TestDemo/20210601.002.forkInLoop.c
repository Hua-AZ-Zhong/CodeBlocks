#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int proc_nbr = 8;

    pid_t pid = 0;
    pid_t child_pid = 0;

    int rc = 0;
    int rv = 0;
    int max_rc = 0;

    printf("This is the father process, pid=%d, ppid=%d\n", getpid(), getppid());

    // fork位于循环语句的测试
    // 测试结果为1个父进程，8个子进程
    //    PPID     PID    PGID     SID TTY        TPGID STAT   UID   TIME COMMAND
    //  686773  686774  686774  686774 pts/2     687232 Ss    1000   0:00  |       \_ -bash
    //  686774  687232  687232  686774 pts/2     687232 S+    1000   0:00  |           \_ a.out
    //  687232  687233  687232  686774 pts/2     687232 S+    1000   0:00  |               \_ a.out
    //  687232  687234  687232  686774 pts/2     687232 S+    1000   0:00  |               \_ a.out
    //  687232  687235  687232  686774 pts/2     687232 S+    1000   0:00  |               \_ a.out
    //  687232  687236  687232  686774 pts/2     687232 S+    1000   0:00  |               \_ a.out
    //  687232  687237  687232  686774 pts/2     687232 S+    1000   0:00  |               \_ a.out
    //  687232  687238  687232  686774 pts/2     687232 S+    1000   0:00  |               \_ a.out
    //  687232  687239  687232  686774 pts/2     687232 S+    1000   0:00  |               \_ a.out
    //  687232  687240  687232  686774 pts/2     687232 S+    1000   0:00  |               \_ a.out

    for(int i=1;i<=proc_nbr;i++)
    {
        printf("begin to call process %d\n",i+1);
        switch(pid=fork())  // switch语句可以替换为if...else if...else语句, pid=fork()可以写一行
        {
            case -1:
                printf("fork error");
                exit(-1); /* parent exits */
                break;

            case 0:
                printf("Now we fork the child process %d!\n",i);
                printf("PID is [%d]\n", child_pid=getpid());
                while(1)
                {
                    printf("Hello World! from child process [%d]\n", child_pid);
                }
                printf("child process [%d] end!\n", child_pid);
                exit(0);
                break;

            default:
                if(i==proc_nbr) // 如果没有default中的等待逻辑，则父进程会退出，仅剩8个子进程
                {
                    for(int k=0;k<proc_nbr;k++)
                    {
                        wait(&rv);
                        printf("My child process exit status is: [%d]\n", rc=WEXITSTATUS(rv));
                        printf("rc=[%d],rv=[%d]\n",rc,rv);
                        max_rc += rc;
                    }
                }
                break;
        }
    }
}
