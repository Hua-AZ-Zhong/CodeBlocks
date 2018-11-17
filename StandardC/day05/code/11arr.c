/*
    数组做参数的练习
*/
#include <stdio.h>
/*
    数组作为参数使用时必须通过另外一个参数
    获得数组中的变量个数
*/
void xian_shi(int shu_zi[], int ge_shu) {
    //printf("sizeof(shu_zi)是%d\n", sizeof(shu_zi));   //对参数中的数组使用sizeof得到的结果不是数组所占的空间大小
    int xun_huan = 0;
    for (xun_huan = 0; xun_huan <= (ge_shu - 1); xun_huan++) {
        printf("%d ", shu_zi[xun_huan]);
    }
    printf("\n");
}

int main() {
    int ge_shu = 0;
    printf("请输入数组中变量的个数：");
    scanf("%d", &ge_shu);
    int shu_zi[ge_shu];
    xian_shi(shu_zi, ge_shu);
    return 0;
}
