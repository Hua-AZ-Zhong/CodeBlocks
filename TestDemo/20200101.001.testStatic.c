#include <stdio.h>

int main()
{
    int num = 1;
    for(int i = 0; i < 5; i++)
    {
        /** static 引用的局部变量，仅初始化一次，生命周期延长至整个程序结束，但是作用域仅限for循环体内 **/
        static int num = 0;
        num += i;
        printf("num in loop is [%d]\n", num);
    }
    printf("num is [%d]\n", num);
    return 0;
}
