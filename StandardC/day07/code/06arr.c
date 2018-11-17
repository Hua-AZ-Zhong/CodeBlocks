/*
    指针和数组的练习
*/
#include <stdio.h>
int main() {
    int shu_zi[5] = {1, 2, 3, 4, 5}, xun_huan = 0;
    int *p_shu_zi = shu_zi, *p_shu_zi_1 = shu_zi;
    for (xun_huan = 0; xun_huan <= 4; xun_huan++) {
        printf("%d ", shu_zi[xun_huan]);
        printf("%d ", *(shu_zi + xun_huan));
        printf("%d ", p_shu_zi[xun_huan]);
        printf("%d ", *(p_shu_zi + xun_huan));
        printf("\n");
    }
    for (xun_huan = 0; xun_huan <= 4; xun_huan++, p_shu_zi_1++) {
        printf("%d ", *p_shu_zi_1);
    }
    printf("\n");
    return 0;
}


