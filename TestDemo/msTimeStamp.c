#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

int main()
{
    struct tm *tmnow;
    struct timeb Tp;

    ftime(&Tp);
    printf("Tp's second is [%ld], time()'s return value is [%ld]\n", Tp.time, time(0));

    tmnow=(struct tm *)localtime(&Tp.time);
    printf("[%04d-%02d-%02d %02d:%02d:%02d.%03d]\n", tmnow->tm_year+1900, tmnow->tm_mon+1, tmnow->tm_mday, tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec, Tp.millitm);
    system("date");
    return 0;
}
