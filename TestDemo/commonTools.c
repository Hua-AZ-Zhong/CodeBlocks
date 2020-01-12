#include "commonTools.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <sys/time.h>    // Not matched for Ubuntu
#include <time.h>        // For Ubuntu
#include <stdarg.h>        // For Ubuntu

/** 获取ms级时间戳，格式为"YYYY-MM-DD HH:MM:SS.ms" - ms记录到3位数字 **/
void getTimeStamp(char *timeStamp)
{
    struct tm *tmnow;
    struct timeb Tp;

    ftime(&Tp);

    tmnow=(struct tm *)localtime(&Tp.time);
    sprintf(timeStamp, "%04d-%02d-%02d %02d:%02d:%02d.%03d", tmnow->tm_year+1900, tmnow->tm_mon+1, tmnow->tm_mday, tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec, Tp.millitm);
    /**
    printf("%s\n", timeStamp);
    printf("Tp's second is [%ld], time()'s return value is [%ld]\n", Tp.time, time(0));
    system("date");
    **/
}

/** 类IST日志输出函数 **/
int OTraceDebug(const char *va_alist, ...)
{
    char logBuffer[10000] = "";
    va_list args;
    char* format;
    char timeBuffer[100];
    getTimeStamp(timeBuffer);
    strcat(logBuffer, timeBuffer);
    sprintf(logBuffer + strlen(logBuffer), "[PID:%10d] ", getpid());

    va_start(args, va_alist);
#if 0
    format = va_arg(args, char* );
    vsprintf(logBuffer, format, args);
    printf("format is [%s]\n", format);
    printf("logBuffer is: %s", logBuffer);
#endif
    vsprintf(logBuffer + strlen(logBuffer), va_alist, args);
    fprintf(fp, "%s", logBuffer);
    fflush(fp);
}
