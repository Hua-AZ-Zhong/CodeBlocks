/*
    扫雷的练习
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int di_lei[10][10] = {0}, ge_shu = 0;
    int hang = 0, lie = 0;
    srand(time(0));
    //布雷
    while (ge_shu < 10) {
        hang = rand() % 10;
        lie = rand() % 10;
        if (!di_lei[hang][lie]) {
            di_lei[hang][lie] = 1;
            ge_shu++;
        }
    }
    //显示地图
    for (hang = 0; hang <= 9; hang++) {
        for (lie = 0; lie <= 9; lie++) {
            printf("%c", di_lei[hang][lie] ? 'O' : ' ');
        }
        printf("\n");
    }
    return 0;
}




