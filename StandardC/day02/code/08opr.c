/*
    逻辑运算符练习
*/
#include <stdio.h>
int main() {
    int shu = 0;
    printf("3 == 5是%d\n", 3 == 5);
    printf("3 != 5是%d\n", 3 != 5);
    printf("3 > 5是%d\n", 3 > 5);
    printf("3 < 5是%d\n", 3 < 5);
    printf("3 >= 5是%d\n", 3 >= 5);
    printf("3 <= 5是%d\n", 3 <= 5);
    printf("3 < 7 < 5是%d\n", 3 < 7 < 5);
    printf("(3 < 7) && (7 < 5)是%d\n", (3 < 7) && (7 < 5));
    printf("(3 < 7) || (7 < 5)是%d\n", (3 < 7) || (7 < 5));
    printf("!0是%d\n", !0);
    0 && (shu = 7);   //&&的短路特性
    printf("shu是%d\n", shu);
    1 || (shu = 7);   //||的短路特性
    printf("shu是%d\n", shu);
    return 0;
}
