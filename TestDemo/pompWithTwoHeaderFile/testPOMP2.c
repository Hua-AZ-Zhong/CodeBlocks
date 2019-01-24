#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <unistd.h>  /** for sleep() **/
#include <stdlib.h>  /** for getenv() **/
#include <sys/timeb.h>  /** for ftime() **/
#include "POMP_Struct.h"
#include "POMP.h"

FILE *fp = NULL;
FILE *tmp = NULL;
struct POMP pomp;
struct POMP *pm = &pomp;

int main(int argc, char **argv)
{
    int count = 5;
    char initDate[9]={0};
    char curDate[9]={0};

    printf("POMP's size is [%ld]\n",sizeof(struct POMP));
    memset(pm, 0x00, sizeof(struct POMP));
    printf("Initialize the structure OK!\n");

    GetSysDate(initDate);
    printf("Init Date is [%s]\n", initDate);
    char logPath[100] = "";
    sprintf(logPath, "%s/IST_TO_POMP.%s.debug", getenv("PWD"), initDate);
    if((fp = fopen(logPath,"a+")) == NULL)
    {
        printf("Open init log file failed!\n");
        return -1;
    }
    else
    {
        printf("Open log file [%s]!\n", logPath);
    }

    while (count)
    {
        GetSysDate(curDate);
        if(memcmp(curDate,initDate,8)!=0)
        {
            printf("new date [%s]!\n", curDate);
            tmp = fp;
            sprintf(logPath, "%s/IST_TO_POMP.%s.debug", getenv("PWD"), curDate);
            if((fp = fopen(logPath,"a+")) == NULL)
            {
                printf("Open new log file failed!\n");
                return -1;
            }
            else
            {
                printf("Open new log file [%s]!\n", logPath);
                fclose(tmp);
                memcpy(initDate,curDate,8);
            }
        }
        setData(pm, argv[0], "03");
        OTraceDebug(fp, pm, 0);
        srand((unsigned)time(NULL));
        while(rand()%1000000 != 911)
        {
            ;
        }   
        setData(pm, argv[0], "04");
        OTraceDebug(fp, pm, 1);
        //count--;
        sleep(1);
    }
    
    fclose(fp);
}
