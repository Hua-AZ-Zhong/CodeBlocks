/*
    乘法计算的宏练习
*/
#include <stdio.h>
#define CHENG(x,y)       ((x) * (y))
int main() {
    printf("CHENG(2 + 7, 5 - 2)是%d\n", CHENG(2 + 7, 5 - 2));
    printf("24 / CHENG(2, 3)是%d\n", 24 / CHENG(2, 3));
    return 0;
}
