/*
    局部变量地址做返回值的练习
*/
#include <stdio.h>

int * f() {
    int shu_zi = 3;
    return &shu_zi;   //不可以把局部变量的地址作为返回值使用
}

int * f1() {
    int shu_zi = 5;
    int shu_zi_1 = 7;
    int shu_zi_2 = shu_zi + shu_zi_1;
    return NULL;
}

int main() {
    int *p_shu_zi = NULL;
    p_shu_zi = f();
    printf("%d\n", *p_shu_zi);
    f1();
    printf("%d\n", *p_shu_zi);
    return 0;
}
