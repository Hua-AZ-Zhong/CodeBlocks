/*
    数组初始化练习
*/
#include <stdio.h>
int main() {
    int xun_huan = 0;
    //int shu_zi[3] = {1, 2, 3};
    //int shu_zi[3] = {1, 2};  //未指定初始化数据的变量自动被初始化成0
    //int shu_zi[3] = {1, 2, 3, 4};  //多余的数据被丢弃
    //int shu_zi[] = {1, 2, 3};  //自动计算出数组中变量的个数
    int shu_zi[3] = {[2] = 3, [0] = 1};  //C99规范中支持指定初始化
    //shu_zi = 1;   数组名称不可以被修改
    for (xun_huan = 0; xun_huan <= 2; xun_huan++) {
        printf("%d ", shu_zi[xun_huan]);
    }
    printf("\n");
    return 0;
}
