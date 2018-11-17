/*
     在屏幕上打印单位矩阵
*/
#include <stdio.h>
int main() {
    //int shu_zi[4][4] = {{1}, {0, 1}, {0, 0, 1}, {0, 0, 0, 1}}, xun_huan = 0, xun_huan_1 = 0;
    int shu_zi[4][4] = {[3][3] = 1, [2][2] = 1, [1][1] = 1, [0][0] = 1}/*二维数组的指定初始化*/, xun_huan = 0, xun_huan_1 = 0;
    for (xun_huan = 0; xun_huan <= 3; xun_huan++) {
        for (xun_huan_1 = 0; xun_huan_1 <= 3; xun_huan_1++) {
            printf("%d ", shu_zi[xun_huan][xun_huan_1]);
        }
        printf("\n");
    }
    return 0;
}
