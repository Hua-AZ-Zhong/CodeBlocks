/*
    位运算符练习
*/
#include <stdio.h>
int main() {
    printf("3 | 5是%d\n", 3 | 5);
    printf("3 & 5是%d\n", 3 & 5);
    printf("3 ^ 5是%d\n", 3 ^ 5);
    printf("~3结果是0x%x\n", ~3);
    printf("3 << 2是%d\n", 3 << 2);
    printf("~(1 << 31)是%x\n", ~(1 << 31));  //有符号整数的最大数
    printf("16 >> 3是%d\n", 16 >> 3);
    printf("-16 >> 3是%d\n", -16 >> 3);
    return 0;
}




