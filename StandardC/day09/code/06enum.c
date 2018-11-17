/*
    枚举练习
*/
#include <stdio.h>
int main() {
    enum ji_jie {SPR, SUM, AUT = 6, WIN};
    printf("SPR是%d\n", SPR);
    printf("WIN是%d\n", WIN);
    enum ji_jie season;
    season = SUM;
    printf("season是%d\n", season);
    return 0;
}
