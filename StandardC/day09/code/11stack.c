/*
    堆相关函数的练习
*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *p_shu_zi = NULL, ge_shu = 0, xun_huan = 0;
    //p_shu_zi = (int *)malloc(3 * sizeof(int));  //不保证变量都被清0
    p_shu_zi = (int *)calloc(3, sizeof(int));   //保证所有变量都被清0了
    if (p_shu_zi) {
        for (xun_huan = 0; xun_huan <= 2; xun_huan++) {
            printf("%d\n", *(p_shu_zi + xun_huan));
            *(p_shu_zi + xun_huan) = xun_huan + 1;
        }
        int *p_shu_zi_1 = realloc(p_shu_zi, 6 * sizeof(int));   //把原来的三个整数的空间调整成6个整数
        if (p_shu_zi_1) {  //如果调整成功
            printf("%p %p\n", p_shu_zi, p_shu_zi_1);
            p_shu_zi = p_shu_zi_1;  //用新地址覆盖掉旧地址
            //打印新空间中的六个整数变量
            for (xun_huan = 0; xun_huan <= 5; xun_huan++) {
                printf("%d ", *(p_shu_zi + xun_huan));
            }
            printf("\n");
        }
        free(p_shu_zi);
        p_shu_zi = NULL;
    }
    return 0;
}
