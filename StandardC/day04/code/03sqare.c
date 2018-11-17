/*
     计算10到20之间所有数字的平方
*/
#include <stdio.h>
int main() {
    int xun_huan = 0;
    for (xun_huan = 20; xun_huan >= 10; xun_huan--) {
        printf("数字%d的平方是%d\n", xun_huan, xun_huan * xun_huan);
    }
    return 0;
}
