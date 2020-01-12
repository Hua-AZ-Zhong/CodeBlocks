#include "commonTools.h"
#include <stdio.h>

int main()
{
    char timeStampBuffer[26] = { 0 };
    getTimeStamp(timeStampBuffer);
    printf("%s\n", timeStampBuffer);

    fp = fopen("./output.log", "a+");
    if(fp == NULL)
    {
        printf("Open file failed\n");
        return -1;
    }
    OTraceDebug("Hello world!\n");
    OTraceDebug("%s\n", "Hi, hello world!");
    fclose(fp);
    return 0;
}
