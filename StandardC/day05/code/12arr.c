/*
    二维数组做参数的练习
*/
#include <stdio.h>
/*
    任何数组做参数只能当成一维数组使用。
    数组的下标需要另外计算。
*/
void xian_shi(const int shu_zi[], int zu, int ge_shu) {
    int xun_huan = 0, xun_huan_1 = 0;
    for (xun_huan = 0; xun_huan <= (zu - 1); xun_huan++) {
        for (xun_huan_1 = 0; xun_huan_1 <= (ge_shu - 1); xun_huan_1++) {
            printf("%d ", shu_zi[xun_huan * ge_shu + xun_huan_1]);
        }
        printf("\n");
    }
}

int main() {
    int shu_zi[3][2] = {1, 2, 3, 4, 5, 6};
    xian_shi(shu_zi, 3, 2);
    return 0;
}
