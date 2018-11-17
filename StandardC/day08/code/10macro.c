/*
    宏运算符##练习
*/
#include <stdio.h>

//##运算符可以把参数所代表的标识符和其他
//内容合并成为一个新的标识符
#define GLOBAL(n)    g_##n
#define LOCAL(n)     l_##n
int GLOBAL(shu_zi);
int main() {
    GLOBAL(shu_zi) = 3;
    int LOCAL(shu_zi) = 5;
    printf("%d\n", GLOBAL(shu_zi));
    printf("%d\n", LOCAL(shu_zi));
    return 0;
}




