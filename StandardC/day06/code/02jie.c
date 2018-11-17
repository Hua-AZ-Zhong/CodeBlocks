/*
     阶乘计算的练习
*/
#include <stdio.h>

int jie_cheng(int shu_zi) {
    if (1 == shu_zi) {
        return 1;
    }
    else {
        return shu_zi * jie_cheng(shu_zi - 1);
    }
}

int main() {
    int xun_huan = 0, shu_zi = 0, jie_guo = 1;
    printf("请输入一个正整数：");
    scanf("%d", &shu_zi);
    for (xun_huan = 1; xun_huan <= shu_zi; xun_huan++) {
        jie_guo *= xun_huan;
    }
    printf("结果是%d\n", jie_guo);
    printf("结果是%d\n", jie_cheng(shu_zi));
    return 0;
}





