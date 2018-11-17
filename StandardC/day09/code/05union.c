/*
    联合的练习
*/
#include <stdio.h>
union lian_he {
    int shu_zi;
    char zi_fu[2];
} lian_he_1;
int main() {
    printf("sizeof(lian_he_1)是%d\n", sizeof(lian_he_1));
    printf("%p %p\n", &lian_he_1.shu_zi, &(lian_he_1.zi_fu[0]));
    lian_he_1.shu_zi = 0x12345678;
    printf("0x%x\n", lian_he_1.zi_fu[0]);
    return 0;
}
