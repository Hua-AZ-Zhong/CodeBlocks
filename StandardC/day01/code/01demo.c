#include <stdio.h>
#include "01demo.h"
/*
 *  文件名称：        01demo.c
 *  文件作者：        杨健
 *  所属公司：        达内时代科技集团有限公司
 *  编写时间：        2013/01/04
 *      版本：        1.0
 *  
 */
int main() {
    int shu_zi = 3, jia_ge = 30;
    //shu_zi = 3;    //变量赋值语句
    //jia_ge * shu_zi;     //单张电影票的价格是30，一共三张
    printf("总票价是%d\n", jia_ge * shu_zi);
    printf("%d X %d = %d\n", jia_ge, shu_zi, jia_ge * shu_zi);
    return 0;
}
