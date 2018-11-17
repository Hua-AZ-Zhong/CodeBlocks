/*
     多文件的练习
*/
#include <stdio.h>
#include "readInt.h"
//static int jie_guo;     全局变量的作用域被缩小到当前文件中
int jie_guo;
int main() {
    int shu_zi = 0;
    printf("请输入一个数字：");
    readInt();
    printf("数字是%d\n", jie_guo);
    return 0;
}
