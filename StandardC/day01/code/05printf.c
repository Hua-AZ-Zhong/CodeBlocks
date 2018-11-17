/*
    printf函数练习
*/
#include <stdio.h>
int main() {
    printf("%d\n", 7);
    printf("%4d\n", 7);  //数字占4个位置
    printf("%-4d\n", 7); //-表示数字左对齐
    printf("%04d\n", 7); //没有占满的位置用0占位
    printf("%c\n", 'a'); //字符类型数据使用%c表示
    printf("%f\n", 1.5f);  //浮点类型数据用%f表示
    printf("%5.2f\n", 1.5f);  //一共占5个位置，小数点后占2位
    printf("%lf\n", 1.5);  //双精度浮点数用%lf表示
    printf("%g   %lg\n", 1.5f, 1.5);  //小数点后面不会补0
    printf("123%d7%d\n", 456, 89);
    printf("12%c%c%d7%c9\n", '3', '4', 56, '8');
    return 0;
}




