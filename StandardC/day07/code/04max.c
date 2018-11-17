/*
    指针做返回值练习
*/
#include <stdio.h>

int *zui_da(int *p_shu_zi_1, int *p_shu_zi_2) {
    return *p_shu_zi_1 > *p_shu_zi_2 ? p_shu_zi_1 : p_shu_zi_2;
}

int main() {
    int shu_zi_1 = 0, shu_zi_2 = 0;
    int *p_shu = NULL;
    printf("请输入两个整数：");
    scanf("%d %d", &shu_zi_1, &shu_zi_2);
    p_shu = zui_da(&shu_zi_1, &shu_zi_2);
    printf("最大数字是%d\n", *p_shu);
    return 0;
}
