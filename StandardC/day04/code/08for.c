/*
    for循环的多种写法练习
*/
#include <stdio.h>
int main() {
    int xun_huan = 0, xun_huan_1 = 0;
    /*for (xun_huan = 0; xun_huan < 3; xun_huan++) {
        printf("xun_huan是%d\n", xun_huan);
    }*/
    /*for (xun_huan = 0; xun_huan < 3; xun_huan++) 
        printf("xun_huan是%d\n", xun_huan);*/
    /*for (xun_huan = 0, xun_huan_1 = 10; xun_huan_1 > (xun_huan + 3); xun_huan++, xun_huan_1--) {
        printf("xun_huan是%d, xun_huan_1是%d\n", xun_huan, xun_huan_1);
    }*/
    /*for (int xun_huan_2 = 0; xun_huan_2 < 3; xun_huan_2++) {
        printf("xun_huan_2是%d\n", xun_huan_2);
    }
    printf("xun_huan_2是%d\n", xun_huan_2);  //xun_huan_2未声明*/
    /*xun_huan = 0;
    for (;xun_huan < 3;) {
        printf("xun_huan是%d\n", xun_huan);
        xun_huan++;
    }*/
    xun_huan = 0;
    //for (;xun_huan < 3;) {
    while (xun_huan < 3) {
        printf("xun_huan是%d\n", xun_huan);
        xun_huan++;
    }
    return 0;
}





