/*
    static关键字练习
*/
#include <stdio.h>

void f(void) {
    static int shu_zi = 3;  //静态局部变量的生命周期是整个程序运行期间
    printf("shu_zi是%d\n", shu_zi);
    shu_zi++;
}

int main() {
    f();
    f();
    f();
    return 0;
}
