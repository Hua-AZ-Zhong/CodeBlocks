/*
    宏练习
*/
#include <stdio.h>
#define PI              3.14f
#define ZHOU_CHANG(r)   2 * PI * r
#define MIAN_JI(r)      PI * r * r
int main() {
    int ban_jing = 0;
    const float pi = 3.14f;
    printf("请输入一个半径：");
    scanf("%d", &ban_jing);
    printf("圆的周长是%g\n", ZHOU_CHANG(ban_jing));
    printf("圆的面积是%g\n", MIAN_JI(ban_jing));
    printf("圆的周长是%g\n", 2 * pi * ban_jing);
    printf("圆的面积是%g\n", pi * ban_jing * ban_jing);
    //printf("&PI是%p,&pi是%p\n", &PI, &pi);  //宏不可以取地址，因为在编译的时候宏已经不存在了
    //PI = 3.0f;   //宏被数字替换，数字不能被赋值
    //pi = 3.0f;   //const变量不可以被赋值
    return 0;
}




