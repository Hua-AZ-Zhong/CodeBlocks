/*
    栈的练习
*/
#include <stdio.h>
int f() {
    int shu_zi = 3;
    printf("&shu_zi是%p\n", &shu_zi);
    printf("shu_zi是%d\n", shu_zi);
}

int f1() {
    int shu_zi = 5;
    printf("&shu_zi是%p\n", &shu_zi);
    printf("shu_zi是%d\n", shu_zi);
}

int main() {
    f();
    f1();
    return 0;
}
