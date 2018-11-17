/*
    在屏幕上输出乘法表
*/
#include <stdio.h>
int main() {
    int xun_huan = 0, xun_huan_1 = 0;
    for (xun_huan = 1; xun_huan <= 9; xun_huan++) {
        for (xun_huan_1 = 1; xun_huan_1 <= xun_huan; xun_huan_1++) {
            printf("%dX%d=%2d ", xun_huan_1, xun_huan, xun_huan * xun_huan_1);
        }
        printf("\n");
    }
    return 0;
}
