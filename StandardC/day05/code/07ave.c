/*
    用函数计算两个浮点数的平均值
*/
#include <stdio.h>

float ping_jun(float, float);

int main() {
    printf("结果是%g\n", ping_jun(3.6, 5.2));
    return 0;
}

float ping_jun(float shu_zi, float shu_zi_1) {
    return (shu_zi + shu_zi_1) / 2;
}

