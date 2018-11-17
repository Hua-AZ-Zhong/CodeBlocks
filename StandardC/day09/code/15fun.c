/*
    函数指针的练习
*/
#include <stdio.h>

int jia(int x, int y) {
    return x + y;
}

int main() {
    int (*p_func)(int, int);
    p_func = jia;
    printf("函数的地址是%p和%p\n", jia, p_func);
    return 0;
}



