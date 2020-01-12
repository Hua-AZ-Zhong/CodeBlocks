#ifndef COMMONTOOLS_H
#define COMMONTOOLS_H

/** Group: Header File  **/
#include <stdio.h>
/** End Group: Header File  **/

/** Group: Global Variable **/

FILE *fp = NULL;

/** End Group: Global Variable **/

/** Group: Function Declaration **/

/** 获取ms级时间戳，格式为"YYYY-MM-DD HH:MM:SS.ms" - ms记录到3位数字 **/
void getTimeStamp(char *timeStamp);

/** 类IST日志输出函数 **/
int OTraceDebug(const char *va_alist, ...);

/** End Group: Function Declaration **/

#endif
