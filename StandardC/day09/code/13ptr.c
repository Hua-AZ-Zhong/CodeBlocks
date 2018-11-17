/*
    二级指针练习
*/
#include <stdio.h>
int main() {
    int shu_zi = 3;
    int *p_shu_zi = &shu_zi;
    int **pp_shu_zi = &p_shu_zi;   //二级指针声明
    printf("%d %p %p\n", **pp_shu_zi, *pp_shu_zi, pp_shu_zi);
    return 0;
}
