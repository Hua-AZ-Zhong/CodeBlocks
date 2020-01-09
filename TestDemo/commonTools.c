#include "commonTools.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <sys/time.h>    // Not matched for Ubuntu
#include <time.h>        // For Ubuntu

/** 获取ms级时间戳，格式为"YYYY-MM-DD HH:MM:SS.ms" - ms记录到3位数字 **/
void getTimeStamp(char *timeStamp)
{
    struct tm *tmnow;
    struct timeb Tp;

    ftime(&Tp);
    printf("Tp's second is [%ld], time()'s return value is [%ld]\n", Tp.time, time(0));

    tmnow=(struct tm *)localtime(&Tp.time);
    sprintf(timeStamp, "%04d-%02d-%02d %02d:%02d:%02d.%03d", tmnow->tm_year+1900, tmnow->tm_mon+1, tmnow->tm_mday, tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec, Tp.millitm);
    printf("%s\n", timeStamp);
    system("date");
}
