/*
    指针练习
*/
#include <stdio.h>
int main() {
    int *p_shu_zi, *p_shu_zi_1;   //指针类型变量的声明
    char *p_zi_fu;
    int shu_zi = 0;
    int shu[2] = {1, 2};
    printf("&shu_zi是%p\n", &shu_zi);
    printf("shu是%p\n", shu);
    p_shu_zi = &shu_zi;
    printf("p_shu_zi是%p\n", p_shu_zi);
    printf("*p_shu_zi是%d\n", *p_shu_zi);
    //shu = &shu_zi;    //数组名称不可以被赋值
    p_shu_zi = shu;
    printf("p_shu_zi是%p\n", p_shu_zi);
    printf("*p_shu_zi是%d\n", *p_shu_zi);
    printf("sizeof(p_shu_zi)是%d\n", sizeof(p_shu_zi));
    p_shu_zi_1 = p_shu_zi;
    p_zi_fu = p_shu_zi;
    printf("p_zi_fu是%p, p_shu_zi是%p\n", p_zi_fu, p_shu_zi);
    printf("*p_zi_fu是%d\n", *p_zi_fu);
    *p_shu_zi = 300;
    printf("*p_zi_fu是%d\n", *p_zi_fu);
    return 0;
}





