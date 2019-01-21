// Function Declaration
#ifndef POMP_STRUCT_H
#define POMP_STRUCT_H
#endif
int OTraceDebug(FILE *fp, struct POMP *pm, int flashFlag);
void GetTimeSys(char *str);
void GetSysDate(char *sysDate);
void GetTimeStamp(char *timeStamp);
void getCostTime(char *costTime);
void getModuleName(char *mainArgv, char *moduleName);
void setData(struct POMP *pm, char *mainArgv, char *timeType);
