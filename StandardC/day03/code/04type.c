/*
    类型转换练习
*/
#include <stdio.h>
int main() {
    int shu_zi = 160;
    printf("%d %d\n", shu_zi, (char)shu_zi);   //强制类型转换
    printf("大小是%d\n", sizeof(3 < 5 ? 1 : 0.9));
    return 0;
}
