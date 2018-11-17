/*
    预定义宏练习
*/
#include <stdio.h>
int main() {
    printf("行号是%d\n", __LINE__);  //行号
    printf("文件是%s\n", __FILE__);  //文件名
    printf("日期是%s\n", __DATE__);  //文件日期
    printf("时间是%s\n", __TIME__);  //文件时间
    printf("%sC标准\n", __STDC__ ? "支持" : "不支持");   //是否支持C标准
    return 0;
}
