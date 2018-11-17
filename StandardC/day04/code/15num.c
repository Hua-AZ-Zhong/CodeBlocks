/*
    统计一个数字中每个字符的出现次数
*/
#include <stdio.h>
int main() {
    int shu_zi = 0, ci_shu[10] = {0}, xun_huan = 0;
    printf("请输入一个数字：");
    scanf("%d", &shu_zi);
    do {
        ci_shu[shu_zi % 10]++;
        shu_zi /= 10;
    } while (shu_zi);
    for (xun_huan = 0; xun_huan <= 9; xun_huan++) {
        if (ci_shu[xun_huan]) {
            printf("数字%d的出现次数是%d\n", xun_huan, ci_shu[xun_huan]);
        }
    }
    return 0;
}




