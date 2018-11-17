/*
    用函数交换两个变量的数值
*/
#include <stdio.h>

void jiao_huan(int shu_zi, int shu_zi_1) {
    int shu = shu_zi;
    shu_zi = shu_zi_1;
    shu_zi_1 = shu;
}

void jiao_huan_1(int shu_zi[2]) {
    int shu = shu_zi[0];
    shu_zi[0] = shu_zi[1];
    shu_zi[1] = shu;
}

int main() {
    //错误的做法
    /*int shu_zi = 3, shu_zi_1 = 7;
    jiao_huan(shu_zi, shu_zi_1);
    printf("shu_zi是%d,shu_zi_1是%d\n", shu_zi, shu_zi_1);*/
    int shu_zi[2] = {3, 7};
    jiao_huan_1(shu_zi);
    printf("shu_zi[0]是%d,shu_zi[1]是%d\n", shu_zi[0], shu_zi[1]);
    return 0;
}





