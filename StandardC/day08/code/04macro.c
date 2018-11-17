/*
    带参数的宏和函数的区别
*/
#include <stdio.h>

#define SHE_ZHI(shu_zi)    shu_zi = 3

void she_zhi(int shu_zi) {
    shu_zi = 3;
}

int main() {
    int shu_zi = 4;
    she_zhi(shu_zi);
    printf("shu_zi是%d\n", shu_zi);
    SHE_ZHI(shu_zi);   //会修改变量shu_zi的数值，因为宏是直接被文字替换的，因此参数就是宏内部使用的变量
    printf("shu_zi是%d\n", shu_zi);
    return 0;
}
