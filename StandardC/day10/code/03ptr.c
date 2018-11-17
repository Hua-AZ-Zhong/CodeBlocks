/*
    数组指针练习
*/
#include <stdio.h>
int main() {
    int shu_zi[3] = {1, 2, 3};
    int shu_zi_1[2][3] = {1, 2, 3, 4, 5, 6};
    int (*p_shu_zi)[3];   //int p_shu_zi[1][3] 效果类似
    //p_shu_zi = NULL;
    p_shu_zi = &shu_zi;
    printf("p_shu_zi是%p,*p_shu_zi是%p\n", p_shu_zi, *p_shu_zi);
    printf("shu_zi_1是%p,*shu_zi_1是%p\n", shu_zi_1, *shu_zi_1);
    p_shu_zi = shu_zi_1;
    printf("p_shu_zi + 1是%p, *p_shu_zi + 1是%p\n", p_shu_zi + 1, *p_shu_zi + 1);
    return 0;
}



