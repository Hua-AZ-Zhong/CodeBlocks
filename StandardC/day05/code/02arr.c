/*
    二维数组练习
*/
#include <stdio.h>
int main() {
    int shu_zi[12];
    //int shu_zi_1[4][3];    //一共四组，每组三个整数变量
    //int shu_zi_1[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    //int shu_zi_1[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    //shu_zi_1[2][1] = 4;  //2表示组下标，1表示组内下标
    int shu_zi_1[][3] = {{1, 2}, {4, 5}};  //可以不指定组的个数，但是必须可以根据初始化数据计算出来
    printf("数组中变量个数为%d\n", sizeof(shu_zi_1) / sizeof(shu_zi_1[0][0]));
    printf("shu_zi_1是%p, shu_zi_1[0]是%p, &shu_zi_1[0][0]是%p\n", shu_zi_1, shu_zi_1[0], &shu_zi_1[0][0]);
    printf("&shu_zi_1[0]是%p\n", &shu_zi_1[0]);
    printf("shu_zi_1 + 1是%p, shu_zi_1[0] + 1是%p, &shu_zi_1[0] + 1是%p\n", shu_zi_1 + 1, shu_zi_1[0] + 1, &shu_zi_1[0] + 1);
    return 0;
}




