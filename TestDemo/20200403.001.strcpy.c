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
    /** strcpy函数会拷贝结束符 '\0' 至目标字符串 **/
    strcpy(array, argv[1]);
    printf("Input String [%s]\n", argv[1]);
    printf("Array String [%s]\n", array);
    return 0;
}
