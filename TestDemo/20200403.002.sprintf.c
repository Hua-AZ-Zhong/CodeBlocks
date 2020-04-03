#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Usage: %s strings\n", argv[0]);
        return 0;
    }

    char array[100];
    memset(array, '0', sizeof(array));
    printf("Array String [%s]\n", array);
    /** sprintf函数会在目标字符串后加入串结束符 '\0' **/
    /** 返回值：如果成功，则返回写入的字符总数，不包括字符串追加在字符串末尾的空字符。如果失败，则返回一个负数。 **/
    sprintf(array, "%s", argv[1]);
    printf("Input String [%s]\n", argv[1]);
    printf("Array String [%s]\n", array);
    return 0;
}
