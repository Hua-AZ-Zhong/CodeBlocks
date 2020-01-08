#include "commonTools.h"
#include <stdio.h>

int main()
{
    char timeStampBuffer[26] = { 0 };
    getTimeStamp(timeStampBuffer);
    printf("%s\n", timeStampBuffer);
    return 0;
}
