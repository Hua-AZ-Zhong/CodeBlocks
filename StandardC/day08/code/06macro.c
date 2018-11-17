/*
    把描述换算成天数的练习
*/
#include <stdio.h>

//每个宏都应该被包含在一对小括号中
//这样可以强制把宏当成一个整体
#define MIAO_SHU       (24 * 3600)
//宏的每个参数都应该用小括号包围
//这样可以保证每个参数先计算出结果
//然后再进行宏计算
#define ZHUAN_HUAN(s)  ((s) / MIAO_SHU)

int main() {
    printf("天数是%d\n", ZHUAN_HUAN(48 * 3600));
    printf("天数是%d\n", ZHUAN_HUAN(24 * 3600 + 24 * 3600));
    return 0;
}
