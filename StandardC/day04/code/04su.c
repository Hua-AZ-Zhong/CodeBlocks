/*
    判断一个数字是不是素数
*/
#include <stdio.h>
#include <math.h>
int main() {
    int xun_huan = 0, gen = 0, shu_zi = 0;
    printf("请输入一个数字：");
    scanf("%d", &shu_zi);
    gen = sqrt(shu_zi);
    for (xun_huan = 2; xun_huan <= gen; xun_huan++) {
        if (!(shu_zi % xun_huan)) {
            break;
        }
    }
    if (xun_huan <= gen) {
        printf("数字%d不是素数\n", shu_zi);
    }
    else {
        printf("数字%d是素数\n", shu_zi);
    }
    return 0;
}




