/*
   数组名称的使用练习
*/
#include <stdio.h>
int main() {
    int shu_zi[3] = {1, 2, 3}, xun_huan = 0;
    printf("shu_zi是%p\n", shu_zi);  //数组名称代表数组中首变量的地址
    printf("&shu_zi[0]是%p\n", &shu_zi[0]);
    printf("shu_zi + 1是%p, &shu_zi[1]是%p\n", shu_zi + 1, &shu_zi[1]);  //可以根据数组中某个变量的地址计算出其他变量的地址
    for (xun_huan = 0; xun_huan <= 2; xun_huan++) {
        printf("%d ", *(shu_zi + xun_huan));
    }
    printf("\n");
    printf("shu_zi是%p,&shu_zi是%p\n", shu_zi, &shu_zi);   //数组名称和它的地址数据是一样的
    printf("sizeof(shu_zi)是%d\n", sizeof(shu_zi));   //计算结果是数组所占的字节个数
    printf("数组中变量个数是%d\n", sizeof(shu_zi) / sizeof(shu_zi[0]));
    return 0;
}




