#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Usage: %s strings\n", argv[0]);
        return 0;
    }

    /** 如果atoi和atol的参数含有字母，则返回值为0 **/
    printf("atoi(%s) = [%d], atol(%s) = [%ld]\n", argv[1], atoi(argv[1]), argv[1], atol(argv[1]));
    return 0;
}
