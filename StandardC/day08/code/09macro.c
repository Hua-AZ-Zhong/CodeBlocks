/*
    宏运算符练习
*/
#include <stdio.h>
//#运算符只能用在带参数的宏里，
//这个运算符放在一个参数前面表示
//把这个参数转换成字符串字面值
#define STR(n)       #n
int main() {
    printf("结果是%s\n", STR(5 - 4));
    return 0;
}
