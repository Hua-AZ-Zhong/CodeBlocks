/*
    用宏表示数组长度的练习
*/
#include <stdio.h>
#define HANG            10
#define LIE             10
#define GE_SHU(shu_zu)  sizeof(shu_zu) / sizeof(shu_zu[0][0])
/*
    宏不是C语言指令，不能在后面加上；
*/
//#define HANG            10;
//#define LIE             10;
int main() {
    int lei[HANG][LIE];    //声明数组时使用宏表示数组中变量个数
    float shu[3][4];
    printf("变量个数是%d\n", GE_SHU(lei));
    printf("变量个数是%d\n", GE_SHU(shu));
    return 0;
}
