/*
    整数转换成逻辑结果的练习
*/
#include <stdio.h>
int main() {
    int shu_zi = 0;
    printf("请输入一个数字：");
    scanf("%d", &shu_zi);
    switch(shu_zi % 2) {
    case 0:
        printf("结果为假\n");
        break;
    case 1:
        printf("结果为真\n");
        break;
    default:
        printf("不能转换\n");
        break;
    }
    return 0;
}
