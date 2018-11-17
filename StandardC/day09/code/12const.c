/*
    const指针练习
*/
#include <stdio.h>
int main() {
    int shu_zi = 3;
    const int * p_shu_zi = NULL;
    int * const p_shu_zi_1 = &shu_zi;
    p_shu_zi = &shu_zi;
    //p_shu_zi_1 = &shu_zi;   这种指针变量本身不可以被修改
    *p_shu_zi_1 = 5;
    //*p_shu_zi = 5;    const指针指向的变量不可以修改
    printf("请输入一个整数：");
    //scanf("%d", p_shu_zi);    编译会出现警告
    scanf("%d", &shu_zi);
    return 0;
}



