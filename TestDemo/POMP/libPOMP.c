#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>  /** for sleep() **/
#include <stdlib.h>  /** for getenv() **/
#include <sys/timeb.h>  /** for ftime() **/
#include "POMP.h"

void GetSysDate(char *SysDate)
{
    struct tm *tmnow;
    time_t Clock;
                                    
    Clock=(time_t)time((time_t *)0);
    tmnow=(struct tm *)localtime(&Clock);
                                            
    sprintf(SysDate, "%04d%02d%02d", tmnow->tm_year+1900, tmnow->tm_mon+1, tmnow->tm_mday);
}

void GetTimeStamp(char *timeStamp)
{
    struct tm *tmnow;
    time_t Clock;
    struct timeb Tp;

    ftime(&Tp);
    Clock=(time_t)time((time_t *)0);
    tmnow=(struct tm *)localtime(&Clock);
                                            
    sprintf(timeStamp, "%04d-%02d-%02d", tmnow->tm_year+1900, tmnow->tm_mon+1, tmnow->tm_mday);
    sprintf(timeStamp + 10, " %02d:%02d:%02d.%03d", tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec, Tp.millitm);
}

void GetTimeSys(char *str)
{
    struct timeval *Tp;
    struct timezone *Tzp;
    struct tm *tmnow;
    time_t Clock;
    char strtime[20],strdate[20];
                                    
    Clock=(time_t)time((time_t *)0);
    tmnow=(struct tm *)localtime(&Clock);
                                            
    sprintf(str, "[%04d-%02d-%02d ", tmnow->tm_year+1900, tmnow->tm_mon+1, tmnow->tm_mday);
    sprintf(strtime, "%02d:%02d:%02d]", tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec);
                                                    
    strcat(str,strtime);
}

int getSTAN()
{
    srand((unsigned)time(NULL));        /** 调用srand()函数设置随机数种子，种子加入时间 **/
    return rand()%1000000;         /** 调用rand()函数产生一个随机数，除以100万取模，得到六位随机流水号 **/
}
void setData(struct POMP *pm)
{
    pm->TranId = getSTAN();
    sprintf(pm->TerId, "%s", "12345678");
    sprintf(pm->CardId, "%s", "6227611399999999");
    sprintf(pm->ProName, "%s", "IST");
    sprintf(pm->ModName, "%s", "ZPC");
    sprintf(pm->NodeId, "%s", "01");
    sprintf(pm->TxnID, "%s", "03");
    sprintf(pm->TimeType, "%s", "01");
    GetTimeStamp(pm->TxnDateTime);
    sprintf(pm->LinkSysName, "%s", "ZPA");
    sprintf(pm->ReturnCode, "%s", "14");
    //sprintf(pm->ReturnMsg, "|");
    sprintf(pm->SucFlag, "A");
    sprintf(pm->costtime, "%s", "1024");
}

int OTraceDebug(FILE *fp, struct POMP *pm, int flashFlag)
{
    char msg2file[10000] = "";
    char timeBuffer[100];
    char POMPLOG[10000] = {0};
    GetTimeSys(timeBuffer);
    strcat(msg2file, timeBuffer);
    sprintf(msg2file + strlen(msg2file), "[PID:%10d] LOG=", getpid());
    sprintf(POMPLOG, "%06d|%s|%s|%s|%s|", pm->TranId, pm->TerId, pm->CardId, pm->ProName, pm->ModName);
    sprintf(POMPLOG + strlen(POMPLOG), "%s|%s|%s|%s|%s|", pm->NodeId, pm->TxnID, pm->TimeType, pm->TxnDateTime, pm->LinkSysName);
    sprintf(POMPLOG + strlen(POMPLOG), "%s|%s|%s|%s", pm->ReturnCode, pm->ReturnMsg, pm->SucFlag, pm->costtime);
    sprintf(msg2file + strlen(msg2file), "%s", POMPLOG);

    fprintf(fp, "%s\n", msg2file);
    if(flashFlag)
    {
        fflush(fp);
    }
}
