/*
    计算利率的练习
*/
#include <stdio.h>
int main() {
    int li_lv = 0, nian = 0, xun_huan = 0, xun_huan_1 = 0, ge_shu = 0;
    printf("请输入利率的个数：");
    scanf("%d", &ge_shu);
    float qian[ge_shu];
    for (xun_huan = 0; xun_huan <= (ge_shu - 1); xun_huan++) {
        qian[xun_huan] = 100.0f;
    }
    printf("请输入最小利率数字和年数：");
    scanf("%d %d", &li_lv, &nian);
    printf("年");
    for (xun_huan = li_lv; xun_huan <= (li_lv + ge_shu - 1); xun_huan++) {
        printf("%7d%%", 100 + xun_huan);
    }
    printf("\n");
    for (xun_huan = 1; xun_huan <= nian; xun_huan++) {
        printf("%2d", xun_huan);
        for (xun_huan_1 = li_lv; xun_huan_1 <= (li_lv + ge_shu - 1); xun_huan_1++) {
            qian[xun_huan_1 - li_lv] *= (100 + xun_huan_1) / 100.0f;
            printf("%8.2f", qian[xun_huan_1 - li_lv]);
        }
        printf("\n");
    }
    return 0;
}




