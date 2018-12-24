#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <unistd.h>  /** for sleep() **/
#include <stdlib.h>  /** for getenv() **/

int OTraceDebug(const char *va_alist, ...);

int main()
{
    char *name = "zhonghua";
    int age = 30;
    int count = 5;
    while (count)
    {
        OTraceDebug("hello world! name is %s, age is %d\n", name, age);
        count--;
        sleep(1);
    }
}

void GetTimeSys(char *str)
{
    struct timeval *Tp;
    struct timezone *Tzp;
    struct tm *tmnow;
    time_t Clock;
    int ret;
    char strtime[20],strdate[20];
                                    
    Clock=(time_t)time((time_t *)0);
    tmnow=(struct tm *)localtime(&Clock);
                                            
    sprintf(str, "[%04d%02d%02d ", tmnow->tm_year+1900, tmnow->tm_mon+1, tmnow->tm_mday);
    sprintf(strtime, "%02d:%02d:%02d]", tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec);
                                                    
    strcat(str,strtime);
}

int OTraceDebug(const char *va_alist, ...)
{
    char msg2file[10000] = "";
    char logPath[100] = "";
    va_list args;
    char* format;
    char timeBuffer[100];
    GetTimeSys(timeBuffer);
    strcat(msg2file, timeBuffer);
    sprintf(msg2file + strlen(msg2file), "[PID:%10d] ", getpid());

    sprintf(logPath, "%s/%s", getenv("PWD"), "POMP.log");

    va_start(args, va_alist);
#if 0
    format = va_arg(args, char* );
    vsprintf(msg2file, format, args);
    printf("format is [%s]\n", format);
    printf("msg2file is: %s", msg2file);
#endif
    vsprintf(msg2file + strlen(msg2file), va_alist, args);
    FILE *fp = NULL;
    if((fp = fopen(logPath,"a+")) == NULL)
    {
        printf("Open log file failed!\n");
    }
    fprintf(fp, "%s", msg2file);
    fclose(fp);
}
