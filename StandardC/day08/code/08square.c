/*
     用宏来计算数字的平方
*/
#include <stdio.h>

#define PING_FANG(n)       ((n) * (n))

int main() {
    int shu_zi = PING_FANG(7);
    printf("shu_zi是%d\n", shu_zi);
    shu_zi = 7;
    shu_zi = PING_FANG(++shu_zi);  //不用使用自增或自减的结果作为宏的参数
    printf("shu_zi是%d\n", shu_zi);
    return 0;
}
