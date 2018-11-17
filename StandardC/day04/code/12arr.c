/*
    数组的练习
*/
#include <stdio.h>
int main() {
    int ge_shu = 0, xun_huan = 0;
    printf("请输入变量的个数：");
    scanf("%d", &ge_shu);
    int shu_zi[ge_shu];
    for (xun_huan = 0; xun_huan <= (ge_shu - 1); xun_huan++) {
        printf("请输入一个数字：");
        scanf("%d", &shu_zi[xun_huan]);
    }
    for (xun_huan = ge_shu - 1; xun_huan >= 0; xun_huan--) {
        printf("%d ", shu_zi[xun_huan]);
    }
    printf("\n");
    return 0;
}
