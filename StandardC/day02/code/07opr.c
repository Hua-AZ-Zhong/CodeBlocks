/*
    运算符练习
*/
#include <stdio.h>
int shu_zi_2 = 0;
int main() {
    int shu_zi = 4, shu_zi_1 = 3;
    printf("15 / 4是%d\n", 15 / 4);
    printf("5.0f / 0.0f是%f\n", 5.0f / 0.0f);
    printf("15 %% 4是%d\n", 15 % 4);  //取余结果的符号和%前面数字的符号保持一致
    printf("15 %% -4是%d\n", 15 % -4);
    printf("-15 %% 4是%d\n", -15 % 4);
    //printf("15 %% 4.0f是%d\n", 15 % 4.0f);//编译报错，取余操作的两个操作数都应该是整数
    shu_zi = shu_zi_1 = 7;
    printf("shu_zi是%d, shu_zi_1是%d\n", shu_zi, shu_zi_1);
    shu_zi = (2, 2 + 3);
    printf("shu_zi是%d\n", shu_zi);
    shu_zi = 2, 2 + 3;
    printf("shu_zi是%d\n", shu_zi);
    shu_zi *= 5 - 2;
    printf("shu_zi是%d\n", shu_zi);
    //++shu_zi;   //shu_zi++
    shu_zi_1 = 6;
    shu_zi = ++shu_zi_1;   //前++的优先级最高
    printf("shu_zi是%d,shu_zi_1是%d\n", shu_zi, shu_zi_1);
    shu_zi_1 = 6;
    shu_zi = shu_zi_1++;  //后++的优先级最低
    printf("shu_zi是%d,shu_zi_1是%d\n", shu_zi, shu_zi_1);
    shu_zi_1 = 6;
    shu_zi = shu_zi_1++ + ++shu_zi_1;  //一条语句中多个++,--的结果不确定
    printf("shu_zi是%d,shu_zi_1是%d\n", shu_zi, shu_zi_1);
    shu_zi_2 = 6;
    shu_zi = shu_zi_2++ + ++shu_zi_2;
    printf("shu_zi是%d,shu_zi_2是%d\n", shu_zi, shu_zi_2);
    return 0;
}




