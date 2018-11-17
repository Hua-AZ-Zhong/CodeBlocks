/*
     猜数游戏的练习
*/
#include <stdio.h>
int main() {
    int shu_zi = 0, shu_zi_1 = 0;
    printf("请输入一个数字：");
    scanf("%d", &shu_zi);
    //有可能根本就不会开始循环
    /*while (shu_zi != shu_zi_1) {
        printf("请猜一个数字：");
        scanf("%d", &shu_zi_1);
        if (shu_zi_1 > shu_zi) {
            printf("猜大了\n");
        }
        else if (shu_zi_1 < shu_zi) {
            printf("猜小了\n");
        }
        else {
            printf("猜对了\n");
        }
    }*/
    do {
        printf("请猜一个数字：");
        scanf("%d", &shu_zi_1);
        if (shu_zi_1 > shu_zi) {
            printf("猜大了\n");
        }
        else if (shu_zi_1 < shu_zi) {
            printf("猜小了\n");
        }
        else {
            printf("猜对了\n");
        }
    } while (shu_zi != shu_zi_1);
    return 0;
}
