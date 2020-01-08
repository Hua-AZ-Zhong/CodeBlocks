/** 将数据Buffer输出到与CMMT日志一样的结果 **/
#include <stdio.h>
#include <string.h>

void dumpMessage(unsigned char *message, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(*message == 0x00 || *message > 0x80)
            printf(".");
        else
            printf("%c", *message);
        message++;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Param number error!\n");
        printf("Usage: \n");
        printf("    argv[0] + space + your message\n");
        return -1;
    }
    unsigned char buffer[1024] = {0};
    int dataLen = strlen(argv[1]);
    unsigned char *bp = buffer;

    memcpy(buffer, argv[1], dataLen);
    int count = 1;
    int tmpLen = dataLen;
    while( count <= dataLen)
    {
        static int lineHeader = 0x10;
        printf("%05X   ", lineHeader);
        int width = 8;
        for(int i = 0; i < 16 && i < tmpLen; i++)
        {
            if( (count%4)==0 && (count%16)!=0)
            {
                printf("%02X   ", *bp);
                width += 5;
            }
            else
            {
                printf("%02X ", *bp);
                width += 3;
            }
            bp++;
            count++;
        }
        lineHeader += 0x10;
        while(width++ <= 62)
        {
            printf(" ");
        }
        printf("| ");
#if 0
        if(tmpLen > 0 && tmpLen % 16 == 0)
            dumpMessage((bp - 16), 16);
        else if(tmpLen > 0 && tmpLen % 16 != 0)
            dumpMessage((bp - tmpLen), tmpLen);
#endif
        printf("\n");
        tmpLen -= 16;
    }

    return 0;
}
