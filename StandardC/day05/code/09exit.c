/*
    exit函数练习
*/
#include <stdio.h>
#include <stdlib.h>

void f(void) {
    //return ;
    exit(0);    //立刻结束整个程序
}

int main() {
    f();
    printf("abc\n");
    return 0;
}




