#include <string.h>
#include <stdio.h>
 
int main()
{
    char str[80] = "This is a test string";
    const char delim[2] = " ";
    char *pointer = NULL;

    /* 获取第一个子字符串 */
    pointer = strtok(str, delim);

    /* 继续获取其他的子字符串 */
    while( pointer != NULL )
    {
        printf("%s\n", pointer);
        pointer = strtok(NULL, delim);
    }
   
    return(0);
}
